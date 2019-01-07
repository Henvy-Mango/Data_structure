//#include<stdio.h>
//#include<stdlib.h>
//
//#define Max 10
//#define True 1
//#define False 0
//
//typedef struct vnode *VNode;
//typedef struct vnode adj[Max];
//struct vnode
//{
//	char data;
//	struct vnode *next;
//};
//
//typedef struct vexnode *Graph;
//struct vexnode
//{
//	adj vex;   //存放顶点
//	int n, e;
//};
//
//typedef struct Edge
//{
//	char V1, V2;
//}Edge;
//
//int visit[Max] = { 0 };
//
//Graph Init(Graph G)
//{
//
//
//	int i = 0;
//	char S[10];
//
//	scanf("%d", &G->n);      //顶点 
//	scanf("%d", &G->e);      //边 
//	scanf("%s", S);
//
//	for (i = 0; i < G->n; i++)
//	{
//		G->vex[i].data = S[i];    //顶点信息 
//		G->vex[i].next = NULL;    //初始化 
//	}
//
//	return G;
//}
//
//void Insert(Graph G, Edge E)
//{
//	int i = 0;
//	int v1 = 0, v2 = 0;
//	while (G->vex[v1].data != E.V1)        //找顶点 
//		v1++;
//	while (G->vex[v2].data != E.V2)        //找顶点 
//		v2++;
//
//	VNode V = (VNode)malloc(sizeof(struct vnode));
//	V->data = v2;
//	V->next = NULL;
//
//	if (G->vex[v1].next == NULL)         //找位置 
//		G->vex[v1].next = V;
//	else
//	{
//		VNode p = &G->vex[v1];
//
//
//		while (V->data > p->next->data)
//		{
//			p = p->next;
//			if (p->next == NULL)	break;
//		}
//
//		if (p->next == NULL)
//			p->next = V;
//		else
//		{
//			V->next = p->next;
//			p->next = V;
//		}
//	}
//}
//
//void DFS(Graph G, int v)
//{
//	visit[v] = 1;
//	VNode p = &G->vex[v];
//	printf("%c", p->data);
//	p = p->next;
//	while (p != NULL)
//	{
//		if (visit[p->data] == 0)
//			DFS(G, p->data);
//		p = p->next;
//	}
//
//}
//
//void BFS(Graph G, int v)
//{
//	VNode p = &G->vex[v];
//	if (visit[v] == 0)
//	{
//		visit[v] = 1;
//		printf("%c", p->data);
//	}
//	p = p->next;
//	while (p != NULL)
//	{
//		if (visit[p->data] == 0)
//		{
//			visit[p->data] = 1;
//			printf("%c", G->vex[p->data].data);
//		}
//		p = p->next;
//	}
//	v++;
//	if (v < G->n)	BFS(G, v);
//}
//
//int main()
//{
//	int i = 0;
//	Edge E;
//	char S[4];
//
//	printf("Please input quantity of Vertex : Please input quantity of Edge : Please input each node name : Please input node pair of each edge ( format : i,j ): \n");
//
//	Graph G = (Graph)malloc(sizeof(struct vexnode));
//	Init(G);
//
//	for (i = 0; i < G->e; i++)     //读取边数据 
//	{
//		scanf("%s", S);
//		E.V1 = S[0];
//		E.V2 = S[2];
//		Insert(G, E);
//		E.V1 = S[2];
//		E.V2 = S[0];
//		Insert(G, E);
//	}
//	DFS(G, 0);
//
//	printf("\n");
//	for (i = 0; i < Max; i++)	visit[i] = 0;
//
//	BFS(G, 0);
//
//
//	return 0;
//}
