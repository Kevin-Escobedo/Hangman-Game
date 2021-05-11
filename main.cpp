#include "WordDatabase.h"

int main(int argc, char** argv)
{
    bool debug = false;

    if(argc == 2)
    {
        if(strcmp("-d", argv[1]) == 0)
        {
            debug = true;
        }
    }

    WordDatabase wd("words.db");
    wd.addTable();

    if(debug)
    {
        std::cout<<"Created table"<<std::endl;
    }
    
    return 0;
}
