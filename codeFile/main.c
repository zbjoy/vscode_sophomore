#include <stdio.h>
#include <time.h>
#include "LoadFile.h"
#include "codeFile.h"

int main()
{
    srand((unsigned int)time(NULL));
    int lines = getFileLine("data.txt");
    ConfigInfo* configinfo;
    parseFile("data.txt", lines, &configinfo);
    getValueByKey("personId", configinfo, lines);

    codeFile("decode.txt", "data.txt");
    decodeFile("code.txt", "decode.txt");
    freeSpace(configinfo);
    configinfo = NULL;
    return 0;
}