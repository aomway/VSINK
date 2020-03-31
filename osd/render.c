#include <stdint.h>
#include <stdio.h>
#include <unistd.h>
#include "render.h"
#include "p2v.h"
#include "typedef.h"
#include <math.h>
#include <sys/time.h>
#include <stdlib.h>
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <sys/time.h>   //      gettimeofday
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include "Util.h"



#define TO_FEET 3.28084
#define TO_MPH  0.621371
#define CELL_WARNING_PCT1 (CELL_WARNING1-CELL_MIN)/(CELL_MAX-CELL_MIN)*100
#define CELL_WARNING_PCT2 (CELL_WARNING2-CELL_MIN)/(CELL_MAX-CELL_MIN)*100


#define true  1
#define false 0


extern int socket_descriptor;
extern struct sockaddr_in address;
extern int socket_descriptor_recv;
extern struct sockaddr_in address_recv;
#define ROW  7
uint32_t *fb_base0;
uint32_t *fb_base1;
uint32_t *fb_ctrl;
uint32_t *working_fb;

struct decoce_param param;
int fd_param;
int *buffer_param;

int fd_video;
int *buffer_video;
int value_param[3];
int *lcdwh;
int flag_lcdwh=0;
static unsigned int count_anjian1=1;
static unsigned int count_anjian2=0;
static unsigned int count_anjian3=0;
static unsigned int count_anjian4=0;
static unsigned int count_anjian5=0;
static unsigned int count_anjian6=0;
static unsigned int count_anjian7=0;
static unsigned int count_osd=0;

int x_step;

unsigned int RED =0xFFFF0000;
//#define RED     (0xFFFF0000)
#define BLUE    (0xFF0000FF)
#define GREEN   (0xFF00FF00)
#define YELLOW  (0xFFFFFF00)
#define BLACK   (0xFF000000)
#define WHITE   (0xFFFFFFFF)

int x_res = 1920;
int y_res = 1080;

int pos_x ;
int pos_y ;


extern void LCDDisplayASCII8X16_720p(u32 x0, u32 y0, u32 ForeColor, char * s);
extern void LCDDisplayASCII8X16(u32 x0, u32 y0, u32 ForeColor, char * s);
extern u32 g_pLCDBuffer;
extern u32 g_dwLcdWidth;
extern u32 g_dwLcdHeight;





