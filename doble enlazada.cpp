#include<iostream>
#include<string>
using std::cout; //No usar using namespace std;
using std::endl;
using std::string;
using std::cin;

struct nodo{
	string nombre;
	string color;
	int cantidad;
	float precio;
	struct nodo* siguiente;
	struct nodo* previo;
};

struct nodo* nuevo(string nombre, string color, int cantidad, float precio){
	struct nodo* temp = new nodo;
	temp->nombre = nombre;
	temp->color = color;
	temp->cantidad = cantidad;
	temp->precio = precio;
	temp->siguiente = NULL;
	temp->previo = NULL;
	return temp;
};

void menu();
void ask(string* nombre, string* color, int* cantidad, float* precio);
void insertar_ini(struct nodo** cabeza, struct nodo** final, string nombre, string color, int cantidad, float precio);
void insertar_fin(struct nodo** cabeza, struct nodo** final, string nombre, string color, int cantidad, float precio);
void insertar_nth(struct nodo** cabeza, struct nodo** final, string nombre, string color, int cantidad, float precio);
void eliminar_ini(struct nodo** cabeza, struct nodo** final);
void eliminar_fin(struct nodo** cabeza, struct nodo** final);
void eliminar_nth(struct nodo** cabeza, struct nodo** final);
void imprimir_ini(struct nodo* cabeza);
void imprimir_fin(struct nodo* final);

int main()
{
	struct nodo* cabeza = NULL;
	struct nodo* final = NULL;
	string nombre, color;
	float precio;
	int cantidad;
	int opc;
	
	do
	{
		system("cls");
		menu(); cin>>opc;
		switch(opc)
		{
			case 1:
					ask(&nombre, &color, &cantidad, &precio);
					insertar_ini(&cabeza, &final, nombre, color, cantidad, precio);
					system("pause>0");
					break;
					
			case 2:
					ask(&nombre, &color, &cantidad, &precio);
					insertar_fin(&cabeza, &final, nombre, color, cantidad, precio);
					system("pause>0");
					break;
					
			case 3:
					ask(&nombre, &color, &cantidad, &precio);
					insertar_nth(&cabeza, &final, nombre, color, cantidad, precio);
					system("pause>0");
					break;
						
			case 4: 
					eliminar_ini(&cabeza, &final);
					system("pause>0");
					break;
					
			case 5: 
					eliminar_fin(&cabeza, &final);
					system("pause>0");
					break;
					
			case 6: 
					eliminar_nth(&cabeza, &final);
					system("pause>0");
					break;
					
			case 7: 
					imprimir_ini(cabeza);
					system("pause>0");
					break;
					
			case 8:
					imprimir_fin(final);
					system("pause>0");
					break;
				
			case 9:
					cout<<"Hasta luego";
					break;
				
			default:
				cout<<"\nOpcion invalida. ";
				system("pause>0");
				break;
		}
		
	}while(opc!=9);
	
	
}

void menu(){
	cout<<"\n\t\t\tMENU\n";
	cout<<"1./Agregar fruta al inicio.\n";
	cout<<"2./Agregar fruta al final.\n";
	cout<<"3./Agregar fruta al la nth posicion.\n";
	cout<<"4./Eliminar una fruta del inicio.\n";
	cout<<"5./Eliminar una fruta del final.\n";
	cout<<"6./Eliminar una fruta del nth posicion.\n";
	cout<<"7./Imprimir inicio a fin.\n";
	cout<<"8./Imprimir fin a inicio.\n";
	cout<<"9./Salir.\n";
	cout<<"Digite la opcion : ";
}

void ask(string* nombre, string* color, int* cantidad, float* precio){
	cout<<"\nNombre de la fruta :"; cin>>*nombre;
	cout<<"\nColor de la fruta :"; cin>>*color;
	cout<<"\nCantidad de fruta :"; cin>>*cantidad;
	cout<<"\nPrecio de la fruta :"; cin>>*precio;
	cout<<endl;
}

void insertar_ini(struct nodo** cabeza, struct nodo** final, string nombre, string color, int cantidad, float precio){
	if(*cabeza == NULL)
	{
		struct nodo* temp = nuevo(nombre, color, cantidad, precio);
		*cabeza = temp;
		*final = temp;
		cout<<"\nSe agrego el elemento correctamente";
		return;
	}
	else
	{
		struct nodo* temp = nuevo(nombre, color, cantidad, precio);
		temp->siguiente = *cabeza;
		(*cabeza)->previo = temp;
		*cabeza = temp;
		cout<<"\nSe agrego el elemento correctamente";
		return;
	}
}

void insertar_fin(struct nodo** cabeza, struct nodo** final, string nombre, string color, int cantidad, float precio){
	if(*cabeza == NULL)
	{
		struct nodo* temp = nuevo(nombre, color, cantidad, precio);
		*cabeza = temp;
		*final = temp;
		cout<<"\nSe agrego el elemento correctamente";
		return;
	}
	else
	{
		struct nodo* temp = nuevo(nombre, color, cantidad, precio);
		temp->previo = *final;
		(*final)->siguiente = temp;
		*final = temp;
		cout<<"\nSe agrego el elemento correctamente";
	}
}

