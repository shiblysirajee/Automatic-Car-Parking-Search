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

	$myuserfullname=$_POST['myuserfullname'];
	$myemail=$_POST['myemail'];
	$mypassword=$_POST['mypassword'];
	$sql="insert into $TABLE_NAME (fullname,email,password) values ('$myuserfullname','$myemail','$mypassword')";
	$result=mysqli_query($connection,$sql);
	
	if($result)
	{
		
		header("location:login_page.php");
		exit;
	}
	else
	{
		echo "Registration Unsuccessful.";
	}

?>

