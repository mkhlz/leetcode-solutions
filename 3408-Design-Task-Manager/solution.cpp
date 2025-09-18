#include <bits/stdc++.h>
using namespace std;

// type aliases
using ll = long long;
using ull = unsigned long long;
using ld = long double;

const ll INF = 1e18;
const int MOD = 1e9+7;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

class TaskManager {
public:
    priority_queue<pair<ll, int>> heap; // heap stores {priority, taskId}
    // map: taskId -> {userId, priority}
    unordered_map<int, pair<int, ll>> map;

    // constructor: initialize from list of {userId, taskId, priority}
    TaskManager(vector<vector<int>>& tasks) {
        for (auto &t : tasks) {
            int userId = t[0];
            int taskId = t[1];
            ll pr = t[2];
            map[taskId] = {userId, pr};
            heap.push({pr, taskId});
        }
    }
    
    // add a new task
    void add(int userId, int taskId, int priority) {
        map[taskId] = {userId, priority};
        heap.push({priority, taskId});
    }
    
    // edit existing task's priority
    void edit(int taskId, int newPriority) {
        if (map.count(taskId)) {
            int userId = map[taskId].first;
            map[taskId] = {userId, newPriority};
            heap.push({newPriority, taskId});
        }
    }
    
    // remove a task
    void rmv(int taskId) {
        map.erase(taskId); // lazy remove
    }
    
    // execute top task: return userId of executed task
    int execTop() {
        // clean stale entries
        while (!heap.empty()) {
            auto [p, tid] = heap.top();
            if (!map.count(tid)) { // task removed
                heap.pop();
                continue;
            }
            auto [uid, curP] = map[tid];
            if (curP != p) { // outdated priority
                heap.pop();
                continue;
            }
            // now valid top task
            heap.pop();
            map.erase(tid); // exeecute and remove
            return uid;
        }
        return -1; // no tasks available
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */