//冒泡排序的思想为：如果对长度为 n 的数组进行排序，则进行 n-1次循环，每次循环依次将最大的数或则最小的数依次放在最后
//直到循环完毕完成排序
#include<stdio.h>

void dubble_sort(int*, int);
void printf_list(int*, int);
void printf_list(int* list, int len)
{
	int i = 0;
	while(i < len)
	{
		printf("%d  ",list[i]);
		i++;
	}
}
void bubble_sort(int *list, int len)
{
	int i = 0;
	int j = 0;
	int temp;
	while(i < len - 1)
	{
		while(j < len - i - 1)
		{
			if(list[j] > list[j+1])
			{
				temp = list[j];
				list[j] = list[j+1];
				list[j+1] = temp;
			}
			j++;
		}
		j = 0;
		i++;
	}
}
int main(void)
{
	int len = 0;
	int list[] = {7,32,54,71,20,9,10,43,2480,470 };
	len = sizeof(list)/sizeof(int);
	bubble_sort(list, len);
	printf_list(list, len);
	return 0;
}
