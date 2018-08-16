/*Link:https://www.codechef.com/problems/PROBLEMS
#include <bits/stdc++.h>
using namespace std;
 
int merge(vector<int> arr,int low,int mid,int high)
{
    int inv_count=0;
    int i,j,k;
    i=low,j=mid;
    vector<int> temp;
    temp.clear();
    while(i<=(mid-1) && j<=high)
    {
        if(arr[i]>arr[j])
        {
            inv_count+=(mid-i);
            temp.push_back(arr[j]);
            j++;
        }
        else
        {
            temp.push_back(arr[i]);
            i++;
        }
    }
    while(i<=mid-1)
    {
        temp.push_back(arr[i]);
        i++;
    }
    while(j<=high)
    {
        temp.push_back(arr[j]);
        j++;
    }
    k=0;
    for(int i=low;i<=high;i++)
    {
        arr[i]=temp[k++];
    }
    return inv_count;
}
 
 
int inversionCount(vector<int> arr,int low,int high)
{
    if(low>=high)
    return 0;
    int mid=(low+high)/2;
    int inv_count=inversionCount(arr,low,mid);
    inv_count+=inversionCount(arr,mid+1,high);
    inv_count+=merge(arr,low,mid+1,high);
    return inv_count;
}
 
int inversionCount1(vector<int> arr)
{
    int count=0;
    int size=arr.size();
    for(int i=0;i<size-1;i++)
    {
        if(arr[i]>arr[i+1])
        count++;
    }
    return count;
}
 
int main() {
    int p,s;
    cin>>p>>s;
    vector<pair<int,int>> subTaskAndAttempts[p];
    vector<int> subTask,attempts;
    int element1,element2;
    subTask.clear();
    attempts.clear();
    for(int i=1;i<=2*p;i++)
    {
        if(i%2==1)
        {
            subTask.clear();
            for(int j=0;j<s;j++)
            {
                cin>>element1;
                subTask.push_back(element1);
            }
        }
        else
        {
            attempts.clear();
            for(int j=0;j<s;j++)
            {
                cin>>element1;
                attempts.push_back(element1);
            }
            for(int j=0;j<s;j++)
            {
                subTaskAndAttempts[i/2-1].push_back(make_pair(subTask[j],attempts[j]));
            }
            subTask.clear();
            attempts.clear();
        }
    }
    for(int i=0;i<p;i++)
    {
        sort(subTaskAndAttempts[i].begin(),subTaskAndAttempts[i].end());
    }
    vector<pair<int,int>> result;
    result.clear();
    attempts.clear();
    for(int i=0;i<p;i++)
    {
    	attempts.clear();
        for(vector<pair<int,int>>::iterator it=subTaskAndAttempts[i].begin();it!=subTaskAndAttempts[i].end();++it)
        {
            attempts.push_back((*it).second);
        }
        result.push_back(make_pair(inversionCount1(attempts),i+1));
        attempts.clear();
    }
    
    sort(result.begin(),result.end());
    for(int i=0;i<p;i++)
    cout<<result[i].second<<endl;
    return 0;
}   
