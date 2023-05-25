#include <Arduino.h>

typedef struct File{
    short int fid;
    short int init;
    short int end;
    char label[4];
};

int file_length(File *f){
    return abs(f->init - f->end);
}
