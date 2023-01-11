void noteOn(byte channel, byte pitch) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, 127};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, 0};
  MidiUSB.sendMIDI(noteOff);
}