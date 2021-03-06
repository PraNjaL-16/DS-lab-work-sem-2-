#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node * lchild;
    char data;
    struct node * rchild;
}*root=NULL;

struct node * Rinsert(struct node * p, int key)
{
    struct node * t = NULL;

    if(p == NULL)
    {
        t = (struct node *)malloc(sizeof(struct node));
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
    {
        p->lchild = Rinsert(p->lchild, key);
    }
    else if(key > p->data)
    {
        p->rchild =  Rinsert(p->rchild, key);
    }

    return p;
}

void inorder(struct node * p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d\t",p->data);
        inorder(p->rchild);

    }
}

int main()
{
    struct node * temp;

    root = Rinsert(root,50);
    Rinsert(root,30);
    Rinsert(root,40);
    Rinsert(root,20);
    Rinsert(root,10);

    inorder(root);

    return 0;
}
