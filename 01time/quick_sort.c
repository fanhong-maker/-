//快速排序的思想为：在区间中随机挑选一个元素作基准，将小于基准的元素放在基准之前，大于基准的元素放在基准之后，
//再分别对小数区与大数区进行排序。
#include<stdio.h>

void quick_sort(int*, int, int);
void printf_list(int* list, int len)
{
	int i = 0;
	while(i < len)
	{
		printf("%d  ",list[i]);
		i++;
	}
}
void quick_sort(int* list, int light, int right)
{
        int i = light;
        int j = right;
        int mid = (right + light)/2;
        int temp;
        while(i <= j)
        {
                while(list[i] < list[mid])
                {
                        i++;
                }
                while(list[j] > list[mid])
                {
                        j--;
                }
                if(i <= j)
                {
                        temp = list[i];
                        list[i] = list[j];
                        list[j] = temp;
                        i++;
                        j--;
                }
        }
        if(i < right)
        {
                quick_sort(list, i, right);
        }
        if(j > light)
        {
                quick_sort(list, light, j);
        }    
}
int main(void)
{
        int list[] = {12,789,1,2,2943,34,89,56,65,76};
        int len;
        len = sizeof(list)/sizeof(int);
        int light = 0;
        int right = len - 1;
        quick_sort(list, light, right);
        printf_list(list, len);
        return 0;
}