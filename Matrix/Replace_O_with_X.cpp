class Solution{
public:
    void DFS(int row,int col,vector<vector<char>> &mat,vector<vector<int>> &vis,int *rowin,int *colin,int n,int m)
    {
        vis[row][col] = 1;
        for(int i=0;i<4;i++)
        {
            int newr = row + rowin[i];
            int newc = col + colin[i];
            
            if(newr >= 0 && newr < n && newc >= 0 && newc < m && mat[newr][newc] == 'O' && vis[newr][newc] == 0)
                DFS(newr,newc,mat,vis,rowin,colin,n,m);
        }
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        int rowin[] = {0,-1,0,1};
        int colin[] = {-1,0,1,0};
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((i == 0 || i == n-1 || j == 0 || j == m-1) && mat[i][j] == 'O') 
                    DFS(i,j,mat,vis,rowin,colin,n,m);
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j] == 'O' && vis[i][j] == 0) mat[i][j] = 'X'; 
            }
        }
        
        return mat;
    }
};