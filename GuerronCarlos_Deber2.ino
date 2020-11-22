/*
 *                DEBER 2
 * Nombre: Carlos Guerrón                 
 * Fecha: 23/11/2020
 * Realizar un programa que al presionar el pulsador cada vez, se visualiza a cada número primo hasta el 99.
 */
// declaramos las variables que vamos a usar para nuestro programa
const int da=11;  // decodificador dato A es en el pin 11
const int db=10;  // decodificador dato B es en el pin 10
const int dc=9; // decodificador dato C es en el pin 9
const int dd=8; // decodificador dato D es el pin 8 
const int btn1=5; // el boton esta en el pin 5
const int unidades=13; // para manejar las unidades usamos el pin 13
const int decenas=12; // para manejar las decenas usamos el pin 12
int contador; 
int uni;
int dec;
int residuo;
int j;
boolean nroprimo;  //declaramos la variable de numero primo un valor booleano es decir verdad o falso
void setup() {
pinMode(da,OUTPUT);   // los datos del A hasta el D son salidas al decodificador
pinMode(db,OUTPUT);
pinMode(dc,OUTPUT);
pinMode(dd,OUTPUT);
pinMode(btn1,INPUT);  // el boton es una entrada de datos
pinMode(unidades,OUTPUT);  //son salidas que se activan para indicar las decenas y unidades en el display 
pinMode(decenas,OUTPUT);
}

void loop() {
  if(digitalRead(btn1)==HIGH){
    delay(100);
    if(contador<=99){
      contador ++;
      nroprimo=true;
      
      for(j=2; j<contador; j++){
        residuo=contador%j;
        
        if(residuo==0){
          nroprimo=false;
          }
        }
        if(contador == 1){
          nroprimo = false;
          }
          if(nroprimo){
            if(contador<10){
              uni=contador;
              dec=0;
              }
              else{
                dec=contador/10;
                uni=contador-dec*10;
                }
          }
    }
    else
    contador = 0;
    }

      digitalWrite(unidades,HIGH);
      digitalWrite(decenas,LOW);
      contadornum(uni);
      delay(200);
      digitalWrite(unidades,LOW);
      digitalWrite(decenas,HIGH);
      contadornum(dec);
      delay(200);
}
void contadornum (int i){
    switch(i){
    case 0:
    digitalWrite(da,LOW);
    digitalWrite(db,LOW);
    digitalWrite(dc,LOW);
    digitalWrite(dd,LOW);
    break;
    case 1:
    digitalWrite(da,HIGH);
    digitalWrite(db,LOW);
    digitalWrite(dc,LOW);
    digitalWrite(dd,LOW);
    break;
    case 2:
    digitalWrite(da,LOW);
    digitalWrite(db,HIGH);
    digitalWrite(dc,LOW);
    digitalWrite(dd,LOW);
    break;  
    case 3:
    digitalWrite(da,HIGH);
    digitalWrite(db,HIGH);
    digitalWrite(dc,LOW);
    digitalWrite(dd,LOW);
    break; 
    case 4:
    digitalWrite(da,LOW);
    digitalWrite(db,LOW);
    digitalWrite(dc,HIGH);
    digitalWrite(dd,LOW);
    break;
    case 5:
    digitalWrite(da,HIGH);
    digitalWrite(db,LOW);
    digitalWrite(dc,HIGH);
    digitalWrite(dd,LOW);
    break;
    case 6:
    digitalWrite(da,LOW);
    digitalWrite(db,HIGH);
    digitalWrite(dc,HIGH);
    digitalWrite(dd,LOW);
    break;
    case 7:
    digitalWrite(da,HIGH);
    digitalWrite(db,HIGH);
    digitalWrite(dc,HIGH);
    digitalWrite(dd,LOW);
    break;
    case 8:
    digitalWrite(da,LOW);
    digitalWrite(db,LOW);
    digitalWrite(dc,LOW);
    digitalWrite(dd,HIGH);
    break;
    case 9:
    digitalWrite(da,HIGH);
    digitalWrite(db,LOW);
    digitalWrite(dc,LOW);
    digitalWrite(dd,HIGH);
    break;
    }
  }
