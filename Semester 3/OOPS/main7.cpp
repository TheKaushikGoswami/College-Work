// C++ Program to take 2 inputs and divide one by another

#include <iostream>
using namespace std;


int main(){

    int result = -1;
    
    int a, b;
    cin >> a >> b;

    try{

        if(b == 0){
            string s="Zero Division Error";
            throw s;
        }

        result = a/b;
        cout << result;
    }

    catch(string e){
        cout << e << endl << "Division not successful";
    }


    return 0;

}