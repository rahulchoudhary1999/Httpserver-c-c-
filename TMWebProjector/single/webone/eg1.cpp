#include<tmwp>
#include<iostream>
using namespace std;
using namespace tmwp;
/*void doSomething(int dataCount,char *data[])
{
cout<<"great, this code got executed on server side"<<endl;
if(dataCount>0) cout<<"Data That Arrived"<<endl;
for(int r=0;r<dataCount;r++)
{
cout<<data[r]<<endl;
}
}*/


void doSomething(Request &request,Response &response)
{
char *n=request.get((char *)"nm");
char *c=request.get((char *)"ct");
printf("%s\n",n);
printf("%s\n",c);
/* map<char *, char *>::iterator itr; 
 
    for (itr = request.dataMap.begin(); itr != request.dataMap.end(); ++itr) { 
         printf("%s,",itr->first);
printf("%s\n",itr->second);
    } 
 */ 
response.write("<!DOCTYPE HTML>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<title>Whatever</title>");
response.write("<meta charset='utf-8'>");
response.write("</head>");
response.write("<body>");
response.write("Hello ");
response.write(n);
response.write("<br>");
response.write("Data Saved");
response.write("</body>");
response.write("</html>");
response.close();

}
int main()
{
TMWebProjector server(8080);
server.onRequest("/register",doSomething);
server.start();
return 0;
}