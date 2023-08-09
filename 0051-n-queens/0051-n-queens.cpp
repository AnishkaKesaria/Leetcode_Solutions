class Solution {
public:
    
    map<int,bool> rowCheck;
    map<int,bool> upperRDCheck;
    map<int,bool> bottomLDCheck;

    void storeSolution(vector<vector<char>> board, int n, vector<vector<string>> &ans)
    {
        vector<string> temp;
        for(int i=0; i<n; i++)
        {
            string output = "";
            for(int j=0; j<n; j++)
            {
                output.push_back(board[i][j]);
            }
            temp.push_back(output);
        }
        ans.push_back(temp);
    }
    
    bool isSafe(int row, int col, vector<vector<char>> board, int n)
    {
        if(rowCheck[row] == true)
            return false;
        else if(upperRDCheck[n-1+col-row] == true)
            return false;
        else if(bottomLDCheck[row+col] == true)
            return false;
        else
            return true;
    }
    
    void solve(vector<vector<char>> board, int col, int n, vector<vector<string>>& ans)
    {
        if(col>=n)
        {
            storeSolution(board, n, ans);
            return;
        }
        
        for(int i=0; i<n; i++)
        {
            if(isSafe(i, col, board, n))
            {
                board[i][col] = 'Q';
                rowCheck[i] = true;
                upperRDCheck[n-1+col-i] = true;
                bottomLDCheck[i+col] = true;
                solve(board, col+1, n, ans);
                board[i][col] = '.';
                rowCheck[i] = false;
                upperRDCheck[n-1+col-i] = false;
                bottomLDCheck[i+col] = false;
            }
        }
        return;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<char>> board(n, vector<char> (n,'.'));
        vector<vector<string>> ans;
        int col = 0;
        solve(board,col,n, ans);
        return ans;
    }
};