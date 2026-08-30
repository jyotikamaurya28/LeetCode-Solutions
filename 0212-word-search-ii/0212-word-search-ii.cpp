class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                child[i] = nullptr;
            word = "";
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> ans;
    int m, n;

    void insert(string& word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->child[idx])
                node->child[idx] = new TrieNode();

            node = node->child[idx];
        }

        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node) {
        char ch = board[r][c];

        if (ch == '#')
            return;

        int idx = ch - 'a';

        if (!node->child[idx])
            return;

        TrieNode* next = node->child[idx];

        if (next->word != "") {
            ans.push_back(next->word);
            next->word = "";
        }

        board[r][c] = '#';

        if (r + 1 < m) dfs(board, r + 1, c, next);
        if (r - 1 >= 0) dfs(board, r - 1, c, next);
        if (c + 1 < n) dfs(board, r, c + 1, next);
        if (c - 1 >= 0) dfs(board, r, c - 1, next);

        board[r][c] = ch;
    }

    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        m = board.size();
        n = board[0].size();

        for (string& word : words)
            insert(word);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }

};