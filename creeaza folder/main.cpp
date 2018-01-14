#include <iostream>
#include <string>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

string projectPath = "C:\\work\\c++\\creeaza folder\\foldere";
string dirName = "\\Dosar";
string subdirName = "\\AltDosar";
string fileName = "\\File";
string fileExtension = ".txt";

int numberOfDir = 300;
int numberOfFiles = 50;
int numberOfSubdirectors = 50;

string intToString(int number)
{
    ostringstream oss;

    oss<< number;

    return oss.str();
}

void createDir(string path)
{
    string command;

    command = "mkdir \"" + path + "\"" ;

    //cout<<'\n'<<command<<'\n';

    system(command.c_str());
}

void createFile(string path)
{
    fclose(fopen(path.c_str(),"w"));
}

int main()
{
    for(int i=0;i<numberOfDir;i++)
    {
        ///creaza dosar
        string dirPath = projectPath + dirName + intToString(i+1);
        createDir(dirPath);

        for(int j=0;j<numberOfSubdirectors;j++)
        {
            string subdirPath = dirPath + subdirName + intToString(j+1);
            createDir(subdirPath);
        }
    }

    return 0;
}
