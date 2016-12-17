#include <WaveHC.h>
#include <WaveUtil.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include <LiquidCrystal.h>
#include "ColorUtil.h"

LiquidCrystal lcd(A0, A1, 9, 8, 7, 6);

const int button = A3;

SdReader card;    // This object holds the information for the card
FatVolume vol;    // This holds the information for the partition on the card
FatReader root;   // This holds the information for the volumes root directory
WaveHC wave;      // This is the only wave (audio) object, since we will only play one at a time

Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_700MS, TCS34725_GAIN_1X);

void setupSdReader(SdReader &card) {
  if (!card.init()) Serial.println("Card init failed");
  card.partialBlockRead(true); // Optimization. Disable if having issues
}

void setupFatVolume(FatVolume &vol) {
  uint8_t slot;
  // There are 5 slots to look at.
  for (slot = 0; slot < 5; slot++)
    if (vol.init(card, slot)) break;
  if (slot == 5) Serial.println("No valid FAT partition");
}

void setupFatReader(FatReader &root) {
  if (!root.openRoot(vol)) Serial.println("Can't open root dir");
}

void setupRGBSensor(Adafruit_TCS34725 &tcs) {
  if (!tcs.begin()) Serial.println("No TCS34725 found ... check your connections");
}

void setup() {
  Serial.begin(9600);
  setupSdReader(card);
  setupFatVolume(vol);
  setupFatReader(root);
  setupRGBSensor(tcs);
  lcd.begin(16, 2);
  lcd.clear();
  pinMode(button, INPUT);
}

void play() {
  uint16_t clear, red, green, blue;

  tcs.setInterrupt(false);
  delay(60);
  tcs.getRawData(&red, &green, &blue, &clear);
  tcs.setInterrupt(true);

  uint32_t sum = clear;
  float r, g, b;
  r = red; r /= sum;
  g = green; g /= sum;
  b = blue; b /= sum;
  r *= 256; g *= 256; b *= 256;

  double hsl[3];
  getHSL(hsl, r, g, b);
  Serial.print("r: "); Serial.print((int) r);
  Serial.print(" g: "); Serial.print((int) g);
  Serial.print(" b: "); Serial.print((int) b); Serial.println();
  Serial.print("H: "); Serial.print(hsl[0]);
  Serial.print(" S: "); Serial.print(hsl[1]);
  Serial.print(" L: "); Serial.print(hsl[2]); Serial.println();

  root.rewind();
  FatReader file;

  file.open(root, "MACNTOSH.WAV");
  if (!wave.create(file)) Serial.println("Can't open the file");
  wave.play();
  while(wave.isplaying) delay(100);
}

void loop() {
  int state = digitalRead(button);
  bool pushed = (state == LOW);
  if (pushed) {
    play();
  }

  delay(50);
}
