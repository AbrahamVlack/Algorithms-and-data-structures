#include<iostream>
#include<string>
#include<fstream>
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ofstream;

struct nodo{
	string fruta;
	string color;
	int unidades;
	float precio;
	struct nodo* siguiente;
};

struct nodo* nuevo(string fruta, string color, int unidades, float precio){
	struct nodo* temp = new nodo;
	temp->fruta = fruta;
	temp->color = color;
	temp->unidades = unidades;
	temp->precio = precio;
	temp->siguiente = NULL;
	return temp;
};

void menu();
void insertar_ini(nodo** cabeza, string fruta, string color, int unidades, float precio);
void insertar_fin(nodo** cabeza, string fruta, string color, int unidades, float precio);
void insertar_nth(nodo** cabeza, string fruta, string color, int unidades, float precio);
void imprimir(nodo* cabeza);
void eliminar_ini(nodo** cabeza);
void eliminar_fin(nodo** cabeza);
void eliminar_nth(nodo** cabeza);
void ask(string *fruta, string *color, int *unidades, float *precio);
void serializacion(struct nodo* cabeza);

int main()
{
	int opc;
	string fruta, color;
	float precio;
	int unidades;
	
	struct nodo* cabeza = NULL;
	
	do
	{
		system("cls");
		menu(); cin>>opc;
		switch(opc)
		{
			case 1:
				
					ask(&fruta, &color, &unidades, &precio);
					insertar_ini(&cabeza, fruta, color, unidades, precio);
					cout<<"\n La fruta se agregado correctamente";
					system("pause>0");
					break;	
				
			case 2:
					ask(&fruta, &color, &unidades, &precio);
					insertar_fin(&cabeza, fruta, color, unidades, precio);
					cout<<"\n La fruta se agregado correctamente";
					system("pause>0");	
					break;
			
			case 3:
					ask(&fruta, &color, &unidades, &precio);
					insertar_nth(&cabeza, fruta, color, unidades, precio);
					cout<<"\n La fruta se agregado correctamente";
					system("pause>0");
					break;
						
			case 4: //eliminar al inicio
					eliminar_ini(&cabeza);
					system("pause>0");
					break;
					
			case 5: //eliminar al final
					eliminar_fin(&cabeza);
					system("pause>0");
					break;
					
			case 6: 
					eliminar_nth(&cabeza);
					system("pause>0");
					break;
					
			case 7: // imprimir
					imprimir(cabeza);
					system("pause>0");
					break;
			
			case 8:
				serializacion(cabeza);
				cout<<"\ncorrecto";
				system("pause>0");
				break;
				
			case 9:
				cout<<"\nHasta luego";
				break;
				
			default:
				cout<<"\nOpcion invalida. ";
				system("pause>0");
				break;
		}
		
	}while(opc!=9);
	
}

void insertar_ini(nodo** cabeza, string fruta, string color, int unidades, float precio)
{
	struct nodo* temp = nuevo(fruta, color, unidades, precio);
	
	if(*cabeza == NULL){                    
	
	
		*cabeza = temp;
	}
	else 
	{
		struct nodo* temp = nuevo(fruta, color, unidades, precio);
		temp->siguiente = *cabeza;
		*cabeza = temp;
	}
	
}

void insertar_fin(nodo** cabeza, string fruta, string color, int unidades, float precio)
{
	if(*cabeza == NULL)
	{
		struct nodo* temp = nuevo(fruta, color, unidades, precio);
		*cabeza = temp;
		
	}
	else 
	{
		struct nodo* temp = nuevo(fruta, color, unidades, precio);
		struct nodo* temp2 = *cabeza;
		while(temp2->siguiente!=NULL)
		{
			temp2 = temp2->siguiente;
		}
		temp2->siguiente = temp;
	}
	
}
	

void imprimir(nodo* cabeza)
{
	if(cabeza==NULL)
	{
		cout<<"\nLa lista es vacia";
	}
	else
	{
		struct nodo* temp = cabeza;
		while(temp!=NULL)
		{
			cout<<"\nFruta :"<<temp->fruta;
			cout<<"\ncolor :"<<temp->color;
			cout<<"\nunidades :"<<temp->unidades;
			cout<<"\nPrecio :"<<temp->precio;
			cout<<endl;
			temp = temp->siguiente;
		}
	}
}


