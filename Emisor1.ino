/*  ----------------------------------------------------------------
    http://www.prometec.net/nrf2401
    Prog_79_1_Emisor
    
    Programa para transmitir numeros mediante radios NRF2401
--------------------------------------------------------------------  
*/

#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

int msg[1] ;                             // Array a transmitir
int acelerar[2];
RF24 radio(9,10);                        // Creamos un objeto radio del tipo RF2$
const uint64_t pipe = 0xE8E8F0F0E1LL;    // Usamos este canal
 
void setup(void){
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(pipe);          // Abrir para escribir
 pinMode(2,INPUT_PULLUP);
 pinMode(7,OUTPUT);
 pinMode(6,OUTPUT);
 digitalWrite(6,LOW);
 digitalWrite(7,HIGH);
 }
void loop(void)
{  //for (int x=0;x<2255;x++)
       //{  msg[0] = x ;
         // radio.write(msg, 1);
   //    }
      // if (digitalRead(2)==HIGH){
       //acelerar[0]=1;
       //radio.write(acelerar,2);
       //Serial.println(acelerar[0]);}
       //else {
        //acelerar[0]=0;
        //radio.write(acelerar,2);
        //Serial.println(acelerar[0]);
        //}
        int pin3 = analogRead(A0);
        acelerar[0] = pin3;
        radio.write(acelerar,2);
        Serial.println(acelerar[0]);
       }