int *lcdwh_memory_open(void) {
        char buf[128];
        int fd;
        sprintf(buf, "/lcdwidth_height");
        fd = shm_open(buf, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
        if(fd < 0) { perror("shm_open"); exit(1); }
        if (ftruncate(fd, 4096) == -1) { perror("ftruncate"); exit(1); }
        int *retval = mmap(NULL, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
        return retval;
}


void SetPixelOS(int16_t x, int16_t y, uint32_t color) //set pixel off screen
{
  working_fb[y * x_res + x] = color;
}


int get_parameter(struct decoce_param *pparam)
{
   if(confile_init()) {
        printf("config file parse filed!\n");
        return -1;
   }
   pparam->wififreq     = get_conf_string("wififreq", "AUTO");
   pparam->color        = get_conf_string("color",    "YELLOW");
   pparam->invert_poll  = get_conf_string("invert_poll","1");
   pparam->invert_pitch = get_conf_string("invert_pitch","1");
   pparam->txpower      = get_conf_string("txpower","10mW");  
   pparam->osd          = get_conf_int("osd",1);  
   pparam->plane        = get_conf_int("plane",1);

   return 0;
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

void Arrow(uint16_t x0, uint16_t y0, int len){


//      blt_clr(fb_base0,x0,y0,x0+w,y0+h);
        DrawLineOS(x0,y0+18,x0+20,y0+18,RED);
        DrawLineOS(x0+10,y0,x0+20,y0+18,RED);
        DrawLineOS(x0+10,y0+36,x0+20,y0+18,RED);

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


#define BG_COLOR 0x7f0000ff
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
                //memset(src_addr, 0x0, x_stride);
                for(j = 0; j < x_stride; j++)
                        src_addr[j] = BG_COLOR;
        }
}





int width, height;

float scale_factor_font;
int setting_home;
int home_set;
float home_lat;
float home_lon;
int home_counter;
char buffer[40];

int packetslost_last[6];
int fecs_skipped_last;
int injection_failed_last;
int tx_restart_count_last;



int getWidth(float pos_x_percent) {
    return (x_res * 0.01f * pos_x_percent);
}

int getHeight(float pos_y_percent) {
    return (y_res * 0.01f * pos_y_percent);
}

float getOpacity(int r, int g, int b, float o) {
    if (o<0.5) o = o*2;
    return o;
}

void setfillstroke() {
//    Fill(COLOR);
//    Stroke(OUTLINECOLOR);
//    StrokeWidth(OUTLINEWIDTH);
}

void render_init() {

	fb_base0 = (int32_t *)p2v_memfb(0x11800000, 1920*1088*4);
	//fb_base0 = (int32_t *)p2v(0x11800000, 1920*1088*4);
        printf("fb_base virt 0x%08x\n", (uint32_t)fb_base0);

        memset(fb_base0,0x00,1920*1088*4);

        fb_base1 = (int32_t *)p2v_memfb(0x12000000, 1920*1088*4);
        //fb_base1 = (int32_t *)p2v(0x12000000, 1920*1088*4);
        printf("fb_base virt 0x%08x\n", (uint32_t)fb_base1);

        memset(fb_base1,0x00,1920*1088*4);

        fb_ctrl = (int32_t *)p2v(0x43c00000, 4096);
	fb_ctrl[56] = 0x5;
        g_pLCDBuffer = (u32)fb_base0;
	working_fb = (u32)fb_base0;
	
	if(get_parameter(&param)) {
              printf("player:get decode parameter failed\n");
              return -1;
        }


	count_anjian1 =1;
	count_anjian6 = 0;
	printf("%s %s %s %s \n", param.wififreq,param.color,param.invert_poll,param.invert_pitch);


	lcdwh = lcdwh_memory_open();	

	if(lcdwh[0]==0){
		lcdwh[0] = 1920;
	}

	 if(!strncmp(param.color,"Red",3)){
                RED = 0xFFFF0000;
		count_anjian3 = 0;
        }else if(!strncmp(param.color,"Blue",4)){
                RED = 0xFF0000FF;
		count_anjian3 = 1;
        }else if(!strncmp(param.color,"Green",5)){
                RED = 0xFF00FF00;
		count_anjian3 = 2;
        }else if(!strncmp(param.color,"Yellow",6)){
                RED = 0xFFFFFF00;
		count_anjian3 = 3;
        }else if(!strncmp(param.color,"Black",5)){
                RED = 0xFF000000;
		count_anjian3 = 4;
        }else if(!strncmp(param.color,"White",5)){
                RED = 0xFFFFFFFF;
		count_anjian3 = 5;
        }else{
                RED=0xFFFFFF00;
        }

	if(!strncmp(param.txpower,"1mW",3)){
                count_anjian7 = 0;
        }else if(!strncmp(param.txpower,"25mW",4)){
                count_anjian7 = 1;
        }else if(!strncmp(param.txpower,"200mW",5)){
                count_anjian7 = 2;
        }else if(!strncmp(param.txpower,"500mW",5)){
                count_anjian7 = 3;
        }else{
        	count_anjian7 = 0;
	}


	if(!strncmp(param.wififreq,"AUTO",4)){
                count_anjian2 = 0;
	}else if(!strncmp(param.wififreq,"5180M",5)){
		count_anjian2 = 1;
	}else if(!strncmp(param.wififreq,"5200M",5)){
		count_anjian2 = 2;
	}else if(!strncmp(param.wififreq,"5220M",5)){
		count_anjian2 = 3;
        }else if(!strncmp(param.wififreq,"5240M",5)){
		count_anjian2 = 4;
        }else if(!strncmp(param.wififreq,"5745M",5)){
		count_anjian2 = 5;
        }else if(!strncmp(param.wififreq,"5765M",5)){
		count_anjian2 = 6;
        }else if(!strncmp(param.wififreq,"5785M",5)){
		count_anjian2 = 7;
        }else if(!strncmp(param.wififreq,"5805M",5)){
		count_anjian2 = 8;
        }else if(!strncmp(param.wififreq,"5825M",5)){
		count_anjian2 = 9;
        }else{

		count_anjian2 = 0;
	}











	if(param.osd >0){
		count_osd = 1;
	}else{
		count_osd =0;
	}

	if(param.plane > 0){
		count_anjian6 =1;
	}else{
		count_anjian6 =0;
	}


	if(lcdwh[0] == 1920){  //1080P

		x_res = 1920;
		y_res = 1080;
		pos_x = x_res/2 - 24*14;
		pos_y = y_res/2 - 36*6;
		x_step = 58;
		blt_bg(fb_base0,pos_x-46,pos_y-20,pos_x+24*30,pos_y+36*12);

		g_dwLcdWidth = 1920;
		g_dwLcdHeight = 1080;		
		blt_bg(fb_base0,pos_x-44,pos_y,pos_x-4,pos_y+36*12);

		Arrow(pos_x-44,pos_y,1);

		LCDDisplayASCII8X16(pos_x,pos_y,   RED,      "RH CH         :               ");
		LCDDisplayASCII8X16(pos_x+16*24,pos_y,RED,param.wififreq);
		LCDDisplayASCII8X16(pos_x,pos_y+58,RED,      "Power         :               ");
		LCDDisplayASCII8X16(pos_x+16*24,pos_y+58,RED,param.txpower);
		LCDDisplayASCII8X16(pos_x,pos_y+58*2,RED,    "Color         :               ");
		LCDDisplayASCII8X16(pos_x+16*24,pos_y+58*2,RED,param.color);
		LCDDisplayASCII8X16(pos_x,pos_y+58*3,RED,    "Roll          :               ");
		LCDDisplayASCII8X16(pos_x+16*24,pos_y+58*3,RED,(param.invert_poll==-1) ? "Positive":"Negative" );
		LCDDisplayASCII8X16(pos_x,pos_y+58*4,RED,    "Pitch         :               ");
		LCDDisplayASCII8X16(pos_x+16*24,pos_y+58*4,RED,(param.invert_pitch==-1) ? "Positive":"Negative" );
		LCDDisplayASCII8X16(pos_x,pos_y+58*5,RED,    "OSD           :               ");
		LCDDisplayASCII8X16(pos_x+16*24,pos_y+58*5,RED,(param.osd > 0)?"ON":"OFF");
		LCDDisplayASCII8X16(pos_x,pos_y+58*6,RED,    "Plane         :               ");
		LCDDisplayASCII8X16(pos_x+16*24,pos_y+58*6,RED,(param.plane >0) ? "Racing Drone":"Fixed Wing");


	}else if(lcdwh[0] == 1280){  //720P
		x_res = 1280;
        	y_res = 720;
	    	pos_x = x_res/2 - 16*14;
		pos_y = y_res/2 - 24*6;
	
		blt_bg(fb_base0,pos_x-46,pos_y-20,pos_x+16*30,pos_y+24*12);	
        	g_dwLcdWidth = 1280;
        	g_dwLcdHeight = 720;
		x_step = 39;
	
		LCDDisplayASCII8X16_720p(pos_x,pos_y,   RED,          "RH CH         :               ");
                LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y,RED,param.wififreq);
                LCDDisplayASCII8X16_720p(pos_x,pos_y+x_step,RED,      "Power         :               ");
                LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y+x_step,RED,param.txpower);
                LCDDisplayASCII8X16_720p(pos_x,pos_y+x_step*2,RED,    "Color         :               ");
                LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y+x_step*2,RED,param.color);
                LCDDisplayASCII8X16_720p(pos_x,pos_y+x_step*3,RED,    "Roll          :               ");
                LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y+x_step*3,RED,(param.invert_poll==-1) ? "Positive":"Negative");
                LCDDisplayASCII8X16_720p(pos_x,pos_y+x_step*4,RED,    "Pitch         :               ");
                LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y+x_step*4,RED,(param.invert_poll==-1) ? "Positive":"Negative");
                LCDDisplayASCII8X16_720p(pos_x,pos_y+x_step*5,RED,    "OSD           :               ");
                LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y+x_step*5,RED,(param.osd > 0)?"ON":"OFF");
                LCDDisplayASCII8X16_720p(pos_x,pos_y+x_step*6,RED,    "Plane         :               ");
                LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y+x_step*6,RED,(param.plane >0) ? "Racing Drone":"Fixed Wing");
	
		
	
	}

    	printf("width %d height %d\n",lcdwh[0],lcdwh[1]);	
}


