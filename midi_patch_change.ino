
#include <MIDI.h>
MIDI_CREATE_DEFAULT_INSTANCE();
byte patchnum = 0;


void setup() {
   
  // put your setup code here, to run once:
pinMode(2, INPUT_PULLUP);
pinMode(3, INPUT_PULLUP);
MIDI.begin(MIDI_CHANNEL_OMNI);
}

void loop() {
  // put your main code here, to run repeatedly:]
  if(digitalRead(3) == LOW && patchnum < 128){
    patchnum++;
    MIDI.sendProgramChange(patchnum,1);
    delay(200);
  }

   if(digitalRead(2) == LOW && patchnum > 0){
    patchnum--;
    MIDI.sendProgramChange(patchnum,1);
    delay(200);
  }

}
