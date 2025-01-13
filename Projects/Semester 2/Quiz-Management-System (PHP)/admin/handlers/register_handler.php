<?php

require '../config/config.php';

if (isset($_POST['submit'])) {
    $roll = $conn->real_escape_string($_POST['roll']);
    $name = $conn->real_escape_string($_POST['name']);
    $email = $conn->real_escape_string($_POST['email']);
    $em_check = "SELECT * FROM `users` WHERE `email` = '$email'";
    $em_result = $conn->query($em_check);
    if ($em_result->num_rows > 0) {
        echo "<script>alert('User with this email is already registered'); window.location.href='../../register.php';</script>";
    } else {
        $course = $conn->real_escape_string($_POST['course']);
        $year = $conn->real_escape_string($_POST['year']);
        $password = $conn->real_escape_string($_POST['password']);
        $cnf_password = $conn->real_escape_string($_POST['cnf_password']);

        $sql = "SELECT * FROM `users` WHERE `roll_no` = '$roll'";
        $result = $conn->query($sql);

        if ($result->num_rows > 0) {
            echo "<script>alert('User with this roll number is already registered!'); window.location.href='../../register.php';</script>";
        } elseif ($password == $cnf_password) {
            $token = bin2hex(random_bytes(50));
            $sql = "INSERT INTO `users` (`roll_no`, `name`, `email`, `course`, `year`, `password`) VALUES ('$roll', '$name', '$email', '$course', '$year', '$password')";
            if ($conn->query($sql) === TRUE) {
                echo "<script>alert('Team Registered Successfully! Please Login Now.'); window.location.href='../../login.php';</script>";
            } else {
                echo "<script>alert('Error: " . $conn->error . "'); window.location.href='../../register.php';</script>";
            }
        } else {
            echo "<script>alert('Passwords do not match!'); window.location.href='../../register.php';</script>";
        }
    }
}

?>