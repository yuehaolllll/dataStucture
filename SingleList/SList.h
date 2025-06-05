#include <stdio.h>
#include <stdlib.h>

typedef int SLTDataType;

typedef struct SLTNode
{

    SLTDataType data;
    struct SLTNode* next;

}SLTNode;


void SLTPrint(SLTNode* phead);
void SLTPushBack(SLTNode** pphead, SLTDataType data);


