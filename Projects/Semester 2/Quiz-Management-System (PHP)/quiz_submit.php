<?php

error_reporting(E_ALL & ~E_WARNING);
ini_set('display_errors', 1);

include 'includes/header.php';
include 'admin/config/config.php';

// Extract 'id' query parameter safely
$quiz_id = $_SERVER['QUERY_STRING'];
$quiz_id = str_replace("quiz_id=", "", $quiz_id);

// Prepare statement to avoid SQL injection
$sql = "SELECT * FROM `quiz` WHERE `id` = ?";
$stmt = $conn->prepare($sql);

if (!$stmt) {
    echo "Prepare failed: (" . $conn->errno . ") " . $conn->error;
    include 'includes/footer.php';
    exit;
}

$stmt->bind_param("s", $quiz_id);
$stmt->execute();
$result = $stmt->get_result();

if ($row = $result->fetch_assoc()) {
    $quiz_name = $row['name'];
    $total_questions = $row['total_ques'];

    if (isset($_POST['submit'])) {
        $score = 0;
        for ($i = 1; $i <= $total_questions; $i++) {
            if (empty($_POST['ques' . $i]) || empty($_POST['ans' . $i])) {
                continue;
            }
            $ques = $_POST['ques' . $i];
            $ans = $_POST['ans' . $i];
            if ($ques == $ans) {
                $score++;
            }
        }

        $final_score = ($score / $total_questions) * 100;
        $final_score = number_format($final_score, 2);

        // Prepare statement for insert to avoid SQL injection
        $sql_insert = "INSERT INTO `$quiz_name` (`user_id`, `marks`, `percentage`) VALUES (?, ?, ?)";
        $stmt_insert = $conn->prepare($sql_insert);

        if (!$stmt_insert) {
            echo "Prepare failed: (" . $conn->errno . ") " . $conn->error;
        } else {
            $stmt_insert->bind_param("sii", $_SESSION['user'], $score, $final_score);
            if ($stmt_insert->execute()) {
                // echo "<script>alert('Quiz Submitted Successfully!'); window.location.href='index.php';</script>";
                echo "
                <script src='https://cdn.jsdelivr.net/npm/sweetalert2@11'></script>
                <script>
                    Swal.fire({
                        title: 'Quiz Submitted Successfully!',
                        icon: 'success',
                        showConfirmButton: false,
                        timer: 1500
                    })
                    setTimeout(() => {
                        window.location.href = 'index.php';
                    }, 1500);
                    </script>";
            } else {
                echo "Error: " . $stmt_insert->error;
            }
            $stmt_insert->close();
        }
    }
} else {
    echo "Quiz not found.";
}

$stmt->close();
include 'includes/footer.php';

?>
