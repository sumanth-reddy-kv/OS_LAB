#include<bits/stdc++.h>

using namespace std;
int pointer=0,faults,hits;
void show(int framesize,int frames[])
{
    int j;
    for(j=0;j<framesize;j++)
    {
        if(frames[j]==-1)
            cout<<"|-";
        else
            cout<<"|"<<frames[j];
    }
    cout<<"|"<<endl;
}
void insertion(int val,int framesize,int frames[])
{
    int i,alloted=0;

    for(i=0;i<framesize;i++)
    {
        if(frames[i]==val)
        {
            hits++;
            alloted=1;
            cout<<" Hit for the reference "<<val<<"---> ";
            break;
        }
        else if(frames[i]==-1)
        {
            faults++;
            alloted=1;
            frames[i]=val;
            cout<<" Fault for the reference "<<val<<"---> ";
            break;
        }
    }
    if(alloted==0)
    {
        faults++;
        cout<<" Fault for the reference "<<val<<"---> ";
        frames[pointer%framesize]=val;
        pointer=(pointer+1)%framesize;
    }

    show(framesize,frames);

}
int main()
{
    int i, framesize, references;

    cout<<"\nEnter the frame size: ";
    cin>>framesize;

    int frames[framesize];

    for(i=0;i<framesize;i++)
        frames[i]=-1;

    show(framesize,frames);

    cout<<"\nEnter the no of refernces: ";
    cin>>references;

    vector<int> refer(references);

    cout<<"\nEnter the refernces: ";
    for(i=0;i<references;i++)
    {
        cin>>refer[i];
        insertion(refer[i],framesize,frames);
    }

    cout<<"\nNumber of Faults: "<<faults<<endl<<"Number of Hits: "<<hits<<endl;

    return 0;
}