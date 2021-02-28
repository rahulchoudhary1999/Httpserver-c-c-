g++ -c TMWP.cpp -std=c++11 -I ..\include 
ar rcs tmwp.lib *.o
del ..\lib\tmwp.lib
move tmwp.lib ..\lib