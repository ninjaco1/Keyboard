/*******************************************************************
*
*
*
*
*
*
*
*
*

 *******************************************************************/

// ----------------------------
// Standard Libraries
// ----------------------------

#include "Keyboard.h"
#include <Keypad.h>
#include <string.h>

// define



const byte ROWS = 5; //four rows
const byte COLS = 13; //four columns

// https://www.arduino.cc/en/Reference/KeyboardModifiers

// the library will return the character inside this array
// when the appropriate button is pressed.
char keys[ROWS][COLS] = {
    {KEY_ESC, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '+'},
    {KEY_TAB, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']'},
    {KEY_CAPS_LOCK,'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', KEY_RETURN},
    {KEY_LEFT_SHIFT, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', KEY_RIGHT_SHIFT, ''},
    {KEY_LEFT_CTRL, KEY_LEFT_GUI , KEY_LEFT_ALT, '\\', KEY_BACKSPACE, '', ' ', '', '', KEY_RIGHT_ALT, KEY_RIGHT_GUI, '', KEY_RIGHT_CTRL}
};

byte rowPins[ROWS] = {0, 1, 2, 3, 4}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 6, 7, 8, 9, 10, 14, 15, 16, 18, 19, 20, 21}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

void setup()
{
  Serial.begin(9600);
  Keyboard.begin();
}

// // This will hold down all the following buttons.
// void sendMacroCommand(uint8_t key)
// {
//   Keyboard.press(KEY_LEFT_CTRL);
//   Keyboard.press(KEY_LEFT_SHIFT);
//   Keyboard.press(KEY_LEFT_ALT);
//   Keyboard.press(key);
// }

void loop()
{
  char key = keypad.getKey();

  if (key)
  {
    switch (key)
    {
    case '1':
      // sendMacroCommand(KEY_F1);
      Keyboard.press('1');
      break;
    case '2':
      // sendMacroCommand(KEY_F2);
      break;
    case '3':
      // sendMacroCommand(KEY_F3);
      break;
    case '4':
      // sendMacroCommand(KEY_F4);
      break;
    case '5':
      // sendMacroCommand(KEY_F5);
      break;
    case '6':
      // sendMacroCommand(KEY_F6);
      break;
    case '7':
      // sendMacroCommand(KEY_F7);
      break;
    case '8':
      // sendMacroCommand(KEY_F8);
      break;
    case '9':
      // sendMacroCommand(KEY_F9);
      break;
    case '0':
      // sendMacroCommand(KEY_F10);
      break;
    case '*':
      // sendMacroCommand(KEY_F11);
      break;
    case '#':
      // sendMacroCommand(KEY_F12);
      break;
    case 'A':
      // sendMacroCommand('a');
      break;
    case 'B':
      // sendMacroCommand('b');
      break;
    case 'C':
      // sendMacroCommand('c');
      break;
    case 'D':
      // sendMacroCommand('d');
      break;
    }
    Serial.println(key);

    // delay(100);
    Keyboard.releaseAll(); // this releases the buttons
  }
}