void set_freq(int value){

	int freq[10] = {0,5180,5200,5220,5240,5745,5765,5785,5805,5825};
	char buf[20];
	if(value == 0){
		strcpy(buf,"AUTO");
	}else{
		sprintf(buf,"%dM",freq[value]);
	}
	if(x_res==1920){
		blt_bg(fb_base0,pos_x+16*24,pos_y,pos_x+25*24,pos_y+36);
		LCDDisplayASCII8X16(pos_x+16*24,pos_y,RED,buf);
	}else if(x_res==1280){
		blt_bg(fb_base0,pos_x+16*16,pos_y,pos_x+25*16,pos_y+36);
		LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y,RED,buf);
	}
}
void set_power(int value){

        char *power[4] = {"1mW","25mW","200mW","500mW"};
        if(x_res==1920){
                blt_bg(fb_base0,pos_x+16*24,pos_y+x_step,pos_x+25*24,pos_y+x_step*2);
                LCDDisplayASCII8X16(pos_x+16*24,pos_y+x_step,RED,power[value]);
        }else if(x_res==1280){
                blt_bg(fb_base0,pos_x+16*16,pos_y+x_step,pos_x+25*16,pos_y+x_step*2);
                LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y+x_step,RED,power[value]);
        }
}



void set_color(int value){

        char *color[6] = {"Red","Blue","Green","Yellow","Black","White"};
        if(x_res==1920){
		blt_bg(fb_base0,pos_x+16*24,pos_y+x_step*2,pos_x+25*24,pos_y+x_step*3);
                LCDDisplayASCII8X16(pos_x+16*24,pos_y+x_step*2,RED,color[value]);
        }else if(x_res==1280){
		blt_bg(fb_base0,pos_x+16*16,pos_y+x_step*2,pos_x+25*16,pos_y+x_step*3);
                LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y+x_step*2,RED,color[value]);
        }
}

