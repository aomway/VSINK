/*********************************************************************************************
* File��	AscII8x16.c
* Author:	embest	
* Desc��	Ascii table in 8x16 dot lattice 
* History:	
*********************************************************************************************/
#include "typedef.h"
#include <stdlib.h>
#include <string.h>
/*------------------------------------------------------------------------------------------*/
/*	 								constant define						 				    */
/*------------------------------------------------------------------------------------------*/
#define G_AUC_ASCII_LEN 4096

const u8 g_ucAscii8x16_720p[]= {

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,
0x0E,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x0F,0xE0,0x1F,0xE0,0x1F,0xC0,0x3B,0x80,0x37,0x00,0x66,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x18,0xC0,0x18,0xC0,0x18,0xC0,
0x18,0xC0,0xFF,0xF0,0xFF,0xF0,0x38,0xC0,0x38,0xC0,0x31,0xC0,0x31,0xC0,0xFF,0xF0,
0xFF,0xF0,0x31,0x80,0x31,0x80,0x31,0x80,0x31,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x06,0x00,0x1F,0x80,0x3F,0xC0,0x37,0xE0,
0x77,0xC0,0x7E,0x00,0x3E,0x00,0x1E,0x00,0x0F,0x00,0x07,0x80,0x07,0xC0,0x07,0xE0,
0x76,0xE0,0x7E,0xE0,0x76,0xE0,0x37,0xC0,0x1F,0x80,0x06,0x00,0x06,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x78,0xC0,0xFD,0xC0,0xDD,0x80,
0xDD,0x80,0xDF,0x00,0xDF,0x00,0xDF,0x00,0xFF,0xE0,0x7F,0xF0,0x0F,0x70,0x0F,0x30,
0x1B,0x30,0x1B,0x30,0x3B,0x70,0x33,0xF0,0x31,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1E,0x00,0x37,0x00,0x77,0x00,
0x77,0x00,0x77,0x00,0x37,0xE0,0x3D,0xC0,0x39,0xC0,0x7D,0xC0,0xFD,0xC0,0xEF,0x80,
0xEF,0x80,0xE7,0x80,0xE3,0xB0,0xF7,0xF0,0x7F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x78,0x00,0x78,0x00,0x38,0x00,0x38,0x00,0x30,0x00,0xE0,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x70,0x00,0xE0,0x01,0xC0,0x01,0x80,0x03,0x80,0x03,0x00,
0x07,0x00,0x07,0x00,0x07,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x07,0x00,0x07,0x00,
0x07,0x00,0x07,0x00,0x03,0x80,0x01,0x80,0x01,0xC0,0x00,0xE0,0x00,0x70,0x00,0x00,

0x00,0x00,0x00,0x00,0xE0,0x00,0x70,0x00,0x38,0x00,0x18,0x00,0x1C,0x00,0x0C,0x00,
0x0E,0x00,0x0E,0x00,0x0E,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x0E,0x00,0x0E,0x00,
0x0E,0x00,0x0E,0x00,0x1C,0x00,0x18,0x00,0x38,0x00,0x70,0x00,0xE0,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x0F,0x00,
0x07,0x00,0xF6,0xF0,0x7F,0xE0,0x0F,0x00,0x0F,0x00,0x7F,0xE0,0xF6,0xF0,0x07,0x00,
0x0F,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,
0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0xFF,0xF0,0x06,0x00,0x06,0x00,0x06,0x00,
0x06,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x78,0x00,0x78,0x00,0x38,0x00,0x38,0x00,0x30,0x00,0xE0,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x60,0x00,0x60,0x00,0xC0,0x00,0xC0,0x01,0xC0,
0x01,0x80,0x03,0x80,0x03,0x00,0x07,0x00,0x06,0x00,0x0E,0x00,0x0C,0x00,0x1C,0x00,
0x18,0x00,0x38,0x00,0x30,0x00,0x30,0x00,0x60,0x00,0x60,0x00,0xE0,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x39,0xC0,0x39,0xC0,
0x70,0xE0,0x70,0xE0,0x70,0xE0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xF0,0xE0,0x70,0xE0,
0x70,0xE0,0x70,0xE0,0x39,0xC0,0x39,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x03,0x00,0x07,0x00,0x3F,0x00,
0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,0x07,0x00,
0x07,0x00,0x07,0x00,0x07,0x00,0x0F,0x00,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x39,0xC0,0x70,0xE0,
0x70,0xE0,0x70,0xE0,0x00,0xE0,0x01,0xC0,0x01,0xC0,0x03,0x80,0x07,0x00,0x0E,0x00,
0x18,0x60,0x30,0x60,0x60,0xE0,0xFF,0xE0,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x33,0xC0,0x71,0xC0,
0x71,0xE0,0x71,0xE0,0x01,0xC0,0x03,0x80,0x0F,0x00,0x01,0xC0,0x00,0xE0,0x00,0xE0,
0x70,0xE0,0x70,0xE0,0x70,0xE0,0x79,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x80,0x03,0x80,0x03,0x80,0x07,0x80,
0x0F,0x80,0x0F,0x80,0x1B,0x80,0x3B,0x80,0x33,0x80,0x73,0x80,0x63,0x80,0xFF,0xF0,
0x03,0x80,0x03,0x80,0x03,0x80,0x03,0xC0,0x0F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xE0,0x3F,0xE0,0x30,0x00,
0x30,0x00,0x30,0x00,0x30,0x00,0x3F,0x80,0x79,0xC0,0x70,0xE0,0x00,0xE0,0x00,0xE0,
0x70,0xE0,0x70,0xE0,0x70,0xE0,0x71,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC0,0x1D,0xC0,0x39,0xC0,
0x70,0x00,0x70,0x00,0x70,0x00,0xFF,0x80,0xF9,0xC0,0xF0,0xE0,0xF0,0xE0,0xF0,0xE0,
0x70,0xE0,0x70,0xE0,0x70,0xE0,0x39,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xE0,0x7F,0xE0,0x70,0xC0,
0x60,0xC0,0x61,0x80,0x01,0x80,0x03,0x00,0x03,0x00,0x07,0x00,0x06,0x00,0x0E,0x00,
0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x39,0xC0,0x70,0xE0,
0x70,0xE0,0x70,0xE0,0x78,0xE0,0x3D,0xC0,0x1F,0x80,0x3F,0xC0,0x71,0xE0,0x60,0xE0,
0xE0,0xE0,0xE0,0xE0,0x70,0xE0,0x79,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x39,0xC0,0x70,0xE0,
0x70,0xE0,0xF0,0xE0,0xF0,0xE0,0xF0,0xE0,0x70,0xE0,0x7B,0xE0,0x3F,0xE0,0x00,0xE0,
0x00,0xE0,0x01,0xC0,0x79,0xC0,0x7B,0x80,0x3F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x0F,0x00,0x06,0x00,0x0E,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0xC0,0x01,0x80,0x03,0x00,
0x06,0x00,0x0C,0x00,0x18,0x00,0x30,0x00,0x60,0x00,0x30,0x00,0x18,0x00,0x0C,0x00,
0x06,0x00,0x03,0x00,0x01,0x80,0x00,0xC0,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xF0,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x00,0x30,0x00,0x18,0x00,0x0C,0x00,
0x06,0x00,0x03,0x00,0x01,0x80,0x00,0xC0,0x00,0x60,0x00,0xC0,0x01,0x80,0x03,0x00,
0x06,0x00,0x0C,0x00,0x18,0x00,0x30,0x00,0x60,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x39,0xE0,0x60,0xE0,0x60,0xF0,
0x70,0xF0,0x70,0xE0,0x00,0xE0,0x03,0xC0,0x07,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
0x00,0x00,0x00,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x80,0x3C,0xE0,0x30,0x60,
0x77,0xF0,0x6F,0xF0,0xED,0xF0,0xFD,0xF0,0xFD,0xB0,0xF9,0xB0,0xFB,0xF0,0xFF,0xE0,
0x7F,0xC0,0x70,0x30,0x30,0x60,0x38,0xE0,0x0F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0E,0x00,0x0F,0x00,0x0F,0x00,
0x1F,0x00,0x1B,0x00,0x1B,0x80,0x1B,0x80,0x3B,0x80,0x31,0x80,0x3F,0xC0,0x31,0xC0,
0x71,0xC0,0x61,0xE0,0x60,0xE0,0x60,0xE0,0xF1,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x80,0x71,0xE0,0x70,0xE0,
0x70,0xE0,0x70,0xE0,0x70,0xE0,0x71,0xC0,0x7F,0x80,0x71,0xE0,0x70,0xE0,0x70,0x70,
0x70,0x70,0x70,0x70,0x70,0xF0,0x71,0xE0,0xFF,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xE0,0x3C,0xE0,0x78,0x70,
0x70,0x30,0x70,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,
0xF0,0x30,0x70,0x70,0x70,0x60,0x38,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x00,0x73,0xC0,0x71,0xE0,
0x70,0xE0,0x70,0xF0,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,0x70,
0x70,0xE0,0x70,0xE0,0x71,0xE0,0x73,0xC0,0xFF,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xE0,0x70,0xE0,0x70,0x70,
0x70,0x00,0x70,0x00,0x71,0x80,0x71,0x80,0x7F,0x80,0x71,0x80,0x71,0x80,0x70,0x00,
0x70,0x00,0x70,0x30,0x70,0x70,0x70,0xE0,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xE0,0x70,0xF0,0x70,0x70,
0x70,0x30,0x70,0x00,0x70,0xC0,0x71,0xC0,0x7F,0xC0,0x71,0xC0,0x70,0xC0,0x70,0x00,
0x70,0x00,0x70,0x00,0x70,0x00,0x70,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xC0,0x39,0xC0,0x78,0xE0,
0x70,0x60,0xF0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE0,0x00,0xE3,0xF0,0xE0,0xE0,
0xF0,0xE0,0x70,0xE0,0x70,0xE0,0x39,0xE0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xF0,0x70,0xE0,0x70,0xE0,
0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x7F,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,
0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0xF9,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xE0,0x0F,0x00,0x0F,0x00,
0x0F,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,
0x0F,0x00,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x7F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xF0,0x03,0x80,0x03,0x80,
0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,
0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0xF3,0x80,0xE7,0x00,0x7E,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xF0,0x71,0xC0,0x71,0x80,
0x73,0x80,0x77,0x00,0x76,0x00,0x7E,0x00,0x7E,0x00,0x7F,0x00,0x77,0x00,0x73,0x80,
0x73,0x80,0x71,0xC0,0x71,0xC0,0x70,0xE0,0xFD,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0x00,0x78,0x00,0x78,0x00,
0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,0x78,0x00,
0x78,0x00,0x78,0x30,0x78,0x70,0x78,0xE0,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF0,0xF0,0x70,0xE0,0x71,0xE0,
0x71,0xE0,0x79,0xE0,0x79,0xE0,0x79,0xE0,0x7B,0xE0,0x7F,0xE0,0x7F,0xE0,0x7F,0xE0,
0x7F,0xE0,0x6E,0xE0,0x6E,0xE0,0x6E,0xE0,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF1,0xF0,0x78,0x60,0x78,0x60,
0x7C,0x60,0x7C,0x60,0x7E,0x60,0x6E,0x60,0x67,0x60,0x67,0x60,0x63,0xE0,0x63,0xE0,
0x61,0xE0,0x61,0xE0,0x60,0xE0,0x60,0xE0,0xF8,0x60,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x39,0xC0,0x70,0xE0,
0x70,0xE0,0x70,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,
0x70,0x70,0x70,0xE0,0x70,0xE0,0x39,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0x80,0x71,0xE0,0x70,0xE0,
0x70,0x70,0x70,0x70,0x70,0x70,0x70,0xE0,0x71,0xE0,0x7F,0x80,0x70,0x00,0x70,0x00,
0x70,0x00,0x70,0x00,0x70,0x00,0x70,0x00,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0x80,0x39,0xC0,0x70,0xE0,
0x70,0xE0,0xF0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,
0xFF,0x70,0x7F,0xE0,0x7B,0xE0,0x3B,0xC0,0x1F,0xC0,0x01,0xF0,0x01,0xE0,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xC0,0x71,0xE0,0x70,0xE0,
0x70,0xE0,0x70,0xE0,0x70,0xE0,0x71,0xC0,0x7F,0x80,0x77,0x00,0x73,0x80,0x73,0x80,
0x71,0xC0,0x71,0xC0,0x71,0xC0,0x70,0xE0,0xFC,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x1F,0xE0,0x71,0xE0,0x70,0xE0,
0x60,0x60,0x60,0x00,0x70,0x00,0x3C,0x00,0x1F,0x00,0x07,0xC0,0x01,0xE0,0x00,0xE0,
0xE0,0x60,0x60,0xE0,0x70,0xE0,0x79,0xC0,0x7F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x7F,0xE0,0xEE,0x60,0xEE,0x70,
0xCE,0x30,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,
0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xF0,0x70,0x60,0x70,0x60,
0x70,0x60,0x70,0x60,0x70,0x60,0x70,0x60,0x70,0x60,0x70,0x60,0x70,0x60,0x70,0x60,
0x70,0x60,0x70,0x60,0x70,0xE0,0x39,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xF0,0x70,0xE0,0x70,0xC0,
0x70,0xC0,0x38,0xC0,0x39,0xC0,0x39,0x80,0x3D,0x80,0x1D,0x80,0x1F,0x80,0x1F,0x00,
0x1F,0x00,0x0F,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xF0,0xE7,0x70,0xE7,0x60,
0x67,0x60,0x77,0x60,0x7F,0x60,0x7F,0xE0,0x7F,0xC0,0x7F,0xC0,0x3F,0xC0,0x3F,0xC0,
0x3F,0xC0,0x3B,0xC0,0x3B,0x80,0x39,0x80,0x19,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFD,0xF0,0x38,0xC0,0x39,0xC0,
0x39,0x80,0x1D,0x80,0x1F,0x00,0x0F,0x00,0x0E,0x00,0x07,0x00,0x0F,0x00,0x0F,0x80,
0x1B,0x80,0x19,0xC0,0x31,0xC0,0x70,0xE0,0xF9,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xF9,0xF0,0x70,0xE0,0x70,0xC0,
0x38,0xC0,0x39,0x80,0x1D,0x80,0x1F,0x80,0x0F,0x00,0x0F,0x00,0x0E,0x00,0x0E,0x00,
0x0E,0x00,0x0E,0x00,0x0E,0x00,0x0E,0x00,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x3F,0xF0,0x70,0xE0,0x61,0xC0,
0x01,0xC0,0x03,0x80,0x03,0x80,0x07,0x00,0x07,0x00,0x0E,0x00,0x0E,0x00,0x1C,0x00,
0x3C,0x00,0x38,0x70,0x78,0x60,0x70,0xE0,0xFF,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x0F,0xE0,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,
0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,
0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0F,0xE0,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x70,0x00,0x30,0x00,0x38,0x00,0x18,0x00,
0x1C,0x00,0x1C,0x00,0x0C,0x00,0x0E,0x00,0x06,0x00,0x07,0x00,0x07,0x00,0x03,0x00,
0x03,0x80,0x01,0x80,0x01,0xC0,0x01,0xC0,0x00,0xC0,0x00,0xE0,0x00,0x60,0x00,0x70,

0x00,0x00,0x00,0x00,0x7F,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,
0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x03,0x00,0x7F,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x0F,0x00,0x1F,0x80,0x39,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFF,0xF0,

0x00,0x00,0x00,0x00,0x7C,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x3F,0x80,0x71,0xC0,0x70,0xC0,0x07,0xC0,0x3C,0xC0,0x70,0xC0,
0x70,0xC0,0xF0,0xC0,0xF0,0xC0,0x73,0xF0,0x3F,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0xF0,0x00,0x70,0x00,0x70,0x00,
0x70,0x00,0x70,0x00,0x7F,0xC0,0x7D,0xE0,0x78,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xF0,
0x70,0xE0,0x70,0xE0,0x70,0xE0,0x79,0xC0,0x7F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0x80,0x39,0xC0,0x79,0xE0,0x71,0xE0,0x70,0x00,0x70,0x00,
0x70,0x00,0x70,0x60,0x70,0x60,0x38,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x60,0x03,0xE0,0x00,0xE0,0x00,0xE0,
0x00,0xE0,0x00,0xE0,0x1F,0xE0,0x39,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,
0x70,0xE0,0x70,0xE0,0x70,0xE0,0x39,0xF0,0x1F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0x80,0x39,0xC0,0x70,0xE0,0x70,0xE0,0x7F,0xE0,0x70,0x00,
0x70,0x00,0x70,0x00,0x70,0x60,0x38,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x07,0xE0,0x0E,0x70,0x0C,0x70,
0x0C,0x00,0x1C,0x00,0x7F,0xC0,0x1C,0x00,0x1C,0x00,0x1C,0x00,0x1C,0x00,0x1C,0x00,
0x1C,0x00,0x1C,0x00,0x1C,0x00,0x1C,0x00,0x7F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0xF0,0x39,0xF0,0x71,0xC0,0x71,0xC0,0x71,0xC0,0x39,0xC0,
0x3F,0x80,0x70,0x00,0x3E,0x00,0x3F,0xE0,0x60,0xE0,0x60,0x60,0x70,0xE0,0x3F,0xC0,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0xF0,0x00,0x70,0x00,0x70,0x00,
0x70,0x00,0x70,0x00,0x7F,0xC0,0x7D,0xC0,0x78,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,
0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0xF9,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0x00,0x0F,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x3E,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0xC0,0x01,0xC0,0x00,0x00,
0x00,0x00,0x00,0x00,0x0F,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,
0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x01,0xC0,0x73,0x80,0x3F,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x30,0x00,0xF0,0x00,0x70,0x00,0x70,0x00,
0x70,0x00,0x70,0x00,0x73,0xE0,0x71,0x80,0x73,0x00,0x76,0x00,0x7E,0x00,0x7F,0x00,
0x7B,0x80,0x73,0x80,0x71,0xC0,0x71,0xE0,0xFD,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x06,0x00,0x3E,0x00,0x06,0x00,0x06,0x00,
0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0xE0,0xF7,0x70,0xE7,0x70,0xE7,0x70,0xE7,0x70,0xE7,0x70,
0xE7,0x70,0xE7,0x70,0xE7,0x70,0xE7,0x70,0xFF,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0xC0,0x7D,0xC0,0x78,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,
0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0xF9,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0x80,0x39,0xC0,0x70,0xE0,0x70,0xE0,0xE0,0x70,0xE0,0x70,
0xE0,0x70,0x70,0xE0,0x70,0xE0,0x39,0xC0,0x1F,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0x80,0x7D,0xE0,0x78,0xE0,0x70,0xE0,0x70,0x70,0x70,0x70,
0x70,0x70,0x70,0xE0,0x70,0xE0,0x79,0xC0,0x7F,0x80,0x70,0x00,0x70,0x00,0xFC,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0xE0,0x39,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0xF0,0xE0,
0x70,0xE0,0x70,0xE0,0x70,0xE0,0x39,0xE0,0x1F,0xE0,0x00,0xE0,0x00,0xE0,0x03,0xF0,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFD,0xE0,0x1F,0xF0,0x1E,0x00,0x1C,0x00,0x1C,0x00,0x1C,0x00,
0x1C,0x00,0x1C,0x00,0x1C,0x00,0x1C,0x00,0xFF,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x1F,0xC0,0x39,0xE0,0x30,0xE0,0x30,0x00,0x3C,0x00,0x0F,0x80,
0x01,0xC0,0x60,0xE0,0x70,0xE0,0x78,0xE0,0x7F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0C,0x00,0x0C,0x00,
0x0C,0x00,0x1C,0x00,0x7F,0xC0,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,0x0C,0x00,
0x0C,0x00,0x0C,0x00,0x0C,0x60,0x0E,0xE0,0x07,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x30,0x60,0xF3,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,0x70,0xE0,
0x70,0xE0,0x70,0xE0,0x71,0xE0,0x39,0xF0,0x3F,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFD,0xF0,0x78,0xE0,0x38,0xC0,0x39,0xC0,0x19,0x80,0x1D,0x80,
0x1F,0x80,0x0F,0x00,0x0F,0x00,0x0F,0x00,0x06,0x00,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0xF0,0xE7,0x70,0x77,0x60,0x77,0x60,0x7F,0xE0,0x7F,0xC0,
0x3F,0xC0,0x3F,0xC0,0x3F,0xC0,0x39,0x80,0x19,0x80,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFF,0xE0,0x39,0xC0,0x39,0x80,0x1F,0x00,0x0F,0x00,0x07,0x00,
0x0F,0x00,0x1F,0x80,0x19,0xC0,0x31,0xC0,0xFB,0xF0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0xFD,0xF0,0x38,0xC0,0x38,0xC0,0x39,0xC0,0x1D,0x80,0x1F,0x80,
0x0F,0x00,0x0F,0x00,0x0F,0x00,0x06,0x00,0x06,0x00,0x0E,0x00,0x7C,0x00,0x78,0x00,

0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x7F,0xE0,0x71,0xC0,0x63,0x80,0x07,0x80,0x07,0x00,0x0E,0x00,
0x1C,0x00,0x1C,0x60,0x38,0x60,0x70,0xE0,0x7F,0xE0,0x00,0x00,0x00,0x00,0x00,0x00,

0x00,0x00,0x00,0x00,0x01,0xE0,0x01,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,
0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x00,0x0E,0x00,0x03,0x00,0x03,0x80,0x03,0x80,
0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x03,0x80,0x01,0x80,0x01,0xE0,0x00,0x00,

0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,
0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,0x06,0x00,

0x00,0x00,0x00,0x00,0x78,0x00,0x18,0x00,0x1C,0x00,0x1C,0x00,0x1C,0x00,0x1C,0x00,
0x1C,0x00,0x1C,0x00,0x1C,0x00,0x0C,0x00,0x07,0x00,0x0C,0x00,0x1C,0x00,0x1C,0x00,
0x1C,0x00,0x1C,0x00,0x1C,0x00,0x1C,0x00,0x1C,0x00,0x18,0x00,0x78,0x00,0x00,0x00,

0x00,0x00,0x3C,0x00,0x6E,0x00,0x67,0x30,0xC7,0xF0,0x03,0xE0,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00


};


