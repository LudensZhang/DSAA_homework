#include <iostream>
#include <cstdlib>
#include <cstdio>
#define OK 1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

using namespace std;

typedef int Status;

typedef struct {
    int *elem;
    int length;
    int listsize;
} SqList;

Status listInit(SqList &L) {
    L.elem = (int *) malloc(LIST_INIT_SIZE * sizeof(int));
    if (L.elem == NULL) return OVERFLOW;
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return OK;
}
Status listDelete(SqList &L, int i)
                  {
                   if(i <0 || i > L.length)
                      return 0;
                   int *p = &(L.elem[i]);
                   int *q = L.elem + L.length - 1;
                   for(++p;p <= q;++p)
                       *(p-1) = *p;
                   --L.length;
                  }
Status listInsert(SqList &L, int data) {
    if (L.length == L.listsize) {
        L.elem = (int *) realloc(L.elem, (L.listsize + LISTINCREMENT) * sizeof(int));
        if (L.elem == NULL) return OVERFLOW;
        L.listsize += LISTINCREMENT;
    }
    L.elem[L.length] = data;
    L.length++;
    return OK;
}

SqList makeList(int *a, int n) {
    SqList L;
    listInit(L);
    for (int i = 0; i < n; i++) listInsert(L, a[i]);
    return L;
}

Status printList(SqList L) {
    for (int i = 0; i < L.length; i++) printf("%d ", L.elem[i]);
    printf("\n");
    return OK;
}
Status reverse(SqList &L)
               {
                if(L.length % 2 == 1)
                   {
                    for(int i =0; i <= ((L.length-1)/2-1); i++)
                        {
                         int tmp = L.elem[i];
                         L.elem[i] = L.elem[L.length - i - 1];
                         L.elem[L.length - i -1] = tmp;
                        }
                   }
                else
                    {
                     for(int i =0; i <= (L.length/2-1); i++)
                        {
                            int tmp = L.elem[i];
                            L.elem[i] = L.elem[L.length - i - 1];
                            L.elem[L.length - i -1] = tmp;
                        }
                    }
               }
SqList founddelete(SqList &L1, SqList &L2, SqList &L3)
                   {
                    for(int i = 0;i <= (L1.length-1);i++)
                        for(int j = 0;j <= (L2.length-1);j++)
                            if(L1.elem[i] == L2.elem[j] )
                               {
                                for(int k = 0;k <= (L3.length-1);k++)
                                    {
                                     if(L2.elem[j] == L3.elem[k])
                                        {
                                          listDelete(L1,i);
                                        }
                                    }
                               }
                   }
int main()
{
    int a[6] = {6,7,8,9,10,11},b[5] = {1,3,4,5,6},c[5] = {3,4,6,7,8};
    SqList L1, L2, L3;
    L1 = makeList(a,6);
    L2 = makeList(b,5);
    L3 = makeList(c,5);
    printList(L1);
    printList(L2);
    printList(L3);
    founddelete(L1,L2,L3);
    printList(L1);


}