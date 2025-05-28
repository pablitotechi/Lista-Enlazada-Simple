#include <iostream>
#include <stdlib.h>
using namespace std;
 
struct nodo{
       int dato;        
       struct nodo *siguiente;
};
 
typedef struct nodo *miLista;
 
void insertarInicio(miLista &lista, int valor)
{
    miLista s;
    s = new(struct nodo);
    s->dato = valor;
    s->siguiente = lista;
    lista  = s;
}
 
void insertarFinal(miLista &lista, int valor)
{
    miLista t, s = new(struct nodo);
 
    s->dato  = valor;
    s->siguiente = NULL;
 
    if(lista==NULL)
    {
        lista = s;
    }
    else
    {
        t = lista;
        while(t->siguiente!=NULL)
        {
            t = t->siguiente;
        }
        t->siguiente = s;
    }
 
}
 
int insertarAntesDespues()
{
    int _op, band;
    cout<<endl;
    cout<<"\t 1. Antes de la posicion           "<<endl;
    cout<<"\t 2. Despues de la posicion         "<<endl;
 
    cout<<"\n\t Opcion : "; cin>> _op;
 
    if(_op==1)
        band = -1;
    else
        band = 0;
 
    return band;
}
 
void insertarElemento(miLista &lista, int valor, int pos)
{
    miLista s, t;
    int i;
    s = new(struct nodo);
    s->dato = valor;
 
    if(pos==1)
    {
        s->siguiente = lista;
        lista = s;
    }
    else
    {
        int x = insertarAntesDespues();
        t = lista;
 
        for(i=1; t!=NULL; i++)
        {
            if(i==pos+x)
            {
                s->siguiente = t->siguiente;
                t->siguiente = s;
                return;
            }
            t = t->siguiente;
        }
    }
    cout<<"   Error...Posicion no encontrada..!"<<endl;
}
 
void buscarElemento(miLista lista, int valor)
{
    miLista s = lista;
    int i = 1, band = 0;
 
    while(s!=NULL)
    {
        if(s->dato==valor)
        {
            cout<<endl<<" Encontrada en posicion "<< i <<endl;
            band = 1;
        }
        s = s->siguiente;
        i++;
    }
 
    if(band==0)
        cout<<"\n\n Numero no encontrado..!"<< endl;
}
 
void imprimirLista(miLista lista)
{
     int i = 0;
 
     while(lista != NULL)
     {
          cout <<' '<< i+1 <<") " << lista->dato << endl;
          lista = lista->siguiente;
          i++;
     } 
}
 
 
void eliminarElemento(miLista &lista, int valor)
{
    miLista p, ant;
    p = lista;
 
    if(lista!=NULL)
    {
        while(p!=NULL)
        {
            if(p->dato==valor)
            {
                if(p==lista)
                    lista = lista->siguiente;
                else
                    ant->siguiente = p->siguiente;
 
                delete(p);
                return;
            }
            ant = p;
            p = p->siguiente;
        }
    }
    else
        cout<<" Lista vacia..!";
}
 
 
void menu1()
{
    cout<<"\n\t\tMENU LISTA SIMPLE\n\n";
    cout<<" 1. INSERTAR AL INICIO               "<<endl;
    cout<<" 2. INSERTAR AL FINAL                "<<endl;
    cout<<" 3. INSERTAR EN UNA POSICION         "<<endl;
    cout<<" 4. IMPRIMIR LISTA                   "<<endl;
    cout<<" 5. BUSCAR DATO                  "<<endl;
    cout<<" 6. ELIMINAR DATO                "<<endl;
    cout<<" 7. SALIR                            "<<endl;
 
    cout<<"\n POR FAVOR , INGRESE UNA OPCION: ";
}
 
 
/*                        Funcion Principal
---------------------------------------------------------------------*/
 
int main()
{
    miLista lista = NULL;
    int op;    
    int _dato;  
    int pos;   
 
 

    do
    {
        menu1();  cin>> op;
 
        switch(op)
        {
            case 1:
 
                 cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
                 insertarInicio(lista, _dato);
            break;
 
 
            case 2:
 
                 cout<< "\n NUMERO A INSERTAR: "; cin>> _dato;
                 insertarFinal(lista, _dato );
            break;
 
 
            case 3:
 
                 cout<< "\n NUMERO A INSERTAR: ";cin>> _dato;
                 cout<< " Posicion : ";       cin>> pos;
                 insertarElemento(lista, _dato, pos);
            break;
 
 
            case 4:
 
                 cout << "\n\n MOSTRANDO LISTA\n\n";
                 imprimirLista(lista);
            break;
 
 
            case 5:
 
                 cout<<"\n Valor a buscar: "; cin>> _dato;
                 buscarElemento(lista, _dato);
            break;
 
            case 6:
 
                cout<<"\n Valor a eliminar: "; cin>> _dato;
 
                eliminarElemento(lista, _dato);
            break;

 
                    }
 
        cout<<endl<<endl;
 
    }while(op!=7);
 
 
   system("pause");
   return 0;
}
