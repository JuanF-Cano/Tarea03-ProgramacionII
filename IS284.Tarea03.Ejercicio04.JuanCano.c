/* 
- Fecha de publicación: 1/09/2024
- Hora de publicación: 11:00 am
- Versión de su código: 1.0
- Autor. Ing(c): Juan Fernando Cano Duque
- Nombre del lenguaje utilizado: C
- Versión del lenguaje utilizado: C11
- Nombre y versión del Sistema Operativo(S.O) sobre el que compilo y probo los ejecutables: windows 10.0.22631
- Versión del compilador utilizado: Compilado con GCC 6.3.0 (MinGW.org GCC-6.3.0-1)
- Presentado a: Doctor Ricardo Moreno Laverde
- Universidad Tecnológica de Pereira
- Programa de Ingeniería de Sistemas y Computación
- Asignatura IS284 Programación II

- Descripción del programa: Este programa recibe por pantalla el número de términos e imprime de la serie de Pell hasta ese número sin superarlo

    Salvedad: El programa solo funciona si se le ingresan números enteros positivos y no mayores a 27, ya que si no podría haber un desbordamiento de datos por culpa del que el número superaria la capacidad del unsigned long int. De lo contrario no se garantizan resultados 
    Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h>// Librería que contiene las funciones estándar para entrada y salida de datos

// Inicio función PrintPellSeries. Esta función va a imprimir la serie de Pell hasta el número de terminos indicado y no devuelve nada
void PrintPellSeries(unsigned long int n1, unsigned long int n2, int limit) {
    // n1: Primer digito y digito imprimible de la serie de Pell
    // n2: Segundo digito y digito que trae el proximo digito para la serie.
    // limit: Contiene el límite de terminos que fue ingresado por teclado

    // Imprimimos la serie de Pell siempre y cuando el limite no llegue a 0
    if ( limit > 0 ) { // Condición cota de la función para el llamado recursivo
        printf("%lu", n1); // Imprimimos el número de la serie de Pell correspondiente, guardado en n1 
        if ( limit > 1 ) { // Si no está en el último digito imprime coma ","
            printf(", "); // Imprimimos coma y espacio para mantener el orden de la impresión de la serie
        } else {
            printf(".\n"); // Imprimimos punto y salto de linea al final de la recursión para que en consola se vea más ordenado
        }
        PrintPellSeries(n2, n2 * 2 + n1, limit - 1); // Llamado recursivo a la función 
        // Pasa n2 como n1, n2 * 2 + n1 como n2 y el limite se reduce en 1 por llamado para ir descontanto cada digito impreso
    } // Fin de la condición cota

    return; // No devuelve nada y finaliza la función
}// Fin función PrintPellSeries

int main() { // Inicio función principal
    int limit = 0; // Variable que va a contener el número de términos a imprimir ingresados por el usuario

    // Pedimos al usuario que ingrese el número de términos que desea ver de la serie de Pell
    printf("\nIngrese el n%cmero de t%crminos que desea ver de la serie de Pell: ", 163, 130);
    scanf("%i", &limit); // Se recibe el dato y se guarda dentro de la variable limit

    // Llamado a la función que va a imprimir la serie con los dos primeros digitos de esta (0 y 1) y el límite ingresado
    PrintPellSeries(0, 1, limit); 
    
    //----------------------------------------- Finalización del programa -------------------------------------------
    getchar(); // Consumimos el caracter de nueva linea restante en el buffer
    printf("\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0; // Devuelve 0 como estandar para decir que el programa finalizó de manera correcta
} // Fin función principal