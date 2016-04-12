public class Solution {
    // use backtracking and trie data structure
    Set<String> results = new HashSet<>();
    
    public List<String> findWords(char[][] board, String[] words) {
        Trie dict = new Trie();
        dict.build(words);
        
        for (int row = 0; row < board.length; row++) {
            for (int col = 0; col < board[row].length; col++) {
                searchHelper(board, row, col, "", dict);
            }
        }
        return new ArrayList<String>(results);
    }
    
    public void searchHelper(char[][] board, int row, int col, String word, Trie dict) {
        // visited
        if (row < 0 || col < 0 || row == board.length
            ||col == board[row].length || board[row][col] >= 256) return;
        //board[row][col] >= 256]) return;
    
        
        
        word += board[row][col];
        //if no prefix, retrun; if found, add
        if (!dict.startsWith(word)) return;
        if(dict.search(word)) results.add(word);
        //mark visited
        board[row][col] ^= 256;
        
        searchHelper(board, row - 1, col, word, dict);
        searchHelper(board, row + 1, col, word, dict);
        searchHelper(board, row, col - 1, word, dict);
        searchHelper(board, row, col + 1, word, dict);
        
            
        //unmark
        board[row][col] ^= 256;
        return;
    }
    

}

class TrieNode {
    // Initialize your data structure here.
    public char val;
    public boolean isWord = false;
    public boolean isLeaf = true;
    public TrieNode[] children = new TrieNode[26];
    public TrieNode() {
    }
    public TrieNode(char ch){
        this.val = ch;
    }
}

class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    public void build(String[] words){
        for(int i = 0 ; i < words.length; i++)
            this.insert(words[i]);
    }
    // Inserts a word into the trie.
    public void insert(String word) {
        TrieNode node = this.root;
        for(int i = 0; i < word.length(); i++){
            int j = word.charAt(i) - 'a';
            if(node.children[j] == null){
                node.children[j] = new TrieNode(word.charAt(i));
            }
            node.isLeaf = false;
            node = node.children[j];
        }
        node.isWord = true;
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
        TrieNode node = this.root;
        for(int i = 0; i < word.length(); i++){
            if(node.isLeaf) return false;
            int j = word.charAt(i) - 'a';
            if(node.children[j] == null)
                return false;
            node = node.children[j];
        }
        return node.isWord;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        TrieNode node = this.root;
        for(int i = 0; i < prefix.length(); i++){
            if(node.isLeaf) return false;
            int j = prefix.charAt(i) - 'a';
            if(node.children[j] == null){
                return false;
            }
            node = node.children[j];
        }
        return true;
    }
}
