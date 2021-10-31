//插入排序：它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
//从小到大排序时，相当于遇到比temp大的后移，遇到比temp小的数时，在改数前插入。
#include<stdio.h>

void insert_sort(int*, int);
void printflist(int*, int);
void insert_sort(int* list, int len)
{
        int temp;
        int j;
        for (int i = 1; i < len; i++)
        {
                temp = list[i];    //temp用于存储待插入数
                for(j = i; j > 0 && list[j-1] > temp; j--)
                {
                        list[j] = list[j - 1];
                }
                list[j] = temp;
        }
}
void printflist(int* list, int len)
{
        for(int i = 0; i < len; i++)
        {
                printf("%d  ", list[i]);
        }
}
int main(void)
{
        int len = 0;
	int list[] = {7,32,54,71,20,9,10,43,2480,470 };
	len = sizeof(list)/sizeof(int);
        insert_sort(list, len);
        printflist(list, len);
        return 0;
}