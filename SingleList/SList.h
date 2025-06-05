#include <stdio.h>
#include <stdlib.h>

typedef int SLTDataType;

// 定义single list node
typedef struct SLTNode
{

    SLTDataType data;           // 数据
    struct SLTNode* next;       // 下一节点

}SLTNode;


void SLTPrint(SLTNode* phead);
void SLTPushBack(SLTNode** pphead, SLTDataType x);
void SLTPopBack(SLTNode** pphead);
void SLTPushFront(SLTNode** pphead, SLTDataType x);
void SLTPopFront(SLTNode** pphead);
SLTNode* SLTFind(SLTNode* phead, SLTDataType x);
void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x);
void SLTErase(SLTNode** pphead, SLTNode* pos);
void SLTDestroy(SLTNode** pphead);

