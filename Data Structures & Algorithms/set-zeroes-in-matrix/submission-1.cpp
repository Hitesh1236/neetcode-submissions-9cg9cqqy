class Solution {
   public:
    void setZeroes(vector<vector<int>>& matrix) {
        int width = matrix[0].size();
        int height = matrix.size();
        bool firstRow = false;
        bool firstCol = false;

        for (int j = 0; j < width; j++) {
            if (matrix[0][j] == 0) {
                firstRow = true;
                break;
            }
        }
        for (int i = 0; i < height; i++) {
            if (matrix[i][0] == 0) {
                firstCol = true;
                break;
            }
        }
        for (int row = 0; row < height; row++) {
            for (int column = 0; column < width; column++) {
                if (matrix[row][column] == 0) {
                    matrix[row][0] = 0;
                    matrix[0][column] = 0;
                }
            }
        }
        for (int row = 1; row < height; row++) {
            if (matrix[row][0] == 0) {
                for (int column = 1; column < width; column++) {
                    matrix[row][column] = 0;
                }
            }
        }
        for (int column = 1; column < width; column++) {
            if (matrix[0][column] == 0) {
                for (int row = 1; row < height; row++) {
                    matrix[row][column] = 0;
                }
            }
        }
        if (firstRow) {
            for (int j = 0; j < width; j++) {
                matrix[0][j] = 0;
            }
        }

        if (firstCol) {
            for (int i = 0; i < height; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};
