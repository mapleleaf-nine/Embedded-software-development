/*选择排序（Selection sort）是一种简单直观的排序算法。它的工作原理如下。首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，
然后，再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。*/
#include <stdio.h>
int SelectionSort(int arr[], int len);
int main()
{
    int arr[] = {23,43,65,86,53,11,35,24,54};
    int i,len = 0;
    /*求数组元素个数*/
    len = sizeof(arr)/sizeof(*arr);
    printf("%d\n",len);
    SelectionSort(arr, len);
    for(i=0;i<len;i++)
    {
        printf("%d,",arr[i]);
    }
    return 0;
}

int SelectionSort(int arr[], int len)
{
    int i,j,temp;
    for(i=0;i<len-1;i++)
    {
        int min = i;
        for(j=i+1;j<len;j++)
        {
            if(arr[min]>arr[j])
            {
                min = j;
            }
        }
        if(min != i)             //存在比arr[i]小的值
        {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
    return 0;
}

