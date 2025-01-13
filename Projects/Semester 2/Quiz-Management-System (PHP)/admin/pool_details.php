<?php

include "../includes/header.php";
include 'config/config.php';

if (!isset($_SESSION['admin'])) {
    header('location: ../login.php');
}

$pool_id = $_SERVER['QUERY_STRING'];
$pool_id = substr($pool_id, 8);

$sql = "SELECT name FROM `question_pools` WHERE `id` = '$pool_id'";
$result = $conn->query($sql);
$row = $result->fetch_assoc();
$pool_name = $row['name'];
$pool_name = strtolower($pool_name);

$sql = "SELECT * FROM `$pool_name`";
$result = $conn->query($sql);

?>

<div class="container-fluid p-0">
<nav class="navbar navbar-expand-md bg-light m-0">
        <div class="container-fluid">
            <a class="navbar-brand" href="./index.php">Quiz Manager</a>
            <button style="border:none"z class="navbar-toggler" type="button" data-bs-toggle="collapse"
                data-bs-target="#navbarSupportedContent" aria-controls="navbarSupportedContent" aria-expanded="false"
                aria-label="Toggle navigation">
                <span class="navbar-toggler-icon"></span>
            </button>
            <div class="collapse navbar-collapse" id="navbarSupportedContent">
                <ul class="navbar-nav me-auto mb-2 mb-lg-0">
                    <li class="nav-item">
                        <a class="nav-link active" aria-current="page" href="index.php">Home</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="pools.php">Question Pools</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="user_details.php">Result by Roll</a>
                    </li>
                </ul>
                <form class="d-flex" method="post" role="search">
                    <button class="btn btn-outline-danger" type="submit" name="logout">Logout</button>
                </form>
            </div>
        </div>
    </nav>
    <div class="container">
        <div class="row justify-content-center">
            <div class="col-md-10 mt-5">
                <div class="card p-4 mb-5" style="border-radius:30px">
                        <h1 class="text-center"><?php echo strtoupper(str_replace('_',' ',$pool_name)); ?></h1>
                    <div class="card-body">
                        <table class="table table-stripe table-hover">
                            <thead>
                                <tr>
                                    <th scope="col" class="col-md-1">Sr no.</th>
                                    <th scope="col" class="col-md-4">Question</th>
                                    <th scope="col" class="col-md-2">Option 1</th>
                                    <th scope="col" class="col-md-2">Option 2</th>
                                    <th scope="col" class="col-md-2">Option 3</th>
                                    <th scope="col" class="col-md-2">Option 4</th>
                                    <th scope="col" class="col-md-2">Answer</th>
                                </tr>
                            </thead>
                            <tbody>
                            <?php
                            while ($row = $result->fetch_assoc()) {
                                echo "<tr>";
                                echo "<th scope='row'>" . $row['id'] . "</th>";
                                echo "<td>" . $row['question'] . "</td>";
                                echo "<td>" . $row['option1'] . "</td>";
                                echo "<td>" . $row['option2'] . "</td>";
                                echo "<td>" . $row['option3'] . "</td>";
                                echo "<td>" . $row['option4'] . "</td>";
                                echo "<td>" . $row['answer'] . "</td>";
                                echo "</tr>";
                            }
                            ?>
                            </tbody>
                        </table>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div>