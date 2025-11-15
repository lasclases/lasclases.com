#include <stdio.h>
#include <conio.h>

// Todos los archivos con extension .h ( o archivos de cabecera ) lo que
// hacen es incluir prototipos de funciones. Por ejemplo: stdio.h, contiene
// el prototipo de la funcion printf() por lo que es requerida para usar 
// dicha funcion. Las funciones deben estar declaradas ( prototipadas )
// antes de ser usadas.
// Otros archivos de cabecera muy usados son:
/*
        alloc.h -> Asignacion dinamica de memoria.
        bios.h -> Funciones de interfaz con el BIOS
        errno.h -> definicion de varios codigos de error
        graphics.h -> funciones graficas
        io.h -> funciones de I/O de bajo nivel
        math.h -> funciones matematicas
        stdlib.h -> funciones variadastime.h -> funciones de hora y fecha.
*/

// Es buena idea agregar la definicion de todas las funciones propias aqui, al
// principio del codigo y luego desarrollar las mismas al final. Ejemplo:

    // La siguiente funcion usa una llamada por Valor.
int cuadrado (int x); // Declara una funcion que recibe un valor entero
        // como parametro y retorna uno entero como resultado. Al final 
        // del codigo esta desarrollada la funcion.
        // Las declaraciones se usan para que el programa sepa anticipada-
        // mente que tipo de variables recibira o retornara una funcion.
        // Esto es de vital importancia cuando estos tipos no son int ( que
        // es el que se toma by default ). Si no reciben parametros ni retor-
        // nan ninguno, se usa el prototipo: void nombreFunc(void);

    // La siguiente funcion usa una llamada por Referecnia.
void intercambia (char *x, char *y); // Declara una funcion que recibe un puntero ( VER
    // PUNTEROS MAS ADELANTE ), o sea, que recibe la direccion de memoria
    // en la cual se encuentra una variable de tipo entero.
void intercambia2 (char *x, char *y); // Otra version de la misma funcion.
    // En esta funcion trabajaremos con las direcciones y no con los contenidos.
    // La idea es mostrar una diferencia fundamental. Vea las funciones al final.

// Aqui tambien pueden ser declaradas las variables globales. Aquellas que
// seran podran ser usadas en todo el programa dentro de cualquier funcion.
int GLOBAL;
// Pero el uso de estas variables debe limitarse a aquellas que sean realmente
// necesarias ya que estas ocupan memoria durante toda la ejecucion del progra-
// ma, no ayudan a modularizar el programa y que pueden generar efectos secunda-
// rios desconocidos debido a que pueden alterar el valor en cualquier momento
// alterando otros resultados. Esto es un dolor de cabeza en programas muy
// grandes generando fallas que no son faciles de detectar.

