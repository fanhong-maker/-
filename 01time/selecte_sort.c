//选择排序（Selection sort）是一种简单直观的排序算法。它的工作原理如下。
//首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置，然后，
//再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。以此类推，直到所有元素均排序完毕。

#include<stdio.h>

void selectsort(int*,int);
void printflist(int*, int);
void printflist(int* list, int len)
{
        int i ;
        for (i = 0; i < len; i++)
        {
                printf("%d  ",list[i]);
        }
}
void selectsort(int *list, int len)
{
        int m;  //用于存入最大元素值的下标
        int temp;
        for(int i = 0; i < len; i++)
        {
                m = i;
                for(int j = i + 1; j < len; j++)
                {
                        if(list[m] > list[j])
                        {
                                m = j;
                        }
                }
                temp = list[i];
                list[i] = list[m];
                list[m] = temp;
        }
}
int main()
{
        int len;
        int list[] = {23,54,13,7,89,10,4,243,8,68};
        len = sizeof(list)/sizeof(int);
        selectsort(list, len);
        printflist(list, len);
        return 0;
}