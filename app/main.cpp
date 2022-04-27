#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>

#ifdef WINDOWS
#include <direct.h>
#define GetCurrentDir _getcwd
#else
#include <unistd.h>
#define GetCurrentDir getcwd
#endif

#include "../code/Empty.h"

using namespace std;

std::string get_current_dir() {
    cout << "directory" << endl;
   char buff[FILENAME_MAX]; //create string buffer to hold path
   GetCurrentDir( buff, FILENAME_MAX );
   string current_working_dir(buff);
   return current_working_dir;
}

int main(){
    cout<<"Starting workflow" << endl;


    cout << get_current_dir() << endl;

    string array[5]; 
    short loop=0; 
    string line; 
    ifstream myfile ("../app/music_files_test.txt"); 
    if (myfile.is_open()) 
    {
        cout << "FILE FOUND"<< endl;
        while (! myfile.eof() ) 
        {
            getline (myfile,line); 
            array[loop] = line;
            cout << array[loop] << endl; 
            loop++;
        }
        myfile.close(); 
    }
    else cout << "can't open the file"; 
    return 0;
}