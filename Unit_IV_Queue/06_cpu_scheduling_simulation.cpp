#include <iostream>
#include <queue>
#include <string>
#include <vector>

/*
 * Simulation of CPU Round Robin Scheduling using a Queue:
 * Processes are placed in a FIFO Ready Queue.
 * Each process is allocated a fixed time quantum of CPU execution.
 * If unfinished, it is requeued at the back of the Ready Queue.
 */

struct Process {
    std::string pid;
    int burstTime;
    int remainingTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;

    Process(std::string id, int bt) 
        : pid(id), burstTime(bt), remainingTime(bt), 
          completionTime(0), waitingTime(0), turnaroundTime(0) {}
};

void simulateRoundRobin(std::vector<Process>& processes, int timeQuantum) {
    std::queue<int> readyQueue;
    int n = processes.size();

    // Initially enqueue all process indices
    for (int i = 0; i < n; ++i) {
        readyQueue.push(i);
    }

    int currentTime = 0;
    std::cout << "========================================================\n";
    std::cout << "   Round Robin CPU Scheduling Simulation (Quantum = " << timeQuantum << ")\n";
    std::cout << "========================================================\n";
    std::cout << "Execution Gantt Trace:\n";

    while (!readyQueue.empty()) {
        int idx = readyQueue.front();
        readyQueue.pop();

        int execTime = std::min(timeQuantum, processes[idx].remainingTime);
        std::cout << "[Time " << currentTime << " -> ";
        currentTime += execTime;
        processes[idx].remainingTime -= execTime;
        std::cout << currentTime << "] Executing " << processes[idx].pid 
                  << " (Remaining BT: " << processes[idx].remainingTime << ")\n";

        if (processes[idx].remainingTime > 0) {
            readyQueue.push(idx); // Requeue process
        } else {
            // Process finished
            processes[idx].completionTime = currentTime;
            processes[idx].turnaroundTime = processes[idx].completionTime;
            processes[idx].waitingTime = processes[idx].turnaroundTime - processes[idx].burstTime;
            std::cout << "  *** " << processes[idx].pid << " FINISHED at time " << currentTime << " ***\n";
        }
    }

    std::cout << "\n========================================================\n";
    std::cout << "Process\tBurst Time\tCompletion\tTurnaround\tWaiting\n";
    std::cout << "--------------------------------------------------------\n";
    double totalWT = 0, totalTAT = 0;
    for (const auto& p : processes) {
        totalWT += p.waitingTime;
        totalTAT += p.turnaroundTime;
        std::cout << p.pid << "\t" << p.burstTime << "\t\t" 
                  << p.completionTime << "\t\t" 
                  << p.turnaroundTime << "\t\t" 
                  << p.waitingTime << "\n";
    }
    std::cout << "--------------------------------------------------------\n";
    std::cout << "Average Turnaround Time: " << (totalTAT / n) << " units\n";
    std::cout << "Average Waiting Time:    " << (totalWT / n) << " units\n";
}

int main() {
    std::vector<Process> processes = {
        Process("P1", 8),
        Process("P2", 4),
        Process("P3", 9),
        Process("P4", 5)
    };

    int timeQuantum = 3;
    simulateRoundRobin(processes, timeQuantum);

    return 0;
}
