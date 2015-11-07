<?php
$connection = mysqli_connect('localhost','eloyalty','@csci155','eloyalty_data') or die(mysqli_error($connection));

if(isset($_POST['action']))
{          
    if($_POST['action']=="login")
    {
        $email = mysqli_real_escape_string($connection,$_POST['email']);
        $pass = mysqli_real_escape_string($connection,$_POST['password']);
        $strSQL = mysqli_query($connection,"select username from users where email='".$email."' and pass='".md5($pass)."'");
        $Results = mysqli_fetch_array($strSQL);
        if(count($Results)>=1)
        {
            $message = $Results['username']." Login Sucessfully!!";
        }
        else
        {
            $message = "Invalid email or password!!";
        }        
    }
    elseif($_POST['action']=="signup")
    {
        $username       = mysqli_real_escape_string($connection,$_POST['username']);
        $email      = mysqli_real_escape_string($connection,$_POST['email']);
        $pass   = mysqli_real_escape_string($connection,$_POST['pass']);
        $query = "SELECT email FROM users where email='".$email."'";
        $result = mysqli_query($connection,$query);
        $numResults = mysqli_num_rows($result);
        if (!filter_var($email, FILTER_VALIDATE_EMAIL)) // Validate email address
        {
            $message =  "Invalid email address please type a valid email!!";
        }
        elseif($numResults>=1)
        {
            $message = $email." Email already exists!!";
        }
        else
        {
            mysql_query("insert into users(username,email,password) values('".$username."','".$email."','".md5($password)."')");
            $message = "Signup Sucessfully!!";
        }
    }
}
 
//code found from http://www.phpgang.com/how-to-create-login-and-signup-form-in-php_377.html


?>
