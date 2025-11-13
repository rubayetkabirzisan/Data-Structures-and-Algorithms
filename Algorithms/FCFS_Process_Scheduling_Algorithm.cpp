#include<bits/stdc++.h>
using namespace std;
struct Process {
    int id;
    int burst_time;
    int arrival_time;
};
void fcfs(vector<Process> &processes) {
    int n = processes.size();
    vector<int> wait_time(n);
    vector<int> turn_around_time(n);
    int total_wait_time = 0;
    int total_turn_around_time = 0;
    wait_time[0] = 0;
    for (int i = 1; i < n; i++) {
        wait_time[i] = processes[i-1].burst_time + wait_time[i-1];
    }
    for (int i = 0; i < n; i++) {
        turn_around_time[i] = processes[i].burst_time + wait_time[i];
    }
    for (int i = 0; i < n; i++) {
        total_wait_time += wait_time[i];
        total_turn_around_time += turn_around_time[i];
        cout << "Process " << processes[i].id
             << " -> Burst Time: " << processes[i].burst_time
             << ", Waiting Time: " << wait_time[i]
             << ", Turn Around Time: " << turn_around_time[i]
             << endl;
    }
    cout << "Average Waiting Time: " << (float)total_wait_time / n << endl;
    cout << "Average Turn Around Time: " << (float)total_turn_around_time / n << endl;
}
int main() {
    vector<Process> processes = {
        {1, 10, 0},
        {2, 5, 1},
        {3, 8, 2}
    };
    fcfs(processes);
}
