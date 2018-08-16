/*Link:https://www.codechef.com/LTIME62B/problems/FRCPRT */
/*Editorial:https://discuss.codechef.com/questions/132603/frcprt-editorial
#include <bits/stdc++.h>
using namespace std;
 
char arr[100][100];
int countOne[200];
int n,m;
 
void countOnes()
{
    for(int i=0;i<200;i++)
    countOne[i]=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(arr[i][j]=='1')
            {
                countOne[i]++;
                countOne[n+j]++;
            }
        }
    }
}
 
void printArray()
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<arr[i][j];
        }
        cout<<endl;
    }
}
 
void move(char dir)
{
    switch(dir)
    {
        case 'L':
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<countOne[i];j++)
            arr[i][j]='1';
            for(int j=countOne[i];j<m;j++)
            arr[i][j]='0';
        }
        //printArray();
        countOnes();
        break;
        case 'R':
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m-countOne[i];j++)
            arr[i][j]='0';
            for(int j=m-countOne[i];j<m;j++)
            arr[i][j]='1';
        }
        //printArray();
        countOnes();
        break;
        case 'U':
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<countOne[n+i];j++)
            arr[j][i]='1';
            for(int j=countOne[n+i];j<n;j++)
            arr[j][i]='0';
        }
        //printArray();
        countOnes();
        break;
        case 'D':
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n-countOne[n+i];j++)
            arr[j][i]='0';
            for(int j=n-countOne[n+i];j<n;j++)
            arr[j][i]='1';
        }
        //printArray();
        countOnes();
        break;
    }
}
int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    cin>>n>>m;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    countOnes();
	    string force;
	    cin>>force;
	    int len=force.length();
	    move(force[0]);
	    int left=0,right=0,up=0,down=0;
	    list<char> seq;
	    for(int i=1;i<len;i++)
	    {
	        if(force[i]=='L')
	        {
	            seq.push_back('L');
	            seq.remove('R');
	        }
	        else if(force[i]=='R')
	        {
	            seq.push_back('R');
	            seq.remove('L');
	        }
	        else if(force[i]=='U')
	        {
	            seq.push_back('U');
	            seq.remove('D');
	        }
	        else
	        {
	            seq.push_back('D');
	            seq.remove('U');
	        }
	    }
	    for(list<char>::iterator it=seq.begin();it!=seq.end();++it)
	    {
	        move(*it);
	    }
	   printArray();
	}
	return 0;
} 
