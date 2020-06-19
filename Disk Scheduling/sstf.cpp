#include<bits/stdc++.h>

using namespace std;

void sstf(int n,int head,vector<int> arr,int seektime)
{
    int position,i;

    cout<<" ->"<<head;

    vector<int> is_visited(arr.size(),0);
    while(n)
    {
        int min=INT_MAX;
        for(i=0;i<arr.size();i++)
        {
            if( abs(head-arr[i])<min && is_visited[i]==0 )
            {
                min=abs(head-arr[i]);
                position = i;
            }
        }

        cout<<" ->"<<arr[position];
        seektime+=min;
        head=arr[position];
        is_visited[position]=1;
        n--;
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

    sstf(n,head,arr,seektime);

    return 0;
}