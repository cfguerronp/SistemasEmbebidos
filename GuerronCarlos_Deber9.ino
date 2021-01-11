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
  Serial.begin(9600);  //llamamos a la cx serial
  Serial.println("       DEBER 9");
  Serial.println("Carlos Guerron");
  MsTimer2::set(1000, reset); // creamos el contador de mstimer a 1 segundo
  attachInterrupt(0,activacion,LOW); //creamos una activacion para que funcione el sistema
}

void loop() {
  if(onOff==1){ //condicion para que cuando el swtich sea 1 realice el sigueitne codigo
    conversor=analogRead(0); //toma los datos del puerto 0 analogo
    tiempo=map(conversor,0,1023,0,60); //convierte a 60 los 1024 datos que toma el potenciometro
    Serial.println(String("Reinicio Perro Guarian en: ")+String(tiempo)+String(" seg")); //mensaje serial 
    delay(1000); 
    }
}

void reset(){
  contador++;
  Serial.println(contador);
  if(contador==tiempo){ //condicon para que cuando el contador sea igual a tiempo este se reseete
    Serial.println("Sistema reseteado!!!"); 
    wdt_disable();  //resetear el perro guardian
    wdt_enable(WDTO_1S);
    
    }
  }
void activacion(){
  switch(onOff){ //switcvh para el funcionamiento de nuestro sistema
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