int main(void) { // Aqui main no recibe argumentos, pero podria. Ver
                // "Argumentos de main" mas a delante.
    // PRIMERO QUE NADA. Siempre deben comentar su codigo. Esto les facili-
    // tara su lectura al momento de la revision. Deben colocar comentarios
    // explicitos y no absurdos como:
    // i = 3;  // Asigno el valor de 3 a la variable i. POR FAVOR. Lo he visto.
    // mejor seria:
    // i = 3; // Asigno al contador la cantidad de veces que se ejecutara...
    // Los comentarios pueden agregarse de una sola linea, empezando la misma
    // con : "//" como han visto hasta ahora. O si son de varias lineas con:
    /* Comentario
    de
    varias
    lineas */
    // Exacto, empieza por /* y termina en */
    //
    // Tipos de Variables.
    // LAS VARIABLES PUEDEN SER DECLARADAS A CUALQUIER ALTURA DEL CODIGO.
    // Sin embargo, se recomienda realizar todas las declaraciones al principio
    // del codigo para mantener una mayor legibilidad del mismo.
    char ch, ch2; // Variables tipo char. Ocupa 1 byte -> 0..255
    int i, cont, q; // Variable de Enteros. Ocupa 2 bytes -> -32.768 a 32767
    float f; // Coma flotante. 
            // Numeros Reales. Ocupa 4 bytes -> 3.4E-38 a 3.4E+38
    double d; // Coma flotante doble precision.
            // Numeros Reales. Ocupa 8 bytes -> 1.7E-308 a 1.7E+308
    // Los dos ultimos tipos (float y double) contienen
    // un componente entero y otro fraccionario
    // Tambien estas variables pueden ser midificadas por:
    //    signed, unsigned, long y short
    // dependiendo de en que casos aplique. Por ejemplo:
    // long int i; -> representa un entero entre -2147483648 y 2147483647
    // por lo que ocupa 4 bytes ( el doble de lo normal )
    // Otro ejemplo seria p.ej:
    // unsigned int i; -> Aun de 2 bytes pero el rango es: 0 a 65535
    const float pi = 3.1415926;
    const int ConstI = 100; // Declara una constante. Este tipo de variables
        // pueden ser inicializadas. Luego de esto el valor no puede variar.
        // otro ejemplo seria -> const float pi = 3.1415926;
    // Se pueden declarar varias variables del mismo tipo en una misma
    // sentencia. Estas deben estar separadas por una como. P.Ej:
    // int a,b,c; -> declara a, b y c como variables de tipo enteras.
    // Todas las variables son locales y solo son reconocidas dentro de su
    // propio ambito, funcion o bloque ( Entiendase esto ultimo como que las
    // variables pueden ser declaradas dentro de un bucle de control if{},
    // while{}, etc y aun asi serian locales dentro de este bloque. Se crean
    // dentro de el y son destruidas al salir del mismo ). Por ejemplo todas
    // estas variables de ejemplo (ch, i, f y d), son solo
    // reconocidas dentro de main y no dentro de otras funciones. esto nos
    // permitiria usar el mismo nombre de variables dentro de distintas fun-
    // ciones, aunque personalmente no lo recomiendo a menos que sean variables
    // para contadores u otras operaciones de control.
    // Existe otro tipo de variable llamada "void" que ocuap cero bytes y que
    // es usada para declarar que una funcion no recibe ningun parametro como:
    // int funcion(void); o que no retorna ningun valor: void funcion(int x);
    //
    // Otra cosa importante en la declaracion de las variables son los llamados
    // especificadores. Estos son : extern, static, register y auto.
    // su forma de uso es: especificador tipo nombre; p.ej: extern int i;
    // auto es el tipo predeterminado de todas las variables por lo que este
    // especificador practicamente no se usa.
    // Dado que C permite enlazar juntos distintos modulos de un mismo programa
    // que son compilados por separado ( lo que ayuda a la gestion de grades
    // proyectos ), debe haber una forma de hacer conocer a todos los archivos
    // las variables globales requeridas por el programa. extern se encarga de
    // esto. Indica que la declaracion ya se ha hecho en otra parte. Por lo
    // tanto si tienes la declaracion de la variable global en un programa y
    // debes usar la misma dentro de otro modulo, lo unico que se debe hacer
    // es declarar la variable en el programa principal y declararla ( con el
    // mismo nombre ) como extern en los modulos. Asi si tenmos "archivo 1" y
    // este incluye un modulo llamdo "archivo 2" ( quien tambien necesita de las
    // variables globales definidas en "archivo 1" ), se hace las declaraciones:
    //  archivo 1                archivo 2
    //    int x,y;                extern int x,y;
    // Las variables "static" son muy importantes. Son variables que solo son
    // reconocidas dentro de su propio bloque pero que el valor de la misma per-
    // manece entre llamadas a la funcion, o sea que no se destruye el valor
    // al salir del bloque. En otras palabras: las variables "static" son varia-
    // bles permanentes pero difieren de las globales en que no son conocidas
    // fuera de su funcion.
    // Se puede declarar una variable global como static y esto lo que haria es
    // impedir que esta variable sea usada y conocida solo dentro del modulo
    // actual y no en todo el proyecto.
    // Como ultimo tipo tenemos el muy especial register. una variable de tipo
    // register pide al compilador que coloque el valor de esta variable direc-
    // tamente dentro de un registro del CPU en lugar de en memoria para asi
    // poder tener acceso a esta mucho mas rapida. Solo se puede usar en varia-
    // bles locales. Estas variables son ideales para bucles para casos el lo
    // que la velocidad de proceso de informacion es critica. Personalmente
    // les recomiendo el acostumbrase a su uso en
    // los casos en que se hagan muchas referencias a la misma variable.
    //
    // Constantes de caracter con barra Invertida.
    // estos son:
    /*  \b Espacio atras
        \f Salto de Pagina
        \n Salto de linea
        \r Retorno de carro
        \t Tabulacion
        \" Comilla doble
        \' Comilla simple
        \0 Nulo
        \\ Backslash
        \v Tabludaor Vertical
        \a Alerta
        \o Constante Octal
        \x Constante hexadecimal */
    // Operadores aritmeticos:
    // Resta "-", suma "+", Multiplicacion "*", Division "/", Division en 
    // modulo "%", decremento "--" e incremento "++"
    // Ejemplo X=X+1; puede ponerse como: x++; o como ++x;
    // Sin embargo existe una diferencia entre estas dos ultimas y es que
    // y=10; x = ++y; -> entonces x= 11 y y=11 ( incrementa y luego asigna )
    // y=10; x = y++; -> entonces x =10 y y=11 (Primero opera y luego inc )
    // La precedencia de los operadores aritmeticos es:
    // ++ -- Se hace primero
    // * / %
    // + - Se hace de ultimo
    //
    // Operadores relacionales y logicos.
    // Mayor que ">", Mayor o Igual que ">=", Menor que "<", Menor o Igual que
    // "<=", Igual "==" y distinto "!=" son los relacionales.
    // Los logicos son: AND "&&", OR "||" y NOT "!"
    // La precedencia de estos es:
    // !
    // > >= < <=
    // == !=
    // &&
    // ||
    //
    // Operadores a nivel de bits:
    // AND (&), OR (|), XOR (^), Complemento a uno (~), desplazamiento a la
    // derecha (>>) y desplazamiento a la izquierda (<<).
    //
    // Los operadores ?, & y *
    // y = (x>9) ? 100 : 200; es lo mismo que decir
    // if (x>9) y=100; else y=200;
    //
    //Los otros dos son operadores monarios que se usan para los punteros.
    //Los operadores son '&' y '*'( Luego profundizaremos en esto ).
    // Operadores:
    // sizeof NombreVariable; retorna el tamaño de la variable. (Portabilidad)
    // , => x=(y=3, y+1); => x=4 otro ej: y=10;x=(y=y-5,25/y); => y=5
    // el "." y el "->" Se usan en estructuras ( y en objectos en c++ )
    //    para referenciar variables o partes de las estructuras (u objetos).
    /*    p.ej: struct empleado {
                    char nombre[80];
                    int edad;
                    float sueldo;
                 } emp;  // emp es una variable de tipo empleado. */   
    //     *p = &emp; // pone en p la direccion de emp. Podemos usar:
    //    emp.sueldo=100; o referenciandola por punteros
    //    p->sueldo=100;
    //
    // Los () y [] aumentan la precedencia de lo que contienen.
    //
    // x=x+10; se puede escribir como x+=10; Es una abreviatura que se
    // puede usar con el resto de los operadores.
    //
    //######################################################################
    // PUNTEROS
    int *p;  //Esta expresion declara una variable p que es un puntero a entero,
    /* lo que quiere decir que 'p' contendra la direccionde memoria de una
    variable de tipo entero. No es lo mismo tener un puntero a char que un
    puntero a int. P.Ej:
    char *pc;
    int *pi;
    Ambas variables (pc y pi) son punteros, o sea, que contienen una direccion
    de memoria. La diferencia entre estas dos declaraciones se refleja princi-
    palmente si se van a realizar operaciones sobre este puntero. Si al puntero
    *pc se le suma 1, este apuntara a la proxima direccion de memoria que en
    el caso de un char es 1 byte despues. En el caso de int es 2 bytes despues.
    VER Tipos e VAriables mas arriba.
    */
    /* Un puntero es una variable que contiene una direccionde memoria.
    Los punteros tienen usos muy importantes dentro del lenguaje pero yo
    diria que el mas importante es que proporcionan el medio para poder
    parsar parametros por referencia a las funciones. La forma normal para
    pasar datos a una funcion es por valor. VER FUNCIONES 
    Como vimos en la seccion de operadores, los que se usan para punteros 
    son el '&' y el '*'. El '&' es un operador monario ( un operador que actua 
    solo sobre un elemento. ).  '&' devuelve la direccion de memoria
    de la variable que precede. P.Ej: p = &cont;  coloca en p la direccion
    de memoria en la que se encuentra la variable cont. NO ES EL VALOR DE
    cont. Es Donde esta ese valor. P.Ej: cont = 100 y se encuentra en la
    direccion de memoria 12345 => p=&cont asigna 12345 a m, NO 100.
    El operador monario * es el complementario ( Aparte de su uso en la
    declaracion de punteros ). Lo que quiero decir con complementario es que
    siguiendo el mismo ejemplo anterior, si q=*p entonces se asigna 100
    a la variable q ya que *p significa el Valor que se encuantra en la
    localidad de memoria a puntada por la direccion p.    */

    cont = 100; // Asigna el valor 100 a la variable entera cont.
        // El anterior fue un buen ejemplo de como no se deben hacer
        // los comentaiors, pero en este caso es para ejemplificar mi punto.
    p = &cont; // Asigna a 'p' ( quien se definio como un puntero a entero )
        // la "DIRECCION DE MEMORIA" en la cual se encuentra el valor
        // ed la variable cont. Po lor tanto, P = "Un numero raro aqui", no 100
    q = *p; // Asigno a 'q' el contenido de lo que se encuentra en la direccion
        //de memoria p. => q = 100.
        // OJO: OPERACION CON PUNTEROS.
    // Una opcion tambien posible y muy poderosa es los punteros a funciones.
    // Ese tema no lo abordaremos por ahora.
    // El mal uso de punteros es peligroso. Un error con punteros puede colgar
    // el programa e incluso al mismo sistema operativo.  Uno de los problemas
    // mas comunes es por el uso de punteros no inicializados.
    // Vean los siguientes ejemplos y digan que ven mal:
    /*
        #include <stdio.h>
        main(void) {
                int x, *p;
                x = 10;
                p = x;
                printf("%d", *p);
                return 0;
        }
	
	por supuesto ( p = x ) es un error.        


        OTRO
        
        main (void) {
                int x, *p;
                
                x = 10;
                *p = x;
                return 0;
        }

	asigna 10 al contenido de un puntero que aun no se ha inicializado

     */
    // system("cls"); // Ejecuta una orden de sistema, en este caso cls
    // Mejor usaremos:
    clrscr();
    // Impresion de la tabla ASCII
    for (i=0;i<256;i++) {
        printf("(%i,%c) ",i,i);
    }
    printf("\n\n");
    sleep(3); // Espera 3 segundos
    printf("%c",'\a'); // Imprime el caracter especial '\a' lo que en realidad
        // es que emite un pitido.
    /* Sentencias de control
       La mayoria de las sentencias de control se basan en una prueba
       condicional. O es Cierto o es Falso.
       if (expresion) sentencia; else sentencia; //Recuerden que se puede usar
                                                 //el operador ?
       if (expresion) { sentencias } else { sentencias }
       //
       if anidados: if (exp1)
                     if (exp2) sent;
                     else sent;               Ó
                    if (exp1) {
                     if (exp2) sent; }
                    else sent;
       //
       if-else-if
       if (exp)
        sent;
       else if (exp)
        sent;
       else if (exp)
        sent;
       else
        sent;
       //
       switch
       switch(variable){
              case const1:
                secuencia de comandos
                break;
              case const2:
                secuencia de comanods
                break;
              .
              .
              default:
                secuaencia de comandos
       } 
       Si se omiten los break, el codigo seguira ejecutando el resto de los
       casos buscando a otro que aplique. la sentencia "break" se usa dentro 
       de cualquier sentencia o bucle de control para salir de el.
       OJO: Los switch, al igual que el resto de las sentencias y bucles,
       se pueden anidar.
       //
    BUCLES
       for(x=100; x!=x; x-=5) {
              sentencias;
       }
       otro ej usando el operador "," para encadenar expresiones y asi ambas
       variables controlen el bucle:
       for(x=0, y=0; x+y<10; ++x) {
         sentencias;
       }
       otro: for(;;) printf("ad infinitum");
       otro: for(;;){ c=getchar(); if (c=='A') break; }
       WHILE
       while(condicion) sentencia;
       DO/WHILE
       do { secuencia de sent; } while(condicion);
    BREAK.
       Finaliza un case de la sentencia switch como tambien termina inmediata-
       mente la ejecucion de un bucle tal y como vimos en el ejemplo del for
       infinito.
    continue
        Es similar a break pero este no termina el bucle sino que fuerza una
        nueva iteracion. P ej:
        do {
                ch=getchar();
                if(ch=='A') continue;
                printf("%c",ch);
        while (ch!='x');
        imprimira todo los caracteres que se introduzcan menos la 'A' que
        fuerza a ir a la siguiente iteracion por lo que el printf no se ejecuta.
    GOTO
        En desuso ya que un lenguaje de programacion estructurado como el
        C posee suficientes recursos como bucles y sentencias para evitarlo,
        aun asi existe. Ej:
        bucle1:
          if(exp) goto bucle1;
          etc...
    exit()  -> Finaliza de inmediato la ejecucion de un programa 
    Su forma es void exit(int estado); // si estado = 0 => todo normal
    pero se pueden expresar otros numeros como codigos dfe error.   
    */
    //
    // FUNCIONES
    // ir al final del archivo y observar el ejemplo de funcion llamado
    // cuadrado.
    do {
        printf("Introduzca una letra (x para salir): ");
        ch=getchar();
        fflush(stdin);  // Por si acaso se introdujo un caracter de control.
    } while( ch != 'x' );
    printf("\n");
    printf("Introduzca un numero: ");
    scanf("%i",&i);
    printf("El cuadrado del numero %i es: %i\n", i, cuadrado(i));
    ch = 'a';
    ch2 = 'Z';
    printf("\nEn este momento ch=%c y ch2=%c\n",ch,ch2);
    intercambia(&ch, &ch2);
    printf("Luego de ejecutar intercambia, ch=%c y ch2=%c\n", ch, ch2);
    intercambia2(&ch, &ch2);
    printf("Ejecutamos la verion intercambia2, ch=%c y ch2=%c\n", ch, ch2);
    printf("Exacto, no cambiaron. Lean el codigo\n");
    // Exacto, funciona en la funcion pero no aqui. Ver mas datos en el
    // desarrollo de la funcion. Pensar en esto.
    system("pause"); // Para no se cierre la ventana de DOS y ver el resultado.
    //clrscr(); // Definida en conio.h
    //textcolor(1); // Definida en conio.h
    //textbackground(4); // Definida en conio.h
    printf("Texto de prueba\n");
    system("pause"); // Para no se cierre la ventana de DOS y ver el resultado.
    return 0;
}

