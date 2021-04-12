#include<stdio.h>
#include<stdlib.h>
#include <iostream>
using namespace std;
#define maxsize 10
#define n_actions 2
#define num_episodes 20
#define OK 1
#define ERROR 0
#define OVERFLOW 1

typedef int Status;

typedef struct node{
    char data;
    struct node *lchild,*rchild;
} node;
typedef node *bitree;


typedef struct {
    bitree a[maxsize];
    int first,tail;
}sequeue;

bool EnQueue(sequeue &Q,bitree t)
{
    if(Q.first==(Q.tail+1)%maxsize)return 0;
    Q.a[Q.tail]=t;
    Q.tail=(Q.tail+1)%maxsize;
}

bool DeQueue(sequeue &Q,bitree &t)
{
    if(Q.first==Q.tail)return 0;
    t=Q.a[Q.first];
    Q.first=(Q.first+1)%maxsize;
}

bool QStackEmpty(sequeue Q)
{
    if(Q.first==Q.tail)return true;
    return false;
}

bool QStackPush(sequeue &Q,bitree t)
{
    EnQueue(Q,t);
}

bool QStackPop(sequeue &Q,bitree &t)
{
    int i;
    if(Q.first==Q.tail)return 0;
    for(i=0;i<Q.tail-Q.first-1;i++)
    {
        DeQueue(Q,t);
        EnQueue(Q,t);
    }
    DeQueue(Q,t);
}

typedef struct {
    bitree a[maxsize];
    int top;
}seqstack;

bitree buildtree()          //构造二叉树
{
    char c;
    node *p;
    c=getchar();
    if(c=='0')return(0);
    p=new(node);
    p->data=c;
    p->lchild=buildtree();
    p->rchild=buildtree();
    return(p);
}

void preorder(bitree t)//这是非递归先序实现
{
    sequeue Q;
    Q.first=Q.tail=0;//置栈空

    //seqstack s;
    //s.top = -1;//置栈空
    while((t)||!QStackEmpty(Q))
    {
        while(t)
        {
            printf("%c", t->data);
            if(t->rchild!=NULL)
                QStackPush(Q,t->rchild);
            //s.a[++s.top] = t->rchild;//入栈
            t = t->lchild;
        }
        if (!QStackEmpty(Q)) {

            QStackPop(Q,t);
            //  t = s.a[s.top--];//出栈
        }
    }
}

void midorder(bitree t) //这是非递归中序实现，也适合先序
{
    if(!t)return;
    seqstack s;
    s.top = -1;//置栈空
    while((t)||(s.top!=-1))
    {
        while(t)
        {   //printf(" %c  ", t->data);//也适合先序
            s.a[++s.top] = t;//入栈
            t = t->lchild;
        }
        if (s.top>-1) {
            t=s.a[s.top--];
            printf("%c", t->data);
            t=t->rchild;
        }
    }
}

void postorder(bitree t)//这是非递归后序实现，也适合先序/中序
{
    if(!t)return;
    bitree lastvist=t;//初始化，只要是地址,且不为0即可!
    seqstack s;
    s.top = -1;//置栈空
    while(t||s.top != -1)
    {
        while(t)
        {
            //printf("%c", t->data);//也适合先序
            s.a[++s.top] = t;//入栈
            t=t->lchild;
        }
        t=s.a[s.top];
        if(t->rchild!=lastvist)
        {
            //printf("%c", t->data);//也适合中序
            t=t->rchild;
            if(!t)
                lastvist=t;
        }
        else
        {
            printf("%c", t->data);//适合后序
            s.top--;    //出栈
            lastvist=t;//更新
            t=0;//使下一循环直接取栈顶
        }
    }
}

void DLR(bitree root){        //递归先序二叉树
    if(!root)return;
    printf("%c", root->data);
    DLR(root->lchild);
    DLR(root->rchild);
}

void LDR(bitree root)        //递归中序二叉树
{
    if(!root)return;
    LDR(root->lchild);
    printf("%c",root->data);
    LDR(root->rchild);
}

void LRD (bitree root)      //递归后序二叉树
{
    if(!root)return;
    LRD(root->lchild);
    LRD(root->rchild);
    printf("%c",root->data);
}

Status mirror_tree(bitree root){      //镜像二叉树
    if(!root)return 0;
    node *p = root->rchild;
    root->rchild = root->lchild;
    root->lchild = p;
    mirror_tree(root->lchild);
    mirror_tree(root->rchild);
}

Status find_x( bitree root, char x, bitree &tmp){       //找到x节点
    if(!root)return ERROR;
    if(root->data == x){
        tmp = root;
        return OK;
    }
    else{
        if(find_x(root->lchild, x, tmp))return OK;
        else if(find_x(root->rchild, x, tmp))return OK;
    }
}

int tree_height(bitree root){     //求二叉树高度

    if(!root)return 0;
    if(root && !root->lchild && !root->rchild)return 1;
    if(tree_height(root->lchild) >= tree_height(root->rchild))return tree_height(root->lchild)+1;
    else return tree_height(root->rchild)+1;
}

int main(){
    bitree t, t_tmp;
    char x;
    t = buildtree();
    cin>>x;
    find_x(t, x, t_tmp);
    printf("%d",tree_height(t_tmp));
}