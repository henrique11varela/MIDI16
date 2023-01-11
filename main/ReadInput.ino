/* Reads Face Buttons */
void readFaceButtons(){
  for (int i = 0; i < 16; i++) {  //for each output/input pin
    int binary = i;
    for (int j = 0; j < 4; j++) {  //write binary to S pins
      digitalWrite(s[j], (binary % 2 == 1) ? HIGH : LOW);
      binary /= 2;
    }
    faceButtonState[i][1] = faceButtonState[i][0];
    faceButtonState[i][0] = !digitalRead(sig); //read Sig pin
  }
};

void readLever(){
  leverState[0][1] = leverState[0][0];
  leverState[1][1] = leverState[1][0];
  leverState[0][0] = !digitalRead(lever[0]);
  leverState[1][0] = !digitalRead(lever[1]);
};

void readButton(){
  buttonState = digitalRead(button);
};