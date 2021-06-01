#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Worker {
public:
    int id;
    long long nextFreeTime;

    Worker(int id) {
        this->id = id;
        nextFreeTime = 0;
    }
};

struct WorkerCompare {
    bool operator()(const Worker& w1, const Worker& w2) const {
        if (w1.nextFreeTime == w2.nextFreeTime)
            return w1.id > w2.id;
        else
            return w1.nextFreeTime > w2.nextFreeTime;
    }
};


class JobQueue {
private:
    int num_workers_;
    vector<int> jobs_;

    vector<int> assigned_workers_;
    vector<long long> start_times_;

    void WriteResponse() const {
        for (int i = 0; i < jobs_.size(); ++i) {
            cout << assigned_workers_[i] << " " << start_times_[i] << "\n";
        }
    }

    void ReadData() {
        int m;
        cin >> num_workers_ >> m;
        jobs_.resize(m);
        for (int i = 0; i < m; ++i)
            cin >> jobs_[i];
    }

    void AssignJobs() {
        assigned_workers_.resize(jobs_.size());
        start_times_.resize(jobs_.size());
        priority_queue < Worker, vector<Worker>, WorkerCompare> queue;
        for (int i = 0; i < num_workers_;i++)
            queue.push(Worker(i));
        for (int i = 0; i < jobs_.size();i++) {
            Worker freeThread = queue.top();
            queue.pop();
            assigned_workers_[i]= freeThread.id;
            start_times_[i]=freeThread.nextFreeTime;
            freeThread.nextFreeTime += jobs_[i];
            queue.push(freeThread);
        }


    }

public:
    void Solve() {
        ReadData();
        AssignJobs();
        WriteResponse();
    }
};

int main() {
    std::ios_base::sync_with_stdio(false);
    JobQueue job_queue;
    job_queue.Solve();
    return 0;
}
