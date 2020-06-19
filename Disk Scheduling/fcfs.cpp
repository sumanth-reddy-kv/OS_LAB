#include<bits/stdc++.h>

using namespace std;

void fcfs(int head,vector<int> arr,int seektime)
{
    cout<<" ->"<<head;

    for(int i=0;i<arr.size();i++)
    {
        cout<<" ->"<<arr[i];
        seektime+=abs(head-arr[i]);
        head=arr[i];
    }

    cout<<"\n Seek Time: "<<seektime<<endl;
}
int main()
{
    int i,n,head=0,seektime=0;

    cout<<"\nEnter the size of requests array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"\nEnter the indexes of tracks: ";

    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }

    cout<<"\nEnter the position of head: ";
    cin>>head;

    fcfs(head,arr,seektime);

    return 0;
}