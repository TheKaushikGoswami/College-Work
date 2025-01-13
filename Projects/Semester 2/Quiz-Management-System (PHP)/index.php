<?php
ini_set("display_errors",1);
include 'includes/header.php';
include 'admin/config/config.php';

$user_roll = $_SESSION['user'];

if (isset($_POST['logout'])) {
    session_destroy();
    header('location: tech-quiz/login.php');
}

if (!isset($_SESSION['user'])) {
    header('location: login.php');
}

?>

<style>
    @media screen and (max-width: 640px) {
        .logo{
            height: 100px !important;;
        }
        .navbar{
            height: 100px !important;
        }

    }
</style>

<div class="container-fluid p-0">
    <nav class="navbar col-md-12 bg-light m-0 d-flex justify-content-betwen" style="height:150px">
        <img class="logo" src="qms.png" alt="" style="height:150px;">
        <form class="" method="post" role="search">
            <button class="btn btn-outline-danger mx-3" type="submit" name="logout">Logout</button>
        </form>
    </nav>
    <h1 class="text-center mb-4 py-3 bg-light" style="font-size:40px">Active Quizes</h1>
    <div class="row">
        <div class="col-md-12">
            <div class="row d-flex p-3 justify-content-center">
            <?php
            $sql = "SELECT * FROM `quiz` WHERE `allocated_to` LIKE CONCAT('%', ? , '%')";
            $stmt = $conn->prepare($sql);
            $stmt->bind_param("s", $user_roll);
            $stmt->execute();
            $result = $stmt->get_result();
            
            
            if ($result->num_rows > 0) {
                while ($row = $result->fetch_assoc()) {
                    // // check if the quiz is allocated to the user or not
                    // $allocated_to = explode(',', $row['allocated_to']);
                    // // if (!in_array($_SESSION['user'], $allocated_to)) {
                    // //     continue;
                    // // }
                    // echo $_SESSION['user'];

                    // // var_dump($allocated_to);
                    //
                    
                    ?>
                    <div class="card m-3 mb-2" style="width:20rem;border-radius:30px">
                            <h2 class="text-center my-2"><?php echo strtoupper(str_replace('_',' ',$row['name'])) ?></h2>
                        <div class="card-body">
                            <p class="card-text"><?php echo $row['rules'] ?></p>
                            <?php
                            $quiz_name = $row['name'];
                            $quiz_name = strtolower($quiz_name);
                            $sql2 = "SELECT * FROM `$quiz_name` WHERE `user_id` = '$user_roll'";
                            $result2 = $conn->query($sql2);
                            if ($result2->num_rows > 0) {
                                ?>
                                <a class="btn btn-outline-primary disabled">Start Quiz</a> <span class="badge bg-success">Completed</span>
                                <?php
                            }
                            else if ($row['start'] > date('Y-m-d H:i:s')) {
                                echo '<a class="btn btn-outline-primary disabled">Start Quiz</a> <span class="badge bg-warning rounded-pill">Not Started</span>';
                            }
                            else if(strtotime($row['start'] . ' + ' . $row['time'] . ' minutes') < strtotime(date('Y-m-d H:i:s'))) {
                                echo '<a class="btn btn-outline-primary disabled">Start Quiz</a> <span class="badge bg-danger rounded-pill">Time Over</span>';
                            }
                            else {
                                echo '<a href="quiz.php?quiz_id=' . $row['id'] . '" class="btn btn-outline-primary">Start Quiz</a>';
                            }
                            ?>
                            
                        </div>
                    </div>
                    <?php
                }
            }
            else{
                echo "<div class='alert alert-danger text-center'>No active quizes</div>";
            }
            ?>
            </div>
        </div>
    </div>
 
    <script>
  (function () {
    let devtoolsOpen = false;

    const detectDevTools = function () {
      if (window.outerWidth - window.innerWidth > 100 || window.outerHeight - window.innerHeight > 100) {
        if (!devtoolsOpen) {
          devtoolsOpen = true;
        //   turn off the developer console
            document.getElementById('quiz-submit-button').click();
          alert("Developer tools are not allowed!");
        }
      } else {
        devtoolsOpen = false;
      }
    };

    window.addEventListener('resize', detectDevTools);
    setInterval(detectDevTools, 1000);
  })();
</script>


</div>

<?php include 'includes/footer.php'; ?>