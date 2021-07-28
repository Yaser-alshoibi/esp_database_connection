<?php     
  require 'database.php';
  
  if (!empty($_POST)) {
    $Stat = $_POST['Stat'];
      
    // insert data
    $pdo = Database::connect();
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    $sql = "UPDATE led SET Stat = ? WHERE ID = 0";
    $q = $pdo->prepare($sql);
    $q->execute(array($Stat));
    Database::disconnect();
    header("Location: Main.php");
  }
?>