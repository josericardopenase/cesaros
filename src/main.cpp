#include <Arduino.h>
#include <kernel/filedescriptors.h>

void setup() {
    Serial.begin(9600);
    /*Serial.print(sizeof(File)); 10 bytes*/

    File f = {
        0,
        0x0555,
        0x0FFF,
    };

    FileDescriptor fd = create_file_descriptor(&f);
    FileDescriptor fd1 = create_file_descriptor(&f);

    write(&fd1, 'h');
    write(&fd1, 'o');
    write(&fd1, 'l');
    write(&fd1, 'a');

    unsigned char byte1 = read(&fd);
    unsigned char byte2 = read(&fd);
    unsigned char byte3 = read(&fd);
    unsigned char byte4 = read(&fd);

    Serial.print("Byte 1: ");
    Serial.print((char) byte1);
    Serial.println();
    Serial.print("Byte 2: ");
    Serial.print((char)byte2);
    Serial.println();
    Serial.print("Byte 3: ");
    Serial.print((char)byte3);
    Serial.println();
    Serial.print("Byte 4: ");
    Serial.print((char)byte4);
    Serial.println();
}

void loop() {
}