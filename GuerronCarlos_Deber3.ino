/*
 *           DEBER 3
 * Nombre: Carlos Guerron
 * Fecha: 30/11/2020
 * Realizar un programa de juego de preguntas. Se debe tener mínimo 8 preguntas que deben observarse en orden aleatorio. 
 * La forma de visualización es por medio de comunicación serial. Su respuesta solo debe ser "SI" y "NO" ingresadas de la misma forma por comunicación serial.
 * Al final de mostrar solo 5 de las 8 preguntas. Se presentan el puntaje (respuestas acertadas) en un display.
 */
const int A=5;  // Declaramos los pines del arduino que estaran conectados al decodificador 7447
const int B=4;
const int C=3;
const int D=2;
String dat;   // estas variables alamacenana las respuestas en las preguntas
String dat0;
String dat1;
String dat2;
String dat3;
String dat4;
String dat5;
String dat6;
String dat7;
String dat8;
int acep0=0;  // estas variables almacenan el si acepto o no en las respectivas preguntas
int acep1=0;
int acep2=0;
int acep3=0;
int acep4=0;
int acep5=0;
int acep6=0;
int acep7=0;
int acep8=0;   
int cont=0; // para realizar el conteo 
int start=1;  // nos inda el incio del juego

void setup() {
  pinMode(A,OUTPUT);   // Declaramos que los pines del decodificador son salidas de dato
  pinMode(B,OUTPUT);
  pinMode(C,OUTPUT);
  pinMode(D,OUTPUT);
  Serial.begin(9600);
  Serial.println("    Deber 3   ");
  Serial.println("Carlos Guerron");
  Serial.println("Juego de preguntas, por favor indique la respuesta de la pregunta solo con 'SI' o 'NO'");
  Serial.println();
}

