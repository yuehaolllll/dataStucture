#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



//顺序表

/*
// 静态顺序表设计
typedef int SLDataType;
#define N 10

typedef struct SeqList
{
    SLDataType _a[N];
    int size;
}SeqList;

void SeqListPushBack(SeqList* ps, SLDataType e);
void SeqListPopBack(SeqList* ps);
void SeqListPushFront(SeqList* ps, SLDataType e);
void SeqListPopFront(SeqList* ps);
*/


// 动态顺序表设计
typedef int SLDataType;

typedef struct SeqList
{
    SLDataType* _a;
    int size;       // 有效数据个数
    int capacity;   // 空间大小

}SeqList;


void SeqListInit(SeqList* ps);
void SeqListDestroy(SeqList* ps);
void SeqListPrint(SeqList* ps);
void SeqListCheckCapacity(SeqList* ps);
void SeqListPushBack(SeqList* ps, SLDataType e);          // 尾部添加
void SeqListPopBack(SeqList* ps);                         // 尾部删除
void SeqListPushFront(SeqList* ps, SLDataType e);         // 首部添加
void SeqListPopFront(SeqList* ps);                        // 首部删除
void SeqListInsert(SeqList* ps, int pos, SLDataType e);   // 任意位置添加
void SeqListErase(SeqList* ps, int pos);                  // 任意位置删除
int SeqListFind(SeqList* ps, SLDataType e);




