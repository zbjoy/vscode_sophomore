#include "codeFile.h"

void codeFile(char *destFilePath, char *sourceFilePath)
{
    FILE* fpDest = fopen(destFilePath, "w");
    FILE* fpSrc = fopen(sourceFilePath, "r");
    if(!fpDest || !fpSrc)
    {
        perror("\n");
        return;
    }

    while(!feof(fpSrc))
    {
        char ch = fgetc(fpSrc);
        if(ch == EOF)
        {
            break;
        }

        short temp = (short)ch;
        temp <<= 4;
        temp |= 0x8000;
        temp += rand() % 16;
        //printf("%hd\n", temp);

        fprintf(fpDest, "%hd", temp);
    }
    fclose(fpDest);
    fclose(fpSrc);
}

void decodeFile(char *destFilePath, char *sourceFilePath)
{
    FILE* fpDest = fopen(destFilePath, "w");
    FILE* fpSrc = fopen(sourceFilePath, "r");

    while(!feof(fpSrc))
    {
        short temp;
        fscanf(fpSrc, "%hd", &temp);
        if(feof(fpSrc))
        {
            break;
        }
        temp <<= 1;
        temp >>= 5;
        char ch = (char)temp;
        fputc(ch, fpDest);
    }

    fclose(fpDest);
    fclose(fpSrc);
}
