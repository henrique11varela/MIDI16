#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int s[4] = { 15, 14, 16, 10 };
const int sig = 9;

bool buttonState[16]; //pressed is true

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(s[i], OUTPUT);  //setup S pins
  }
  pinMode(sig, INPUT_PULLUP);  //setup Sig pin
  Serial.begin(9600);  //setup Serial bus
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS); //setup SSD1306
  display.clearDisplay();
  display.display();
}

void loop() {
  readFaceButtons();
  buttonDisplay(0);
}
