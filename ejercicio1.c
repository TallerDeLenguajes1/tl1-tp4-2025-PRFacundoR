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
   /*void pasajeDeNodos(Nodo **listaI, Nodo **listaF,int *incremento){
        
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
        

    }*/

        void pasajeDeNodos(Nodo **listaI, Nodo **listaF, int *incremento) {
        Nodo **aux = listaI;

        while (*aux) {
            if ((*aux)->T.TareaID == *incremento) {
                Nodo *temp = *aux;
                *aux = (*aux)->Siguiente;
                temp->Siguiente = NULL;
                insertarNodo(listaF, temp);
                break;
            }
            aux = &(*aux)->Siguiente;
        }
    }
//ottra forma   
    void mostrarListadoTareas(Nodo **Lista){

        Nodo*aux=*Lista;

        while (aux!=NULL)
        {

            printf("El id de la tarea es: %d\n",aux->T.TareaID);
            printf("La descripcion de la tarea es: \n");
            
            puts(aux->T.Descripcion);
            
            printf("La duracion de la lista es: %d\n",aux->T.Duracion);
            printf("\n");

            
            aux=aux->Siguiente;
           
        }
        


    }

    void consultaTareas(Nodo **listaI, Nodo **listaF,int*id,char palabraClave[],int *consulta){
        

        Nodo *aux1=*listaI;
        Nodo *axu2=*listaF;
        
            
        
        
        switch (*consulta)
        {
        case 1:

            while (aux1 || axu2)
            {
                
                if (aux1!=NULL && aux1->T.TareaID==*id)
                {
                    printf("La tarea pertenece a tarea pendiente");
                    break;
                }else if(axu2!=NULL && axu2->T.TareaID==*id){
                    printf("La tarea pertenece a tarea realizada");
                    break;
                }else{
                    printf("No existe tarea con ese id");
                    break;  
                }
                


                aux1=aux1->Siguiente;
                axu2=axu2->Siguiente;
            }
            
 
            break;
        
        case 2:

        while (aux1 || axu2)
        {
            
            if (aux1!=NULL && strstr(aux1->T.Descripcion,palabraClave)!=NULL)
            {
                printf("La tarea pertenece a tarea pendiente");
                break;
            }else if(axu2!=NULL && strstr((axu2)->T.Descripcion,palabraClave)!=NULL){
                printf("La tarea pertenece a tarea realizada");
                break;
            }else{
                printf("No existe tarea con esa descripcion");
                break;
            }
            


            aux1=aux1->Siguiente;
            axu2=axu2->Siguiente;
        }



           
            break;

        
        }
       
        


    }



int main()
{
    srand(time(NULL));
    int id=1000;
    int numeroTPend;
    int duracion;
    int tamanio=0;
    char descripcion[C]; 
    char palabraClave[C];
    Nodo *TareasPendientes=creacion();
    Nodo *TareasRealizadas=creacion();
    int final=0;
    int PasajeDeNodo;
    int idTarea;
    int consulta;

   
    printf("Ponga 0 si quiere agregar una tarea o 1 si quiere terminar de agregar tareas \n");
    scanf("%d",&final);
    
    while(final==0)
    {
        
        printf("\nIngrese la duracion de la tarea entre 10 y 100\n");
        scanf("%d",&duracion);

        printf("Ingrse la descripcion de la tarea\n");

        fflush(stdin);
        gets(descripcion);
        tamanio=strlen(descripcion);

        Nodo *tareaPendiente= CrearNodo(&duracion, descripcion, &tamanio,&id);
        insertarNodo(&TareasPendientes, tareaPendiente);
        id+=1;
        printf("Desea seguir agregando tareas ponga 0 si es asi o 1 si quiere finalizar\n");
        
        scanf("%d",&final);
      
    }
    
    printf("Si quieres pasar un nodo de tarea pendiente a tarea realizada, oprima 1(uno), sino apriete otro numero\n");
    scanf("%d",&PasajeDeNodo);
    while (PasajeDeNodo==1)
    {
        printf("Ingrese el id(de 1000(mil) para adelante) de la tarea a cambiar de lista\n");
        scanf("%d",&idTarea);
        

        pasajeDeNodos(&TareasPendientes, &TareasRealizadas, &idTarea);

        printf("Si quieres pasar un nodo de tarea pendiente a tarea realizada, oprima 1(uno), sino apriete otro numero\n");
        scanf("%d",&PasajeDeNodo);
    }
    

    printf("Lista de Tareas Pendientes:\n");
    mostrarListadoTareas(&TareasPendientes);
    
    printf("Lista de Tareas Realizadas:\n");
    mostrarListadoTareas(&TareasRealizadas);

    
    printf("Oprima 1 si quiere consultar por Id de la tarea, oprima 2 si quiere consultar por una palabra clave, otro numero si quiere salir de la operacion\n");
    scanf("%d",&consulta);
    while (consulta<3 && consulta>0)
    {
    printf("Ingrese la palabra clave para buscar en las tareas: \n");
    fflush(stdin);
    gets(palabraClave);
    
    consultaTareas(&TareasPendientes, &TareasRealizadas, &id, palabraClave,&consulta);
    
    printf("Oprima 1 para otra consulta por id de tarea, 2 para consultar por palabra clave, otro numero para salir\n");
    scanf("%d", &consulta);
    }
    return 0;
}