//##########################################################################
// FUNCIONES
// Esta funcion recibe una valor entero y devuelve el cuadrado del mismo.
    /*El paso de el parametro se realiza por valor. Eso quiere decir que la
    variable con la que se hace la llamada desde el bloque main permanece 
    igual*/
    /*Pasando los datos por referencia, se pueden alterar los valores de las
    variables originales con las que se realizo el llamado a la funcion. Si
    se pasan por valor, solo se alteraran los valores de las variables dentro
    la funcion. Los paso de variables por referencia se realizan con punteros.
    Se les llama por referencia porque lo que recibe la funcion es precisamente
    una referencia de donde esta la variable con la que se desea trabajar. En
    realidad, al pasar un variable por referencia a una funcion lo que se le
    esta enviando es la direccion de la memoria que contiene el valor de la
    variable con la que se desea operar. Se puede ver que si se trabaja con
    el contenido de esta direccion de memoria, este cambio se vera reflejado
    para todo el programa*/
int cuadrado (int x) { // Ejemplo de una funcion que recibe un entero como
    // parametro y retorna otro entero como resultado. 
    // ( YA QUE CUANDO NO SE DECLARA EXPLICITAMENTE UN TIPO DE
    // VARIABLE COMO RETORNO, SE TOMA int BY DEFAULT. De todas formas pre-
    // fiero declarar las funciones completas tanto en el prototipo como
    // en el desarrollo de la misma y asi evitarme cualquier warning )
    // OJO OJO: Por convencion, el prototipo de las funciones deben ser 
    // declaradas al principio del archivo.
    // Estos parametros conocidos como "formales" se comportan como variables
    // locales de la funcion, o sea se crean al entrar y se destruyen al salir
    // a menos qe se declaren static.
    // Las llamadas a funciones pueden ser por valor o por referencia.
    // este caso es por valor y se pasa a la funcion una copia estatica del
    // valor de la funcion. La funcion trabaja sobre esta y retorna el resultado
    // pero el valor original de la variable en el codigo que llamo a la funcion
    // permanece sin alterar.
    // En el caso de la llamda por referencia, lo que se le envia a la funcion
    // es la direccion ( ojo con esto ) de la variable. Por lo tanto, cualquier
    // operacion sobre la variable, alteraria el valor original de la misma.
    // una declaracion por referencia seria:
    // int cuadrado (int *x);
    // en este caso, al llamar a esta funcion desde el bloque main, cuya llamada
    // debe ser: cuadrado(&i); ya que debe pasar la direccion de la variable,
    // y debido al codigo que sigue:
    x*=x; // x=x*x
    // el valor original de la variable en el bloque main (contenido de i)
    // tambien variara. Esta forma tiene muchas ventajas que observaran a
    // medida que desarrollen programas.
    // En el unico caso que esto no aplica es en el paso de cadenas a funciones
    // y esto es por... OJO-> a que solo se pasa la dierccion del array y no
    // una copia del mismo ( es una llamada por referencia ). Cuando se llama
    // a una funcion con un nombre de array, se pasa a la funcion un puntero
    // al primer elemento del array. Esto es debido a la forma en que C maneja
    // los arays. En C, un nombre de array sin indice es un puntero al primer
    // elemento. Luego profundizaremos en cuanto a los arrays pero ahora enfo-
    // quemos la atencion en las 3 formas de declarar un parametro que va a
    // recibir un puntero a array. Teniendo el siguiente codigo:
    /*  #include
        void func(int cad[7];
        main(void) {
          int a[7], i;
          for(i=0;i<7;++i) a[i]=i;
          muestra(a);
          return 0;
        }
    la primera forma de declararla es:
        void muestra(int miCad[7]) {
          register int i;
          for(i=0;i<7;i++) printf("%i", miCad[i]);
        }
    Aqui, aunque miCad se declara como un array de enteros de 7 elementos,
    el compilador automaticamente lo convierte en un puntero a entero. Esto
    es asi porque ningun parametro puede recibir un array de enteros. Asi, solo
    se pasa el puntero al array por lo que debe haber un parametro de tipo 
    puntero para recibirlo.
    
    La segunda forma es:
        void muestra(int miCad[]) {
          register int i;
          for(i=0;i<7;i++) printf("%i", miCad[i]);
        }
    donde miCad se declara como un array de tamaño desconocido. (OJO: C no
    comprueba los limites de los arrays esto debe hacerlo el programador en
    el caso de que sea necesario. Un descontrol en las cadenas puede generar
    sobreescritura del area de memoria. Luego ahondaremos. OJO ) Este metodo
    define a miCad como un puntero a entero.
    
    La ultima forma, y la que usaremos, es la mas comun en los programas
    profesionales escritos en C, es declarandolo directamente como un puntero.
        void muestra(int *miCad) {
          register int i;
          for(i=0;i<7;i++) printf("%i", miCad[i]);
        }
    esto se puede ya que cualquier puntero puede ser indexado usando [] como
    si fuese un array. Los punteros y los arrays estan intimamente relacio-
    nados. Muy Poderoso pero inimaginablemente peligroso :-).
    
    Todos los metodos producen el mismo resultado -> un puntero.
    Un elemento de un array que se use ya sea como argumento o de otra forma
    en un programa es tratado como una variable normal. Asi:
        x = a[i]; es una declaracion normal de variables. X es entero de la
        misma forma que a[i] es un entero. Se puede pasar muestra(a[i]) y esta
        sera tratada como cualquier otro entero.
    Entonces:  CUANDO SE USA UN ARRAY COMO ARGUMENTO DE UNA FUNCION, ES SU
    DIRECCION LO QUE SE PASA A LA FUNCION. No EXISTE paso por valor de cadenas
    en C. Cuando operas sobre el contenido de una cadena dentro de una funcion,
    en realidad estas operando sobre el contenido de dicha cadena. OJO con eso.
    */
    /*
    Argumentos de main.
      main puede recibir argumentos. Esto es:
      int main(int argc, char *argv[])
      donde el parametro argc es el numero de argumentos ed la linea de ordenes
      y que siempre vale 1 por lo menos ( el nombre del programa ). El argumento
      argv es un puntero a un array de punteros a caracteres (char). Cada ele-
      mento del array apunta a un argumento de la linea de ordenes. Todos los
      argumentos de la linea de ordenes son cadenas.
      
    
        
    */
    return (x); //return se usa para finalizar el bloque y retornar algun
            // resultado, si es necesario. Puede usarse varias veces dentro de
            // una funcion ya que como fuerza la salida inmediata de la misma
            // se puede usar dentro de p.ej un bucle if que retorne varios
            // resultados dependiendo de alguna condicion.
            // if (exp1) return 0;
            // if (exp2) return 1; etc.
}

    // Ahora desarrollaremos la funcion intercambie. Esta funcion no retorna
    // ningun Valor y recibe la direccion de memoria de dos variables. Este
    // tipo de funcion recibe lo que se conoce una "llamada por referencia"
    // En este caso no trabajos con versiones locales de la misma variable
    // ( no solo con el valor ) sino con las direcciones de ellas.
