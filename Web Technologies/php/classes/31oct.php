<?php

ini_set('display_errors', 1); // Show errors for debugging


?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>

<body>
    <h1>
        This is Doc
    </h1>
    <pre>

        <?php

            $var1 = ''; // Variable declaration

            $var2 = array(); // Array declaration

            $var3 = array('a', 'b', 'c'); // Array declaration with values

            $var4 = array(
                'a' => 'A',
                'b' => 'B',
                'c' => 'C'
            ); // Array declaration with key and values

            $var5 = array(
                'a' => array(
                    'a1' => 'A1',
                    'a2' => 'A2'
                ),
                'b' => array(
                    'b1' => 'B1',
                    'b2' => 'B2'
                ),
                'c' => array(
                    'c1' => 'C1',
                    'c2' => 'C2'
                )
            ); // Array declaration with key and values (Multidimensional array)

            $var6 = array(
                array(
                    'a1' => 'A1',
                    'a2' => 'A2'
                ),
                array(
                    'b1' => 'B1',
                    'b2' => 'B2'
                ),
                array(
                    'c1' => 'C1',
                    'c2' => 'C2'
                )
            ); // Array declaration with key and values (Multidimensional array)

            echo "<h1>Hello World!</h1>"; // HTML code (All HTML code must be in string format) (Can't print array)

            print_r("<p>Hello World</p>"); // Print string (Can print array)

            print_r($var3); // Print array

            echo "<br> <br>";

            print_r($var4); // Print another array

            echo "<br> <br>";

            print_r($var5); // Print multidimensional array

            echo "<br> <br>";

            print_r($var6, "<br>"); // Print multidimensional array

            echo "<br> <br>";

            echo 990283.."s"; // Concatenation of string with number (using double .)

            echo "<br> <br>";

            echo 990283 . "s"; // Concatenation of string with number (using single .)

            echo "<br> <br>";

            echo "Hello" . "World"; // Concatenation of string with string (using single .)

            echo "<br> <br>";

            echo "Hello" . " " . "World"; // Concatenation of string with string (using single .)

            print_r("<br> <br>");

            print_r($var6[0]['a1']); // Print array value

            die; // Stop the code

            
            // Types of error:
            // 1. Fatal error - Doesn't let the code run
            // 2. Warning - Shows error but let the code run
            // 4. Notice - Doesn't show error but let the code run

            
        ?>
    </pre>

    <!-- 

    <pre> tag is used to show the code as it is written

     -->

</body>

</html>