#include "files.h"

typedef struct {
    File *f;
    int pointer;
} FileDescriptor;

FileDescriptor create_file_descriptor(File *f){
    FileDescriptor fd = {
        f,
        f->init
    };
    return fd;
}

unsigned char read(FileDescriptor* fd) {
    unsigned char* pointer = reinterpret_cast<unsigned char*>(fd->f->init + fd->pointer);
    fd->pointer += sizeof(unsigned char);
    return *pointer;
}

 void write(FileDescriptor* fd, int value) {
    unsigned char* pointer = reinterpret_cast<unsigned char*>(fd->f->init + fd->pointer);
    fd->pointer += sizeof(unsigned char);
    *pointer = value;
}