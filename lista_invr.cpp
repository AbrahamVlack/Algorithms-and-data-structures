//Lista y lista inversa
//Abraham Campos
// date: 17/7/22

#include<iostream>
#include<stack>
using std::cout;
using std::stack;

struct nodo{// para la lista
	int data;
	struct nodo* siguiente;
};

struct nodo* create(int num);
void lista(struct nodo *&cabeza, int num);
void lista_invr(struct nodo *&cabeza);
void imprimir(struct nodo* cabeza);
void vaciar(struct nodo *&cabeza);


int main(){
	struct nodo* cabeza = NULL;
	
	lista(cabeza, 1);
	lista(cabeza, 2);
	lista(cabeza, 3);
	lista(cabeza, 4);
	imprimir(cabeza);
	lista_invr(cabeza);
	
	
	return 0;
}

struct nodo* create(int num){
	struct nodo* temp = (nodo*) malloc(sizeof(nodo));
	temp->data = num;
	temp->siguiente = NULL;
	
	return temp;
}

void lista(struct nodo *&cabeza, int num){
	if(cabeza == NULL){
		struct nodo* temp = NULL;
		temp = create(num);
		cabeza = temp;
		return;
	}
	else{
		struct nodo* temp = create(num);
		struct nodo* temp2 = cabeza;
		while(temp2->siguiente != NULL){
			temp2 = temp2->siguiente;
		}
		temp2->siguiente = temp;
	}
}

void lista_invr(struct nodo *&cabeza){
	if(cabeza == NULL){
		return;
	}
	else if(cabeza->siguiente == NULL){
		return;
	}
	else{
		stack<int> pila;
		struct nodo* temp = cabeza;
		while(temp != NULL){
			pila.push(temp->data);
			temp = temp->siguiente;
		}
		vaciar(cabeza);
		// construccion de la lista invertida
		while(pila.empty() != true){
			lista(cabeza, pila.top());
			pila.pop();
		}
	}
	cout<<std::endl<<"Lista creada e invertida:";
	imprimir(cabeza);
}

void vaciar(struct nodo *&cabeza){ //liberacion adecuada de la memoria
	while(cabeza != NULL){
		
		if(cabeza->siguiente == NULL){
			struct nodo* temp3 = cabeza;
			cabeza = NULL;
			delete temp3;
			return; 
		}
		struct nodo* temp = cabeza;
		struct nodo* temp2 = cabeza;
		while(temp->siguiente != NULL){
				temp = temp->siguiente;	
			}
		while(temp2->siguiente != temp){
			temp2 = temp2->siguiente;
		}
		temp2->siguiente = NULL;
		delete temp;
	}
}

void imprimir(struct nodo* cabeza){
	struct nodo* temp = cabeza;
	while(temp != NULL){
		cout<<temp->data<<" ";
		temp = temp->siguiente;
	}
}