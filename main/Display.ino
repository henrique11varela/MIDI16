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
  for (int i = 0; i < 16; i++) {
    if (faceButtonState[i][0]) {
      display.fillCircle(buttonCoords[i][0], buttonCoords[i][1], 5, 1);
    } else {
      display.drawCircle(buttonCoords[i][0], buttonCoords[i][1], 5, 1);
    }
  }
};

void leverDisplay(int x, int y) {
  display.drawFastHLine(x, y + 15, 16, 1);
  if (!leverState[0][0] && !leverState[1][0]) {
    display.drawFastVLine(x + 8, y, 16, 1);
    return;
  }
  if (leverState[0][0]) {
    display.drawLine(x, y, x + 8, y + 15, 1);
    return;
  }
  if (leverState[1][0]) {
    display.drawLine(x + 15, y, x + 8, y + 15, 1);
    return;
  }
};





