/* 
- Fecha de publicación: 1/09/2024
- Hora de publicación: 12:10 pm
- Versión de su código: 1.0
- Autor. Ing(c): Juan Fernando Cano Duque
- Nombre del lenguaje utilizado: C
- Versión del lenguaje utilizado: C11
- Nombre y versión del Sistema Operativo(S.O) sobre el que compiló y probó los ejecutables: windows 10.0.22631
- Versión del compilador utilizado: Compilado con GCC 6.3.0 (MinGW.org GCC-6.3.0-1)
- Presentado a: Doctor Ricardo Moreno Laverde
- Universidad Tecnológica de Pereira
- Programa de Ingeniería de Sistemas y Computación
- Asignatura IS284 Programación II

- Descripción del programa: Este programa recibe por pantalla el número de términos e imprime de la serie de Perrin hasta ese número sin superarlo

    Salvedad: El programa solo funciona si se le ingresan números enteros positivos y no mayores a 79, ya que si no podría haber un desbordamiento de datos por culpa del que el número superaría la capacidad del unsigned long int. De lo contrario no se garantizan resultados 
    Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h>// Librería que contiene las funciones estándar para entrada y salida de datos

// Inicio función PrintPerrinSeries. Esta función va a imprimir la serie de Perrin hasta el número de términos indicado y no devuelve nada
void PrintPerrinSeries(unsigned long int n1, unsigned long int n2, unsigned long int n3, int limit) {
    // n1: Primer dígito y dígito imprimible de la serie de Perrin
    // n2: Segundo dígito y dígito que trae el próximo dígito para la serie
    // n3: Tercer dígito y dígito que se va a operar para sacar el siguiente dígito
    // limit: Contiene el límite de términos que fue ingresado por teclado

    // Imprimimos la serie de Perrin siempre y cuando el límite no llegue a 0
    if ( limit > 0 ) { // Condición cota de la función para el llamado recursivo
        printf("%lu", n1); // Imprimimos el número de la serie de Perrin correspondiente, guardado en n1 
        if ( limit > 1 ) { // Si no está en el último dígito imprime coma ","
            printf(", "); // Imprimimos coma y espacio para mantener el orden de la impresión de la serie
        } else {
            printf(".\n"); // Imprimimos punto y salto de línea al final de la recursión para que en consola se vea más ordenado
        }
        PrintPerrinSeries(n2, n3, n1 + n2, limit - 1); // Llamado recursivo a la función 
        // Pasa n2 como n1, n3 como n2, n1 + n2 como n3 y el límite se reduce en 1 por llamado para ir descontando cada dígito impreso
    } // Fin de la condición cota

    return; // No devuelve nada y finaliza la función
}// Fin función PrintPerrinSeries

int main() { // Inicio función principal
    int limit = 0; // Variable que va a contener el número de términos a imprimir ingresados por el usuario

    // Pedimos al usuario que ingrese el número de términos que desea ver de la serie de Perrin
    printf("\nIngrese el n%cmero de t%crminos que desea ver de la serie de Perrin: ", 163, 130);
    scanf("%i", &limit); // Se recibe el dato y se guarda dentro de la variable limit

    printf("\n");
    // Llamado a la función que va a imprimir la serie con los tres primeros dígitos de esta (3, 0, 2) y el límite ingresado
    PrintPerrinSeries(3, 0, 2, limit); 
    
    //----------------------------------------- Finalización del programa -------------------------------------------
    getchar(); // Consumimos el carácter de nueva línea restante en el buffer
    printf("\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0; // Devuelve 0 como estándar para decir que el programa finalizó de manera correcta
} // Fin función principal