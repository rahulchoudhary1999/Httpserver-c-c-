#include<stdio.h>
int extensionEquals(char *left,char *right)
{
char a,b;
while(*left && *right)
{
a=*left;
b=*right;
if(a>=65 && a<=90) a+=32;
if(b>=65 && b<=90) b+=32;
if(a!=b) return 0;
left++;
right++;
}
return *left==*right;
}
int main()
{
printf("%d\n",extensionEquals("html","htmlbabu"));
printf("%d\n",extensionEquals("html","html"));
printf("%d\n",extensionEquals("html","HtML"));
return 0;
}