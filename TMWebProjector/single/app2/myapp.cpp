#include<tmwp>
#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
using namespace std;
using namespace tmwp;

void functionOne(Request &request,Response &response)
{
cout<<"one get called"<<endl;
request.setInt("abcd",23);
request.setInt("pqr",15);
request.forward("three");
}
void functionTwo(Request &request,Response &response)
{
}
void functionThree(Request &request,Response &response)
{
int s=request.getInt("abcd");
int f=request.getInt("pqr");
char rs[20];
response.write("<!DOCTYPE html>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<meta charset='utf-8'>");
response.write("<title>ABC School</title>");
response.write("</head>");
response.write("<body>");
sprintf(rs,"%d ",s);
response.write(rs);
sprintf(rs,"%d",f);
response.write(rs);
response.write("</body>");
response.write("</html>");
response.close();
}
int main()
{
TMWebProjector server(8080);
server.onRequest("/one",functionOne);
server.onRequest("/two",functionTwo);
server.onRequest("/three",functionThree);
server.start();
return 0;
}