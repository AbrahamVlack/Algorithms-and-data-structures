/*Campos Hernandez Jose Abraham
fecha : 31/03/22
*/
#include<iostream>
#include<string>
using std::cout;
using std::endl;
using std::cin;
using std::string;

struct nodo{
	string fruta;
	float precio;
	struct nodo* siguiente;
};

void menu();
nodo* insertar_ini(nodo* cabeza, string fruta, float precio);
nodo* insertar_fin(nodo* cabeza, string fruta, float precio);
void imprimir(nodo* cabeza);

int main()
{
	int opc;
	string fruta;
	float precio;
	
	struct nodo* cabeza = NULL;
	do
	{
		system("cls");
		menu(); cin>>opc;
		switch(opc)
		{
			case 1:
				
					cout<<"\n Escriba el nombre de la fruta :"; cin>>fruta;
					cout<<"\n Escriba el precio de la fruta :"; cin>>precio;
					cabeza = insertar_ini(cabeza, fruta, precio);
					cout<<"\n La fruta se agregado correctamente";
					system("pause>0");
					break;	
				
			case 2:
					cout<<"\n Escriba el nombre de la fruta :"; cin>>fruta;
					cout<<"\n Escriba el precio de la fruta :"; cin>>precio;
					cabeza = insertar_fin(cabeza, fruta, precio);
					cout<<"\n La fruta se agregado correctamente";
					system("pause>0");	
					break;
					
				
			case 3: // imprimir
					imprimir(cabeza);
					system("pause>0");
					break;
					
			case 4:
				cout<<"\nHasta luego";
				break;
				
			default:
				cout<<"\nOpcion invalida. ";
				system("pause>0");
				break;
		}
		
	}while(opc!=4);
	
}

nodo* insertar_ini(nodo* cabeza, string fruta, float precio)
{
	
	if(cabeza == NULL)
	{
		struct nodo* temp = new nodo;
		temp->fruta = fruta;
		temp->precio = precio;
		temp->siguiente = NULL;
		cabeza = temp;
	}
	else // agregar al inicio
	{
		struct nodo* temp = new nodo;
		temp->fruta = fruta;
		temp->precio = precio;
		temp->siguiente = cabeza;
		cabeza = temp;
	}
	return cabeza;
}

nodo* insertar_fin(nodo* cabeza, string fruta, float precio)
{
	if(cabeza == NULL)
	{
		struct nodo* temp = new nodo;
		temp->fruta = fruta;
		temp->precio = precio;
		temp->siguiente = NULL;
		cabeza = temp;
		
	}
	else // agregar al final
	{
		struct nodo* temp = new nodo;
		struct nodo* temp2 = cabeza;
		temp->fruta = fruta;
		temp->precio = precio;
		temp->siguiente = NULL;
		while(temp2->siguiente!=NULL)
		{
			temp2 = temp2->siguiente;
		}
		temp2->siguiente = temp;
	}
	
	return cabeza;
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
			cout<<"\nPrecio :"<<temp->precio;
			cout<<endl;
			temp = temp->siguiente;
		}
	}
}

void menu()
{
	cout<<"\n\t\t\tMENU\n";
	cout<<"1./Agregar fruta al inicio.\n";
	cout<<"2./Agregar fruta al final.\n";
	cout<<"3./Imprimir.\n";
	cout<<"4./Salir.\n";
	cout<<"Digite la opcion : ";
}