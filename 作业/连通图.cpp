#include<stdio.h>
#include<stdlib.h>

typedef struct ArcNode
{
	int adjvex;
	struct ArcNode *next;
}ArcNode;

typedef struct VNode
{
	char data;
	ArcNode *first;
}VNode,AdjList[10];

typedef struct 
{
	AdjList Vertices;
	int vexnum, arcnum;
	int kind;
}ALGraph;

