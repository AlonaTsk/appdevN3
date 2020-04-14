#include <stdio.h>
#include "screen.h"
int devicestatus(void){
    printf("%c[5n", ESC);
    char status[40];
    scanf("%s", status);
    int ret;
    char dum;
    sscanf(status, "%c%c%d%c", &dum, &dum, &ret, &dum);
    return ret;
}
void setfgcolor(int fg){
    printf("%c[1;%dm", 0x1B, fg);
} 
void setbgcolor(int bg){
    printf("%c[1;%dm", ESC, bg);
}
void setcolors(int f, int b){
    setfgcolor(f);
    setbgcolor(bg(b));
}
void resetcolors(void){
    printf("%c[0m", 0x1B );
}
void clearscreen(void){
    printf("%c[2J", ESC);
}
void gotoXY(int row, int col){
    printf("%c[%d;%dH", ESC, row, col);
}
void drawbar(int col, int height){
    int i;
    for(i=1; i<=height; i++){
        gotoXY(i, col);
    #ifdef UNICODE
        printf("%s", BAR);
    #else
        printf("%c", '|');
    #endif
    }
}
Position getscreensize(void){
    Position p;
    char ret[100]= "\0";
    int r, c;
    gotoXY(999,999);
    printf("%c[6n", ESC);
    scanf("%s", ret);
#ifdef DEBUG
printf("%s\n", ret);
#endif
#include <string.h>
if(strlen(ret)>0){
    char dum;
    sscanf(ret, "%c%c%d%c%d%c", &dum, &dum, &r, &dum, &c, &dum);
    p.row = r;
    p.col = c;
}else{
    p.row = 0;
    p.col = 0;
}
    //
    return p;    
}