#include<stdio.h>
#include<stdlib.h>

char *replaceBlank( char *s);

int main(){
    char *str_with_blank;
    gets(str_with_blank);
    printf("After replace:%s\n", replaceBlank(str_with_blank));
    return 0;
}

char *replaceBlank( char *s){
    if(s == NULL)return NULL;
    int slen = 0;
    int blank_count = 0;
    while(s[slen]!='\0'){
        slen++;
        if(s[slen] == ' ')blank_count++;
    }
    printf("the string has %d blank\n",blank_count);
    int reslen = slen+2*blank_count;
    char *res = malloc(sizeof(char)*(reslen+1));
    int pre = slen;
    int post = reslen;
    while(pre != post && pre >= 0){
        if(s[pre]!=' '){
            res[post--] = s[pre--];
        }
        else{
            res[post--] = '0';
            res[post--] = '2';
            res[post--] = '%';
            pre--;
        }
    }
    while(pre >= 0){
        res[post--] = s[pre--];
    }
    return res;
}
