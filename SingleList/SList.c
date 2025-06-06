#include "SList.h"


SLTNode* ButListNode(SLTDataType x){

    SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
    
    if(newnode == NULL){
        printf("malloc failed\n");
        exit(-1);
    }

    newnode->data = x;
    newnode->next = NULL;

    return newnode;

}

void SLTPrint(SLTNode* phead){

    SLTNode* node = phead;
    while(node != NULL){
 
        printf("%d ", node->data);
        node = node->next;

    }
    printf("\n");

}

void SLTPushBack(SLTNode** pphead, SLTDataType x){

    assert(pphead);
    if(pphead == NULL){
        perror("SLTPushBack:");
        return;
    }

    // 创建新增节点及赋值
    SLTNode* newnode = ButListNode(x);

    // 如果原链表为空
    if(*pphead == NULL){
        *pphead = newnode;
    }else{                     // 如果原链表不为空，那么找到尾部插入新节点

        SLTNode* tail = *pphead;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = newnode;

    }

}

void SLTPopBack(SLTNode** pphead){

    assert(pphead);
    if(pphead == NULL){
        perror("SLTPopBack:");
        return;
    }

    // 如果链表为空
    if((*pphead) == NULL)
        return;
    

    // 如果链表仅有一个
    if((*pphead)->next == NULL){
        free(*pphead);
        *pphead = NULL;
        return;
    }

    // 非以上两种情况，需要找到倒数第二个节点
    SLTNode* prev = *pphead;
    while(prev->next->next != NULL){
        prev = prev->next;
    }

    free(prev->next);
    prev->next = NULL;

}

void SLTPushFront(SLTNode** pphead, SLTDataType x){

    assert(pphead);
    if(pphead == NULL){
        perror("SLTPushFront");
        return;
    }

    // 新建节点
    SLTNode* newnode = ButListNode(x);

    // 交换
    newnode->next = *pphead;
    (*pphead) = newnode;


}

void SLTPopFront(SLTNode** pphead){

    assert(pphead);
    if(pphead == NULL){
        perror("SLTPushFront");
        return;
    }

    if(*pphead == NULL){
        return;
    }else{
        SLTNode* next = (*pphead)->next;
        free(*pphead);
        *pphead = next;   
    }


}

SLTNode* SLTFind(SLTNode* phead, SLTDataType x){

    SLTNode* node = phead;
    while(node != NULL){
        if(node->data == x){
            return node;
        }else{
            node = node->next;
        }
    }

    return NULL;

}

void SLTInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x){

    assert(pphead);
    if(pphead == NULL){
        perror("SLTPushFront");
        return;
    }

    // 创建新节点
    SLTNode* newnode = ButListNode(x);

    // 判断是否为第一个
    if(*pphead == pos){
        newnode->next = pos;
        *pphead = newnode;
        
    }else{

        // 寻找pos的前一个节点
        SLTNode* posprev = *pphead;
        while(posprev->next != pos){
            posprev = posprev->next;
        }

        posprev->next = newnode;
        newnode->next = pos;

    }

}

void SLTInsertAfter(SLTNode** pphead, SLTNode* pos, SLTDataType x){

    assert(pphead);
    if(pphead == NULL){
        perror("SLTPushFront");
        return;
    }

    // 创建新节点
    SLTNode* newnode = ButListNode(x);

    newnode->next = pos->next;
    pos->next = newnode;

}

void SLTErase(SLTNode** pphead, SLTNode* pos){

    assert(pphead);
    if(pphead == NULL){
        perror("SLTPushFront");
        return;
    }

    SLTNode* prev = *pphead;

    if(pos == *pphead){
        *pphead = pos->next;
        free(pos);
    }else{

        while(prev->next != pos){
            prev = prev->next;
        }

        prev->next = pos->next;
        free(pos);

    }

}

void SLTEraseAfter(SLTNode** pphead, SLTNode* pos){

    assert(pphead);
    if(pphead == NULL){
        perror("SLTPushFront");
        return;
    }

    SLTNode* next = pos->next;
    pos->next = next->next;
    free(next);

}

void SLTDestroy(SLTNode** pphead){

    assert(pphead);
    if(pphead == NULL){
        perror("SLTPushFront");
        return;
    }

    SLTNode* cur = *pphead;

    while(cur != NULL){

        SLTNode* next = cur->next;
        free(cur);
        cur = next;

    }
    *pphead = NULL;

}