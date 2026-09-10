//Round Robin
//All arrive in same time
#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n, qt, temp, sq=0, BT[10], WT[10], TAT[10], rem_BT[10];
    cout<<"Enter number of Process: ";
    cin>>n;

    for(int i=0; i<n; i++)
    {
        cout<<"Enter Burst Time of p"<<i<<": ";
        cin>>BT[i];
        rem_BT[i]=BT[i];
    }
    cout<<"Enter Quantum time: ";
    cin>>qt;

    int i=0, cnt = 0;
    while(1)
    {
        for(i = 0, cnt = 0; i<n; i++)
        {
            int temp = qt;
            if(rem_BT[i]==0)
            {
                cnt++;
                continue;
            }

            if(rem_BT[i]>qt)
            {
                rem_BT[i] = rem_BT[i]-qt;
            }
            else if(rem_BT[i]>=0)
            {
                temp = rem_BT[i];
                rem_BT[i] = 0;
            }
            sq = sq+temp;
            TAT[i] = sq;

        }

        if(n==cnt) break;
    }
    float AWT = 0, ATAT = 0;

    printf("\nProcess \tBurst time \tTurnAround time \tWaiting time\n");
    for(int i=0; i<n; i++)
    {
        WT[i] = TAT[i] - BT[i];
        AWT += WT[i];
        ATAT += TAT[i];

        cout<<"\n\tp"<<i+1<<"\t\t"<<BT[i]<<"\t\t"<<TAT[i]<<"\t\t"<<WT[i]<<endl;
    }

    AWT/=n;
    ATAT/=n;
    cout<<"Average waiting time: "<<AWT<<endl;
    cout<<"Average Turnaround time: "<<ATAT<<endl;
}


/*
Enter number of Process: 4
Enter Burst Time of p0: 5
Enter Burst Time of p1: 3
Enter Burst Time of p2: 1
Enter Burst Time of p3: 4
Enter Quantum time: 2

Process         Burst time      TurnAround time     Waiting time

    p1              5               13          8

    p2              3               10          7

    p3              1               5           4

    p4              4               12          8
Average waiting time: 6.75
Average Turnaround time: 10
*/
