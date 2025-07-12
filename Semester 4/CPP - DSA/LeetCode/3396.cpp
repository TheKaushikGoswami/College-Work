// A function to remove first 3 elements from a vector and return the new vector

#include <iostream>
#include <vector>
using namespace std;

vector<int> removeFirstThreeElements(const vector<int>& vec) {
    // Check if the vector has at least 3 elements
    if (vec.size() < 3) {
        // Remove all elements if less than 3
        return vector<int>(); // Return an empty vector
    }

    // Create a new vector to store the result
    vector<int> newVec(vec.begin() + 3, vec.end()); // Copy elements from index 3 to the end

    return newVec; // Return the new vector
}

// A function to check if a vector is distinct
bool isDistinct(const vector<int>& vec) {
    // Create a set to store unique elements
    set<int> uniqueElements(vec.begin(), vec.end());

    // Check if the size of the set is equal to the size of the vector
    return uniqueElements.size() == vec.size(); // Return true if distinct, false otherwise
}

// A function to call isDistinct and removeFirstThreeElements until the vector is distinct
void processVector(vector<int>& vec) {
    // Loop until the vector is distinct
    while (!isDistinct(vec)) {
        // Remove the first 3 elements
        vec = removeFirstThreeElements(vec);
    }
}