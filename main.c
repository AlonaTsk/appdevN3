#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "sound.h"
#include "comm.h"
int main(void) {
   Position p = getscreensize();
	getchar();
	//Check if the screensize is wide enough to continue the program
	if(p.col < 500){
		printf("The screen size is not wide enough to display %d bars\n",500);
		return 1;
	}
    FILE *fp;
    fp = fopen("test.wav", "r");
    WAVheader h = readwavhdr(fp);
    displayWAVhdr(h);
    clearscreen();
    wavdata(h,fp);
    fclose(fp);
    getchar();
   
}