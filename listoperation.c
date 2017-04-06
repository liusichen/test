#include<stdio.h>
#include<stdlib.h>

struct ListNode{
    int value;
    struct ListNode *next;
};

struct ListNode *createList();
int findLocation(struct ListNode *head,int k);
void deleteNode(struct ListNode *head,int k);
void printReverse(struct ListNode *head);

int main(){
    int value[] = {1,2,3,4,5,6,7,8};
    struct ListNode *head = createList();
    int i;
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = head;
    for(i = 0; i < 8; i++){
        struct ListNode *new = (struct ListNode *)malloc(sizeof(struct ListNode));
        new->value = value[i];
        new->next = NULL;
        p->next = new;
        p = p->next;
    }
    //-----------------findlocation------------------
    int key;
    printf("the key you want to find:");
    scanf("%d",&key);
    int num = findLocation(head,key);
    printf("the location is %d\n",num);

    //---------------printReverse-------------------
    printReverse(head);


    //the list value
    p = head->next;
    while(p!=NULL){
        printf("%d ",p->value);
        p = p->next;
    }
    printf("\n");
    //----------------delete node------------------
    printf("the key you want to delete:");
    scanf("%d",&key);
    deleteNode(head,key);
    //the list value
    p = head->next;
    while(p!=NULL){
        printf("%d ",p->value);
        p = p->next;
    }
    printf("\n");
    return 0;
}

struct ListNode *createList(){
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p->next = NULL;
    return p;
}

 int findLocation(struct ListNode *head,int k){
     struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
     p = head->next;
     int i = 1;
     while(p != NULL && p->value != k){
         p = p->next;
         i++;
     }
     if(p != NULL)return i;
     return 0;
 }
    
void printReverse(struct ListNode *head){
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = head->next;
    int *stack =calloc(100,sizeof(int));
    int top = 0;
    while(p != NULL){
        stack[top++] = p->value;
        p = p->next;
    }
    while(top > 0){
        printf("%d ",stack[--top]);
    }
    printf("\n");
    return;
}

void deleteNode(struct ListNode *head,int k){
    struct ListNode *p = (struct ListNode *)malloc(sizeof(struct ListNode));
    p = head;
    struct ListNode *q = (struct ListNode *)malloc(sizeof(struct ListNode));
    if(p)q = p->next;
    while(q != NULL && q->value != k){
        p = q;
        q = q->next;
    }
    if(q != NULL){
        p->next = q->next;
        free(q);
        return;
    }
    printf("no value equal key\n");
    return;
}
        
