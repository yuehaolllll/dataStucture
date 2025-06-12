#include "List.h"

ListNode* BuyListNode(ListDataType x){

    ListNode* node = (ListNode*)malloc(sizeof(ListNode));
    node->data = x;

}

ListNode* ListInit(){

    // 哨兵位头结点
    ListNode* phead = (ListNode*)malloc(sizeof(ListNode));
    phead->next = phead;
    phead->prev = phead;

    return phead;
}

void ListPrint(ListNode* phead){

    assert(phead);

    ListNode* node = phead->next;
    while(node != phead){

        printf("%d ", node->data);
        node = node->next;

    }
    printf("\n");

}


void ListPushBack(ListNode* phead, ListDataType x){

    assert(phead);

    // // 开辟新节点
    // ListNode* newnode = BuyListNode(x);
    // // 找到尾节点
    // ListNode* tail = phead->prev;

    // // 将新节点尾插
    // tail->next = newnode;
    // newnode->next = phead;
    // newnode->prev = tail;
    // phead->prev = newnode;
    ListInsert(phead, x);

}

void ListPopBack(ListNode* phead){

    assert(phead);
    
    if(phead->next == phead){
        return;
    }else{
        // 找到尾
        ListNode* tail = phead->prev;

        // 尾删即把tail的前一个与phead相连
        phead->prev = tail->prev;
        tail->prev->next = phead;

        free(tail);
    }

    

}

void ListPushFront(ListNode* phead, ListDataType x){

    assert(phead);

    // // 新建节点
    // ListNode* newnode = BuyListNode(x);

    // // 找到第一个
    // ListNode* first = phead->next;

    // // 头插
    // phead->next = newnode;
    // newnode->next = first;
    // newnode->prev = phead;
    // first->prev = newnode;
    ListInsert(phead->next, x);

}

void ListPopFront(ListNode* phead){

    assert(phead);

    if(phead->next == phead){
        return;
    }else{
        // 找到第一个
        ListNode* first = phead->next;

        // 头删
        phead->next = first->next;
        first->next->prev = phead;

        free(first);
    }

}

ListNode* ListFind(ListNode* phead, ListDataType x){

    assert(phead);

    ListNode* cur = phead->next;

    while(cur != phead){

        if(cur->data == x){
            return cur;
        }
        cur = cur->next;
    }

    return NULL;

}

void ListInsert(ListNode* pos, ListDataType x){

    assert(pos);

    // 构建新节点
    ListNode* newnode = BuyListNode(x);

    // 找到pos的前一个节点
    ListNode* posPrev = pos->prev;
    // 插入新节点
    posPrev->next = newnode;
    newnode->prev = posPrev;
    newnode->next = pos;
    pos->prev = newnode;

}

void ListErase(ListNode* pos){

    assert(pos);

    // 删除pos节点
    pos->prev->next = pos->next;
    pos->next->prev = pos->prev;

    free(pos);

}


