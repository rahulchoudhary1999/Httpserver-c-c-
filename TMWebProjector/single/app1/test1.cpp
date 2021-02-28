#include<iostream>
#include<stdio.h>
#include<fstream>
#include<vector>
using namespace std;
class Student
{
public:
int rollNumber;
char *name;
};
int main()
{
vector<Student> students;
ifstream file1;
file1.open("student.dat",ios::in);
if(!file1)
{
printf("Error2");
return 0;
}
Student s;
while(true)
{
if(!file1.read((char *)&s,sizeof(s)))break;
students.push_back(s);
}
for(int i=0;i<students.size();i++)
{
printf("%d,%s\n",students[i].rollNumber,students[i].name);
}
file1.close();
return 0;
}