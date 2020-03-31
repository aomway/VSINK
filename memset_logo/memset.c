#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include "p2v.h"
#include "typedef.h"
#include <sys/time.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/mman.h>



#define RED     (0xFFFF0000)
#define BLUE    (0xFF0000FF)
#define GREEN   (0xFF00FF00)
#define YELLOW  (0xFFFFFF00)
#define BLACK   (0xFF000000)

extern void LCDDisplayASCII8X16(u32 x0, u32 y0, u32 ForeColor, char * s);
extern u32 g_pLCDBuffer;
int x_res = 1920;
int y_res = 1080;
uint32_t *working_fb;
int fd_param;
int *buffer_param;



static void fill_bmp(int fd, uint32_t *buf, uint32_t alpha, int width, int height)
{
    int i, j;
    unsigned char tmp_buf[54];
    unsigned char *bmp_line;

    uint32_t *p = buf;

    printf("++fill_bmp\n");
    unsigned char *bmp_buf  = (unsigned char *)malloc(width*height*3);
    if(bmp_buf == NULL)
        return;

    read(fd, tmp_buf, 54); //skip bmp hdr, TODO,parse hdr
    i = read(fd, bmp_buf, width*height*3);
    if(i != width*height*3) {
        printf("read bmp file fail\n");
        return;
    }
    for(i=0; i<height; i++) {
        bmp_line = bmp_buf + ((height-1-i) * width * 3);
        for(j=0;j<width;j++) {
               *p = (alpha<<24) | (bmp_line[j*3]) |  (bmp_line[j*3+1]<<8) |  ((bmp_line[j*3+2]<<16));
           p++;
        }
    }
    printf("--fill_bmp, %d, %d\n", i, j);
    free(bmp_buf);
}

void blt_clr(uint32_t *fb, uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
        uint32_t *src_addr;
        int x_stride;
        int i;
        int iter = y1 - y0 + 1;

        x_stride = (x1 - x0 + 1) * 4;
        for(i=0; i<iter; i++) {
                src_addr = &fb[(y0 + i)*x_res + x0];
                memset(src_addr, 0x0, x_stride);
        }
}

void blt_bg(uint32_t *fb, uint16_t x0, uint16_t y0, uint16_t x1, uint16_t y1)
{
        uint32_t *src_addr;
        int x_stride;
        int i;
        int j;
        int iter = y1 - y0 + 1;

        x_stride = (x1 - x0 + 1);
        for(i=0; i<iter; i++) {
                src_addr = &fb[(y0 + i)*x_res + x0];
                for(j = 0; j < x_stride; j++)
                        src_addr[j] = YELLOW;
        }
}

void SetPixelOS(int16_t x, int16_t y, uint32_t color) //set pixel off screen
{
  working_fb[y * x_res + x] = color;
}


void DrawLineOS(int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint32_t color)
{
  int16_t temp;
  int dalt_x,dalt_y,err=0;
 if (y1>y2)
    {
    temp=x1;
    x1=x2;
    x2=temp;
    temp=y1;
    y1=y2;
    y2=temp;
    }
SetPixelOS(x1,y1,color);
 dalt_x=x2-x1;
 dalt_y=y2-y1;
 if(dalt_x>=0)
     {
      if(dalt_y>dalt_x)//k>1
        {
         while(y1<y2)
         {
          if(err<0)
          {
           x1=x1+1;
           y1=y1+1;
           err=err+dalt_y-dalt_x;
           }
           else
           {
           y1=y1+1;
           err=err-dalt_x;
           }
          SetPixelOS(x1,y1,color);
         }
       }
     else  // 0<=k=<1
      {
       if (dalt_y==0)
          y1=y1-1;
       while(x1<x2)
         {
          if(err<0)
          {
           x1=x1+1;
           err=err+dalt_y;
           }
           else
           {
           y1=y1+1;
                x1=x1+1;
           err=err+dalt_y-dalt_x;
           }
          SetPixelOS(x1,y1,color);
         }
     }

  }
else
  {
   dalt_x=x1-x2;
    if(dalt_y>dalt_x)//k<-1
     {
      while(y1<y2)
       {
        if(err<0)
         {
          x1=x1-1;
          y1=y1+1;
          err=err+dalt_y-dalt_x;
         }
        else
         {
          y1=y1+1;
          err=err-dalt_x;
         }
        SetPixelOS(x1,y1,color);
      }
    }
   else       //0>k>=-1
    {
      if (dalt_y==0)
          y1=y1-1;
    while(x1>x2)
      {
       if(err<0)
        {
         x1=x1-1;
         err=err+dalt_y;
        }
       else
        {
         x1=x1-1;
         y1=y1+1;
         err=err+dalt_y-dalt_x;
        }
       SetPixelOS(x1,y1,color);
      }
    }
  }

}

