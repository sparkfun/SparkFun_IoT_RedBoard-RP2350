#include <WiFi.h>
#include <ArduinoJson.h>
#include <FastLED.h>
#include <cstdint>

// WiFi variables
#ifndef STASSID
#define STASSID "SSID"
#define STAPSK  "PASSWORD"
#endif // !STASSID

const char* ssid = STASSID;
const char* password = STAPSK;

const char* host = "corquaid.github.io";
const uint16_t port = 443;

WiFiMulti multi;

// LED variables
#define NUM_LEDS 1
#define DATA_PIN PIN_NEOPIXEL
#define LED_TYPE WS2812
#define COLOR_ORDER GRB
#define LED_BRIGHTNESS 30

CRGB leds[NUM_LEDS];

void setup() {
    Serial.begin(115200);

    // Uncomment to wait for serial monitor
    // while(!Serial) { delay(100);};

    // Setup RGB LED.
    FastLED.addLeds<LED_TYPE, DATA_PIN, COLOR_ORDER>(leds, NUM_LEDS);
    FastLED.setBrightness(LED_BRIGHTNESS);

    // Set the LED Red while connecting to WiFi.
    FastLED.showColor(CRGB::Red);

    Serial.print("Connecting to ");
    Serial.println(ssid);

    // Connect to a WiFi network.
    multi.addAP(ssid, password);

    if(multi.run() != WL_CONNECTED) {
        Serial.println(F("Unable to connect to network, rebooting in 10 seconds..."));
        delay(10000);
        rp2040.reboot();
    }

    Serial.println(F("Connected to network"));
    Serial.println(F("IP address: "));
    Serial.println(WiFi.localIP());

    // Create a WiFi clent. It has to be a "secure" client because the server we are connecting to uses HTTPS.
    BearSSL::WiFiClientSecure client;
    client.setTimeout(10000);
    // Doesn't validate the chain, just accept whatever is given. VERY INSECURE!
    client.setInsecure();
    // Connect to server.
    if(!client.connect(host, port)) {
        Serial.println(F("Connection failed"));
        delay(5000);
        return;
    }

    Serial.println(F("Connected!"));

    // Set the LED to blue while downloading data.
    FastLED.showColor(CRGB::Blue);

    Serial.println(F("Downloading list of astronauts currently in space..."));
    
    // Send HTTP GET request
    client.println(F("GET /international-space-station-APIs/JSON/people-in-space.json HTTP/1.0"));
    client.println(F("Host: corquaid.github.io"));
    client.println(F("Connection: close"));
    
    if(client.println() == 0) {
        Serial.println(F("Failed to send request"));
        client.stop();
        return;
    }

    // Check HTTP status
    char status[32] = {0};
    client.readBytesUntil('\r', status, sizeof(status));
    if(strncmp(status + 9, "200 OK", sizeof(status)) != 0) {
        Serial.print(F("Unexpected response: "));
        Serial.println(status);
        client.stop();
        return;
    }

    // Skip HTTP headers
    const char endOfHeaders[] = "\r\n\r\n";
    if(!client.find(endOfHeaders)) {
        Serial.println(F("Invalid response"));
        client.stop();
        return;
    }

    // Parse JSON
    JsonDocument doc;
    DeserializationError error = deserializeJson(doc, client);
    if(error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        client.stop();
        return;
    }

    // Print number of astronauts in space and their names.
    int numberOfPeople = doc[F("number")];

    Serial.print(F("There are "));
    Serial.print(numberOfPeople);
    Serial.println(F(" astronauts in space."));

    for(JsonObject people_item : doc[F("people")].as<JsonArray>()) {
        int people_item_id = people_item[F("id")];
        const char* people_item_name = people_item[F("name")];
        Serial.print(people_item_id);
        Serial.print(F(": "));
        Serial.println(people_item_name);
    }

    // Set the LED to green to indicate success.
    FastLED.showColor(CRGB::Green);
}

void loop() {}
