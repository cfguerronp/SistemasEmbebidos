/*
 *                DEBER 1
 *  Nombre: Carlos Guerrón
 *  Fecha: 23/11/2020
 *  Realizar un programa que accione mediante 4 switchs a un juego de luces diferente.
 */
const int ledb=8; // led blue pin 8
const int ledg=7; // led green pin 7
const int ledo=6; // led orange pin 6
const int ledp=5; //led pink pin 5 
const int ledr=4; //led red pin 4
const int ledy=3; //led yellow pin 3
const int sw0=9;  // switch 0 pin 9
const int sw1=10; // switch 1 pin 10
const int sw2=11; // switch 2 pin 11
const int sw3=12; // switch 3 pin 12
int i=0;     // contadores para los ciclos while
int j=0;
int k=0;
int l=0;
void setup() {

pinMode(ledb,OUTPUT); // declaramos los leds como salida de dato
pinMode(ledg,OUTPUT);
pinMode(ledo,OUTPUT);
pinMode(ledp,OUTPUT);
pinMode(ledr,OUTPUT);
pinMode(ledy,OUTPUT);
pinMode(sw0,INPUT);  //declaramos los switchs como entrada de dato 
pinMode(sw1,INPUT);
pinMode(sw2,INPUT);
pinMode(sw3,INPUT);
}

void loop() {
// Juego 1: Se encienden 10 veces los leds pares en intervalos de 1 segundo   
if(digitalRead(sw0)==HIGH){
  delay(400);
  while(i<10){
    digitalWrite(ledb,LOW);
    digitalWrite(ledo,LOW);
    digitalWrite(ledr,LOW);
    digitalWrite(ledg,HIGH);
    digitalWrite(ledp,HIGH);
    digitalWrite(ledy,HIGH);
    delay(1000);
    digitalWrite(ledb,LOW);
    digitalWrite(ledo,LOW);
    digitalWrite(ledr,LOW);
    digitalWrite(ledg,LOW);
    digitalWrite(ledp,LOW);
    digitalWrite(ledy,LOW);
    delay(1000);
    i++;
    }
  }
  else 
  i=0;
//Juego 2: S e encienden los leds impares 10 veces en lapsos de 1 segundo
if(digitalRead(sw1)==HIGH){
      delay(400);
      while(j<10){
        digitalWrite(ledg,LOW);
        digitalWrite(ledp,LOW);
        digitalWrite(ledy,LOW);
        digitalWrite(ledb,HIGH);
        digitalWrite(ledo,HIGH);
        digitalWrite(ledr,HIGH);
        delay(1000);
        digitalWrite(ledg,LOW);
        digitalWrite(ledp,LOW);
        digitalWrite(ledy,LOW);
        digitalWrite(ledb,LOW);
        digitalWrite(ledo,LOW);
        digitalWrite(ledr,LOW);
        delay(1000);
        j++;
        }
      }
      else 
      j=0;
//Juego 3: Se encienden los leds de forma secuencial, este proceso se repite 5 veces
if(digitalRead(sw2)==HIGH){
  delay(400);
      while(k<5){
        digitalWrite(ledb,HIGH);
        digitalWrite(ledg,LOW);
        digitalWrite(ledo,LOW);
        digitalWrite(ledp,LOW);
        digitalWrite(ledr,LOW);
        digitalWrite(ledy,LOW);
        delay(1000);
        digitalWrite(ledb,LOW);
        digitalWrite(ledg,HIGH);
        digitalWrite(ledo,LOW);
        digitalWrite(ledp,LOW);
        digitalWrite(ledr,LOW);
        digitalWrite(ledy,LOW);
        delay(1000);
        digitalWrite(ledb,LOW);
        digitalWrite(ledg,LOW);
        digitalWrite(ledo,HIGH);
        digitalWrite(ledp,LOW);
        digitalWrite(ledr,LOW);
        digitalWrite(ledy,LOW);
        delay(1000);
        digitalWrite(ledb,LOW);
        digitalWrite(ledg,LOW);
        digitalWrite(ledo,LOW);
        digitalWrite(ledp,HIGH);
        digitalWrite(ledr,LOW);
        digitalWrite(ledy,LOW);
        delay(1000);
        digitalWrite(ledb,LOW);
        digitalWrite(ledg,LOW);
        digitalWrite(ledo,LOW);
        digitalWrite(ledp,LOW);
        digitalWrite(ledr,HIGH);
        digitalWrite(ledy,LOW);
        delay(1000);
        digitalWrite(ledb,LOW);
        digitalWrite(ledg,LOW);
        digitalWrite(ledo,LOW);
        digitalWrite(ledp,LOW);
        digitalWrite(ledr,LOW);
        digitalWrite(ledy,HIGH);
        delay(1000);
        k++;
        }
  }
  else
  k=0;
//Juego 4: Se encienden los leds par por par en orden, este proceso se repite 5 veces. 
if(digitalRead(sw3)==HIGH){
    delay(400);
    while(l<5){
      digitalWrite(ledb,HIGH);
      digitalWrite(ledg,HIGH);
      digitalWrite(ledo,LOW);
      digitalWrite(ledp,LOW);
      digitalWrite(ledr,LOW);
      digitalWrite(ledy,LOW);
      delay(1000);
      digitalWrite(ledb,LOW);
      digitalWrite(ledg,LOW);
      digitalWrite(ledo,HIGH);
      digitalWrite(ledp,HIGH);
      digitalWrite(ledr,LOW);
      digitalWrite(ledy,LOW);
      delay(1000);
      digitalWrite(ledb,LOW);
      digitalWrite(ledg,LOW);
      digitalWrite(ledo,LOW);
      digitalWrite(ledp,LOW);
      digitalWrite(ledr,HIGH);
      digitalWrite(ledy,HIGH);
      delay(1000);
      l++;
      }
    }
    else
    l=0;
}
