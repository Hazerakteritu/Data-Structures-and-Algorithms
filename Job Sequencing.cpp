//Job sequencing - takeuforward
//https://takeuforward.org/data-structure/job-sequencing-problem/

#include<bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id; // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

bool comparison(Job a, Job b)
{
    return (a.profit > b.profit);
}

//Function to find the maximum profit and the number of jobs done
pair<int,int>JobScheduling(Job arr[], int n)
{

    sort(arr, arr + n, comparison);
    int maxi = arr[0].dead;
    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, arr[i].dead);
    }

    int slot[maxi + 1];

    for (int i = 0; i <= maxi; i++)
        slot[i] = -1;

    int countJobs = 0, jobProfit = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = arr[i].id;
                countJobs++;
                jobProfit += arr[i].profit;
                break;
            }
        }
    }
    //print sequence of jobs
    for(int i=0; i<=maxi; i++)
    {
        if(slot[i]!=-1)
            cout<<slot[i]<<" ";
    }
    cout<<endl;

    return make_pair(countJobs, jobProfit);
}

int main()
{
    int n ;
    cin>>n;
    Job arr[n];
    for(int i=0; i<n; i++){
        int id,dd,prft;
        cin>>id>>dd>>prft;
        arr[i].id = id;
        arr[i].dead = dd;
        arr[i].profit = prft;
    }
   // Job arr[n] = {{1,4,20},{2,1,10},{3,2,40},{4,2,30}};


    pair < int, int > ans = JobScheduling(arr, n);
    //print number of job done and maxprofit
    cout << ans.first << " " << ans.second << endl;

    return 0;
}

//Time Complexity: O(N log N) + O(N*M).
//O(N log N ) for sorting the jobs in decreasing order of profit.
//O(N*M) since we are iterating through all N jobs and for every job we are checking
//from the last deadline, say M deadlines in the worst case.

//Space Complexity: O(M) for an array that keeps track on which day which job is performed
//if M is the maximum deadline available.

