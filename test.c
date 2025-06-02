#include <stdio.h>


// practice 1: 原地移除数组中的元素
int removeElement(int* nums, int numSize, int val){

    int src = 0;
    int dst = 0;

    while(src <= numSize){
        if(nums[src] == val){
            src += 1;
            
        }else{
            nums[dst] = nums[src];
            dst++;
            src++;
        }

    }
    
    return dst-1;
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

