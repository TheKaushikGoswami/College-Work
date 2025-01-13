<?php

class Database{
    public $host    = 'srv1474.hstgr.io';
    public $user    = 'u558257531_admin';
    public $pass    = '0VfWUKW#1tP;';
    public $dbname  = 'u558257531_interschool';
    
    public $link;
    public $error;
    public function __construct(){
        $this->connectDB();
    }
    private function connectDB(){
       $this->link = new mysqli($this->host, $this->user, $this->pass, $this->dbname);
        if(!$this->link){
            $this->error = "Connection Fail".$this->link->connect_error;
            return false;  
        }
    }

      // Select or Read Data
      public function select($query){
        $result = $this->link->query($query)or die($this->link->error.__LINE__);
        if($result->num_rows > 0){
            return $result;
        }else{
            return false;
        }
    }

       // insert Data
       public function insert($query){
        $insert_row = $this->link->query($query)or die($this->link->error.__LINE__);
        if($insert_row){
            return $last_id = $this->link->insert_id;
           // header("location:index.php?msg=".urlencode('Data Successfully Inserted.'));
            //exit();
        }else{
            die("Error :".$this->link->errno.")".$this->link->error);
        }
    }

        // update Data
        public function update($query){
            $update_row = $this->link->query($query)or die($this->link->error.__LINE__);
            if($update_row){
                header("location:index.php?msg=".urlencode('Data Updated Successfully .'));
                exit();
            }else{
                die("Error: :".$this->link->errno.")".$this->link->error);
            }
        }
        // delete Data
      public function delete($query){
        $delete_row = $this->link->query($query)or die($this->link->error.__LINE__);
        if($delete_row){
            header("location:index.php?msg=".urlencode('Data Deleted Successfully .'));
            exit();
        }else{
            die("Error: :".$this->link->errno.")".$this->link->error);
        }
    }
   
}
?>