Problem Link: https://www.codingninjas.com/studio/problems/flood-fill-algorithm_8230806?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include "bits/stdc++.h"
void dfs(int r, int c, vector<vector<int>>& res, vector<vector<int>>& image, int dx[], int dy[],
    int newColor, int prevColor, int n, int m) {
    res[r][c] = newColor;

    for (int i=0; i<4; i++) {
        int new_r = r+dx[i];
        int new_c = c+dy[i];

        if (new_r>=0 && new_r<n && new_c>=0 && new_c<m && 
        image[new_r][new_c] == prevColor && res[new_r][new_c] != newColor) {
            dfs(new_r, new_c, res, image, dx, dy, newColor, prevColor, n, m);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int x, int y, int newColor)
{
    int n = image.size(), m = image[0].size();
    int preColor = image[x][y];

    vector<vector<int>> res = image;

    int dx[] = {1, -1, 0, 0};
    int dy[] = {0, 0, 1, -1};

    dfs(x, y, res, image, dx, dy, newColor, preColor, n, m);
    return res;
}
