#include<stdio.h>
int main()
{
FILE *f;
char g;
int backslashnCnt;
int cnt;
int length;
f=fopen("index.html","rb");
fseek(f,0,2);  // move to end
length=ftell(f);
printf("%d\n",length);
fseek(f,0,0);  // move to start
backslashnCnt=0;
cnt=0;
while(1)
{
g=fgetc(f);
if(feof(f)) break;
if(g=='\n') backslashnCnt++;
printf("%c",g);
cnt++;
}
fclose(f);
printf("%d\n",cnt);
printf("\\n count %d\n: ",backslashnCnt);
return 0;
}