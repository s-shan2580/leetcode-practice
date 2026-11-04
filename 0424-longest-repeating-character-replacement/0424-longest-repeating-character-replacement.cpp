class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        vector<int> freq(26, 0);

        int l = 0, maxFreq = 0, maxi = 0;

        for(int r = 0; r < n; r++) {

            // Include current character in the window
            freq[s[r] - 'A']++;

            // Update historical maximum frequency
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // Shrink window if replacements required exceed k
            while((r - l + 1 - maxFreq) > k) {

                // Remove leftmost character from the window
                freq[s[l] - 'A']--;

                // Move left pointer forward
                l++;
            }

            // Update maximum window length
            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};