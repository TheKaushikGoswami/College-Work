<?php
include 'Database.php';
include 'config.php';
?>
<?php
$db = new Database();
$query = "SELECT * FROM registration";
$read = $db->select($query);
$query1 = "SELECT * FROM judges where name like '%Singing'";
$read1 = $db->select($query1);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Singing Judge Panel</title>
    <link rel="shortcut icon" href="./assets/images/user.svg" type="image/x-icon">
    <!-- font awesome  -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.6.0/css/all.min.css" integrity="sha512-Kc323vGBEqzTmouAECnVceyQqyqdsSiqLQISBL29aUW4U/M7pSPA/gEUZQqv1cwx4OnYxTxve5UMg5GT6L4JJg==" crossorigin="anonymous" referrerpolicy="no-referrer" />
    <!-- aos -->
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <style>
        @import url('https://fonts.googleapis.com/css2?family=Montserrat:wght@300;400;500;600;700&display=swap');

        /* Base styling */
        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Montserrat', sans-serif;
        }

        body {
            background-color: #c9d6ff;
            background: linear-gradient(to right, #e2e2e2, #c9d6ff);
            display: flex;
            align-items: center;
            justify-content: center;
            flex-direction: column;
            height: auto;
        }

        .container {
            background-color: #fff;
            border-radius: 30px;
            box-shadow: 0 5px 15px rgba(0, 0, 0, 0.35);
            width: 80%;
            max-width: 100%;
            padding: 30px;
            text-align: center;
            margin: 40px 0px;
        }

        .line {
            width: 70%;
            margin: 20px auto;
            border: 1px solid #FF6600;
            border-radius: 5px;
        }

        header {
            line-height: 35px;
        }

        form {
            margin: 0 auto;
            justify-content: center;
            align-items: center;
            width: 70%;
            padding: 50px;
            border: 5px solid #FF6600;
            border-radius: 30px;
        }

        .section1-form {
            text-align: left;
            padding: 20px;
            text-transform: capitalize;
        }

        .section2-form {
            text-align: left;
            padding: 20px;
            display: flex;
            flex-direction: column;
        }

        .section2-form label,
        .section1-form h4,
        .section2-form h4 {
            padding: 10px 10px;
            border-radius: 5px;
            width: 100%;
            margin: 10px 0;
            background-color: #FF6600;
            color: white;
            text-transform: capitalize;
        }

        .section1-form select,
        .section2-form input {
            width: 100%;
            padding: 10px;
            margin: 10px 0;
            border: 2px solid #FF6600;
            border-radius: 5px;
            font-size: 16px;
            outline: none;
        }

        .section1-form option {
            color: white;
            background-color: #FF6600;
            padding: 10px 10px;
            border-radius: 5px;
            margin: 5px;
        }

        .section2-form p {
            color: lightgray;
            font-size: 15px;
        }

        input[type=submit] {
            background-color: #FF6600;
            color: white;
            padding: 10px 20px;
            border: none;
            border-radius: 5px;
            cursor: pointer;
            margin-top: 20px;
            width: 100%;
            font-weight: 800;
            transition: 0.5s;
        }

        input[type=submit]:hover {
            background-color: darkblue;
            transition: 0.5s;
        }

        footer h6 {
            margin-top: 10px;
            align-items: center;
        }
        .fa-circle-arrow-left{
            position: absolute;
            align-items: center;
            left: 0;
            margin:5px 0px 0px 10px;
            cursor: pointer;
            color: #FF6600;

        }

        /* Media Queries for Responsiveness */
        @media (max-width: 768px) {
            .container {
                width: 95%;
                padding: 20px;
            }

            form {
                padding: 30px;
                width: 98%;
            }

            header h1 {
                font-size: 1.5rem; /* Adjust header size */
            }

            header h4 {
                font-size: 1rem; /* Adjust subheader size */
            }

            .section1-form h4,
            .section2-form h4 {
                font-size: 1rem; /* Adjust section titles */
            }

            .section1-form select,
            .section2-form input {
                font-size: 14px; /* Adjust font size */
            }

            input[type=submit] {
                font-size: 16px; /* Adjust submit button font size */
            }
        }

        @media (max-width: 480px) {
            header h1 {
                font-size: 1.2rem; /* Further adjust header size for smaller devices */
            }

            header h4 {
                font-size: 0.9rem; /* Further adjust subheader size for smaller devices */
            }

            .section1-form h4,
            .section2-form h4 {
                font-size: 0.9rem; /* Further adjust section titles */
            }

            .section1-form select,
            .section2-form input {
                font-size: 12px; /* Further adjust font size */
            }

            input[type=submit] {
                font-size: 14px; /* Further adjust submit button font size */
            }
        }
    </style>
</head>

<body>

    <div class="container">
        <header>
            <h1 data-aos="fade-up" data-aos-duration="1000"><a href="./judges.php"><i class="fa-solid fa-circle-arrow-left"></i></a>
                <span style="color: #FF6600;">GEETA</span>
                <span style="color: darkblue;">UNIVERSITY</span>
            </h1>
            <h4 data-aos="fade-up" data-aos-duration="1100">16th InterSchool Group Dance, Singing and Declamation Competition</h4>
            <hr class="line">
        </header>

        <h3 data-aos="fade-down" data-aos-duration="1000" class="title" style="margin-bottom: 15px;">Singing Competition</h3>

        <form data-aos="zoom-out" data-aos-duration="1100" action="" method="post">
            <div class="section1-form">
                <h4>Select your Team Id</h4>
                <select name="team_id" id="team_id">
                    <?php if ($read) { ?>
                    <?php 
                        $i = 0;              
                        while ($row = $read->fetch_assoc()) { 
                        $i++;
                    ?>
                    <option value="<?php echo $row['team_id'] ?>">S<?php echo $row['team_id'] ?></option>
                    <?php } ?>
                    <?php } else { ?>
                    <p>Data is not Found!</p>
                    <?php } ?>
                </select>

                <h4 data-aos="fade-up" data-aos-duration="1000">Select your Judge Id</h4>
                <select name="judge_id" id="judge_id">
                    <?php if ($read1) { ?>
                    <?php 
                        $i = 0;              
                        while ($row1 = $read1->fetch_assoc()) { 
                        $i++;
                    ?>
                    <option data-aos="fade-up" data-aos-duration="1100" value="<?php echo $row1['name'] ?>"><?php echo $row1['name'] ?></option>
                    <?php } ?>
                    <?php } else { ?>
                    <p>Data is not Found!</p>
                    <?php } ?>
                </select>
            </div>

            <div class="section2-form">
                <h4>Enter the marks in given inputs</h4>
                <p class="text-danger">The value must be less than or equal to 20</p>

                <label for="song_choice">Song Choice</label>
                <input type="number" id="song_choice" name="song_choice" required max="20">

                <label for="vocal_quality">Vocal Quality</label>
                <input type="number" id="vocal_quality" name="vocal_quality" required max="20">

                <label for="coordination">Coordination</label>
                <input type="number" id="coordination" name="coordination" required max="20">

                <label for="rhythm_timing">Rhythm & Timing</label>
                <input type="number" id="rhythm_timing" name="rhythm_timing" required max="20">

                <label for="creativity">Creativity</label>
                <input type="number" id="creativity" name="creativity" required max="20">

                <input data-aos="zoom-in" data-aos-duration="1200" type="submit" name="singing_submit" value="Submit">
            </div>
        </form>

        <footer>
            <h6>Made by Geeta Technical Hub</h6>
        </footer>
    </div>

<script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
<script>
    AOS.init();
</script>

<?php
$db = new Database();
if(isset($_POST['singing_submit'])){
    $song_choice = mysqli_real_escape_string($db->link, $_POST['song_choice']);
    $vocal_quality = mysqli_real_escape_string($db->link, $_POST['vocal_quality']);
    $creativity = mysqli_real_escape_string($db->link, $_POST['creativity']);
    $rhythm_timing = mysqli_real_escape_string($db->link, $_POST['rhythm_timing']);
    $coordination = mysqli_real_escape_string($db->link, $_POST['coordination']);
    $team_id = mysqli_real_escape_string($db->link, $_POST['team_id']);
    $judge_id = mysqli_real_escape_string($db->link, $_POST['judge_id']);
    $total = (int)$song_choice + (int)$vocal_quality + (int)$creativity + (int)$rhythm_timing + (int)$coordination;
    
    $duplicate = "SELECT * FROM singing_score WHERE team_id = '$team_id' AND judge_id = '$judge_id'";
    $check = $db->select($duplicate);
    
    
    if($song_choice == "" || $vocal_quality == "" || $creativity == "" || $rhythm_timing == "" || $coordination == "" || $team_id == "" || $judge_id == ""){
        $error = "Field must not be Empty !!";
    } else {
        if($check){
            $error = "This team has already been scored by this judge."; ?>

    <?php if(isset($error)){ ?>
    <script>
        alert("<?php echo $error ?>");
        </script>
    <?php } ?>
    <?php
        } else {
            $query = "INSERT INTO singing_score(`team_id`, `judge_id`, `song_choice`, `vocal_quality`, `coordination`, `creativity`, `rhythm_timing`, `total`) 
        VALUES('$team_id', '$judge_id', '$song_choice', '$vocal_quality', '$coordination', '$creativity', '$rhythm_timing',  '$total')";
        $create = $db->insert($query);
        }
    }  
}
    
?>

</body>

</html>
