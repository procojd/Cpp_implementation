#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Job {
    int id;
    int deadline;
    int profit;
};
bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}
void jobScheduling(vector<Job>& jobs) {
    // Sort jobs based on profit in descending order
    sort(jobs.begin(), jobs.end(), compareJobs);

    vector<int> result(jobs.size(), -1); // Result array to store the scheduled jobs
    vector<bool> slot(jobs.size(), false); // Array to check if a time slot is occupied

    // Iterate through each job and find a suitable slot for it
    for (int i = 0; i < jobs.size(); ++i) {
        for (int j = min(jobs[i].deadline - 1, static_cast<int>(jobs.size()) - 1); j >= 0; --j) {
            if (!slot[j]) {
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }

    // Display the scheduled jobs
    cout << "Scheduled Jobs:\n";
    for (int i = 0; i < jobs.size(); ++i) {
        if (slot[i]) {
            cout << "Job " << jobs[result[i]].id << " with profit " << jobs[result[i]].profit << " scheduled at time " << i + 1 << '\n';
        }
    }
}

int main() {
    // Example jobs
    vector<Job> jobs = {
        {1, 4, 20},
        {2, 1, 10},
        {3, 1, 40},
        {4, 1, 30}
    };

    jobScheduling(jobs);

    return 0;
}
