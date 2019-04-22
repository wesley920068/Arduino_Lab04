#include "SevSeg.h"
SevSeg sevseg;

void setup() {
  byte num2[]={11,12,13,14};
  //           千 百 十 個
    // byte pin[]={15,10,9,8,5,4,3,2};
  byte pin[]={2,3,4,5,8,9,10,15};
    //        a,b,c,d,e,f,g,h
  
 sevseg.begin(COMMON_CATHODE,4,num2,pin,false,false,false);
  sevseg.setBrightness(90);
  pinMode(6,INPUT);
}


void loop() {
  static int Min=0,Hour=0,sum=0;
  static unsigned long timer = millis();

    if(millis()-timer>100)            //delay(300)
    {
        timer+=100;
            if(++Min>=60)
            {
              Min=0;
             if(++Hour>=24)
              Hour=0;
              }
            sevseg.setNumber(Hour*100+Min,2);  
            if(digitalRead(6)==1)
              {
                Min = 0;
                Hour = 0;
                sum = 0;
              }
     }
        sevseg.refreshDisplay();            

 }
