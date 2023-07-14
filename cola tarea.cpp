#include<iostream>
#include<queue>
#include<string>
using std::queue;
using std::cout;
using std::endl;
using std::string;
using std::cin;

struct fruta
{
	string nombre;
	string color;
	float precio;
};

struct fruta registrar_fruta()
{
	fruta fruit;
	cout<<"\nNombre: "; cin>>fruit.nombre;
	cout<<"\nColor: "; cin>>fruit.color;
	cout<<"\nPrecio: "; cin>>fruit.precio;
	return fruit;
}
void menu();
void insertar_back(queue<fruta> frutilla);

int main()
{
	queue<fruta> frutilla;
	fruta aux;
	
	
	
	int opc;
	do
	{
		system("cls");
		menu(); std::cin>>opc;
		
		switch(opc)
		{
			case 1 : // insertar front
					
					system("pause>0");
					break;
			case 2 : //insertar back
					{
					insertar_back(frutilla);
					system("pause>0");
					break;
					}
			case 3 ://Para insertar en nth posicion el usuario tiene que dar posiciones validas
			
					system("pause>0");
					break;	
			case 4 ://imprimir del front al back
						
						
					system("pause>0");
					break;
				
			case 5 :
				system("pause>0");
				break;
				
			case 6 :
				system("pause>0");
				break;
				
			case 7 :
				system("pause>0");
				break;
				
			case 8 :
				system("pause>0");
				break;
				
			case 9 :
				cout<<"\nHasta luego";
				break;	
				
			default:
				cout<<"\nOpcion incorrecta";
				system("pause>0");
				break;
		}
		
	}while(opc!=9);
}

void menu()
{
	cout<<"\n\t\t\tMENU : REGISTRO DE DATOS";
	cout<<"\n1. Agregar palabra en el front";
	cout<<"\n2. Agregar una palabra en el back";
	cout<<"\n3. Agregar una palabra en lugar N";
	cout<<"\n4. Imprimir de front al back";
	cout<<"\n5. Imprimir back al front";
	cout<<"\n6. Eliminar palabra del front";
	cout<<"\n7. Eliminar palabra del back";
	cout<<"\n8. Eliminar posicional N";
	cout<<"\n9. Salir";
	cout<<"\nOpcion :";
}

void insertar_back(queue<fruta> frutilla, fruta aux)
{
	
}
