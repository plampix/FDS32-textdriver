#include "fds132text.h"

fdsScreen::fdsScreen() {
  first = NULL; //make sure it's a null pointer
}

void fdsScreen::setPins() {
#if defined (ESP8266)
  setPins(D5, D7, D2, 1000);
#else
  setPins(13, 11, 8, 1000);
#endif
}

void fdsScreen::setPins(int p_clockPin, int p_dataPin, int p_boardEnable, int p_displayTimeRow) {
  clockPin  = p_clockPin;
  dataPin = p_dataPin;
  boardEnable = p_boardEnable;
  displayTimeRow = p_displayTimeRow;
  pinMode (clockPin, OUTPUT);
  pinMode (dataPin, OUTPUT);
  pinMode(boardEnable, OUTPUT);
  digitalWrite(boardEnable, LOW); // LOw if using transistor
  SPI.begin();  // start the SPI library
#if defined (ESP8266)
  SPI.setFrequency(1000000);
#endif
  SPI.setClockDivider(SPI_CLOCK_DIV2);
  SPI.setBitOrder(MSBFIRST);  //Code was written for this bit Order
  SPI.setDataMode(SPI_MODE2);
}

// Takes a C-style string and puts it in the list of fdsStrings
fdsString* fdsScreen::addString(char initialValue[], int position) {
  fdsString* newString;
  newString = (fdsString*) malloc(sizeof(class fdsString));
  newString -> startLocation = position;

  placeString(newString);

  newString -> firstNode = 0;
  newString -> set(initialValue);
  return newString;
}

// Takes a C++ String and puts it in the list of fdsStrings
fdsString* fdsScreen::addString(String initialValue, int position) {
  char chararray[initialValue.length()];
  initialValue.toCharArray(chararray, initialValue.length());
  addString(chararray, position);
}

// Takes a fdsChar and puts it in the list of fdsStrings
fdsString* fdsScreen::addString(fdsChar *value, int position) {
  fdsString* newString;
  newString = (fdsString*) malloc(sizeof(class fdsString));
  newString -> startLocation = position;

  placeString(newString);

  newString -> firstNode = 0;
  newString -> set(value);
  return newString;
}

// Place the string in the right location
void fdsScreen::placeString(fdsString* theString) {
  int position = theString -> startLocation;

  if (first == 0) { //if there is no string yet
    first = theString;
    theString -> next = 0;
  }
  else { // If there is already a string
    fdsString* stringNavigator = first;

    // Find the place where the string should be, as the strings should be ordered by position
    while ((stringNavigator -> next != 0) //The loop should quit if there is no next item, in which case theString should be last
           && (((stringNavigator -> next) -> startLocation) < position)) // also if the next item has a bigger start position,
      // so we found the right position
    {
      stringNavigator = stringNavigator -> next;
    }

    theString -> next = stringNavigator -> next;
    stringNavigator -> next = theString;
  }
}

// Set this string to the C-style string supplied
// If there is already a string it will be overwritten
void fdsString::set(char value[]) {
  if (firstNode == 0) { // If there is no string make a node for the fist character
    firstNode = (fdsStringNode*) malloc(sizeof(fdsStringNode));
    firstNode -> next = 0;
  }
  lastNode = firstNode -> set(value);
}

// Set a string to a character
void fdsString::set(fdsChar *value) {
  if (firstNode == 0) { // If there is no string make a node for the fist character
    firstNode = (fdsStringNode*) malloc(sizeof(fdsStringNode));
    firstNode -> next = 0;
  }
  lastNode = firstNode -> set(value);
}

void fdsString::set(String value) {
  set((char*) value.c_str());
}

// Outputs the point where this string should stop displaying.
// Either the end of the screen or the start of the next string
int fdsString::nextStart() {
  if (next == 0) {
    return 271;
  }
  return (next -> startLocation);
}

// Chage the output array to what's currently in the strings
void fdsScreen::update() {
  fdsString *current = first; // pointer to the string we are converting into our output right now
  clear();
  while (current != 0) { // if we still have at least one string to go
    // put it on the buffer starting at it's start
    updateFromfdsStringNode(current -> firstNode, current -> startLocation, current -> nextStart());
    current = current -> next;
  }
}

void fdsScreen::clear() {
  //clear the output
  memset(output, 0, sizeof(output[0][0]) * 35 * 7);
}

