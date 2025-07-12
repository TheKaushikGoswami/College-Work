#include <iostream>
using namespace std;

// Recursion -> Function which calls itself
int find_power(int num){
    // Base case -> If num is 0, return 1
    if(num == 0){
        return 1;
    }

    // Recursive case -> Call the function with num - 1
    int smaller_power = find_power(num - 1);
    int bigger_power = smaller_power * 2;

    return bigger_power;
}

void print_table(int num, int i = 1){
    // Base case -> If i is greater than 10, return
    if(i > 10){
        return;
    }

    // Print the table of num
    cout << num << " * " << i << " = " << num * i << endl;

    // Recursive case -> Call the function with i + 1
    print_table(num, i + 1);
}

int main(){
    int n = 2;
    cout << "Table of " << n << endl;
    print_table(n);
}