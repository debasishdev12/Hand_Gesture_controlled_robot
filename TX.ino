#include<VirtualWire.h>

#define sample 10

int smoothX = 0;
int smoothY = 0;

int x = 0;
int y = 0;

char *controller;
void setup()
{
  Serial.begin(9600);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  
  vw_set_ptt_inverted(true);
  vw_set_tx_pin(7);
  vw_setup(4000);
}

void loop()
{
  x = (smoothX - (analogRead(A0) - smoothX/sample))*3;
  int x_map = map(x,0,1023,0,255) *(-1); 
  y = (smoothY - (analogRead(A1) - smoothY/sample))*3;
  int y_map = map(y,0,1023,0,255)*(-1);
 
  if(y_map > 260)    
  { 
    controller = "1";    //forward 
    vw_send((uint8_t*)controller, 1);
    //vw_wait_tx();
  }
  if(y_map < 215)
  { 
    controller = "2";    //backward 
    vw_send((uint8_t*)controller, 1);
    //vw_wait_tx();
  }
  if(x_map > 260)
  { 
    controller = "3";   //right  
    vw_send((uint8_t*)controller, 1);
    //vw_wait_tx();
  }
  if(x_map < 210)
  { 
    controller = "4";   //left 
    vw_send((uint8_t*)controller, 1);
    //vw_wait_tx();
  }
  if(x_map > 215 || x_map < 260 || y_map > 210 || y_map < 250)
  { 
    controller = "0";   //stop 
    vw_send((uint8_t*)controller, 1);
    //vw_wait_tx();
  }
  Serial.print("X :    ");
  Serial.print(x_map);
  Serial.print("\tY :    ");
  Serial.println(y_map);
}
