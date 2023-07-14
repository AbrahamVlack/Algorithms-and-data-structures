#include<iostream>
#include<queue>
#include<stack>

//Campos Hernande Jose Abraham
//Matricula 2020301199
//Ocampo Vazquez Bryann Milton
//2021630539

using std::queue;
using std::cout; // No usar using namespace std;
using std::stack;


struct nodo{
	int numero;
	nodo* izquierda;
	nodo* derecha;
};

struct nodo* nuevo(int valor){ //constructor
	struct nodo* temp = new nodo; // (*nodo) malloc(sizeof(nodo*));
	temp->izquierda = NULL;
	temp->derecha = NULL;
	temp->numero = valor;

	return temp;
}

void menu();

//modificacion
void insertar(nodo** raiz, int valor);

struct nodo* eliminarhoja(nodo* raiz, int num); //retorna una raiz modif
void eliminar(nodo** raiz, int num); // a doble apuntador

//lecturas
void preorden(nodo* raiz);
void postorden(nodo* raiz);
void inorden(nodo* raiz);

void preordenconver(nodo* raiz);
void postordenconver(nodo* raiz);
void inordenconver(nodo* raiz);

void buscarmenor(nodo* raiz);
void buscarmayor(nodo* raiz);
void busqueda(nodo* raiz, int num);

void cargar_arbol(nodo** raiz);

void mayor(nodo* raiz, int* cont, queue<int>* q);
void n_esimo(nodo* raiz);

void zigzag(nodo* raiz);


int main()
{
	struct nodo* raiz = NULL;
	int opc, valor;
	do{
		system("cls");
		menu(); std::cin>>opc;
		switch(opc)
		{

			case 1:

				cout<<"\nDigite el valor del nodo:"; std::cin>>valor;
				insertar(&raiz, valor);

				system("pause>0");

				break;

			case 2:
				cout<<"\nRecorrido en preorden: ";
				preorden(raiz);
				system("pause>0");

				break;

			case 3:
				cout<<"\nRecorrido en inorden: ";
				inorden(raiz);
				system("pause>0");

				break;

			case 4:
				cout<<"\nRecorrido en postorden: ";
				postorden(raiz);
				system("pause>0");

				break;

			case 5:
				cout<<"\nRecorrido en preorden converso: ";
				preordenconver(raiz);
				system("pause>0");

				break;

			case 6:
				cout<<"\nRecorrido en inorden converso: ";
				inordenconver(raiz);
				system("pause>0");

				break;

			case 7:
				cout<<"\nRecorrido en postorden converso: ";
				postordenconver(raiz);
				system("pause>0");

				break;

			case 8:
				int del;
				cout<<"\nDigite la hoja a eliminar :"; std::cin>>del;
				eliminar(&raiz, del);
				system("pause>0");
				break;

			case 9:
				buscarmenor(raiz);
				system("pause>0");
				break;

			case 10:
				buscarmayor(raiz);
				system("pause>0");
				break;

			case 11:
			int num;
			std::cout<<std::endl<<"Digite el numero:"; std::cin>>num;
			busqueda(raiz, num);
			system("pause>0");
				break;

			case 12:
				cargar_arbol(&raiz);

				system("pause>0");
				break;
				
			
			case 13:
				n_esimo(raiz);
				system("pause>0");
				break;
				
			case 14:
				zigzag(raiz);
				system("pause>0");
				break;

			case 15:
				cout<<"\nHasta luego";
				exit(0);
				break;

			default:
				cout<<"\nOpcion incorrecta";
				system("pause>0");
				break;
		}


	}while(opc!=15);


}

void insertar(nodo** raiz, int valor){
	if(*raiz == NULL){
		struct nodo* temp = nuevo(valor);
		*raiz = temp;
		return;
	}
	else if((*raiz)->numero == valor){
		std::cout << "\nNo se puede insertar, existe un nodo con este valor." << std::endl;
		return;
	}
	else
	{
		if(valor < (*raiz)->numero ){
			insertar(&((*raiz)->izquierda), valor); //interesante &((*nodo)->link) es &(*(*nodo).link)
			return;
		}
		else{
			insertar(&((*raiz)->derecha), valor);
			return;
		}
	}
}