void set_poll(int value){

        //char *color[6] = {"RED","BLUE","GREEN","YELLOW","BLACK","WHITE"};
        if(x_res==1920){
		blt_bg(fb_base0,pos_x+16*24,pos_y+x_step*3,pos_x+30*24,pos_y+x_step*4);
		LCDDisplayASCII8X16(pos_x+16*24,pos_y+x_step*3,RED,value ? "Positive" : "Negative");
        }else if(x_res==1280){
		blt_bg(fb_base0,pos_x+16*16,pos_y+x_step*3,pos_x+30*16,pos_y+x_step*4);
		LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y+x_step*3,RED,value ? "Positive" : "Negative");
	}
}

void set_pitch(int value){

        //char *color[6] = {"RED","BLUE","GREEN","YELLOW","BLACK","WHITE"};
        if(x_res==1920){
		blt_bg(fb_base0,pos_x+16*24,pos_y+x_step*4,pos_x+30*24,pos_y+x_step*5);
                LCDDisplayASCII8X16(pos_x+16*24,pos_y+x_step*4,RED,value ? "Positive" : "Negative");
        }else if(x_res==1280){
		blt_bg(fb_base0,pos_x+16*16,pos_y+x_step*4,pos_x+30*16,pos_y+x_step*5);
                LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y+x_step*4,RED,value ? "Positive" : "Negative");
        }
}

void set_osd(int value){

        //char *color[6] = {"RED","BLUE","GREEN","YELLOW","BLACK","WHITE"};
        if(x_res==1920){
                blt_bg(fb_base0,pos_x+16*24,pos_y+x_step*5,pos_x+25*24,pos_y+x_step*6);
                LCDDisplayASCII8X16(pos_x+16*24,pos_y+x_step*5,RED,value ? "ON":"OFF");
        }else if(x_res==1280){
                blt_bg(fb_base0,pos_x+16*16,pos_y+x_step*5,pos_x+25*16,pos_y+x_step*6);
                LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y+x_step*5,RED,value ? "ON" : "OFF");
        }
}



void set_save(int value){

        if(x_res==1920){
                blt_bg(fb_base0,pos_x+16*24,pos_y+x_step*6,pos_x+30*24,pos_y+x_step*7);
                LCDDisplayASCII8X16(pos_x+16*24,pos_y+x_step*6,RED,value ? "Racing Drone":"Fixed Wing");
        }else if(x_res==1280){
                blt_bg(fb_base0,pos_x+16*16,pos_y+x_step*6,pos_x+30*16,pos_y+x_step*7);
                LCDDisplayASCII8X16_720p(pos_x+16*16,pos_y+x_step*6,RED,value ? "Racing Drone" : "Fixed Wing");
        }
}



