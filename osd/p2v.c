#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/mman.h>


//uint32_t g_count = 256;
int g_size = 0x4;
//unsigned long g_paddr = 0xC001B000;


void *p2v(unsigned int g_paddr, uint32_t g_count)
{
	int fd;
        void * mem;
        void * aligned_vaddr;
        unsigned long aligned_paddr;
        uint32_t aligned_size;
        unsigned int tmp;

        /* Align address to access size */
        g_paddr &= ~(g_size - 1);

        aligned_paddr = g_paddr & ~(4096 - 1);
        aligned_size = g_paddr - aligned_paddr + (g_count * g_size);
        aligned_size = (aligned_size + 4096 - 1) & ~(4096 - 1);

        if ((fd = open("/dev/mem", O_RDWR, 0)) < 0) {
                printf("open /dev/mem failed\r\n");
                return NULL;
        }

        aligned_vaddr = mmap(NULL, aligned_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, aligned_paddr);
        if (aligned_vaddr == NULL) {
                printf("Error mapping address\n");
                close(fd);
                return NULL;
        }

        mem = (void *)((uint32_t)aligned_vaddr + (g_paddr - aligned_paddr));
	return mem;
}

void *p2v_memfb(unsigned int g_paddr, uint32_t g_count)
{
        int fd;
        void * mem;
        void * aligned_vaddr;
        unsigned long aligned_paddr;
        uint32_t aligned_size;
        unsigned int tmp;

        /* Align address to access size */
        g_paddr &= ~(g_size - 1);

        aligned_paddr = g_paddr & ~(4096 - 1);
        aligned_size = g_paddr - aligned_paddr + (g_count * g_size);
        aligned_size = (aligned_size + 4096 - 1) & ~(4096 - 1);

        if ((fd = open("/dev/mem_fb", O_RDWR, 0)) < 0) {
                printf("open /dev/mem failed\r\n");
                return NULL;
        }

        aligned_vaddr = mmap(NULL, aligned_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, aligned_paddr);
        if (aligned_vaddr == NULL) {
                printf("Error mapping address\n");
                close(fd);
                return NULL;
        }

        mem = (void *)((uint32_t)aligned_vaddr + (g_paddr - aligned_paddr));
        return mem;
}


