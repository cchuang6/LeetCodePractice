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

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
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
            int j = prefix.charAt(i) - 'a';
            if(node.children[j] == null){
                return false;
            }
            node = node.children[j];
        }
        return true;
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");
