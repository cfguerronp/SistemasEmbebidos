/*    UNIVERSIDAD TECNICA DEL NORTE
*        FICA-CITEL 
*        DEBER 10
* Nombre: Carlos Guerron
* Fecha: 11/01/2021
* Objetivo: Realice una interfaz que permita mover una esfera por toda la pantalla mediante teclas.
*/
  int directionx= 300; // Inicializamos variables para que empiece en el centro nuestra elipse
  int directiony= 300; //  estas variables son para que se pueda mover por la direccion x e y
 void setup(){
  size(600,600); 
  background(229,187,32); 

}
  void draw(){
  if(keyPressed){  // condicion para que detecte el presionar de la tecla
    switch(keyCode){  // switch con el codigo de las teclas de arrriba, abajo, izqueirda, derecha
      case 40:  // arriba
        directiony += 8;  // le aumentamos a la variable para que se mueva hacia arriba
      break; 
      case 38: // abajo
        directiony -= 8; // le disminuimos a la variable para que recorra hacia abajo
      break;
      case 37:  //izquierda  
        directionx -= 8; // le disminuimos a la variable para que recorra hacia la izquierda
      break;
      case 39:  // derecha 
        directionx += 8;  // le aumentamos a la variable para que se mueva hacia la derecha
      break;
    }
    background(229,187,32);
    if(directionx>=575)  // Creamos condicones para que la elipse solo  llegue hasta el extremo de la pantalla 
      directionx=575;
    if(directiony>=575)
      directiony=575;
    if(directionx<=25)
      directionx=25;
    if(directiony<=25)
      directiony=25;
      
    fill(#3527D6); //color de la circunferencia
    stroke(0); // color de linea
    strokeWeight(3); // tama;o de linea de la elipse
    ellipse(directionx,directiony,50,50); // creamos nuestra ellipse
  
}
  
  }
