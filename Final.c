/* 
	////Created by Kevin////
	Use
		'Tools' -> Board -> TeensyTeensy LC 
		'Tools' -> USB Type -> Serial + Mouse + Keyboard + Joystick
   
   Potentiometers should be connected to analog inputs 0 to 1.

   
*/

void setup() {
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
}
int pots[2];
void loop() {
  
  pots[0] = analogRead(0);
  pots[1] = analogRead(1);

  pots[0] = ((pots[0] > 512) ? 512 : pots[0]);
  pots[1] = ((pots[1] > 512) ? 512 : pots[1]);
  
  //deadzone 
  if (abs(pots[0] - pots[1]) < 10){
    Joystick.Zrotate(512);
  }
  //left
  else if (pots[0] > pots[1]){
    Joystick.Zrotate(512 - pots[0]);
  }
  //right
  else if (pots[0] < pots[1]){
    Joystick.Zrotate(512 + pots[1]);
  }
  delay(5);
}
