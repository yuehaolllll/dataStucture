#include "SeqList.h"


void SeqListInit(SeqList* ps)
{
    ps->_a = (SLDataType*)malloc(sizeof(SLDataType)*4);
    if(ps->_a == NULL){
        printf("error\n");
        exit(-1);
    }
    ps->size = 0;
    ps->capacity = 4;
}

void SeqListDestroy(SeqList* ps)
{

    free(ps);
    ps->_a = NULL;

}

void SeqListPrint(SeqList* ps)
{

    assert(ps);
    for(int i = 0; i < ps->size; i++){
        printf("%d ", ps->_a[i]);
    }
    printf("\n");

}

void SeqListCheckCapacity(SeqList* ps)
{

    assert(ps);

    if(ps->size == ps->capacity){
        ps->capacity *= 2;
        ps->_a = (SLDataType*)realloc(ps->_a, sizeof(SLDataType)*ps->capacity);
        if(ps->_a == NULL){
            printf("expand capacity failed\n");
            exit(-1);
        }
    }else{
        ;
    }

}

void SeqListPushBack(SeqList* ps, SLDataType e)
{

    // assert(ps);

    // SeqListCheckCapacity(ps);

    // ps->_a[ps->size] = e;
    // ps->size++;

    SeqListInsert(ps, ps->size, e);

}          

void SeqListPopBack(SeqList* ps)
{

    // assert(ps);
    
    // //ps->_a[ps->size-1] = 0;    // actually, this code is useless
    // ps->size--;

    SeqListErase(ps, ps->size-1);

}   

void SeqListPushFront(SeqList* ps, SLDataType e)
{

    // assert(ps);

    // SeqListCheckCapacity(ps);
    
    // int end = ps->size - 1;
    // while(end >= 0){
    //     ps->_a[end + 1] = ps->_a[end];
    //     --end;
    // }

    // ps->_a[0] = e;
    // ps->size++;

    SeqListInsert(ps, 0, e);

}

void SeqListPopFront(SeqList* ps)
{

    // assert(ps);
    // for(int i = 0; i < ps->size-1; i++){
    //     ps->_a[i] = ps->_a[i+1];
    // }

    // ps->size--;

    SeqListErase(ps, 0);

}   

void SeqListInsert(SeqList* ps, int pos, SLDataType e)
{

    assert(ps);
    assert(pos <= ps->size && pos >= 0);

    SeqListCheckCapacity(ps);

    int end = ps->size - 1;
    while(end >= pos){
        ps->_a[end+1] = ps->_a[end];
        end--;
    }

    ps->_a[pos] = e;
    ps->size++;

}

void SeqListErase(SeqList* ps, int pos)
{

    assert(ps);
    assert(pos <= ps->size && pos >= 0);

    int start = pos;
    while(start < ps->size){
        ps->_a[start] = ps->_a[start+1];
        start++;
    }

    ps->size--;

}

int SeqListFind(SeqList* ps, SLDataType e)
{

    assert(ps);

    int i = 0;
    while(i < ps->size){
        if(ps->_a[i] == e){
            return i;
        }else{
            i++;
        }
    }

    return -1;

}



