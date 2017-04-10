/*
*   用于练习剑指offer的代码
*   熟悉C语言使用
*   时间：2017.4.10
*/

#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int key;
    struct ListNode *next;
};

void printListFromEtoF(struct ListNode *head);

int main(){
    int num;
    printf("the list len is:");
    scanf("%d",&num);
    struct ListNode *head, *p;
    int headvalue;
    scanf("%d",&headvalue);
    head->key = headvalue;
    head->next = NULL;
    p = head;
    int i = 1;
    while(i < num){
        int tmp;
        printf("%d\n",i);
        struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
        scanf("%d",&tmp);
        new->key = tmp;
        new->next = NULL;
        p->next = new;
        p = p->next;
        i++;
    }
    printf("WTF!!\n");
    p = head;
    while(p){
        printf("%d ",p->key);
        p = p->next;
    }
    printf("\n");
    printListFromEtoF(head);
    return 0;
}

void printListFromEtoF(struct ListNode *head){
    struct ListNode *p = head;
    int stack[100];
    int top = 0;
    while(p){
        stack[top++]=p->key;
        p = p->next;
    }
    while(top > 0){
        printf("%d ",stack[--top]);
    }
    printf("\n");
    return;
}
