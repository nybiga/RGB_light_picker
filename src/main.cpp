#include <Arduino.h>
#include <limits.h>  // For INT_MIN

// Colors' pins
int redPin = 3, greenPin = 4, bluePin = 5;
// Array of colors' pins
int colorPins[] = {redPin, greenPin, bluePin};
// Array of colors
String colorList[] = {"Black(OFF)", "Red", "Yellow", "Green", "Blue", "Purple", "White", "Teal"};
// Array of colors' values
int colorValues[][3] = {
  {0, 0, 0},       // black
  {255, 0, 0},     // red
  {255, 200, 0},  // yellow
  {0, 255, 0},     // green
  {0, 0, 255},     // blue
  {165, 52, 235},   // purple
  {255, 255, 255},  // white
  {0 ,204, 204}   // teal
};

int currentColor = 0, newColor = INT_MIN;

// Corresponding rgb values
int redValue, greenValue, blueValue;

// Function declaration
void printOptions();
void lightUp();

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 3; i++){
    pinMode(colorPins[i], OUTPUT);
  }
  // Begins serial monitor
  Serial.begin(9600);

  printOptions();
}

void loop() {
  // put your main code here, to run repeatedly:
  // Reads input
  String colorInput = Serial.readString();
  Serial.print(colorInput);
  // Validates input
  if (colorInput != ""){
    if (colorInput == "0") newColor = 0;
    else if (colorInput == "1") newColor = 1;
    else if (colorInput == "2") newColor = 2;
    else if (colorInput == "3") newColor = 3;
    else if (colorInput == "4") newColor = 4;
    else if (colorInput == "5") newColor = 5;
    else if (colorInput == "6") newColor = 6;
    else if (colorInput == "7") newColor = 7;
    else Serial.println(" Invaild color, pick a valid color");

    if (currentColor == newColor) Serial.println(" Color already selected");
    
  }
  // Checks for change in color
  if (newColor != INT_MIN && currentColor != newColor){
    Serial.println(" New color selected");
    currentColor = newColor;
  }
  
  lightUp();
}

// Prints color options
void printOptions(){
  Serial.println("Select a number to pick a color");
  int arraySize = sizeof(colorList) / sizeof(colorList[0]);
  for (int i = 0; i < arraySize; i++){
    Serial.println((String) i + ": " + colorList[i]);
  }
}

// Lights up LED
void lightUp(){
  redValue = colorValues[currentColor][0], 
  greenValue = colorValues[currentColor][1], 
  blueValue = colorValues[currentColor][2];

  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}