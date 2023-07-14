#include<iostream>
using std::cout;

struct grafo{
	int Vex;
	int Edg;
	int **Adj;
};

struct grafo* matriz_adj(){
	int i, u, v;
	struct grafo *G = new grafo; //(struct grafo*) malloc(sizeof(struct grafo));
	
	cout<<"\nNumero de vertices: "; std::cin>>G->Vex ;
	cout<<"\nNumero de aristas: "; std::cin>>G->Edg ;
	
	G->Adj = new int*[G->Vex * G->Vex]; //(int**) malloc(sizeof(G->Vex * G->Vex));
	for(u = 0; u<G->Vex; u++){
		for(v = 0; v<G->Vex; v++){
			G->Adj[v][v] = 0;
		}
	}
	
	for(i = 0; i<G->Edg; i++){
		cout<<"\nAristas :"; std::cin>>u,v;
		
		G->Adj[u][v] = 1;
		G->Adj[v][u] = 1;
	}
	
	return G;
}

int main(){
	struct grafo* temp = matriz_adj();
	
}


