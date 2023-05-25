#include "files.h"

typedef struct Partition{
    int init;
    int end;
    char label[3];
};

typedef struct MagicBlock{
    int init;
    int end;
    File files[10];
};

class FileSystem
{
    public:
        void initialize_file_system(Partition *parttn)
        {
            this->mb = MagicBlock{
                parttn->init,
                parttn->init + 0x64,
            };
        }
        void load_file_system(Partition *prttn)
        {
        }
        void create_file(char name[4])
        {
        }
    private:
        Partition *pt;
        MagicBlock mb;
};