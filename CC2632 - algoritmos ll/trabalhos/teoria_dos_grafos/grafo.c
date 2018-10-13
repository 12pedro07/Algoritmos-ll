#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////
//			LISTA DE TAREFAS:			// 
//		(OK) 0 -> Desenhar Grafo		//
//		(OK) 1 -> Grafo simples			//
//		(OK) 2 -> Sequencia dos graus	//
//		(OK) 3 -> Numero de arestas		//
//		(OK) 4 -> Grafo completo		//
//		(  ) 5 -> Grafo conexo			//
//		(  ) 6 -> Grafo bipartido		//
//		(  ) 7 -> Grafo arvore			//
//		(  ) 8 -> Maior numero de		//
//				  passeios de tamanho	//
//				  3 e em quais vertices	//
//				  eles ocorrem			//
//////////////////////////////////////////


/* 	matriz de adjacencia:
		   v1 | v2 | v3 | v4 
	v1 - (  0 |  2 |  0 |  1 )
	v2 - (  2 |  0 |  2 |  1 )
	v3 - (  0 |  2 |  0 |  1 )
	v4 - (  1 |  1 |  1 |  0 )

	matriz de incidencia:
		   e1 | e2 | e3 | e4 | e5 | e6 | e7 
	v1 - (  1 |  1 |  1 |  0 |  0 |  0 |  0 )
	v2 - (  1 |  1 |  0 |  1 |  1 |  0 |  1 )
	v3 - (  0 |  0 |  0 |  1 |  1 |  1 |  0 )
	v4 - (  0 |  0 |  1 |  0 |  0 |  1 |  1 )
	
*/

struct grafo{
	int** m_adj;
	int ordem;
};

struct grafo cria_grafo(int ordem){
	struct grafo g;
	g.ordem = ordem;
	g.m_adj = malloc(sizeof(int*)*ordem);
	int i;
	for (i=0;i<ordem;i++)
		g.m_adj[i] = malloc(sizeof(int)*ordem);
	return g;
}

void destroi_grafo(struct grafo g){
	int i;
	for (i=0;i<g.ordem;i++){
		free(g.m_adj[i]);
	}
	free(g.m_adj);
}

void matriz_adjacencia(struct grafo g){
	printf("\nMatriz de adjacencia:\n\n");
	int i,j;
	printf("       v0 |");
	for (i=1;i<g.ordem-1;i++){
		printf(" v%d |",i);
	} printf(" v%d\n",i);
	for (i=0;i<g.ordem;i++){
		printf("v%d - (",i);
		for (j=0;j<g.ordem-1;j++){
			if (g.m_adj[i][j]<10)
				printf("  %d |",g.m_adj[i][j]);
			else
				printf(" %d |",g.m_adj[i][j]);
		}
		printf(" %d  )\n",g.m_adj[i][j]);	
	}
	puts("");
}

void simples(struct grafo g){
	int i,j;
	for (i=0;i<g.ordem;i++){
		
		// procura por laços
		if (g.m_adj[i][i] != 0) {
		printf("\t1.--> grafo nao simples, possui um laco no vertice v%d\n",i);
		return;
		}
		
		// procura por arestas paralelas / multiplas
		for (j=0;j<=i;j++){ // olha apenas na parte inferior da diagonal principal, para economizar processamento, pois A(G) = A(G)Transposta
			if (g.m_adj[i][j] > 1){
				printf("\t1. --> grafo nao simples, possui arestas multiplas entre os vertices v%d e v%d\n",i,j);
				return;
			}
		}

	}
	printf("\t1.--> grafo simples\n");
}

void seq_graus(struct grafo g){
	
	int i,j,aux;
	int* seq = malloc(sizeof(int)*g.ordem);
	
	// grau do vertice i = somatoria dos elementos da linha i na matriz de adjacencia
	for (i=0;i<g.ordem;i++){
		seq[i] = 0;
		for (j=0;j<g.ordem;j++){
			seq[i] += g.m_adj[i][j];
		}
	}
	
	// bubblesort invertido
	for(i = 1; i < g.ordem; i++){
		for(j = 0; j < g.ordem-1; j++){
			if (seq[j] < seq[j+1]){
				aux = seq[j];
				seq[j]=seq[j+1];
				seq[j+1]=aux;
			}
		}
	}

	// impressao
	printf("\t2. --> seq. de graus: ");
	for (i=0;i<g.ordem;i++){
		printf("%d ",seq[i]);
	} printf("\n");
	
	free(seq);
	
}

void num_arestas(struct grafo g){
	int i,j,arestas=0;
	for (i=0;i<g.ordem;i++){
		for (j=0;j<=i;j++){
			arestas += g.m_adj[i][j];
		}
	}
	
	printf("\t3. --> %d arestas\n",arestas);
	
}

void completo(struct grafo g){
	int i,j;
	for (i=0;i<g.ordem;i++){
		for (j=0;j<i;j++){
			if (g.m_adj[i][j] == 0){
				printf("\t4. --> Grafo nao completo, nao existe a aresta v%d v%d\n",i,j);
				return;
			}
		}
	}
	printf("\t4. --> Grafo completo\n");
}

int main(int argc, char*argv[]){

//////////// TESTES ////////////////////
	struct grafo x = cria_grafo(4);
	
	x.m_adj[0][0] = 0;
	x.m_adj[0][1] = 2;
	x.m_adj[0][2] = 0;
	x.m_adj[0][3] = 1;
	x.m_adj[1][0] = 2;
	x.m_adj[1][1] = 0;
	x.m_adj[1][2] = 2;
	x.m_adj[1][3] = 1;
	x.m_adj[2][0] = 0;
	x.m_adj[2][1] = 2;
	x.m_adj[2][2] = 0;
	x.m_adj[2][3] = 1;
	x.m_adj[3][0] = 1;
	x.m_adj[3][1] = 1;
	x.m_adj[3][2] = 1;
	x.m_adj[3][3] = 0;

	matriz_adjacencia(x);
	simples(x);
	seq_graus(x);
	num_arestas(x);
	completo(x);
	
	puts("");
	destroi_grafo(x);

////////////////////////////////////////

	system("pause");
	return 0;
}
