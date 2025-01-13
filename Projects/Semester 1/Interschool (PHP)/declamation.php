<?php
include 'Database.php';
include 'config.php';
?>

<?php
$db = new Database();
$query = "SELECT * FROM registration";
$read = $db->select($query);
$query1 = "SELECT * FROM judges where name like '%Declamation'";
$read1 = $db->select($query1);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Declamation Judge Panel</title>
    <!-- font awesome  -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.6.0/css/all.min.css" integrity="sha512-Kc323vGBEqzTmouAECnVceyQqyqdsSiqLQISBL29aUW4U/M7pSPA/gEUZQqv1cwx4OnYxTxve5UMg5GT6L4JJg==" crossorigin="anonymous" referrerpolicy="no-referrer" />
    <!-- aos -->
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
    <link rel="shortcut icon" href="./assets/images/user.svg" type="image/x-icon">
</head>

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

    /* Mobile responsiveness */
    @media (max-width: 768px) {
        body {
            padding: 10px;
        }

        .container {
            width: 100%;
            padding: 15px;
            margin: 20px 0;
        }

        form {
            width: 100%;
            padding: 10px;
        }

        .section1-form h4,
        .section2-form h4,
        .section2-form label {
            font-size: 14px;
            padding: 5px 10px;
        }

        .section1-form select,
        .section2-form input {
            padding: 8px;
            font-size: 14px;
        }

        input[type=submit] {
            padding: 8px 15px;
            font-size: 14px;
        }

        .title {
            font-size: 18px;
        }
      
    }
</style>

<body>
    <div class="container">
        <header>
            <h1 data-aos="fade-up" data-aos-duration="1000" ><a href="./judges.php"><i class="fa-solid fa-circle-arrow-left"></i></a><span style="color: #FF6600;">GEETA</span> <span style="color: darkblue;">UNIVERSITY</span></h1>
            <h4 data-aos="fade-up" data-aos-duration="1100">16th InterSchool Group Dance, Singing and Declamation Competition</h4>
            <hr class="line">
        </header>

        <h3  data-aos="fade-down" data-aos-duration="1000" class="title" style="margin-bottom: 15px;">Declamation Competition</h3>

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
                            <option value="<?php echo $row['team_id'] ?>">DC<?php echo $row['team_id'] ?></option>
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
                            <option value="<?php echo $row1['name'] ?>"><?php echo $row1['name'] ?></option>
                        <?php } ?>
                    <?php } else { ?>
                        <p>Data is not Found!</p>
                    <?php } ?>
                </select>
            </div>

            <div class="section2-form">
                <h4>Enter the marks in given inputs</h4>
                <p class="text-danger">The value must be less than or equal to 20</p>

                <label for="dictation_articulation">Dictation & Articulation</label>
                <input type="number" id="dictation_articulation" name="dictation_articulation" required max="20">

                <label for="expression_emotions">Expression & Emotions</label>
                <input type="number" id="expression_emotions" name="expression_emotions" required max="20">

                <label for="interpretation">Interpretation</label>
                <input type="number" id="interpretation" name="interpretation" required max="20">

                <label for="stage_presence">Stage Presence</label>
                <input type="number" id="stage_presence" name="stage_presence" required max="20">

                <label for="timing_pace">Timing & Pace</label>
                <input type="number" id="timing_pace" name="timing_pace" required max="20">

                <input data-aos="zoom-in" data-aos-duration="1000" type="submit" name="declamation_submit" value="Submit">
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
    if (isset($_POST['declamation_submit'])) {
        $dictation_articulation = mysqli_real_escape_string($db->link, $_POST['dictation_articulation']);
        $expression_emotions = mysqli_real_escape_string($db->link, $_POST['expression_emotions']);
        $interpretation = mysqli_real_escape_string($db->link, $_POST['interpretation']);
        $stage_presence = mysqli_real_escape_string($db->link, $_POST['stage_presence']);
        $timing_pace = mysqli_real_escape_string($db->link, $_POST['timing_pace']);
        $team_id = mysqli_real_escape_string($db->link, $_POST['team_id']);
        $judge_id = mysqli_real_escape_string($db->link, $_POST['judge_id']);
        $total = (int)$dictation_articulation + (int)$expression_emotions + (int)$interpretation + (int)$stage_presence + (int)$timing_pace;

        $duplicate = "SELECT * FROM declamation_score WHERE team_id = '$team_id' AND judge_id = '$judge_id'";
        $check = $db->select($duplicate);

        if ($dictation_articulation == "" || $expression_emotions == "" || $interpretation == "" || $stage_presence == "" || $timing_pace == "" || $team_id == "" || $judge_id == "") {
            $error = "Field must not be Empty !!";
        } else {
            if ($check) {
                $error = "This team has already been scored by this judge."; ?>

                <?php if (isset($error)) { ?>
                    <script>
                        alert("<?php echo $error ?>");
                    </script>
                <?php } ?>
            <?php
            } else {
                $query = "INSERT INTO declamation_score(`team_id`, `judge_id`, `dictation_articulation`, `expression_emotions`, `interpretation`, `stage_presence`, `timing_pace`, `total`) VALUES('$team_id', '$judge_id', '$dictation_articulation', '$expression_emotions', '$interpretation', '$stage_presence', '$timing_pace', '$total')";
                $create = $db->insert($query);

                if ($create) {
                    $msg = "You have successfully submitted the marks!";
                    echo "<script>alert('$msg');</script>";
                }
            }
        }
    }
    ?>
</body>

</html>
