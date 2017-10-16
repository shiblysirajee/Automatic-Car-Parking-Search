<!DOCTYPE html>
<html lang="en">
<head>
<title>Spark Login Page</title>

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
  padding-top: 40px;
  padding-bottom: 40px;
}

.bg-2 { 
      background-color: #fff; /* Dark Blue */
      color: #000;
  }
.bg-4 { 
    background-color: #2f2f2f;
    color: #ffffff;
    padding: 15px;
}

	
</style>
</head>

<body>              
<div class="container-fluid bg-1 text-center">   
    	<img src="logo.png" class="img-circle" style="display:inline" alt="spark" width="235" height="235">
    	<h1>Smart Parking</h1>
    	<p>We provide smart car parking solution.</p>
</div>
                 
<div class="container-fluid bg-2">
	<div class="container">
	
  		<h3 class="col-sm-offset-3 col-sm-6">Lets Login and Gets into it. </h3>
  
  		<form name="Login" method="POST" action="loginCheck.php">
    	<div class="col-sm-offset-3 col-sm-6">
      		<input type="email" class="form-control input-lg" placeholder="Enter email" name="myemail">
    	</div>
    	
    	<div class="col-sm-offset-3 col-sm-6">
      		<input type="password" class="form-control input-lg" id="pwd" placeholder="Enter password" name="mypassword">
    	</div>
    	
    	<div class="col-sm-offset-3 col-sm-6">
    		<button type="Submit" name="submit" class="btn btn-success">Login</button>
    	</div>
  		</form>
  		
  	</div>
  	<div class="container">
  	 <a class="col-sm-offset-3 col-sm-6" href="registration.php">Registration</a>
  	</div>
</div>
<footer class="container-fluid bg-4 text-center">
 <p>Developed By Mashuk And Shibly</p> 
</footer>
		
</body>

</html>