/* Campos Hernandez Jose Abraham
date : 03/08/22 */
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

struct extras{
	string empresa;
	string color;
	float calificacion;
};

struct computador{
	string procesador;
	int nucleos;
	int ram;
	string num_serie;
	extras ext;
};

struct computador registrar_computador();
void imprimir(computador lap);
void menu();

int main()
{
	int opc;
	computador lap1;
	
	do{
		system("cls");
		menu(); cin>>opc;
		switch(opc)
		{
			case 1:
				lap1 = registrar_computador();
				system("pause>0");
				break;
				
			case 2:
				imprimir(lap1);
				system("pause>0");
				break;
			case 3:
				cout<<"\nHasta luego.";
				break;
		}
		
	}while(opc!=3);
	
}


struct computador registrar_computador()
{
	computador lap;
	cout<<"\nProcesador :"; cin>>lap.procesador;
	cout<<"\nNucleos :"; cin>>lap.nucleos;
	cout<<"\nRam :"; cin>>lap.ram;
	cout<<"\nNumero de serie :"; cin>>lap.num_serie;
	cout<<"\nEmpresa :"; cin>>lap.ext.empresa;
	cout<<"\nColor :"; cin>>lap.ext.color;
	cout<<"\nCalificacion :"; cin>>lap.ext.calificacion;
	return lap;
}

void imprimir(computador lap)
{
	cout<<"\nComputador";
	cout<<"\nProcesador :"<<lap.procesador;
	cout<<"\nNucleos :"<<lap.nucleos;
	cout<<"\nRam :"<<lap.ram;
	cout<<"\nNumero de serie :"<<lap.num_serie;
	cout<<"\nEmpresa :"<<lap.ext.empresa;
	cout<<"\nColor :"<<lap.ext.color;
	cout<<"\nCalificacion :"<<lap.ext.calificacion;
	
}

void menu()
{
	cout<<"\nMenu";
	cout<<"\n1. Registrar datos";
	cout<<"\n2. Imprimir datos";
	cout<<"\n3. Salir";
	cout<<"\nOpcion : ";
}

