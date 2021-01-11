/*  DEBER 9
 * Nombre: Carlos Guerrón
 * Fecha: 13/01/2021
 * Objetivo:Realice un programa que mediante un conversor análogo-digital se configure el tiempo de reinicio del perro guardián (tiempos seleccionados por el usuario). 
 * Envíe mensajes por comunicación serial validando todo el proceso. 
 * 
 */

 #include <avr/wdt.h>
 #include<MsTimer2.h>

 int onOff=0;
 int i=0;
 int tiempo=0;
 int conversor;
 int contador=0;
 
void setup() {
  Serial.begin(9600);
  Serial.println("       DEBER 9");
  Serial.println("Carlos Guerron");
  MsTimer2::set(1000, reset);
  attachInterrupt(0,activacion,LOW);
}

void loop() {
  if(onOff==1){
    conversor=analogRead(0);
    tiempo=map(conversor,0,1023,0,60);
    Serial.println(String("Reinicio Perro Guarian en: ")+String(tiempo)+String(" seg"));
    delay(1000);
    }
}

void reset(){
  contador++;
  Serial.println(contador);
  if(contador==tiempo){
    Serial.println("Sistema reseteado!!!");
    wdt_disable();
    wdt_enable(WDTO_1S);
    
    }
  }
void activacion(){
  switch(onOff){
    case 0:
      Serial.println("SISTEMA ENCENDIDO");
      Serial.println("Mueva el potenciometro para ajustar el tiempo de reinicio");
      onOff++;
    break;
    case 1:
      Serial.println(String("Reiniciando en: ")+String(tiempo)+String(" segundos."));
      MsTimer2::start();
      onOff++;
    break;

    }
  }
