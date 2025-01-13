<?php 
ob_start();
session_start(); // Start the session

// Check if the user is logged in

include 'Database.php';
include 'config.php';

$db = new Database();

if (!isset($_SESSION['email'])) {
    header('Location: login.php'); // Redirect to the login page

}


if(isset($_POST['submit'])){
    // Rest of your code...
    date_default_timezone_set('Asia/Kolkata');
    for($i=1;$i<=6;$i++){
        $date = $_POST['date'];
        $meal = $_POST['meal'];
        $item = $_POST['item'.$i];
        if($item == '0'){
            continue;
        }
        $query = "INSERT INTO `menu`(`date`, `meal_id`, `item_id`) VALUES ('$date','$meal','$item')";
        $create = $db->insert($query);
        
        
    }
    if(isset($create)){
        echo "<script>alert('Data Inserted Successfully.');</script>";
    }else{
        echo "<script>alert('Data Insertion Failed.');</script>";
    }
}

if(isset($_POST['logout'])){
    session_destroy();
    header('Location: login.php'); // Redirect to the login page
    exit;
}




?>