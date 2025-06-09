


/*
// practice 1: 原地移除数组中的元素。要求O(N)
//解题思路：定义两个起始点（src、dst），当src遇到要去除的数时，src++，反之将src指向的数赋给dst指向的位置，然后src、dst均自增

#include <stdio.h>
int removeElement(int* nums, int numSize, int val){

    int src = 0;
    int dst = 0;

    while(src < numSize){
        if(nums[src] == val){
            src += 1;
            
        }else{
            nums[dst] = nums[src];
            dst++;
            src++;
        }

    }
    
    return dst;
}

int main()
{

    int arr[10] = {1, 3, 3, 4, 5, 8, 9, 3, 7, 1};
    int sz = sizeof(arr) / sizeof(arr[0]);
    int ret = removeElement(arr, sz, 3);
    for(int i = 0; i < ret; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;

}
*/



/*
//practice 2：给定一个有序数组，去除数组中的重复元素。要求O(1).

#include <stdio.h>
int removeDuplicaties(int* nums, int numSize){

    int prev = 0;
    int cur = 1;
    int dst = 0;
    if(numSize == 0){
        return 0;
    }
    while(cur < numSize){
        if(nums[prev] == nums[cur]){
            prev++;
            cur++;
        }else{
            nums[dst] = nums[prev];
            dst++;
            prev++;
            cur++;
        }
    }
    nums[dst] = nums[prev];
    dst++;
    return dst;

}

int main(){

    int arr[] = {2,2,2,3,3,3,5,5,6,7,8,9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int ret = removeDuplicaties(arr, sz);
    for(int i = 0; i < ret; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;

}

*/


/*
//practice 3: 数组与数字的相加

#include <stdio.h>
#include <stdlib.h>
int* addToArrayForm(int* A, int ASize, int K, int* returnSize){

    int kNum = K;
    int KSize = 0;
    //1.求K的位数     123->12->1->0
    while(kNum){
        KSize++;
        kNum /= 10;
    }

    //2.以位数多的为参照
    int len = ASize > KSize ? ASize : KSize;

    //3.开辟一个空间（大小为len+1）
    int* retArr = (int*)malloc(sizeof(int)*(len+1));

    //4.对位求和
    int A_i = ASize - 1;       //A数字的索引(从最后一位开始)
    int ret_i = 0;             //存入retArr的索引
    int nextNum = 0;           //进位记录
                       
    while(len--){

        int a = 0;
        if(A_i >= 0){
            a = A[A_i];
            A_i--;
        }

        int ret = a + K%10 + nextNum;
        K /= 10;

        if(ret > 9){
            ret -= 10;
            nextNum = 1;
        }else{
            nextNum = 0;
        }
        retArr[ret_i] = ret;
        ret_i++;

    }

    if(nextNum == 1){
        retArr[ret_i] = 1;
        ret_i++;
    }

    //5.翻转retArr
    int left = 0;
    int right = ret_i - 1;
    while(left < right){
        int tmp = retArr[left];
        retArr[left] = retArr[right];
        retArr[right] = tmp;

        left++;
        right--;
    }

    *returnSize = ret_i;
    return retArr;

}


int main(){

    int arr[] = {9,9,9,9,9};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int K = 999;
    int retSize = 0;
    // 遇到的问题，之前出错时因为创建了一个int* retSize，导致这个指针是一个野指针，没有开辟内存，导致无法访问。
    //正确做法为创建一个int类型的变量，将其地址传给函数，函数借用地址改变其值。

    int* ret = addToArrayForm(arr, sz, K, &retSize);

    for(int i = 0; i < retSize; i++){
        printf("%d ", ret[i]);
    }
    return 0;

}
*/


