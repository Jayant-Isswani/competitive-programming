void bfs(vector<int> *graph,bool *visited,int start)
{
    queue<int> q;
    q.push(start);
    visited[start]=true;
    while(!q.empty())
    {
        int front=q.front();
        q.pop();
        for(vector<int>::iterator i=graph[front].begin();i!=graph[front].end();++i)
        {
            if(visited[*i]==false)
            {
                visited[*i]=true;
                q.push(*i);
            }
        }
    }    
}
