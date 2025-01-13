<?php

include 'config/config.php';
// include 'pools.php';

if (!isset($_SESSION['admin'])) {
    header('location: ../login.php');
}

if (isset($_POST['submit'])) {
    $table = $_POST['question_pool'];
    
    $file = $_FILES['file'];

    // Check if the file is a CSV
    $file_extension = pathinfo($file['name'], PATHINFO_EXTENSION);
    if ($file_extension == 'csv') {
        // Read CSV file
        $csv_data = array_map('str_getcsv', file($file['tmp_name']));

        // Extract header and data
        $header = array_shift($csv_data);

        // Prepare SQL statement
        $sql = "INSERT INTO $table(question, option1, option2, option3, option4, answer) VALUES ";

        foreach ($csv_data as $row) {
            $sql .= "('" . implode("', '", $row) . "'),";
        }

        // Remove the trailing comma
        $sql = rtrim($sql, ',');

        // Execute the query
        
        if ($conn->query($sql) === TRUE) {
            echo "<script>alert('Questions uploaded successfully!');
                window.location.href='pools.php';
            </script>";
        } else {
            echo "<script>alert('Error: " . $sql . "<br>" . $conn->error . "')</script>";
        }
    } else {
        echo "<script>alert('Please upload a CSV file.');
            window.location.href='pools.php';
        </script>";
    }
}

?>