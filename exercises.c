#include "arraylist.h"
#include "stack.h"
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "exercises.h"

// Funciones auxiliares que puedes utilizar para debuggear tus ejercicios
// NO MODIFICAR
void imprime_lista(List *L) {
  int *dato;
  dato = (int *)first(L);
  printf("[");
  while (dato != NULL) {
    printf("%d ", *dato);
    dato = (int *)next(L);
  }
  printf("]\n");
}

// Ojo que la pila se vacía al imprimir y se imprime en orden inverso
// NO MODIFICAR
void imprime_y_vacia_pila(Stack *P) {
  void *dato;
  printf("[");
  while ((dato = pop(P)) != NULL) {
    printf("%d ", *(int *)dato);
  }
  printf("]\n");
}

/*
Ejercicio 1.
Crea una Lista y agrega punteros a elementos del 1 al 10.
Recuerda que la lista almacena punteros, por lo que
debes reservar memoria para cada elemento que agregues.
Al finalizar retorna la lista creada.
*/

List *crea_lista() {
  List *L = create_list();
  int *dato;
  for (int i = 1; i <= 10; i++)
    {
      dato = (int *)malloc(sizeof(int));
      *dato = i;
      pushBack(L, dato);
    }
  return L;
}

/*
Ejercicio 2.
Crea una función que reciba una lista de enteros (int*) y
retorne la suma de sus elementos.
*/
int sumaLista(List *L) { 
  int suma = 0;
  int *dato;

  dato = (int *)first(L);
  while (dato != NULL){
    suma += *dato;
    dato = (int *)next(L);
  }
  
  
  return suma; }

/*
Ejercicio 3.
Crea una función que reciba una lista de punteros a int (int*) y
un entero elem. La función debe eliminar todos los elementos
de la lista que sean iguales a elem.
Asume que popCurrent luego de eliminar un elemento se
posiciona en el elemento anterior.
*/

void eliminaElementos(List*L, int elem){
  void* elemento = first(L);
  while(elemento != NULL){
    int valo = *(int*)elemento;
    if(valo == elem){
      popCurrent(L);
    }
    elemento = next(L);
  }
}

/*
Ejercicio 4.
La función copia los punteros de la pila P1 en la pila P2.
El orden de ambas pilas se debe mantener.
Puedes usar una pila auxiliar.
*/

void copia_pila(Stack* P1, Stack* P2) {
    Stack* temp = create_stack();
    if (temp == NULL) EXIT_FAILURE;
    

    while (top(P1) != 0) {
        void* elemento = pop(P1);
        push(temp, elemento);
    }

    while (top(temp) != 0) {
        void* elemento = pop(temp);
        push(P1, elemento); 
        push(P2, elemento);
    }

}
/*
Ejercicio 5.
La función verifica si la cadena de entrada tiene sus
paraéntesis balanceados. Retorna 1 si están balanceados,
0 en caso contrario.
*/

int sonPareja(char c1, char c2){
  return (c1 == '(' && c2 == ')') || (c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}');

}

int parentesisBalanceados(char *cadena) {
  Stack* P = create_stack();
  char *elemento = cadena;
  while(*elemento){
    if (*elemento == '(' || *elemento == '[' || *elemento == '{'){
      char *dato = (char*)malloc(sizeof(char));
      *dato = *elemento;
      push(P,dato);
    }else if (*elemento == ')' || *elemento == ']' || *elemento == '}'){
      if (top(P) == 0 || !sonPareja(*(char*)top(P), *elemento)){
        while (top(P) != 0) {
          free(pop(P));
        }
        free(P);
        return 0;
      }else {
        free(pop(P));
      }
    }
    elemento++;
  }
  int resultado = (top(P) == 0);
  while(top(P) != 0){
    free(pop(P));
  }
  free(P);
  return resultado;
}