void eliminar_ini(nodo** cabeza)
{
	if(*cabeza==NULL)
	{
		cout<<"\nLa lista ya esta vacia, no se puede realizar esta operacion";
	}
	else
	{
		struct nodo* temp = *cabeza;
		*cabeza = (*cabeza)->siguiente;
		delete temp;
		cout<<"\nSe a eliminado correctamente";
	}
}

void eliminar_fin(nodo** cabeza)
{
	if(*cabeza==NULL)
	{
		cout<<"\nLa lista ya esta vacia, no se puede realizar esta operacion";
	}
	else if((*cabeza)->siguiente==NULL)
	{
		
		struct nodo* temp = *cabeza;
		*cabeza = NULL;
		delete temp;
		cout<<"\nSe a eliminado correctamente";
	}
	else
	{
		struct nodo* temp = *cabeza;
		struct nodo* temp2 = *cabeza;
		while(temp->siguiente!=NULL)
		{
			temp = temp->siguiente;
		}
		while(temp2->siguiente!=temp)
		{
			temp2 = temp2->siguiente;
		}
		temp2->siguiente = NULL;
		delete temp;
		cout<<"\nSe a eliminado correctamente";
	}
}

void insertar_nth(nodo** cabeza, string fruta, string color, int unidades, float precio){// para insertar un nodo
 // en la nth posicion se deben dar posiciones validas recordando que 1 es el headnodo y n el tailnodo
 	int pos;
	if(*cabeza == NULL)// si el apuntador al headnodo es nullo por defecto el nodo se insertara en la primera posicion
	{
		struct nodo* temp = nuevo(fruta, color, unidades, precio);
		*cabeza = temp;
		return;
	}
	cout<<"\nDigite la posicion donde desea insertar el nodo: "; cin>>pos;
	if(pos == 1)
	{
		struct nodo* temp = nuevo(fruta, color, unidades, precio);
		temp->siguiente = *cabeza;
		*cabeza = temp;
		return;
	}
	else
	{
		int contador = 2;
		struct nodo* temp = nuevo(fruta, color, unidades, precio);
		struct nodo* temp2 = *cabeza;
		while(contador != pos)
		{
			temp2 = temp2->siguiente;
			contador++;
		}
		temp->siguiente = temp2->siguiente;
		temp2->siguiente = temp;
	}
}

void eliminar_nth(nodo** cabeza){
	int pos;
	if(*cabeza == NULL)
	{
		cout<<"\nNo se puede realizar la operacion la lista ya esta vacia";
		return;
	}
	else
	{
		struct nodo* temp = *cabeza;
		cout<<"\nDigite la posicion que desea eliminar :"; cin>>pos;
		if(pos == 1)
		{
			struct nodo* temp = *cabeza;
			*cabeza = (*cabeza)->siguiente;
			delete temp;
			cout<<"\nSe a eliminado correctamente";
		}
		else
		{
			int contador = 2;
			struct nodo* temp = *cabeza;
			while(contador != pos)
			{
				temp = temp->siguiente;
				contador++;
			}
			struct nodo* temp2;
			temp2 = temp->siguiente;
			temp->siguiente = temp2->siguiente;
			
			delete temp2;
			cout<<"\nSe elimino el elemento correctamente";
		}
	}
}

void menu()
{
	cout<<"\n\t\t\tMENU\n";
	cout<<"1./Agregar fruta al inicio.\n";
	cout<<"2./Agregar fruta al final.\n";
	cout<<"3./Agregar fruta al la nth posicion.\n";
	cout<<"4./Eliminar una fruta del inicio.\n";
	cout<<"5./Eliminar una fruta del final.\n";
	cout<<"6./Eliminar una fruta del nth posicion.\n";
	cout<<"7./Imprimir.\n";
	cout<<"8./Archivo.\n";
	cout<<"9./Salir.\n";
	cout<<"Digite la opcion : ";
}

void ask(string *fruta, string *color, int *unidades, float *precio)
{
	cout<<"\n Escriba el nombre de la fruta :"; cin>>*fruta;
	cout<<"\n Escriba el color de la fruta :"; cin>>*color;
	cout<<"\n Escriba el numero de unidades de la fruta :"; cin>>*unidades;
	cout<<"\n Escriba el precio de la fruta :"; cin>>*precio;
}

void serializacion(struct nodo* cabeza){
	ofstream archivo;
	archivo.open("lista.txt");
	struct nodo* temp = cabeza;
	while(temp != NULL){
		archivo << temp->color<<" ";
		temp = temp->siguiente;
	}
	archivo.close();
}



