
#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266HTTPClient.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>     

#define power 2  //--> Defining an On Board LED (GPIO2 = D4), used for indicators when the process of connecting to a wifi router
#define LED_D8 15 //--> Defines an LED Pin. D8 = GPIO15

//----------------------------------------Web Server address / IPv4
// If using IPv4, press Windows key + R then type cmd, then type ipconfig (If using Windows OS).
const char *host = "http://192.168.8.101";
//----------------------------------------

void setup() {
  
    Serial.begin(9600);
    pinMode(LED_D8,OUTPUT); //--> LED port Direction output
    digitalWrite(LED_D8, LOW); //--> Turn off Led  
    pinMode(power,OUTPUT);  
    digitalWrite(power,HIGH);
    WiFiManager wifiManager;
    wifiManager.resetSettings();
    wifiManager.autoConnect("ESP YASER WiFi Manager");
    Serial.println("connected :)");
}
 

void loop() {

  
  if (WiFi.status() == WL_CONNECTED){
    
          digitalWrite(power,LOW);
          
          while(WiFi.status() == WL_CONNECTED){           
            
// Operating code after connecting successfully:

  HTTPClient http; //--> Declare object of class HTTPClient
  //----------------------------------------Getting Data from MySQL Database
  String GetAddress, LinkGet, getData;
  int id = 0; //--> ID in Database
  GetAddress = "/task/GetData.php";
  LinkGet = host + GetAddress; //--> Make a Specify request destination
  getData = "ID=" + String(id);
  
  Serial.println("----------------Connect to Server-----------------");
  Serial.println("Get LED Status from Server or Database");
  Serial.print("Request Link : ");
  Serial.println(LinkGet);
  
  http.begin(LinkGet); //--> Specify request destination
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");    //Specify content-type header
  int httpCodeGet = http.POST(getData); //--> Send the request
  String payloadGet = http.getString(); //--> Get the response payload from server
  
  Serial.print("Response Code : "); //--> If Response Code = 200 means Successful connection, if -1 means connection failed.
  Serial.println(httpCodeGet); //--> Print HTTP return code
  Serial.print("Returned data from Server : ");
  Serial.println(payloadGet); //--> Print request response payload
  
// After recieveing the value and storing it in 'payloadGet':

  if (payloadGet == "1") {
    digitalWrite(LED_D8, HIGH); //--> Turn on Led
  }
  if (payloadGet == "0") {
    digitalWrite(LED_D8, LOW); //--> Turn off Led
  }
  
  //----------------------------------------
 
  Serial.println("----------------Closing Connection----------------");
  http.end(); //--> Close connection
  Serial.println();
  Serial.println("Please wait 5 seconds for the next connection.");
  Serial.println();
  delay(100); //--> GET Data at every 0.1 second
}
        }              
        }
  
