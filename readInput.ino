/* Reads Face Buttons */
void readFaceButtons(){
  for (int i = 0; i < 16; i++) {  //for each output/input pin
    int binary = i;
    for (int j = 0; j < 4; j++) {  //write binary to S pins
      digitalWrite(s[j], (binary % 2 == 1) ? HIGH : LOW);
      binary /= 2;
    }
    buttonState[i] = !digitalRead(sig); //read Sig pin
  }
};