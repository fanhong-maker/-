#include<stdio.h>
#include<stdlib.h>

#define OK 1
#define FALSE 0
#define status int

typedef struct 
{
        int key;        //keyword
        char elem;
}Elemtype;
typedef struct Node
{ 
        int BF;         //balance factor
        Elemtype data;
        struct Node* lchild;
        struct Node* rchild;
}BSNode, *BStree;

status initBStree(BStree* t)
{
        *t = NULL;
        return OK;
}
status destoryBStree(BStree* t)
{
        if(!*t)
        {
                return OK;
        }
        BStree temp;
        temp = *t;
        if((*t)->lchild)
        {
                destoryBStree(&(*t)->lchild);
        }
        if((*t)->rchild)
        {
                destoryBStree(&(*t)->rchild);
        }
        free(temp);
}
status searchBStree(BStree t, int key, BStree f, BStree* p)
{
        if(!t)
        {
                *p = f;
                return FALSE;
        }
        if(t->data.key == key)
        {
                *p = t;
                return OK;
        }
        else if(t->data.key < key)
        {
                return searchBStree(t->rchild, key, t, p);
        }
        else
        {
                return searchBStree(t->lchild, key, t, p);
        }
}
status insertBStree(BStree* t, Elemtype e)
{
        BStree p;
        if(!searchBStree(*t, e.key, NULL, &p))
        {
                BSNode* node;
                node = (BStree)malloc(sizeof(BSNode));
                node->data.key = e.key;
                node->data.elem = e.elem;
                node->lchild = NULL;
                node->rchild = NULL;
                if(!*t)
                {
                        *t = node;
                }
                else if(e.key < p->data.key)
                {
                        p->lchild = node;
                }
                else
                {
                        p->rchild = node;
                }
                return OK;
        }
        else{
                return FALSE;
        }
}
status delete(BStree* p)
{
        BStree temp;
        temp = *p;
        if(!(*p)->lchild && !(*p)->rchild)
        {
                *p = NULL;
                free(temp);
                return OK;
        }
        else if(!(*p)->lchild && (*p)->rchild)
        {
                *p = (*p)->rchild;
                free(temp);
                return OK;
        }
        else if(!(*p)->rchild && (*p)->lchild)
        {
                *p = (*p)->lchild;
                free(temp);
                return OK;
        }
        else
        {
                BStree t, t1;
                t1 = *p;
                t = (*p)->lchild;
                while(t->rchild)
                {
                        t1 = t;
                        t = t->rchild;
                }
                (*p)->data = t->data;
                if(t1 != *p)t1->rchild = t->lchild;
                else t1->lchild = t->rchild;
                free(t);
        }
        return OK;
}
status deleteBStree(BStree* t, int key)
{
        if(!t)
        {
                return FALSE;
        }
        if(key == (*t)->data.key)
        {
                return  delete(t);
        }
        else if(key < (*t)->data.key)
        {
                return deleteBStree(&(*t)->lchild, key);
        }
        else if(key > (*t)->data.key)
        {
                return deleteBStree(&(*t)->rchild, key);
        }
}
status inordertraverse(BStree t)        //中序遍历
{
        if(t == NULL)
        {
                //printf("树为空！\n");
                return OK;
        }
        else
        {
                //printf("aa\n");
                inordertraverse(t->lchild);
                printf("%c  ", t->data.elem);
                inordertraverse(t->rchild);
        }
}
int main()
{
        BStree t;
        initBStree(&t);
        Elemtype elm[5] = {{1,'A'},{5,'E'},{2,'B'},{3,'C'},{4,'D'}};
        for(int i = 0; i < 5; i++)
        {
                //printf("%d  %c\n", elm[i].key,elm[i].elem);
                insertBStree(&t,elm[i]);
        }
        inordertraverse(t);
        return 0;
}