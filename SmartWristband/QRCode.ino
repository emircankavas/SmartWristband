#if (defined(__AVR__))
#include <avr\pgmspace.h>
#else
#include <pgmspace.h>
#endif

const uint8_t colon[] PROGMEM = {
  B00000000,
  B00000000,
  B01100000,
  B11110000,
  B11110000,
  B01100000,
  B00000000,
  B00000000,
  B01100000,
  B11110000,
  B11110000,
  B01100000,
  B00000000,
  B00000000,
};

const byte qrCode48[] PROGMEM = {
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00111111,B11111111,B10000110,B00011001,B11111111,B11111100,
B00111111,B11111111,B10000110,B00011001,B11111111,B11111100,
B00110000,B00000011,B10011000,B01100001,B10000000,B00011100,
B00110000,B00000011,B10011000,B01100001,B10000000,B00001100,
B00110011,B11110011,B10000110,B00000001,B10011111,B11001100,
B00110011,B11110011,B10000110,B00000001,B10011111,B11001100,
B00110011,B11110011,B10011000,B01100001,B10011111,B11001100,
B00110011,B11110011,B10011000,B01100001,B10011111,B11001100,
B00110011,B11110011,B10000001,B11111001,B10011111,B11001100,
B00110011,B11110011,B10000001,B11111001,B10011111,B11001100,
B00110001,B00010011,B10011011,B10111001,B10001000,B10001100,
B00110000,B00000011,B10011111,B10011001,B10000000,B00001100,
B00111111,B11111111,B10011011,B10011001,B11111111,B11111100,
B00111111,B11111111,B10011001,B10011001,B11111111,B11111100,
B00111111,B11111111,B00011001,B10011001,B11111111,B11111000,
B00000000,B00000000,B00000001,B11111000,B00000000,B00000000,
B00000000,B00000000,B00000001,B11111100,B00000010,B00100000,
B00111111,B11110011,B11111110,B00011110,B01100110,B00110000,
B00111111,B11110001,B11111110,B00011110,B01100010,B00100000,
B00111111,B00000000,B01100110,B00011000,B00000001,B11001100,
B00111111,B00000000,B11100110,B00011000,B00000001,B11001100,
B00110000,B11111111,B11100001,B11100000,B00000001,B11110000,
B00110000,B11111111,B11100001,B11100000,B00000001,B11110000,
B00001100,B00110000,B01111000,B00000000,B00011111,B11111100,
B00001100,B00110000,B01111000,B00000000,B00011111,B11111100,
B00110011,B00001111,B11111001,B11100000,B01100001,B11111100,
B00110011,B00001111,B11111001,B11100000,B01100001,B11111100,
B00000000,B00000000,B00111110,B01111111,B10000001,B11011100,
B00000000,B00000000,B00011110,B01111111,B10000001,B11001100,
B00111111,B11111111,B10011000,B00011001,B11100001,B11000000,
B00111111,B11111111,B10011000,B00011001,B11100001,B11000000,
B00110000,B00000011,B10000000,B01111111,B10011111,B11100000,
B00110000,B00000011,B10000000,B01111111,B10011111,B11110000,
B00110011,B11110011,B10011001,B10011000,B01100001,B11000000,
B00110011,B11110011,B10011001,B10011000,B01100001,B11000000,
B00110011,B11110011,B10011001,B10011000,B00000011,B11000000,
B00110011,B11110011,B10011001,B10011000,B00000111,B11000000,
B00110011,B11110011,B10011110,B01100110,B00111000,B00000000,
B00110011,B11110011,B10011110,B01100110,B01111000,B00000000,
B00110011,B11110011,B10011110,B01100110,B00111100,B00000000,
B00110000,B00000011,B10011001,B10000000,B00011111,B11110000,
B00111000,B00000011,B10011001,B11000000,B00111111,B10100000,
B00111111,B11111111,B10011001,B11100110,B01100000,B00000000,
B00111111,B11111111,B00011001,B11100110,B01100000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
B00000000,B00000000,B00000000,B00000000,B00000000,B00000000,
};
