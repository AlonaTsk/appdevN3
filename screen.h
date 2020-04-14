#define ESC 27
enum FG {BLACK=30,RED,GREEN,YELLOW,BLUE,MAGENTA,CYAN,WHITE};
#define bg(c) (c+10) //this is macro definition
#define UNICODE
#define BAR "\u2590"
#define DEBUG

typedef struct{
    int row;
    int col;
}Position;//cursor position

void setfgcolor(int);
void setbgcolor(int);
void setcolors(int, int);
void resetcolors(void);
void clearscreen(void);
void gotoXY(int, int);
void drawbar(int, int);
Position getscreensize(void);
//Is it obligatory to use exactly nano during this course?