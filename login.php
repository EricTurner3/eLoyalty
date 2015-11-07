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
            $message = $email." Email already exist!!";
        }
        else
        {
            mysql_query("insert into users(username,email,password) values('".$username."','".$email."','".md5($password)."')");
            $message = "Signup Sucessfully!!";
        }
    }
}
 

<!-- Login and Signup forms -->
<div id="tabs">
  <ul>
    <li><a href="#tabs-1">Login</a></li>
    <li><a href="#tabs-2" class="active">Signup</a></li>
 
  </ul>                 
  <div id="tabs-1">
  <form action="" method="post">
    <p><input id="email" name="email" type="text" placeholder="Email"></p>
    <p><input id="password" name="password" type="password" placeholder="Password">
    <input name="action" type="hidden" value="login" /></p>
    <p><input type="submit" value="Login" /></p>
  </form>
  </div>
  <div id="tabs-2">
    <form action="" method="post">
    <p><input id="username" name="username" type="text" placeholder="Username"></p>
    <p><input id="email" name="email" type="text" placeholder="Email"></p>
    <p><input id="password" name="password" type="password" placeholder="Password">
    <input name="action" type="hidden" value="signup" /></p>
    <p><input type="submit" value="Signup" /></p>
  </form>
  </div>
</div>

?>