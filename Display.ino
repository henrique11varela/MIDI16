/* displays the buttons on screen
*x* is the left most coord, this is 64x64 */
void buttonDisplay(int x) {
  const int buttonCoords[16][2] = {
    { x + 8, 8 },
    { x + 24, 8 },
    { x + 40, 8 },
    { x + 56, 8 },
    { x + 8, 24 },
    { x + 24, 24 },
    { x + 40, 24 },
    { x + 56, 24 },
    { x + 8, 40 },
    { x + 24, 40 },
    { x + 40, 40 },
    { x + 56, 40 },
    { x + 8, 56 },
    { x + 24, 56 },
    { x + 40, 56 },
    { x + 56, 56 }
  };
  display.clearDisplay();
  for (int i = 0; i < 16; i++) {
    if (buttonState[i]) {
      display.fillCircle(buttonCoords[i][0], buttonCoords[i][1], 5, 1);
    } else {
      display.drawCircle(buttonCoords[i][0], buttonCoords[i][1], 5, 1);
    }
  }
  display.display();
};
