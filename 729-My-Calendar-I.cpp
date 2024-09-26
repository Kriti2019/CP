class MyCalendar {
public:
     std::vector<std::pair<int, int>> bookings;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (const auto& event : bookings) {
            int bookedStart = event.first;
            int bookedEnd = event.second;
            
            // Check if there's an overlap
            if (start < bookedEnd && end > bookedStart) {
                return false; // Overlap found, return false
            }
        }
        
        // No overlap found, add the event to the list of bookings
        bookings.push_back({start, end});
        return true; // Booking successful
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */