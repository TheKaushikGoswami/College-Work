void main() {
  print("Hello, World!");

  // Map
  var map_name = {'key1': 'value1', 'key2': 2, 'kaushik': true};

  print(map_name);
  print(map_name['kaushik']);
  print(map_name['key8']); // null value for non-existing key

  var emp = Map(); // another way of declaring map
  emp = {'name': 'Kaushik', 'yearsOfExperience': 4, 'avgRating': 4.5};
  emp['isRemote'] = false;

  print(emp);

  print(emp.isEmpty);
  print(emp.isNotEmpty);
  print(emp.length);
  print(emp.keys);
  print(emp.values);
  print(emp.containsKey('isRemote'));
  print(emp.containsValue(true));
  print(emp.remove('avgRating'));
  print(emp);
}
