#include<iostream>
#include<string>

using std::cout;
using std::cin;

struct pelicula
{
	float duracion;
	std::string nombre;
	std::string genero;
	std::string director;
	std::string clasificion;
	int year;
};



int main()
{
	int opc;
	cout<<"Menu"<<std::endl;
	cout<<"1- registrar una pelicula "<<std::endl;
	cout<<"2- mostrar pelicula "<<std::endl;
	cout<<"3- salir "<<std::endl;
	cout<<"digite opcion :"; cin>>opc;
	cout<<std::endl;
	switch(opc)
	{
		case 1:
			{
			break;
		
			pelicula Grand_father;
			cout<<"Nombre :";  cin>>Grand_father.nombre; cout<<std::endl;
			cout<<"Duracion :";  cin>>Grand_father.duracion; cout<<std::endl;
			cout<<"Genero :";  cin>>Grand_father.genero; cout<<std::endl;
			cout<<"clasificacion :";  cin>>Grand_father.clasificion; cout<<std::endl;
			cout<<"Director :";  cin>>Grand_father.director;cout<<std::endl;
			cout<<"año :";  cin>>Grand_father.year; cout<<std::endl;
			// Por aca deberia habler un goto para regresar al menu y un crear para limpiar el texto
			}
		break;
		case 2:
			{
				cout<<Grand_father.nombre<<std::endl;// por qui deberia imprimir lo que ya se guardo en la pelicula
				cout<<Grand_father.duracion<<std::endl;
				cout<<Grand_father.genero<<std::endl;
				cout<<Grand_father.clasificion<<std::endl;
				cout<<Grand_father.director<<std::endl;
				cout<<Grand_father.year<<std::endl;
			
			}
		break;
		
		case 3:
		{
			exit(1); // salida
		}	
		break;
	}
}