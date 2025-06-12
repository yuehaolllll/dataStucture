#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int ListDataType;

typedef struct ListNode
{
    ListDataType data;
    struct ListNode* next;        // 当前节点的下一个
    struct ListNode* prev;        // 当前节点的上一个
}ListNode;

ListNode* ListInit();
void ListPrint(ListNode* phead);
void ListPushBack(ListNode* phead, ListDataType x);
void ListPopBack(ListNode* phead);
void ListPushFront(ListNode* phead, ListDataType x);
void ListPopFront(ListNode* phead);
ListNode* ListFind(ListNode* phead, ListDataType x);
void ListInsert(ListNode* pos, ListDataType x);
void ListErase(ListNode* pos);
void ListDestroy(ListNode* phead);






