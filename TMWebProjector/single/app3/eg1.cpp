#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
int x,y;
printf("Enter age:");
scanf("%d",&x);
printf("Enter year:");
scanf("%d",&y);
char c;
FILE *f=fopen("abcd.html","r");
char a[101];
int i;
while(1)
{
c=fgetc(f);
if(c==EOF) break;
if(c=='$') 
{
i=0;
c=fgetc(f);
if(c==EOF) break;
while(1)
{
c=fgetc(f);
if(c=='}') 
{
c=fgetc(f);
break;
}
a[i]=c;
i++;
}
a[i]='\0';
if(strcmp(a,"x")==0) printf("%d",x);
if(strcmp(a,"y")==0) printf("%d",y);
}
printf("%c",c);
}
fclose(f);
return 0;
}