/* 
- Fecha de publicación: 1/09/2024
- Hora de publicación: 12:35 pm
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

- Descripción del programa: Este programa recibe por pantalla el número de términos e imprime de la serie de Catalán hasta ese número sin superarlo

    Salvedad: El programa solo funciona si se le ingresan números enteros positivos y no mayores a 9, ya que si no podría haber un desbordamiento de datos por culpa del que el número superaria la capacidad del unsigned long int. De lo contrario no se garantizan resultados 
    Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h>// Librería que contiene las funciones estándar para entrada y salida de datos

// Inicio función GetFactorial, usada para calcular los términos de la serie de Catalán. Devuelve un entero (El factorial del número ingresado) 
unsigned long int GetFactorial(int n) {
    if (n <= 1) { // Inicio condición cota
        return 1; // Devolvemos 1 para los valores de 0! y 1!
    } else {
        return n * GetFactorial(n - 1); // Llamada recursiva a la función
        // Multiplicamos n por el factorial de n - 1
    } // Fin condición cota
}// Fin función GetFactorial

// Inicio de la función GetUpperHalfFactorial para encontrar el producto de (2n)! / n!
unsigned long int GetUpperHalfFactorial(int n, int limit) {
    if (n > limit) { // Inicio condición cota
        return n * GetUpperHalfFactorial(n - 1, limit); // Lamada recursiva a la función
        // Multiplicamos n por lo que devuelve la función con (n - 1)
    } else {
        return 1; // Devolvemos 1 cuando llegué al límite para que no afecte la multiplicación
    } // Fin condición cota
} // Fin función GetHupperHalfFactorial

// Inicio función PrintCatalanSeries. Esta función va a imprimir la serie de Catalán hasta el número de terminos indicado y no devuelve nada
void PrintCatalanSeries(unsigned long int n1, int term, int limit) {
    // n1: Primer digito y digito imprimible de la serie de Catalán
    // term: Contiene el número del término actual, que se usará para calcular el termino a imprimir
    // limit: Contiene el límite de terminos que fue ingresado por teclado

    // Imprimimos la serie de Catalán siempre y cuando el número del término actual no llegue al límite
    if ( term <= limit ) { // Condición cota de la función para el llamado recursivo
        printf("%lu", n1); // Imprimimos el número de la serie de Catalán correspondiente, guardado en n1 
        if ( term < limit ) { // Si no está en el último digito imprime coma ","
            printf(", "); // Imprimimos coma y espacio para mantener el orden de la impresión de la serie
        } else {
            printf(".\n"); // Imprimimos punto y salto de linea al final de la recursión para que en consola se vea más ordenado
        }
        PrintCatalanSeries((GetUpperHalfFactorial(2 * term, term) / GetFactorial(term + 1)) , term + 1, limit); // Llamado recursivo a la función 
        // Pasa (2term)! / (term!(term+1)!) como n1 y el term (número del término actual) se aumenta en 1 por llamado
    } // Fin de la condición cota

    return; // No devuelve nada y finaliza la función
}// Fin función PrintCatalanSeries

int main() { // Inicio función principal
    int limit = 0; // Variable que va a contener el número de términos a imprimir ingresados por el usuario

    // Pedimos al usuario que ingrese el número de términos que desea ver de la serie de Catalán
    printf("\nIngrese el n%cmero de t%crminos que desea ver de la serie de Catal%cn: ", 163, 130, 160);
    scanf("%i", &limit); // Se recibe el dato y se guarda dentro de la variable limit

    // Llamado a la función que va a imprimir la serie con el primer dígito (1), 1 como número de término inicial y el límite ingresado
    PrintCatalanSeries(1, 1, limit); 
    
    //----------------------------------------- Finalización del programa -------------------------------------------
    getchar(); // Consumimos el caracter de nueva linea restante en el buffer
    printf("\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0; // Devuelve 0 como estandar para decir que el programa finalizó de manera correcta
} // Fin función principal