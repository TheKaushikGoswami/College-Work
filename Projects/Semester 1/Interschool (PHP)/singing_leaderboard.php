<?php
include 'Database.php';
include 'config.php';

$db = new Database();
$q2 = "SELECT singing_score.team_id, registration.school_name, SUM(singing_score.total) AS total 
       FROM singing_score 
       INNER JOIN registration ON singing_score.team_id = registration.team_id 
       GROUP BY singing_score.team_id 
       ORDER BY total DESC";
$s = $db->select($q2);
?>

<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Singing Leaderboard</title>
    <!-- font awesome  -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.6.0/css/all.min.css" integrity="sha512-Kc323vGBEqzTmouAECnVceyQqyqdsSiqLQISBL29aUW4U/M7pSPA/gEUZQqv1cwx4OnYxTxve5UMg5GT6L4JJg==" crossorigin="anonymous" referrerpolicy="no-referrer" />
    <!-- aos -->
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">

    <style>
        @import url('https://fonts.googleapis.com/css2?family=Montserrat:wght@300;400;500;600;700&display=swap');

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Montserrat', sans-serif;
        }

        body {
            background-color: #c9d6ff;
            background: linear-gradient(to right, #e2e2e2, #c9d6ff);

        }

        .container {
            margin: 20px auto;
            max-width: 1200px;
            padding: 20px;
            background-color: white;
            box-shadow: 0px 0px 15px rgba(0, 0, 0, 0.1);
            border-radius: 30px;
        }

        h1 {
            background-color: #FF6600;
            color: white;
            padding: 15px;
            text-align: center;
            border-radius: 10px;
            position: relative;
        }

        table {
            width: 100%;
            border-collapse: collapse;
            margin: 20px 0;

        }

        table,
        th,
        td {
            border: 1px solid #ddd;
        }

        th {
            background-color: #FF6600;
            color: white;
            padding: 12px;
        }

        td {
            padding: 10px;
            text-align: center;
        }

        @media only screen and (max-width: 768px) {

            th,
            td {
                padding: 8px;
                font-size: 10px;
            }
        }

        .footer {
            text-align: center;
            margin-top: 20px;
            font-weight: bold;
            color: #6c757d;
            font-size: 10px;
        }

        .fa-circle-arrow-left{
            position: absolute;
            align-items: center;
            left: 0;
            margin:5px 0px 0px 10px;
            cursor: pointer;
            color: white;

        }



    </style>
</head>

<body>

    <div data-aos="fade-down"
    data-aos-duration="1000" class="container">
        <h1 data-aos="fade-down"
        data-aos-duration="1100"> <a href="./leaderboard.php"><i class="fa-solid fa-circle-arrow-left"></i></a>Singing Leaderboard</h1>
        <table>
            <thead>
                <tr>
                    <th data-aos="fade-down"
                    data-aos-duration="1200">Team Id</th>
                    <th data-aos="fade-down"
                    data-aos-duration="1300">School Name</th>
                    <th data-aos="fade-down"
                    data-aos-duration="1400">Total Score</th>
                </tr>
            </thead>
            <tbody data-aos="fade-down"
            data-aos-duration="1500">
                <?php while ($row = $s->fetch_assoc()) { ?>
                    <tr>
                        <td>S<?php echo $row['team_id']; ?></td>
                        <td><?php echo $row['school_name']; ?></td>
                        <td><?php echo $row['total']; ?></td>
                    </tr>
                <?php } ?>
            </tbody>
        </table>

        <div class="footer">Made by Geeta Technical Hub</div>
    </div>
    <script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>
</body>

<script>
    AOS.init();
</script>    

</html>