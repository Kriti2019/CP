class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
         // Directions: north, east, south, west
        vector<vector<int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int directionIndex = 0; // Start facing north
        int x = 0, y = 0;
        int maxDistanceSquared = 0;

        // Use a set to store obstacle positions for fast lookup
        unordered_set<string> obstacleSet;
        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(to_string(obstacle[0]) + "," + to_string(obstacle[1]));
        }

        for (int command : commands) {
            if (command == -1) {
                // Turn right
                directionIndex = (directionIndex + 1) % 4;
            } else if (command == -2) {// Turn left
                directionIndex = (directionIndex + 3) % 4;
            } else {
                // Move forward k units
                int dx = directions[directionIndex][0];
                int dy = directions[directionIndex][1];
                
                for (int step = 0; step < command; ++step) {
                    int newX = x + dx;
                    int newY = y + dy;
                    if (obstacleSet.find(to_string(newX) + "," + to_string(newY)) == obstacleSet.end()) {
                        x = newX;
                        y = newY;
                        maxDistanceSquared = max(maxDistanceSquared, x * x + y * y);
                    } else {
                        // Encountered an obstacle, stop moving
                        break;
                    }
                     }
            }
        }

        return maxDistanceSquared;
        
    }
};