<?php

include 'config/config.php'; // Adjust the path as necessary

if(isset($_POST['roll_no'])) {
    $roll_no = $_POST['roll_no'];
    $u_name = "SELECT * FROM users WHERE roll_no = ?";
    $u = $conn->prepare($u_name);
    $u->bind_param("s", $roll_no);
    $u->execute();
    $u_result = $u->get_result();
    $u_row = $u_result->fetch_assoc();
    $username = $u_row['name'];
    $course = $u_row['course'];
    $sql = "SELECT * FROM quiz WHERE `allocated_to` LIKE CONCAT('%', ?, '%')";
    $stmt = $conn->prepare($sql);
    $stmt->bind_param("s", $roll_no);
    $stmt->execute();
    $result = $stmt->get_result();

    $output = [];

    if ($result->num_rows > 0) {
        while ($row = $result->fetch_assoc()) {
            $name = $row['name'];
            $name = strtolower($name);
            $no_of_ques = $row['total_ques'];
            $date = $row['start'];
            $date = date('d-m-Y', strtotime($date));

            $sql2 = "SELECT * FROM $name WHERE `user_id` = ?";
            $stmt2 = $conn->prepare($sql2);
            $stmt2->bind_param("s", $roll_no);
            $stmt2->execute();
            $result2 = $stmt2->get_result();

            while ($r = $result2->fetch_assoc()) {
                $correct_ques = $r['marks'];
                $percentage = $r['percentage'];
                $output[] = [$roll_no, $username,$course, $name, $date, $percentage, $correct_ques, $no_of_ques];
            }
        }
        echo json_encode($output);
    } else {
        echo json_encode(["error" => "No student found with this roll number"]);
    }
} else {
    echo json_encode(["error" => "No roll number provided"]);
}
