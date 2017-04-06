#include<stdio.h>
#include<stdlib.h>
int findinarray(int **array,int size,int k);

int main(){
    int size;
    printf("the size of array:");
    scanf("%d",&size);
    int **a =(int **) malloc(sizeof(int *)*size);
    int k;
    int i,j;
    for(i = 0; i < size; i++){
        a[i] = (int *)malloc(sizeof(int)*size);
    }
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("the num you want to find in array:");
    scanf("%d",&k);
    if(findinarray(a,size,k))printf("true\n");
    else{
        printf("false\n");
    }
    return 0;
}

int findinarray(int **array,int size,int k){
    if(array == NULL || k == 0 )return 0;
    int i,j;
    i = 0;
    j = size-1;
    while(i<size&&j>=0){
        while(j>=0&&array[i][j]>k)j--;
        while(j<size&&array[i][j]<k)i++;
        if(array[i][j] == k)return 1;
    }
    return 0;
}

