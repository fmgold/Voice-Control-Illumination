#include <Arduino.h>
#include <WiFi.h>
#include <Firebase_ESP_Client.h>

#include <addons/TokenHelper.h>
#include <addons/RTDBHelper.h>

#define WIFI_SSID "user"             // input your home or public wifi name
#define WIFI_PASSWORD "****"                                    //password of wifi ssid

/* 2. Define the API Key */
#define API_KEY ""
//-----------------------------------------------------------------------
/* 3. Define the RTDB URL */
#define DATABASE_URL ""
//-----------------------------------------------------------------------

FirebaseJson jsonData;
FirebaseData fbdo;

FirebaseAuth auth;
FirebaseConfig config;

bool signupOK = false;

const int ledPin = 17;  // 16 corresponds to GPIO16

// setting PWM properties
const int freq = 5000;
const int ledChannel = 0;
const int resolution = 8;


void setup() {
  Serial.begin(115200);
  // configure LED PWM functionalitites
  ledcSetup(ledChannel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(ledPin, ledChannel);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                      //try to connect with wifi
  Serial.print("Connecting to ");
  Serial.print(WIFI_SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  //-----------------------------------------------------------------------
  Serial.printf("Firebase Client v%s\n\n", FIREBASE_CLIENT_VERSION);

  /* Assign the api key (required) */
  config.api_key = API_KEY;

  /* Assign the RTDB URL (required) */
  config.database_url = DATABASE_URL;

  /* Assign the callback function for the long running token generation task */
  config.token_status_callback = tokenStatusCallback; //see addons/TokenHelper.h
  //-----------------------------------------------------------------------
  /*Or Sign up */
  if (Firebase.signUp(&config, &auth, "", "")) {
    Serial.println("Firebase signUp ok");
    signupOK = true;
  }
  else {
    Serial.printf("%s\n", config.signer.signupError.message.c_str());
  }
  Firebase.begin(&config, &auth);
  Firebase.reconnectWiFi(true);
  delay(1000);
  ledcWrite(ledChannel, 0);
  delay(2000);
  ledcWrite(ledChannel, 63);
  delay(2000);
  ledcWrite(ledChannel, 100);
  delay(2000);
  ledcWrite(ledChannel, 205);
  delay(2000);
}

void loop() {

  Firebase.RTDB.getString(&fbdo, "/Speech/voice");
  //Firebase.RTDB.getString(&fbdo, "/FinalWeight");
  String str = fbdo.to<String>();
  str.remove(0, 2);
  int a = str.length();
  str.remove(a - 2, 2);
  Serial.println(str);
  if (str == "bright" || str == "BRIGHT" ) {
    Serial.println("HIGH ACTIVATED");
    ledcWrite(ledChannel, 200);
  }
  if (str == "mid" || str == "MID" ) {
    Serial.println("MID ACTIVATED");
    ledcWrite(ledChannel, 100);
  }
  if (str == "low" || str == "LOW" ) {
    Serial.println("LOW ACTIVATED");
    ledcWrite(ledChannel, 63);
  }
  if (str == "off" || str == "OFF" ) {
    Serial.println("LOW ACTIVATED");
    ledcWrite(ledChannel, 0);
  }




}
