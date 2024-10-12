class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
         vector<pair<int, int>> events;
    
    // Each interval generates two events: start (+1) and end (+1 after the end)
    for (const auto& interval : intervals) {
        events.emplace_back(interval[0], 1);          // Start of an interval
        events.emplace_back(interval[1] + 1, -1);     // End of an interval (just after it ends)
    }
    
    // Sort events: first by the event position, then by type (-1 before +1 for the same position)
    sort(events.begin(), events.end());
    
    int maxGroups = 0;
    int activeIntervals = 0;
    
    // Traverse events and calculate the number of active intervals at any time
    for (const auto& event : events) {
        activeIntervals += event.second;  // Add +1 or -1 based on the event type
        maxGroups = max(maxGroups, activeIntervals);  // Update max active intervals
    }
    
    return maxGroups;
}
        
    
};