#include <stdio.h>
#include "sound.h"
#include <math.h>
#include "screen.h"

WAVheader readwavhdr(FILE *fp){
    WAVheader myh;
    fread(&myh, sizeof(myh), 1, fp);
    return myh;
}
void displayWAVhdr(WAVheader h){
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
    for(int i=0; i<160; i++){
        fread(samples, sizeof(samples), 1, fp);
        double sum = 0.0;
        for(int j=0; j<500; j++){
            sum = sum + samples[j]*samples[j];
        }
    
        double re = sqrt(sum/500);
#ifdef SDEBUG
        printf("db[%d]=%f\n", i+1, 20*log10(re));
#else 
        if(20*log10(re)>70){
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
        drawbar(i+1, (int)20*log10(re)/3);
        
       
#endif  
      
    }
     gotoXY(1,1); printf("Sample Rate: %d\n", h.sampleRate);
     gotoXY(1,25); printf("Duration: %f s\n", (float)h.subchunk2Size/h.byteRate);
     gotoXY(1,50); printf("Peaks: %d\n", peaks);
     }