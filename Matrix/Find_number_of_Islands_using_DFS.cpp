class Solution {
  public:
    
    void DFS(int row,int col,vector<vector<char>> &mat, vector<vector<int>> &vis,int *rowin,int *colin, int n,int m)
    {
        vis[row][col] = 1;
        for(int i=0;i<9;i++)
        {
            int newr = row + rowin[i];
            int newc = col + colin[i];
            if(newr >=0 && newr < n && newc >= 0 && newc < m && mat[newr][newc] == '1' && vis[newr][newc] == 0)
                DFS(newr,newc,mat,vis,rowin,colin,n,m);
        }
    }
    
    int numIslands(vector<vector<char>>& mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        int rowin[] = {0,-1,-1,-1,0,1,1,1};
        int colin[] = {-1,-1,0,1,1,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == '1' && vis[i][j] == 0) 
                {
                    cnt++;
                    DFS(i,j,mat,vis,rowin,colin,n,m);
                }
            }
        }
        
        return cnt;
    }
};