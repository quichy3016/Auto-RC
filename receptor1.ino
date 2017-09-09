/*  ----------------------------------------------------------------
    http://www.prometec.net/nrf2401
    Prog_79_1_Receptor
    
    Programa para recibir numeros mediante radios NRF2401
--------------------------------------------------------------------  
*/

#include <nRF24L01.h>
#include <RF24.h>
#include <RF24_config.h>
#include <SPI.h>

int msg[1];
int acelerar[2];

RF24 radio(9,10);
const uint64_t pipe = 0xE8E8F0F0E1LL;

void setup(void){
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1,pipe);
  radio.startListening();
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
}
 
void loop(void){
  if (radio.available())
  {
    // bool done = false;  
    //int done = radio.read(msg, 1); 
    // lastmsg = msg[0];
    //Serial.println(msg[0]);
    //int done = radio.read(acelerar,2);
    //if (acelerar[0]==1){
      //digitalWrite(2,HIGH);
      //Serial.println(acelerar[0]);
      //Serial.println("acelerando");}
      //else {
        //digitalWrite(2,LOW);
        //Serial.println(acelerar[0]);
        //Serial.println("FRENO");}
       int done = radio.read(acelerar,2);
       //Serial.println(acelerar[0]);
       if ((acelerar[0]>=437) & (acelerar[0]<=587)){
          digitalWrite(2,LOW);
          digitalWrite(4,LOW);
          analogWrite(3,0);
          Serial.println("Freno");}
       else {if ((acelerar[0]<437) & (acelerar[0]!=0)){
          digitalWrite(2,HIGH);
          digitalWrite(4,LOW);
          byte velocidadI= (155- 0.35*acelerar[0]+100);
          analogWrite(3,velocidadI);
          Serial.println(velocidadI);}
          //Serial.println("izquierda");}
          else if ((acelerar[0]>587) & (acelerar[0]!=0))
          {
            digitalWrite(2,LOW);
            digitalWrite(4,HIGH);
            byte velocidadD= (0.35*(acelerar[0]-587)+100);
            analogWrite(3,velocidadD);
            Serial.println(velocidadD);}}
           // Serial.println("derecha");}}
               
    }
    
  }
