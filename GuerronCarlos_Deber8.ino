/*  DEBER 8
 * Nombre: Carlos Guerrón
 * Fecha: 13/01/2021
 * Objetivo: Realizar un código que el sistema se reinicia cada minuto, active el conversor análogo-digital realice una lectura y vuelve el sistema a un modo sleep.
 * 
 */
#include<avr/power.h>
#include<avr/sleep.h>
#include<avr/wdt.h>
#include<MsTimer2.h>

int tiempo=0;  //tiempo de datos 
int contador=0; //contador del timer
int onOff=0; //modos del sistema

void setup() {
  Serial.begin(9600);  // llamamos a la cx serial
  Serial.println("     DEBER 8    ");
  Serial.println("Carlos Guerron");
  MsTimer2::set(1000,reloj); //llamamos al timer 2, con el metodo reloj
  attachInterrupt(0,activacion,LOW); //creamos la interrupcion para activar el sistema
  
}

void loop() {
  delay(1000);
}

void activacion(){
  switch(onOff){
    case 0:
      Serial.println("SISTEMA ENCENDIDO");
      power_adc_disable();
      tiempo=60; // fijamos el minuto para que se reinicie el sistema
      onOff ++;
    break;
    case 1:
      Serial.println(String("SISTEMA FUNCIONA EN: ")+String(tiempo)+String(" seg"));
      MsTimer2::start();
      onOff++;
    break;
    case 2:
      Serial.println("SISTEMA APAGADO");
      tiempo=0;
      onOff=0;
      MsTimer2::stop();
      power_adc_disable();
    break;
    }
  }
void reloj(){
  contador++;
  Serial.println(String("Lectura en: ")+String(tiempo-contador));
  if(contador==tiempo){
    power_adc_enable();
    delay(10);
    Serial.println(analogRead(0));
    contador=0;
    }
  }
