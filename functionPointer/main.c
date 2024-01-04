#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Person
{
    char name[64];
    int age;
};

void selectSort(void* data, int eleSize, int len, int(*compare)(void*, void*))
{
    char* pArr = data;
    char* temp = malloc(sizeof(char) * eleSize);
    for(int i = 0;i < len - 1; i++)
    {
        char* now = pArr + i * eleSize;
        for(int j = i + 1; j < len; j++)
        {
            char* tempCur = pArr + j * eleSize;
            if(compare(now, tempCur))
            {
                now = tempCur;
            }
        } 
        memcpy(temp, now, sizeof(char) * eleSize);
        memcpy(now, pArr + i * eleSize, sizeof(char) * eleSize);
        memcpy(pArr + i * eleSize, temp, sizeof(char) * eleSize);
    }

    free(temp);
}

int myCompare_Person(void* data, void* temp)
{
    struct Person* per1 = data;
    struct Person* per2 = temp;
    if(per1->age < per2->age)
    {
        return 1;
    }
    return 0;
}

void print_Person(struct Person* per)
{
    printf("Name: %s, age %d\n", per->name, per->age);
}

int main()
{
    struct Person p[] = {{"Bob1", 18},{"Bob2", 12},{"Bob3", 19},{"Bob4", 3},{"Bob5", 70}};
    int len = sizeof(p) / sizeof(struct Person);
    int eleSize = sizeof(struct Person);
    for(int i = 0; i < len; i++)
    {
        print_Person(&p[i]);
    }
    selectSort(p, eleSize, len, myCompare_Person);
    for(int i = 0; i < len; i++)
    {
        print_Person(&p[i]);
    }
    return 0;
}