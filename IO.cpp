#include <string>
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <iomanip>

using namespace std;

class Benjamin_Horn
{
public:
    void name(string);
    void age (int);
private:
    int years;
    string nombre;

};

void startprogram()
{
    string startprogram = "Program Started";
    string name = "- Benjamin Horn";

    for (int i = 0; i < startprogram.length(); i++)
    {
        cout<<startprogram[i];
        Sleep(100);
    }
    cout<<endl;


    for ( int i = 0; i < name.length(); i ++)
    {
        cout<<name[i];
        Sleep(50);
    }
    cout<<endl;
}

void showlines()
{
    string line= "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
    for (int i = 0; i <line.length(); i++)
    {
        cout<<line[i];
        Sleep(50);
    }cout<<endl;
    cout<<endl;

}

void endprogram()
{
    string endprogram = "Program Ended";
    string name = "- Benjamin Horn";

    for (int i = 0; i < endprogram.length(); i++)
    {
        cout<<endprogram[i];
        Sleep(50);
    }
    cout<<endl;


    for ( int i = 0; i < name.length(); i ++)
    {
        cout<<name[i];
        Sleep(50);
    }
    cout<<endl;
}

void graphicname()
{

cout<<endl;
string name1="  Benj       Benjamin    Be      enj";
for (int i = 0; i < name1.length(); i ++){cout<<name1[i]; Sleep(30);}cout<<endl;
string name2="  B   ami    Ben         Ben      nj";
for (int i = 0; i < name2.length(); i ++){cout<<name2[i]; Sleep(30);}cout<<endl;
string name3="  B    min   Ben         Benj     nj";
for (int i = 0; i < name3.length(); i ++){cout<<name3[i]; Sleep(30);}cout<<endl;
string name4="  B   ami    Ben         Be ja    nj";
for (int i = 0; i < name4.length(); i ++){cout<<name4[i]; Sleep(30);}cout<<endl;
string name5="  Benjamin   Benjamin    Be   mi  nj";
for (int i = 0; i < name5.length(); i ++){cout<<name5[i]; Sleep(30);}cout<<endl;
string name6="  B   ami    Ben         Be    in nj";
for (int i = 0; i < name6.length(); i ++){cout<<name6[i]; Sleep(30);}cout<<endl;
string name7="  B    min   Ben         Be     Benj";
for (int i = 0; i < name7.length(); i ++){cout<<name7[i]; Sleep(30);}cout<<endl;
string name8="  B   amin   Ben         Be      enj";
for (int i = 0; i < name8.length(); i ++){cout<<name8[i]; Sleep(30);}cout<<endl;
string name9="  Benjam     Benjamin    Ben      nj";
for (int i = 0; i < name9.length(); i ++){cout<<name9[i]; Sleep(30);}cout<<endl;
cout<<endl;

}

void systemwait()
{
    system("Pause");
    system("cls");

}


int main()
{
startprogram();
showlines();
graphicname();
systemwait();
endprogram();

    return 0;
}
