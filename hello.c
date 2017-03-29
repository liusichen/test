#include<stdio.h>
#include<stdlib.h>

typedef struct TrieNode{
    int count;
    struct TrieNode **next;
};
struct TrieNode* Init();
void Insert(struct TrieNode *head,char *word);
int Counter(struct TrieNode *head,char *pre);

int main(){
    char word[11];
    char prefix[11];
    struct TrieNode *head;
    head = Init();
    int n,m;
    int num;
    
    scanf("%d",&n);
    while(n > 0){
        gets(word);
        Insert(head,word);
        n--;
    }
    
    scanf("%d",&m);
    while(m > 0){
        gets(prefix);
        num = Counter(head,prefix);
        printf("%d\n",num);
        m--;
    }
    return 0;
}

struct TrieNode* Init(){
    struct TrieNode *p = malloc(sizeof(struct TrieNode));
    p->count = 0;
    p->next = (struct TrieNode*)malloc(sizeof(struct TrieNode)*27);
    int i;
    for(i = 0 ;i < 26; i++){
    	p->next[i] = NULL;
    }
    printf("%d\n",p->count);
    return p;
}

void Insert(struct TrieNode *head, char *word){
    struct TrieNode *p;
    p=head;
    printf("WTF!!insert\n");
    int i;
    int sym;
    for(i = 0; word[i] != '\0'; i++){
        sym = word[i]-'a';
        if(p->next[sym] == NULL){
            p->next[sym] = (struct TrieNode *)malloc(sizeof(struct TrieNode));
        }
        p = p->next[sym];
        p->count++;
    }
    return;
}

int Counter( struct TrieNode *head,char *pre){
    struct TrieNode *p;
    p = head;
    int i;
    int sym;
    for(i = 0; pre[i]!='\0'; i++){
        sym = pre[i]-'a';
        if(p->next[sym] == NULL){
            return 0;
        }
        p = p->next[sym];
    }
	printf("WHat\n");
    return p->count;
}
