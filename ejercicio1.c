#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


struct {
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
    }typedef Tarea;

    struct Nodo{
    Tarea T;
    struct Nodo *Siguiente;
    };
    
    typedef struct Nodo* Lista;

int main()
{


    
    return 0;
}
