<?php

include '../includes/header.php';
include 'config/config.php';

if (!isset($_SESSION['admin'])) {
    header('location: ../login.php');
    exit();
}

if (isset($_POST['submit'])) {
    $name = str_replace(' ', '_', $_POST['name']);
    $name = strtolower($name);
    $description = $_POST['description'];

    $sql = "CREATE TABLE `$name` (
        `id` int(11) NOT NULL AUTO_INCREMENT,
        `question` varchar(255) NOT NULL,
        `option1` varchar(255) NOT NULL,
        `option2` varchar(255) NOT NULL,
        `option3` varchar(255) NOT NULL,
        `option4` varchar(255) NOT NULL,
        `answer` varchar(255) NOT NULL,
        PRIMARY KEY (`id`)
      ) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4;";

    $sql2 = "INSERT INTO `question_pools` (`name`, `description`) VALUES ('$name', '$description')";

    if ($conn->query($sql) === TRUE) { $conn->query($sql2); 
        
    echo '
    <script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
<script>
    Swal.fire({
        title: "Question Pool Added Successfully!",
        icon: "success",
        showConfirmButton: false,
        timer: 1500
    })
    setTimeout(() => {
        window.location.href = "pools.php";
    }, 1500);
</script>
'; } else { echo '
<script src="https://cdn.jsdelivr.net/npm/sweetalert2@11"></script>
<script>
    
    Swal.fire({
        title: "Error!",
        text: "Error: ' . $sql . '<br>' . $conn->error . '",
        icon: "error",
        showConfirmButton: false,
        timer: 1500
    })
    setTimeout(() => {
        window.location.href = "add_pool.php";
    }, 1500);
</script>
'; } } ?>

<style>
    input::placeholder,
    textarea::placeholder {
        color: grey !important;
    }
</style>
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
                    <button class="btn btn-outline-danger" type="submit" name="logout">
                        Logout
                    </button>
                </form>
            </div>
        </div>
    </nav>
    <div class="container">
        <div class="card col-md-8 p-3 m-auto mt-3" style="border-radius:30px">
                <h1 class="my-2 text-center">Add New Question Pool</h1>
            <div class="card-body">
                <form class="" action="" method="post">
                    <label for="name">Subject</label>
                    <input type="text" class="form-control mb-3" name="name" id="name"
                        placeholder="Enter Subject Name" />
                    <label for="name">Description</label>
                    <textarea class="form-control mb-3" name="description" id="description" cols="30"
                        rows="10" placeholder="Enter Description"></textarea>
                    <div class="d-flex justify-content-end">
                        <button class="btn btn-outline-dark col-md-1" type="submit" name="submit">
                            Add
                        </button>
                    </div>
                </form>
            </div>
        </div>
    </div>
</div>

<?php include '../includes/footer.php'; ?>