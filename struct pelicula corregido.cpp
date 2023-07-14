#include<iostream>
using std::cout;
using std::endl;
using std::cin;
using std::string;

struct pelicula
{
	float duracion;	
	int anio;
	string nombre;
	string director;
	string clasificacion;
	string genero;
};
 
struct pelicula registrar_pelicula();
void imprimir_pelicula(pelicula peli);
void menu();

int main()
{
	int opc;
	pelicula peli;
	
	do
	{
		system("cls");
		menu(); cin>>opc;
		
		switch(opc)
		{
			case 1:
				peli = registrar_pelicula();
				system("pause>0");
				break;
			case 2:
				imprimir_pelicula(peli);
				system("pause>0");
				break;
			case 3:
				cout<<"\nHasta luego";
				break;
			
			default:
				cout<<"\nOpc no valida";
		}
		
	}while( opc!=3 );
	
}

struct pelicula registrar_pelicula()
{
	pelicula peli;
	cout<<"\nIngresa los datos de la pelicula";
	cout<<"\nTitulo: "; cin>>peli.nombre;
	cout<<"\nDirector: "; cin>>peli.director;
	cout<<"\nClasificacion: "; cin>>peli.clasificacion;
	cout<<"\nGenero: "; cin>>peli.genero;
	return peli;
}

void imprimir_pelicula(pelicula peli)
{
	cout<<"\nPelicula ";
	cout<<endl<<"Nombre :"<<peli.nombre;
	cout<<endl<<"Director :"<<peli.director;
	cout<<endl<<"Clasificacion :"<<peli.clasificacion;
	cout<<endl<<"Genero :"<<peli.genero;
}

void menu()
{
	cout<<"\nPeliculas\n";
	cout<<"\n1./Registrar una pelicula";
	cout<<"\n2./Imprimir pelicula";
	cout<<"\n3./Salir";
	cout<<"\nOpcion :";
}






