<?php
include 'callback/output.php';
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
<?php
echo "
<div class='card col-md-5 m-auto  mb-5'>
        <div class='card-header text-center'>
            <h1>
                Date Selected: $dateselected
            </h1>
        </div>
    </div>";

?>
<section>
    <div class="col-md-2 m-auto my-5 " id="calendarDiv">
        <div class="card">
            <div class="card-header">
                <p class='text-center mb-0 h3'>Select Date</p>
            </div>
            <div class="card-body">
                <div id="calendar">
                    <form action="output.php" method="post">
                        <input type="date" id="datepicker" class="form-control" name="selectedDate" placeholder="Select a date">
                        <div class="d-grid">
                            <button type="submit" class="btn btn-success mt-3" name="search">Search</button>
                        </div>
                    </form>
                </div>
            </div>
        </div>
    </div>
    
   
    
    <div class="col-md-6 m-auto">
        <table class="table table-bordered mb-5">
            <tr>
                <th class="text-center" colspan="4"><h3>Items Rating</h3></th>
            </tr>
            <tr>
                <th class="col-md-3" >Item</th>
                <th class="col-md-3" >No of Person Rated</th>
                <th class="col-md-3" >Total Rating</th>
                <th class="col-md-3" >Out of </th>
            </tr>
            
            <?php
            

            // Fetch all items from the menu table
            $query = "SELECT * FROM `menu` where DATE(`date`) = '$dateselected'";
            $menuItems = $db->select($query);
            if(!$menuItems){
                echo "<tr><td colspan='4' class='text-center'>No data found</td></tr>";
            }else{
            while ($menuItem = mysqli_fetch_assoc($menuItems)) {
                $itemId = $menuItem['item_id'];
                $mealId = $menuItem['meal_id'];
                if($mealId == 1){
                    $meal = 'Breakfast';
                }elseif($mealId == 2){
                    $meal = 'Lunch';
                }elseif($mealId == 3){
                    $meal = 'Snacks';
                }elseif($mealId == 4){
                    $meal = 'Dinner';
                }
                
                // Count the number of users who have rated the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and meal_id = $mealId");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                
                // Calculate the total rating for the item
                $totalRatingResult = $db->select("SELECT SUM(rating) AS total_rating FROM ratings WHERE item_id = $itemId and meal_id = $mealId");
                $totalRating = mysqli_fetch_assoc($totalRatingResult)['total_rating'];
                
                echo "<tr>";
                echo "<td>";
                $name = "SELECT `name` from `items` where `id` = '$itemId'" ; $item = $db->select($name); while ($itemRow = $item->fetch_assoc()) {echo $itemRow['name']; echo " ($meal)"; } 
                echo "</td>";
                echo "<td>" . $ratingCount . "</td>";
                echo "<td>" . $totalRating . "</td>";
                echo "<td>" . $ratingCount * 5 . "</td>";
                echo "</tr>";
            }
        }
            ?>
        </table>


        <table class="table table-bordered mb-5" >
            <tr>
                <th colspan="4"  class="text-center h3">Breakfast</th>
            </tr>
            <tr>
                <th class="col-md-4" >Items</th>
                <th class="col-md-4" >No of Stars</th>
                <th class="col-md-4" >Users rated</th>
            </tr>
            <?php
            $query = "SELECT * FROM `menu` where DATE(`date`) = '$dateselected' and `meal_id` = 1";
            $menuItems = $db->select($query);
            if(!$menuItems){
                echo "<tr><td colspan='3' class='text-center'>No data found</td></tr>";
            }else{
            while ($menuItem = mysqli_fetch_assoc($menuItems)) {
                $itemId = $menuItem['item_id'];
               
                // Count the number of users who have rated 5 for the item 
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 5");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                
                echo "<tr>";
                echo "<td rowspan='5'>";
                $name = "SELECT `name` from `items` where `id` = '$itemId'" ; $item = $db->select($name); while ($itemRow = $item->fetch_assoc()) {echo $itemRow['name'];} 
                echo "</td>";
                echo "<td>5</td>";
                echo "<td>" . $ratingCount . "</td>";
                echo "</tr>";

                // Count the number of users who have rated 4 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 4");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>4</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';

                // Count the number of users who have rated 3 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 3");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>3</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';

                // Count the number of users who have rated 2 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 2");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>2</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';

                // Count the number of users who have rated 1 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 1");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>1</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';
            
            }}

            ?>

        </table>

        <table class="table table-bordered mb-5" >
            <tr>
                <th colspan="4"  class="text-center h3">Lunch</th>
            </tr>
            <tr>
                <th class="col-md-4" >Items</th>
                <th class="col-md-4" >No of Stars</th>
                <th class="col-md-4" >Users rated</th>
            </tr>
            <?php
            $query = "SELECT * FROM `menu` where DATE(`date`) = '$dateselected' and `meal_id` = 2";
            $menuItems = $db->select($query);
            if(!$menuItems){
                echo "<tr><td colspan='3' class='text-center'>No data found</td></tr>";
            }else{
            while ($menuItem = mysqli_fetch_assoc($menuItems)) {
                $itemId = $menuItem['item_id'];
               
                // Count the number of users who have rated 5 for the item 
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 5");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                
                echo "<tr>";
                echo "<td rowspan='5'>";
                $name = "SELECT `name` from `items` where `id` = '$itemId'" ; $item = $db->select($name); while ($itemRow = $item->fetch_assoc()) {echo $itemRow['name'];} 
                echo "</td>";
                echo "<td>5</td>";
                echo "<td>" . $ratingCount . "</td>";
                echo "</tr>";

                // Count the number of users who have rated 4 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 4");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>4</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';

                // Count the number of users who have rated 3 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 3");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>3</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';

                // Count the number of users who have rated 2 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 2");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>2</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';

                // Count the number of users who have rated 1 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 1");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>1</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';
            
            }}

            ?>

        </table>

        <table class="table table-bordered mb-5" >
            <tr>
                <th colspan="4" class="text-center h3" >Snacks</th>
            </tr>
            <tr>
                <th class="col-md-4" >Items</th>
                <th class="col-md-4" >No of Stars</th>
                <th class="col-md-4" >Users rated</th>
            </tr>
            <?php
            $query = "SELECT * FROM `menu` where DATE(`date`) = '$dateselected' and `meal_id` = 3";
            $menuItems = $db->select($query);
            if(!$menuItems){
                echo "<tr><td colspan='3' class='text-center'>No data found</td></tr>";
            }else{
            while ($menuItem = mysqli_fetch_assoc($menuItems)) {
                $itemId = $menuItem['item_id'];
               
                // Count the number of users who have rated 5 for the item 
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 5");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                
                echo "<tr>";
                echo "<td rowspan='5'>";
                $name = "SELECT `name` from `items` where `id` = '$itemId'" ;
                $item = $db->select($name); while ($itemRow = $item->fetch_assoc()) {echo $itemRow['name'];} 
                echo "</td>";
                echo "<td>5</td>";
                echo "<td>" . $ratingCount . "</td>";
                echo "</tr>";

                // Count the number of users who have rated 4 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 4");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>4</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';

                // Count the number of users who have rated 3 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 3");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>3</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';

                // Count the number of users who have rated 2 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 2");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>2</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';

                // Count the number of users who have rated 1 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 1");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>1</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';
            
            }}

            ?>

        </table>


        <table class="table table-bordered mb-5" >
            <tr>
                <th colspan="4"  class="text-center h3">Dinner</th>
            </tr>
            <tr>
                <th class="col-md-4" >Items</th>
                <th class="col-md-4" >No of Stars</th>
                <th class="col-md-4" >Users rated</th>
            </tr>
            <?php
            $query = "SELECT * FROM `menu` where DATE(`date`) = '$dateselected' and `meal_id` = 4";
            $menuItems = $db->select($query);
            if(!$menuItems){
                echo "<tr><td colspan='3' class='text-center'>No data found</td></tr>";
            }else{
            while ($menuItem = mysqli_fetch_assoc($menuItems)) {
                $itemId = $menuItem['item_id'];
               
                // Count the number of users who have rated 5 for the item 
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 5");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                
                echo "<tr>";
                echo "<td rowspan='5'>";
                $name = "SELECT `name` from `items` where `id` = '$itemId'" ; $item = $db->select($name); while ($itemRow = $item->fetch_assoc()) {echo $itemRow['name'];} 
                echo "</td>";
                echo "<td>5</td>";
                echo "<td>" . $ratingCount . "</td>";
                echo "</tr>";

                // Count the number of users who have rated 4 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 4");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>4</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';

                // Count the number of users who have rated 3 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 3");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>3</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';

                // Count the number of users who have rated 2 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM ratings WHERE item_id = $itemId and rating = 2");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>2</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';

                // Count the number of users who have rated 1 for the item
                $ratingCountResult = $db->select("SELECT COUNT(DISTINCT user_id) AS rating_count FROM `ratings` WHERE item_id = $itemId and rating = 1");
                $ratingCount = mysqli_fetch_assoc($ratingCountResult)['rating_count'];
                echo '<tr>';
                echo '<td>1</td>';
                echo "<td>" . $ratingCount . "</td>";
                echo '</tr>';
            
            }}

            ?>

        </table>
    </div>
</section>