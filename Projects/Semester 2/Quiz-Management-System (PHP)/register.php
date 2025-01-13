<?php

include 'admin/config/config.php';
include 'includes/header.php';

?>

<div style="height:10vh">
<img src="qms.png" alt="" style="height:150px">
</div>


<div class="container-fluid" style="height:90vh;display:flex;align-items:center;justify-content:center">
  <div class="card m-auto col-md-4 come-out" style="border-radius:30px">
    <form action="admin/handlers/register_handler.php" method="POST" >
        <h1 class="text-center my-4">Register</h1>
      <div class="card-body">
        <input type="text" name="name" placeholder="Enter Your name" class="form-control mb-2" style="width:80%;margin:auto">
        <input type="number" name="roll" placeholder="Enter Your Roll Number" class="form-control mb-2" style="width:80%;margin:auto">
        <input type="email" name="email" placeholder="Enter Your Email" class="form-control mb-2" style="width:80%;margin:auto">
        <select name="course" id="" class="form-select mb-2" style="width:80%;margin:auto">
          <option disabled>Select Your Course</option>
          <option value="B.Tech">B.Tech</option>
          <option value="M.Tech">M.Tech</option>
          <option value="B.Sc">B.Sc</option>
          <option value="B.A">B.A</option>
          <option value="BCA">BCA</option>
          <option value="MCA">MCA</option>
          <option value="MBA">MBA</option>
        </select>
        <select name="year" id="" class="form-select mb-2" style="width:80%;margin:auto">
          <option disabled>Select Your Year</option>
          <option value="1st">1st</option>
          <option value="2nd">2nd</option>
          <option value="3rd">3rd</option>
          <option value="4th">4th</option>
        </select>
        <input type="password" name="password" placeholder="Enter Your Password" class="form-control mb-2" style="width:80%;margin:auto">
        <input type="password" name="cnf_password" placeholder="Confirm Your Password" class="form-control mb-2" style="width:80%;margin:auto">
        <div class="d-flex justify-content-center flex-column">
          <span class="badge text-dark m-auto">Already have an Account? <a href="login.php">Login</a> here</span><br>
          <input type="submit" name="submit" value="Register" class="btn btn-outline-success col-md-3 m-auto"> 
        </div> 
      </div>    
    </form>
    </div>
</div>

<?php include 'includes/footer.php'; ?>