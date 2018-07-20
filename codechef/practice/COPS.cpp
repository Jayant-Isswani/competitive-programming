#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--)
    {
    	int m,x,y;
    	cin>>m>>x>>y;
    	int arr[m];
    	for(int i=0;i<m;i++)
    	{
    	    cin>>arr[i];
    	}
    	bool issafe[101];
    	for(int i=1;i<=100;i++)
    	{
    	    issafe[i]=true;
    	}
    	for(int i=1;i<=100;i++)
    	{
    	    for(int j=0;j<m;j++)
    	    {
    	        if(i>=(arr[j]-x*y) && i<=(arr[j]+x*y))
    	        {
    	            issafe[i]=false;
    	        }
    	    }
    	}
    	int counter=0;
    	for(int i=1;i<=100;i++)
    	{
    	    if(issafe[i]==true)
    	    counter++;
    	}
    	cout<<counter<<endl;
    }
    return 0;
} 
