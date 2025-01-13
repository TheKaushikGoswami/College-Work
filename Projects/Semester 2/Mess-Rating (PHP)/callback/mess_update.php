<?php 


include 'Database.php';
include 'config.php';
include 'includes/header.php';

$db = new Database();
session_start(); // Start the session

if (!isset($_SESSION['email'])) {
    header('Location: login.php'); // Redirect to the login page

}


if(isset($_POST['submit'])){
    // Rest of your code...
    date_default_timezone_set('Asia/Kolkata');
        $date = $_POST['date'];
        $meal = $_POST['meal'];
        $item = $_POST['item_old'];
        $item_new = $_POST['item_update'];
        $query = "UPDATE `menu` SET `item_id`='$item_new' WHERE DATE(`date`)='$date' AND `meal_id`='$meal' AND `item_id`='$item'";
        $update = $db->update($query);
        if($update){
            echo "<script>alert('Data Successfully Updated.');</script>";
        }else{
            echo "<script>alert('Data Updation Failed.');</script>";
        }
        
   
}

if(isset($_POST['logout'])){
    session_destroy();
    header('Location: login.php'); // Redirect to the login page
    exit;
}





?>