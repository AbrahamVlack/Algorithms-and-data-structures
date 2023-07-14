#include<iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

struct fecha{
	int dia;
	string	mes;
	string anio;
};

struct autor{
	string nombre;
	int libros_publicados;
	int edad;
};

struct libro{
	string editorial;
	string lugar_creacion;
	string ibns;
	fecha date;
	autor aut;
};

struct libro registrar_libro();
void imprimir(libro tex);
void menu();

int main()
{
	int opc;
	libro lib1;
	
	do{
		system("cls");
		menu(); cin>>opc;
		switch(opc)
		{
			case 1:
				lib1 = registrar_libro();
				system("pause>0");
				break;
				
			case 2:
				imprimir(lib1);
				system("pause>0");
				break;
			case 3:
				cout<<"\nHasta luego.";
				break;
		}
		
	}while(opc!=3);
	
}


struct libro registrar_libro()
{
	libro lib;
	cout<<"\nEditorial :"; cin>>lib.editorial;
	cout<<"\nLugar de creacion :"; cin>>lib.lugar_creacion;
	cout<<"\nIBNS :"; cin>>lib.ibns; 
	cout<<"\nFecha \n"; 
	cout<<"\nDia :"; cin>>lib.date.dia;
	cout<<"\nMes :"; cin>>lib.date.mes;
	cout<<"\nanio :"; cin>>lib.date.anio;
	cout<<"\nAutor \n"; 
	cout<<"\nNombre :"; cin>>lib.aut.nombre;
	cout<<"\nNumero de libros publicados :";cin>>lib.aut.libros_publicados;
	cout<<"\nEdad :"; cin>>lib.aut.edad;
	
	return lib;
}

void imprimir(libro lib)
{
	cout<<"\nLibro";
	cout<<"\nEditorial :"<<lib.editorial;
	cout<<"\nLugar de creacion :"<<lib.lugar_creacion;
	cout<<"\nIBNS :"<<lib.ibns; 
	cout<<"\nFecha "; 
	cout<<"\nDia :"<<lib.date.dia;
	cout<<"\nMes :"<<lib.date.mes;
	cout<<"\nanio :"<<lib.date.anio;
	cout<<"\nAutor "; 
	cout<<"\nNombre :"<<lib.aut.nombre;
	cout<<"\nNumero de libros publicados :"<<lib.aut.libros_publicados;
	cout<<"\nEdad :"<<lib.aut.edad;
}

void menu()
{
	cout<<"\nMenu";
	cout<<"\n1. Registrar datos";
	cout<<"\n2. Imprimir datos";
	cout<<"\n3. Salir";
	cout<<"\nOpcion : ";
}

