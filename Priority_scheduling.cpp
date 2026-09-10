//Priority_Scheduling non preemptive

#include<bits/stdc++.h>
using namespace std;

int pid[20], BT[20], WT[20], TAT[20], Priority[20], n;

//WT = ager process er TAT( WT + BT) for FCFS
void calculate_waiting_time()
{
    WT[0]=0;
    for(int i=1; i<n; i++)
    {
        WT[i] = WT[i-1] + BT[i-1];
    }
}

//TurnArroundTime = waiting_time + BT
void calculate_TAT_time()
{
    for(int i=0; i<n; i++)
    {
        TAT[i] = WT[i] + BT[i];
    }
}

void average_WT()
{
    int sum = 0;
    for(int i=0; i<n; i++)
        sum= sum + WT[i];

    printf("\n\nAverage Waiting Time: %lf\n", (double)sum/n);
}

void average_TAT()
{
    int sum = 0;
    for(int i=0; i<n; i++)
        sum+= TAT[i];

    printf("\nAverage Turnarround Time: %lf\n", (double)sum/n);

}

int main()
{
    printf("Enter the number of process: ");
    scanf("%d",&n);

    for(int i=0; i<n; i++)
    {
        pid[i]=i;
        printf("Enter the burst time and priority of process %d: ", i);
        //scanf("%d %d", &BT[i]);
        cin>>BT[i]>>Priority[i];
    }

    //.... sorting by Priority.......
    for(int i=0; i<n; i++)
    {
        for(int k=i+1; k<n; k++)
        {
            if(Priority[i]>Priority[k])
            {
                //int temp = BT[i];
                //BT[i] = BT[k];
                //BT[k] = temp;
                swap(BT[i], BT[k]);
                swap(pid[i], pid[k]);
                swap(Priority[i], Priority[k]);

               // temp = pid[i];
                //pid[i] = pid[k];
                //pid[k] = temp;
            }
        }
    }

    calculate_waiting_time();
    calculate_TAT_time();

    printf("\n\t Process \tBurst Time \tWaiting Time \tTurnaround Time\n");

    for(int i=0; i<n; i++)
    {
        printf("\n\t p%d \t\t %d \t\t %d \t\t %d", pid[i], BT[i], WT[i], TAT[i]);
    }

    average_WT();
    average_TAT();

}

/*
Enter the number of process: 5
Enter the burst time and priority of process 0: 10 3
Enter the burst time and priority of process 1: 1 1
Enter the burst time and priority of process 2: 2 4
Enter the burst time and priority of process 3: 1 5
Enter the burst time and priority of process 4: 5 2

         Process        Burst Time      Waiting Time     Turnaround Time

         p1              1               0       1
         p4              5               1       6
         p0              10              6       16
         p2              2               16      18
         p3              1               18      19

Average Waiting Time: 8.200000

Average Turnarround Time: 12.000000

Process returned 0 (0x0)   execution time : 18.178 s
Press any key to continue.
*/
