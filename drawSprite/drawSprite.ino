/*
  DEMO: draw Sprite

  TEAM a.r.g.: http://www.team-arg.com/demos.html

  2015 - JO3RI

  Demo License: MIT : https://opensource.org/licenses/MIT

*/

#include "Arglib.h"
#include "bitmaps.h"

Arduboy arduboy;
Sprites sprites(arduboy);
byte frame = 0;

void setup()
{
  arduboy.start();
  arduboy.setFrameRate(30);
  arduboy.clearDisplay();
  arduboy.display();
  arduboy.drawBitmap(0, 8, TEAMarg, 128, 48, WHITE);
  arduboy.display();
  delay(1500);
}
void loop() {
  if (!(arduboy.nextFrame())) return;
  arduboy.clearDisplay();
  sprites.drawSelfMasked(20, 0, face_bitmap, frame);
  if (arduboy.everyXFrames(3)) frame++;
  if (frame > 11)frame = 0;
  arduboy.display();
}
