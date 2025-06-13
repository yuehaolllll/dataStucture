#include "Stack.h"

void StackInit(Stack* pst){

    assert(pst);
    pst->data = NULL;
    pst->top = 0;
    pst->capacity = 0;

}

void StackDestroy(Stack* pst){

    assert(pst);

    free(pst->data);
    pst->data = NULL;
    pst->capacity = pst->top = 0;
    
}

bool StackEmpty(Stack* pst){

    assert(pst);

    return pst->top == 0;

}

void StackPush(Stack* pst, STDataType x){

    assert(pst);

    // 检查容量
    if(pst->top == pst->capacity){     // 需要增容
        int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
        STDataType* tmp = (STDataType*)realloc(pst->data, sizeof(STDataType)*newcapacity);
        if(tmp == NULL){
            printf("realloc failed!\n");
            exit(-1);
        }
        pst->data = tmp;
    }

    pst->data[pst->top] = x;
    pst->top++;

}

void StackPop(Stack* pst){

    assert(pst);
    assert(pst->top > 0);

    pst->top--;

}

STDataType StackTop(Stack* pst){

    assert(pst);
    assert(pst->top > 0);

    return pst->data[pst->top-1];

}

int StackSize(Stack* pst){

    assert(pst);
    
    return pst->top;

}


