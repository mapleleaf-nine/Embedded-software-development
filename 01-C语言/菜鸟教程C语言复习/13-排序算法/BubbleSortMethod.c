/*冒泡排序（英语：Bubble Sort）是一种简单的排序算法。它重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序（如从大到小、首字母从A到Z）错误就把他们交换过来。*/

#include <stdio.h>

int BubbleSort(int arr[], int len);

int main()
{
    int arr[] = {23,43,65,86,53,11,35,24,54};
    int i,len = 0;
    /*求数组元素个数*/
    len = sizeof(arr)/sizeof(*arr);
    printf("%d\n",len);
    BubbleSort( arr, len);
    for(i=0;i<len;i++)
    {
        printf("%d,",arr[i]);
    }
    return 0;
}
/*冒泡排序函数*/
int BubbleSort(int arr[], int len)
{
    int i,j,temp;
    for(i=0;i<len-1;i++)
        for(j=0;j<len-1-i;j++)
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    return 0;
}