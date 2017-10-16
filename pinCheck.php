<?php
session_start();
?>
<!DOCTYPE html>
<html lang="en">
<head>
<title>Spark PIN Check</title>

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
.container{
  padding-top: 25px;
  padding-bottom: 425px;
}
.btn {
      padding: 10px 20px;
      background-color: #333;
      color: #f1f1f1;
      border-radius: 0;
      transition: .2s;
}
.btn:hover, .btn:focus {
      border: 1px solid #333;
      background-color: #fff;
      color: #000;
}

	
</style>
</head>

<body>              
<div class="container-fluid bg-1 text-center">   
    	<h1>Smart Parking</h1>
    	<p>We provide smart car parking solution.</p>
</div>
<div class="container">
  <div class="well">
    <div class="row">
    <form method="GET">
      <div class="col-md-6 form-group">
        <input type="text" name="pin" class="form-control input-lg" placeholder="Enter PIN">
      </div>
      <div class="col-md-6 form-group">
        <button class="btn" type="submit">Enter</button>
      </div>
      </form>
     </div>     
  </div>
  
</div>
                 

<footer class="container-fluid bg-4 text-center">
 <p>Created By Mashuk And Shibly</p> 
</footer>
		
</body>

</html>

<!--- PHP Code Check-->
<!--- PHP Code Check-->
<!--- PHP Code Check--> 

<?php
$pinNumber=$_GET["pin"];
//$parts = parse_url($url);
//parse_str($parts['query'], $query);
//echo $query[''];

if($pinNumber==1234)
{
  header("location:login_page.php");
  //header("location:http://192.168.1.11/");
  exit;

}
else if($pinNumber=="")
{

}
else
{
  echo '<script language="javascript">';
  echo 'alert("Sorry! Wrong PIN")';
  echo '</script>';
}
?>
