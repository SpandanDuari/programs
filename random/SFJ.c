#include <stdio.h>

struct Process {
    int id;
    int burstTime;
    int waitingTime;
    int turnaroundTime;
};

// Function to find waiting time for all processes
void findWaitingTime(struct Process processes[], int n) {
    processes[0].waitingTime = 0; // First process has 0 waiting time

    for (int i = 1; i < n; i++) {
        processes[i].waitingTime = processes[i - 1].waitingTime + processes[i - 1].burstTime;
    }
}

// Function to find turnaround time for all processes
void findTurnaroundTime(struct Process processes[], int n) {
    for (int i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].waitingTime + processes[i].burstTime;
    }
}

// Function to implement SJF scheduling
void findAvgTime(struct Process processes[], int n) {
    // Sort processes based on burst time
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (processes[i].burstTime > processes[j].burstTime) {
                struct Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }

    findWaitingTime(processes, n);
    findTurnaroundTime(processes, n);

    printf("Process ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\n",
            processes[i].id,
            processes[i].burstTime,
            processes[i].waitingTime,
            processes[i].turnaroundTime);
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Process processes[n];

    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1; // Process IDs start from 1
        printf("Enter burst time for Process %d: ", processes[i].id);
        scanf("%d", &processes[i].burstTime);
    }

    findAvgTime(processes, n);

    return 0;
}