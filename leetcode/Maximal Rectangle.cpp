#include <iostream>
#include <vector>

using namespace std;

int maximalRectangle(vector<vector<char>> &matrix) {
    if (matrix.empty()) return 0;
    int rows = matrix.size();
    int cols = matrix[0].size();
    int maxArea = 0;
    vector<int> heights(cols + 1, 0);
    vector<int> stack;
    for (int i = 0; i < rows; i++) {
        stack.clear();
        for (int j = 0; j < cols + 1; j++) {
            if (j < cols) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            if (stack.empty() || heights[j] >= heights[stack.back()]) {
                stack.push_back(j);
                continue;
            }
            while (!stack.empty() && heights[j] < heights[stack.back()]) {
                int top = stack.back();
                stack.pop_back();
                int begin = stack.empty() ? 0 : stack.back() + 1;
                int area = heights[top] * (j - begin);
                if (area > maxArea) maxArea = area;
            }
            stack.push_back(j);
        }
    }
    return maxArea;
}

int main() {
    vector<vector<char>> matrix = 
    {
        {'1', '0', '1', '0', '0'},
        {'1', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1'},
        {'1', '0', '0', '1', '0'},
    };
    int ret = maximalRectangle(matrix);
    return 0;
}
