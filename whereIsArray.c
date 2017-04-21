#include<stdio.h>
#include<string.h>

int main(){
    char *a ="123445555";
    char b[] ="123fdfsfsdfsdfsdfsf";
    int alen = strlen(a);
    b[4] = 'z';
    printf("%s\n",b);
    printf("%s\n",a);
    printf("%lu,the len is %d\n",sizeof(*a),alen);
    printf("%lu\n",sizeof(b));
    return 0;
}
