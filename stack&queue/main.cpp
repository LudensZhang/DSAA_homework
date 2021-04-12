#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <stdlib.h>

using namespace std;

typedef int Status;

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
#define OVERFLOW -1
#define OK 1
#define ERROR 0

typedef struct LNode {
    int data;
    LNode *next;
} *LoopList;

LoopList linkInit() {
    LoopList L = (LNode*) malloc(sizeof(LNode));
    L->data = 0; L->next = NULL;
    return L;
}
Status loopInsert(LNode *p, int data) {
    LNode *n = (LNode*) malloc(sizeof(LNode));
    if (n == NULL) return OVERFLOW;
    n->data = data;
    n->next = p->next;
    p->next = n;
    return OK;
}


Status as_queue_in(int a[], int n, int e){
    LoopList L = linkInit();
    for (int i = n-1; i >= 0; i--)
        loopInsert(L, a[i]);
    LNode *p = L->next;
    LNode *q = L->next;
    while(p->next != NULL)
        p = p->next;
    p->next = q;
    free(q);
    LNode *r;
    r->data = e;
    r->next = p->next;
    p->next = r;
    p = p->next;
}

int as_queue_out(int a[], int n){
    LoopList L = linkInit();
    for (int i = n-1; i >= 0; i--)
        loopInsert(L, a[i]);
    LNode *p = L->next;
    LNode *q = L->next;
    while(p->next != NULL)
        p = p->next;
    p->next = q;
    free(q);
    int e;
    e = p->next->data;
    p->next = p->next->next;
    return e;
}

typedef struct{
    char *base;
    char *top;
    int stacksize;
}SqStack;



Status InitStack(SqStack &S){
    S.base = (char * )malloc(STACK_INIT_SIZE * sizeof(char));
    if(!S.base) exit (OVERFLOW);
    S.top = S.base;
    S.stacksize = STACK_INIT_SIZE;
    return OK;
}

char GetTop(SqStack S, char e){
    if(S.top == S.base) return ERROR;
    e = *(S.top-1);
    return e;
}

Status StackEmpty(SqStack S) {
    if (S.base == S.top)
        return OK;
    else
        return ERROR;
}

Status Push(SqStack &S, char e){
    if (S.top - S.base >= S.stacksize) {
        S.base = (char *) realloc(S.base,
                                  (S.stacksize + STACKINCREMENT) * sizeof(char));

        if (!S.base) exit(OVERFLOW);
        S.top = S.base + S.stacksize;
    }
    *S.top = e;
    *S.top++;
}

char Pop(SqStack &S, char e){
    if(S.top == S.base) return ERROR;
    e = * -- S.top;
    return e;
}

SqStack build_stack(SqStack &S, char a[], int n){
    for(int i = 0; i < n; i++) {
        Push(S, a[i]);
    }
    return S;
}

Status print_stack(SqStack S){
    while(S.top != S.base){
        S.top--;
        cout << *S.top;

    }
    cout<<endl;
}

Status match_parentheses(SqStack S){
    int i = 0, j = 0, k = 0;
    while(S.top != S.base-1){
        if(*S.top == *"(")
            i++;
        else if (*S.top == *")")
            i--;
        else if (*S.top == *"[")
            j++;
        else if (*S.top == *"]")
            j--;
        else if (*S.top == *"{")
            k++;
        else if (*S.top == *"}")
            k--;
        S.top--;
    }
    if(i == 0)
        cout<<"()match_succeed"<<endl;
    else cout<<"()match_error"<<endl;
    if(j == 0)
        cout<<"[]match_succeed"<<endl;
    else cout<<"[]match_error"<<endl;
    if(k == 0)
        cout<<"{}match_succeed"<<endl;
    else cout<<"{}match_error"<<endl;
}

Status Prior(char c1, char c2){
    char ch[] = "#+-*/";
    int i = 0, j = 0;
    while(ch[i] && ch[i] != c1)
        i++;
    if(i == 2) i--;
    if(i == 4) i--;
    while(ch[j] && ch[j] != c2)
        j++;
    if(j == 2) j--;
    if(j == 4) j--;
    if(i>=j) return true;
    else return false;
}

Status IsOperator(char a) {
    const char *comp = "#+-*/";
    while(*comp){
        if(*comp == a)
        return true;
        comp++;
    }
    return false;
}

void trans_to_reversepolish(char in_put[]){
    SqStack S;
    InitStack(S);
    char e;
    int i =0, j=0;
    Push(S, in_put[i]);
    i++;
    while(in_put[i] !='#'){
        if(!IsOperator(in_put[i])){
            in_put[j] = in_put[i];
            i++;j++;
        }
        else{
            e = GetTop(S, e);
            if(Prior(e, in_put[i])){
                e = Pop(S, e);
                in_put[j] = e;
                j++;
            }
            else{
                Push(S, in_put[i]);
                i++;
            }
        }
    }
    while(!StackEmpty(S)){
        e = Pop(S, e);
        in_put[j] = e;
        j++;
    }
}


int main() {
    char c[8] = "#b-c/a#";
    trans_to_reversepolish(c);
    cout<<c;
}
