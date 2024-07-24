class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        int rowin[] = {0,-1,-1,-1,0,1,1,1};
        int colin[] = {-1,-1,0,1,1,1,0,-1};
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int onecnt = 0;
                int zerocnt = 0;
                for(int k=0;k<8;k++)
                {
                    int newr = i+rowin[k];
                    int newc = j+colin[k];
                    if(newr >= 0 && newr < n && newc >=0 && newc < m)
                    {
                        if((board[newr][newc])%2 == 0) zerocnt++;
                        else if((board[newr][newc])%2 == 1) onecnt++;
                    }
                }

                if(board[i][j] == 0 && onecnt == 3) board[i][j] += 2;
                else if(board[i][j] == 1 && onecnt < 2) board[i][j] += 0;
                else if(board[i][j] == 1 && onecnt > 3) board[i][j] += 0;
                else if(board[i][j] == 1 && onecnt >= 2 && onecnt <= 3) board[i][j] += 2;
                else board[i][j] += 0;
            }
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                board[i][j] = board[i][j]/2;
            }
        }
    }
};