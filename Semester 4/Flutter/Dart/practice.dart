// ignore_for_file: unused_local_variable

import 'dart:io';

void main() {
  print("Hi! I am Kaushik");

  stdout.write("Enter your name: ");
  var name = stdin.readLineSync();

  print("Welcome, $name");

  var kaushik = new Human(); // creating a Class Object

  // Declaration of Variable

  int i;
  // print(i);          Error: Non-nullable variable 'i' must be assigned before it can be used.

  int? a; // Null-able variable : Can have null value
  print(a);

  int b;
  b = 5;
  print(b);
  b = 10; // Updates the value of b
  print(b);

  // Inline Declaration
  String s = "Kaushik";

  // BigInt
  BigInt longValue;
  longValue = BigInt.parse('87654345676543245676543');

  print(longValue);

  // Decimal
  double d = 9.77;
  num dd = 9.78;

  // Boolean
  bool isLogin = false;
  isLogin = true;

  // var
  var subject = "Maths";

  var test; // when not initialised, the data type is dynamic

  test = "D"; // can accept string
  test = 14; // as well as integer
  test = 9.889; // and decimal values

  // dynamic
  dynamic x;

  x = "String";
  x = 9;
  x = false;

  var h = Human(); // Object creation
  h.myFunc("Kaushik"); // Function Calling

  h.myFunc("Wowww");

  print(h.Add(1, 2));

  // List

  var list = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100];
  list.add(500); // Add an element to the list

  print(list);

  list.replaceRange(0, 3, [0, 1, 2, 3]); // Replace a specific range of elements
  list.removeLast(); // Removes the last element
  list.remove(40); // Removes an element with a specific value
  list.removeAt(2); // Removes an element at a specific index
  list.removeRange(0, 2);

  var names = [];
  names.add("Kaushik");
  names.add("Wowww");
  names.addAll(list); // Add all elements from another list
  names.insert(2, 300); // Insert element at a specific index
  names.insertAll(1, list); // Insert a list at a particular index
  names[2] = "haha"; // Update the value of an index

  print(names);
  print("Length: ${names.length}"); // Length of a list
  print("Reverse: ${names.reversed}"); // Reverse of a list
  print("First: ${names.first}"); // First element of list
  print("Last: ${names.last}"); // Last element of list
  print("Is Empty: ${names.isEmpty}"); // Check if list is empty
  print("Is not Empty: ${names.isNotEmpty}"); // Check if list is not empty
  print(names.elementAt(4)); // Find element at specific index


}

class Human {
  // Constructors

  // Default Construtor
  Human() {
    print("New Object Created!");
  }

  // Functions
  void myFunc(String name) { // Function declaration
    print("Hello, World! $name"); // Function definition
  }

  int Add(int a, int b) {
    return a + b;
  }
}
