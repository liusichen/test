#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int func(int *p,int n){
    int i;
    if(n==1){
        return p[0]+p[1]*p[2];
    }
    else{
        int nCount = 0;
        for(i = 0; i< n; i++){
            nCount += (p+i*3)[0]+(p+i*3)[1]*(p+i*3)[2];
        }
        return nCount +func(p,n-1);
    }
}
int main(){
    int num[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    int result = func((int *)num,3);
    printf("%d",result);
    return 0;
}
