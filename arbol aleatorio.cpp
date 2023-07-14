#include<iostream>
#include <time.h>
#include<queue>

using std::queue;
using std::cout; 

struct nodo{
	int numero;
	nodo* izquierda;
	nodo* derecha;
};

struct nodo2{
	int numero;
	nodo2* siguiente;
};

struct nodo* nuevo(int valor){ 
	struct nodo* temp = new nodo; 
	temp->izquierda = NULL;
	temp->derecha = NULL;
	temp->numero = valor;

	return temp;
}

struct nodo2* lista(int valor){ 
	struct nodo2* temp = new nodo2; 
	temp->numero = valor;
	temp->siguiente = NULL;
	
	return temp;
	
}


void menu();

void insertar(nodo** raiz, int valor);
void inorden(nodo* raiz, queue<int>* q); 
void rand_bol(nodo** raiz, int x);
void lista_impares(nodo2** cabeza, queue<int>* q);
void imprimir(nodo2* cabeza);

int main()
{
	queue<int> cola;
	struct nodo* raiz = NULL;
	struct nodo2* cabeza = NULL;
	int opc, valor, x;
	do{
		system("cls");
		menu(); std::cin>>opc;
		switch(opc)
		{

			case 1:
				cout<<"\nNumero de nodos del arbol :"; std::cin>>x;
				rand_bol(&raiz, x);
				inorden(raiz, &cola);
				system("pause>0");
				break;
			
			case 2:
				lista_impares(&cabeza, &cola);
				imprimir(cabeza);
				system("pause>0");
				break;
				
	
					
			case 3:
				cout<<"\nHasta luego";
				break;

			default:
				cout<<"\nOpcion incorrecta";
				system("pause>0");
				break;
		}


	}while(opc!=3);


}

void insertar(nodo** raiz, int valor){
	if(*raiz == NULL){
		struct nodo* temp = nuevo(valor);
		*raiz = temp;
		return;
	}
	else if((*raiz)->numero == valor){
		return;
	}
	else
	{
		if(valor < (*raiz)->numero ){
			insertar(&((*raiz)->izquierda), valor); 
			return;
		}
		else{
			insertar(&((*raiz)->derecha), valor);
			return;
		}
	}
}


void rand_bol(nodo** raiz, int x){
	srand (time(NULL));
	for(int i=0; i<x; i++)
	{
		insertar(&(*raiz), rand() % 99 + 1);
		
	}

	cout<<"\nArbol aleatorio generado ";

}

void inorden(nodo* raiz, queue<int>* q){ 
	if(raiz == NULL) return ;

	inorden(raiz->izquierda, q);
	if(raiz->numero % 2 == 1){
		(*q).push(raiz->numero);
	}
	inorden(raiz->derecha, q);
}

void lista_impares(nodo2** cabeza, queue<int>* q){
	
	while((*q).empty() != true){
		struct nodo2* temp = lista((*q).front());
	
		if(*cabeza == NULL){                    
			*cabeza = temp;
		}
		else 
		{
			struct nodo2* temp = lista((*q).front());
			temp->siguiente = *cabeza;
			*cabeza = temp;
		}
		(*q).pop();
	}
	
}

void imprimir(nodo2* cabeza){
	if(cabeza==NULL)
	{
		cout<<"\nLa lista es vacia";
	}
	else
	{
		struct nodo2* temp = cabeza;
		while(temp!=NULL)
		{
			cout<<" "<<temp->numero;
			temp = temp->siguiente;
		}
	}
}

void menu(){
	cout<<"\t\t\tMenu";
	cout<<"\n1./Generar arbol";
	cout<<"\n2./Lista de impares";
	cout<<"\n3.Salir";
	cout<<"\nOpciones : ";
}


