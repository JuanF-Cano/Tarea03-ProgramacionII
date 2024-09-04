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

    Salvedad: Se debe presionar enter para finalizar el programa correctamente
*/

#include <stdio.h>

//Funcion que imprime los espacios que se le entregan como parametro
void PrintSpaces(int amount, int index){
    if(index < amount){
        printf(" ");
        PrintSpaces(amount, index+1);
    }
}

//Funcion que imprime las letras "Z" que se le entregan como parametro
void PrintZ(int amount, int index){
    if(index < amount){
        printf("Z");
        PrintZ(amount, index+1);
    }
}

//Funcion que imprime la forma del diamante, recibe la cantidad de espacios, letras "Z" y boolean que sirve para saber si de imprime la parte de arriba del diamante o la de abajo
void PrintDiamond(int amountZ, int amountSpaces, int boolean) {
    if (boolean == 0) {
        if (amountZ <= 7) {
            PrintSpaces(amountSpaces, 0);
            PrintZ(amountZ, 0);
            printf("\n");
            PrintDiamond(amountZ + 2, amountSpaces - 1, boolean);
        } else {
            PrintDiamond(amountZ, amountSpaces, 1);
        }
    } else if (amountZ > 0) {
        PrintSpaces(amountSpaces, 0);
        PrintZ(amountZ, 0);
        printf("\n");
        PrintDiamond(amountZ - 2, amountSpaces + 1, 1);  
    }
}

int main(){
    printf("Este programa imprime un patron determinado en pantalla.\n\n");
    //Se llama a la funcion PrintPattern con los dos terminos iniciales y un index
    PrintDiamond(1, 9, 0);
    
    //----------------------------------------- Finalización del programa -------------------------------------------
    printf("\nPresione enter para continuar . . ."); // Mensaje para indicar que se presione enter para finalizar
    getchar(); // Esperar a que el usuario presione la tecla enter para que no se cierre la CLI
    return 0;
}