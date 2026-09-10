#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

struct Process
{
    int pid;
    int arrivalTime;
    int burstTime;
    int burstTimeRemaining;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    bool isComplete;
    bool inQueue;
};

// Global variables
Process processes[MAX];
int n;
int quantum;
queue<int> readyQueue;
int currentTime = 0;

void checkForNewArrivals()
{
    for (int i = 0; i < n; i++)
    {
        if (processes[i].arrivalTime <= currentTime && !processes[i].inQueue && !processes[i].isComplete)
        {
            processes[i].inQueue = true;
            readyQueue.push(i);
        }
    }
}

void updateQueue()
{
    int i = readyQueue.front();
    readyQueue.pop();

    if (processes[i].burstTimeRemaining <= quantum)
    {
        currentTime += processes[i].burstTimeRemaining;
        processes[i].completionTime = currentTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        if (processes[i].waitingTime < 0) processes[i].waitingTime = 0;
        processes[i].burstTimeRemaining = 0;
        processes[i].isComplete = true;

        checkForNewArrivals();
    }
    else
    {
        processes[i].burstTimeRemaining -= quantum;
        currentTime += quantum;
        checkForNewArrivals();
        readyQueue.push(i);
    }
}

void output()
{
    double avgWaitingTime = 0, avgTurnaroundTime = 0;

    sort(processes, processes + n, [](const Process &a, const Process &b)
    {
        return a.pid < b.pid;
    });

    cout << "\nPID\tArrival\tBurst\tWaiting\tTurnaround\n";
    for (int i = 0; i < n; i++)
    {
        cout << processes[i].pid << "\t" << processes[i].arrivalTime << "\t"
             << processes[i].burstTime << "\t" << processes[i].waitingTime << "\t"
             << processes[i].turnaroundTime << "\n";
        avgWaitingTime += processes[i].waitingTime;
        avgTurnaroundTime += processes[i].turnaroundTime;
    }

    cout << "Average Waiting Time: " << avgWaitingTime / n << endl;
    cout << "Average Turnaround Time: " << avgTurnaroundTime / n << endl;
}

void roundRobin()
{
    readyQueue.push(0);
    processes[0].inQueue = true;

    while (!readyQueue.empty())
    {
        updateQueue();
    }
}

int main()
{
    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter time quantum: ";
    cin >> quantum;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter arrival and burst time of process " << i + 1 << ": ";
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].burstTimeRemaining = processes[i].burstTime;
        processes[i].pid = i + 1;
        processes[i].isComplete = false;
        processes[i].inQueue = false;
    }

    sort(processes, processes + n, [](const Process &a, const Process &b)
    {
        return a.arrivalTime < b.arrivalTime;
    });

    roundRobin();
    output();

    return 0;
}
