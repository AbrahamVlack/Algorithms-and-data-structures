/*
	Por:Campos Hernandez Abraham
*/
#include<iostream>
#include<string>
#include<stack>

using std::cout; //No utilizar namespace std;
using std::endl;
using std::cin;
using std::stack;
using std::string;


bool balanceo(string expresion);

int main() 
{
	
	string expresion;
	cout<<"\nDigite la expresion :"; cin>>expresion;
	
   	if (balanceo(expresion)==true){
   		cout << "\nLa expresion esta balanceada";
	}	
   	else{
   		cout << "\nLa expresion no esta balanceada";
	}
     	
}

bool balanceo(string expresion)
{
	
	stack<char> pila1;
  	char ch;
   
   	for(int i=0; i<expresion.length(); i++) //recorremos la cadena 
	{ 
	    
      	if(expresion[i]=='('||expresion[i]=='['||expresion[i]=='{') //Si en la cadena se encuentra 
      	// una operacion de apertura la agregamos a la pila
		{    
         	pila1.push(expresion[i]);
         	continue; //saltamos a la siguiente iteracion 
      	}
      	
      	if (pila1.empty()) // no puede estar vacia si, significa que hay un perentesis abierto
         	return false;
         	
         	switch (expresion[i]) //Evaluaciones
			{
            	case ')':
            		
               		ch = pila1.top();
               		pila1.pop();
               		
               		if (ch=='[' || ch=='{')
               		{
						return false;
					}
                  	break;
                  	
            	case '}': 
            	
               		ch = pila1.top();
               		pila1.pop();
               		
               	if (ch=='(' || ch=='[')
               		{
               		 return false;              			
				   	}
                 	 break;
                 	 
            	case ']': 
            	
               		ch = pila1.top();
               		pila1.pop();
               		
               	if (ch =='(' || ch == '{')
               		{
               			return false;
				   	}
                 		break;
			}
    }

    return (pila1.empty()); 
}