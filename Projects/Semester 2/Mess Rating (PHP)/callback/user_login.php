<?php
include 'Database.php';
include 'config.php';

$db = new Database();

session_start();

if(isset($_SESSION['email'])){
    header('location:rating.php');
}

if(isset($_POST['login'])){
    $email = $_POST['email'];
    $password = $_POST['password'];
    $query = "SELECT * FROM `users` WHERE `email` = '$email' AND `password` = '$password'";
    $read = $db->select($query);
    if($read){
        $row = $read->fetch_assoc();
        session_start();
        $_SESSION['email'] = $email;
        $_SESSION['id'] = $row['id'];
        header('location:rating.php');
    }else{
        header('location:user_login.php');
        echo "<script>alert('Email or password is incorrect.')</script>";
    }
}
?>