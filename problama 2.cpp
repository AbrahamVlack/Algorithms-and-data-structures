#include<iostream>
#include <fstream>
using namespace std;


void busqueda_lineal(string palabra);

int main()
{
	string palabr;
 	cout<<"Digite la palabra que busca :";//hola, nunca 
 	cin>>palabr;
 	busqueda_lineal(palabr);
 	system("pause");
 	return 0;
}

void busqueda_lineal(string palabra)
{
	ifstream arch;
 	arch.open("hola.txt");
 	bool bandera=false;
 	string pala;
 	while(!arch.eof() && bandera==false)
	{
  		arch>>pala;
  		if(pala==palabra)
	  	{
   			bandera=true;
  		}
 	}
 	
 	if(pala==palabra)
	{
  	cout<<endl<<"La palabra *"<<palabra<<"* se encontro archivo"<<endl;
 	}
	else
  	cout<<endl<<"La palabra no esta en el archivo"<<endl;
}