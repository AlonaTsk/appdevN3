//#define SDEBUG

typedef struct{
    char chunkID[4];
    int chunkSize;
    char format[4];
    char subchunk1ID[4];
    int subchunk1Size;
    short audioFormat;
    short numChannels;
    int sampleRate;
    int byteRate;
    short blockAlign;
    short bitsPerSample;
    char subchunk2ID[4];
    int subchunk2Size;
}WAVheader;

WAVheader readwavhdr(FILE *fp);
void displayWAVhdr(WAVheader h);
void wavdata(WAVheader h, FILE *fp);