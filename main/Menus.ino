void mode0() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Mode\n0");
  display.display();
}

void mode1() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Mode\n1");
  display.display();
}

void mode2() {
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print("Debug\nMode");
  buttonDisplay(64);
  leverDisplay(0, 48);
  display.display();
}