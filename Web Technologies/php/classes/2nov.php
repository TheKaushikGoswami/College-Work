<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>2nd November</title>
</head>
<body>

<?php

    $result = '';

    $num1 = 87;
    $num2 = 70;

    echo $result= $num1 + $num2;
    echo "<br>";
    echo $result= $num1 - $num2;
    echo "<br>";
    echo $result= $num1 * $num2;
    echo "<br>";
    echo $result= $num1 / $num2;
    echo "<br>";
    echo $result= $num1 % $num2;

    $array1 = array(
        
        array(
            'a1' => 'A1',
            'a2' => 'A2'
        ),
        
        array(
            'a1' => 'B1',
            'a2' => 'B2'
        )
    );

    echo "<pre>";
    print_r($array1);
    echo "</pre>";  

    // For Each Loop:

    foreach($array1 as $row){

        foreach($row as $r1){
                
                echo "<pre>";
                echo $r1;
                echo "</pre>";
        }

        // echo "<pre>";
        // echo $row['a1'];
        // echo "</pre>";
    }

    $table = "<table border='1' style='width:500px'>";

    foreach($array1 as $row){
        $table.= '<tr>';

        foreach($row as $r1){

            if ($r1 == 'A1') {
                $r1 = '';
                // break; // Breaks the loop
                continue; // Skips the loop
            }
            elseif ($r1 == 'B1'){
                $r1 = 'Changed Value';
            }
            else{
                $r1 = 'No Value';
            }

           $table.= '<td>'.$r1.'</td>';
        }

        $table.= '</tr>';
    }

    $table.= '</table>';

    echo $table;

    /*

    Types of Operators:

        1. Arithmetic Operators: +, -, *, /, %, ++, --

        2. Assignment Operators: =, +=, -=, *=, /=, %=, .=

        3. Comparison Operators: ==, ===, !=, !==, <, >, <=, >=, <=>, ??, ?:

        4. Logical Operators: &&, ||, !

        5. Increment/Decrement Operators: ++, --

        6. String Operators: ., .=

        7. Array Operators: +, ==, ===, !=, !==, <, >, <=, >=, <=>, ??, ?:

        8. Conditional Assignment Operators: ?:, ??=

        9. Type Operators: instanceof

        10. Bitwise Operators: &, |, ^, ~, <<, >>, <<<, >>>

        11. Error Control Operators: @

        12. Execution Operators: `

        13. Other Operators: ->, ::, [], ()

    */

    /*

    Types of Data:

        1. String: "Hello World", 'Hello World'

        2. Integer: 123, 456, 789

        3. Float: 1.23, 4.56, 7.89

        4. Boolean: true, false

        5. Array: [1, 2, 3], ['a', 'b', 'c']

        6. Object: {a: 1, b: 2, c: 3}, {a: 'a', b: 'b', c: 'c'}

        7. NULL: null
    
    */
        
    /*

    Types of Loop:

        1. For Each Loop:
                            foreach(initialization as key => value; condition; increment/decrement){
                                    code to be executed;
                            }

        2. For Loop:
                            for(initialization; condition; increment/decrement){
                                code to be executed;
                            }

        3. While Loop:
                            while(condition){
                                code to be executed;
                            }

        4. Do While Loop:
                            do{
                                code to be executed;
                            }while(condition);
    
    */



?>
    
</body>
</html>