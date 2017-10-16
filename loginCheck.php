<?php
session_start();

$HOST="localhost";
$USERNAME="root"; //mysql username
$PASSWORD=""; //mysqlpassword
$DB_NAME="db_spark"; //mysql database name
$TABLE_NAME="tbl_memberlogin"; //mysql table name

// connect to server and select database

$connection=mysqli_connect("$HOST","$USERNAME","$PASSWORD")or die("Can Not Connect.");
mysqli_select_db($connection,"$DB_NAME")or die("Can Not Select DataBase.");

// username and password sent from form

$myemail=$_POST['myemail'];
$mypassword=$_POST['mypassword'];

$myemail=stripcslashes($myemail);
$mypassword=stripcslashes($mypassword);

$myemail=mysqli_real_escape_string($connection,$myemail);
$mypassword=mysqli_real_escape_string($connection,$mypassword);

$sql="select * from $TABLE_NAME where email='$myemail' and password='$mypassword'";
$result=mysqli_query($connection,$sql);

$count=mysqli_num_rows($result);

if($count==1)
{
	
	$_SESSION["myemail"]=$myemail;
	
	//$_SESSION['mypassword']=$mypassword;
	
	//header("location:home.php");
	header("location:http://10.0.0.5/");
	//header("location:pincheck.php");
	exit;
	
}
else
{
	echo "Wrong Username OR Password.";
}

?>