void fdsScreen::updateFromfdsStringNode(fdsStringNode *current, int currentbit, int endbit) {
  fdsChar *currentValue = 0; // Pointer to the Character object current is pointing to.
  byte b; //The bits that we are currently inserting into the array.
  while (true) {
    if (current == 0) {
      break; // We should end if we have reached the end of the string (last stringnode)
    }
    if (currentbit > endbit) {
      break; // We should end if we have reached the end of the bit
    }

    // set b to the byte that cointains (at the end) the bits needed to display this part of the current character
    currentValue = (*current).value;
    for (int row = 0; row < 7; row++) {
      b = currentValue -> character_map[row];

      // integer division in C always rounds down, so currentbit/8 gives us the right byte to write to
      // To this byte we want to add the bits in b, and not change the ones that are already there.
      // Bitwise or "|" lets us do this
      // currentbit % 8 gives us a number from 0 to 7 indicating how many bits in the byte we have already used
      // So we want to shift b that many spaces to the left using <<
      output[row][currentbit / 8] = output[row][currentbit / 8] | (b << (currentbit % 8));

      // Now that last shift may have shifted some of the bits off the byte, so we need to put them on the next one.
      // if these bits exist, then shifting b to the right will give us exactly those bits, no more, and put them
      // on the right side of the byte, just where we want them.
      output[row][(currentbit / 8) + 1] = output[row][(currentbit / 8) + 1] | (b >> (8 - (currentbit % 8)));
    }
    // shift our address to the location for the next character
    currentbit += currentValue -> width;
    // and load our next character
    current = current -> next;
  }
  // clean up what is left over after the endbit
  for (int row = 0; row < 7; row++) {
    // Make sure the byte after the endbit is empty
    output[row][(endbit / 8) + 1] = 0;
    output[row][endbit / 8] = output[row][endbit / 8] & (B11111111 >> (8 - (endbit % 8)));

  }
}

void fdsScreen::zeroDisplay() //Clear the display
{
  for (int i = 0; i < 34; i++)
  {
    SPI.transfer(0);
  }
}

void fdsScreen::display(bool inverted) //Display the current fdsScreen::output array
{
  for (int row = 0; row < 7; row++) // The screen can only display one line at a time,
    // We can make it look like it can write them all by writing quickly
  {
#if defined (ESP8266)
    for (int i = 0; i < 34; i++)
      spi_output[i] = output[row][33 - i];
    SPI.writeBytes(spi_output, 34);
#else
    for (int i = 34; i >= 0; i--) {
      if (inverted)
        SPI.transfer(~output[row][i]);
      else
        SPI.transfer(output[row][i]);
    };
#endif
    setRow(row);
    delayMicroseconds(displayTimeRow);         // pause, because otherwise it will update too quickly
    //  setRow(-1);
  }
  setRow(-1); // every line gets displayed as long as every other
}

void fdsScreen::display()
{
  display(false);
}
// The LED screen only shows 1 (out of 7) rows at a time. This activates the row
// (The full screen is shown by quickly alternating between these)
void fdsScreen::setRow (int row)
{
  switch (row) {
    case -1:
      SPI.transfer(0);
      break;
    case 0:
      SPI.transfer(B10000000);
      break;
    case 1:
      SPI.transfer(B01000000);
      break;
    case 2:
      SPI.transfer(B11000000);
      break;
    case 3:
      SPI.transfer(B00100000);
      break;
    case 4:
      SPI.transfer(B10100000);
      break;
    case 5:
      SPI.transfer(B01100000);
      break;
    case 6:
      SPI.transfer(B11100000);
      break;
  }
}

// Set the value of this node to the first character in the array
// Then do the rest of the nodes recursively
fdsStringNode* fdsStringNode::set(char *newValue) {
  value = charTofdsChar(*newValue);

  if (*(newValue + sizeof(char)) == 0) { // C-strings are null teminated. If the next character is 0 this
    // is the end of the string.
    setEnd();
    return this;
  }
  if (next == NULL) { // make more memory availible for the next bit of the string
    next = (fdsStringNode*) malloc(sizeof(fdsStringNode));
    next -> next = NULL;
  }
  return next -> set(newValue + sizeof(char));
}

// Set a node to a character, and make that node the last one
fdsStringNode* fdsStringNode::set(fdsChar *newValue) {
  value = newValue;

  //We know it's only one value long, so we can just end it here
  setEnd();
  return this;
}

