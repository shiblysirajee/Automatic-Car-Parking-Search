<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
<title>Spark Home Page</title>

<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/1.12.4/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.3.7/js/bootstrap.min.js"></script>

<style>
body {
      font: 20px Montserrat, sans-serif;
      line-height: 1.8;
      color: #f5f6f7;
  }
  p {font-size: 16px;}
.bg-1{
	background-color: #F08080;
	color: #fff;
  padding-top: 30px;
  padding-bottom: 30px;
}

.bg-2 { 
      padding-top: 20px;
      background-color: #F1F4F7; 
      color: #000;
      height: 100%;
  }
.bg-3{
  background-color: #fff;
  color: #000;
  height: 100%;
  padding-top: 15px;

  }
.bg-4 { 
    background-color: #2f2f2f;
    color: #ffffff;
    padding: 15px;
}
.row{
  height: 1000px;
}

	
</style>
</head>

<body>              
<div class="container-fluid bg-1 text-center">   
    	<h1>Smart Parking</h1>
    	<p>We provide smart car parking solution.</p>
</div>
                 
<div class="container-fluid text-center">
	<div class="row">
    <div class="col-sm-3 bg-2">
      
      <p>USER: <strong><span style="color:#CD5C5C"><?php echo $_SESSION["myemail"];?></span></strong>
       </p>
      <p>&nbsp;</p>
      <p><a href="logout.php"><span class="glyphicon glyphicon-log-out">Logout</span></a></p>

    </div>
    <div class="col-sm-9 bg-3">
      <div class="col-sm-4">
       <strong>Select Your Target Location:</strong></div>
        <div class="dropdown col-sm-3">
          <button class="btn btn-primary dropdown-toggle" type="button" data-toggle="dropdown">Location:
          <span class="caret"></span></button>
          <ul class="dropdown-menu">
              <li><a href="#">Gulshan</a></li>
              <li><a href="#">Banani</a></li>
              <li><a href="#">Uttara</a></li>
              <li><a href="#">Mohammadpur</a></li>
              <li><a href="#">Mirpur</a></li>
          </ul>
          </div>
      </div>
    </div>      
    </div>
<footer class="container-fluid bg-4 text-center">
 <p>Created By Mashuk And Shibly</p> 
</footer>
		
</body>

</html>