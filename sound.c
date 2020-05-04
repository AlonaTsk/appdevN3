#include <stdio.h>
#include "sound.h"
#include <math.h>
#include "screen.h"
#include "comm.h"
WAVheader readwavhdr(FILE *fp){
    WAVheader myh;
    fread(&myh, sizeof(myh), 1, fp);
    return myh;
}
void displayWAVhdr(WAVheader h){
    gotoXY(1,1);
    double Duration;
    Duration=(double) h.subchunk2Size/h.byteRate;
    printf("Duration: %.3f seconds.\n", Duration);
    printf("Chunk ID: ");
    for(int i=0; i<4; i++) printf("%c", h.chunkID[i]);
    printf("\n");
    printf("Chunk size: %d\n", h.chunkSize);
    printf("Num of Channels: %d\n", h.numChannels);
    printf("Sample: %d\n", h.sampleRate);
    printf("Block align:%d\n", h.blockAlign);
    printf("Bits per sample:%d\n", h.bitsPerSample);
}

void wavdata(WAVheader h, FILE *fp){
    //function for reading sound samples using RMS formula.
    short samples[500];
    int peaks=0, flag=0;
    double dbvalue = 0.0;
    char postdata[50];
    for(int i=0; i<160; i++){
        fread(samples, sizeof(samples), 1, fp);
        double sum = 0.0;
        for(int j=0; j<500; j++){
            sum = sum + samples[j]*samples[j];
        }
    
        double re = 20*log10(sqrt(sum/500));
        if (re > dbvalue)
            dbvalue = re;
#ifdef SDEBUG
        printf("db[%d]=%f\n", i+1, re);
#else 
        if(re>70){
             setfgcolor(RED);
             if(flag==0){
                 flag=1;
                 peaks++;
             }
        }
        else {
             setfgcolor(WHITE);
             flag = 0;
        }
        drawbar(i+1, (int)re/3);
        
       
#endif  
      
    }
    resetcolors();
     gotoXY(1,1); printf("Sample Rate: %d\n", h.sampleRate);
     gotoXY(1,25); printf("Duration: %f s\n", (float)h.subchunk2Size/h.byteRate);
     gotoXY(1,50); printf("Peaks: %d\n", peaks);
     gotoXY(1,75); printf("Max decibel value: %.3f\n", dbvalue);
     //sending peaks and maxdbvalue to sound.php(goes to prog.log)
     sprintf(postdata, "Peaks=%d&Maximum_db_value=%.3f", peaks, dbvalue);
     senddata(URL, postdata);
     }