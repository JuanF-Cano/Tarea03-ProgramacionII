/* 
- Fecha de publicación: 3/09/2024
- Hora de publicación: 12:35 pm
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

- Descripción del programa: Este programa imprime un patròn conocido

    Salvedad: Solo funciona en sistemas windows. Se debe presionar enter para finalizar el programa correctamente
*/

#include<stdio.h>
#include <windows.h> 

// Inicio función PrintSpaces
void PrintSpaces(int counter){
    if(counter > 0){ // Imprime la cantidad de espacios indicados en el llamado inicial
        printf(" "); // Imprime espacio
        PrintSpaces(counter - 1); // Llamado recursivo que va hasta que counter sea 0
    }
} // Fin función PrintSpaces

// Inicio función PrintLetter
void PrintLetter(int counter){
    if(counter > 0){ // Hace el proceso el número de veces indicado (40)
        PrintSpaces(40 - counter); // Imprime los espacios
        printf("A"); // Imprime la letra A
        PrintSpaces((counter - 1) * 2); // Imprime los espacios entre las A
        printf("A\n"); // Imprime A y salto de línea
        Sleep(300); // Espera 300 milisegundos
        system("cls"); // Borra lo que haya en la consola
        PrintLetter(counter - 1); // Llamado recursivo a la funcion con counter - 1 hasta llegar a 0
    }
} // Fin función PrintLetter

// Inicio función principal
int main(){
    // Se espera un tiempo inicialmente
    Sleep(300);
    // Se borra lo que haya en consola
    system("cls");
    // Llama a al función con la cantidad de espacios iniciales
    PrintLetter(40);
    
    //----------------------------------------- Finalización del programa -------------------------------------------
    printf("\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0;
}