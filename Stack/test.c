#include "Stack.h"

void TestStack(){

    Stack st;
    StackInit(&st);
    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);
    StackPush(&st, 4);

    // 栈，后进先出
    while(!StackEmpty(&st)){
        printf("%d ", StackTop(&st));
        StackPop(&st);
    }

    StackDestroy(&st);

}

int main(){

    TestStack();
    return 0;

}