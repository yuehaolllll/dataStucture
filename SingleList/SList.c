#include "SList.h"


void SLTPrint(SLTNode* phead){

    SLTNode* node = phead;
    while(node != NULL){
        printf("%d\n", node->data);
        node = node->next;
    }
    printf("\n");

}

void SLTPushBack(SLTNode** pphead, SLTDataType data){

    // 创建新节点存放数据
    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    newnode->data = data;
    newnode->next = NULL;

    // 检查头节点是否为空
    if(*pphead == NULL){
        *pphead = newnode;
    }else{
        // 找尾节点
        SLTNode* tail = *pphead;
        while(tail->next != NULL){
            tail = tail->next;
        }

        // 将尾部放入要添加的新节点
        tail->next = newnode;
    }

}