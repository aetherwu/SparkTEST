/*
  Send-a-Tweet
  
  Based on kid-summoner.ino by Jen Looper
  Additions and edits by Anouska de Graaf - www.anouskadegraaf.nl
  
*/
 
int val1 = 0; //variable for push-button status scenario 1

const char * SAT1 = "";
const char * serverName = "api.pushingbox.com";   // Pushingbox API URL
 
TCPClient client;
 
void setup() {
    pinMode(D1, INPUT);
    Serial.begin(9600);
    Serial.println("Serial open");
}
 
 
void loop() {
    val1 = digitalRead(D1); //read the state of the push-button
    
    if (val1 == LOW) { //if push-button pressed
        delay(250); //primitive button debounce
        Serial.println("button pushed!"+Time.now());
        sendToPushingBox(SAT1);
    }
}
 
void sendToPushingBox(const char * devid)
{
    Serial.println("Start sendToPushingBox");
    client.stop();
    if (client.connect(serverName, 80)) {
        client.print("GET /pushingbox?devid=");
        client.print(devid);
        client.println(" HTTP/1.1");
        client.print("Host: ");
        client.println(serverName);
        client.println("User-Agent: Spark");
        client.println();
        client.flush();
    }
    else{
        Serial.println("connection failed");
    }
}