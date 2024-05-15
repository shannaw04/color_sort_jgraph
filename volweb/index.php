<!DOCTYPE html>

<html>
<body>

<head>
  
    <title>Color Sort!</title>
    <style>

   .center {
        margin: auto;
        width: 75%;
        padding: 10px;
        text-align: center;
    }


    body {background-color: rgb(89.4%, 91.8%, 94.1%);}

    p {
        font-size: 1.875em;
        font-family: Arial;
    }

    submit {
       font-size:1.875em;
       font-family: Arial;
    }
    </style>

</head>

<body>


<?php 
  $command = "sh make_logo.sh";
  $url = exec($command);
?>


<div class="center">
<img src="<?php echo $url;?>">

<br>
<form action="load.php" method="POST">
<label for "colors"><p>How many colors?:</p></label>
<select name="colors" id="colors" style="width: 50px;">
   <option value="2">2</option>
   <option value="3">3</option>	
   <option value="4">4</option>
   <option value="5">5</option>	
   <option value="6">6</option>
   <option value="7">7</option>	
   <option value="8">8</option>
   <option value="9">9</option>	
   <option value="10">10</option>
   <option value="11">11</option>	
   <option value="12">12</option>	
</select>

<input type="submit" value="Play Game!">
</form>
</div>
</body> 

</html>