void preorden(nodo* raiz){ // R I D
	if(raiz == NULL) return;

	cout<<raiz->numero<<" ";
	preorden(raiz->izquierda);
	preorden(raiz->derecha);

	/* USO INCORRECTO
	struct nodo* temp;
	temp = raiz;
	cout<<raiz->numero<<" ";
	while(raiz->izquierda != NULL){
		preorden(raiz->izquierda);
		break;
	}
	while(raiz->derecha != NULL){
		preorden(raiz->derecha);
		break;
	}*/

}

void inorden(nodo* raiz){ // I R D
	if(raiz == NULL) return ;

	inorden(raiz->izquierda);
	cout<<raiz->numero<<" ";
	inorden(raiz->derecha);
}

void postorden(nodo* raiz){ // I D R
	if(raiz == NULL) return;

	postorden(raiz->izquierda);
	postorden(raiz->derecha);
	cout<<raiz->numero<<" ";
}



void preordenconver(nodo* raiz){ // R D I
	if(raiz == NULL) return;

	cout<<raiz->numero<<" ";
	preordenconver(raiz->derecha);
	preordenconver(raiz->izquierda);
}

void inordenconver(nodo* raiz){ // D R I
	if(raiz == NULL) return ;

	inordenconver(raiz->derecha);
	cout<<raiz->numero<<" ";
	inordenconver(raiz->izquierda);
}

void postordenconver(nodo* raiz){ //  D I R
	if(raiz == NULL) return;

	postordenconver(raiz->derecha);
	postordenconver(raiz->izquierda);
	cout<<raiz->numero<<" ";
}

void eliminar(nodo** raiz, int num){
	if( *raiz == NULL) return;

	if( num < (*raiz)->numero){
		eliminar(&((*raiz)->izquierda), num);
	}
	else if( num > (*raiz)->numero){
		eliminar(&((*raiz)->derecha), num);
	}
	else{
		if((*raiz)->derecha == NULL && (*raiz)->izquierda == NULL){
			delete *raiz;
			*raiz = NULL;
		}
	}
}

struct nodo* eliminarhoja(nodo* raiz, int num){
	if( raiz == NULL) return raiz;

	if( num < raiz->numero){
		raiz->izquierda = eliminarhoja(raiz->izquierda, num);
	}
	else if( num > raiz->numero){
		raiz->derecha = eliminarhoja(raiz->derecha, num);
	}
	else{
		if(raiz->derecha == NULL && raiz->izquierda == NULL){
			delete raiz;
			raiz = NULL;
		}
	}
	return raiz;
}

void buscarmenor(nodo* raiz){
	if(raiz == NULL){
		std::cout << '\n' << "Arbol vacio" ;
		return;
	}
	else{
		struct nodo* temp = NULL;
		temp = raiz;
		while(temp->izquierda != NULL){
			temp = temp->izquierda;
		}
		cout<< '\n' << "es :" <<temp->numero;
		return;
	}
}

void buscarmayor(nodo* raiz){
	if(raiz == NULL){
		std::cout<< '\n' << "Arbol vacio, nada que buscar";
		return;
	}
	else{
		struct nodo* temp = NULL;
		temp = raiz;
		while(temp->derecha != NULL){
			temp = temp->derecha;
		}
		cout<< '\n' << "es :" <<temp->numero;
		return;
	}
}

void busqueda(nodo* raiz, int num){
	if(raiz == NULL){
		std::cout <<std::endl<<"Arbol vacio, nada que buscar";
	}
	else if(num == raiz->numero){
		std::cout<<std::endl<<"Se encontro el valor";
		return;
	}
	else if(num < raiz->numero){
		busqueda(raiz->izquierda, num);
	}
	else if(num > raiz->numero){
		busqueda(raiz->derecha, num);
	}
	else {
		std::cout<<std::endl<<"No Se encontro valor";
		return;
	}

}

