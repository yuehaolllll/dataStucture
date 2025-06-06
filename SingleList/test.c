#include "SList.h"


void TestFunction(){

    SLTNode* plist = NULL;

    SLTPushBack(&plist, 1);
    SLTPushBack(&plist, 2);
    SLTPushBack(&plist, 3);
    SLTPushBack(&plist, 4);
    SLTPushBack(&plist, 5);

    SLTPrint(plist);

    SLTPopBack(&plist);

    SLTPrint(plist);

    SLTPushFront(&plist, -1);

    SLTPrint(plist);

    SLTPopFront(&plist);
    SLTPopFront(&plist);

    SLTPrint(plist);

    SLTNode*pos = SLTFind(plist, 3);
    int i = 0;
    while(pos != NULL){
        i++;
        printf("第%d个->%p->%d\n", i, pos, pos->data);
        pos = SLTFind(pos->next, 3);
        
    }

    SLTNode* pos1 = SLTFind(plist, 2);
    if(pos1 != NULL){
        SLTInsert(&plist, pos1, 20);
    }
    SLTPrint(plist);

    // 后插
    SLTNode* pos2 = SLTFind(plist, 2);
    SLTInsertAfter(&plist, pos2, 20);
    SLTPrint(plist);

    // 清除当前
    SLTNode* pos3 = SLTFind(plist, 3);
    SLTErase(&plist, pos3);
    SLTPrint(plist);

    // 清除之后
    SLTNode* pos4 = SLTFind(plist, 2);
    SLTEraseAfter(&plist, pos4);
    SLTPrint(plist);
    
    // 销毁单链表
    SLTDestroy(&plist);
    SLTPrint(plist);

}


int main(){

    TestFunction();
    return 0;

}