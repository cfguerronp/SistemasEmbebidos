/*
 *        UNIVERSIDAD TECNICA DEL NORTE
 *             FICA-CITEL
 *              DEBER 12
 * Nombre: Carlos Guerrón
 * Fecha: 25/01/2021
 * Objetivo: Codificar su propia versión de algoritmo k-NN o bayesiano a su elección
 */  
 /* ////////////////// ALGORITMO KNN /////////////////
  */

#include "DatosSensores.h"
#include "DatosPrueba.h"
//variables de distancias
float distancia;
float distMen = 2500;
float distMen2 = 2500;
float distMen3 = 2500;
int i;
int k = 0;
//variable respuestas
int resp;
int resp2;
int resp3;
String datoS = "";

void setup() {
  Serial.begin(9600);//inicializa cx
  //Metodo knn hasta k=3
  for (int j = 0; j < 20; j++) {//recorrer matriz prueba
    for (i = 0; i < 200; i++) // ciclo para recorrer toda la matriz base de datos
    {
      distancia = sqrt(pow((datosPrueba[j][0] - matriz[i][0]), 2) + pow((datosPrueba[j][1] - matriz[i][1]), 2)); // calculo de la distancia

      if (distMen > distancia) //metodo para obtener la distancia menor
      {
        distMen = distancia; // asigno el valor obtenido de la distancia menor
        resp = matriz[i][2]; //asigno el grupo obtenido de los datos a una variable
      }
      if (distMen2 > distancia && distancia != distMen ) // metodo para obtener la segunda distancia mas cercana
      {
        distMen2 = distancia;
        resp2 = matriz[i][2];
      }

      if (distMen3 > distancia && distancia != distMen && distancia != distMen2 ) // metodo para obtener la tercera distancia mas cercana
      {
        distMen3 = distancia;
        resp3 = matriz[i][2];
      }

    }
    k = resp + resp2 + resp3 ; // variable que suma el valor de los grupos a los q pertenece
    Serial.println(k);

    Serial.println("DISTANCIA KNN_1");
    Serial.print(distMen);
    Serial.print(" Grupo:");
    Serial.println(resp);
    Serial.println("DISTANCIA KNN_2");
    Serial.print(distMen2);
    Serial.print(" Grupo:");
    Serial.println(resp2);
    Serial.println("DISTANCIA KNN_3");
    Serial.print(distMen3);
    Serial.print(" Grupo:");
    Serial.println(resp3);

    if (k < 4)
    { // condicion para seleccionar el grupo al q pertenece
      Serial.println("Calidad de aire buena");// para que sea del grupo 1 la suma no tiene que dar valores mayores a 4
      distMen = 2500;
    }
    else
    { // por lo tanto si el resultado de k es menor a 4 al punto se le asigna al primer grupo
      Serial.println("Calidad de aire mala");

    }
  }
}
void loop() {
  // put your main code here, to run repeatedly:

}
