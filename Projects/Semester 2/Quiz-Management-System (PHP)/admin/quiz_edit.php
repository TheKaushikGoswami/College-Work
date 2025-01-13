<?php

include '../includes/header.php';
include 'config/config.php';

if (!isset($_SESSION['admin'])) {
    header('location: ../login.php');
}

$quiz_id = $_SERVER['QUERY_STRING'];
$quiz_id = substr($quiz_id, 8);

$sql = "SELECT * FROM `quiz` WHERE `id` = '$quiz_id'";
$result = $conn->query($sql);

while ($row = $result->fetch_assoc()) {
    $quiz_name = $row['name'];
    $quiz_table = str_replace(' ', '_', $quiz_name);
    $rules = $row['rules'];
    $time = $row['time'];
    $start = $row['start'];
    $allocated_to = $row['allocated_to'];

        $allocated_to = explode(',', $allocated_to);
        array_pop($allocated_to)
    
?>

<style>
    @media screen and (max-width: 640px) {
        table {
            font-size: 10px;
        }
    }
</style>

<div class="container-fluid p-0">
    <!-- Rest of the code -->
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
                        <a class="nav-link" href="index.php">Home</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="pools.php">Question Pools</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="user_details.php">Result by Roll</a>
                    </li>
                    <li class="nav-item dropdown">
                        <a class="nav-link dropdown-toggle" href="#" role="button" data-bs-toggle="dropdown"
                            aria-expanded="false">
                            Admin Action
                        </a>
                        <ul class="dropdown-menu bg-light" style="border-radius:25px;padding:20px">
                            <li><a class="dropdown-item" href="add_quiz.php">Create New Quiz</a></li>
                            
                            <li><a class="dropdown-item" href="all_quiz.php">All Quiz</a></li>
                            <li>
                                <hr class="dropdown-divider">
                            </li>
                            <li><a class="dropdown-item" href="add_pool.php">Add New Question Pool</a></li>
                        </ul>
                    </li>
                </ul>
                <form class="d-flex" method="post" role="search">
                    <button class="btn btn-outline-danger" type="submit" name="logout">Logout</button>
                </form>
            </div>
        </div>
    </nav>


    <div class="container mt-5">
        <div class="row">
            <div class="col-md-8 card p-5 m-auto" style="border-radius:30px">
                <h3 class="text-center">Edit Quiz</h3>
                <form method="post">
                    <div class="form-group">
                        <label for="quiz_name">Quiz Name</label>
                        <input type="text" class="form-control mb-3" id="quiz_name" name="quiz_name" value="<?php echo $quiz_name; ?>">  
                        <input type="hidden" id="quiz_id" name="quiz_id" value="<?php echo $quiz_id; ?>">
                        <label>Rules</label>
                        <input type="text" class="form-control mb-3"id="rules"name="rules"value="<?php echo $rules; ?>"placeholder="Rules">
                        <label>Time</label>
                        <input type="text" class="form-control mb-3"id="time"name="time"value="<?php echo $time; ?>"placeholder="Time">
                        <label>Starts at</label>
                        <input type="datetime-local" class="form-control mb-3"id="start"name="start"value="<?php echo $start; ?>">
                        <label>Allocated to:</label>
                        <table class="table col-md-5 m-auto">
                    <thead>
                        <tr>
                            <th scope="col">S.No</th>
                            <th scope="col">Roll No</th>
                            <th scope="col">Name</th>
                            <th scope="col">Course</th>
                            <th scope="col">Year</th>
                        </tr>
                    </thead>
                    <tbody>
                        <?php 
                        if($allocated_to != null){
                            $j = 1;
                            foreach ($allocated_to as $roll_no) {
                                $sql = "SELECT * FROM `users` WHERE `roll_no` = '$roll_no'";
                                $result = $conn->query($sql);
                                $i = 1;
                                $row = $result->fetch_assoc();
                            ?>
                                <tr>
                                    <th scope="row"><?php echo $j; ?></th>
                                    <td><?php echo $row['roll_no']; ?></td>
                                    <td><?php echo $row['name']; ?></td>
                                    <td><?php echo $row['course']; ?></td>
                                    <td><?php echo $row['year']; ?></td>
                                </tr>
                            <?php
                                $j++;
                            }
                        }
                        ?>

                    </tbody>
                    
                </table>
                
                <label>Add more students</label>
                <input type="text" class="form-control" name='new_students' />
                <small>write roll numbers separated by commas.</small>
                        

                    </div>
                    <button type="submit" name="update" class="btn btn-primary">Update</button>
                    <a href="all_quiz.php" class="btn btn-danger">Cancel</a>
                </form>
            </div>
        </div>
    </div>

    <?php
    if(isset($_POST['update'])){
        $quiz_id = $_POST['quiz_id'];
        $quiz_name = $_POST['quiz_name'];
        $rules = $_POST['rules'];
        $time = $_POST['time'];
        $start = $_POST['start'];
        $new_students = $_POST['new_students'];
        $sql = "UPDATE `quiz` SET `name` = '$quiz_name', `rules` = '$rules', `time` = '$time', `start` = '$start' WHERE `id` = '$quiz_id'";
        
        // Updating quiz details in
        if ($conn->query($sql) === TRUE) {
            // Updating quiz table name with quiz name
            $new_table = str_replace(' ', '_', $quiz_name);
            $sql = "ALTER TABLE `$quiz_table` RENAME TO `$new_table`";
            $conn->query($sql);

            if($new_students != null){
                $new_students = explode(',', $new_students);
                $sql = "SELECT * FROM `quiz` WHERE `id` = '$quiz_id'";
                $result = $conn->query($sql);
                $row = $result->fetch_assoc();
                $allocated_to = $row['allocated_to'];
                $allocated_to = explode(',', $allocated_to);
                $allocated_to = array_merge($allocated_to, $new_students);
                $allocated_to = implode(',', $allocated_to);
                $sql = "UPDATE `quiz` SET `allocated_to` = '$allocated_to' WHERE `id` = '$quiz_id'";
                if ($conn->query($sql) === TRUE) {
                    echo "<script>alert('Quiz details updated successfully');window.location = 'all_quiz.php'</script>";
                    
                } else {
                    echo "Error: " . $sql . "<br>" . $conn->error;
                }
            }
            else{
                echo "<script>alert('Quiz details updated successfully');window.location = 'all_quiz.php'</script>";
            }
        } else {
            echo "Error: " . $sql . "<br>" . $conn->error;
        }

        // Adding new students to the quiz

        

    }


?>

</div>

<?php } include '../includes/footer.php'; ?>