#include <stdio.h>
#include <unistd.h>
#include "screen.h"
#include "sound.h"
int main(void) {
    Position cur = getscreensize();
    gotoXY(1,1);
    printf("Screen size, Row=%d, Col=%d\n", cur.row, cur.col);
    printf("Press any key the screen will be cleared\n");
    getchar();
    getchar();
    int i;
    for(int i=0; i<cur.row; i++){
        setcolors(YELLOW, MAGENTA);
        clearscreen();
        float step = (float)cur.col/cur.row;
        gotoXY(i+1, step*i+1);
        printf("HELLO\n");
        usleep(500000);
    }
    /*for(int i=0; i<15; i++){
        setcolors(YELLOW, MAGENTA);
        clearscreen();
        gotoXY(i+1, 70);
        printf("HELLO\n");
        usleep(500000);
    }
    for(int i=15; i>=0; i--){
        setcolors(YELLOW, MAGENTA);
        clearscreen();
        gotoXY(15, 4*i+1);
        printf("HELLO\n");
        usleep(500000);
    }
    for(int i=15; i>=0; i--){
        setcolors(YELLOW, MAGENTA);
        clearscreen();
        gotoXY(i+1, 1);
        printf("HELLO\n");
        usleep(500000);
    }
    */
    //printf("The following message will be in RED color\n");
    gotoXY(14,35);
    setfgcolor(33);
    printf("e1900320\n");
    getchar();
    drawbar(30, 30); 
    drawbar(50, 30);
    
    getchar();
    resetcolors();
    clearscreen();
    printf("This line is back to default color\n");
    FILE *fp;
    fp = fopen("test.wav", "r");
    WAVheader h = readwavhdr(fp);
    displayWAVhdr(h);
    wavdata(h,fp);
    fclose(fp);
    
}