void save_param(){
	char *freq[10] = {"AUTO","5180M","5200M","5220M","5240M","5745M","5765M","5785M","5805M","5825M"};
	char *power[4] = {"1mW","25mW","200mW","500mW"};
	char *color[6] = {"Red","Blue","Green","Yellow","Black","White"};	
	char *roll[2] = {"1","-1"};	
	char *pitch[2] = {"1","-1"};	
	char buf[4];
	int power_flag;


//	munmap(fb_base0,1920*1088*4);
//	munmap(fb_base1,1920*1088*4);
//	munmap(fb_ctrl,4096);

//	if(count_anjian6 % 2){
		set_conf_string("wififreq",freq[count_anjian2%10]);
		set_conf_string("txpower",power[count_anjian7%4]);
		set_conf_string("color",color[count_anjian3%6]);
		set_conf_string("invert_poll",roll[count_anjian4%2]);	
        	set_conf_string("invert_pitch",pitch[count_anjian5%2]);
        	set_conf_int("osd",count_osd%2);
		set_conf_int("plane",count_anjian6%2);
		save_confile("/data/decode.cfg");
		buf[0] = count_anjian2%10;
		power_flag = count_anjian7%4;

		if(power_flag == 0){
			buf[1] = 0;
		}else if(power_flag == 1){
			buf[1] = 2;
		}else if(power_flag == 2){
			buf[1] = 4;
		}else if(power_flag == 3){
			buf[1] = 5;
		}

		buf[2] = count_anjian6%2;
		buf[3] = 1;  // 192.168.1.1
		sendto(socket_descriptor,buf,4,0,(struct sockaddr *)&address,sizeof(address));	
		buf[3] = 2;  //192.168.1.100
		sendto(socket_descriptor_recv,buf,4,0,(struct sockaddr *)&address_recv,sizeof(address_recv));	
//	}
}


void render(int key_value){


	if(key_value == 0x01){
		if(x_res ==1920){
			blt_bg(fb_base0,pos_x-44,pos_y,pos_x-4,pos_y+36*12);
		}else if(x_res ==1280){
			blt_bg(fb_base0,pos_x-44,pos_y,pos_x-4,pos_y+24*12);
		}
		count_anjian1++;
		if(count_anjian1 % ROW == 1){
			Arrow(pos_x-44,pos_y,1);			
		}

		if(count_anjian1 % ROW == 2){
			Arrow(pos_x-44,pos_y+x_step,1);
		}

		if(count_anjian1 % ROW == 3){
			Arrow(pos_x-44,pos_y+x_step*2,1);
                }
		if(count_anjian1 % ROW == 4){
                        Arrow(pos_x-44,pos_y+x_step*3,1);
                }
		if(count_anjian1 % ROW == 5){
                        Arrow(pos_x-44,pos_y+x_step*4,1);
                }
		if(count_anjian1 % ROW == 6){
                        Arrow(pos_x-44,pos_y+x_step*5,1);
                }
		if(count_anjian1 % ROW == 0){
                        Arrow(pos_x-44,pos_y+x_step*6,1);
                }

	
		

	}else if(key_value == 0x02){
		if(count_anjian1 % 7 == 1){
			count_anjian2++;
			set_freq(count_anjian2%10);			
		}
		if(count_anjian1 % 7 == 2 ){
			count_anjian7++;
			set_power(count_anjian7%4);
		}

		if(count_anjian1 % 7 == 3){
			count_anjian3++;
                        set_color(count_anjian3%6);
                }
		if(count_anjian1 % 7 == 4){
                        count_anjian4++;
                        set_poll(count_anjian4%2);
                }
		if(count_anjian1 % 7 == 5){
                        count_anjian5++;
                        set_pitch(count_anjian5%2);
                }
		if(count_anjian1 % 7 == 6){
                        count_osd++;
                        set_osd(count_osd%2);
                }


		if(count_anjian1 % 7 == 0){
                        count_anjian6++;
                        set_save(count_anjian6%2);
                }

	

	}else if(key_value == 0x10){



	}	

}
