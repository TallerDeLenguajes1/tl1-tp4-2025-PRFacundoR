#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define C 1000

typedef struct {
    int TareaID;//Numérico autoincremental comenzando en 1000
    char *Descripcion; //
    int Duracion; // entre 10 – 100
} Tarea;

typedef struct Nodo {
    Tarea T;
    struct Nodo *Siguiente;
} Nodo;




    Nodo* creacion(){

        return NULL;
    }

    Nodo* CrearNodo(int *duracion, char descripcion[], int *tamanio,int *incremento){
        Nodo* tareaPendiente= (Nodo*)malloc(sizeof(Nodo));

        tareaPendiente->T.Duracion=*duracion;

        tareaPendiente->T.Descripcion=(char*)malloc((*tamanio)*sizeof(char)+1);

        strcpy(tareaPendiente->T.Descripcion,descripcion);

        tareaPendiente->T.TareaID=*incremento;

        tareaPendiente->Siguiente=NULL;
        
        return tareaPendiente;
    }


    void insertarNodo(Nodo **lista, Nodo* tareaPendiente){
        tareaPendiente->Siguiente=*lista;
        *lista=tareaPendiente;
    }
   void pasajeDeNodos(Nodo **listaI, Nodo **listaF,int *incremento){
        
        Nodo**aux=&(*listaI);
        
        while (*listaI)
        {
            
            if ((*listaI)->T.TareaID == *incremento)
            {   
                Nodo* temp=*listaI;
                *aux=(*listaI)->Siguiente;
                
                temp->Siguiente=NULL;
                insertarNodo(listaF,temp);

                break;
            }
            aux=&(*listaI);

           *listaI= (*listaI)->Siguiente;
        }
        

    }


int main()
{
    srand(time(NULL));
    int incremento=1000;
    int numeroTPend;
    int duracion;
    int tamanio=0;
    char descripcion[C];
    Nodo *Inicio=creacion();
    Nodo *Fin=creacion();
    int final=0;
   
    printf("Ponga 0 si quiere agregar una tarea o 1 si quiere terminar de agregar tareas \n");
    scanf("%d",&final);
    
    while(final==0)
    {
        incremento+=1;
        printf("\nIngrese la duracion de la tarea entre 10 y 100\n");
        scanf("%d",&duracion);

        printf("Ingrse la descripcion de la tarea\n");

        fflush(stdin);
        gets(descripcion);
        tamanio=strlen(descripcion);

        Nodo *tareaPendiente= CrearNodo(&duracion, descripcion, &tamanio,&incremento);
        insertarNodo(&Inicio, tareaPendiente);
        
        printf("Desea seguir agregando tareas ponga 0 si es asi o 1 si quiere finalizar\n");
        
        scanf("%d",&final);
      
    }
    



    
    
    
    
    return 0;
}
