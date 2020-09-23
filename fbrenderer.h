#ifndef FBRENDERER_H
#define FBRENDERER_H

struct screen {

	int x;
	int y;
	int bpp;
	int screensize;
	char * buffer; // framebuffer memory mapped

};

extern struct screen * FBScreen;

struct screen * initFramebufferScreen();

void closeFramebufferScreen(struct screen * FBScreen);

#endif