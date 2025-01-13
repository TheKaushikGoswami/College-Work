<?php

include 'config/config.php';


$query = "SELECT * FROM users WHERE admin=0";
$result = $conn->query($query);
if ($result->num_rows > 0) {
    echo "<table class='table' style='border-collapse: collapse; width: 100%; text-align: center' align='center'>";
    echo "<tr><th>Roll No</th><th>Name</th><th>Allotment</th></tr>";
    $i = 0;
    while($row = $result->fetch_assoc()) {

        echo "<tr><td>" . $row["roll_no"]. "</td><td>" . $row["name"]. "</td><td><input style='width:25px;height: 25px;' type='checkbox' name='allotment[]' class='allotment' value='" . $row["roll_no"] . "'></td></tr>";
    }
    echo "</table>";
} else { 
    echo "0 results";
}


?>
