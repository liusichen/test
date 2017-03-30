#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define min(a,b) a>b?b:a

int  longestsub(char *s);
char *pretest(char *s ,int slen);

int main(){
    int n;
    char word[1000001];
    scanf("%d",&n);
    while(n > 0){
        scanf("%s",word);
        printf("%d\n",longestsub(word));
        n--;
    }
    return 0;
}

int longestsub(char *s){
    if(s[0] == '\0')return 0;
    int slen = strlen(s);
    char *modifys = malloc(sizeof(char)*(2*slen+1));
    modifys = pretest(s,slen);
    int i;
    int id = 0;
    int maxl = 0;
    int maxlen =0;
    int p[2*slen+1];
    p[0] = 0;
    for(i = 1; i < 2*slen+1; i++){
        p[i] = maxl > i ? min(p[2*id-i],maxl-i) : 1;
        while(modifys[i-p[i]] == modifys[i+p[i]] &&(i-p[i]>=0 && i+p[i] < 2*slen+1))p[i]++;
        maxlen =( maxlen >= p[i]) ? maxlen:p[i];
        if(i+p[i] > maxl){
            maxl = i+p[i];
            id = i;
        }
    }
    return maxlen-1;
    
}

char *pretest(char *s,int slen){
    char *ret = (char *)malloc(sizeof(char)*(2*slen+1));
    int i;
    for(i = 0; i<2*slen+1; i++){
        if(i%2 == 0)ret[i]='#';
        else{
            ret[i]=s[i/2];
        }
    }
    ret[2*slen+1]='\0';
    return ret;
}
