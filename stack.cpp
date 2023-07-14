#include<stack>
#include<iostream>
using std::stack;
using std::cout;
using std::cin;

/*2 almacenar n datos en pila e imprimir el mayor
 imprimir n datos de la pila
 ciclos independientes para la busqueda, impresion y generacion*/

int main() 
{
	stack<int> pila1, pila2;	
	int tam;
	cout<<"Digite el tamano de la pila :"; cin>>tam;
	cout<<"\nStank en generacion :";
	
	for(int i=0; i<tam; i++)
	{
		pila1.push(rand()%100);
		cout<<" "<<pila1.top();
	}
	pila2 = pila1; //pila auxiliar;
	
	
	int mayor = 0;
	for(int i=0; i<tam; i++)
	{
		if(pila1.top()>mayor)
		{
			mayor=pila1.top();
		}
		pila1.pop();
	}
	cout<<"\nEl mayor dato en la pila :"; cout<<mayor;
	
	
	cout<<"\nStack en degeneracion :";
	for(int i=0; i<tam-1;i++)
	{
		cout<<" "<<pila2.top();
		pila2.pop();
	}
	
	
	return 0;
}
