#ifndef __UTIL_h__
#define __UTIL_h__

#include <stdint.h>
struct decoce_param {
        int vout; //0:LCD/TV, 1:HDMI
        int llc;  //0:normal video link. 1:robust video link
        int freq; //freq in KHz
        int bw;   //bandwidth in KHz
        int wr_file; //1:write file
        int timestamp; //0:pass timestamp handle, 1 smooth out
        int cache_ms; //buffer time in ms
	int osd;
	int plane;
	//uint8_t *password;
	char *password;
	char *wififreq;
	char *color;
	char *invert_poll;
	char *invert_pitch;
	char *txpower;
};


#endif // __UTIL_h__
