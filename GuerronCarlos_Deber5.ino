/*
 *           DEBER 5 
 * Nombre: Carlos Guerron 
 * Fecha: 09/12/2020
 * Objetivo: Realizar un programa que mediante interrupciones tenga 3 modos: Inicio del sistema, giro de motor y fin de programa. El giro debe ser ingresado por comunicación serial. 
 * 
 */
#include<Servo.h>

Servo motor1;   // declaramos elk objeto para el servo
String dato;  // variables para que el motor se mueva por cx serial.
int giro=0;
int cero=0; // variable para inicializar el servo en 0
int onOff=0; // variable para el incio del programa y apagado

void setup() {
  // put your setup code here, to run once:
  motor1.attach(8);  //indicamos que el motor estara en el pin 8
  Serial.begin(9600);
  Serial.println("     DEBER 5");
  Serial.println("Carlos Guerron");
  attachInterrupt(0,giroMotor,LOW);
}

void loop() {
  delay(20);
  motor1.write(cero);  // empezamos inicializando al motor en 0
  if(onOff==2){   //indicamos la condiciones de la variable de encedido es igual a 2 se muestra el siguiente programa
    if(Serial.available()>0){ //lee el dato de la terminal virtual
      dato=Serial.readString();  // lo pasa a la variable dato
      giro=dato.toInt();  // convierte a entero el valor ingresado
      }
      if(giro<180){   //condicon que debe ser menos a 180
        motor1.write(giro);  // escribe el dato en el motor para que gire 
        }
        else{
        Serial.println("Error, introducir valores hasta 180");  // si se ingresa un dato erroneo
        delay(20);  //para establizar el motor
        }
    }
}

void giroMotor() {   //metodo para la interrupcion
  switch(onOff){  //un swtich para realizar las condicones del programa
    case 0:
    Serial.println("Inicio Programa");   
    Serial.println("Ingrese datos para el motor del 0 al 180");
    onOff ++;
    break;
    case 1:
    Serial.println("Motor Girando");
    onOff++;
    break;
    case 2:
    Serial.println("Fin del programa");
    motor1.write(0);
    onOff=0;
    break;
    }
  }



  