void intercambia (char *x, char *y) {
    char temporal;
    
    printf("%#x, %#x, %c, %c\n", x, y, *x, *y); // Esto imprimira dos numero
        // hexadecimales ( el simbolo # agrega 0x al principio del numero
        // y tambien puede usarse %#hx para que imprima 0x y el hexadecimal
        // en formato short ( lo hace la h ) ). Estos numeros hexadecimales
        // seran las direcciones de memoria en las que se
        // encuentran las variables x,y y luego los valores de las mismas.
        // Se vera algo como: 0x22ff6f, 0x22ff6e, ch=a, ch2=Z
    temporal = *x; // Salvo el contenido de la direccion en x.
    *x = *y;       // Coloco el contenido de y en el de x
    *y = temporal;       // Asigno el valor original de x a y.
}

void intercambia2 (char *x, char *y) {
    char *temporal;

    temporal = x; // Salvo la direccion en la que se encuentra x.
    x = y;       // Salva el puntero en y en x. Este tipo de asignaciones
        // tambien esta permitida en los punteros.
    y = temporal;       // Asigno la direccion original x a y.
    printf("Dentro de la funcion intercambia2, *temporal=%c, *x=%c, *y=%c\n", *temporal, *x, *y);
    // Esto se imprimira bien, pero en el main no se cambiaran los valores.
    // Esto es porque jugamos con las direcciones aqui adentro, pero estos
    // valores son locales. Los contenidos no se cambian. No hizo nada.
    // Si se queria cambia el contenido tendriamos que haberlo definido
    // como punteros a punteros.
}
