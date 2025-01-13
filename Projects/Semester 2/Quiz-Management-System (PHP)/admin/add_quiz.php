<?php
    
include '../includes/header.php';
include 'config/config.php';

if (!isset($_SESSION['admin'])) {
    header('location: ../login.php');
}

?>
<style>
  input[type="number"]::-webkit-inner-spin-button {
    -webkit-appearance: none;
  }
  @media screen and (max-width:768px){
      .submit-button{
          width:100%;
      }
  }
</style>
<div class="container-fluid p-0">
  <nav class="navbar navbar-expand-md bg-light m-0">
    <div class="container-fluid">
      <a class="navbar-brand" href="./index.php">Quiz Manager</a>
      <button
        class="navbar-toggler"
        type="button"
        data-bs-toggle="collapse"
        data-bs-target="#navbarSupportedContent"
        aria-controls="navbarSupportedContent"
        aria-expanded="false"
        aria-label="Toggle navigation"
      >
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
            <a
              class="nav-link dropdown-toggle"
              href="#"
              role="button"
              data-bs-toggle="dropdown"
              aria-expanded="false"
            >
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
  <div class="container-fluid">
    <div class="card col-md-5 m-auto mt-3 p-3" style="border-radius:30px">
        <h1 class="text-center my-2">Add New Quiz</h1>
      <div class="card-body">
        <form class="" action="quiz.php" method="post">
          <div class="input-group">
            <input
              type="number"
              class="form-control"
              name="num_subjects"
              id="num_subjects"
              placeholder="Enter Number of Subjects"
            /><button
              class="btn btn-outline-success"
              min="1"
              onclick="event.preventDefault();generateSubjects()"
            >
              <svg
                xmlns="http://www.w3.org/2000/svg"
                width="16"
                height="16"
                fill="currentColor"
                class="bi bi-plus-circle-fill"
                viewBox="0 0 16 16"
              >
                <path
                  d="M16 8A8 8 0 1 1 0 8a8 8 0 0 1 16 0M8.5 4.5a.5.5 0 0 0-1 0v3h-3a.5.5 0 0 0 0 1h3v3a.5.5 0 0 0 1 0v-3h3a.5.5 0 0 0 0-1h-3z"
                />
              </svg>
            </button>
          </div>
          <hr />
          <div id="subjects-div"></div>
          <hr />
          <label for="">
            <h5>Quiz details:</h5>
          </label>
          <input
            type="text"
            class="form-control mb-3"
            name="quiz_name"
            id="quiz_name"
            placeholder="Enter Quiz Name"
          />
          <textarea
            class="form-control mb-3"
            name="quiz_rules"
            id="quiz_rules"
            placeholder="Enter Quiz Rules"
            rows="3"
          ></textarea>
          <input
            type="number"
            class="form-control mb-3"
            name="quiz_time"
            id="quiz_time"
            placeholder="Enter Quiz Time in Minutes"
          />
          <hr />
          <label for="">
            <h5>Quiz starts at:</h5>
          </label>
          <input
            type="datetime-local"
            class="form-control mb-3"
            name="quiz_start"
            id="quiz_start"
            placeholder="Enter Quiz Start Time"
          />
          <hr />
          <label for="">
            <h5>Allot Quiz to:</h5>
          </label>

          <div id="allocated-users-div"></div>
          <div class="d-flex justify-content-end">
            <button
              class="btn btn-outline-dark"
              onclick="event.preventDefault();checkAll()"
            >
              All
            </button>
          </div>
          <div id="users-div"></div>
          <input type='hidden' name='allocated_to' />
          <div class="d-flex justify-content-end mb-3">
          <button id="allot-quiz" onclick="event.preventDefault()" class="btn btn-danger">Allot</button>
            </div>

            
          
            <button
              class="btn btn-success col-md-12 submit-button"
              type="submit"
              name="submit"
            > 
              Add Quiz
            </button>
          
        </form>
      </div>
    </div>
  </div>
  <script>
        var selected = '';
      document.getElementById('allot-quiz').addEventListener('click', function(e){
          e.preventDefault();
          var allotment = document.getElementsByClassName('allotment');
          
          for(var i =0; i<allotment.length; i++){
              if(allotment[i].checked){
                  selected += allotment[i].value + ',';
                  document.getElementById('allocated-users-div').innerHtml += `
                    <div class="rounded-pill">${allotment[i].value}</div>
                  `
              }
          }
          document.getElementsByName('allocated_to')[0].value = selected;

          alert('Users Allotted');
      });
  </script>

  <script src="https://ajax.googleapis.com/ajax/libs/jquery/3.5.1/jquery.min.js"></script>
  <script>
    $(document).ready(function () {
      // Function to fetch and display users
      function fetchUsers() {
        let course = $('#allot_course').val();
        let year = $('#allot_year').val();

        $.ajax({
          url: 'fetch_users.php', // Adjust the path if your PHP file is in a different directory.
          type: 'POST',
          data: {
            course: course,
            year: year
          },
          success: function (response) {
            $('#users-div').html(response);
          }
        });
      }

      // Trigger fetchUsers function whenever the selects change
      $('#allot_course, #allot_year').change(fetchUsers);

      // Optionally, call fetchUsers on page load if you want to display some default data
      fetchUsers();
    });

    let subjectsDiv = document.getElementById('subjects-div');
    if (subjectsDiv.innerHTML == '') {
      subjectsDiv.innerHTML = "<h5 class='text-center'><span class='badge rounded-pill bg-success'>First enter number of subjects above</span></h5>";
    }
    function generateSubjects() {

      let subjectsDiv = document.getElementById('subjects-div');
      let numSubjects = document.getElementById('num_subjects');
      let num = 0;

      num = numSubjects.value;
      subjectsDiv.innerHTML = '';
      for (let i = 0; i < num; i++) {
        let subjectDiv = document.createElement('div');
        subjectDiv.classList.add('mb-3');
        subjectDiv.innerHTML = `
                <div class="input-group">
                <select class="form-control col-md-6" name="subject${i + 1}" id="">
                   <?php
                   $sql = "SELECT * FROM `question_pools`";
                    $result = $conn->query($sql);
                    while ($row = $result->fetch_assoc()) {
                        echo '<option value="' . $row["name"] . '">' . str_replace('_', ' ', $row["name"]) . '</option>';
                    }
                   ?>
                </select>
                <input type="number" class="form-control col-md-6" name="num_questions${i + 1}" id="num_questions" placeholder="Enter Number of Questions">
                </div>

            `;
        subjectsDiv.appendChild(subjectDiv);
      }
    }

    function checkAll() {
      let checkboxes = document.querySelectorAll('input[type="checkbox"]');
      checkboxes.forEach(checkbox => {
        if (checkbox.checked == false) {
          checkbox.checked = true;
        } else {
          checkbox.checked = false;
        }
      });
    }
  </script>
</div>

<?php
include '../includes/footer.php';
?>
