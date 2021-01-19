/*
 *   UNIVERSIDAD TECNICA DEL NORTE
 *       SISTEMAS EMBEBIDOS
 *           DEBER 11
 * Nombre:Carlos Guerrón
 * Fehca: 20/01/2021
 * Objetivo: Realice la regresión lineal exponencial dentro del entorno de Arduino con el conjunto de datos estatura-peso. 
 * Con esto, ingrese por comunicación serial los nuevos datos de estatura e imprima el pronóstico del peso.
 * 
 */

 int matriz [14][2]{
 {170,67},
{180,80},
{170,65},
{178,75},
{160,55},
{163,60},
{165,63},
{170,70},
{164,62},
{176,77},
{164,60},
{170,76},
{170,56},
{168,60}, 
  };
int col=0;
int fil=0;
int Ex=0;  //sumatoria de x
int Ey=0; //sumatoria de y
long int Exy=0; //sumatoria de xy
long int Ex2=0; //sumatoria de x^2
long int Ex_2=0; //sumatoria de (Ex)^2
float Ylog=0;
int n=14; //tam de muestras
float Bo; //Ordenada en el origen
float mLog; //pendiente
int m;
int m1; //aux
String dato;  //recibir estatura
int estatura;  //convertir 
float peso;
float aux=0;
void setup() {
  Serial.begin(9600);
  //creacion del modelo
  for(;fil<n;fil++){
      Ex=Ex+matriz[fil][0];
      Ey=Ey+matriz[fil][1];
      Ylog=Ylog+log(matriz[fil][1]);
      Exy=Exy+(matriz[fil][0]*log(matriz[fil][1]));
      Ex2=Ex2+pow(matriz[fil][0],2);
    }
    Ex_2=pow(Ex,2);
    Bo=((float(n*Exy)-float(Ex*Ylog))/(float(n*Ex2)-float(Ex_2)));
    aux=float(Bo*(Ex/n));
    mLog=(float(Ylog/n))-aux;
    m=float(exp(mLog));
    Serial.println("El modelo es: ");
    Serial.println(String("y= ")+String(m)+String("e^(")+String(Bo)+String("*x)"));
    Serial.println("Ingrese su estatura: ");
}

void loop() {
  if(Serial.available()>0){
      dato=Serial.readString();
      estatura=dato.toInt();
      peso=m*exp(Bo*estatura);
      Serial.println(String("Su peso es: ")+String(peso)+String("Kg"));
      Serial.println("Ingrese su estatura: ");
  }
}
