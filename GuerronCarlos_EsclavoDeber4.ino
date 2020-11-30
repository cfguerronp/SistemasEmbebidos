/*
 *            Deber 4 - Esclavo
 * Nombre : Carlos Guerrón
 * Fecha: 29/11/2020
 * Realice un sistema que codifique las vocales en palabras ingresadas por comunicación serial. 
 * Este mensaje se ingresa por comunicación serial en el master, este envía al esclavo para que realice la codificación por comunicación I2C. 
 * Luego, lo envía al master por el mismo medio y se muestra el resultado en una LCD en el master. La codificación es:
a=@

e=#

i= !

o = *

u= $

Ejemplo: CARRO = C@RR*
 * 
 */
 #include<Wire.h>
 char palabra; // variable que guarda la palabra ingresasda 
 String cod; // variable para nombrar a las letras que vamos a codificar
 String pCodi; // para mostarr la palabra codificada
 
void setup() {
  Wire.begin(4);
  Serial.begin(9600);
  Serial.println("      Deber 4 - Esclavo    ");
  Serial.println("Carlos Guerron");
  Serial.println("Codificacion de letras");
  Serial.println();
  Wire.onReceive(receiveEvent);  // solicita recibir del master
  Wire.onRequest(requestEvent);  // solicita envio del mamster

}

void loop() {
  delay(200); 

}
void receiveEvent(int bytes){
  while(Wire.available()){ // realizamos un ciclo while para poner la condicion de la codificacion
    char menu=Wire.read();  // creamos una varible menu para poner los datos de la codificacion
    switch(menu){  // creamos el menu y ponemos las letras del abecedario para poder codificar
      case'a':     // ponemos varios casos con todas la letars del abecedario para evitar errores y para codificar las letras que deseamos
      cod=cod+"@";
      break; 
      case'b':
      cod=cod+"b";
      break; 
      case'c':
      cod=cod+"c";
      break; 
      case'd':
      cod=cod+"d";
      break; 
      case'e':
      cod=cod+"#";
      break; 
      case'f':
      cod=cod+"f";
      break; 
      case'g':
      cod=cod+"g";
      break; 
      case'h':
      cod=cod+"h";
      break; 
      case'i':
      cod=cod+"!";
      break; 
      case'j':
      cod=cod+"j";
      break; 
      case'k':
      cod=cod+"k";
      break; 
      case'l':
      cod=cod+"l";
      break; 
      case'm':
      cod=cod+"m";
      break; 
      case'n':
      cod=cod+"n";
      break; 
      case'o':
      cod=cod+"*";
      break; 
      case'p':
      cod=cod+"p";
      break;
      case'q':
      cod=cod+"q";
      break;
      case'r':
      cod=cod+"r";
      break;
      case's':
      cod=cod+"s";
      break;
      case't':
      cod=cod+"t";
      break;
      case'u':
      cod=cod+"$";
      break;
      case'v':
      cod=cod+"v";
      break;
      case'w':
      cod=cod+"w";
      break;
      case'x':
      cod=cod+"x";
      break;
      case'y':
      cod=cod+"y";
      break;
      case'z':
      cod=cod+"z";
      break;
      }
    }
    Serial.println(cod);   // nos imprime la palabra codificada
    if(Serial.available()>0) { 
    pCodi=Serial.read();
   }
  }
  void requestEvent(){  // creamos el metodo que solicita el envio al master
    if(Serial.available()>0){  // creamos la condicion para la comunicacion I2C con el master
    palabra=Serial.read();  
    Wire.beginTransmission(4); 
    Wire.write(palabra); 
    Wire.endTransmission();  
      }
    }
