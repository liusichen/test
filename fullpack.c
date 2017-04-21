#include<stdio.h>
#include<stdlib.h>

int main(){
    int numofprice;
    int lottery;
    scanf("%d",&numofprice);
    scanf("%d",&lottery);
    int need[numofprice];
    int value[numofprice];
    int i,j;
    int best[lottery+1];

    for(i = 0; i < numofprice; i++){
	scanf("%d",&need[i]);
	scanf("%d",&value[i]);
    }
    
    for(j = 0; j <= lottery; j++)best[j] = 0;
    for(i = 0; i < numofprice; i++){
	for(j = 0; j <= lottery; j++){
	    if(need[i] > j){
		best[j]= best[j]>0?best[j]:0;    
	    }
	    else{
		best[j]=best[j]>(best[j-need[i]]+value[i])?best[j]:(best[j-need[i]]+value[i]);
	    }
	}
    }
    printf("%d\n",best[lottery]);
    return 0;
}
