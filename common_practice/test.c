


/*
// practice 1: 原地移除数组中的元素。要求O(N)
//解题思路：定义两个起始点（src、dst），当src遇到要去除的数时，src++，反之将src指向的数赋给dst指向的位置，然后src、dst均自增
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


