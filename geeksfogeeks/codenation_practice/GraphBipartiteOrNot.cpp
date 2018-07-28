/* Link:https://www.geeksforgeeks.org/bipartite-graph/ */
#include <bits/stdc++.h>
using namespace std;

bool isBipartite(vector<int>* graph,bool* visited,int src,int V)
{
    int color[V];
    for(int i=0;i<V;i++)
    color[i]=-1;
    
    color[src]=1;
    queue<int> q;
    q.push(src);
    int flag=0;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(vector<int>::iterator it=graph[front].begin();it!=graph[front].end();++it)
        {
            if(color[*it]==color[front])
            {
                return false;
            }
            if(color[*it]==-1)
            color[*it]=1-color[front];
        }
    }
    return true;
}

int main() {
    int V,E;
    cin>>V>>E;
	vector<int> graph[V];
	int x,y;
	for(int i=0;i<E;i++)
	{
	    cin>>x>>y;
	    graph[x].push_back(y);
	    graph[y].push_back(x);
	}
	bool visited[V];
	for(int i=0;i<V;i++)
	visited[i]=false;
	bool x1=isBipartite(graph,visited,0,V);
	cout<<x1<<endl;
	return 0;
}
