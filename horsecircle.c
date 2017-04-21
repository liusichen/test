#include<stdio.h>

int main(){
    int n,m,L;
    int r,l,t,b;
    scanf("%d %d %d",&n,&m,&L);
    scanf("%d %d %d %d",&l,&r,&t,&b);
    int ans =0;
    int i,j;
    if(L >= 2*(m+n)){
	printf("%d\n",m*n-(r-l)*(b-t));
	return 0;
    }

    int l1=l,r1=r,t1=t,b1=b;
    if(r+l <= m){
	l1 = m-r;
	r1 = m-l;
    }
    if(t+b <= n){
	t1 = n-b;
	b1 = n-t;
    }
    printf("l1=%d, r1=%d, t1=%d, b1=%d\n",l1,r1,t1,b1);

    for(i = 1; i < L/2 && i <= m; i++){
	for(j = 1; j <= L/2-i && j <= n; j++){
	    if(i <= l1 || j <= t1){
		ans = ans > i*j?ans:i*j;
	    }
	    else if((i > l1 && i <= r1) && (j > t1 && j <= b1)){
		ans = ans > (i*j-(i-l1)*(j-t1)) ? ans : (i*j-(i-l1)*(j-t1));
	    }
	    else if(i > r1 && j > b1){
		ans = ans > (i*j-(r-l)*(b-t)) ? ans : (i*j-(r-l)*(b-t));
	    }
	    else
		continue;
	    	
	    printf("i = %d ,j=%d,ans = %d\n",i,j,ans);
	}
    }
    printf("%d\n",ans);
    return 0;
}
