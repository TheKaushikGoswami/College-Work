<?php
include 'Database.php';
include 'config.php';
?>
<!DOCTYPE html>
<html lang="en">

<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Judges Panel - Interschool</title>
    <!-- font awesome  -->
    <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/font-awesome/6.6.0/css/all.min.css" integrity="sha512-Kc323vGBEqzTmouAECnVceyQqyqdsSiqLQISBL29aUW4U/M7pSPA/gEUZQqv1cwx4OnYxTxve5UMg5GT6L4JJg==" crossorigin="anonymous" referrerpolicy="no-referrer" />
    <!-- aos -->
    <link href="https://unpkg.com/aos@2.3.1/dist/aos.css" rel="stylesheet">
</head>
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
        display: flex;
        align-items: center;
        justify-content: center;
        flex-direction: column;
        height: 100vh;
    }

    .container {
        background-color: #fff;
        border-radius: 30px;
        box-shadow: 0 5px 15px rgba(0, 0, 0, 0.35);
        position: relative;
        overflow: hidden;
        width: 90%;
        max-width: 100%;
        min-height: 580px;
    }

    .container p {
        font-size: 14px;
        /* line-height: 20px; */
        letter-spacing: 0.3px;
        margin: 20px 0;
    }

    .container span {
        font-size: 12px;
    }

    .container a {
        color: #333;
        font-size: 13px;
        text-decoration: none;
        margin: 15px 0 10px;
    }



    .container button.hidden {
        background-color: transparent;
        border-color: #fff;
    }

    .container form {
        background-color: #fff;
        display: flex;
        align-items: left;
        justify-content: center;
        flex-direction: column;
        padding: 0 40px;
        height: 100%;
        line-height: 25px;
    }

    .container input {
        background-color: #eee;
        border: none;
        margin: 8px 0;
        padding: 10px 15px;
        font-size: 13px;
        border-radius: 8px;
        width: 100%;
        outline: none;
    }

    .form-container {
        position: absolute;
        top: 0;
        height: 100%;
        transition: all 0.6s ease-in-out;
        padding: 15px;


    }

    .sign-in {
        left: 0;
        width: 50%;
        z-index: 2;
    }

    .container.active .sign-in {
        transform: translateX(100%);
    }

    .sign-up {
        left: 0;
        width: 50%;
        opacity: 0;
        z-index: 1;

    }

    .container.active .sign-up {
        transform: translateX(100%);
        opacity: 1;
        z-index: 5;
        animation: move 0.6s;
    }

    @keyframes move {

        0%,
        49.99% {
            opacity: 0;
            z-index: 1;
        }

        50%,
        100% {
            opacity: 1;
            z-index: 5;
        }
    }

    .social-icons {
        margin: 20px 0px 0px 0px;
    }



    .toggle-container {
        position: absolute;
        top: 0;
        left: 50%;
        width: 50%;
        height: 100%;
        overflow: hidden;
        transition: all 0.6s ease-in-out;
        border-radius: 150px 0 0 100px;
        z-index: 1000;
    }

    .container.active .toggle-container {
        transform: translateX(-100%);
        border-radius: 0 150px 100px 0;
    }

    .toggle {
        background-color: #512da8;
        height: 100%;
        background: linear-gradient(to right, #FF6600, #FF6600);
        color: #fff;
        position: relative;
        left: -100%;
        height: 100%;
        width: 200%;
        transform: translateX(0);
        transition: all 0.6s ease-in-out;
    }

    .container.active .toggle {
        transform: translateX(50%);
    }

    .toggle-panel {
        position: absolute;
        width: 50%;
        height: 100%;
        display: flex;
        align-items: center;
        justify-content: center;
        flex-direction: column;
        padding: 0 30px;
        text-align: center;
        top: 0;
        transform: translateX(0);
        transition: all 0.6s ease-in-out;
    }

    .toggle-left {
        transform: translateX(-200%);
    }

    .container.active .toggle-left {
        transform: translateX(0);
    }

    .toggle-right {
        right: 0;
        transform: translateX(0);
    }

    .container.active .toggle-right {
        transform: translateX(200%);

    }

    .form-container p {
        font-size: 15px;
        text-align: justify;
        word-spacing: 1px;
    }

    .form-container span {
        font-size: 35px;
    }

    .toggle i {
        font-size: 30px;
        cursor: pointer;
        animation: moveAndScale 2.8s infinite ease-in-out;
    }

    @keyframes moveAndScale {
        0% {
            transform: translateX(0) scale(1);
        }

        50% {
            transform: translateX(10px) scale(1.1);
        }

        100% {
            transform: translateX(0) scale(1);
        }
    }

    .container a {
        background-color: #FF6600;
        color: red;
        border: 1px solid transparent;
        border-radius: 10px;
        font-weight: 600;
        letter-spacing: 0.5px;
        text-transform: uppercase;
        margin-top: 10px;
        cursor: pointer;
        padding: 10px 14px;
        width: 35%;
        text-align: left;
        color: white;
        font-size: 14px;
        letter-spacing: 2px;
        transition: 0.5s all ease;


    }


    .container a {
        color: #fff;
    }

    .container a:hover {
        background-color: #512da8;
        transition: 0.5s all ease;

    }

    .judges-panel {
        line-height: 30px;
        margin-bottom: 20px;
    }

    footer {
        text-align: center;
        bottom: 10px;
        position: absolute;
    }
</style>


<body>

    <div class="container" id="container" data-aos="fade-down"
        data-aos-duration="1000">
        <div class="form-container sign-up">
            <form>
                <h1 class="judges-panel"><span style="color: #FF6600;">JUDGES</span> <span style="color: darkblue;">PANEL</span></h1>
                <h3>Choose one!</h3>
                <a href="./singing.php" class="anim-button" id="singing">Singing</a>
                <a href="./declamation.php" class="anim-button" id="declamation">Declamation</a>
                <a href="./dancing.php" class="anim-button" id="dancing">Dancing</a>

            </form>
        </div>
        <div class="form-container sign-in">
            <form>
                <h1 data-aos="fade-up"
                    data-aos-duration="1100"><span style="color: #FF6600;">GEETA</span> <span style="color: darkblue;">UNIVERSITY</span></h1>
                <div class="social-icons">
                    <h3 data-aos="fade-up"
                        data-aos-duration="1200">The 16th Interschool Dance, Singing & Declamation</h3>
                </div>
                <p data-aos="fade-up"
                    data-aos-duration="1300">Competition celebrates the talent and creativity of young performers, showcasing their passion and dedication. It's a vibrant platform for students to shine, fostering teamwork, confidence, and artistic excellence.</p>

            </form>
        </div>
        <div class="toggle-container">
            <div class="toggle">
                <div class="toggle-panel toggle-left">
                    <h1>Welcome Back!</h1>
                    <p>You Want Go Back ?</p>
                    <i class="hidden fa-solid fa-circle-left" id="make-left"></i>

                </div>
                <div class="toggle-panel toggle-right">
                    <h1 data-aos="zoom-in"
                        data-aos-duration="1000">Hello, Dear!</h1>
                    <p data-aos="zoom-in"
                        data-aos-duration="1100">Now Move for Judges Panel</p>
                    <i class="hidden fa-solid fa-circle-right" id="make-right"></i>

                </div>
            </div>
        </div>
    </div>

    <footer>
        <h6>Made by Geeta Technical Hub</h6>
    </footer>

    <script src="https://unpkg.com/aos@2.3.1/dist/aos.js"></script>

    <script>
        AOS.init();


        const container = document.getElementById('container');
        const registerBtn = document.getElementById('make-right');
        const loginBtn = document.getElementById('make-left');

        registerBtn.addEventListener('click', () => {
            container.classList.add("active");
        });

        loginBtn.addEventListener('click', () => {
            container.classList.remove("active");
        });
    </script>
</body>

</html>