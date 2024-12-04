// Raise an exception if any attempt is made to refer to an element whose index is beyond the array size.

#include <iostream>
using namespace std;

class Array{
    int a[10], n;

    public:
        Array(){
            n = 10;
        }

        void getArray(){
            cout << "Enter the elements of the array: " << endl;
            for(int i=0; i<n; i++){
                cin >> a[i];
            }
        }

        void displayArray(){
            cout << "The elements of the array are: " << endl;
            for(int i=0; i<n; i++){
                cout << a[i] << " ";
            }
            cout << endl;
        }

        int& operator[](int i){
            if(i < 0 || i >= n){
                throw "Index out of bounds.";
            }
            return a[i];
        }
};

int main(){
    Array arr;
    arr.getArray();
    arr.displayArray();

    cout << "Enter the index of the element to be accessed: ";
    int i;
    cin >> i;

    try{
        cout << "The element at index " << i << " is: " << arr[i] << endl;
    }
    catch(const char* msg){
        cerr << msg << endl;
    }

    return 0;
}
