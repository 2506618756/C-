#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define INFINITE 0xFFFFFFFF   
#define VertexData unsigned int  //��������
#define UINT  unsigned int
#define vexCounts 6  //��������
char vextex[] = { 'A', 'B', 'C', 'D', 'E', 'F' };
struct node 
{
    VertexData data;
    unsigned int lowestcost;
}closedge[vexCounts]; //Prim�㷨�еĸ�����Ϣ
typedef struct 
{
    VertexData u;
    VertexData v;
    unsigned int cost;  //�ߵĴ���
}Arc;  //ԭʼͼ�ı���Ϣ
void AdjMatrix(unsigned int adjMat[][vexCounts])  //�ڽӾ����ʾ��
{
    for (int i = 0; i < vexCounts; i++)   //��ʼ���ڽӾ���
        for (int j = 0; j < vexCounts; j++)
        {
            adjMat[i][j] = INFINITE;
        }
    adjMat[0][1] = 6; adjMat[0][2] = 1; adjMat[0][3] = 5;
    adjMat[1][0] = 6; adjMat[1][2] = 5; adjMat[1][4] = 3;
    adjMat[2][0] = 1; adjMat[2][1] = 5; adjMat[2][3] = 5; adjMat[2][4] = 6; adjMat[2][5] = 4;
    adjMat[3][0] = 5; adjMat[3][2] = 5; adjMat[3][5] = 2;
    adjMat[4][1] = 3; adjMat[4][2] = 6; adjMat[4][5] = 6;
    adjMat[5][2] = 4; adjMat[5][3] = 2; adjMat[5][4] = 6;
}
int Minmum(struct node * closedge)  //������С���۱�
{
    unsigned int min = INFINITE;
    int index = -1;
    for (int i = 0; i < vexCounts;i++)
    {
        if (closedge[i].lowestcost < min && closedge[i].lowestcost !=0)
        {
            min = closedge[i].lowestcost;
            index = i;
        }
    }
    return index;
}
void MiniSpanTree_Prim(unsigned int adjMat[][vexCounts], VertexData s)
{
    for (int i = 0; i < vexCounts;i++)
    {
        closedge[i].lowestcost = INFINITE;
    }
    closedge[s].data = s;      //�Ӷ���s��ʼ
    closedge[s].lowestcost = 0;
    for (int i = 0; i < vexCounts;i++)  //��ʼ����������
    {
        if (i != s)
        {
            closedge[i].data = s;
            closedge[i].lowestcost = adjMat[s][i];
        }
    }
    for (int e = 1; e <= vexCounts -1; e++)  //n-1����ʱ�˳�
    {
        int k = Minmum(closedge);  //ѡ����С���۱�
        cout << vextex[closedge[k].data] << "--" << vextex[k] << endl;//���뵽��С������
        closedge[k].lowestcost = 0; //������Ϊ0
        for (int i = 0; i < vexCounts;i++)  //����v�ж�����С���۱���Ϣ
        {
            if ( adjMat[k][i] < closedge[i].lowestcost)
            {
                closedge[i].data = k;
                closedge[i].lowestcost = adjMat[k][i];
            }
        }
    }
}
void ReadArc(unsigned int  adjMat[][vexCounts],vector<Arc> &vertexArc) //����ͼ�ıߴ�����Ϣ
{
    Arc * temp = NULL;
    for (unsigned int i = 0; i < vexCounts;i++)
    {
        for (unsigned int j = 0; j < i; j++)
        {
            if (adjMat[i][j]!=INFINITE)
            {
                temp = new Arc;
                temp->u = i;
                temp->v = j;
                temp->cost = adjMat[i][j];
                vertexArc.push_back(*temp);
            }
        }
    }
}
bool compare(Arc  A, Arc  B)
{
    return A.cost < B.cost ? true : false;
}
bool FindTree(VertexData u, VertexData v,vector<vector<VertexData> > &Tree)
{
    unsigned int index_u = INFINITE;
    unsigned int index_v = INFINITE;
    for (unsigned int i = 0; i < Tree.size();i++)  //���u,v�ֱ������Ŀ���
    {
        if (find(Tree[i].begin(), Tree[i].end(), u) != Tree[i].end())
            index_u = i;
        if (find(Tree[i].begin(), Tree[i].end(), v) != Tree[i].end())
            index_v = i;
    }
 
    if (index_u != index_v)   //u,v����һ�����ϣ��ϲ�������
    {
        for (unsigned int i = 0; i < Tree[index_v].size();i++)
        {
            Tree[index_u].push_back(Tree[index_v][i]);
        }
        Tree[index_v].clear();
        return true;
    }
    return false;
}
void MiniSpanTree_Kruskal(unsigned int adjMat[][vexCounts])
{
    vector<Arc> vertexArc;
    ReadArc(adjMat, vertexArc);//��ȡ����Ϣ
    sort(vertexArc.begin(), vertexArc.end(), compare);//�߰���С��������
    vector<vector<VertexData> > Tree(vexCounts); //6�ö�����
    for (unsigned int i = 0; i < vexCounts; i++)
    {
        Tree[i].push_back(i);  //��ʼ��6�ö���������Ϣ
    }
    for (unsigned int i = 0; i < vertexArc.size(); i++)//���δ�С����ȡ��С���۱�
    {
        VertexData u = vertexArc[i].u;
        VertexData v = vertexArc[i].v;
        if (FindTree(u, v, Tree))//���˱ߵ����������Ƿ���һ������
        {
            cout << vextex[u] << "---" << vextex[v] << endl;//�Ѵ˱߼��뵽��С��������
        }   
    }
}
 
int main()
{
    unsigned int  adjMat[vexCounts][vexCounts] = { 0 };
    AdjMatrix(adjMat);   //�ڽӾ���
    cout << "Prim :" << endl;
    MiniSpanTree_Prim(adjMat,0); //Prim�㷨���Ӷ���0��ʼ.
    cout << "-------------" << endl << "Kruskal:" << endl;
    MiniSpanTree_Kruskal(adjMat);//Kruskal�㷨
    return 0;
} 
