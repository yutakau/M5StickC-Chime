#include <M5StickC.h>

const int servo_pin = 26;
int freq = 50;
int ledChannel = 0;
int resolution = 10;

// Store-chime melody
const note_t melody[] = {NOTE_Fs,NOTE_D,NOTE_A,NOTE_D,NOTE_E,NOTE_A,NOTE_E,NOTE_Fs,NOTE_E,NOTE_A,NOTE_D };
const unsigned int octave[] = { 3,3,2,3,3,3,3,3,3,2,3};
const unsigned int duration[] = { 4,4,4,4,4,12,4,4,4,4,16};
const unsigned int length = 11;

void setup() {
  M5.begin();
  M5.Lcd.setRotation(3);
  M5.Lcd.setCursor(0, 30, 4);
  M5.Lcd.println("Chime");
  ledcSetup(ledChannel, freq, resolution);
  ledcAttachPin(servo_pin, ledChannel);
  ledcWrite(ledChannel, 256);//0°
  Serial.begin(115200);
}

void playChime(const note_t* melody, const unsigned int* octave, const unsigned int* duration) {  
  Serial.printf("%d\n",length);  
  for(int i = 0; i < length; i++) {      
    ledcWriteNote(ledChannel, melody[i], octave[i]);
    delay(duration[i] * 70);
    ledcWriteTone(ledChannel, 0);
    delay(100);
  } 
}


void loop() {
  //Serial.print("start");
  playChime( melody, octave, duration );
  //Serial.print("fin..");
  while(1) ;

}
