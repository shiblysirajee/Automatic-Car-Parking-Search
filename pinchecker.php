<?php
$pinNumber=$_POST['pin'];

if($pinNumber==1234)
{
	header("location:login_page.php");
	//header("location:http://192.168.1.13/");
	exit;

}
else
{
	echo '<script language="javascript">';
	echo 'alert("Sorry! Wrong PIN")';
	echo '</script>';
}
?>