#include<iostream>
#include<fstream>
#include<string>
#include<conio.h>
using namespace std;

int main()
{
    int a = 0;
    string str;
    string filename = "prikol.cpp";
    string filename_exe = "prog.exe";
    fstream file;
    file.open(filename, ios::out | ios::ate);
    if (file.is_open())
    {
        cout << "------------------" << endl;
        cout << "|F1 - Exit       |\n|F5 - Start      |\n|Enter - Continue|\n";
        cout << "------------------" << endl;
        do
        {
            getline(cin, str);
            a = _getch();
            file << str << endl;

            if (a == 0)
            {
                a = _getch();
                if (a == 63)
                {
                    file.close();
                    string command = "g++ -o " + filename_exe + " " + filename;
                    system(command.c_str());
                    command = "start " + filename_exe;
                    system(command.c_str());
                }
                else if (a == 59)
                {
                    exit(0);
                }
            }

        } while (true);
    }
    else
    {
        cout << "Error!" << endl;
    }
}