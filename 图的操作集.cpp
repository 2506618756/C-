#include <iostream>
#include <cstdlib>
using namespace std;

#define INFINITY 65535

typedef int Vertex;
typedef int WeightType;
typedef char DataType;
typedef struct GNode * PtrToGNode;
struct GNode{
	int Nv;
	int Ne;
	WeightType G[100][100];
	DataType Data[100];
};
typedef PtrToGNode MGraph;
typedef struct ENode * PtrToENode;
struct ENode{
	Vertex V1,V2;
	WeightType Weight;
};
typedef PtrToENode Edge;
MGraph CreateGraph( int Max )
{
	MGraph Graph;
	Graph = (MGraph)malloc(sizeof(struct GNode));
	Graph->Nv = Max;
	Graph->Ne = 0;
	for( int i=0; i<Graph->Nv; i++ )
		for( int j=0; j<Graph->Nv; j++ )
			Graph->G[i][j] = INFINITY;
	return Graph;
}
void InsertEdge( MGraph Graph, Edge E )
{
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;
}
MGraph BulidGraph()
{
	MGraph Graph;
	Edge E;
	int Nv,i;
	scanf("%d",&Nv);
	Graph = CreateGraph( Nv );
	scanf("%d",&(Graph->Ne));
	if(Graph->Ne)
	{
		E = (Edge)malloc(sizeof(struct ENode));
		for( i=0; i<Graph->Ne; i++ )
		{
			scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
			InsertEdge( Graph, E );
		}
	}
	getchar();
	for( int V=0; V<(Graph->Nv); V++ )
		scanf("%c",&(Graph->Data[V]));
	return Graph;
}
int main()
{
	ios::sync_with_stdio(false);
	BulidGraph();
	return 0;
}
