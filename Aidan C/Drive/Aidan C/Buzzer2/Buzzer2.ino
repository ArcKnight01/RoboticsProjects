#include <stdlib.h>
#include <unistd.h>
#define C5  523
#define CS5 554
#define D5  587
#define DS5 622
#define E5  659
#define F5  698
#define FS5 740
#define G5  784
#define GS5 831
#define A5_  880
#define AS5 932
#define B5  988
#define C6  1047

int buzzer = 10;
int mosquito = 17000;
float sounds[] = {16.35, 17.32, 18.35, 19.45, 20.60, 21.83, 23.12, 24.50, 25.96, 27.50, 29.14, 30.87, 32.70, 34.65, 36.71, 38.89, 41.20, 43.65, 46.25, 49.00, 51.91, 55.00, 58.27, 61.74, 65.41, 69.30, 73.42, 77.78, 82.41, 87.31, 92.50, 98.00, 103.83,  110.00, 116.54, 123.47, 130.81, 138.59, 146.83,  155.56, 164.81, 174.61, 185.00, 196.00, 207.65, 220.00, 233.08, 246.94, 261.63, 277.18, 293.66, 311.13, 329.63, 349.23, 369.99, 392.00, 415.30, 440.00, 466.16, 493.88, 523.25, 554.37, 587.33, 622.25, 659.25, 698.46, 739.99, 783.99, 830.61, 880.00, 932.33, 987.77, 1046.50, 1108.73, 1174.66, 1244.51, 1318.51, 1396.91, 1479.98, 1567.98, 1661.22, 1760.00, 1864.66, 1975.53, 2093.00, 2217.46, 2349.32, 2489.02, 2637.02, 2793.83, 2959.96, 3135.96, 3322.44, 3520.00, 3729.31, 3951.07, 4186.01, 4434.92, 4698.63, 4978.03, 5274.04, 5587.65, 5919.91,  6271.93, 6644.88, 7040.00, 7458.62, 7902.13};
int arraySize = sizeof(sounds);
//float C0, CS0_Db0, D0, DS0_Eb0, E0, F0, FS0_Gb0, G0, GS0_Ab0, A0_, AS0_Bb0, B0, C1, CS1_Db1, D1, DS1_Eb1, E1, F1, FS1_Gb1, G1, GS1_Ab1, A1_, AS1_Bb1, B1, C2, CS2_Db2, D2, DS2_Eb2, E2, F2, FS2_Gb2, G2, GS2_Ab2, A2_, AS2_Bb2, B2, C3, CS3_Db3, D3, DS3_Eb3, E3, F3, FS3_Gb3, G3, GS3_Ab3, A3_, AS3_Bb3, B3, C4, CS4_Db4, D4, DS4_Eb4, E4, F4, FS4_Gb4, G4, GS4_Ab4, A4_, AS4_Bb4, B4, C5, CS5_Db5, D5, DS5_Eb5, E5, F5, FS5_Gb5, G5, GS5_Ab5, A5_, AS5_Bb5, B5, C6, CS6_Db6, D6, DS6_Eb6, E6, F6, FS6_Gb6, G6, GS6_Ab6, A6, AS6_Bb6, B6, C7, CS7_Db7, D7, DS7_Eb7, E7, F7, FS7_Gb7, G7, GS7_Ab7, A7, AS7_Bb7, B7, C8, CS8_Db8, D8, DS8_Eb8, E8, F8, FS8_Gb8, G8, GS8_Ab8, A8, AS8_Bb8, B8;
//float note[] = {C0, CS0_Db0, D0, DS0_Eb0, E0, F0, FS0_Gb0, G0, GS0_Ab0, A0_, AS0_Bb0, B0, C1, CS1_Db1, D1, DS1_Eb1, E1, F1, FS1_Gb1, G1, GS1_Ab1, A1_, AS1_Bb1, B1, C2, CS2_Db2, D2, DS2_Eb2, E2, F2, FS2_Gb2, G2, GS2_Ab2, A2_, AS2_Bb2, B2, C3, CS3_Db3, D3, DS3_Eb3, E3, F3, FS3_Gb3, G3, GS3_Ab3, A3_, AS3_Bb3, B3, C4, CS4_Db4, D4, DS4_Eb4, E4, F4, FS4_Gb4, G4, GS4_Ab4, A4_, AS4_Bb4, B4, C5, CS5_Db5, D5, DS5_Eb5, E5, F5, FS5_Gb5, G5, GS5_Ab5, A5_, AS5_Bb5, B5, C6, CS6_Db6, D6, DS6_Eb6, E6, F6, FS6_Gb6, G6, GS6_Ab6, A6, AS6_Bb6, B6, C7, CS7_Db7, D7, DS7_Eb7, E7, F7, FS7_Gb7, G7, GS7_Ab7, A7, AS7_Bb7, B7, C8, CS8_Db8, D8, DS8_Eb8, E8, F8, FS8_Gb8, G8, GS8_Ab8, A8, AS8_Bb8, B8};
/*
void noteFrequency(){
  for(int i = 0; i <= arraySize; i++){
//    note[i] = sounds[i];
  }
}
*/

void setup() {
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
  Serial.println("press any button to begin");
}
void buzz(int note){
  tone(buzzer, note, 500);
  delay(100);
}
/*void music(){
  song[]={C0, A0_, B8, G7};
  lengthSong = sizeof(song);
  for(int j = 0; j<= lengthSong; song++){
  buzz(song[j]);
  }
  delay(10000);
}
*/
void loop() {
  if (Serial.available() > 0) { //check to see if serial is available

      int keyboard = Serial.read(); //serial reads user input

  switch (keyboard) {
      case '1':
        Serial.println("C");
        tone(buzzer, C5, 250);
        break;
      case '2':
        Serial.println("D");
        tone(buzzer, D5, 250);
        break;
      case '3':
        Serial.println("E");
        tone(buzzer, E5, 250);
        break;
      case '4':
        Serial.println("F");
        tone(buzzer, F5, 250);
        break;
      case '5':
        Serial.println("G");
        tone(buzzer, G5, 250);
        break;
      case '6':
        Serial.println("A");
        tone(buzzer, A5_, 250);
        break;
      case '7':
        Serial.println("B");
        tone(buzzer, B5, 250);
        break;
      case '8':
        Serial.println("C");
        tone(buzzer, C6, 250);
        break;
    }
  //music();
  }
}

  
/*
int array[] = {15, 50, 34, 20, 10, 79, 100};
int n;
n = sizeof(array);
printf("Size of the given array is %d\n", n_sizeof(int));
return 0;

song[]={a4, c4,d, e};
lengthSong = sizeof(song);
for(int j =0; j<= lengthSong; song++){
  buzz(song[j]);
}

//
int a1, a2, a3, a4;
note[] = {a1, a2, a3, a4};
*/
