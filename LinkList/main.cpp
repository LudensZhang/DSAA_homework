#include <iostream>
#include <cstdlib>
#include <cstdio>
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

using namespace std;

typedef int Status;

typedef struct LNode {
    int data;
    LNode *next;
} *LinkList;

LinkList linkInit() {
    LinkList L = (LNode*) malloc(sizeof(LNode));
    L->data = 0; L->next = NULL;
    return L;
}

Status linkInsert(LNode *p, int data) {
    LNode *n = (LNode*) malloc(sizeof(LNode));
    if (n == NULL) return OVERFLOW;
    n->data = data;
    n->next = p->next;
    p->next = n;
    return OK;
}

LinkList makeLink(int *a, int n) {
    LinkList L = linkInit();
    for (int i = n-1; i >= 0; i--)
        linkInsert(L, a[i]);
    return L;
}

Status printLink(LinkList L) {
    LNode *p = L->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
    return OK;
}

Status delete_extrem(LinkList &L, int mink, int maxk)
{
    LNode *p = L;
    while(p->next != NULL && p->next->data <= mink)
          p = p->next;
    while(p->next != NULL && p->next->data < maxk)
          {
                LNode *q = p->next;
                p->next = q->next;
                free(q);
          }
}

LinkList combine(LinkList &L1, LinkList&L2)
                 {
                  LNode *p = L1->next, *q = L1;
                  while(q->next != NULL)
                        q = q->next;
                  q->next = p;
                  L1->next = p->next;
                  q->next = p;
                  p->next = NULL;
                  while(L1->next != q)
                        {
                         p = L1->next;
                         L1->next =p->next;
                         p->next = q->next;
                         q->next = p;
                        }
                  LNode *p2;
                  while(L2->next != NULL)
                        {
                         p=L1->next;
                         p2 = L2->next;
                         while (p->next != NULL && p2->data <= p->next->data)
                                p = p->next;
                         L2->next = p2->next;
                         p2->next = p->next;
                         p->next = p2;
                        }
                  free(L2);
                 }
LinkList founddelete(LinkList &L1, LinkList &L2, LinkList &L3) {
                      LNode *p = L1, *q = L2, *r = L3;
                      while(p->next != NULL){
                             while(q->next != NULL) {
                                 if (p->next->data == q->next->data){
                                     while (r->next != NULL) {
                                         if (q->next->data == r->next->data) {
                                             LNode *t = p->next;
                                             p->next = t->next;
                                             free(t);
                                         }
                                         r = r->next;
                                     }}
                             q=q->next;
                             r = L3;
                             }
                             p = p->next;
                             q = L2;
                            }
                     }
int main ()
{
    int a[5] = {5,6,7,8,10},b[5] = {1,2,4,5,8},c[6] = {1,2,3,7,8,10};
    LinkList L1,L2,L3;
    L1 = makeLink(a,5);
    L2 = makeLink(b,5);
    L3 = makeLink(c,6);
    printLink(L1);
    printLink(L2);
    printLink(L3);
    //delete_extrem(L1, 4,7);
   // combine(L1,L2);
    founddelete(L1, L2, L3);
    printLink(L1);
    return 0;
}

