/* 
- Fecha de publicación: 1/09/2024
- Hora de publicación: 6:00 pm
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

- Descripción del programa: Este programa recibe por pantalla el número de términos e imprime de la serie de Motzkin hasta ese número sin superarlo

    Salvedad: El programa solo funciona si se le ingresan números enteros positivos y no mayores a 25, ya que si no podría haber un desbordamiento de datos por culpa del que el número superaría la capacidad del unsigned long int. De lo contrario no se garantizan resultados 
    Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h>// Librería que contiene las funciones estándar para entrada y salida de datos

// Escribimos el prototipo de la función para poder usar la recursividad cruzada
unsigned long int GetMotzkin (int term);

unsigned long int SummationMotzkin(int n, int k, int accumulator) { // Función para las sumatorias
    if (k > n) { // Si el índice k es igual a n, significa que ya iteramos para todos los términos
        return accumulator; // Retorna el valor acumulado
    } else {
        return SummationMotzkin(n, k + 1, accumulator + (GetMotzkin(n - k)) * GetMotzkin(k));
        // Llama recursivamente a SummationMotzkin con el índice k incrementado y el acumulador actualizado
    }
} // Fin función SummationMotzkin 

// Inicio función GetMotzkin que recibe el número del término para calcular y devolver el valor de este
unsigned long int GetMotzkin (int term) { 
    if (term <= 1) { //si es cero o uno, el término será 1
        return 1; // Caso base para la recursividad
    } else {
        return GetMotzkin(term - 1) + SummationMotzkin(term - 2, 0, 0); // Llamado recursivo a la función
        // Se pasa el número de término y se inicia el acumulador y k en 0 para la función SummationMotzkin
    } // Fin condición cota
}; // Fin función GetMotzkin

// Inicio función PrintMotzkinSeries. Esta función va a imprimir la serie de Motzkin hasta el número de términos indicado y no devuelve nada
void PrintMotzkinSeries(unsigned long int n1, int term, int limit) {
    // n1: Primer dígito y dígito imprimible de la serie de Motzkin
    // term: Contiene el número del término actual, que se usará para calcular el término a imprimir
    // limit: Contiene el límite de términos que fue ingresado por teclado

    // Imprimimos la serie de Motzkin siempre y cuando el número del término actual sea menor al límite ingresado
    if ( term < limit ) { // Condición cota de la función para el llamado recursivo
        printf("%lu", n1); // Imprimimos el número de la serie de Motzkin correspondiente, guardado en n1 
        if ( term < limit - 1 ) { // Si no está en el último dígito imprime coma ","
            printf(", "); // Imprimimos coma y espacio para mantener el orden de la impresión de la serie
        } else {
            printf(".\n"); // Imprimimos punto y salto de línea al final de la recursión para que en consola se vea más ordenado
        }
        PrintMotzkinSeries(GetMotzkin(term), term + 1, limit); // Llamado recursivo a la función 
        // Damos el valor de GetMotzkin a n1 para que se imprima el valor del término actual, sumamos 1 al término y el límite se mantiene
    } // Fin de la condición cota

    return; // No devuelve nada y finaliza la función
}// Fin función PrintMotzkinSeries

int main() { // Inicio función principal
    int limit = 0; // Variable que va a contener el número de términos a imprimir ingresados por el usuario

    // Pedimos al usuario que ingrese el número de términos que desea ver de la serie de Motzkin
    printf("\nIngrese el n%cmero de t%crminos que desea ver de la serie de Motzkin: ", 163, 130);
    scanf("%i", &limit); // Se recibe el dato y se guarda dentro de la variable limit

    printf("\n");
    // Llamado a la función que va a imprimir la serie con el primer número (1), el término siguiente (1) y el límite ingresado
    PrintMotzkinSeries(1, 1, limit + 1); 
    
    //----------------------------------------- Finalización del programa -------------------------------------------
    getchar(); // Consumimos el carácter de nueva línea restante en el buffer
    printf("\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0; // Devuelve 0 como estándar para decir que el programa finalizó de manera correcta
} // Fin función principal