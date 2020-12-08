/*
 *          DEBER 6
 * Nombre: Carlos Guerrón
 * Fecha: 09/12/2020
 * Objetivo: Realizar un reloj con alarma ingresada por comunicación serial.  Los números sean vistos en displays.
 * 
 */
#include<LiquidCrystal.h> 
#include<MsTimer2.h>

LiquidCrystal lcd (13,12,11,10,9,8);

int segundos=0;  // variables que usamos para el reloj
int minutos=0;
int horas=0;
int btnH = 3; //Valores de pindes los botenes para igualar hora en reloj
int btnM = 4;
int led=5; // led que muestra la alarma 
String alarmHrs;  //Dato que seran ingresado por cx serial para la alarma
String alarmMin;
int hAlarm=70;  // variable para incializar las horas dela alarma
int mAlarm=70;  // variable para inicialziar los minutos de la alarma
int onOff=0; // variable para el encendido del sistema
int i=0; // variable para secuencia de luz de la alarma
 
void setup() {
  lcd.begin(16,2);  //inicializamos lcd
  Serial.begin(9600);  //iniciamos la cx serial
  Serial.println("       Deber 6  ");  
  Serial.println("Carlos Guerron");
  Serial.println("Alarma: ");
  MsTimer2::set(1000,reloj);  // declaramos el timer 2 con el emtodo reloj
  MsTimer2::start();
  attachInterrupt(0,actAlarm,LOW);  //activamos una interrupcion 
  pinMode(led,OUTPUT);  
  pinMode(btnH,INPUT);
  pinMode(btnM,INPUT);
}

void loop() {
if(onOff==1){
  if(Serial.available()>0){
    alarmHrs=Serial.readString();
    hAlarm=alarmHrs.toInt();
    if(hAlarm<24)
    Serial.println("Hora registrada.");
    else
    Serial.println("Ingrese valores hasta 23 horas");
    }
  }
  if(onOff==2){
    if(Serial.available()>0){
    alarmMin=Serial.readString();
    mAlarm=alarmMin.toInt();
    if(mAlarm<60)
    Serial.println("Minutos registrados.");
    else
    Serial.println("Ingrese valores hasta 59 minutos");
    
    }
  }
  if(hAlarm==horas && mAlarm==minutos){
    while(i<15){
      digitalWrite(led,HIGH);
      delay(700);
      digitalWrite(led,LOW);
      delay(700);
      i++;
      }
    }
  
}

void actAlarm(){
  switch(onOff){
    case 0:
    Serial.println("Horas: ");
    onOff++;
    i=0;
    break;
    case 1:
    Serial.println("");
    Serial.println("Minutos: ");
    onOff++;
    break;
    case 2:
    Serial.println("");
    Serial.println("Fin de Configuracion");
    hAlarm=70;
    mAlarm=70;
    onOff=0;
    break;
    }
  }
  
void reloj(){
  if(segundos<60)
  segundos++;
  else{
    segundos=0;
    if(minutos<60)
    minutos++;
    else{
      minutos=0;
      if(horas<24)
      horas++;
      else
      horas=0;
      }
    }
    if(digitalRead(btnH)==HIGH){
      if(horas<24)
      horas++;
      else
      horas=0;
      }
      
    if(digitalRead(btnM)==HIGH){
      if(minutos<60)
      minutos++;
      else
      minutos=0;
      }
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("DEBER 6 GuerronC");
    lcd.setCursor(0,1);
    lcd.print(String(horas)+String(":")+String(minutos)+String(":")+String(segundos));
  }