void insertar_nth(struct nodo** cabeza, struct nodo** final, string nombre, string color, int cantidad, float precio){
	int pos;
	cout<<"Digite la posicion donde desea insertar la fruta :"; cin>>pos;
	if(*cabeza==NULL && pos == 1) // lista vacia
	{
		struct nodo* temp = nuevo(nombre, color, cantidad, precio);
		*final = temp;
		*cabeza = temp;
		cout<<"\nSe agrego el elemento correctamente";
		return;
	}
	else
	{
		if(pos==1) // agregar al inicio
		{
			struct nodo* temp = nuevo(nombre, color, cantidad, precio);
			temp->siguiente = *cabeza;
			(*cabeza)->previo = temp;
			*cabeza = temp;
			cout<<"\nSe agrego el elemento correctamente";
			return;
		}
		else
		{
			int contador = 2;
			struct nodo* temp = nuevo(nombre, color, cantidad, precio);
			nodo* aux = *cabeza;
			
			while(contador!=pos)
			{
				aux = aux->siguiente;
				contador++;
			}
			if(aux == *final) // agregar al final 
			{
				aux->siguiente = temp;
				temp->previo = aux;
				*final = temp;
				cout<<"\nSe agrego el elemento correctamente";
				return;
			}
			else
			{
				struct nodo* aux2 = aux; //puente
				aux2 = aux2->siguiente;
				aux->siguiente = temp;
				temp->previo = aux;
				temp->siguiente = aux2;
				aux2->previo = temp;
				cout<<"\nSe agrego el elemento correctamente";
				return;
			}
		}
	
	}
	
}

void eliminar_ini(struct nodo** cabeza,struct nodo** final){
	if(*cabeza == NULL)
	{
		cout<<"\nLa operacion no se puede realizar, la lista ya esta vacia";
	}
	else if((*cabeza)->siguiente == NULL)
	{
		struct nodo* temp = NULL;
		temp = *cabeza;
		*cabeza == NULL;
		*final == NULL;
		delete temp; 
		cout<<"\nSe elimino el elemento correctamente.";
	}
	else
	{
		struct nodo* temp = *cabeza;
		*cabeza = (*cabeza)->siguiente;
		(*cabeza)->previo = NULL;
		delete temp;
		cout<<"\nSe elimino el elemento correctamente.";
	}
}

void eliminar_fin(struct nodo** cabeza, struct nodo** final){
	if(*cabeza == NULL)
	{
		cout<<"\nLa operacion no se puede realizar, la lista ya esta vacia";
	}
	else if((*cabeza)->siguiente==NULL)
	{
		struct nodo* temp = *cabeza;
		*cabeza == NULL;
		*final == NULL;
		delete temp;
		cout<<"\nSe elimino el elemento correctamente.";
	}
	else
	{
		struct nodo* temp = *final;
		*final = (*final)->previo;
		delete temp;
		cout<<"\nSe elimino el elemento correctamente.";
	}
}

void eliminar_nth(struct nodo** cabeza, struct nodo** final){
	
	if(*cabeza == NULL)
	{
		cout<<"\nLa operacion no se puede realizar, la lista ya esta vacia";
	}
	else
	{
		struct nodo* temp = *cabeza;
		int pos;
		int contador = 1;
		cout<<"\nDigite la posicion que desea eliminar :"; cin>>pos;
		if((*cabeza)->siguiente == NULL && pos==1)
		{
			*cabeza == NULL;
			*final == NULL;
			delete temp;
			cout<<"\nSe elimino el elemento correctamente.";
		}
		else if(pos==1 && (*cabeza)->siguiente != NULL)
		{
			*cabeza = (*cabeza)->siguiente;
			(*cabeza)->previo = NULL;
			delete temp;
			cout<<"\nSe elimino el elemento correctamente.";
		}
		while(contador!=pos)
		{
			temp = temp->siguiente;
			contador++;
		}
		if(temp->siguiente == NULL)
		{
			*final = (*final)->previo;
			delete temp;
			cout<<"\nSe elimino el elemento correctamente.";
		}
		else
		{
			nodo* temp2 = temp->siguiente;
			temp->siguiente = temp2->siguiente;
			temp = temp2->siguiente;
			temp->previo = temp2->previo;
			delete temp2;
			cout<<"\nSe elimino el elemento correctamente.";
		}
	}
}

void imprimir_ini(struct nodo* cabeza){
	if(cabeza == NULL)
	{
		cout<<"\nLa lista esta vacia";
	}
	else
	{
		cout<<"\nLista :";
		struct nodo* temp = cabeza;
		while(temp!=NULL)
		{
			cout<<"\nNombre :"<<temp->nombre;
			cout<<"\nColor :"<<temp->color;
			cout<<"\nCantidad :"<<temp->cantidad;
			cout<<"\nPrecio :"<<temp->precio<<endl;
			temp = temp->siguiente;
			
		}
	}
}

void imprimir_fin(struct nodo* final){
	if( final == NULL)
	{
		cout<<"\nLa lista esta vacia";
	}
	else
	{
		struct nodo* temp = final;
		while(temp != NULL)
		{
			cout<<"\nNombre :"<<temp->nombre;
			cout<<"\nColor :"<<temp->color;
			cout<<"\nCantidad :"<<temp->cantidad;
			cout<<"\nPrecio :"<<temp->precio<<endl;
			temp = temp->previo;
		}
	}
}