#include<stdio.h>

float dfs(int P,int Q,int p,int k,int i,int N);

int main(){
    int P,Q,N;
    scanf("%d %d %d",&P,&Q,&N);
    float ans;
    ans = dfs(P,Q,P,0,0,N);
    
    printf("%f\n",ans);
    return 0;
}

float dfs(int P,int Q,int p,int k,int i,int N){
    if(N == i){
	printf("%d\n",k);
	return k;
    }
    long long fenmu = 1 << i;
    if(p > 100) return dfs(P,Q,(P/2*fenmu),k+1,i+1,N);
    if(p == 0) return dfs(P,Q,p+Q,k+1,i,N);
    float tmp =((float)p)/100;
    return  tmp*dfs(P,Q,(P/2*fenmu),k+1,i+1,N)+(1-tmp)*dfs(P,Q,p+Q,k+1,i,N);
}
