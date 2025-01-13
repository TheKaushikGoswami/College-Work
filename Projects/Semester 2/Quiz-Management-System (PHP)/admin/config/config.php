<?php
ini_set("display_errors",1);
$host = 'srv1474.hstgr.io';
$user = 'u558257531_techquiz_user';
$pass = 'Q8H?lD>pr?7w';
$db = 'u558257531_techquiz';
$tz = 'Asia/Kolkata';

date_default_timezone_set($tz);
$conn = new mysqli($host, $user, $pass, $db);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

if (!isset($_SESSION)){
    session_start();
}

if (isset($_POST['logout'])) {
    session_destroy();
    if(isset($_SESSION['admin'])){
        header('Location: ../login.php');
    }else{
        header('Location: login.php');
    }
    exit; // Ensure no further code is executed after redirection
}

?>