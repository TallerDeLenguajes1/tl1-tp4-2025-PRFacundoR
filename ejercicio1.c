#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define C 1000

struct {
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
}typedef Tarea;

 struct {
    Tarea T;
    struct Nodo *Siguiente;
}typedef Nodo;




    Nodo* creacion(){

        return NULL;
    }

    Nodo* CrearNodo(int *duracion, char descripcion[], int *tamanio,int *incremento){
        Nodo* tareaPendiente= (Nodo*)malloc(sizeof(Nodo));

        tareaPendiente->T.Duracion=*duracion;

        tareaPendiente->T.Descripcion=(char*)malloc(*tamanio*sizeof(char)+1);

        strcpy(tareaPendiente->T.Descripcion,descripcion);

        tareaPendiente->T.TareaID=*incremento;

        tareaPendiente->Siguiente=NULL;
        
        return tareaPendiente;
    }



int main()
{
    srand(time(NULL));
    int incremento;
    int numeroTPend;
    int duracion;
    int tamanio;
    char descripcion[C];
    Nodo *Inicio=creacion();

    printf("Ingrese el numero de tareas que quieres dar`\n");
    scanf("%d",&numeroTPend);

    for (int i = 0; i < numeroTPend; i++)
    {
        incremento=1000+i;
        printf("\nIngrese la duracion de la tarea entre 10 y 100\n");
        scanf("%d",&duracion);

        printf("Ingrse la descripcion de la tarea\n");
        gets(descripcion);
        tamanio=strlen(descripcion);

        Nodo *tareaPendiente= CrearNodo(&duracion, descripcion, &tamanio,&incremento);

    }
    
    
    
    
    
    return 0;
}
