/*
 *          DEBER 7
 * Nombre: Carlos Guerrón
 * Fecha: 09/12/2020
 * Objetivo: Realiza un programa que valide y actualice una contraseña almacenada en la memoria EEPROM. Como estado inicial, la contraseña es de 4 dígitos que son: 4563. 
 * 
 */

 #include <EEPROM.h>  //llamamos a la libreria de la eeprom

 int contrase=4563;  //variable que contiene la contraseña predeterminada
 int onOff=0;  //variable para el inicio de programa
 String dato; // variable que toma el dato ingresado en cx serial
 int contr; // variable para tomar el dato de la contraseña
 int PASS; // variable para tomar dato flotante de la eeptom 
void setup() {
  Serial.begin(9600);
  Serial.println("       DEBER 7");
  Serial.println("Carlos Guerron");
  EEPROM.get(0,PASS);   // la funcion get obtiene diferentes variables de EEPROM y recupera un número de bytes que se relaciona al tipo de dato de la variable.
  attachInterrupt(0,validarContra,LOW); // activamos una interruppcion para realizar el proceso

}

void loop() {
  if(onOff==1){ //iniciamos con las condiciones para validar y actualziar la contraseña
    if(Serial.available()>0){
      dato=Serial.readString(); // guarda en la variable dato lo que pongamos en la cx serial
      contr=dato.toInt(); // convertimos a entero la variable dato
      }
      PASS=contr; // igualamos la variable de la eeprom con el dato que se ingreso
    }
    if(onOff==2){
      if(PASS==contrase){ // realizamosla comparacion de la contraseña ingresada con la que guardamos
        Serial.println("Password ingresado correctamente!!");
        delay(1000);
        }
        if(PASS!=contrase){  //comparamos la contraseña ingresada con la guardada 
          Serial.println("Password erroneo!!");
          delay(1000);
          }
      }
      if(onOff==3){
        if(Serial.available()>0){ // pedimos otra contraseña para actualizar
          dato=Serial.readString(); // ponemos en la variable dato 
          contr=dato.toInt();  // convertimos a entero
          }
          PASS=contr;  // igualamos las dos variables 
          EEPROM.update(0,PASS);  // actualziamos en la eeprom la nueva contraseña
          contrase=PASS; // igualamos la variable contraseñapara que se actualice con la nueva
        }

}

void validarContra(){
  switch(onOff){
    case 0:
    Serial.println("Digite su password: ");
    onOff++;
    break;
    case 1:
    Serial.println("Validar password");
    onOff++;
    break;
    case 2:
    Serial.println("Ingrese el nuevo password: ");
    onOff;
    break;
    case 3:
    Serial.println("Password actualizado");
    onOff=0;
    PASS=0;
    contr=0;
    break;
    }
  }
