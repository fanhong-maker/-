#include<stdio.h >
#include<stdlib.h>

int main()
{
        int arr[] = {1,2,3};
        printf("%p\n", &arr);
        printf("%p\n", arr);
        printf("%p\n", &arr[0]);
        printf("%p\n", *arr);
}