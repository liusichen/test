#include<stdio.h>
#include<stdlib.h>

struct BiTree{
    int key;
    struct BiTree *left;
    struct BiTree *right;
};

struct BiTree* getBitree(int *array,int len);
void preOrder(struct BiTree *root);

int main(){
    int size;
    printf("the nodenum is :");
    scanf("%d",&size);
    int *nums = malloc(sizeof(int)*(size+1));
    int i;
    for(i = 0; i < size; i++){
        scanf("%d",&nums[i]);
    }
    struct BiTree* root = getBitree(nums,size);
    preOrder(root);
    printf("\n");
    return 0;
}

struct BiTree* getBitree(int *array,int len){
    if(array == NULL|| len == 0)return NULL;
    struct BiTree* root = (struct BiTree *)malloc(sizeof(struct BiTree));
    root->key = array[0];
    root->left = NULL;
    root->right = NULL;
    struct BiTree* p = (struct BiTree *)malloc(sizeof(struct BiTree));
    p = root;
    struct BiTree **stack = calloc(30,sizeof(struct BiTree*));
    stack[0] = p;
    int *indexstack = calloc(30,sizeof(int));
    indexstack[0] = 0;
    int top = 1;

    while(top > 0){
        struct BiTree* tmp =stack[--top];
        int indextmp = indexstack[top];
        int lefttmp = 2*indextmp + 1;
        int righttmp = lefttmp+1;
        if(righttmp < len){
            struct BiTree *rightnode = (struct BiTree *)malloc(sizeof(struct BiTree));
            rightnode->key = array[righttmp];
            rightnode->right = rightnode->left = NULL;
            tmp->right = rightnode;
            stack[top] = rightnode;
            indexstack[top++] = righttmp;
        }
        if(lefttmp < len){
            struct BiTree *leftnode = (struct BiTree *)malloc(sizeof(struct BiTree));
            leftnode->key = array[lefttmp];
            leftnode->right = leftnode->left = NULL;
            tmp->left = leftnode;
            stack[top] = leftnode;
            indexstack[top++] = lefttmp;
        }
    }
    return root;
}

//----------递归-------------
/*
void preOrder(struct BiTree *root){
    if(root == NULL)return;
    printf("%d ",root->key);
    preOrder(root->left);
    preOrder(root->right);
}
*/

void preOrder(struct BiTree *root){
    if(root == NULL)return;
    struct BiTree *p = root;
    struct BiTree **stack = calloc(30, sizeof(struct BiTree));
    int top = 0;
    stack[top++] = p;
    while(top > 0){
        struct BiTree *tmp = stack[--top];
        printf("%d ",tmp->key);
        if(tmp->right)stack[top++] = tmp->right;
        if(tmp->left)stack[top++] = tmp->left;
    }
}
