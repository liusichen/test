#include<stdio.h>
#include<string.h>

int reverse(char *s);

int main(){
    int slen;
    scanf("%d",&slen);
    char *s = malloc(sizeof(char)*(slen));
    scanf("%s",s);
    int res = reverse(s);
    printf("%d\n",res);
    return 0;
}

int reverse(char *s){
    int slen = strlen(s);
    if(slen<=1)return 0;
    int i;
    int *dp = (int *)malloc(sizeof(int)*(slen+1));
    dp[0]=0;
    printf("%s\n",s);
    int couA=0;
    int couB=0;
    int couC=0;
    int couD=0;
    for(i = 0;s[i]!='\0';i++){
        if(s[i]=='D'){
            couD++;
            dp[i+1] = dp[i];
        }
        else if(s[i] == 'C'){
            couC++;
            dp[i+1] = dp[i]+couD;
        }
        else if(s[i] == 'B'){
            couB++;
            dp[i+1] = dp[i]+couD+couC;
        }
        else{
            couA++;
            dp[i+1] = dp[i]+couD+couC+couB;
        }
    }

    return dp[i];
}


