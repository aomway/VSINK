#ifndef _P2V_H_
#define _P2V_H_

#include <stdint.h>

#define VENC_DBB_BASE (0x83c00000)

typedef struct venc_dbb_regs {
uint32_t VIDINRES;	//0x0
uint32_t VIDINSCAN;	//0x1
uint32_t VIDINTS;	//0x2
uint32_t VIDINUIT;	//0x3
uint32_t VIDINLEVEL;	//0x4 
uint32_t VID_PAD1[11];	//0x5~0xf
uint32_t GOPATTR;	//0x10
uint32_t SLICEATTR;	//0x11
uint32_t QPSLICEATTR;	//0x12
uint32_t RCATTR;	//0x13
uint32_t RCQPLIMS;	//0x14
uint32_t RCXOPTS;	//0x15
uint32_t PREDATTR;	//0x16
uint32_t ENCOPTS;	//0x17
uint32_t VID_PAD2[8];	//0x18~0x1f
uint32_t INSTRUCTION;	//0x20
uint32_t STATUS;	//0x21
uint32_t ERRID;		//0x22
uint32_t IDRCNT;	//0x23
uint32_t FRAMECNT;	//0x24
uint32_t SEQLEN;	//0x25
uint32_t PICLEN;	//0x26
uint32_t SLICELEN;	//0x27
uint32_t FRAMEDROPCNT;	//0x28
uint32_t PL0P16X16MVS;	//0x29
uint32_t VID_PAD[7];	//0x2a~0x30
uint32_t DBB_CTRL;	//0x31
uint32_t IIS_DAT;	//0x32
uint32_t FPGAMAGIC;	//0x33
uint32_t VCAP_CTRL;	//0x34
uint32_t ARMMAGIC;	//0x35
uint32_t SYSCTRL3;	//0x36
} t_venc_dbb_regs, *p_venc_dbb_regs;

void *p2v(unsigned int g_paddr, uint32_t g_count);

#endif
