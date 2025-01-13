<?php
include 'callback/mess_update.php';
?>

<section>
    

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
<div class="card col-md-6 m-auto">
        <div class="card-header">

            <h1 class="m-auto text-center fs-lg">Mess Meals Update</h1>
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
                <label for="item1">Item you want to replace</label>
                <select class="form-select mb-3" name="item_old" id="item1">
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
                <label for="item2">Item You want to add</label>
                <select class="form-select mb-3" name="item_update" id="item2">
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
    <div class="col-md-8 m-auto">
        <table class="table table-bordered">
            <tr>
                <th class="text-center" colspan="3"><h3>Current Menu</h3></th>
            </tr>
            <tr>
                <th>Date</th>
                <th>Meal</th>
                <th>Item</th>
            </tr>
            <?php
                $query = "SELECT * FROM `menu` where `date` >= '$date'";
                $read = $db->select($query);
                if($read){
                    while($row = $read->fetch_assoc()){
            ?>
            <tr>
                <td><?php echo date('Y-m-d', strtotime($row['date'])); ?></td>
                <td><?php $mealView = $row['meal_id']; 
                    if($mealView == 1){
                        echo "Breakfast";
                    }elseif($mealView == 2){
                        echo "Lunch";
                    }elseif($mealView == 3){
                        echo "Snacks";
                    }elseif($mealView == 4){
                        echo "Dinner";
                    }
                ?></td>
                <td><?php $itemName = $row['item_id'];  $name = "SELECT `name` from `items` where `id` = '$itemName'" ; $item = $db->select($name); while ($itemRow = $item->fetch_assoc()) {echo $itemRow['name'];} ?></td>
            </tr>
            <?php
                    }
                }
            ?>
        </table>
    </div>
</section>

<?php
include 'includes/footer.php';
?>