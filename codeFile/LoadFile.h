#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct ConfigInfo
{
    char key[64];
    char value[64];
}ConfigInfo;

int getFileLine(const char* filePath);

int isInvalidLine(const char* str);

void parseFile(char* filePath, int lines, ConfigInfo** configinfo);

void getValueByKey(char* key, struct ConfigInfo* configinfo, int lines);

void freeSpace(struct ConfigInfo* configinfo);