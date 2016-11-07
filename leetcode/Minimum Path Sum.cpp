#include <iostream>
#include <vector>

using namespace std;

int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> tgrid;
    for(int i = 0; i < grid.size(); i++)
        tgrid.push_back(vector<int>(grid[0].size(), 0));
    tgrid[0][0] = grid[0][0];
    for(int i = 1; i < tgrid.size(); i++)
        tgrid[i][0] = tgrid[i-1][0] + grid[i][0];
    for(int j = 1; j < tgrid[0].size(); j++)
        tgrid[0][j] = tgrid[0][j-1] + grid[0][j];
    for(int i = 1; i < tgrid.size(); i++)
        for(int j = 1; j < tgrid[0].size(); j++)
            tgrid[i][j] = grid[i][j] + (tgrid[i-1][j] < tgrid[i][j-1] ? tgrid[i-1][j] : tgrid[i][j-1]); 
    return tgrid[tgrid.size()-1][tgrid[0].size()-1];
}

int main(int argc, const char * argv[]) {
    vector<vector<int>> grid = {{1,4,2,5,1},{1,4,2,5,1},{1,4,2,5,1},{1,4,2,5,1},{1,4,2,5,1}};
    int res = minPathSum(grid);
    return 0;
}
