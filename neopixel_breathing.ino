#include "Adafruit_NeoPixel.h"
#include "stdlib.h"
#include "time.h"

Adafruit_NeoPixel pixels(8, D1, NEO_GRB+NEO_KHZ800);
uint8_t r, g, b, j;  // j是亮度

void setAllColor() {
    for(int i=0; i<8; i++) {
        pixels.setPixelColor(i, r*j/255, g*j/255, b*j/255);
    }
    pixels.show();
}

void setup(){
    srand(time(NULL));
    pixels.begin();
}

void loop() {
    r = rand() % 256;
    g = rand() % 256;
    b = rand() % 256;

    for(j=1; j<=254; j++) {
        setAllColor();
        delay(5);
    }
    for(j=255; j>=2; j--) {
        setAllColor();
        delay(5);
    }
}
