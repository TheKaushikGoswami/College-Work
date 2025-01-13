<?php

include_once "config/config.php";

if (!isset($_SESSION['admin'])) {
    header('location: ../login.php');
} 

if(isset($_POST['submit'])) {
    $num_subjects = $_POST['num_subjects'];
    $pools = '';
    for($i = 0; $i < $num_subjects; $i++) {
        $pools .= $_POST['subject' . ($i + 1)] . ',';
    }
    $num_questions = '';
    for($i = 0; $i < $num_subjects; $i++) {
        $num_questions .= $_POST['num_questions' . ($i + 1)] . ',';
    }
    $total_ques = 0;
    for($i = 0; $i < $num_subjects; $i++) {
        $total_ques += $_POST['num_questions' . ($i + 1)];
    }

    $quiz_name = $_POST['quiz_name'];
    $quiz_name = strtolower(str_replace(' ', '_', $quiz_name));
    $quiz_rules = $_POST['quiz_rules'];
    $quiz_time = $_POST['quiz_time'];
    $quiz_start = $_POST['quiz_start'];
    $allocated_to_users = $_POST['allocated_to'];

    $quiz_table = "CREATE TABLE `$quiz_name` (
        `id` INT(11) NOT NULL AUTO_INCREMENT,
        `user_id` BIGINT(20) NOT NULL,
        `marks` FLOAT NOT NULL,
        `percentage` FLOAT NOT NULL,
        PRIMARY KEY (`id`)
    ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;";

    $sql = "INSERT INTO `quiz` (`name`, `rules`, `time`, `pools`, `ques_per_pool`, `total_ques`, `start`, `allocated_to`) VALUES ('$quiz_name', '$quiz_rules', '$quiz_time', '$pools', '$num_questions', '$total_ques', '$quiz_start', '$allocated_to_users')";
    $result = $conn->query($sql);
    if($result) {
        $conn->query($quiz_table);
        echo "<script>alert('Quiz added successfully');window.location.href='add_quiz.php'</script>";
        // echo "
        // <script src='https://cdn.jsdelivr.net/npm/sweetalert2@11'></script>
        // <script>
        //     Swal.fire({ 
        //         title: 'Quiz added successfully!',
        //         icon: 'success',
        //         showConfirmButton: false,
        //         timer: 1500
        //     })
        //     setTimeout(() => {
        //         window.location.href = './add_quiz.php';
        //     }, 1500);
        // </script>
        // ";
        
    } else {
        echo $conn->error;
    }

}