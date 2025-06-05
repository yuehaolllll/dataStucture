#include "SList.h"

void Testfunction(){

    SLTNode* plist = NULL;
    SLTPushBack(&plist, 1);
    SLTPushBack(&plist, 2);
    SLTPushBack(&plist, 3);
    SLTPushBack(&plist, 4);

    SLTPrint(plist);


}

int main(){

    Testfunction();
    return 0;

}