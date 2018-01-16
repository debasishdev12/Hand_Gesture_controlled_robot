//RECEIVER

#include<VirtualWire.h>

const int motorLeftA = 3;
const int motorLeftB = 5;
const int motorRightA = 8;
const int motorRightB = 9;

void setup()
{
  vw_set_ptt_inverted(true);
  vw_set_rx_pin(7);
  vw_setup(4000);
  vw_rx_start();
  
  pinMode(motorLeftA,OUTPUT);
  pinMode(motorLeftB,OUTPUT);
  pinMode(motorRightA,OUTPUT);
  pinMode(motorRightB,OUTPUT);
  
  digitalWrite(motorLeftA,LOW);
  digitalWrite(motorLeftB,LOW);
  digitalWrite(motorRightA,LOW);
  digitalWrite(motorRightB,LOW);
}

void loop()
{
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  
  if(vw_get_message(buf,&buflen))
  {
     for(int i = 0;i < buflen; i++){
       if(buf[i] == '1')
       {
         forward();   //forward
       }
       if(buf[i] == '2')
       {
         reverse();  //reverse
       }
       if(buf[i] == '3')
       {
         right();   //right
       }
       if(buf[i] == '4')
       {
         left();  //left
       }
       if(buf[i] == '0')
       {
         brake();  //left
       }
   }  
 }
}

void forward()
{
  digitalWrite(motorLeftA,HIGH);
  digitalWrite(motorLeftB,LOW);
  digitalWrite(motorRightA,HIGH);
  digitalWrite(motorRightB,LOW);
}
void left()
{
  digitalWrite(motorLeftA,HIGH);
  digitalWrite(motorLeftB,LOW);
  digitalWrite(motorRightA,LOW);
  digitalWrite(motorRightB,LOW);
}
void right()
{
  digitalWrite(motorLeftA,LOW);
  digitalWrite(motorLeftB,LOW);
  digitalWrite(motorRightA,HIGH);
  digitalWrite(motorRightB,LOW);
}
void reverse()
{
  digitalWrite(motorLeftA,LOW);
  digitalWrite(motorLeftB,HIGH);
  digitalWrite(motorRightA,LOW);
  digitalWrite(motorRightB,HIGH);
}
void brake()
{
  digitalWrite(motorLeftA,LOW);
  digitalWrite(motorLeftB,LOW);
  digitalWrite(motorRightA,LOW);
  digitalWrite(motorRightB,LOW);
}
