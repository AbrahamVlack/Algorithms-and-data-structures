#include<iostream>
#include<time.h>

using std::cout;
using std::cin;
using std::endl;

void menu();
int* new_array(int size);
void imprimir(int a[], int size);
void busqueda_lineal(int a[], int size, int busca);
void bubble_sort(int a[], int size);
int rep_elem(int a[], int size);
void nuevo_arreglo(int a[], int size);


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
				int* pointer;
				int contador;
				cout<<"\nDigite el tamano del array :"; cin>>tam;
				ptr = new_array(tam);
				cout<<"\nArray : ";
				bubble_sort(ptr, tam);
				imprimir(ptr,tam);
				contador = rep_elem(ptr, tam);
				cout<<endl;
				cout<<"\nArray : ";
				nuevo_arreglo(ptr, tam);
				cout<<"\nNumero de elementos eliminados "<<contador;
				system("pause>0");
				break;

			case 2:
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
	cout<<"2./Salir.\n";
	cout<<"Digite la opcion : ";
}

int* new_array(int size)
{
	int *A;
	A = new int[size];
	srand(time(NULL));
	for(int i=0; i<size; i++)
	{
		A[i]= rand() % 300 + 200;
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

int rep_elem(int a[], int size)
{
	int conta=0;
	for(int i=0; i<size; i++)
	{
		if(a[i]==a[i+1])
		{
			conta = conta+1;
		}
	}
	
	return conta;
	
}

void nuevo_arreglo(int a[], int size)
{
	int A[size];
	for(int i=0; i<=size; i++)
	{
		if(a[i]==a[i+1])
		{
			A[i] = 0;
		}
		else
		{
			A[i] = a[i];
		}
	}
	for(int i=0; i<size; i++)
	{
		if(A[i]==0)
		{
			cout<<"";
		}
		else
		{
			cout<<" "<<A[i];
		}
	}
}