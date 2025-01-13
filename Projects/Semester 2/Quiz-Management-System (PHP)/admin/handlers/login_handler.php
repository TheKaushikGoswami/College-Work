<?php

include '../config/config.php';
include '../../includes/header.php';

if (isset($_POST['submit'])) {
    $email = $conn->real_escape_string($_POST['email']);
    $password = $conn->real_escape_string($_POST['password']);
    
    $sql = "SELECT * FROM users WHERE email = '$email' AND password = '$password'";
    $result = $conn->query($sql);
    
    if ($result->num_rows == 1) { // Assuming one user per email, no need to loop.
        $row = $result->fetch_assoc();
        if ($row['status'] == 0) {
            // echo "<script>alert('Email not verified!'); window.location.href='../../login.php';</script>";
            echo "<script src='https://cdn.jsdelivr.net/npm/sweetalert2@11'></script>
            <script>
                Swal.fire({
                    title: 'Email not verified!',
                    icon: 'error',
                    showConfirmButton: false,
                    timer: 1500
                });
                setTimeout(() => {
                    window.location.href = '../../login.php';
                }, 1500);
            </script>
            ";
        } else {
            $_SESSION[$row['admin'] ? 'admin' : 'user'] = $row['roll_no'];
            $redirectPath = $row['admin'] ? '../../admin/index.php' : '../../index.php';
            // echo "<script>alert('Logged in successfully!'); window.location.href='$redirectPath';</script>";
            echo "
            <script src='https://cdn.jsdelivr.net/npm/sweetalert2@11'></script>
            <script>
                Swal.fire({
                    title: 'Logged in successfully!',
                    icon: 'success',
                    showConfirmButton: false,
                    timer: 1500
                });
                setTimeout(() => {
                    window.location.href = '$redirectPath';
                }, 1500);
                
            </script>
                ";
        }
    } else {
        // echo "<script>alert('Invalid email or password!'); window.location.href='../../login.php';</script>";
        echo "
        <script src='https://cdn.jsdelivr.net/npm/sweetalert2@11'></script>
        <script>
            Swal.fire({
                title: 'Invalid email or password!',
                icon: 'error',
                showConfirmButton: false,
                timer: 1500
            });
            setTimeout(() => {
                window.location.href = '../../login.php';
            }, 1500);
        </script>
        ";
    }
}

include '../../includes/footer.php';

?>
