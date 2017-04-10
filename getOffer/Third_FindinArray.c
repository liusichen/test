#include<stdio.h>
#include<stdlib.h>

void FindInArray(int **num, int rows, int columns, int *i, int *j, int k);

int main(){
    int rows,columns;
    printf("the rows :");
    scanf("%d",&rows);
    printf("the columns :");
    scanf("%d", &columns);
    int **nums = (int **)malloc(sizeof(int *)*rows);
    int k;
    printf("the key you wanted to find:");
    scanf("%d",&k);
    int i,j;
    for(i = 0; i < rows; i++){
        nums[i] =(int *) malloc(sizeof(int)*columns);
    }
    for(i = 0; i < rows; i++){
        for(j = 0; j < columns; j++){
            scanf("%d ",&nums[i][j]);
        }
    }

    i = 0;
    j = 0;
    FindInArray(nums, rows, columns, &i, &j, k);
    printf("Rows : %d\nColumns : %d\n",i,j);
    return 0;
}

void FindInArray(int **num, int rows, int columns, int *i, int *j, int k){
    if(num == NULL || rows < 0 || columns < 0)
        return;
    int row = 0;
    int column = columns-1;
    while(row <= rows && column >= 0){
        printf("the nums is %d\n",num[row][column]);
        if(num[row][column] > k){
            column--;
        }
        else if(num[row][column] < k){
            row++;
        }
        else{
            *i = row;
            *j = column;
            return;
        }
    }
    *i = rows;
    *j = columns;
    return;
}
