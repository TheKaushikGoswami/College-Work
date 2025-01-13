<?php

include_once('config.php');
include_once('Database.php');

$db = new Database();

session_start();

if (isset($_SESSION['email'])) {
    header('Location: mess.php'); // Redirect to the mess.php page
    exit(); // Stop executing the rest of the code
}

if (isset($_POST['login'])) {
    $email = $_POST['email'];
    $password = $_POST['password'];
    if ($email == 'mess@geetauniversity.edu.in' && $password == 'mess@123') {
        $_SESSION['email'] = $email;
        header('location:mess.php');
        exit(); // Stop executing the rest of the code
    } else {
        echo "<script>alert('Email or password is incorrect.')</script>";
    }
}
?>
