#include <iostream>
#include <queue>
#include <vector>

/*
 * LEVEL 4 (HARD): Operating System CPU Round Robin Scheduler Simulation
 * Uses a Queue to schedule processes with a fixed time quantum.
 */

struct Process {
    int id;
    int burstTime;
    int remainingTime;
    int waitingTime;
    int turnaroundTime;
};

void runRoundRobin(std::vector<Process>& procs, int quantum) {
    std::queue<int> q;
    for (size_t i = 0; i < procs.size(); ++i) q.push(i);

    int time = 0;
    std::cout << "Execution Gantt Chart:\n";

    while (!q.empty()) {
        int idx = q.front();
        q.pop();

        int run = std::min(quantum, procs[idx].remainingTime);
        std::cout << "[T=" << time << "] P" << procs[idx].id << " runs for " << run << " units\n";
        time += run;
        procs[idx].remainingTime -= run;

        if (procs[idx].remainingTime > 0) {
            q.push(idx);
        } else {
            procs[idx].turnaroundTime = time;
            procs[idx].waitingTime = procs[idx].turnaroundTime - procs[idx].burstTime;
            std::cout << "  -> P" << procs[idx].id << " finished at T=" << time << "\n";
        }
    }

    std::cout << "\nProcess\tBurst\tTurnaround\tWaiting\n";
    for (const auto& p : procs) {
        std::cout << "P" << p.id << "\t" << p.burstTime << "\t" 
                  << p.turnaroundTime << "\t\t" << p.waitingTime << "\n";
    }
}

int main() {
    std::vector<Process> plist = {
        {1, 5, 5, 0, 0},
        {2, 3, 3, 0, 0},
        {3, 8, 8, 0, 0}
    };
    runRoundRobin(plist, 2);
    return 0;
}
