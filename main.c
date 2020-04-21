#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "sound.h"
int main(void) {
   
    FILE *fp;
    fp = fopen("test.wav", "r");
    WAVheader h = readwavhdr(fp);
    displayWAVhdr(h);
    clearscreen();
    wavdata(h,fp);
    fclose(fp);
    getchar();
    
}