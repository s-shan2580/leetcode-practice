class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int col0 = 0;

        // Step 1: Store markers
        for (int i = 0; i < m; i++) {

            // Check first column
            if (matrix[i][0] == 0)
                col0 = 1;

            for (int j = 1; j < n; j++) {

                if (matrix[i][j] == 0) {
                    // Mark row
                    matrix[i][0] = 0;

                    // Mark column
                    matrix[0][j] = 0;
                }
            }
        }

        // Step 2: Use markers to set inner matrix
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {

                if (matrix[i][0] == 0 ||
                    matrix[0][j] == 0) {

                    matrix[i][j] = 0;
                }
            }
        }

        // Step 3: Handle first row
        if (matrix[0][0] == 0) {
            for (int j = 0; j < n; j++)
                matrix[0][j] = 0;
        }

        // Step 4: Handle first column
        if (col0 == 1) {
            for (int i = 0; i < m; i++)
                matrix[i][0] = 0;
        }
    }
};