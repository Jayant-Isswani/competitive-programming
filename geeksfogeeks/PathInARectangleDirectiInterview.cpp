#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int calculatePath(bool marked[1000][1000],int m,int n,pair<int,int> start,pair<int,int> end,int level[1000][1000])
{
    queue< pair <int,int> > q;
    q.push(make_pair(start.first,start.second));
    int noOfPath=0;
    level[start.first][start.second]=0;
    if(marked[end.first][end.second]==1)
    return -1;
    //cout<<start.first<<" "<<start.second<<endl;
    while(!q.empty())
    {
        pair<int,int> front = q.front();
        q.pop();
        if(front==end)
        {
            //cout<<"Here";
            break;
        }
        if(front.first+1<m && marked[front.first+1][front.second]==0)
        {
            level[front.first+1][front.second]=level[front.first][front.second]+1;
            q.push(make_pair(front.first+1,front.second));
        }
        if(front.first-1>=0 && marked[front.first-1][front.second]==0)
        {
            level[front.first-1][front.second]=level[front.first][front.second]+1;
            q.push(make_pair(front.first-1,front.second));
        }
        if(front.second+1<n && marked[front.first][front.second+1]==0)
        {
            level[front.first][front.second+1]=level[front.first][front.second]+1;
            q.push(make_pair(front.first,front.second+1));
        }
        if(front.second-1>=0 && marked[front.first][front.second-1]==0)
        {
            level[front.first][front.second-1]=level[front.first][front.second]+1;
            q.push(make_pair(front.first,front.second-1));
        }
    }
    return level[end.first][end.second];
    // return 0;
}

int main() {
	int m,n,k,r;
	cin>>m>>n>>k>>r;
	int X[k],Y[k];
	bool marked[1000][1000];
	for(int i=0;i<m;i++)
	    for(int j=0;j<n;j++)
	        marked[i][j]=0;
	for(int i=0;i<k;i++){
	    cin>>X[i];
	}
	for(int i=0;i<k;i++){
	    cin>>Y[i];
	}
	for(int i=0;i<k;i++)
	{
	    for(int j=0;j<=r;j++)
	    {
	        if(X[i]-j>=0)
	        {
	            marked[X[i]-j-1][Y[i]-1]=1;
	        }
	        if(X[i]+j<=m)
	        {
	            marked[X[i]+j-1][Y[i]-1]=1;
	        }
	        if(Y[i]-j>=0)
	        {
	            marked[X[i]-1][Y[i]-j-1]=1;
	        }
	        if(Y[i]+j<=n)
	        {
	            marked[X[i]-1][Y[i]+j-1]=1;
	        }
	    }
	}
	
	/*for(int i=0;i<m;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cout<<marked[i][j]<<" ";
	    }
	    cout<<endl;
	}*/
	int level[1000][1000];
	pair<int,int> start=make_pair(0,0);
	pair<int,int> end = make_pair(m-1,n-1);
	int countPath=0;
	countPath=calculatePath(marked,m,n,start,end,level);
	cout<<countPath<<endl;
	return 0;
}
