<?php

include 'config/config.php';

if ($_SERVER['REQUEST_METHOD'] == 'POST') {
    $course = $_POST['course'];
    $year = $_POST['year'];

    // Prepare and execute the query
    $query = "SELECT * FROM question_pools WHERE course = '$course' AND year = '$year'";
    $result = $conn->query($query);

    // Check if there are rows returned from the query
    if ($result->num_rows > 0) {
        echo "<option selected>Select Pool Here</option>";
        // Output each pool as an option
        while ($row = $result->fetch_assoc()) {
            echo '<option value="' . $row["name"] . '">' . str_replace('_', ' ', $row["name"]) . '</option>';
        }
    } else {
        // If no pools are found for the given course and year, disable the select
        echo '<option disabled>No Pools Found</option>';
    }
}