/*
//practice 3: 合并两个有序数组

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n){

    // 1.开辟一个大小为m+n的空间
    int* nums3 = (int*)malloc(sizeof(int)*(m+n));

    // 2.比较nums1和nums2中的各个元素，存入nums3
    int i = 0;
    int j = 0;
    int k = 0;
    while(i < m && j < n){
        if(nums1[i] < nums2[j]){
            nums3[k] = nums1[i];
            i++;
            k++;
        }else{
            nums3[k] = nums2[j];
            j++;
            k++;
        }
    }
    while(i < m){
        nums3[k] = nums1[i];
        i++;
        k++;
    }
    while(j < n){
        nums3[k] = nums2[j];
        j++;
        k++;
    }

    // 3.将nums3中的元素移入nums1中
    memcpy(nums1, nums3, sizeof(int)*(m+n));
    free(nums3);


}

int main(){

    int arr1[11] = {1,1,2,2,4,6,7,0,0,0,0};
    int arr2[6] = {3,4,5,6,0,0};
    int sz1 = sizeof(arr1)/sizeof(arr1[0]);
    int sz2 = sizeof(arr2)/sizeof(arr2[0]);
    merge(arr1, 11, 7, arr2, 6, 4);
    for(int i = 0; i < 11; i++){
        printf("%d ", arr1[i]);
    }
    return 0;

}
*/


/*
// practice 4: 旋转数组

#include <stdio.h>

void rotate(int* nums, int numSize, int k){

    // 1.判断旋转多少个
    if(k >= numSize){
        k %= numSize;
    }

    // 2.逆序前numSize - k个
    int left1 = 0;
    int right1 = numSize - k - 1;
    while(left1 < right1){
        int tmp = nums[left1];
        nums[left1] = nums[right1];
        nums[right1] = tmp;
        left1++;
        right1--;
    }

    // 3.逆序后k个
    int left2 = numSize - k;
    int right2 = numSize - 1;
    while(left2 < right2){
        int tmp = nums[left2];
        nums[left2] = nums[right2];
        nums[right2] = tmp;
        left2++;
        right2--;
    }

    // 4.逆序整个nums数组
    int left = 0;
    int right = numSize - 1;
    while(left < right){
        int tmp = nums[left];
        nums[left] = nums[right];
        nums[right] = tmp;
        left++;
        right--;
    }

}


int main(){

    int arr[] = {1,2,3,4,5,6,7,8};
    int sz = sizeof(arr)/sizeof(arr[0]);
    rotate(arr, sz, 3);

    for(int i = 0; i < sz; i++){
        printf("%d ", arr[i]);
    }

    return 0;

}
*/


/*
// practice 5: 单链表删除指定值

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};

struct ListNode* removeElement(struct ListNode* head, int val){

    struct ListNode* cur = head;
    struct ListNode* prev = NULL;

    while(cur != NULL){

        if(cur->val == val){

            if(cur == head){
                head = cur->next;
                free(cur);
                cur = head;
            }else{
                prev->next = cur->next;
                free(cur);
                cur = prev->next;
            }
        }else{
            prev = cur;
            cur = cur->next;
        }
    }

    return head;

}


void ListNodePushBack(struct ListNode** pphead, int x){

    // 创建新节点
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = x;
    newnode->next = NULL;

    // 如果原链表为空
    if(*pphead == NULL){
        *pphead = newnode;
    }else{
        // 找到链表尾部
        struct ListNode* tail = *pphead;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = newnode;
    }
    

}

void ListNodePrint(struct ListNode* phead){

    struct ListNode* node = phead;
    while(node != NULL){
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");

}

void Test(){

    struct ListNode* plist = NULL;
    ListNodePushBack(&plist, 1);
    ListNodePushBack(&plist, 2);
    ListNodePushBack(&plist, 1);
    ListNodePushBack(&plist, 1);

    ListNodePrint(plist);

    struct ListNode* ret = removeElement(plist, 1);

    ListNodePrint(ret);

}

int main()
{

    Test();
    return 0;

}
*/


// practice 6

#include <stdio.h>
#include <stdlib.h>

struct ListNode
{
    int val;
    struct ListNode* next;
};


// 链表的分割
struct ListNode* partitionList(struct ListNode* list, int x){

    struct ListNode* cur = list;
    struct ListNode* head1 = NULL;
    struct ListNode* tail1 = NULL;
    struct ListNode* head2 = NULL;
    struct ListNode* tail2 = NULL;

