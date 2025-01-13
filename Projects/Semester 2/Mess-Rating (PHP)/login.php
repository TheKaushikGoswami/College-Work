<?php

include "callback/login.php";
include "includes/header.php";
?>

	<div class="d-flex align-items-center" style="height:100vh;">
		<div class="card col-md-6 m-auto">
			<div class="card-header">
				<h1 class="m-auto text-center h1">Mess Master Login</h1>
			</div>
			<div class="card-body">
				<form action="" method="post">
					<label for="email">Email</label>
					<input type="email" name="email" id="email" class="form-control mb-4" placeholder="Enter your email"
                    required>
					<label for="password">Password</label>
					<input type="password" name="password" id="password" class="form-control mb-5"
                    placeholder="Enter your password" required>
					<div class="d-grid">
						<button type="submit" name="login" class="btn btn-primary">Sign in</button>
					</div>
				</form>
			</div>
        </div>
    </div>
    
<?php
include "includes/footer.php";
?>