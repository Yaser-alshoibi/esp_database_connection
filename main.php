<!DOCTYPE html>
<html>
  <head>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <meta charset="utf-8">
    <style>
      html {
          font-family: Arial;
          display: inline-block;
          margin: 0px auto;
          text-align: center;
      }
      
      h1 { font-size: 2.0rem; color:#2980b9;}
      h2 { font-size: 1.25rem; color:#2980b9;}
      
      .buttonON {
        display: inline-block;
        padding: 15px 25px;
        font-size: 24px;
        font-weight: bold;
        cursor: pointer;
        text-align: center;
        text-decoration: none;
        outline: none;
        color: #fff;
        background-color: #4CAF50;
        border: none;
        border-radius: 15px;
        box-shadow: 0 5px #999;
      }
      .buttonON:hover {background-color: #3e8e41}
      .buttonON:active {
        background-color: #3e8e41;
        box-shadow: 0 1px #666;
        transform: translateY(4px);
      }
        
      .buttonOFF {
        display: inline-block;
        padding: 15px 25px;
        font-size: 24px;
        font-weight: bold;
        cursor: pointer;
        text-align: center;
        text-decoration: none;
        outline: none;
        color: #fff;
        background-color: #e74c3c;
        border: none;
        border-radius: 15px;
        box-shadow: 0 5px #999;
      }
      .buttonOFF:hover {background-color: #c0392b}
      .buttonOFF:active {
        background-color: #c0392b;
        box-shadow: 0 1px #666;
        transform: translateY(4px);
      }
    </style>
  </head>
  <body>
  <h1>Smart Methods - ESP task</h1>
  <h2>Controlling LED using ESP8266 with MySQL Database</h2>
    
    <form action="updateDB.php" method="post" id="LED_ON" onsubmit="myFunction()">
      <input type="hidden" name="Stat" value="1"/>    
    </form>
    
    <form action="updateDB.php" method="post" id="LED_OFF">
      <input type="hidden" name="Stat" value="0"/>
    </form>
    
    <button class="buttonON" name= "subject" type="submit" form="LED_ON" value="SubmitLEDON" >LED ON</button>
    <button class="buttonOFF" name= "subject" type="submit" form="LED_OFF" value="SubmitLEDOFF">LED OFF</button>  
  </body>
</html>