<!DOCTYPE html>
<html>

<head>
   <meta name="viewport" content="width=device-width, initial-scale=1.0">


   <style>

     .center {
        margin: auto;
        width: 75%;
        padding: 10px;
        text-align: center;
     }


      body {background-color: rgb(89.4%, 91.8%, 94.1%);}

      p {
        font-size: 1.25em;
        font-family: Arial;
      }

      select {
         display: inline-block;
         width: 50px;
      }

   </style>
</head>




<body>
<?php
  $from = $_POST["from"];
  $to = $_POST["to"];
  $command = "sh move.sh $to $from";
  $url = exec($command);
?>

<div class="center">

   <form action="move.php" method="POST"> 
     <table class = "center" style="width:40%">
     <tr>
     <td>
     <label for "From"><p>From</p></label>
     <select name="from" id="from" style="height:22px;">
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
     </td>

     <td>
     <label for "To"><p>To</p></label>
     <select name="to" id="to" style="height:22px">
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
     </td>

     <td>
     <br><br><br>
     <input type="submit" value="Move"> 
     </td> 
   </tr>
   </table>
   </form>

   <img src="<?php echo $url;?>">

  </div>
</body>
</html>
