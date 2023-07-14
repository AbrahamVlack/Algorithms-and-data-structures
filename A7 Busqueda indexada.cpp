
/*Programa creado por: Campos Hernadez Jose Abraham
  date : 03/06/22 */
  //cambios 03/11/22
#include<iostream>
#include<time.h>

using std::cout;
using std::cin;
using std::endl;

void menu();
int* new_array(int size);
void imprimir(int a[], int size);
void busqueda_lineal(int a[], int size, int busca);
void busqueda_binaria(int a[], int size, int busca);
void bubble_sort(int a[], int size);
void busqueda_indexada(int a[],int size, int busca);

int main()
{
	int opc;
	bool rep = true;
	do
	{
		system("cls");
		menu(); cin>>opc;
		
		switch(opc)
		{
			case 1:
				int tam;
				int* ptr;
				cout<<"\nDigite el tamano del array :"; cin>>tam;
				ptr = new_array(tam);
				cout<<"\nprecione cualquier tecla para continuar. ";
				system("pause>0");
				break;
				
			case 2:
				cout<<"\nArray : ";
				imprimir(ptr,tam);
				cout<<"\nprecione cualquier tecla para continuar. ";
				system("pause>0");
				break;
				
			case 3:
				int dato;
				cout<<"\nNumero que desea buscar : "; cin>>dato;
				busqueda_lineal(ptr,tam,dato);
				cout<<"\nprecione cualquier tecla para continuar. ";
				system("pause>0");
				break;
				
			case 4:
				int data;
				cout<<"\nNumero que desea buscar : "; cin>>data;
				busqueda_binaria(ptr,tam,data);
				cout<<"\nprecione cualquier tecla para continuar. ";
				system("pause>0");
				break;
				
			case 5:
				int dat;
				cout<<"\nNumero que desea buscar : "; cin>>dat;
				busqueda_indexada(ptr,tam, dat);
				system("pause>0");
				break;
			
			case 6:
				cout<<"\nHasta luego. ";
				exit(1);
				
			default:
			cout<<"\nOpcion invalida.";
			system("pause>0");
			break;
		}
		
	}while(rep);
	
}

void menu()
{
	cout<<"\n\t\t\tMENU\n";
	cout<<"1./Generar un array.\n";
	cout<<"2./Imprimir.\n";
	cout<<"3./Busqueda lineal.\n";
	cout<<"4./Busqueda binaria.\n";
	cout<<"5./Busqueda indexada.\n";
	cout<<"6./Salir.\n";
	cout<<"Digite la opcion : ";
}

int* new_array(int size)
{
	int *A;
	A = new int[size];
	srand(time(NULL));
	for(int i=0; i<size; i++)
	{
		A[i]= rand() % 100;
	}
	return A;
}

void imprimir(int a[], int size)
{
	for(int i=0; i<size; i++)
	{
		cout<<" "<<a[i];
	}
	cout<<endl;
}

void busqueda_lineal(int a[], int size, int busca)
{
	for(int i=0; i<size; i++)
	{
		if(a[i]==busca)
		{
			cout<<"\nSe encontro el elemento "<<a[i]<<" en el indice :"<<i;
			return;	
		}
	}
	cout<<"\nDato no encontrado ";
	return;
}

void bubble_sort(int a[], int size)
{
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size-1;j++)
		{
			if(a[j]>a[j+1])
			{
				a[j]=a[j]+a[j+1];
				a[j+1]=a[j]-a[j+1];
				a[j]=a[j]-a[j+1];
			}
		}
	}
}

void busqueda_binaria(int a[], int size, int busca)
{
	
	bubble_sort(a,size);
	int inf = 0;
	int sup = size-1;
	
	while(inf<=sup)
	{
		int centro = ((sup-inf)/2)+inf;
		
		if(a[centro]==busca)
		{
			cout<<"\nSe encontro el elemento "<<a[centro]<<" en el indice :"<<centro;
			return;
		}
		else
		{
			if(busca<a[centro])
			{
				sup=centro-1;
			}
			else
			{
				inf = centro+1;
			}
		}
		
	}	
	cout<<"\nNo se encontro el elemento";
	return;
}


void busqueda_indexada(int a[],int size, int busca)
{
	//todo este primer bloque pudo haber sido otra funcion.
	//recordar que tanto como el indice como el arreglo deben estar ordenados.
	bubble_sort(a,size);
	int division = size/3 + 1;
	int b[division]; //valores del indice
	int index[division];// indice
	/*Los bloques siempre crearan cuartiles es decir siempre se tendra un indice de 4 secciones 
	opcional (se podria crear un indice del indice cuando el array es muy grande)*/
	for(int i=0; i<division; i++)
	{
		b[i] = a[division*i];
		index[i] = i*division;
	}
	//busqueda linear o secuencial
	for(int i=0; i<division; i++)
	{
		if(busca>=b[i] && busca<b[i+1])
		{
			for(int j=index[i]; j<index[i+1]; j++)
			{
				cout<<" "<<a[j]; //comprobacion que solo esta buscando en el indice indicado
				if(busca == a[j])
				{
					cout<<"\nDato encontrado :"<<a[j];
					return;
				}
				
			}
		}
		

	}
	cout<<"\nDato no encontrado ";
	return;
	
}

