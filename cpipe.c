#include <string.h>
#include <stdio.h>
#include <unistd.h>
char v1[30];
char v2[30];
int main()
{
 int k,ret;
 while(1){ 
 ret=scanf("%s", v1);
 if(ret < 0)break;
 printf("out %d   %s\n",ret, v1 );
 sleep(10);
 }
 return 0;
}
