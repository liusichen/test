#include<stdio.h>

int main(){
    int num,depth,leavesnum;
    scanf("%d %d %d",&num,&depth,&leavesnum);
    int nums[num];
    int i,j;
    int max =0;
    for(i = 0; i < depth; i++){
	scanf("%d",&nums[i]);
	if(nums[i]>max)max = nums[i];
    }
    int treelevel[depth+1][max];
    for(i = 0;i < depth; i++){
    	for(j = 0; j < nums[i-1]; j++){
	    scanf("%d",&treelevel[i][j]);
	}
    }
    int leavesnode[num+1];
    for(i = 0; i < leavesnum; i++){
        int tmp;
	scanf("%d",&tmp);
        leavesnode[tmp] = 1;	
    }
    int distance[leavesnum][leavesnum];
    for(i = 0; i < leavesnum; i++){
	for(j = 0; j < leavesnum; j++){
	    scanf("%d",&distance[i][j]);
	}
    }
    
    int ans[num];
    int k;
    if(num == 0)return 0;
    if(num == 1){
	printf("0\n");
        return 0;
    }
    k = 1;
    int tmppar;
    for(i = 0; i < nums[1];i++){
   	ans[k++]=treelevel[1][i];
    }
    j = 0;
    for(i = 2; i < depth; i++){
	while(leavesnode[treelevel[i-1][j]]==1)j++;
        tmppar = j;
        for(j = 0; j < nums[i]; j++){
            if()
    	}
    }
}  
