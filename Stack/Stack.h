#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

// 栈定义
typedef struct Stack
{
    STDataType* data;
    int top;
    int capacity;
}Stack;

// 函数接口
void StackInit(Stack* pst);
void StackDestroy(Stack* pst);
bool StackEmpty(Stack* pst);
void StackPush(Stack* pst, STDataType x);
void StackPop(Stack* pst);
STDataType StackTop(Stack* pst);
int StackSize(Stack* pst);

