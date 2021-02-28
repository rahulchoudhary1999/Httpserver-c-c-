#include<tmwp>
#include<stdio.h>
#include<malloc.h>
#include<iostream>
#include<fstream>
#include<string.h>
#include<vector>
using namespace std;
using namespace tmwp;
class Student
{
public:
int rollNumber;
char name[22];
};
void add_student(Request &request,Response &response)
{
int rollNumber=atoi(request.get((char *)"rollnumber"));
char *name=request.get((char *)"name");
Student s;
s.rollNumber=rollNumber;
strcpy(s.name,name);
ofstream file;
file.open("student.dat",ios::out|ios::app);
if(!file)
{
printf("Error in opening file");
return;
}
file.write((char *)&s,sizeof(s));
file.close();
response.write("<!DOCTYPE HTML>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<title>Whatever</title>");
response.write("<meta charset='utf-8'>");
response.write("</head>");
response.write("<body>");
response.write("Data Saved<br>");
response.write("<a href='index.html'>HOME</a>");
response.write("</body>");
response.write("</html>");
response.close();
}

void get_students(Request &request,Response &response)
{
vector<Student> students;
ifstream file1;
file1.open("student.dat",ios::in);
if(!file1)
{
printf("Error2");
return;
}
Student s;
while(true)
{
if(!file1.read((char *)&s,sizeof(s)))break;
students.push_back(s);
}
response.write("<!DOCTYPE html>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<meta charset='utf-8'>");
response.write("<title>ABC,School Record</title>");
response.write("</head>");
response.write("<body>");
response.write("<table border='1'>");
response.write("<thead>");
response.write("<th>Sr.no.</th>");
response.write("<th>Roll number</th>");
response.write("<th>Name</th>");
response.write("</thead>");
response.write("<tbody>");
char data[501];
for(int i=0;i<students.size();i++)
{
sprintf(data,"<tr><td>%d</td><td>%d</td><td>%s</td></tr>",i+1,students[i].rollNumber,students[i].name);
printf("%s\n",data);
response.write(data);
}
response.write("</tbody>");
response.write("</table>");
response.write("</body>");
response.write("</html>");
response.close();
file1.close();
}

void edit_student(Request &request,Response &response)
{
int rollNumber=atoi(request.get((char *)"rollnumber"));
Student s;
ifstream file1;
file1.open("student.dat",ios::in);
if(!file1)
{
printf("Error2");
return;
}
Student student;
while(true)
{
if(!file1.read((char *)&student,sizeof(student)))break;
if(student.rollNumber==rollNumber)
{
file1.close();
break;
}
}
char data[501];
response.write("<DOCTYPE html>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<meta charset='utf-8'>");
response.write("<title>ABC,School</title>");
response.write("</head>");
response.write("<body>");
response.write("Student (Edit Module)");
response.write("<form method='get' action='updateStudent'>");
sprintf(data,"Roll number: %d",student.rollNumber);
response.write(data);
sprintf(data,"<input type='hidden' id='rollnumber' name='rollnumber' value='%d'><br>",student.rollNumber);
response.write(data);
sprintf(data,"Name <input type='text' id='name' name='name' value='%s'><br>",student.name);
response.write(data);
response.write("<button type='submit'>Update</button>");
response.write("</form><br>");
response.write("<a href='index.html'>HOME</a>");
response.write("</body>");
response.write("</html>");
response.close();
}

void update_student(Request &request,Response &response)
{
int rollNumber=atoi(request.get((char *)"rollnumber"));
char *name=request.get((char *)"name");
fstream file1;
file1.open("student.dat",ios::in | ios::binary | ios::out); 
if(!file1)
{
printf("Error2");
return;
}
Student student;
int pos;
printf("%d\n",rollNumber);
while(true)
{
pos=file1.tellg(); 
if(!file1.read((char *)&student,sizeof(student)))break;
if(student.rollNumber==rollNumber)
{
break;
}
}
printf("Position %d\n",pos);
strcpy(student.name,name);
file1.seekp(pos);
file1.write((char *)&student,sizeof(student));
file1.close();
response.write("<!DOCTYPE html>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<meta charset='utf-8'>");
response.write("<title>ABC School</title>");
response.write("</head>");
response.write("<body>");
response.write("Student (Edit Module)<br>");
response.write("<h3>Student Updated</h3>");
response.write("<form method='get' action='index.html'>");
response.write("<button type='submit'>Ok</button>");
response.write("</form>");
response.write("</body>");
response.write("</html>");
response.close();
}

void confirm_delete_student(Request &request,Response &response)
{
int rollNumber=atoi(request.get((char *)"rollnumber"));
Student s;
ifstream file1;
file1.open("student.dat",ios::in);
if(!file1)
{
printf("Error2");
return;
}
Student student;
while(true)
{
if(!file1.read((char *)&student,sizeof(student)))break;
if(student.rollNumber==rollNumber)
{
file1.close();
break;
}
}

char data[501];
response.write("<DOCTYPE html>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<meta charset='utf-8'>");
response.write("<title>ABC,School</title>");
response.write("</head>");
response.write("<body>");
response.write("Student (Delete Module)");
response.write("<form method='get' action='deleteStudent'>");
sprintf(data,"Roll number : %d",student.rollNumber);
response.write(data);
sprintf(data,"<input type='hidden' id='rollnumber' name='rollnumber' value='%d'><br>",student.rollNumber);
response.write(data);
sprintf(data,"Name :%s<br>",student.name);
response.write(data);
response.write("<button type='submit'>Delete</button>");
response.write("</form><br>");
response.write("<a href='index.html'>HOME</a>");
response.write("</body>");
response.write("</html>");
response.close();
}

void delete_student(Request &request,Response &response)
{
int rollNumber=atoi(request.get((char *)"rollnumber"));
vector<Student> students;
ifstream file1;
file1.open("student.dat",ios::in);
if(!file1)
{
printf("Error2");
return;
}
Student student;
while(true)
{
if(!file1.read((char *)&student,sizeof(student)))break;
if(student.rollNumber!=rollNumber)
{
students.push_back(student);
}
}
file1.close();

ofstream file;
file.open("student.dat",ios::out);
if(!file)
{
printf("Error in opening file");
return;
}
for(int i=0;i<students.size();i++)
{
file.write((char *)&students[i],sizeof(students[i]));
}
file.close();

response.write("<!DOCTYPE html>");
response.write("<html lang='en'>");
response.write("<head>");
response.write("<meta charset='utf-8'>");
response.write("<title>ABC School</title>");
response.write("</head>");
response.write("<body>");
response.write("Student (Delete Module)<br>");
response.write("<h3>Student Deleted</h3>");
response.write("<form method='get' action='index.html'>");
response.write("<button type='submit'>Ok</button>");
response.write("</form>");
response.write("</body>");
response.write("</html>");
response.close();
}

int main()
{
TMWebProjector server(8080);
server.onRequest("/addStudent",add_student);
server.onRequest("/getStudents",get_students);
server.onRequest("/editStudent",edit_student);
server.onRequest("/updateStudent",update_student);
server.onRequest("/confirmDeleteStudent",confirm_delete_student);
server.onRequest("/deleteStudent",delete_student);
server.start();
return 0;
}