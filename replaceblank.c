#include<stdio.h>
#include<stdlib.h>

char *replaceBlank(char *s, int maxlen);

int main(){
    char *str = "i am ben";
    char *res;
    int total_len;
    scanf("%d",&total_len);
    res = replaceBlank(str,total_len);
    printf("%s\n",res);
    return 0;
}

char* replaceBlank(char *s, int maxlen){
    if(s == NULL)return s;
    int oldstr_len = 0;
    int blank_num = 0;
    int newstr_len;
    for(oldstr_len = 1; s[oldstr_len] != '\0'; oldstr_len++){
        if(s[oldstr_len] == ' ')blank_num++;
    }
    newstr_len = oldstr_len + blank_num * 2;
    printf("%d\n",newstr_len);
    char *res;
    if(newstr_len > maxlen)return s;
    res = malloc(sizeof(char)*(newstr_len+1));
    int left = oldstr_len;
    int right = newstr_len;

    while(left >= 0 && right > left){
        if(s[left] == ' '){
            res[right--] = '0';
            res[right--] = '2';
            res[right--] = '%';
        }
        else{
            res[right--] = s[left];
        }
        left--;
    }
    while(left >= 0){
        res[left] = s[left];
        left--;
    }
    system("pause");
    printf("%s\n",res);
    return res;
}
