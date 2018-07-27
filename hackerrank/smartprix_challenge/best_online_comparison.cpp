#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
	// your code goes here
	int n,m;
	cin>>n;
	string replacement[n];
	for(int i=0;i<n;i++)
	{
	    cin>>replacement[i];
	}
	cin>>m;
	string argument[m];
	for(int i=0;i<m;i++)
	{
	    cin>>argument[i];
	}
	int count=0;
	for(int i=0;i<m;i++)
	{
	    if(argument[i].at(0)=='{')
	    {
	        if(argument[i].length()==2)
	        {
	            //cout<<i<<" ";
	            if(count<n)
	            {
	                argument[i]=replacement[count];
	                count++;
	            }
	    }
	        else
	        {
	            string str=argument[i].substr(1,argument[i].length()-2);
	            //cout<<str;
	            stringstream abcd(str);
	            int x=0;
	            abcd>>x;
	            if(x==0&&str!="0")
	            argument[i]=str;
	            //cout<<x;
	            else if(x>=n)
	            argument[i]=to_string(x);
	            else
	            argument[i]=replacement[x];
	        }
	    }
	}
	//cout<<m;
	for(int i=0;i<m;i++)
	{
	    //cout<<"rfgtrh";
	    cout<<argument[i]<<" ";
	}
	return 0;
}
