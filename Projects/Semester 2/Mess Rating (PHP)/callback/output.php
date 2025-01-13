<?php 


include 'Database.php';
include 'config.php';
include 'includes/header.php';

$dateselected = date('Y-m-d');
$db = new Database();
session_start(); // Start the session

if(isset($_POST['logout'])){
    session_destroy();
    header("Location: login.php");
}
if(isset($_POST["search"])){
    $dateselected = $_POST["selectedDate"];
    // echo "<h1 class='text-center'>Date Selected:";
    // echo $dateselected;
    // echo "</h1>";
}


?>