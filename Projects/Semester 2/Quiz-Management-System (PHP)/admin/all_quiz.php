<?php

include '../includes/header.php';
include 'config/config.php';

if (!isset($_SESSION['admin'])) {
    header('location: ../login.php');
}

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
                        <ul class="dropdown-menu bg-light" style="border-radius:25px;padding:20px;overflow:hidden">
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
    <div class="container-fluid p-0">
        <div class="row d-flex justify-content-center">
            <?php
            $sql = "SELECT * FROM `quiz`";
            $result = $conn->query($sql);

            if ($result->num_rows > 0) {
                while ($row = $result->fetch_assoc()) {
            ?>
                        <div class="card m-3" style="width:20rem;border-radius:30px">
                                <h2 class="text-center mt-3"><?php echo str_replace('_',' ', $row['name']) ?></h2>
                            <div class="card-body">
                                <!--<p><?php echo $row['rules'] ?></p>-->
                                <!-- <p><?php echo $row['time'] ?></p> -->
                                <a href="quiz_details.php?quiz_id=<?php echo $row['id'] ?>" class="btn btn-outline-dark">View Details</a>
                                <a href="quiz_edit.php?quiz_id=<?php echo $row['id'] ?>" class="btn btn-outline-danger">Edit Quiz</a>
                            </div>
                        </div>
            <?php
                }
            }
               ?> 
        </div>
    </div>
   
</div>

<?php
include '../includes/footer.php';
?>