class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int n = skill.size();
        long long totalSum = 0;
        
        // Calculate the total sum of skills
        for (int s : skill) {
            totalSum += s;
        }
        
        // Check if the total sum is divisible by n / 2
        if (totalSum % (n / 2) != 0) {
            return -1;
        }
        
        // Target sum for each team
        int targetTeamSkill = totalSum / (n / 2);
        
        // Sort the skills array
        sort(skill.begin(), skill.end());
        
        long long totalChemistry = 0;
        int i = 0, j = n - 1;
        
        // Use two pointers to form teams
        while (i < j) {
            if (skill[i] + skill[j] != targetTeamSkill) {
                return -1;  // If the team does not match the target skill
            }
            // Calculate the chemistry of the team
            totalChemistry += (long long)skill[i] * skill[j];
            
            // Move pointers
            i++;
            j--;
        }
        
        return totalChemistry;
        
    }
};