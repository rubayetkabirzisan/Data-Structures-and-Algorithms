#include <stdio.h>

// Process structure
typedef struct {
    int id;
    int burst_time;
    int remaining_time;
} Process;

// Round Robin scheduling function
void round_robin(Process processes[], int n, int quantum) {
    int time = 0; // Current time
    int done = 0; // Number of processes finished

    while (done < n) {
        done = 0;

        for (int i = 0; i < n; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > quantum) {
                    time += quantum;
                    processes[i].remaining_time -= quantum;
                    printf("Process %d executed for %d units of time, remaining time: %d\n", processes[i].id, quantum, processes[i].remaining_time);
                } else {
                    time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    printf("Process %d finished at time %d\n", processes[i].id, time);
                }
            } else {
                done++;
            }
        }
    }
}

int main() {
    // Define processes
    Process processes[] = {
        {1, 10, 10},
        {2, 5, 5},
        {3, 8, 8}
    };
    int n = sizeof(processes) / sizeof(processes[0]);
    int quantum = 2;

    // Call Round Robin scheduling
    round_robin(processes, n, quantum);

    return 0;
}


