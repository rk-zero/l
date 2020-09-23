#include <stdio.h>
#include <stdlib.h>

#include "dbg.h"

#include "fbrenderer.h"

//#include <assert.h>
//#include <string.h>

#include <linux/fb.h>

#include <fcntl.h> 				// open()
#include <sys/ioctl.h> 		// ioctl()
#include <unistd.h> 			// close()
#include <sys/mman.h> 		// mmap()

struct fb_fix_screeninfo finfo;
struct fb_var_screeninfo vinfo;
					
int fbfiledevice;		// the /dev/fb0

struct screen * initFramebufferScreen() {

	int fbfiledevice = 0;

	fbfiledevice = open("/dev/fb0", O_RDWR);
  if (fbfiledevice == -1) {
      perror("Error: cannot open framebuffer device");
      exit(1);
  }
  struct fb_var_screeninfo vinfo;
  struct fb_fix_screeninfo finfo;

  // Get fixed screen information
  if (ioctl(fbfiledevice, FBIOGET_FSCREENINFO, &finfo) == -1) {
      perror("Error reading fixed information");
      exit(2);
  }

  // Get variable screen information
  if (ioctl(fbfiledevice, FBIOGET_VSCREENINFO, &vinfo) == -1) {
      perror("Error reading variable information");
      exit(3);
  }

	struct screen * FBScreen = malloc(sizeof(struct screen));
	FBScreen->x = vinfo.xres_virtual;
	FBScreen->y = vinfo.yres_virtual;
	FBScreen->bpp = vinfo.bits_per_pixel;
	FBScreen->screensize = vinfo.xres_virtual * vinfo.yres_virtual * vinfo.bits_per_pixel / 8;

	FBScreen->buffer = (char *)mmap(0, FBScreen->screensize, PROT_READ | PROT_WRITE, MAP_SHARED, fbfiledevice, 0);

	printf("Pointer to FBScreen: %p \n", FBScreen);

	return FBScreen;

}

void closeFramebufferScreen(struct screen * FBScreen) {

	munmap(FBScreen->buffer, FBScreen->screensize);
	close(fbfiledevice);
	free(FBScreen);

}