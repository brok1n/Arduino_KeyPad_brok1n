#include <bKeyPad.h>

char keyValue[][4] = { {'1', '2', '3', '+'}, {'4', '5', '6', '-'}, {'7', '8', '9', 'x'}, {'C', '0', '=', '/'} };
int  keyPin[][4] = { { 30, 32, 34, 36 }, { 22, 24, 26, 28}};

Bkeypad keypad;

void setup() {
  // put your setup code here, to run once:
  Serial.begin( 115200 );
  keypad.init( keyValue, keyPin );
}

void loop() {
  // put your main code here, to run repeatedly:
  char ch = keypad.getKey();
  if( ch > -1 )
    Serial.println( ch );
  
}
