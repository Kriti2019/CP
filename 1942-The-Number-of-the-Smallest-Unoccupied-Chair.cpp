class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
         int n = times.size();

    // Create events for each friend [arrival time, leaving time, index]
    vector<tuple<int, int, int>> events;
    for (int i = 0; i < n; ++i) {
        events.emplace_back(times[i][0], times[i][1], i);
    }

    // Sort events based on arrival time
    sort(events.begin(), events.end());

    // Min-heap for available chairs
    priority_queue<int, vector<int>, greater<int>> availableChairs;
    for (int i = 0; i < n; ++i) {
        availableChairs.push(i); // Initially, all chairs from 0 to n-1 are available
    }

    // Min-heap for occupied chairs (sorted by leaving time)
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;

    // Process each event
    for (const auto& [arrTime, leaveTime, friendIdx] : events) {
        // Release chairs for friends who have left by this arrival time
        while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrTime) {
            availableChairs.push(occupiedChairs.top().second);
            occupiedChairs.pop();
        }

        // Assign the smallest available chair to the current friend
        int chair = availableChairs.top();
        availableChairs.pop();

        // If the current friend is the target friend, return the chair number
        if (friendIdx == targetFriend) {
            return chair;
        }

        // Add the chair to the occupied list with its leaving time
        occupiedChairs.emplace(leaveTime, chair);
    }

    // If no chair is found for the target friend, return -1 (should not happen)
    return -1;
    }
};