#include<stdio.h>
#include<stdlib.h>
typedef struct point{
	int x;
	int y;
};
typedef struct line{
	point p1;
	point p2;
}

int main(){
    int rectnum;
    int i,j;
    scanf("%d",&rectnum);
    line rect[rectnum][4];
    for(i = 0; i < rectnum; i++){
	for(j = 0; j < 4; j++){
	   scanf("%d %d %d %d",&rect[i][j].p1.x,&rect[i][j].p1.y,&rect[i][j].p2.x,&rect[i][j].p2.y);
	}
    }
    int flag = 0;
    for(i = 0; i < rectnum; i++){
	for(j = 1 ; j < 4; j++){
	    if((rect[i][0].p1.y-rect[i][0].p2.y)*(rect[i][j].p1.y-rect[i][j].p2.y)== -(rect[i][0].p1.x-rect[i][0].p2.x)(rect[i][j].p1.x-rect[i][j].p2.x))continue;
 	    if((rect[i][0].p1.y-rect[i][0].p2.y)(rect[i][j].p1.x-rect[i][j].p2.x) == (rect[i][j].p1.y-rect[i][j].p2.y)(rect[i][0].p1.x-rect[i][0].p2.x))continue;
            flag = 1;
	}
	if(flag == 1){
	   printf("NO\n");
	   flag = 0;
	}
	else{
	   printf("YES\n");
	}
    }
    return 0;
}
