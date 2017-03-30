#include<stdio.h>
#include<stdlib.h>

int main(){
    int floor;
    scanf("%d",&floor);
    //printf("the floor is %d\n",floor);
    int dp[floor][floor];
    int i = 1;
    int j = 0;
    while(i <= floor){
	while(j < i){
	    scanf("%d",&dp[floor-i][j]);
	    j++;
	   // printf("%d,",dp[floor-i][j-1]);
	}
	//printf("\n");
	j = 0;
	i++;
    }

    for(i = 1; i < floor; i++){
	for(j = 0; j < floor-i;j++){
	    dp[i][j] += (dp[i-1][j] > dp[i-1][j+1])?dp[i-1][j]:dp[i-1][j+1]; 
	}
    }	
    printf("%d\n",dp[floor-1][0]);
    return 0;
}
