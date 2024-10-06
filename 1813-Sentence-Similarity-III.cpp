class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
         auto split = [](const string& sentence) {
        vector<string> words;
        istringstream stream(sentence);
        string word;
        while (stream >> word) {
            words.push_back(word);
        }
        return words;
    };
    
    // Split both sentences into words
    vector<string> words1 = split(sentence1);
    vector<string> words2 = split(sentence2);
    
    // Make sure words1 is the smaller one for simpler comparison
    if (words1.size() > words2.size()) {
        swap(words1, words2);
    }
    
    int n1 = words1.size(), n2 = words2.size();
    int left = 0, right = 0;
    
    // Check prefix matching
    while (left < n1 && words1[left] == words2[left]) {
        ++left;
    }
    
    // Check suffix matching
    while (right < n1 && words1[n1 - 1 - right] == words2[n2 - 1 - right]) {
        ++right;
    }
    
    // The sentences are similar if the sum of matched prefix and suffix covers the entire smaller sentence
    return left + right >= n1;
        
    }
};