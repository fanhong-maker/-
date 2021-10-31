//用顺序表编写图书馆
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 200
#define TRUE 1
#define FLASE 0
#define OK 1
#define INFEASIBLE -1
#define OVERFLOW -2

typedef struct 
{
        int year;
        int month;
        int day;
}Date;
typedef struct 
{
        char name[48];
        char author[20];
        Date date;
}Book;
typedef struct
{
        Book books[MAX_SIZE];
        int length;
}Library;
int pagedispaly();
int choosefunc(Library** library);
int intilib(Library** library);
int isempty(Library* library);
int destroylib(Library** library);
int clearpol(Library* library);
int liblength(Library* library);
int insertbook(Library** library);
int deletebook(Library** library);
int dispalycontents(Library* library);
int findbook(Library* library);
int pagedispaly()
{
        printf("--------欢迎来到陕师大图书系统--------\n");
        printf("---------键入9退出图书系统---------\n");
        printf("---------键入0初始图书系统---------\n");
        printf("--------键入1判断图书是否为空--------\n");
        printf("---------键入2摧毁图书系统---------\n");
        printf("---------键入3清空图书系统---------\n");
        printf("---------键入4获取图书总数---------\n");
        printf("-----------键入5插入书籍-----------\n");
        printf("-----------键入6删除书籍-----------\n");
        printf("---------键入7显示图书信息---------\n");
        printf("-----------键入8查找书籍-----------\n");
        puts("");
}
int choosefunc(Library** library)
{
        int i; 
        while(1)
        {
                if(*library == NULL)
                {
                        printf("第一次使用图书系统请键入0初始化\n");
                }
                 //功能选择
                printf("请键入功能:");
                scanf("%d", &i);
                switch (i)
                {
                        case 0:
                                intilib(library);
                                break;
                        case 1:
                                isempty(*library);
                                break;        
                        case 2:
                                destroylib(library);
                                break;      
                        case 3:
                                clearpol(*library);
                                break;  
                        case 4:
                                liblength(*library);
                                break;
                        case 5:
                                insertbook(library);
                                break; 
                        case 6:
                                deletebook(library);
                                break;
                        case 7:
                                dispalycontents(*library);
                                break;  
                        case 8:
                                findbook(*library);
                                break;
                        case 9:
                                return 0;
                        default:
                                printf("无此功能，重新键入！\n");
                } 
        }
}
int intilib(Library** library)
{
        *library = (Library*)malloc(sizeof(Library));
        if(*library != NULL)
        {
                printf("初始化成功！\n");
        }
        else
        {
                printf("分配内存失败!\n");
                exit(FLASE);
        }
        (*library)->length = 0;
        puts("");
        return OK;
}
int isempty(Library* library)
{
        if(library->length == 0)
        {
                printf("图书为空！\n");
                return TRUE;
        }
        else
        {
                printf("图书不为空！\n");
                return FLASE;
        }
        puts("");
}
int destroylib(Library** library)
{
        if(*library == 0)
        {
                printf("图书系统未初始化，不能执行该操作！");
                puts("");
                puts("");
        }
        free(*library);
        *library = NULL;
        return OK;
}
int clearpol(Library* library)
{
        library->length = 0;
        printf("清空完成！\n");
        puts("");
        return OK;
}
int liblength(Library* library)
{
        printf("图书有：%d\n",library->length);
        return OK;
}
int insertbook(Library** library)
{
        int length = (*library)->length;
        if(length > MAX_SIZE)
        {
                printf("图书系统存储空间！\n");
                puts("");
                return OVERFLOW;
        }
        printf("请输入书名：");
        scanf("%s", (((*library)->books)[length]).name);
        printf("请输入作者：");
        scanf("%s", ((*library)->books)[length].author);
        printf("请输入出版日期（格式2021-9-17）：");
        scanf("%d-%d-%d", &((*library)->books)[length].date.year,&((*library)->books)[length].date.month,&((*library)->books)[length].date.day);
        puts("");
        (*library)->length++;
        printf("添加书籍成功！\n");
        return OK; 
}
int deletebook(Library** library)
{
        int length = (*library)->length;
        if(length == 0)
        {
                printf("图书列表为空，不能进行删除操作！\n");
                return INFEASIBLE;
        }
        char name[48];
        printf("请输入书名：");
        scanf("%s", name);
        while(strcmp((*library)->books[length-1].name, name))
        {
                length--;
        }
        if(length == (*library)->length)
        {
                length--;
        }
        else
        {
                for(int i = 0; i < (*library)->length-length; i++)
                {
                        (*library)->books[length-1+i] = (*library)->books[length+i];
                }
        }
        return OK;
}
int dispalycontents(Library* library)
{
        int length = library->length;
        if(length == 0)
        {
                printf("无图书\n\n");
                return INFEASIBLE;
        }
        for(int i = 0; length > i; i++)
        {
                printf("第%d本书的信息\n", i+1);
                printf("书名：%s\n", library->books[i].name);
                printf("作者：%s\n", library->books[i].author);
                printf("书名：%d-%d-%d\n", library->books[i].date.year,library->books[i].date.month,library->books[i].date.day);
                puts("");
        }
        return OK;
}
int findbook(Library* library)
{
        int length = library->length;
        char name[48];
        printf("请输入要查找的书籍！");
        scanf("%s",name);
        while(strcmp(library->books[length-1].name, name))
        {
                length--;
        }
        printf("第%d本书的信息\n", length);
        printf("书名：%s\n", library->books[length-1].name);
        printf("作者：%s\n", library->books[length-1].author);
        printf("书名：%d-%d-%d\n", library->books[length-1].date.year,library->books[length-1].date.month,library->books[length-1].date.day);
        puts("");
}

int main(void) 
{
        Library* library = NULL;
        pagedispaly();
        choosefunc(&library);
        return 0;
}