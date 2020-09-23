#include <stdio.h>
#include <stdlib.h>
#include "dbg.h"
#include "fbrenderer.h"


int main (int argc, char * argv[]) {

		
		struct screen * FBScreen = initFramebufferScreen();

		printf("Pointer to FBScreen: %p \n", FBScreen);
		printf("x: %d \n", FBScreen->x);
		printf("y: %d \n", FBScreen->y);
		printf("bpp: %d \n", FBScreen->bpp);
		printf("Memoryusage: %d \n", FBScreen->screensize);
				

		return 1;

}