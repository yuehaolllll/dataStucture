#include "List.h"


void Test(){

    ListNode* plist = ListInit();

    ListPushBack(plist, 1);
    ListPushBack(plist, 2);
    ListPushBack(plist, 3);

    ListPrint(plist);            // 新链表： 1 2 3

    ListPopBack(plist);          // 尾删  ： 1 2

    ListPrint(plist);

    ListPushFront(plist, -1); // 头插  ： -1 1 2

    ListPrint(plist);

    ListPopFront(plist);        // 头删   ： 1 2

    ListPrint(plist);

    ListNode* ret = ListFind(plist, 1);
    printf("%d\n", ret->data);

    ListNode* ret1 = ListFind(plist, 2);
    ListInsert(ret1, -2);
    ListPrint(plist);

    ListNode* ret2 = ListFind(plist, -2);
    ListErase(ret2);
    ListPrint(plist);

}

int main()
{
    Test();
    return 0;

}

