class TaskManager {
public:
    // userId,taskId,priority
    unordered_map<int, int> taskPrioMap;    // taskId, Priorites
    priority_queue<pair<int, int>> maxHeap; // Priorites,taskId
    unordered_map<int, int> taskOwnerMap;   // taskId,UserId

    TaskManager(vector<vector<int>>& tasks) {
        for (auto& t : tasks) {
            taskPrioMap.insert({t[1], t[2]});
            maxHeap.push({t[2], t[1]});
            taskOwnerMap.insert({t[1], t[0]});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskPrioMap.insert({taskId, priority});
        maxHeap.push({priority, taskId});
        taskOwnerMap.insert({taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        taskPrioMap[taskId] = newPriority;
        maxHeap.push({newPriority, taskId});
    }

    void rmv(int taskId) {
        taskPrioMap.erase(taskId);
        taskOwnerMap.erase(taskId);
    }

    int execTop() {
        while (!maxHeap.empty()) {
            auto [Priorites, taskId] = maxHeap.top();
            if (taskPrioMap.find(taskId) != taskPrioMap.end() &&
                taskPrioMap[taskId] == Priorites) {
                int userId = taskOwnerMap[taskId];
                maxHeap.pop();
                taskPrioMap.erase(taskId);
                taskOwnerMap.erase(taskId);
                return userId;
            }
            maxHeap.pop();
        }
        return -1;
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