
#include <linux/input.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdint.h>
#include <pthread.h> 
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "keyboard.h"
#include "render.h"
#include "confile.h"
#include "udp_util.h"


#define  KEY_EVENT_DEV0_NAME    "/dev/input/event0"
 

static pthread_t keyboard_thread;

void *keyboard_worker(void *arg);

int socket_descriptor;
int socket_descriptor_recv;
struct sockaddr_in address;
struct sockaddr_in address_recv;
char line[4096];
unsigned char key_value;
int flag =0;
static unsigned int count_delay=0;
int flag_atart_osd=0;

void *keyboard_worker(void *arg)
{
	int key_fd  = 0;
	struct input_event key_event  = {0};
	int ret;	

	int flag_down=0;
	int count_down=0;
	key_fd = open(KEY_EVENT_DEV0_NAME, O_RDONLY);
	if(key_fd <= 0)
	{
		printf("---open /dev/input/event0 device error!---\n");
		return ret;
	}
	
	while(1)
	{
		ret = read(key_fd, &key_event, sizeof(key_event));
		
		if(ret)
		{
			if(key_event.type == EV_KEY && key_event.value == 1 )
			{
				flag_down=1;
				count_down=1;
				
			}else if(key_event.type == EV_KEY && key_event.value == 2){
				count_down++;
			}else if(key_event.type == EV_KEY && key_event.value == 0){
			
				if(flag_down == 1 && count_down < 4){  //短按
					if(key_event.code == 0x66)
					{
						key_value = 0x01;
						printf("1 on\n");
					}
					if(key_event.code == 0x67)
                                          {
                                                  key_value = 0x02;
						printf("2 on\n");
                                          }

	
				}	
				if(flag_down == 1 && count_down > 6){   //长按
					 if(key_event.code == 0x66)
                                        {
                                                key_value = 0x10;
						printf("1 long on\n");
                                        }
                                        if(key_event.code == 0x67)
                                          {
			
                                                  key_value = 0x20;
						printf("2 long on\n");
                                          }


				}
					flag_down = 0;
					count_down  =0;
			}	
		}
 
	}
	
	
	
}

long get_file_size(const char *path)
{
    unsigned long filesize = -1;
    struct stat statbuff;
    if(stat(path, &statbuff) < 0)
        return filesize;
    else
        return statbuff.st_size;
}

int readline(FILE* f)
{
    char c;
    int len = 0;

    //printf("++%s\n", __FUNCTION__);
    while ( (c = fgetc(f) ) != EOF && c != '\n' && (len < 1024))
    {
        //printf("%c", c);
        line[len++] = c;
        line[len] = '\0';
    }
    //printf("--%s\n", __FUNCTION__);
    if(len > 1000)
        return 0;
    return len;
}

int searchstr(char *main, char *pattern)
{
    int step, i;
    int mlen = strlen(main);
    int plen = strlen(pattern);

    //printf("++%s\n", __FUNCTION__);
    step = mlen - plen;
    if(step < 0)
        return 0;

    i = 0;
    do {
        if(strncmp(&main[i], pattern, plen) == 0)
            return 1;
        i++;
        step--;
    } while(step >= 0);
    return 0;
}


int kill_mavlink(void)
{
    char kill_cmd[64];
    FILE* fp;
    int len;
    int hit;
    int pid;

    system("ps > /tmp/ps.txt");
    fp = fopen("/tmp/ps.txt", "r");
    if(fp == NULL) {
        printf("cannot open /tmp/ps.txt\n");
        //rec_off();
        //exit(0);
        return -1;
    }
    do {
        len = readline(fp);
        //printf("len %d\n", len);
        hit = 0;
        if(len > 12) { //9+3
            //check "mmcblk1p1" "mnt" present on line
            //printf("%s\n", line);
            hit = searchstr(line, "mavlink_proxy");
            if(!hit)
                continue;
            else {
                sscanf(line,"%05lu ", &pid);
                sprintf(kill_cmd, "kill -9 %d", pid);
                printf("found mavlink pid %d!\n", pid);
                system(kill_cmd);
                fclose(fp);
                return 1;
            }
            //break;
        }
    } while(len>0);
    fclose(fp);
}




void main()
{

	pthread_attr_t attr;
	int len;
	static int count=0;
	
	pthread_attr_init(&attr);
    	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
    	len = pthread_create(&keyboard_thread, &attr, keyboard_worker, NULL);
    	pthread_attr_destroy(&attr);

//	render_pre_init();
        socket_descriptor=init_tx_port(9020,&address);

    	bzero(&address_recv,sizeof(struct sockaddr_in));
    	address_recv.sin_family=AF_INET;
    	address_recv.sin_addr.s_addr=inet_addr("192.168.1.100");
    	address_recv.sin_port=htons(9020);

    	socket_descriptor_recv=socket(AF_INET,SOCK_DGRAM,0);//IPV4




	while(1){

		if(key_value == 0x20){  //2 long button	
			key_value =0x00;
			count++;
			if(count % 2 ==1 ){
				kill_mavlink();	
				system("/data/memtool 0x43C000E0=0 ");
//				usleep(20000);
				render_init();
				flag_atart_osd =1;
			}else{
				save_param();
				system("/data/mavlink_proxy_vsink > /dev/null &");
				flag_atart_osd = 0;
			}		
		}else if(key_value == 0x10){  //1 long button

			render(key_value);
			key_value = 0x00;
			count_delay =0;
		}else if(key_value ==0x01){   //1 button

			if(flag_atart_osd == 1){
				render(key_value);
				key_value = 0x00;
				count_delay=0; 
			}

		}else if(key_value == 0x02){  //2 button
			
			if(flag_atart_osd == 1){
				render(key_value);
				key_value = 0x00;
				count_delay=0;
			}
		}
		if(flag_atart_osd == 1){
			count_delay++;
			if(count_delay >=50){
				count_delay =0;
				count=0;
				save_param();
                                system("/data/mavlink_proxy_vsink > /dev/null &");
				flag_atart_osd =0;
			}
		}
		usleep(100000);
	}
}
