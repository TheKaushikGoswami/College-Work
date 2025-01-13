<?php
session_start(); // Start the session

include 'Database.php';
include 'config.php';

$db = new Database();

$danger = 'danger';
$userid = $_SESSION['id'];
$date = date('Y-m-d');

if(!isset($_SESSION['id'])){
    header('location:user_login.php');
}

if(isset($_POST['logout'])){
    session_destroy();
    header('location:user_login.php');
}

if($currentTime >= '8:00' && $currentTime <= '12:00'){
    $meal = '1';
    $query = "SELECT * FROM `menu` WHERE meal_id = 1 AND date = '$date'";
    $result = $db->select($query);
    $no_of_rows = mysqli_num_rows($result);
    
}elseif($currentTime >= '12:00' && $currentTime <= '16:00'){
    $meal = '2';
    $query = "SELECT * FROM `menu` WHERE meal_id = 2 AND date = '$date'";
    $result = $db->select($query);
    $no_of_rows = mysqli_num_rows($result);

}elseif($currentTime >= '16:00' && $currentTime <= '20:00'){
    $meal = '3';
    $query = "SELECT * FROM `menu` WHERE meal_id = 3 AND date = '$date'";
    $result = $db->select($query);
    $no_of_rows = mysqli_num_rows($result);

}elseif($currentTime >= '20:00' && $currentTime <= '23:59'){
    $meal = '4';
    $query = "SELECT * FROM `menu` WHERE meal_id = 4 AND date = '$date'";
    $result = $db->select($query);
    $no_of_rows = mysqli_num_rows($result);

}

if(isset($_POST['submit'])){
    $i = 1;
    while($i <= $no_of_rows){
        // error_reporting(E_ALL ^ E_WARNING);
        $item_id = $_POST['item_id'.$i];
        $rating = $_POST['rating'.$i];
        $check = "SELECT * FROM `ratings` WHERE user_id = '$userid' AND item_id = '$item_id' AND meal_id = '$meal' and date = '$date'";
        if($rating == 0){
            $rating = NULL;
        }
        $check_result = $db->select($check);
        if($check_result){
            if($check_result->num_rows > 0){
                $query = "UPDATE `ratings` SET `rating`='$rating' WHERE user_id = '$userid' AND item_id = '$item_id' AND meal_id = '$meal' and date = '$date'";
                $result = $db->update($query);
            }else{
                break;
            }
        }
        else{
        $query = "INSERT INTO `ratings`(`user_id`, `item_id`, `rating`, `meal_id`) VALUES ('$userid','$item_id','$rating','$meal')";
        $result = $db->insert($query);
    }
    $i++;
    }
    
}



?>