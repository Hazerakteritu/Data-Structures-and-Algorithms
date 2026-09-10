//shortest Job First

#include<stdio.h>

int pid[20], BT[20], WT[20], TAT[20], n;

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
        printf("Enter the burst time of process %d: ", i);
        scanf("%d", &BT[i]);
    }

    //.... sorting.......
    for(int i=0; i<n; i++)
    {
        for(int k=i+1; k<n; k++)
        {
            if(BT[i]>BT[k])
            {
                int temp = BT[i];
                BT[i] = BT[k];
                BT[k] = temp;

                temp = pid[i];
                pid[i] = pid[k];
                pid[k] = temp;
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

Enter the number of process: 4
Enter the burst time of process 0: 6
Enter the burst time of process 1: 8
Enter the burst time of process 2: 7
Enter the burst time of process 3: 3

         Process        Burst Time      Waiting Time Turnaround Time

         p3              3               0           3
         p0              6               3           9
         p2              7               9           16
         p1              8               16          24

Average Waiting Time: 7.000000

Average Turnarround Time: 13.000000

Process returned 0 (0x0)   execution time : 22.186 s
Press any key to continue.

*/
