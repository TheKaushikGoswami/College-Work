void main() {
  print("Hello, World!");

  // Final keyword
  final name = "Kaushik"; // The value of variable can't be updated later

  // name = "Haha"; Error

  print(name);

  final int i;
  i = 10;
  print(i);

  // Const keyword
  const test =
      "Woww"; // Same as final but must be declared and initialized together, not later

  print(test);

  final names = ["Kaushik", "Praveen"];
  names.add("Rahul"); // Data can be modified during runtime
  print(names);

  const names2 = ["Abhishek", "Sahil"];
  names2.add("Kaushik");
  // print(names2); Will throw an error as data can't be modified during runtime
}
