class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();

        vector<int> freq(26, 0);
        int l = 0, maxFreq = 0, maxi = 0;

        for(int r = 0; r < n; r++) {

            // Expand window by including the current character
            freq[s[r] - 'A']++;

            // Store the highest frequency encountered so far.
            // We deliberately don't decrease it when shrinking the window.
            maxFreq = max(maxFreq, freq[s[r] - 'A']);

            // If window length exceeds maxFreq + k, shrink it.
            // Here maxFreq is historical, so this doesn't necessarily
            // restore the actual validity of the current window.
            while((r - l + 1 - maxFreq) > k) {

                // Remove the leftmost character from the window
                freq[s[l] - 'A']--;
                l++;
            }

            // Update the maximum window length.
            // A stale maxFreq may make the current window appear valid,
            // but it cannot produce a length larger than what a genuinely
            // valid substring can achieve.
            maxi = max(maxi, r - l + 1);
        }

        return maxi;
    }
};