// Free the memory used by the rest of the string and NULL the pointer
void fdsStringNode::setEnd() {
  if (next == NULL) {
    return;
  }

  next -> setEnd();
  free(next);
  next = NULL;
}

String fdsScreen::dump()
{
  String d = "";
  for (int row = 0; row < 21; row++)
  {
    for (int i = 0 + ((row / 7) * 90); i < 90 + ((row / 7) * 90); i++)
    {
      d += (output[row % 7][i / 8] & (1 << i % 8) ? "O" : " ");
    }
    d += "\n";
  }
  return d;
}

void fdsScreen::wipe(int duration, int direction)
{
  unsigned long start;
  if (direction == 0)
  {
    for (int row = 0; row < 7; row++)
    {
      start = millis();
      for (int i = 0; i <= 34; i++)
      {
        output[row][i] = 0;
      }
      while (millis() - start < duration / 7)
      {
        display();
      }
    }
  }
  if (direction == 1)
  {
    for (int row = 7; row >= 0; row--)
    {
      start = millis();
      for (int i = 0; i <= 34; i++)
      {
        output[row][i] = 0;
      }
      while (millis() - start < duration / 7)
      {
        display();
      }
    }
  }
  if (direction == 2)
  {
    for (int i = 0; i < 90; i++)
    {
      start = millis();
      for (int row = 0; row < 7; row++)
      {
        for (int x = i; x < 270; x += 90)
        {
          output[row][x / 8] &= ~round(pow(2, x % 8));
        }
      }
      while (millis() - start < duration / 90)
      {
        display();
      }
    }
  }
  if (direction == 3)
  {
    for (int i = 89; i >= 0; i--)
    {
      start = millis();
      for (int row = 0; row < 7; row++)
      {
        for (int x = i; x < 270; x += 90)
        {
          output[row][x / 8] &= ~round(pow(2, x % 8));
        }
      }
      while (millis() - start < duration / 90)
      {
        display();
      }
    }
  }
}

void fdsScreen::pacman(int duration, char padstring[])
{
  for (int i = 0; i <= 270; i += 2)
  {
    addString(padstring, i);
    update();
    //   dump();
    display();
  }
  addString("~FIN~", 0);
}

void fdsScreen::blink(int duration, int times)
{
  unsigned long start = millis();
  for (int i = 1; i <= times; i++)
  {
    zeroDisplay();
    delay((duration / times) / 2);
    while (millis() - start < (i * (duration / times)))
    {
      display();
    }
  }
}

void fdsScreen::flash(int duration, int invertedTime, int times)
{
  if (invertedTime > 500)
    invertedTime = 500;
  unsigned long start = millis();
  bool inverted = false;
  for (int i = 1; i <= times; i++)
  {
    while (millis() - start < (i * (duration / times)) - invertedTime)
      display();
    while (millis() - start < (i * (duration / times)))
      display(true);
  }
}
void fdsScreen::setScore(int home, int away, int reset)
{
  if (reset)
    clear();
  else
  {
    clearDigit(0);
    clearDigit(1);
    clearDigit(3);
    clearDigit(4);
  }
  if (home >= 10)
  {
    drawDigit(home / 10, 0);
    drawDigit(home % 10, 1);
  }
  else
    drawDigit(home, 1);
  draw7segmentpart('g', 2);
  if (away >= 10)
  {
    drawDigit(away / 10, 3);
    drawDigit(away % 10, 4);
  }
  else
    drawDigit(away, 3);
}

