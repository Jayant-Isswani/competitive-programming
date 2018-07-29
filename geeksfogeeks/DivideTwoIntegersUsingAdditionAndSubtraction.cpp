#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b;
	cin>>a>>b;
	if(b==0)
	cout<<"Cannot divide by zero";
	else
	{
	    if(a==0)
	    cout<<"0"<<endl;
	    else
	    {
	        int count=0;
	        while(abs(a)>=abs(b)*count)
	        {
	                count++;
	        }
	        if((a>0 && b<0)||(a<0 && b>0))
	        {
	           cout<<-(count-1)<<endl;
	        }
	        else
	        {
	            cout<<count-1<<endl;
	        }
	    }
	}
	return 0;
}
