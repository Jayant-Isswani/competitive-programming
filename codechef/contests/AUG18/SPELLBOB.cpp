/*Link: https://www.codechef.com/problems/SPELLBOB/ */
#include <bits/stdc++.h>
using namespace std;
 
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string first;
	    string second;
	    cin>>first;
	    cin>>second;
	    int flag=0;
	    string possible_values[]={"bob","obb","bbo"};
	    for(int i=0;i<3;i++)
	    {
	        string str=possible_values[i];
	        int j;
	        for(j=0;j<3;j++)
	        {
	            if(!(first[j]==str[j]||second[j]==str[j]))
	            break;
	        }
	        if(j==3)
	        flag=1;
	    }
	    if(flag==1)
	    cout<<"yes"<<endl;
	    else
	    cout<<"no"<<endl;
	}
	return 0;
} 
