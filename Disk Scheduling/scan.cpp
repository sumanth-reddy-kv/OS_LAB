#include<bits/stdc++.h>

using namespace std;

void scan(int head,int prevhead, vector<int> arr,int seektime,int disksize)
{
    cout<<" ->"<<head;

    int move,i,j,flag;
    if(head-prevhead<0)
        move=0;
    else
        move=1; //if head-prev head = 0, we assume that it moves forward    
    
    sort(arr.begin(),arr.end());

    if(move==1)
    {
        for(i=0;i<arr.size();i++)
        {
            if(arr[i]>=head)
            {
                flag=i;
                break;
            }
        }
        j=flag;
        while(j<arr.size())
        {
            cout<<" ->"<<arr[j];
            seektime+=abs(head-arr[j]);
            head=arr[j];
            j++;
        }
        
        j=flag-1;
        seektime+=(disksize-1 - head);
        head=disksize-1;
//      cout<<" ->"<<head;    //incase we want to print the ends

        while(j>-1)
        {
            cout<<" ->"<<arr[j];
            seektime+=abs(head-arr[j]);
            head=arr[j];
            j--;
        }
    }
    else
    {
        for(i=arr.size()-1;i>=0;i--)
        {
            if(arr[i]<=head)
            {
                flag=i;
                break;
            }
        }
        j=flag;
        while(j>-1)
        {
            cout<<" ->"<<arr[j];
            seektime+=abs(head-arr[j]);
            head=arr[j];
            j--;
        }

        j=flag+1;
        seektime+=head;
        head=0;
//      cout<<" ->"<<head;    //incase we want to print the ends
        while(j<arr.size())
        {
            cout<<" ->"<<arr[j];
            seektime+=abs(head-arr[j]);
            head=arr[j];
            j++;
        }
    }

    cout<<"\n Seek Time: "<<seektime<<endl;
}
int main()
{
    int i,n,head,seektime=0,prevhead,disksize;

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

    cout<<"\nEnter the previous position of head (determines the direction): ";
    cin>>prevhead;

    cout<<"\nEnter disk size: ";
    cin>>disksize;
    scan(head,prevhead,arr,seektime,disksize);

    return 0;
}