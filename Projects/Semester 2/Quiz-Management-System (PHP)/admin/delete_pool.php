<?php

include 'config/config.php';
include '../includes/header.php';
include '../includes/footer.php';

if (!isset($_SESSION['admin'])) {
    header('location: ../login.php');
}

$pool_name = $_SERVER['QUERY_STRING'];
$pool_name = substr($pool_name, 5);

$pool_name = str_replace('%20', '_', $pool_name);

$pool_name = strtolower($pool_name);

$sql = "DELETE FROM `question_pools` WHERE `name` = '$pool_name'";

$result = $conn->query($sql);

if ($result === TRUE) {
    $sql2 = "DROP TABLE `$pool_name`";
    $result2 = $conn->query($sql2);
    // echo "<script>alert('Pool deleted successfully!'); window.location.href='pools.php';</script>";
    echo "
    <script src='https://cdn.jsdelivr.net/npm/sweetalert2@11'></script>
    <script>
    Swal.fire({
        title: 'Pool deleted successfully!',
        icon: 'success',
        showConfirmButton: false,
        timer: 1500
    })
    
    setTimeout(() => {
        window.location.href = 'pools.php';
    }, 1500);
    </script>";
} else {
    echo "Error: " . $sql . "<br>" . $conn->error;
}


?>