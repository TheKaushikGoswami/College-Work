<?php

include 'admin/config/config.php';
include 'includes/header.php';

if (isset($_SESSION['admin'])) {
    header('location: admin/index.php');
} else if (isset($_SESSION['user'])) {
    header('location: index.php');
}

?>
<div style="height:10vh">
<img src="qms.png" alt="" style="height:150px">
</div>

<div class="container-fluid" style="height:90vh;display:flex;align-items:center">
    <div class="come-out card col-md-3 m-auto bg-light text-dark" style="border-radius:30px">
        <h1 class="text-center my-4">Login here</h1>
        <div class="card-body mb-4">
            <form action="admin/handlers/login_handler.php" method="post">
                <input type="email" name="email" placeholder="Enter Your Email" class="form-control col-md-8 mb-3" style="width:80%;margin:auto">
                <input type="password" name="password" placeholder="Enter Your Password" class="form-control col-md-8 mb-3" style="width:80%;margin:auto">
                <div class="d-flex justify-content-center flex-column">
                    <span class="badge text-dark m-auto">Don't have an Account? <a href="register.php">Sign up</a> here</span><br>
                    <button class="btn btn-outline-success col-md-3 m-auto" name="submit" type="submit">Sign In</button>
                </div>
            </form>
        </div>
    </div>
</div>

<?php include 'includes/footer.php'; ?>