/* Link:https://www.geeksforgeeks.org/word-ladder-length-of-shortest-chain-to-reach-a-target-word/ */
#include <bits/stdc++.h>
using namespace std;

struct QItem
{
    string word;
    int len;
};

bool differenceOneOrNot(string a,string b)
{
    int count=0;
    int x=min(a.length(),b.length());
    for(int i=0;i<x;i++)
    {
        if(a[i]!=b[i])
        count++;
        if(count>1)
        return false;
    }
    if(count==1)
    return true;
    else
    return false;
}

int chainLength(set<string> dict,string start,string end)
{
    queue<QItem> q;
    QItem item1={start,1};
    // item1.word=start;
    // item1.len=1;
    q.push(item1);
    while(!q.empty())
    {
        //cout<<item1.word<<" "<<item1.len<<endl;
        QItem item=q.front();
        q.pop();
        for(set<string>::iterator it=dict.begin();it!=dict.end();++it)
        {
            string temp=*it;
            if(differenceOneOrNot(temp,item.word)==true)
            {
                //cout<<temp<<" ";
                item1.word=temp;
                item1.len=item.len+1;
                q.push(item1);
                dict.erase(temp);
                if(temp==end)
                return item1.len;
            }
        }
    }
    return 0;
}

int main() {
    int n;
    cin>>n;
	set<string> dict;
	string element;
	for(int i=0;i<n;i++)
	{
	    cin>>element;
	    dict.insert(element);
	}
	string start,end;
	cin>>start>>end;
	//cout<<start<<" "<<end<<endl;
	int len=chainLength(dict,start,end);
	cout<<len<<endl;
	return 0;
}