extern u32 g_pLCDBuffer;
extern u32 g_dwLcdWidth;
extern u32 g_dwLcdHeight;

static void PutTFT16Bit_480640_720p(u32 x,u32 y, u32 c)
{
	// RGB24
    if(x<(g_dwLcdWidth) && y<(g_dwLcdHeight))
        memcpy((unsigned char*)(g_pLCDBuffer + (x+y*g_dwLcdWidth)*4), (unsigned char*)&c, 4);
}
/*
static u32 GetTFT16Bit_480640(u32 x,u32 y)
{
	u32 color = 0;
	
	// RGB24
	memcpy((unsigned char*)&color, (unsigned char*)(g_pLCDBuffer + (x+y*g_dwLcdWidth)*4), 4);
	return color;
}
*/
void LCDDisplayASCII8X16_720p(u32 x0, u32 y0, u32 ForeColor, char * s)
{
	u32 i,j,k,x,y,xx;
	u8 qm;
	u32 ulOffset;
	u16 ywbuf[24],temp[2];
	u32 tmp;
    
	for(i = 0; i < strlen((const char*)s); i++)
	{
		if(((u8)*(s+i) >= 127) || (((u8)*(s+i) <= 31)))
		{
			temp[0] = *(s + i);
			temp[1] = '\0';
			return;
		}
		else
		{
			qm = *(s+i);
			qm -= 0x20;
    		ulOffset = (u32)(qm) * 48;	
    		for (j = 0; j < 24; j ++)
    		{
			tmp = j<<1;
    			ywbuf[j] = (g_ucAscii8x16_720p[ulOffset + tmp] << 8) | g_ucAscii8x16_720p[ulOffset + tmp + 1];
    		}

    		for(y = 0; y < 24; y++)
    		{
       		    for(x = 0; x < 16; x++) 
       		    {
           			k = x % 16;
	       			if (ywbuf[y]  & (0x8000 >> k))
	       			{
	       				xx = x0 + x + i*16;
	       				PutTFT16Bit_480640_720p( xx, y + y0, ForeColor);
	       			}
	   		    }
    	    }
         }
    }
}
