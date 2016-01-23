#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wiringPi.h>

void setup(int *buttonPress) {
  int i;
  for(i = 0; i < 12; i++) {
    digitalWrite(i, LOW); // Turn off all LEDS
  }
  if(digitalRead(12) == LOW) {
    *buttonPress = 0; // Set button press to 0
    printf("Start game\n");
    return;
  }
}
void game(int *buttonPress) {
  int led = 11, x, descend, target; 
  *buttonPress = 0;
  target = 9 - (rand() % 9);
  for(x = 0; x < 4; x++) {
    digitalWrite(target, HIGH); delay(200); digitalWrite(target, LOW); delay(200); 
  }

  while(*buttonPress == 0) {
    if(descend) {
      if(led == 12) {
        descend = 0;
      } else {
        delay(20);
        digitalWrite(led, LOW);
        led++;
      }
    } else {
      if(led == -1) {
        descend = 1;
      } else {
        digitalWrite(led, HIGH);
        delay(60);
        led--;
      }
    }
    if(digitalRead(12) == LOW) {
      printf("Target: %d\n", target);
      printf("Hit: %d\n", led+1);
      *buttonPress = 1;
    }
  }

  while(*buttonPress == 1) {
    for(x = 0; x < 12; x++) {
      digitalWrite(x, LOW);
    }
    printf("Target: %d\n", target);
    printf("Hit: %d\n", led+1);
    if(led + 1 == target) { // Win
      for(x = 0; x < 4; x++) { 
        digitalWrite(2, HIGH); digitalWrite(6, HIGH); digitalWrite(10, HIGH); delay(200); digitalWrite(2, LOW); digitalWrite(6, LOW); digitalWrite(10, LOW); delay(200); // Flash green LEDS
      }
    } else { // Lose
        digitalWrite(led + 1, HIGH);
      for(x = 0; x < 4; x++) {
        digitalWrite(target, HIGH); delay(200); digitalWrite(target, LOW); delay(200); 
      }
      for(x = 0; x < 12; x++) {
        digitalWrite(x, LOW);
      }
      for(x = 0; x < 4; x++) {
        digitalWrite(1, HIGH); digitalWrite(5, HIGH); digitalWrite(9, HIGH); delay(200); digitalWrite(1, LOW); digitalWrite(5, LOW); digitalWrite(9, LOW); delay(200); // Flash red LEDS
      }
    }
    break;
  }
  return;
}
int main() {
  wiringPiSetup();
  int i, buttonPress;
  for(i = 0; i < 12; i++) {
  	pinMode(i, OUTPUT); // Set all pins for LEDS to output
  }
  pinMode(12, INPUT); // Set pin for button to input
  pullUpDnControl(12, PUD_UP); // Pull down button input
  srand(time(NULL)); 
  
  while(1) {
    setup(&buttonPress); // Setup game
    game(&buttonPress); // Start game
  }
}