void cargar_arbol(nodo** raiz){
	if(*raiz != NULL){
		cout<<"\nArbol no vacio, no se puede cargar";
		return;
	}
	else{
		insertar(&(*raiz), 49);
		insertar(&(*raiz), 37);
		insertar(&(*raiz), 13);
		insertar(&(*raiz), 7);
		insertar(&(*raiz), 19);
		insertar(&(*raiz), 25);
		insertar(&(*raiz), 41);
		insertar(&(*raiz), 89);
		insertar(&(*raiz), 53);
		insertar(&(*raiz), 71);
		insertar(&(*raiz), 60);
		insertar(&(*raiz), 82);
		
	}

	cout<<"\n\nArbol Cargado.........";

}

void menu(){
	cout<<"\t\t\tMenu";
	cout<<"\n1./Insertar nodo";
	cout<<"\n2./Preorden";
	cout<<"\n3./Inorden";
	cout<<"\n4./Posorden";
	cout<<"\n5./Preorden Converso";
	cout<<"\n6./Inorden Converso";
	cout<<"\n7./Posorden Converso";
	cout<<"\n8./Eliminar una hoja";
	cout<<"\n9./Busca menor";
	cout<<"\n10./Busca mayor";
	cout<<"\n11./Busca nth";
	cout<<"\n12./Cargar Arbol";
	cout<<"\n13./Encontrar el n-esimo mayor elemento";
	cout<<"\n14./Recorrido ZigZag";
	cout<<"\n\n15.Salir";
	cout<<"\nOpciones : ";
}

void mayor(nodo* raiz, int* cont, queue<int>* q){ 
	
	if(raiz == NULL) return ;

	mayor(raiz->derecha, cont, q); //Guardado D R I
	(*q).push(raiz->numero); // si no esta (*q).push y solo se coloca *q.push marca error porque piensa que tratas de usar el operador ->
	mayor(raiz->izquierda, cont, q);
	*cont = *cont + 1;
	
}

void n_esimo(nodo* raiz){
	queue<int> p;
	int cont = 0;
	if(raiz == NULL){
		cout<<"Arbol vacio";
		return;
	}
	else
	{
		mayor(raiz, &cont, &p); //no recordaba que podia pasar una cola como argumento de una funcion atravez de apuntadores
		int aux;
		cout<<"\nDigite el mayor elemento que desea encontrar";
		cout<<"\nConsiderando que 1 es el mayor y n el menor :"; std::cin>>aux;
		if(aux > cont || aux < 0){
			cout<<"Error";
			return;
		} 
		else if(aux == 1){
			cout<<p.front();
    		return;
		}
		else{
			for(int i = 1; i< aux ; i++){
				p.pop();
			}
			cout<<"Es :"<<p.front();
		}		
			
	}	
		
}

void zigzag(nodo* raiz){ 
	struct nodo* temp = NULL;// contenedor que guarda direcciones de nodos
	
	stack<nodo*> pila1, pila2;
	pila1.push(raiz); //se insertar la raiz en la pila 1
	
	while(pila1.empty() != true || pila2.empty() != true){
		
		while (pila1.empty() != true)
        {
            temp = pila1.top();
            pila1.pop();
            
            cout<<temp->numero<<" ";
            if (temp->derecha != NULL){
            	pila2.push(temp->derecha);
			}
                
            if (temp->izquierda != NULL){
            	pila2.push(temp->izquierda);
			}
                
        }
        
        while (pila2.empty() != true)
        {
            temp = pila2.top();
            pila2.pop();
            cout<<temp->numero<<" ";
            
            if (temp->izquierda != NULL){
            	pila1.push(temp->izquierda);
			}
                
            if (temp->derecha != NULL){
            	pila1.push(temp->derecha);
			}   
        }
	}
}

