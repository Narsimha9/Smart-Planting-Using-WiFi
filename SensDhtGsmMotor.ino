
#include<SoftwareSerial.h>
 #include <DHT.h>  
 #include <ESP8266WiFi.h>  
 #include <WiFiClient.h>  
 #include <ThingSpeak.h>  
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
 #define DHTPIN D0  
 #define DHTTYPE DHT11  
 DHT dht(DHTPIN, DHTTYPE);
 
char auth[] = "a81c7019948e4cb8a6fa1603c223e30c";
char ssid[] = "Narsimha";
char password[] = "Simhalp9"; 
SoftwareSerial gsm(D2,D3);
int sm=A0;
//const char* ssid = "Narsimha";  
 //uconst char* password = "Simhalp9";  
 WiFiClient client;  
 unsigned long myChannelNumber = 543197;  
 const char * myWriteAPIKey = "FCYOGGX6WKSZTOZN";  
 uint8_t temperature, humidity, k=0, l=0,m=0;
void setup()
{  
 Serial.begin(9600);
  dht.begin();  
  delay(10);  
    Blynk.begin(auth, ssid, password);

  Serial.println();  
  Serial.println();  
  Serial.print("Connecting to ");  
  Serial.println(ssid);  
  WiFi.begin(ssid, password);  
  while (WiFi.status() != WL_CONNECTED)  
  {  
   delay(500);  
   Serial.print(".");  
  }  
  Serial.println("");  
  Serial.println("WiFi connected");  
 
  Serial.println(WiFi.localIP());  
  ThingSpeak.begin(client);  
pinMode(sm,INPUT);
gsm.begin(9600);
}
void loop()
{
  Blynk.run();
int sensorvalue=analogRead(A0);
sensorvalue=constrain(sensorvalue,485,1023);
int soil=map(sensorvalue,485,1023,100,0);
  Serial.println("moisture:");
  Serial.println(soil);
  Serial.println("%");
  static boolean data_state = false;  
  temperature = dht.readTemperature();  
  humidity = dht.readHumidity();  
  Serial.print("Temperature Value is :");  
  Serial.print(temperature);  
  Serial.println("C");  
  Serial.print("Humidity Value is :");  
  Serial.print(humidity);  
  Serial.println("%");  
   while(1)
   {
 if(temperature < 255)
  {
   k=temperature;  
    ThingSpeak.writeField(myChannelNumber, 1, k, myWriteAPIKey);
  }
  
  if(humidity < 255)
  {
     l=humidity;
     
   ThingSpeak.writeField(myChannelNumber, 2, l, myWriteAPIKey);
  }
 if(soil<101)
  {    
    m=soil;
    
   ThingSpeak.writeField(myChannelNumber, 3, m, myWriteAPIKey);
  }
 }  
 int count=1;
 if(soil<50)
 {
 while(count>=1&&count<=3)
 {
 if(count==1)
 {
if(soil<=50)
{
gsm.println("ATCMGF=1");
  gsm.println("AT+CMGS=\"+918499008525\"\r"); //Mobile phone number to send message
  delay(1000);
  gsm.println ("1 stplant moisture % is:");
  Serial.println ("1 stplant moisture % is:");
  gsm.println(soil);
  gsm.println("%");
  delay(100);
  gsm.println("ATD8309483023;");
  delay(100);
  gsm.println("ATH");
  gsm.println((char)26);
  delay(10000);
  int sensorvalue=analogRead(A0);
sensorvalue=constrain(sensorvalue,485,1023);
int soil=map(sensorvalue,485,1023,100,0);
if(soil>50)
{
  gsm.println("ATCMGF=1");
  gsm.println("AT+CMGS=\"+918499008525\"\r"); //Mobile phone number to send message
  delay(1000);
  gsm.println (" now 1 stplant moisture % is:");
  Serial.println (" now 1 stplant moisture % is:");
  gsm.println(soil);
  gsm.println("%");
  delay(100);
  gsm.println("ATD8309483023;");
  delay(100);
  gsm.println("ATH");
  gsm.println((char)26);
  break;
}
} 
}
else if(count==2)
{
 if(soil<=50)
{
  
gsm.println("ATCMGF=1");
  gsm.println("AT+CMGS=\"+918499008525\"\r"); //Mobile phone number to send message
  delay(1000);
  gsm.println ("2nd stplant moisture % is:");
  Serial.println ("2nd plant moisture % is:");
  gsm.println(soil);
  gsm.println("%");
  delay(100);
  gsm.println("ATD8309483023;");
  delay(100);
  gsm.println("ATH");
  gsm.println((char)26);
  delay(10000);
  int sensorvalue=analogRead(A0);
sensorvalue=constrain(sensorvalue,485,1023);
int soil=map(sensorvalue,485,1023,100,0);
if(soil>50)
{
  gsm.println("ATCMGF=1");
  gsm.println("AT+CMGS=\"+918499008525\"\r"); //Mobile phone number to send message
  delay(1000);
  gsm.println (" now 2 stplant moisture % is:");
  Serial.println (" now 2 ndstplant moisture % is:");
  gsm.println(soil);
  gsm.println("%");
  delay(100);
  gsm.println("ATD8309483023;");
  delay(100);
  gsm.println("ATH");
  gsm.println((char)26);
  break;
}
} 
}
else if(count==3)
{
 if(soil<=50)
{
gsm.println("ATCMGF=1");
  gsm.println("AT+CMGS=\"+918499008525\"\r"); //Mobile phone number to send message
  delay(1000);
  gsm.println ("3 stplant moisture % is:");
  Serial.println ("3 rdtplant moisture % is:");
  gsm.println(soil);
  gsm.println("%");
  delay(100);
  gsm.println("ATD8309483023;");
  delay(100);
  gsm.println("ATH");
  gsm.println((char)26);
  delay(10000);
  int sensorvalue=analogRead(A0);
sensorvalue=constrain(sensorvalue,485,1023);
int soil=map(sensorvalue,485,1023,100,0);
if(soil>50)
{
  gsm.println("ATCMGF=1");
  gsm.println("AT+CMGS=\"+918499008525\"\r"); //Mobile phone number to send message
  delay(1000);
  gsm.println (" now 3 stplant moisture % is:");
  Serial.println ("now 3rd stplant moisture % is:");
  gsm.println(soil);
  gsm.println("%");
  delay(100);
  gsm.println("ATD8309483023;");
  delay(100);
  gsm.println("ATH");
  gsm.println((char)26);
  break;
}
} 
}
count++; 

delay(10000);
}
 }

else
{
gsm.println("ATCMGF=1");
  gsm.println("AT+CMGS=\"+918499008525\"\r"); //Mobile phone number to send message
  delay(1000);
  gsm.println ("your plant is safe:");
  Serial.println ("your plant is safe:");
  gsm.println(soil);
  gsm.println("%");
  delay(100);
  gsm.println("ATD8309483023;");
  delay(100);
  gsm.println("ATH");
  gsm.println((char)26);
}
delay(10000);
}
  




