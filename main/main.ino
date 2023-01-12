#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "MIDIUSB.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

const int button = 8;                 // 0-Button
const int lever[2] = { 4, 5 };        // L R
const int s[4] = { 15, 14, 16, 10 };  // S0 S1 S2 S3
const int sig = 9;                    // Sig

//0 is curr state, 1 old state
bool faceButtonState[16][2];  //[button][curr old]
bool leverState[2][2];        //[L R][curr old]
bool buttonState;             //pressed is true

//0 is curr state, 1 old state
int activeMenu[2] = { 0, 0 };  // [curr old]
const int maxMenu = 2;

//MIDI globals
int noteOctave = 0;  //
int noteBase = 0;    // 0-C 1-Db 2-D 3-Eb 4-E 5-F 6-Gb 7-G 8-Ab 9-A 10-Bb 11-B
int channel = 0;     // 0 to 15

void setup() {
  for (int i = 0; i < 4; i++) {
    pinMode(s[i], OUTPUT);  //setup S pins
  }
  pinMode(sig, INPUT_PULLUP);       //setup Sig pin
  pinMode(lever[0], INPUT_PULLUP);  //setup lever L
  pinMode(lever[1], INPUT_PULLUP);  //setup lever R
  pinMode(button, INPUT_PULLUP);    //setup radio button

  Serial.begin(9600);                                   //setup Serial bus
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);  //setup SSD1306
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(1, 0);
  display.display();
}

void loop() {
  readFaceButtons();
  readLever();
  readButton();
  if (buttonState) {  // play mode
    switch (activeMenu[0]) {
      case 0:
        mode0();
        break;
      case 1:
        mode1();
        break;
      case 2:
        mode2();
        break;
      default:
        break;
    }
  } else {  // menu mode
    if (leverState[0][0] != leverState[0][1] && leverState[0][0]) {
      if (activeMenu[0] == 0) {
        activeMenu[0] = maxMenu;
      } else {
        activeMenu[0]--;
      }
    } else if (leverState[1][0] != leverState[1][1] && leverState[1][0]) {
      if (activeMenu[0] == maxMenu) {
        activeMenu[0] = 0;
      } else {
        activeMenu[0]++;
      }
    }
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(activeMenu[0]);
    display.display();
  }
}
