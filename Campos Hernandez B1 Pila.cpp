#include<stack>
#include<iostream>
#include<string>
using std::stack;
using std::cout;
using std::string;
using std::cin;
using std::endl;

void menu();
void insertar_top(stack<string>* pila, string palabra);
void insertar_inicio(stack<string>* pila, string palabra);
void imprimir_fin_to_ini(stack<string>* pila);

int main()
{
	stack<string> pila, pila2;
	string palabra;
	int opc;
	do
	{
		system("cls");
		menu(); std::cin>>opc;
		
		switch(opc)
		{	
				
			
			case 1:
				
				cout<<"\nAgregar palabra al inicio :"; cin>>palabra;
				insertar_inicio(&pila, palabra);
				
				/*if(pila.empty()==true)
				{
					cout<<"\nAgregar palabra al inicio :"; cin>>palabra;
					pila.push(palabra);
					cout<<"\npalabra agregada correctamente";
				}
				else
				{
					cout<<"\nAgregar palabra al inicio :"; cin>>palabra;
					while(pila.empty()!=true)
					{
						pila2.push(pila.top());
						pila.pop();
					}
					pila.push(palabra);
					while(pila2.empty()!=true)
					{
						pila.push(pila2.top());
						pila2.pop();
					}
					cout<<"\npalabra agregada correctamente";	
				}*/
				system("pause>0");
				break;
			
			case 2:
				{
					cout<<"\nPalabra que desea agregar al final :"; cin>>palabra;
					insertar_top(&pila, palabra);
					system("pause>0");
				}
				
				break;
			
			case 3:// El usuario debe de proporcionar posiciones validas 
				{
						if(pila.empty()==true)//si la pila esta vacia
					{
						cout<<"\nAgregar palabra :"; cin>>palabra;
						pila.push(palabra);
						cout<<"\npalabra agregada correctamente";
					}
					else
					{
						int pos,n;
						n=0;
						cout<<"\ninfo : ultimo/top = 0, primero = n-1";
						cout<<"\nDigite la posicion donde desea insertar la palabra :"; cin>>pos;
						if(pos==0)//si quiere agregar una palabra en el top de la pila
						{
							cout<<"\nAgregar palabra :"; cin>>palabra;
							pila.push(palabra);
							cout<<"\npalabra agregada correctamente";
						}
						else//el usuario debe tener recordar 
							//que la posicion 0 es el ultimo elemento o top en la pila y la primera posicion es n-1;
						{
							cout<<"\nAgregar palabra :"; cin>>palabra;
							while(pos!=n)
							{
								pila2.push(pila.top());
								pila.pop();
								n++;
							}
							pila2.push(palabra);
							while(pila.empty()!=true)
							{
								pila2.push(pila.top());
								pila.pop();
							}
							while(pila2.empty()!=true)
							{
								pila.push(pila2.top());
								pila2.pop();
							}
							cout<<"\npalabra agregada correctamente";
						}
					}
					system("pause>0");
				break;
				}
			
			case 4://imprimir de inicio a fin
			{
			
				stack<string> aux;
				aux = pila;
				while(pila.empty()!=true)
				{
					pila2.push(pila.top());
					pila.pop();
				}
				while(pila2.empty()!=true)
				{
					pila.push(pila2.top());
					cout<<" "<<pila.top();
					pila2.pop();
				}
				pila = aux;
				system("pause>0");
				break;
			}
			
			case 5:// imprime de fin a inicio
			{
				imprimir_fin_to_ini(&pila);
				/*
				stack<string> aux;
				aux = pila;
				while(pila.empty()!=true)
				{
					cout<<" "<<pila.top();
					pila.pop();
				}
				pila = aux;
				system("pause>0");
				break;
				*/
				system("pause>0");
				break;
			}
			
			case 6://eliminar al inicio
				{
					if(pila.empty()==true)
					{
						cout<<"\nError :La pila ya esta vacia";
					}
					else
					{
						while(pila.empty()!=true)
						{
							pila2.push(pila.top());
							pila.pop();
						}
						pila2.pop();
						while(pila2.empty()!=true)
						{
							pila.push(pila2.top());
							pila2.pop();
						}
						cout<<"\nSe elimino la palabra correctamente";
					}
					system("pause>0");
					break;
				}
				
			
			case 7://eliminar al final
				if(pila.empty()==true)
				{
					cout<<"\nError : La pila ya esta vacia";
					
				}
				else
				{
					pila.pop();
					cout<<"\nPalabra eliminada correctamente";
				}
				
				
				system("pause>0");
				break;
			
			case 8:// El usuario debe de proporcionar posiciones validas 
				{
					int pos,n;
					n=0;
					if(pila.empty()==true)
					{
						cout<<"\nError : La pila ya esta vacia";
					}
					else
					{
						cout<<"\ninfo : ultimo/top = 0, primero = n-1";
						cout<<"\nDigite la posicion que desea eliminar :"; cin>>pos;//el usuario debe tener recordar 
						//que la posicion 0 es el ultimo elemento en la pila y la primera posicion es n-1;
							while(n!=pos)
							{
								pila2.push(pila.top());
								pila.pop();
								n++;
							}
							pila.pop();
							
							while(pila.empty()!=true)
							{
								pila2.push(pila.top());
								pila.pop();
							}
							while(pila2.empty()!=true)
							{
								pila.push(pila2.top());
								pila2.pop();
							}
							cout<<"\nLa palabra a sido eliminada correctamente";
					}
					system("pause>0");
					break;
					
				}
			
			case 9:
				cout<<"\nHasta luego";
				break;
				
			default:
				cout<<"\nOpcion invalida";
				system("pause>0");
				break;
		}
	}while(opc!=9);
}

void menu()
{
	cout<<"\n\t\t\tMENU : REGISTRO DE DATOS";
	cout<<"\n1. Agregar palabra al inicio";
	cout<<"\n2. Agregar una palabra al final";
	cout<<"\n3. Agregar una palabra en lugar N";//
	cout<<"\n4. Imprimir de INICIO a FIN";
	cout<<"\n5. Imprimir FIN a INICIO";
	cout<<"\n6. Eliminar al inicio";
	cout<<"\n7. Eliminar al final";
	cout<<"\n8. Eliminar posicional N";
	cout<<"\n9. Salir";
	cout<<"\nOpcion :";
	
}

void insertar_top(stack<string>* pila, string palabra)
{
	(*pila).push(palabra); // la azucar sintetica es pila->push(palabra)
	cout<<"\npalabra agregada correctamente";
}

void insertar_inicio(stack<string>* pila, string palabra)
{
	stack<string> aux;
	if(pila->empty()==true)
	{
		pila->push(palabra);
		cout<<"\npalabra agregada correctamente";
	}
	else
	{
		while(pila->empty()!=true)
		{
			aux.push(pila->top());
			pila->pop();
		}
		aux.push(palabra);
		while(aux.empty()!=true)
		{
			pila->push(aux.top());
			aux.pop();
		}
		cout<<"\npalabra agregada correctamente";
	}
}

void imprimir_fin_to_ini(stack<string>* pila)
{
	//string zxc;
	stack<string> aux;
	aux = *pila;
	while(pila->empty()!=true)
	{
		//zxc = pila->top();
		cout<<" "<<pila->top(); //zxc; //WEIRD???
		pila->pop();
	}
	*pila = aux;
}