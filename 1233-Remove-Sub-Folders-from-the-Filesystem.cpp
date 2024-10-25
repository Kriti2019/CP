class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());  // Sort the folders lexicographically
    vector<string> result;
    
    for (const string& f : folder) {
        // If result is empty or f is not a subfolder of the last added folder
        if (result.empty() || f.find(result.back() + '/') != 0) {
            result.push_back(f);  // Add the folder to result
        }
    }
    
    return result;
    }
};