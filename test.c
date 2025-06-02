#include "SeqList.h"

void TestSeqList1(){

    SeqList s;
    SeqListInit(&s);
    SeqListPushBack(&s, 1);
    SeqListPushBack(&s, 2);
    SeqListPushBack(&s, 3);
    SeqListPushBack(&s, 4);
    SeqListPushBack(&s, 5);
    SeqListPushBack(&s, 6);
    SeqListPushBack(&s, 7);
    SeqListPushBack(&s, 8);
    SeqListPushBack(&s, 9);

    SeqListPrint(&s);

    SeqListPopBack(&s);
    SeqListPopBack(&s);
    SeqListPopBack(&s);

    SeqListPrint(&s);

    SeqListPushFront(&s, 1);
    SeqListPushFront(&s, 1);

    SeqListPrint(&s);

    SeqListPopFront(&s);
    SeqListPopFront(&s);

    SeqListPrint(&s);

    SeqListInsert(&s, 5, 0);

    SeqListPrint(&s);

    SeqListErase(&s, 5);

    SeqListPrint(&s);

    int ret = SeqListFind(&s, 5);
    if(ret != -1){
        SeqListErase(&s, ret);
    }

    SeqListPrint(&s);

    

}

int main(){

    TestSeqList1();
    return 0;
}

