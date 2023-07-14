#include<iostream>
#include <stdlib.h>
#include <time.h>

using std::cout;
using std::endl;
using std::cin;

int *new_array(int tam);
void imprimir(int a[], int len);
void bubble_sort(int a[], int len);
void insertion_sort(int a[], int len);
void selection_sort(int a[], int len);
void merge_sort(int a[], int l, int r);
void merge(int a[], int izq, int mid, int dere);
void Quick_sort(int a[],int inicio,int final);
int particion(int a[],int inicio,int final);
void salir();
int get_menor(int a[], int inicio, int len);
void menu();


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
				int *ptr;
				cout<<"\nDigite el tamano del arreglo :"; cin>>tam;
				ptr = new_array(tam);
				cout<<("\nPulse cualquier tecla para continuar");
				system("pause>nul");
				break;
				
			case 2:	

				cout<<"\nArray :";
				imprimir(ptr,tam);
				cout<<endl;
				cout<<("\nPulse cualquier tecla para continuar");
				system("pause>nul"); /*no se puede consultar nuevamente la informacion o
				operar con ella despues de hacer uso de cualquier SORT al terminar liberar la memoria 
				al usar delete ptr, se tiene que crear un nuevo arreglo*/
				break;
							
			case 3:
				cout<<"\nBubble sort :";
				bubble_sort(ptr,tam); imprimir(ptr,tam);
				cout<<endl;
				cout<<("\nPulse cualquier tecla para continuar");
				system("pause>nul");
				delete ptr; 
				break;
				
			case 4:
				cout<<"\nInsercion sort :";
				insertion_sort(ptr, tam); imprimir(ptr,tam);
				cout<<endl;
				cout<<("\nPulse cualquier tecla para continuar");
				system("pause>nul");
				delete ptr;
				break;
				
			case 5:
				cout<<"\nSeleccion sort :";
				selection_sort(ptr, tam); imprimir(ptr,tam);
				cout<<endl;
				cout<<("\nPulse cualquier tecla para continuar");
				system("pause>nul");
				delete ptr;
				break;
				
			case 6:
				cout<<"\nMerge sort :";
				merge_sort(ptr, 0, tam-1); imprimir(ptr,tam);
				cout<<endl;
				cout<<("\nPulse cualquier tecla para continuar");
				system("pause>nul");
				delete ptr;
				break;
				
			case 7:
				{
				cout<<"\nQuick sort :";
				int inicio=0;
				int final = tam; //pelea con sizeof(prt)
				Quick_sort(ptr,inicio,final); imprimir(ptr,tam);
				cout<<("\nPulse cualquier tecla para continuar");
				system("pause>nul");
				delete ptr;
				break;
				}
				
			case 8:
				cout<<"\nHasta luego\n";
				exit(1);
				break;
				
			default:
				cout<<"opc no elegible";
				system("pause>nul");
				break;
		}
		
	}while(rep);
	
}

int get_menor(int a[], int inicio, int len)
{
	int ind_menor = a[inicio];
	int posicion = inicio;
	
	for(int i = inicio+1; i<len; i++)
	{
		if(a[i]<ind_menor)
		{
			ind_menor = a[i];
			posicion = i;
		}
		
	}
	
	return posicion;
}

void menu()
{
	cout<<"\t\t\tMenu\n";
	cout<<"1.Generar un arraglo.\n";
	cout<<"2.Imprimir .\n";
	cout<<"3.Ordenamiento burbuja.\n";
	cout<<"4.Ordenamiento insercion.\n";
	cout<<"5.Ordenamiento seleccion.\n";
	cout<<"6.Ordenamiento merge.\n";
	cout<<"7.Ordenamiento Quick.\n";
	cout<<"8.Salir.\n\n";
	cout<<"Digite la opcion :";
	
}

int *new_array(int tam)
{
	//parece tentador solo hacer esto
	//int A[tam]; pero no
	int* A;
	A = new int[tam];
	srand (time(NULL)); //semilla generador de numeros pseudoaleatorios que usa rand()
	for(int i=0; i<tam; i++)
	{
		A[i] = rand() % 100; //num aleatorios del 0 al 99
	}
	return A; //apunta al inicio del array generado por new 
}

void imprimir(int a[], int len)
{
	for(int i=0; i<len; i++)
	{
		cout<<" "<<a[i];
	}
	cout<<endl;
}

void bubble_sort(int a[], int len)//a[] sintax alternativo de *a como lo interprete el compilador
{
	for(int i=0; i<len; i++)
	{
		for(int j=0; j<len-1;j++)
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

void insertion_sort(int a[], int len)
{
	int valor, espacio;
	
	for(int i=1; i<len; i++)
	{
		valor = a[i]; //3 2 1 4
		espacio = i; // 0 1
		while(espacio>0 && a[espacio-1]>valor) 
		{
			a[espacio] = a[espacio-1];
			espacio = espacio -1;
		}
		a[espacio]=valor;
	}
}

void selection_sort(int a[], int len)
{
	int aux;
	int indx_menor;
	for(int i=0; i<len-1; i++)
	{
		indx_menor = get_menor(a,i,len);
		aux = a[i];
		a[i] = a[indx_menor];
		a[indx_menor] = aux;
	}
	 
		
}

void Quick_sort(int a[],int inicio,int final) //a,0,1
{
    int pIndex;
    if(inicio<final) //0<1?
    {
        pIndex = particion(a,inicio,final); //2
        Quick_sort(a,inicio,pIndex-1); //a,0,2-1
        Quick_sort(a,pIndex+1,final);
    }
}

int particion(int a[],int inicio,int final)//a,0,1
{
	int temp;
    int pivote=a[final]; //a[1] = 2
    int pIndex=inicio; //0
    for(int i=inicio;i<final;i++) // 0<2?
    {
        if(a[i]<=pivote) 
        {
        	temp=a[i]; 
            a[i]=a[pIndex]; //a[1]
            a[pIndex]=temp; //a[1]
            pIndex=pIndex+1; //2
        }
    }
    temp= a[pIndex] ; //a[2]
    a[pIndex] = a[final] ; //a[5] 
    a[final] =temp; // a[2] //{1,2,3,6,5,4}
    
    return pIndex; //2
}


void merge_sort(int a[], int l, int r)// 0-7
{
    if (l < r) //0<7
    {
       
        int m = l+(r-l)/2; //para evitar el desborde
 
        merge_sort(a, l, m);
        merge_sort(a, m+1, r);
 
        merge(a, l, m, r);
    }
}

void merge(int a[], int izq, int mid, int dere)
{
    int i, j, k;
    int n1 = mid - izq + 1;
    int n2 =  dere - mid;
 
    int L[n1], R[n2];
    
    for (i = 0; i < n1; i++)
        L[i] = a[izq + i];
    for (j = 0; j < n2; j++)
        R[j] = a[mid + 1+ j];
    
    i = 0; 
    j = 0; 
    k = izq;
	 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
 
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
