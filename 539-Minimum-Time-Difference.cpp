class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
           vector<int> minutes;
        
        // Convert time to minutes
        for (string time : timePoints) {
            int hours = stoi(time.substr(0, 2));
            int mins = stoi(time.substr(3, 2));
            minutes.push_back(hours * 60 + mins);
        }
        
        // Sort the time points in minutes
        sort(minutes.begin(), minutes.end());
        
        // Initialize minimum difference as large as possible
        int minDiff = INT_MAX;
        
        // Find the minimum difference between consecutive time points
        for (int i = 1; i < minutes.size(); i++) {
            minDiff = min(minDiff, minutes[i] - minutes[i - 1]);
        }
        
        // Also check the circular difference between the first and last time point
        int circularDiff = (1440 + minutes[0]) - minutes.back();
        minDiff = min(minDiff, circularDiff);
        
        return minDiff;
    }
};