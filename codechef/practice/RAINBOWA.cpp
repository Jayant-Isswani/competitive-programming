#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    while(t--)
    {
    	int n,k;
    	cin>>n;
    	int arr[n];
    	int counter=1;
    	vector <pair<int,int> > freq;
    	for(int i=0;i<n;i++)
    	{
    	    cin>>arr[i];
    	}
    	int i=1,element=arr[0];
    	while(i<n)
    	{
    	    if(arr[i]==arr[i-1])
    	    {
    	        i++;
    	        counter++;
    	    }
    	    else
    	    {
    	        freq.push_back(make_pair(element,counter));
    	        element=arr[i];
    	        counter=1;
    	        i++;
    	    }
    	}
    	if(counter>0)
    	{
    	    freq.push_back(make_pair(element,counter));
    	}
    	int flag=0;
    	if((int)freq.size()!=13)
    	{
    	    flag=1;
    	}
    	for(int i=0;i<6;i++)
    	{
    	    if(freq[i].first != i+1)
    	    {
    	        flag=1;
    	    }
    	}
    	for(int i=7;i<13;i++)
    	{
    	    if(freq[i].first != 13-i || freq[i].second != freq[12-i].second)
    	    {
    	        flag=1;
    	    }
    	}
    	if(flag==0)
    	cout<<"yes"<<endl;
    	else
    	cout<<"no"<<endl;
    }
    return 0;
} 
