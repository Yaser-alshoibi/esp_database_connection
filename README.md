# ESP Connection

In this project, I have used ESP8266 to recieve a value from a database using GET method and by connecting the ESP to internet using WiFi Manager library.


# Database and Web Implementation

I have created a database named 'esp'. Then, I created a table called 'led'. Then I created two coloums, one is ID and it is used as primary key, the other is Stat which will hold LED statues either 0 or 1.

Then I built four files:
- main.php > contain html and css codes.
- database.php > Build database connection.
- updateDB.php > Updates Stat coloumn after clicking on the buttons in main.php interface.
- GetData.php > To send the data and connect with ESP.


# Working Principle

I used ESP8266 module and an LED. First after plugging ESP on the user has to scan and connect to any Wi-Fi network, and once the connection is established the rest of the program will run which will connect to my IP address to access my virtual server and opens getData.php file to use GET method to retrive the value stored in my local database under Stat column, which depends on the interface on main.php page. After that, the value will be stored and used to turn my LED ON of OFF.


# Circuit Implementation

I will be using to LED, one is to be controlled be the interface, and the other LED is built-in LED within ESP8266 to indicate if it is connected or not.

![image](https://user-images.githubusercontent.com/85786699/127397021-b9606876-f4a7-4876-aa7b-548cfa333162.png)



# Code using Arduino IDE

LED is onnected to D8 which is equivelent to GPIO 15.
Built in LED of ESP8266 is controlled by GPIO 2.

**Note: this code is only comppitable with ESP8266, to use this code with ESP32 you need to change <ESP8266WiFi.h> library to <WiFi.h>, and <ESP8266HTTPClient.h> to <HTTPClient.h>, and <ESP8266WebServer.h> to <WebServer.h>**

In the start you need to look for your IPv4 using CMD and ipconfig and write it into the constant host.
<br>
```C++
const char *host = "http://192.168.8.101";
```
<br><br>
And also you need to write the path to getData.php file.<br>
```C++
GetAddress = "/task/GetData.php";
```
<br><br>

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
<br><br>
    
Inside void loop starting with the if condition which runs the rest of the code if the ESP connected successfuly:


<br>

if (WiFi.status() == WL_CONNECTED){
    
  digitalWrite(power,LOW);
          
  while(WiFi.status() == WL_CONNECTED){


Then the rest of the code will operate which use GET method to recieve the value from the database to either turning the LED ON or OFF, code is explained using comments.



# Expirement Video




https://user-images.githubusercontent.com/85786699/127403267-0164780f-dbd6-47f3-9b30-83656b6ed019.mp4


