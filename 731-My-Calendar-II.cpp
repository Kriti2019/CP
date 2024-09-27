class MyCalendarTwo {
public:
     // List to store single bookings
    std::vector<std::pair<int, int>> events;
    // List to store overlaps that represent double bookings
    std::vector<std::pair<int, int>> overlaps;
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
          for (const auto& overlap : overlaps) {
            int overlapStart = overlap.first;
            int overlapEnd = overlap.second;
            if (start < overlapEnd && end > overlapStart) {
                return false; // Triple booking detected
            }
        }
        
        // Check overlaps with all existing events to update the overlaps list
        for (const auto& event : events) {
            int eventStart = event.first;
            int eventEnd = event.second;
            if (start < eventEnd && end > eventStart) {
                // Calculate the overlapping interval
                int overlapStart = std::max(start, eventStart);
                int overlapEnd = std::min(end, eventEnd);
                overlaps.push_back({overlapStart, overlapEnd});
            }
        }
        
        // No triple booking detected, so add the current event to the events list
        events.push_back({start, end});
        return true;
        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */