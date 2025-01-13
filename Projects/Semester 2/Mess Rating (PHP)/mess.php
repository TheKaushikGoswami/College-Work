<?php
include "callback/mess.php";
include "includes/header.php";
?>
<nav class="navbar bg-success-subtle">
  <div class="container-fluid">
    <a class="navbar-brand" href="mess.php">Mess Master</a>
    
      <ul class="navbar-nav">
        
        <li class="nav-item">
        <form action="" method="post">
            <button class="nav-button btn btn-danger" name="logout" type="submit">Logout</button>
            <a href="mess_update.php" class="btn btn-success">Update</a>
            <a href="output.php" class='btn btn-warning'>Stats</a>
        </form>
        </li>
      </ul>
    </div>
</nav>

    <div class="col-md-4">
        
    </div>
    <div class="card col-md-6 mt-5 m-auto">
        <div class="card-header">

            <h1 class="m-auto text-center fs-lg">Mess Meals Entry</h1>
        </div>

        <div class="card-body ">
            <form action="" method="post" class="fs-5">
                <label for="date">Date</label>
                <input class="form-control mb-3" name="date" type="date">
                <label for="meal">Meal</label>
                <select class="form-select mb-3" name="meal" id="meal">
                    <?php
                        $query = "SELECT * FROM `meals`";
                        $read = $db->select($query);
                        if($read){
                            while($row = $read->fetch_assoc()){
                                echo "<option value='".$row['id']."'>".$row['name']."</option>";
                            }}
                    ?>
                </select>
                <label for="item1">Item 1</label>
                <select class="form-select mb-3" name="item1" id="item1">
                    <?php
                        $query = "SELECT * FROM `items`";
                        $read = $db->select($query);
                        if($read){
                            while($row = $read->fetch_assoc()){
                    ?>
                    <option value="<?php echo $row['id']; ?>"><?php echo $row['name']; ?></option>
                    <?php
                            }
                        }
                    ?>
                </select>
                <label for="item2">Item 2</label>
                <select class="form-select mb-3" name="item2" id="item2">
                    <?php
                        $query = "SELECT * FROM `items`";
                        $read = $db->select($query);
                        if($read){
                            while($row = $read->fetch_assoc()){
                    ?>
                    <option value="<?php echo $row['id']; ?>"><?php echo $row['name']; ?></option>
                    <?php
                            }
                        }
                    ?>
                </select>
                <label for="item3">Item 3</label>
                <select class="form-select mb-3" name="item3" id="item3">
                    <?php
                        $query = "SELECT * FROM `items`";
                        $read = $db->select($query);
                        if($read){
                            while($row = $read->fetch_assoc()){
                    ?>
                    <option value="<?php echo $row['id']; ?>"><?php echo $row['name']; ?></option>
                    <?php
                            }
                        }
                    ?>
                </select>
                <label for="item4">Item 4</label>
                <select class="form-select mb-3" name="item4" id="item4">
                    <?php
                        $query = "SELECT * FROM `items`";
                        $read = $db->select($query);
                        if($read){
                            while($row = $read->fetch_assoc()){
                    ?>
                    <option value="<?php echo $row['id']; ?>"><?php echo $row['name']; ?></option>
                    <?php
                            }
                        }
                    ?>
                </select>
                <label for="item5">Item 5</label>
                <select class="form-select mb-3" name="item5" id="item5">
                    <?php
                        $query = "SELECT * FROM `items`";
                        $read = $db->select($query);
                        if($read){
                            while($row = $read->fetch_assoc()){
                    ?>
                    <option value="<?php echo $row['id']; ?>"><?php echo $row['name']; ?></option>
                    <?php
                            }
                        }
                    ?>
                </select>
                <label for="item6">Item 6</label>
                <select class="form-select mb-3 mb-3" name="item6" id="item6">
                    <?php
                        $query = "SELECT * FROM `items`";
                        $read = $db->select($query);
                        if($read){
                            while($row = $read->fetch_assoc()){
                    ?>
                    <option value="<?php echo $row['id']; ?>"><?php echo $row['name']; ?></option>
                    <?php
                            }
                        }
                    ?>
                </select>
                <div class="d-grid mt-5">
                        <button class="btn btn-primary" name="submit" type="submit">Submit</button>
                    </div>
            </form>
        </div>
    </div>
<?php
include "includes/footer.php";
?>