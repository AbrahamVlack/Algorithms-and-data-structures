#include<iostream> //ordenamiento burbuja
using std::cout;
using std::endl;

void sort(int a[], int lenght);
void imprimir(int lenght,int a[]);

int main()
{
	int a[] = {5,3,4,2,1,7,9,0,-1,-2,10};
	int size = sizeof(a)/sizeof(a[0]); //5 elements
	
	sort(a,size);
	imprimir(size,a);
	
}

void sort(int a[], int lenght)
{
	
	for(int i =0; i<lenght; i++)
	{
		for(int j=0; j<lenght-1; j++)
		{
			if(a[j]>a[j+1])//Cambiando el sentido de la diferencia cambia el orden de mayor a menor
			{
				a[j]=a[j]+a[j+1];//swap
				a[j+1] =a[j]-a[j+1];
				a[j] = a[j]-a[j+1];
			}
			
		}
		
	}
}

void imprimir(int lenght,int a[])
{
	for(int i =0; i<lenght; i++)
	{
		cout<<" "<<a[i];
	}
}