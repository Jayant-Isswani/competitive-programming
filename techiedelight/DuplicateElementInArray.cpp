/* Link:http://www.techiedelight.com/find-duplicate-element-limited-range-array/ */
#include <bits/stdc++.h>
using namespace std;

int findDuplicateElement(int* arr,int n)
{
    set<int> set;
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(set.find(arr[i])!=set.end())
        count++;
        set.insert(arr[i]);
    }
    return count;
}

int main() {
	int n;
	cin>>n;
	int arr[n];
	for(int i=0;i<n;i++)
	cin>>arr[i];
	int x=findDuplicateElement(arr,n);
	cout<<x<<" ";
	return 0;
}