void loop() {
  delay(1000); 
  if(start==1){ // empieza con una condicioon de valor inicial
    start=0;
    int i,pregunta; // la i es para el ciclo for y la variable pregunta es varibale que indica si la pregunta es determiado valor aleotorio nos aparece la pregunta
    for(i=0; i<5; i++){  // Este ciclo hace las 5 preguntas aleotorias que vamos a mostrar
      delay(10); // este delay sirve para que se evite repetir preguntas
      randomSeed(millis()); // esta funcion genera numeros pseudoaleotorios
      pregunta=random(0,8);  // crea valores del 0 al 7 aleotoriamente
      Serial.print(pregunta);  // lee en la terminal el valor de la pregunta
       if(pregunta==0){ // indicamos si el valor de la pregunta 0 
        delay(2000);
        Serial.println("  Tulcan es capital de Ecuador");// imprime la pregunta 0
        delay(4000);
        if(Serial.available()>0){
          dat0=Serial.readString();  // lee el dato ingresado y lo almacena en la variable
          dat0.toUpperCase();  // convertimos a mayusculas para evitar errores
          if(dat0=="NO"){ // se condiciona la respuesta afirmativa 
            acep0=1; // auemnta 
            Serial.println("Correcto..!!");  // indica que la respuesta es correcta
            }
            else
            Serial.println("Incorrecto..!!");  // indica que la respuesta es incorrecta 
          }
        }
        // de aqui en adelante repetimos el proceso 8 veces
        if(pregunta==1){
          delay(1000);
          Serial.println("  La electronica empezo en 1904");
          delay(4000);
          if(Serial.available()>0){
            dat1=Serial.readString();
            dat1.toUpperCase();
            if(dat1=="SI"){
              acep1=1;
              Serial.println("Correcto..!!");
              }
              else
              Serial.println("Incorrecto..!!");
            }
          }
          if(pregunta==2){
            delay(1000);
            Serial.println("  El arduino UNO tiene el Atmega328");
            delay(4000);
            if(Serial.available()>0){
              dat2=Serial.readString();
              dat2.toUpperCase();
              if(dat2=="SI"){
                acep2=1;
                Serial.println("Correcto..!!");
                }
                else
                Serial.println("Incorrecto..!!");
              }
            }
            if(pregunta==3){
              delay(1000);
              Serial.println("  El presidente de Venezuela es Hugo Chavez");
              delay(4000);
              if(Serial.available()>0){
                dat3=Serial.readString();
                dat3.toUpperCase();
                if(dat3=="NO"){
                  acep3=1;
                  Serial.println("Correcto..!!");
                  }
                  else
                  Serial.println("Incorrecto..!!");
                }
              }
              if(pregunta==4){
                delay(1000);
                Serial.println("  Un ingeniero en Telecomunicaciones realiza cableado estructurado");
                delay(4000);
                if(Serial.available()>0){
                  dat4=Serial.readString();
                  dat4.toUpperCase();
                  if(dat4=="SI"){
                    acep4=1;
                    Serial.println("Correcto..!!");
                    }
                    else
                    Serial.println("Incorrecto..!!");
                  }
                }
                if(pregunta==5){
                  delay(1000);
                  Serial.println("  La red 5G supera velocidades de 20Gbps");
                  delay(4000);
                  if(Serial.available()>0){
                    dat5=Serial.readString();
                    dat5.toUpperCase();
                    if(dat5=="NO"){
                      acep5=1;
                      Serial.println("Correcto..!!");
                      }
                      else
                      Serial.println("Incorrecto..!!");
                    }
                  }
                  if(pregunta==6){
                    delay(1000);
                    Serial.println("  Richard Carapaz gano el Tour de Francia");
                    delay(4000);
                    if(Serial.available()>0){
                      dat6=Serial.readString();
                      dat6.toUpperCase();
                      if(dat6=="NO"){
                        acep6=1;
                        Serial.println("Correcto..!!");
                        }
                        else
                        Serial.println("Incorrecto..!!");
                      }
                  }
                      if(pregunta==7){
                        delay(1000);
                        Serial.println("  La UTN tiene acreditacion");
                        delay(4000);
                        if(Serial.available()>0){
                          dat7=Serial.readString();
                          dat7.toUpperCase();
                          if(dat7=="SI"){
                            acep7=1;
                            Serial.println("Correcto..!!");
                            }
                            else
                            Serial.println("Incorrecto..!!");
                          }
                        }
                        if(pregunta==8){
                          delay(1000);
                          Serial.println("  El ultimo campeon del mundial es Argentina");
                          delay(4000);
                          if(Serial.available()>0){
                            dat8=Serial.readString();
                            dat8.toUpperCase();
                            if(dat8=="NO"){
                              acep8=1;
                              Serial.println("Correcto..!!");
                              }
                              else
                              Serial.println("Incorrecto..!!");
                            }
                          }
                       cont=acep0+acep1+acep2+acep3+acep4+acep5+acep6+acep7+acep8;  //esta variable cuenta las respuestas corectas para mostrar en el display
                       if(cont==0){   // esta condicional hace que muestre el 0 si se tiene 0 aciertos
                        digitalWrite(A,LOW);
                        digitalWrite(B,LOW);
                        digitalWrite(C,LOW);
                        digitalWrite(D,LOW);
                        }
                        if(cont==1){
                          digitalWrite(A,HIGH);
                          digitalWrite(B,LOW);
                          digitalWrite(C,LOW);
                          digitalWrite(D,LOW);
                          }
                          if(cont==2){
                            digitalWrite(A,LOW);
                            digitalWrite(B,HIGH);
                            digitalWrite(C,LOW);
                            digitalWrite(D,LOW);
                            }
                            if(cont==3){
                              digitalWrite(A,HIGH);
                              digitalWrite(B,HIGH);
                              digitalWrite(C,LOW);
                              digitalWrite(D,LOW);
                              }
                              if(cont==4){
                                digitalWrite(A,LOW);
                                digitalWrite(B,LOW);
                                digitalWrite(C,HIGH);
                                digitalWrite(D,LOW);
                                }
                                if(cont==5){
                                  digitalWrite(A,HIGH);
                                  digitalWrite(B,LOW);
                                  digitalWrite(C,HIGH);
                                  digitalWrite(D,LOW);
                                  }
                    }
                    Serial.println("Su puntuacion es: "+String(cont));
                    
      }
}
