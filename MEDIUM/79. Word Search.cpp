#include "leetcode.h"

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0; i<board.size(); i++) {
            for(int j=0; j<board[i].size(); j++)
                if(dfs(board, i, j, word))
                    return true;
        }
        return false;
    }
    bool dfs(vector<vector<char>>& board, int i, int j, string word) {
        // succeed
        if(word.empty())
            return true;
        // out of bound
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size())
            return false;
        // no match
        if(board[i][j] != word[0])
            return false;
        // check next char
        char saved = board[i][j];
        board[i][j] = '.';
        string s = word.substr(1);
        bool res = dfs(board, i-1, j, s)
                   || dfs(board, i, j-1, s)
                   || dfs(board, i+1, j, s)
                   || dfs(board, i, j+1, s);
        board[i][j] = saved;
        return res;
    }
};


int main() {
    vector<vector<char>> board = {
        {'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}
    };
    string word = "ABCCED";
    Solution sol;
    cout << sol.exist(board, word) << endl;
}