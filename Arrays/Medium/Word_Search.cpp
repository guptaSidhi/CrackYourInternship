class Solution {
public:
    bool solve(int index,int row,int col,string word,vector<vector<char>> &board,vector<vector<int>> &vis,int n,int m,int *rowin,int *colin)
    {
        if(index == word.size()-1){
            if(board[row][col] == word[index]) return true;
            return false;
        }

        vis[row][col] = 1;
        for(int i=0;i<4;i++)
        {
            int newr = row + rowin[i];
            int newc = col + colin[i];
            if(newr >= 0 && newr < n && newc >= 0 && newc < m && vis[newr][newc] == 0 && board[newr][newc] == word[index+1])  
                if(solve(index+1,newr,newc,word,board,vis,n,m,rowin,colin)) return true;
        }

        vis[row][col] = 0;
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        int rowin[] = {-1,0,1,0};
        int colin[] = {0,1,0,-1};
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j] == word[0])
                {
                    if(solve(0,i,j,word,board,vis,n,m,rowin,colin)) return true;
                }
            }
        }

        return false;
    }
};