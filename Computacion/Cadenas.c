/* Dise~ne un programa que contenga las siguientes funciones:

 1.- Una que imprima una cadena de cualquier longitud recibida como parametro.
     ( Haga su propia logica de puts(), o sea, imprima \n al final ).
     Esta funcion retornara cero si todo salio bien y uno si ocurrio algun
     error (En nuestro caso este error solo sera "cadena esta vacia")
 2.- Una que convierta cada caracter de la cadena recibida al caracter ascii
     que sigue. El resultado se guardara en la misma cadena. No retornara nada.

 Ud. debe, desde el bloque main():

 1.- Pedir una cadena. Declare esta local y asumala de maximo 20 caracteres.
     Esta es la misma que se le pasara a las funciones 1 y 2.
 2.- Todas las funciones deben ser llamadas desde aqui.
 3.- Los mensajes deben ser impresos desde aqui tambien, excepto cuando se
     imprima la cadena con la funcion 1 ya que esta se encargara de hacerlo.
*/

#include<stdio.h>

int muestra(char a[]);
void cambia(char a[]);

main(){
    char cad[20]={0};
    printf("Introduzca una cadena: ");
    // gets(cad); // ADVERTENCIA: gets() es insegura y obsoleta. Se recomienda usar fgets().
    // Usamos fgets para leer de forma segura, limitando la entrada a 19 caracteres (20 - 1 para el nulo).
    fgets(cad, 20, stdin);
    
    /* OJO: La función gets() es extremadamente insegura ya que no verifica los límites
     de la cadena, lo que puede llevar a desbordamientos de búfer.
     La alternativa moderna y segura es fgets(cadena, tamaño, stdin).
     
     Si se usa fgets(), es posible que se capture el carácter de nueva línea ('\n').
     Si se desea eliminarlo, se puede hacer:
     size_t len = strlen(cad);
     if (len > 0 && cad[len-1] == '\n') {
         cad[len-1] = '\0';
     }
     
     La técnica de scanf("%*[^\n]") para limpiar el buffer es una solución común
     para evitar el comportamiento indefinido de fflush(stdin), pero es compleja.
     Para este ejemplo, asumiremos que fgets() es suficiente para la entrada.
    */
    printf("Inprimire la cadena con mi funcion: ");
    if (muestra(cad)) printf("NADA!!!. Esta vacia\n");
    printf("Luego de cambiar la cadena obtenemos: ");
    cambia(cad);
    if (muestra(cad)) printf("NADA!!!. Esta vacia\n");
    printf("ADIOS!!!\n\n");
    return 0;
}

int muestra(char a[]){
    int i=0;
    if (!a[i]) { putchar('\n'); return 1; }
    for(;a[i];i++)    // Es lo mismo que for(i=0;a[i]!=0;i++)
	putchar(a[i]);
    putchar('\n');
    return 0;
}

void cambia(char a[]){
    int i=0;
    while(a[i]) a[i++]++;
}


/* A continuacion les agrego dos salidas de este programa para 2 casos:

Introduzca una cadena: Cadena de Prueba
Inprimire la cadena con mi funcion: Cadena de Prueba
Luego de cambiar la cadena obtenemos: Dbefob!ef!Qsvfcb
ADIOS!!!

OTRO CASO para una cadena vacia:

Introduzca una cadena:
Inprimire la cadena con mi funcion:
NADA!!!. Esta vacia
Luego de cambiar la cadena obtenemos:
NADA!!!. Esta vacia
ADIOS!!!

*/