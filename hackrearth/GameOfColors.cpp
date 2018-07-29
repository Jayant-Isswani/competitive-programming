/* Link:https://www.hackerearth.com/practice/algorithms/dynamic-programming/introduction-to-dynamic-programming-1/practice-problems/algorithm/game-of-colors/ */ 
#include <iostream>
#include <map>
#include <set>
using namespace std;

int calculate(int time,int freq[][100],int i,int j,char predict)
{
    int x=time%(freq[i][j]*3);
    char ch;
    if(x<freq[i][j])
    ch='R';
    else if(x<2*freq[i][j])
    ch='G';
    else
    ch='B';
    if(ch==predict)
    return 1;
    else
    return 0;
}

void getresult(int n,int time,int freq[][100],map<pair<char,int>,int> color1[][100])
{
    color1[0][0][make_pair('G',time)]=calculate(time,freq,0,0,'G');
    color1[0][0][make_pair('B',time)]=calculate(time,freq,0,0,'B');
    color1[0][0][make_pair('R',time)]=calculate(time,freq,0,0,'R');
    for(int i=1;i<n;i++)
    {
        color1[i][0][make_pair('G',time)]=color1[i-1][0][make_pair('G',time)]+calculate(time,freq,i,0,'G');
        color1[0][i][make_pair('G',time)]=color1[0][i-1][make_pair('G',time)]+calculate(time,freq,0,i,'G');
        color1[i][0][make_pair('B',time)]=color1[i-1][0][make_pair('B',time)]+calculate(time,freq,i,0,'B');
        color1[0][i][make_pair('B',time)]=color1[0][i-1][make_pair('B',time)]+calculate(time,freq,0,i,'B');
        color1[i][0][make_pair('R',time)]=color1[i-1][0][make_pair('R',time)]+calculate(time,freq,i,0,'R');
        color1[0][i][make_pair('R',time)]=color1[0][i-1][make_pair('R',time)]+calculate(time,freq,0,i,'R');
    }
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<n;j++)
        {
            color1[i][j][make_pair('G',time)]=color1[i-1][j][make_pair('G',time)]+color1[i][j-1][make_pair('G',time)]-
                                    color1[i-1][j-1][make_pair('G',time)]+calculate(time,freq,i,j,'G');
            color1[i][j][make_pair('B',time)]=color1[i-1][j][make_pair('B',time)]+color1[i][j-1][make_pair('B',time)]-
                                    color1[i-1][j-1][make_pair('B',time)]+calculate(time,freq,i,j,'B');
            color1[i][j][make_pair('R',time)]=color1[i-1][j][make_pair('R',time)]+color1[i][j-1][make_pair('R',time)]-
                                    color1[i-1][j-1][make_pair('R',time)]+calculate(time,freq,i,j,'R');
        }
    }
}

int main() {
	// your code goes here
	int n,q;
	cin>>n>>q;
	int freq[n][100];
	for(int i=0;i<n;i++)
	{
	    for(int j=0;j<n;j++)
	    {
	        cin>>freq[i][j];
	    }
	}
	set<int> time;
	int time2[q],x1[q],x2[q],y1[q],y2[q];
	char color[q];
	for(int i=0;i<q;i++)
	{
	    cin>>time2[i]>>x1[i]>>y1[i]>>x2[i]>>y2[i]>>color[i];
	    time.insert(time2[i]);
	}
    map<pair<char,int>,int> color1[n][100];
	for(set<int>::iterator it=time.begin();it!=time.end();++it)
	{
	    getresult(n,*it,freq,color1);
	}
	for(int i=0;i<q;i++)
	{
	    //cout<<color1[x2[i]-1][y2[i]-1][make_pair(color[i],time2[i])]<<" "<<color1[x2[i]-1][y1[i]-1][make_pair(color[i],time2[i])]<<" "
	    //<<color1[x1[i]-1][y2[i]-1][make_pair(color[i],time2[i])]<<" "<<color1[x1[i]-1][y1[i]-1][make_pair(color[i],time2[i])]<<endl;
	    int final_result=color1[x2[i]-1][y2[i]-1][make_pair(color[i],time2[i])]-(y1[i]>=2?(color1[x2[i]-1][y1[i]-2][make_pair(color[i],time2[i])]):0)
	                     -(x1[i]>=2?(color1[x1[i]-2][y2[i]-1][make_pair(color[i],time2[i])]):0)+((x1[i]>=2&&y1[i]>=2)?(color1[x1[i]-2][y1[i]-2][make_pair(color[i],time2[i])]):0);
	    cout<<final_result<<endl;
	}
	return 0;
}
