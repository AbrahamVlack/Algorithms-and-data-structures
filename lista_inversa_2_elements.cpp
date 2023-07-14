#include<iostream>
#include<queue>
using std::cout;
using std::queue;

struct nodo{
	int data;
	struct nodo* siguiente;
};

struct nodo* create(int num);
void lista(struct nodo *&cabeza, int num);
void list_invr(struct nodo *&cabeza);
void selec_queue_divider(struct nodo* cabeza, queue<int> *q, queue<int> *q2);
void free_memory(struct nodo *& cabeza);
void print(struct nodo *cabeza);


int main(){
	struct nodo* cabeza = NULL;
	lista(cabeza, 1);
	lista(cabeza, 2);
	lista(cabeza, 3);
	lista(cabeza, 4);
	lista(cabeza, 5);
	lista(cabeza, 6);
	lista(cabeza, 7);
	
	print(cabeza);
	list_invr(cabeza);
	cout<<"\nNew lista : ";
	print(cabeza);
	
	return 0;
}

struct nodo* create(int num){
	struct nodo* temp = new nodo;
	temp->data = num;
	temp->siguiente = NULL;
	
	return temp;
}

void lista(struct nodo *&cabeza, int num){
	if(cabeza == NULL){
		struct nodo* temp = create(num);
		cabeza = temp;
		return;
	}
	else{
		struct nodo* temp = create(num);
		struct nodo* aux = cabeza;
		while(aux->siguiente != NULL){
			aux = aux->siguiente;
		}
		aux->siguiente = temp;
	}
}

void print(struct nodo* cabeza){
	if(cabeza == NULL){
		return;
	}
	else{
		struct nodo* temp = cabeza;
		while(temp != NULL){
			cout<<temp->data<<" ";
			temp = temp->siguiente;
		}
	}
}

void list_invr(struct nodo *&cabeza){
	if(cabeza == NULL){
		return;
	}
	else if(cabeza->siguiente == NULL){
		return;
	}
	else{
		queue<int> cola, cola2;
		selec_queue_divider(cabeza, &cola, &cola2);	
		//-------------------------------------- // liberacion de memoria
		free_memory(cabeza);
		//----------------------------------------// list construction
		while(cola.empty() != true || cola2.empty() != true){
			if(cola2.empty() == true){
				return;
			}
			lista(cabeza, cola2.front());
			cola2.pop();
			lista(cabeza, cola.front());
			cola.pop();
		}
		
		
	}
}

void selec_queue_divider(struct nodo* cabeza, queue<int> *q, queue<int> *q2){
	
	queue<int> aux;
	struct nodo* temp = cabeza;
	while(temp != NULL){
		aux.push(temp->data);
		temp = temp->siguiente;
	}
	while(aux.empty() != true){ // division de la lista cada 2 elemests
		(*q).push(aux.front());
		aux.pop();
		
		if(aux.empty() == true){ //handle de imparidad
			break;
		}
		
		(*q2).push(aux.front());
		aux.pop();
	}
	
}

void free_memory(struct nodo *&cabeza){
	
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