<?php

include '../config/config.php';

if (isset($_GET['token'])) {
    $token = $_GET['token'];

    // Prepare statement to select user with the given token
    $sql = $conn->prepare("SELECT * FROM `users` WHERE `token` = ?");
    $sql->bind_param("s", $token);
    $sql->execute();
    $result = $sql->get_result();

    if ($result->num_rows > 0) {
        // Prepare statement to update user status
        $updateSql = $conn->prepare("UPDATE `users` SET `status` = '1' WHERE `token` = ?");
        $updateSql->bind_param("s", $token);
        $updateSql->execute();

        echo "<script>alert('Email verified successfully'); window.location.href='../../login.php';</script>";
    } else {
        echo "<script>alert('Invalid token'); window.location.href='../../login.php';</script>";
    }
} else {
    // Redirect user if no token is provided in the URL
    echo "<script>window.location.href='/quiz-system/login.php';</script>";
}

?>
