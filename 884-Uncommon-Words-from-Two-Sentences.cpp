class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> wordCount;
    vector<string> result;

    // Helper function to split the sentence into words and count their occurrences
    auto addWords = [&](const string& sentence) {
        stringstream ss(sentence);
        string word;
        while (ss >> word) {
            wordCount[word]++;
        }
    };

    // Process both sentences
    addWords(s1);
    addWords(s2);

    // Find words that occur exactly once
    for (const auto& entry : wordCount) {
        if (entry.second == 1) {
            result.push_back(entry.first);
        }
    }

    return result;
       
        
    }
};