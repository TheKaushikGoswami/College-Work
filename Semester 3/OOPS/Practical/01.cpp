// Multiplication of 2 matrices using OOP

#include <iostream>
using namespace std;

class Matrix{
    int a[10][10], b[10][10], c[10][10], m, n, p, q;

    public:
        void getMatrix(){
            cout << "Enter the number of rows and columns of the first matrix: ";
            cin >> m >> n;
            cout << "Enter the number of rows and columns of the second matrix: ";
            cin >> p >> q;

            if(n != p){
                cout << "The matrices cannot be multiplied with each other." << endl;
                exit(0);
            }

            cout << "Enter the elements of the first matrix: " << endl;
            for(int i=0; i<m; i++){
                for(int j=0; j<n; j++){
                    cin >> a[i][j];
                }
            }

            cout << "Enter the elements of the second matrix: " << endl;
            for(int i=0; i<p; i++){
                for(int j=0; j<q; j++){
                    cin >> b[i][j];
                }
            }
        }

        void multiplyMatrix(){
            for(int i=0; i<m; i++){
                for(int j=0; j<q; j++){
                    c[i][j] = 0;
                    for(int k=0; k<n; k++){
                        c[i][j] += a[i][k] * b[k][j];
                    }
                }
            }
        }

        void displayMatrix(){
            cout << "The product of the two matrices is: " << endl;
            for(int i=0; i<m; i++){
                for(int j=0; j<q; j++){
                    cout << c[i][j] << " ";
                }
                cout << endl;
            }
        }
    
};

int main(){
    Matrix m;
    m.getMatrix();
    m.multiplyMatrix();
    m.displayMatrix();
    return 0;

}