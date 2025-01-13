<?php
include 'callback/rating.php';
include 'includes/header.php';
?>




<div class="col-md-4">
    <form action="" method="post">
        <button type='submit' name='logout' class='btn btn-danger'>Logout</button>
    </form>
</div>
<div class="d-flex align-items-center" style="height:100vh;">
    <div class="card col-md-6 m-auto">
        <div class="card-header">
            <h1 class="m-auto text-center mx-5 h1">Rate the Dishes</h1>
        </div>
        <div class="card-body ">
            <form action="" method="post">
                <?php
                   if($currentTime >= '8:00' && $currentTime <= '12:00'){
                    $query = "SELECT * FROM `menu` WHERE meal_id = 1 AND date = '$date'";
                    $result = $db->select($query);

                    if ($result) {
                        $i = 1;
                        while ($row = $result->fetch_assoc()) {
                            $item_id = $row['item_id'];
                            $q2 = "SELECT * FROM `items` WHERE id = $item_id";
                            $r2 = $db->select($q2);

                            if ($r2) {
                                foreach ($r2 as $row2) {
                                    $item_name = $row2['name'];
                                }
                                $check = "SELECT * FROM `ratings` WHERE user_id = '$userid' AND item_id = '$item_id' AND meal_id = '$meal'";
                                $check_result = $db->select($check);
                                if($check_result){
                                    echo "<div class='input-group color-danger mb-3'><span class='input-group-text col-md-3' id='basic-addon1'>";
                                    echo $item_name. "</span>";
                                    $i++;}
                                else{
                                echo "<div class='input-group mb-3'><span class='input-group-text col-md-3' id='basic-addon1'>";
                                echo $item_name. "</span>";
                                echo "<div class='rating border border-start-0 rounded col-md-9' >
                                <input type='hidden' name='item_id".$i."' value='".$item_id."'> 
                                    <input type='radio' id='star5".$i."' name='rating".$i."' value='5' /><label for='star5".$i."'></label>
                                    <input type='radio' id='star4".$i."' name='rating".$i."' value='4' /><label for='star4".$i."'></label>
                                    <input type='radio' id='star3".$i."' name='rating".$i."' value='3' /><label for='star3".$i."'></label>
                                    <input type='radio' id='star2".$i."' name='rating".$i."' value='2' /><label for='star2".$i."'></label>
                                    <input type='radio' id='star1".$i."' name='rating".$i."' value='1' /><label for='star1".$i."'></label>
                                    </div></div>";
                                $i++;
                            } }
                        }
                    }
                }elseif($currentTime >= '12:00' && $currentTime <= '16:00'){
                    $query = "SELECT * FROM `menu` WHERE meal_id = 2 AND date = '$date'";
                    $result = $db->select($query);

                    if ($result) {
                        $i = 1;
                        while ($row = $result->fetch_assoc()) {
                            $item_id = $row['item_id'];
                            $q2 = "SELECT * FROM `items` WHERE id = $item_id";
                            $r2 = $db->select($q2);

                            if ($r2) {
                                foreach ($r2 as $row2) {
                                    $item_name = $row2['name'];
                                }
                                $check = "SELECT * FROM `ratings` WHERE user_id = '$userid' AND item_id = '$item_id' AND meal_id = '$meal'";
                                $check_result = $db->select($check);
                                if($check_result){
                                    echo "<div class='input-group color-danger mb-3'><span class='input-group-text col-md-3' id='basic-addon1'>";
                                    echo $item_name. "</span>";
                                    $i++;}
                                else{
                                echo "<div class='input-group mb-3'><span class='input-group-text col-md-3' id='basic-addon1'>";
                                echo $item_name. "</span>";
                                echo "<div class='rating border border-start-0 rounded col-md-9' >
                                <input type='hidden' name='item_id".$i."' value='".$item_id."'> 
                                    <input type='radio' id='star5".$i."' name='rating".$i."' value='5' /><label for='star5".$i."'></label>
                                    <input type='radio' id='star4".$i."' name='rating".$i."' value='4' /><label for='star4".$i."'></label>
                                    <input type='radio' id='star3".$i."' name='rating".$i."' value='3' /><label for='star3".$i."'></label>
                                    <input type='radio' id='star2".$i."' name='rating".$i."' value='2' /><label for='star2".$i."'></label>
                                    <input type='radio' id='star1".$i."' name='rating".$i."' value='1' /><label for='star1".$i."'></label>
                                    </div></div>";
                                $i++;
                            } 
                        }}
                    } 
                }elseif($currentTime >= '16:00' && $currentTime <= '20:00'){
                    $query = "SELECT * FROM `menu` WHERE meal_id = 3 AND date = '$date'";
                    $result = $db->select($query);

                    if ($result) {
                        $i = 1;
                        while ($row = $result->fetch_assoc()) {
                            $item_id = $row['item_id'];
                            $q2 = "SELECT * FROM `items` WHERE id = $item_id";
                            $r2 = $db->select($q2);

                            if ($r2) {
                                foreach ($r2 as $row2) {
                                    $item_name = $row2['name'];
                                }
                                $check = "SELECT * FROM `ratings` WHERE user_id = '$userid' AND item_id = '$item_id' AND meal_id = '$meal' and date = '$date'";
                                $check_result = $db->select($check);
                                if($check_result){
                                    echo "<div class='input-group mb-3'><span class='input-group-text text-danger col-md-3' id='basic-addon1'>";
                                    echo $item_name. "</span>
                                    <div class='text-danger border text-center border-start-0 rounded col-md-9' >
                                    You have already rated this item.</div>
                                    </div>";
                                    }
                                else{
                                echo "<div class='input-group mb-3'><span class='input-group-text col-md-3' id='basic-addon1'>";
                                echo $item_name. "</span>";
                                echo "<div class='rating border border-start-0 rounded col-md-9' >
                                <input type='hidden' name='item_id".$i."' value='".$item_id."'> 
                                    <input type='radio' id='star5".$i."' name='rating".$i."' value='5' /><label for='star5".$i."'></label>
                                    <input type='radio' id='star4".$i."' name='rating".$i."' value='4' /><label for='star4".$i."'></label>
                                    <input type='radio' id='star3".$i."' name='rating".$i."' value='3' /><label for='star3".$i."'></label>
                                    <input type='radio' id='star2".$i."' name='rating".$i."' value='2' /><label for='star2".$i."'></label>
                                    <input type='radio' id='star1".$i."' name='rating".$i."' value='1' /><label for='star1".$i."'></label>
                                    </div></div>";
                                $i++;
                            } 
                        }}
                    }
                }elseif($currentTime >= '20:00' && $currentTime <= '23:59'){
                    $query = "SELECT * FROM `menu` WHERE meal_id = 4 AND date = '$date'";
                    $result = $db->select($query);

                    if ($result) {
                        $i = 1;
                        while ($row = $result->fetch_assoc()) {
                            $item_id = $row['item_id'];
                            $q2 = "SELECT * FROM `items` WHERE id = $item_id";
                            $r2 = $db->select($q2);

                            if ($r2) {
                                foreach ($r2 as $row2) {
                                    $item_name = $row2['name'];
                                }
                                $check = "SELECT * FROM `ratings` WHERE user_id = '$userid' AND item_id = '$item_id' AND meal_id = '$meal'";
                                $check_result = $db->select($check);
                                if($check_result){
                                    echo "<div class='input-group color-danger mb-3'><span class='input-group-text col-md-3' id='basic-addon1'>";
                                    echo $item_name. "</span>";
                                    $i++;}
                                else{
                                echo "<div class='input-group mb-3'><span class='input-group-text col-md-3' id='basic-addon1'>";
                                echo $item_name. "</span>";
                                echo "<div class='rating border border-start-0 rounded col-md-9' >
                                <input type='hidden' name='item_id".$i."' value='".$item_id."'> 
                                    <input type='radio' id='star5".$i."' name='rating".$i."' value='5' /><label for='star5".$i."'></label>
                                    <input type='radio' id='star4".$i."' name='rating".$i."' value='4' /><label for='star4".$i."'></label>
                                    <input type='radio' id='star3".$i."' name='rating".$i."' value='3' /><label for='star3".$i."'></label>
                                    <input type='radio' id='star2".$i."' name='rating".$i."' value='2' /><label for='star2".$i."'></label>
                                    <input type='radio' id='star1".$i."' name='rating".$i."' value='1' /><label for='star1".$i."'></label>
                                    </div></div>";
                                $i++;
                            }}}}
                }
                ?>
                
                <div class="d-grid">
                    <button type="submit" name="submit" class="btn btn-primary">Submit</button>
                </div>
            </form>
        </div>

    </div>
</div>
<script>
    if (window.history.replaceState) {
        window.history.replaceState(null, null, window.location.href);
    }
</script>
<?php
include "includes/footer.php";
?>