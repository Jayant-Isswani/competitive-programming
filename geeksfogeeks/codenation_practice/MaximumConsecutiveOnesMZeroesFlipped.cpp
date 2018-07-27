/*  Link:https://www.geeksforgeeks.org/find-zeroes-to-be-flipped-so-that-number-of-consecutive-1s-is-maximized/  */
#include <bits/stdc++.h>
using namespace std;

int solve(int* arr,int n,int m)
{
    vector<pair<int,int>> add;
	vector<int> indices;
	int i=0;
	while(i<n)
	{
	    int count1,count2;
	    if(arr[i]==0)
	    {
	        indices.push_back(i);
	        int j=i-1;
	        while(j>=0 && arr[j]==1)
	        j--;
	        count1=i-j;
	        j=i+1;
	        while(j<n && arr[j]==1)
	        j++;
	        count2=j-i;
	        i=j;
	        add.push_back(make_pair(count1-1,count2-1));
	   }
	    else
	    i++;
	}
	int res,sum;
	int size=indices.size();
	//cout<<size<<endl;
	for(int i=0;i<size;i++)
	{
	    res=0;
	    for(int j=i;j<min(i+m,size);j++)
	    {
	        if(j!=min(i+m,size)-1)
	        res=res+add[j].first+1;
	        else
	        res=res+add[j].first+add[j].second+1;
	        //cout<<res<<" and ";
	    }
	    sum=max(sum,res);
	}
	return sum;
}

int solve1(int* arr,int n,int m)
{
    int wL=0,wR=0;
    int bestWindow=0,zeroCount=0;
    while(wR<n)
    {
        if(zeroCount<=m)
        {
            if(arr[wR]==0)
            zeroCount++;
            wR++;
        }
        
        if(zeroCount>m)
        {
            if(arr[wL]==0)
            zeroCount--;
            wL++;
        }
        if(wR-wL>bestWindow)
        {
            bestWindow=wR-wL;
        }
    }
    return bestWindow;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int m;
	cin>>m;
	int sum=solve(arr,n,m);
	cout<<sum<<endl;
	int sum1=solve1(arr,n,m);
	cout<<sum1<<endl;
	return 0;
}
