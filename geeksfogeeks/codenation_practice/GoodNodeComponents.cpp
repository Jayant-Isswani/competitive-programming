/* Link:https://www.careercup.com/question?id=5840928073842688 */
#include <bits/stdc++.h>
using namespace std;

int findStepsAllGoodNodes(int* list,int n)
{
    if(n<2)
    return 0;
    int component[n];
    for(int i=0;i<n;i++)
    component[i]=0;
    int currComp=1;
    component[0]=currComp;
    int result=0;
    for(int i=1;i<n;i++)
    {
        if(component[i]>0)
        continue;
        currComp++;
        int j=i;
        while(component[j]==0)
        {
            component[j]=currComp;
            j=list[j];
        }
        if(component[j]==currComp)
        result++;
    }
    return result;
}

int main() {
	int n;
	cin>>n;
	int list[n];
	for(int i=0;i<n;i++)
	{
	    cin>>list[i];
	    list[i]--;
	}
	int res=findStepsAllGoodNodes(list,n);
	cout<<res<<endl;
	return 0;
}