void fdsScreen::draw7segmentpart(char part, int position)
{
  position *= 2; // segments are two bytes wide
  switch (part)
  {
    case 'a':
      output[0][position]      |= B11110000;
      output[1][position]      |= B11111000;
      output[2][position]      |= B11110000;
      output[0][position + 1]  |= B00001111;
      output[1][position + 1]  |= B00011111;
      output[2][position + 1]  |= B00001111;
      break;
    case 'b':
      output[2][position + 1]  |= B00100000;
      output[3][position + 1]  |= B01110000;
      output[4][position + 1]  |= B01110000;
      output[5][position + 1]  |= B01110000;
      output[6][position + 1]  |= B01110000;
      output[0][position + 12] |= B11000000;
      output[1][position + 12] |= B11000000;
      output[2][position + 12] |= B10000000;
      output[0][position + 13] |= B00000001;
      output[1][position + 13] |= B00000001;
      break;
    case 'c':
      output[4][position + 12] |= B10000000;
      output[5][position + 12] |= B11000000;
      output[6][position + 12] |= B11000000;
      output[5][position + 13] |= B00000001;
      output[6][position + 13] |= B00000001;
      output[0][position + 24] |= B00000111;
      output[1][position + 24] |= B00000111;
      output[2][position + 24] |= B00000111;
      output[3][position + 24] |= B00000111;
      output[4][position + 24] |= B00000010;
      break;
    case 'd':
      output[5][position + 22] |= B10000000;
      output[4][position + 23] |= B11111111;
      output[5][position + 23] |= B11111111;
      output[6][position + 23] |= B11111111;
      output[5][position + 24] |= B00000001;
      break;
    case 'e':
      output[4][position + 11] |= B00010000;
      output[5][position + 11] |= B00111000;
      output[6][position + 11] |= B00111000;
      output[0][position + 22] |= B11100000;
      output[1][position + 22] |= B11100000;
      output[2][position + 22] |= B11100000;
      output[3][position + 22] |= B11100000;
      output[4][position + 22] |= B01000000;
      break;
    case 'f':
      output[2][position]      |= B00000100;
      output[3][position]      |= B00001110;
      output[4][position]      |= B00001110;
      output[5][position]      |= B00001110;
      output[6][position]      |= B00001110;
      output[0][position + 11] |= B00111000;
      output[1][position + 11] |= B00111000;
      output[2][position + 11] |= B00010000;
      break;
    case 'g':
      output[2][position + 11] |= B11000000;
      output[3][position + 11] |= B11100000;
      output[4][position + 11] |= B11000000;
      output[2][position + 12] |= B00111111;
      output[3][position + 12] |= B01111111;
      output[4][position + 12] |= B00111111;
      break;
  }
}

void fdsScreen::clearDigit(int position)
{
  position *= 2;
  for (int i = 0; i < 7; i++)
  {
    output[i][position] = 0;
    output[i][position + 1] = 0;
    output[i][position + 11] &= B00000111;
    output[i][position + 12] = 0;
    output[i][position + 13] &= B11111110;
    output[i][position + 22] &= B00011111;
    output[i][position + 23] = 0;
    output[i][position + 24] &= B11111000;
  }
}

void fdsScreen::drawDigit(int digit, int position)
{
  switch (digit)
  {
    case 0:
      draw7segmentpart('a', position);
      draw7segmentpart('b', position);
      draw7segmentpart('c', position);
      draw7segmentpart('d', position);
      draw7segmentpart('e', position);
      draw7segmentpart('f', position);
      break;
    case 1:
      draw7segmentpart('b', position);
      draw7segmentpart('c', position);
      break;
    case 2:
      draw7segmentpart('a', position);
      draw7segmentpart('b', position);
      draw7segmentpart('d', position);
      draw7segmentpart('e', position);
      draw7segmentpart('g', position);
      break;
    case 3:
      draw7segmentpart('a', position);
      draw7segmentpart('b', position);
      draw7segmentpart('c', position);
      draw7segmentpart('d', position);
      draw7segmentpart('g', position);
      break;
    case 4:
      draw7segmentpart('b', position);
      draw7segmentpart('c', position);
      draw7segmentpart('f', position);
      draw7segmentpart('g', position);
      break;
    case 5:
      draw7segmentpart('a', position);
      draw7segmentpart('c', position);
      draw7segmentpart('d', position);
      draw7segmentpart('f', position);
      draw7segmentpart('g', position);
      break;
    case 6:
      draw7segmentpart('a', position);
      draw7segmentpart('c', position);
      draw7segmentpart('d', position);
      draw7segmentpart('e', position);
      draw7segmentpart('f', position);
      draw7segmentpart('g', position);
      break;
    case 7:
      draw7segmentpart('a', position);
      draw7segmentpart('b', position);
      draw7segmentpart('c', position);
      break;
    case 8:
      draw7segmentpart('a', position);
      draw7segmentpart('b', position);
      draw7segmentpart('c', position);
      draw7segmentpart('d', position);
      draw7segmentpart('e', position);
      draw7segmentpart('f', position);
      draw7segmentpart('g', position);
      break;
    case 9:
      draw7segmentpart('a', position);
      draw7segmentpart('b', position);
      draw7segmentpart('c', position);
      draw7segmentpart('d', position);
      draw7segmentpart('f', position);
      draw7segmentpart('g', position);
      break;
  }
}

