#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter the number of Processes : ";
    cin >> n;
    int bt[n], wt[n], tat[n], avwt = 0, avtat = 0;
    cout << "Enter Process Burst Time for each process : ";
    for (int i = 0; i < n; i++)
    {
        cin >> bt[i];
    }
    wt[0] = 0;
    for (int i = 1; i < n; i++)
    {
        wt[i] = 0;
        for (int j = 0; j < i; j++)
        {
            wt[i] += bt[j];
        }
    }

    cout << "Process\tBurst Time\tWaiting Time\tTurnaround Time" << endl;
    for (int i = 0; i < n; i++)
    {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        cout << i + 1 << "\t" << bt[i] << "\t\t" << wt[i] << "\t\t" << tat[i] << endl;
    }
    avwt /= n;
    avtat /= n;
    cout << "Average Waiting Time\t" << avwt << endl;
    cout << "Average Turnaround Time\t" << avtat << endl;

    return 0;
}


