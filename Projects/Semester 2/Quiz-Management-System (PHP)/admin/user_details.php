<?php

include 'config/config.php';
include '../includes/header.php';

?>

<style>
    @media screen and (max-width: 640px) {
        table{
            font-size: 5px;
        }
        .check-result {
            width: 100% !important;
        }
    }
    input[type=number]::-webkit-inner-spin-button {
  -webkit-appearance: none;
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
                        <a class="nav-link active" aria-current="page" href="index.php">Home</a>
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
</div>

<div class="container-fluid" style="height:90vh;display:flex;align-items:center;justify-content:center">
    <div class="card m-auto col-md-8 col-sm-12 come-out p-3 check-result" style="border-radius:30px">
        <h1 Search class="text-center my-4">Student Progress</h1>
        <div class="card-body">
            <form action="user_details.php" method="POST">
                <input type="number" name="roll_no" placeholder="Enter User's Roll Number" class="form-control mb-2" style="width:80%;margin:auto">
            </form>
        </div>
        <div id="userDetails" class="mb-5">
            
        </div>
        <button id="generate-pdf" class="btn btn-outline-dark col-md-2 m-auto">
            Generate PDF
        </button>
    </div>
</div>
<script>
document.addEventListener("DOMContentLoaded", function() {
    document.getElementById('generate-pdf').addEventListener('click', function () {
        var element = document.createElement('div');
        element.innerHTML = "<div style='display:flex;justify-content:center'><img src='../qms.png' style='width:400px;margin:auto' /></div>";
        element.innerHTML += "<h2 style='text-align:center' class='mb-5'>STUDENT PROGRESS</h2>";
        element.innerHTML += document.getElementById('userDetails').innerHTML;
        element.innerHTML += "<p class='mx-5' style='text-align:right;margin-top:30px'>Generated on: " + new Date().toDateString() + "</p>";

        html2pdf().from(element).save();
    });
});
</script>
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>

<script>
$(document).ready(function() {
    $("input[name='roll_no']").on('input', function() {
        var roll_no = $(this).val();
        if(roll_no.length > 0) {
            $.ajax({
                url: 'fetch_data.php', 
                type: 'POST',
                dataType: 'json',
                data: {roll_no: roll_no},
                success: function(data) {
                    if(!data.error) {
                        var tableHtml = '<table class="table text-light col-md-11">' +
                                        '<thead>' +
                                        '<tr>' +
                                        '<th scope="col" class"col-md-4">Roll No</th>' +
                                        '<th scope="col" class"col-md-4">Student Name</th>' +
                                        '<th scope="col" class"col-md-4">Course</th>' +
                                        '<th scope="col" class"col-md-4">Quiz</th>' +
                                        '<th scope="col" class"col-md-4">Date</th>' +
                                        '<th scope="col" class"col-md-4">Percentage</th>' +
                                        '<th scope="col" class"col-md-4">Correct/Total</th>' +
                                        '</tr>' +
                                        '</thead>' +
                                        '<tbody>';
                        data.forEach(function(item) {
                            tableHtml += '<tr>' +
                                         '<td>' + item[0] + '</td>' + 
                                         '<td>' + item[1].toUpperCase() + '</td>' + 
                                         '<td>' + item[2].toUpperCase() + '</td>' + 
                                         '<td>' + item[3].replaceAll('_',' ') + '</td>' + 
                                         '<td>' + item[4] + '</td>' + 
                                         '<td>' + item[5] + '%</td>' + 
                                         '<td>' + item[6] + 
                                            '/' + item[7] + '</td>' + 
                                         '</tr>';
                        });
                        tableHtml += '</tbody></table>';
                        $('#userDetails').html(tableHtml);
                    } else {
                        $('#userDetails').html('<h3 class="text-center my-4">' + data.error + '</h3>');
                    }
                },
                error: function(xhr, status, error) {
                    $('#userDetails').html('<h3 class="text-center my-4">No students found with this roll number</h3>');
                }
            });
        } else {
            $('#userDetails').empty();
        }
    });
});
</script>


<?php include '../includes/footer.php'; ?>
