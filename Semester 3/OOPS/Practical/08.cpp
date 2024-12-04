// Perform the deletion of white spaces such as horizontal tab, vertical tab, space, line feed, new line and carriage return from a text file and store the contents of the file without the white spaces in another file.

#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream fin("input.txt");
    ofstream fout("output.txt");

    char ch;
    while(fin.get(ch)){
        if(ch != ' ' && ch != '\t' && ch != '\v' && ch != '\n' && ch != '\r'){
            fout << ch;
        }
    }

    fin.close();
    fout.close();

    return 0;
}