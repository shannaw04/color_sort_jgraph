<html>
<body>

Welcome <?php echo $_POST["colors"]; ?><br>

<?php 

$command = "sh play_game.sh";
//echo 'Command: '.$command.PHP_EOL;
$url = exec($command);
//echo 'Result: '.$result.PHP_EOL;

?>
<!-- img src="<?php echo $url; ?>" /> -->


<img src="<?php echo $url;?>" alt="game" class="game">


</body>
</html>
