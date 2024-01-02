#include "LoadFile.h"

int getFileLine(const char *filePath)
{
    FILE* fp = fopen(filePath, "r");
    if(fp == NULL)
    {
        perror("getFileLine()\n");
        return -1;
    }

    int lines = 0;
    while(!feof(fp))
    {
        char buf[128];
        if(fgets(buf, 128, fp) == NULL)
        {
            break;
        }
        // if(!feof(fp))
        // {
        //     break;
        // }
        if(isInvalidLine(buf))
        {
            lines++;
        }
    }
    fclose(fp);
    fp = NULL;
    return lines;
}

int isInvalidLine(const char *str)
{
    if(str == NULL)
    {
        return 0;
    }
    char* ret = strchr(str, ':');
    if(ret == NULL)
    {
        return 0;
    }
    return 1;
}

void parseFile(char *filePath, int lines, ConfigInfo **configinfo)
{
    ConfigInfo* config = (ConfigInfo*)malloc(sizeof(ConfigInfo) * lines);
    if(config == NULL)
    {
        return;
    }
    FILE* fp = fopen(filePath, "r");
    if(fp == NULL)
    {
        perror("\n");
        return;
    }

    int index = 0;
    while(!feof(fp))
    {
        char buf[128] = "";
        fgets(buf, 128, fp);
        if(feof(fp))
        {
            break;
        }
        if(!isInvalidLine(buf))
        {
            continue;
        }
        int len = strchr(buf, '\n') - buf;
        buf[len] = '\0';
        char* pos = strchr(buf, ':');
        strncpy(config[index].key, buf, pos-buf);
        config[index].key[pos-buf] = '\0';
        //printf("%s\n", config[index].key);
        strncpy(config[index].value, pos+1, strlen(buf) - (pos - buf) + 1);      
        //printf("%s\n", config[index].value);
        index++;
    }
    fclose(fp);
    fp = NULL;
    *configinfo = config;
}

void getValueByKey(char *key, ConfigInfo *configinfo, int lines)
{
    for(int i = 0; i < lines; i++)
    {
        if(!strcmp(configinfo[i].key, key))
        {
            printf("%s\n", configinfo[i].value);
            return;
        }
    }
    return;
}

void freeSpace(ConfigInfo *configinfo)
{
    if(configinfo == NULL)
    {
        return;
    }
    free(configinfo);
}
