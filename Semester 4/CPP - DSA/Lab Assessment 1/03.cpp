// Linear Keyboard

// You are given a keyboard that consists of 26 keys. The keys are arranged sequentially in one row in a certain order. Each key corresponds to a unique lowercase Latin letter.

// You have to type the word s on this keyboard. It also consists only of lowercase Latin letters.
// To type a word, you need to type all its letters consecutively one by one. To type each letter you must position your hand exactly over the corresponding key and press it.

// Moving the hand between the keys takes time which is equal to the absolute value of the difference between positions of these keys (the keys are numbered from left to right). No time is spent on pressing the keys and on placing your hand over the first letter of the word.

// For example, consider a keyboard where the letters from 'a' to 'z' are arranged in consecutive alphabetical order. The letters 'h', 'e', 'l' and 'o' then are on the positions 8, 5, 12 and 15 respectively. Therefore, it will take |5−8|+|12−5|+|12−12|+|15−12|=13 units of time to type the word "hello".


// Determine how long it will take to print the word s.


// Input format
// The first line of a description contains a keyboard — a string of length 26 
// which consists only of lowercase Latin letters. Each of the letters from 'a' to 'z' appears exactly once on the keyboard.
// The second line of the input contains the word s.


// Output format
// Print  the minimal time it takes to type the word s on the given keyboard.

// Example 1

// Input
// abcdefghijklmnopqrstuvwxyz
// hello

// Output
// 13

// Explanation
// The letters 'h', 'e', 'l' and 'o' then are on the positions 8 , 5 , 12 and 15 , respectively.
// Therefore, it will take |5−8|+|12−5|+|12−12|+|15−12|=13 units of time to type the word "hello".

// Constraints
// 1 <= s.length <= 1000 

#include <bits/stdc++.h>
using namespace std;

int main(){
    string keyboard, s;
    cin >> keyboard >> s;
    vector <int> key;
    int time = 0;

    for(char c : s){
        key.push_back(keyboard.find(c)+1);
    }

    for(int i=0; i<key.size() - 1; i++){
        time += abs(key[i] - key[i+1]);
    }
    cout << time;
    return 0;
}