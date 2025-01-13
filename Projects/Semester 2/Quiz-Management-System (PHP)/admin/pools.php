<?php

include '../includes/header.php';
include 'config/config.php';

if (!isset($_SESSION['admin'])) {
    header('location: ../login.php');
}

$sql = "SELECT * FROM `question_pools`";

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
                        <a class="nav-link" href="index.php">Home</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="pools.php">Question Pools</a>
                    </li>
                    <li class="nav-item">
                        <a class="nav-link" href="user_details.php">Result by Roll</a>
                    </li>
                    <li class="nav-item dropdown">
                        <button class="nav-link dropdown-toggle" role="button" data-bs-toggle="dropdown"
                            aria-expanded="false"  aria-current="page">
                            Admin Action
                        </button>
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
                <div class="d-flex" role="search"><!-- Button trigger modal -->
                    <button type="button" class="btn btn-outline-success mx-2" data-bs-toggle="modal" data-bs-target="#exampleModal">
                    Upload Questions
                    </button>

                    <!-- Modal -->
                    <div class="modal modal-lg fade" id="exampleModal" tabindex="-1" aria-labelledby="exampleModalLabel" aria-hidden="true">
                    <div class="modal-dialog modal-dialog-centered">
                        <div class="modal-content  p-5 " style="border-radius:30px">
                            <form action="upload_questions.php" method="post" enctype="multipart/form-data">
                                    <h1 class="modal-title fs-5" id="exampleModalLabel">Upload Questions to Pool</h1>
                                <div class="modal-body">
                                    <label for="">Question Pool</label>
                                        <select name="question_pool"id="filtered_pools" class="form-select mb-3" id="" class="form-control">
                                            <?php
                                            $sql = "SELECT * FROM `question_pools`";
                                            $result = $conn->query($sql);

                                            if($result->num_rows >0){
                                                while($row=$result->fetch_assoc()){
                                                    echo '<option value="'. $row['name'] . '"> '. str_replace('_', ' ', $row['name']) . ' </option>"';
                                                }
                                            }
           
                                            ?>
                                          
                                        </select>
                                    <label for="">Upload File</label>
                                    <input type="file" name="file" class="form-control mb-3" id="" placeholder="Upload CSV File" accept=".csv">
                                </div>
                                
                                <div class="modal-footer">
                                    <button type="button" class="btn btn-outline-dark" data-bs-dismiss="modal">Close</button>
                                    <button class="btn btn-outline-success" type="submit" name="submit">Upload</button> 
                                </div>
                            </form>
                        </div>
                    </div>
                    </div>
                    <form class="d-flex" method="post" role="search">
                    <button class="btn btn-outline-danger mx-2" type="submit" name="logout">Logout</button>
                </form>
                </div>
            </div>
        </div>
    </nav>
    <div class="container-fluid mt-3">
        <div class="row m-auto d-flex justify-content-center">
            <?php
            if ($result->num_rows > 0) {
                foreach ($result as $row) {
                    // now write the code to get number of questions in the pool
                    $pool_name = $row['name'];
                    $pool_name = strtolower($pool_name);
                    $sql = "SELECT * FROM `$pool_name`";
                    $result2 = $conn->query($sql);
                    $num_questions = $result2->num_rows;


            ?>
                    <div class="card m-3" style="width: 20rem;border-radius:25px">
                        <span class="badge rounded-pill bg-primary" style="position: absolute;right: -11px;top: -7px;"><?php echo $num_questions ?></span>
                        <div class="card-body">
                            <h4 class="card-title mb-3"><?php echo str_replace('_', ' ', $row["name"]); ?></h4>
                            <p class="card-text">
                                <?php echo $row["description"]; ?><br>
                                <!-- <b>Course: </b><?php //echo $row['course'];?><br> -->
                                <!-- <b>Year: </b><?php //echo $row['year'];?> -->
                            </p>
                            <div class="buttons d-flex justify-content-between">
                                <a href="pool_details.php?pool_id=<?php echo $row['id'] ?>" class="btn btn-outline-dark">View Details</a>
                                <a href="#" class="btn btn-outline-danger" onclick="deletePool('<?php echo str_replace('_', ' ', $row["name"]); ?>')">Delete Pool</a>
                            </div>
                        </div>
                    </div>
            <?php
                }
            }
            ?>
        </div>
    </div>
 
</div>

<script src="https://cdn.jsdelivr.net/npm/sweetalert2@10"></script>

<script>
    function deletePool(poolName) {
        var r = Swal.fire({
            title: 'Are you sure?',
            text: "You want to delete " + poolName + " pool",
            icon: 'warning',
            showCancelButton: true,
            confirmButtonColor: '#d33',
            cancelButtonColor: '#3085d6',
            confirmButtonText: 'Yes, delete it!'
        }).then((result) => {
            if (result.isConfirmed) {
                window.location.href = "delete_pool.php?pool=" + poolName;
            }
        });
      
    }
</script>

<?php
include '../includes/footer.php';
?>