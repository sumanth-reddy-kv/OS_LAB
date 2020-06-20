#include <bits/stdc++.h>

using namespace std;

struct page{
    int pg_no;
    int frame;
};
int main()
{
    int log_add, phy_add, pg_size,i,j;

    cout<<"\nEnter the size of logical address: ";
    cin>>log_add;

    cout<<"\nEnter the size of physical address: ";
    cin>>phy_add;

    cout<<"\nEnter the size of the page: ";
    cin>>pg_size;

    int no_of_frames= log_add/pg_size;
    int no_of_pages= phy_add/pg_size;

    struct page pagetable[no_of_pages];

    cout<<"\nEnter page table: \n";
    for(i=0;i<no_of_pages;i++)
    {
        pagetable[i].frame = -1;
    }
    for(i=0;i<no_of_pages;i++)
    {
        int new_frame;
        bool flag = false;
        pagetable[i].pg_no=i;

        cout<<"Enter frame for "<<i<<" page number(-1 if frame doesn't exist): ";
        cin>>new_frame;

        for(j=0;j<no_of_pages;j++)
        {
            if(pagetable[i].frame = new_frame && new_frame != -1)
            {
                flag = true;
                cout<<("Frame number already present\n");
            }
        }
        if(new_frame > no_of_frames)
        {
            flag = true;
            cout<<"Cannot exceed frame size"<<endl;
        }
        if(flag == false)
        {
            pagetable[i].frame = new_frame;
        }
    }
    int log_address;
    cout<<"Enter -1 to exit"<<endl;

    while(1)
    {
        cout<<"Enter the logical address: ";
        cin>>log_address;

        if(log_address == -1)
            return 0;

        int page_no = log_address/pg_size;
		int offset = log_address%pg_size;
		if(pagetable[page_no].frame == -1)
			cout<<"No such logical address exist"<<endl;
		else
			cout<<"Page no: "<<page_no<<"\nOffset: "<<offset<<"\nFrame no: "<<pagetable[page_no].frame<<"\nPhysical address: "<<pagetable[page_no].frame*pg_size + offset<<endl;
    }

}