void Rect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h){


//      blt_clr(fb_base0,x0,y0,x0+w,y0+h);
        DrawLineOS(x0,y0,x0+w,y0,YELLOW);
        DrawLineOS(x0+w,y0,x0+w,y0+h,YELLOW);
        DrawLineOS(x0+w,y0+h,x0,y0+h,YELLOW);
        DrawLineOS(x0,y0+h,x0,y0,YELLOW);

}



void set_timer()
{
        struct itimerval itv, oldtv;
        itv.it_interval.tv_sec = 1;
        itv.it_interval.tv_usec = 0;
        itv.it_value.tv_sec = 1;
        itv.it_value.tv_usec = 0;
        setitimer(ITIMER_REAL, &itv, &oldtv);
}

void process_worker(int sig)
{
	static unsigned long timestamp = 0;
        static int process_width;
        static int process_height;
        static int block_num_adjust;
        static int block_width;
        static int process_x;
        static int process_y;
        static int step;
	if (timestamp == 0) {
                int screen_width;
                int screen_height;
                timestamp =1;
                step = 0;
                screen_width = x_res;
                screen_height = y_res;
                /* draw process bar background */
                process_width = screen_width * 4 / 5 - 16;
                process_height = screen_height / 10;
                process_x = (screen_width - process_width) / 2;
                process_y = screen_height - process_height * 2;
                block_width = process_width / 40;
                block_num_adjust = process_width / block_width;
//              draw_box(process_x, process_y, process_width, process_height, 0);
               // draw_box(process_x, process_y, block_width, process_height, 0);
		Rect(process_x,process_y,process_width,process_height);
		printf("process_width %d process_height %d process_x %d process_y %d block_width %d block_num_adjust %d\n",process_width,process_height,process_x,\
                process_y,block_width,block_num_adjust);
        } else {
                int i;
                int current_x;

		current_x = process_x + step*block_width;
	
		printf("current %d\n",current_x);	
		if(step < block_num_adjust){
			blt_bg(working_fb,current_x,process_y,current_x+40,process_y+108);

		if((buffer_param[0] != 0) && (buffer_param[1] !=0) ){
			exit(0);
		}	

		}else{
			exit(0);
		}

		step++;
		#if 0
                for (i = 0 ; i < 4; i++) {
                        current_x = process_x + block_width * ( step -i );
                        if (current_x >= (process_x + process_width - 2 * block_width) || current_x < process_x) {
                                continue;
                        }
                 //       draw_box(current_x, process_y, block_width, process_height, i + 1);
                }
		#endif
        }


}


int main(int argc, char *argv[])
{
	uint32_t *fb_base0;
	uint32_t *fb_base1;
	uint32_t *fb_ctrl;
	int i;
	int alpha;
 	int logo_fd;
	char disp_str[128];


	signal(SIGALRM, process_worker);
	set_timer();

	if(argc != 2) {
		printf("memset alpha[int]\n");
		return -1;
	}
	fb_base0 = (int32_t *)p2v(0x11800000, 1920*1088*4);
	printf("fb_base virt 0x%08x\n", (uint32_t)fb_base0);
	alpha = atoi(argv[1]);

	logo_fd = open("/media/aomway.bmp", O_RDONLY, S_IRUSR);
	fill_bmp(logo_fd, (uint32_t *)fb_base0, alpha, 1920, 1080);
	close(logo_fd);

	working_fb = fb_base0;
	fb_ctrl = (int32_t *)p2v(0x43c00000, 4096);


	fd_param = shm_open("/param.txt",O_RDWR|O_CREAT|O_EXCL,0777);
        if(fd_param < 0){
               fd_param = shm_open("/param.txt",O_RDWR,0777);
        }else
                ftruncate(fd_param,4096);
         buffer_param= mmap(NULL,4096,PROT_READ|PROT_WRITE,MAP_SHARED,fd_param,0);



//	for(i=0;i<30;i++){
//		blt_bg(fb_base0,100+i*20,100,100+i*20+10,120);
//	}

	fb_ctrl[56] = 0x5;

	while(1){

		sleep(2);
	}

	return 0;
}
