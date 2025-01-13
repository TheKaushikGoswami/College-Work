<?php

include '../includes/header.php';
include 'config/config.php';

if (!isset($_SESSION['admin'])) {
    header('location: ../login.php');
}

?>

<style>
    .card-body{
        text-align: justify;
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
    <div class="row justify-content-center">
        <div class="col-md-8">
            <div class="card my-5 p-3" style="border-radius:30px">
                <!-- <div class="card-header"> -->
                    <h1 class="m-auto my-2">Quiz Management System</h1>
                <!-- </div> -->
                <div class="card-body">
                    <p>Welcome to our cutting-edge Quiz Management System, where innovation meets education! Designed to provide an enriching and dynamic assessment experience, our platform stands out with its unique feature: the intelligent shuffling of questions and options.</p>
                    <hr class="mx-3">
                    <h4 class="mt-3">Key Features:</h4>
                    <ul>
                        <li><strong>Dynamic Question Shuffling for Varied Assessments:</strong> At the heart of our system lies the capability to create a truly diverse and engaging quiz experience. No longer will users encounter the predictability of fixed question sequences. Our platform dynamically shuffles the order of questions, ensuring that each attempt feels like a fresh challenge. This not only keeps users on their toes but also encourages deeper comprehension as they navigate through a varied set of topics.</li>

                        <li><strong>Option Randomization Enhances Critical Thinking:</strong> To elevate the quiz-taking experience, we take randomization a step further by shuffling the options for each question. By doing so, our system ensures that the correct answer isn't consistently placed in a particular position. This thoughtful design promotes genuine critical thinking and understanding, as users must carefully consider and evaluate all options, leading to a more comprehensive grasp of the material.</li>

                        <li><strong>Empowering Admins for Creative Assessments:</strong> Our system places the power of creativity in the hands of administrators. With an intuitive interface, admins can effortlessly create quizzes by inputting questions, options, and correct answers. The system takes care of the intricate details of shuffling, allowing educators and trainers to focus on crafting meaningful content that resonates with their audience.</li>

                        <li><strong>Secure Assessments, Mitigating the Risk of Cheating:</strong> In the ever-evolving landscape of online assessments, security is paramount. By randomizing both questions and options, our system goes above and beyond to mitigate the risk of cheating and answer sharing among users. This not only maintains the integrity of assessments but also cultivates an environment of trust and fairness.
                        </li>

                        <li><strong>Efficient Record-Keeping and Performance Analytics:</strong> Seamlessly record user responses and quiz results for a comprehensive view of performance analytics. Administrators can easily track individual progress, identify areas of strength and weakness, and make informed decisions for further educational strategies.</li>
                    </ul>
                    <hr class="mx-3">
                    <p>Whether you're an educator seeking a reliable and innovative assessment tool or an organization dedicated to employee training, our Quiz Management System with Dynamic Shuffling promises a holistic, fair, and engaging experience for all users. Experience the transformative power of assessment with our state-of-the-art platform and unlock new possibilities in the realm of online quizzes!</p>
                    <hr class="mx-3">
                </div>
                <div class="d-flex justify-content-end">
                    <h4>Made with <span class="text-danger">&hearts;</span> in Bharat by Kaushik Goswami & Humanshu Jaglan</h4>
                </div>
            </div>
        </div>
    </div>
</div>

<?php
include '../includes/footer.php';
?>