    while(cur != NULL){

        // 小于x的部分
        if(cur->val < x){

            if(head1 == NULL){
                head1 = tail1 = cur;
            }else{
                tail1->next = cur;
                tail1 = tail1->next;
            }

        }else{     // 大于x的部分

            if(head2 == NULL){
                head2 = tail2 = cur;
            }else{
                tail2->next = cur;
                tail2 = tail2->next;
            }

        }

        cur = cur->next;

    }

    tail2->next = NULL;
    // 合并两个链表
    tail1->next = head2;

    return head1;

}

// 合并两个链表
struct ListNode* mergeList(struct ListNode* l1, struct ListNode* l2){

    if(l1 == NULL){
        return l2;
    }

    struct ListNode* head = NULL;
    struct ListNode* tail = NULL;


    while(l1 != NULL && l2 != NULL){
        if(l1->val < l2->val){

            if(head == NULL){
                head = tail = l1;
            }else{
                tail->next = l1;
                tail = tail->next;
            }
            l1 = l1->next;
            
        }else{
            if(head == NULL){
                head = tail = l2;
            }else{
                tail->next = l2;
                tail = tail->next;
            }
            l2 = l2->next;
        }
    }

    if(l1 != NULL){
        tail->next = l1;
    }

    if(l2 != NULL){
        tail->next = l2;
    }


    return head;

}

// 寻找链表的倒数第k个节点
struct ListNode* kNode(struct ListNode* head, int k){

    struct ListNode* fast = head;
    struct ListNode* slow = head;

    while(k){
        if(fast != NULL){
            fast = fast->next;
            k--;
        }else{
            return NULL;
        }
        
    }

    while(fast != NULL){

        fast = fast->next;
        slow = slow->next;

    }

    return slow;

}

// 寻找链表的中间节点（如果为偶数个则返回第二个）
struct ListNode* middleNode(struct ListNode* head){

    // 方法：快慢指针
    struct ListNode* slow = head;
    struct ListNode* fast = head;

    while(fast != NULL && fast->next != NULL){

        slow = slow->next;
        fast = fast->next->next;

    }

    return slow;

}


// 翻转链表
struct ListNode* reverseList_PushFront(struct ListNode* head){

    if(head == NULL){
        return NULL;
    }

    struct ListNode* newHead = NULL;
    struct ListNode* node = head;
    struct ListNode* next = head->next;
    
    while(node != NULL){

        node->next = newHead;
        newHead = node;
        node = next;
        if(next != NULL){
            next = next->next;
        }
        
    }

    return newHead;

}

struct ListNode* reverseList(struct ListNode* head){

    // 如果链表为空
    if(head == NULL){
        return NULL;
    }

    // 创建节点索引
    struct ListNode* n1 = NULL;
    struct ListNode* n2 = head;
    struct ListNode* n3 = head->next;

    // 翻转链表
    while(n2 != NULL){

        // 翻转
        n2->next = n1;

        // 迭代链表
        n1 = n2;
        n2 = n3;
        if(n3 != NULL){
            n3 = n3->next;
        }

    }

    return n1;

}

void ListNodePushBack(struct ListNode** pphead, int x){

    // 创建新节点
    struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newnode->val = x;
    newnode->next = NULL;

    // 如果原链表为空
    if(*pphead == NULL){
        *pphead = newnode;
    }else{
        // 找到链表尾部
        struct ListNode* tail = *pphead;
        while(tail->next != NULL){
            tail = tail->next;
        }
        tail->next = newnode;
    }
    

}

void ListNodePrint(struct ListNode* phead){

    struct ListNode* node = phead;
    while(node != NULL){
        printf("%d ", node->val);
        node = node->next;
    }
    printf("\n");

}

void Test(){

    struct ListNode* plist = NULL;
    ListNodePushBack(&plist, 2);
    ListNodePushBack(&plist, 5);
    ListNodePushBack(&plist, 8);
    ListNodePushBack(&plist, 1);
    ListNodePushBack(&plist, 2);
    ListNodePushBack(&plist, 3);
    ListNodePushBack(&plist, 4);
    ListNodePushBack(&plist, 2);
    ListNodePushBack(&plist, 0);

    ListNodePrint(plist);

    struct ListNode* ret = partitionList(plist, 4);
    ListNodePrint(ret);

}

int main()
{

    Test();
    return 0;

}




