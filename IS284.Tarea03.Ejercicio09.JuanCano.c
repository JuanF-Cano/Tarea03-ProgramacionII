/* 
- Fecha de publicación: 1/09/2024
- Hora de publicación: 4:30 pm
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

- Descripción del programa: Este programa recibe por pantalla el número de términos e imprime de la serie de Bell hasta ese número sin superarlo

    Salvedad: El programa solo funciona si se le ingresan números enteros positivos y no mayores a 24, ya que si no podría haber un desbordamiento de datos por culpa del que el número superaría la capacidad del unsigned long int. De lo contrario no se garantizan resultados 
    Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h>// Librería que contiene las funciones estándar para entrada y salida de datos

// Inicio función GetFactorial, usado para obtener el binominal. Devuelve un entero (El factorial del número ingresado) 
unsigned long int GetFactorial(int n) {
    if (n <= 1) { // Inicio condición cota
        return 1; // Devolvemos 1 para los valores de 0! y 1!
    } else {
        return n * GetFactorial(n - 1); // Llamada recursiva a la función
        // Multiplicamos n por el factorial de n - 1
    } // Fin condición cota
}// Fin función GetFactorial

// Inicio función GetBinominal que calcula el binominal de (n k) para hacer el cálculo de un término de la serie
int GetBinominal(int k, int n) {
    return GetFactorial(n) / (GetFactorial(k) * GetFactorial(n - k));
} // Fin función GetBinominal

// Escribimos el prototipo de la función para poder usar la recursividad cruzada
unsigned long int GetBell (int term);

unsigned long int SummationBell(int n, int k, int accumulator) { // Función para las sumatorias
    if (k > n - 1) { // Si el índice k es igual a n - 1, significa que ya iteramos para todos los términos
        return accumulator; // Retorna el valor acumulado
    } else {
        return SummationBell(n, k + 1, accumulator + (GetBinominal(k, n - 1)) * GetBell(k));
        // Llama recursivamente a SummationBell con el índice k incrementado y el acumulador actualizado
    }
} // Fin función SummationBell 

// Inicio función GetBell que recibe el número del término para calcular y devolver el valor de este
unsigned long int GetBell (int term) { 
    if (term <= 1) { //si es cero o uno, el término será 1
        return 1; // Caso base para la recursividad
    } else {
        return SummationBell(term, 0, 0); // Llamado recursivo a la función
        // Se pasa el número de término y se inicia el acumulador y k en 0 para la función SummationBell
    } // Fin condición cota
}; // Fin función GetBell

// Inicio función PrintBellSeries. Esta función va a imprimir la serie de Bell hasta el número de términos indicado y no devuelve nada
void PrintBellSeries(unsigned long int n1, int term, int limit) {
    // n1: Primer dígito y dígito imprimible de la serie de Bell
    // term: Contiene el número del término actual, que se usará para calcular el término a imprimir
    // limit: Contiene el límite de términos que fue ingresado por teclado

    // Imprimimos la serie de Bell siempre y cuando el número del término actual sea menor al límite ingresado
    if ( term < limit ) { // Condición cota de la función para el llamado recursivo
        printf("%lu", n1); // Imprimimos el número de la serie de Bell correspondiente, guardado en n1 
        if ( term < limit - 1 ) { // Si no está en el último dígito imprime coma ","
            printf(", "); // Imprimimos coma y espacio para mantener el orden de la impresión de la serie
        } else {
            printf(".\n"); // Imprimimos punto y salto de línea al final de la recursión para que en consola se vea más ordenado
        }
        PrintBellSeries(GetBell(term), term + 1, limit); // Llamado recursivo a la función 
        // Damos el valor de GetBell a n1 para que se imprima el valor del término actual, sumamos 1 al término y el límite se mantiene
    } // Fin de la condición cota

    return; // No devuelve nada y finaliza la función
}// Fin función PrintBellSeries

int main() { // Inicio función principal
    int limit = 0; // Variable que va a contener el número de términos a imprimir ingresados por el usuario

    // Pedimos al usuario que ingrese el número de términos que desea ver de la serie de Bell
    printf("\nIngrese el n%cmero de t%crminos que desea ver de la serie de Bell: ", 163, 130);
    scanf("%i", &limit); // Se recibe el dato y se guarda dentro de la variable limit

    printf("\n");
    // Llamado a la función que va a imprimir la serie con el primer número (1), el término siguiente (1) y el límite ingresado
    PrintBellSeries(1, 1, limit + 1); 
    
    //----------------------------------------- Finalización del programa -------------------------------------------
    getchar(); // Consumimos el carácter de nueva línea restante en el buffer
    printf("\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0; // Devuelve 0 como estándar para decir que el programa finalizó de manera correcta
} // Fin función principal