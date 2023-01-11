#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>


#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int encoder[3] = {6, 7, 8};
const int lever[2] = {4, 5}; //L R
const int s[4] = { 15, 14, 16, 10 }; // S0 S1 S2 S3
const int sig = 9; // Sig

bool buttonState[16]; //pressed is true
bool leverState[2]; //pressed is true

//MIDI globals
uint octave = 0;
uint base = 0;
uint channel = 0;

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(s[i], OUTPUT);  //setup S pins
  }
  pinMode(sig, INPUT_PULLUP);  //setup Sig pin
  pinMode(lever[0], INPUT_PULLUP);  //setup lever L
  pinMode(lever[1], INPUT_PULLUP);  //setup lever R
  Serial.begin(9600);  //setup Serial bus
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS); //setup SSD1306
  display.clearDisplay();
  display.display();
}

void loop() {
  readFaceButtons();
  readLever();
  buttonDisplay(0);
}


