# ESP Database Connection

In this project, I have used ESP8266 to receive a value from a database using GET method and by connecting ESP to the internet using WiFi Manager library.<br>

# Database and Web Implementation

I have created a database named 'esp'. Then, I created a table called 'led'. Then I created two columns, one is ID and it is used as primary key, the other is Stat which will hold LED statues either 0 or 1.

Then I built four files:
- main.php > Contains html and css codes.
- database.php > Builds database connection.
- updateDB.php > Updates Stat coloumn after clicking on the buttons in main.php interface.
- GetData.php > Sends the data and connect with ESP.

<p align="center">
<img src="https://user-images.githubusercontent.com/85786699/127405540-26815bc9-6ab3-4336-8e10-591a99c6fef7.png">
<br> 
Figure 1: Main.php interface</p>

# Working Principle

I used ESP8266 module and an LED. First after plugging ESP on the user has to scan and connect to any Wi-Fi network, and once the connection is established, the rest of the program will run which will connect to my IP address to access my virtual server and opens getData.php file to use GET method to retrieve the value stored in my local database under Stat column, which depends on the interface on main.php page. After that, the value will be stored and used to turn my LED ON of OFF.


# Circuit Implementation

I used two LEDs, one is to be controlled be the interface, and the other LED is built-in LED within ESP8266 to indicate if it is connected to the internet or not.

<p align="center">
<img src="https://user-images.githubusercontent.com/85786699/127397021-b9606876-f4a7-4876-aa7b-548cfa333162.png">
<br>
Figure 2: Circuit Connection</p>



# Code using Arduino IDE

LED is connected to D8 which is equivalent to GPIO 15.
Built-in LED of ESP8266 is controlled by GPIO 2.

**Note: this code is only compatible with ESP8266, to use this code with ESP32 you need to change <ESP8266WiFi.h> library to <WiFi.h>, and <ESP8266HTTPClient.h> to <HTTPClient.h>, and <ESP8266WebServer.h> to <WebServer.h>**

In the beginning you need to look for your IPv4 using CMD and ipconfig and write it into the constant host.
<br>
```C++
const char *host = "http://192.168.8.101";
```
<br>

Also, you need to write the path to getData.php file.<br>

```C++
GetAddress = "/task/GetData.php";
```
<br>

Inside the void setup:
<br>
```C++
  Serial.begin(9600);
  pinMode(LED_D8,OUTPUT); //--> LED port Direction output
  digitalWrite(LED_D8, LOW); //--> Turn off Led  
  pinMode(power,OUTPUT);  
  digitalWrite(power,HIGH);
  WiFiManager wifiManager;
  wifiManager.resetSettings();
  wifiManager.autoConnect("ESP YASER WiFi Manager");
  Serial.println("connected :)");
```
<br>
    
Inside void loop starting with if condition which runs the rest of the code if the ESP connected successfuly:
<br>
```C++

if (WiFi.status() == WL_CONNECTED){
  digitalWrite(power,LOW);       
  while(WiFi.status() == WL_CONNECTED){
```
<br>


Then the rest of the code will operate which use GET method to receive the value from the database to either turning the LED ON or OFF, code is explained using comments.


<br>

# Expirement Video

<br>


https://user-images.githubusercontent.com/85786699/127403267-0164780f-dbd6-47f3-9b30-83656b6ed019.mp4


<br>

