public class WordDictionary {
    TrieNode root;
    WordDictionary(){
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    public void addWord(String word) {
        TrieNode node = this.root;
        char[] chars = word.toCharArray();
        for(int i = 0; i < chars.length; i++){
            int j = chars[i] - 'a';
            if(node.children[j] == null){
                node.children[j] = new TrieNode(chars[i]);
            }
            node.isLeaf = false;
            node = node.children[j];
        }
        node.isWord = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    public boolean search(String word) {
        char[] chars = word.toCharArray();
        return searchHelper(chars,0, this.root);
    }
    
    //A helper for recursive search
    boolean searchHelper(char[] word, int start, TrieNode curr){
        //TrieNode node = curr;
        for(int i = start; i < word.length; i++){
            //search recursively
            if(word[i] == '.'){
                if(curr.isLeaf) return false;
                for(int j = 0; j < 26; j++){
                    if(curr.children[j] != null){
                        if(searchHelper(word, i+1, curr.children[j])) return true;
                    }
                }
                return false;
            }
            //search one by one
            int j = word[i] - 'a';
            if(curr.children[j] == null) return false;
            curr = curr.children[j];                
        }
        return curr.isWord;
    }
}

class TrieNode{
    char val;
    boolean isWord = false;
    boolean isLeaf = true;
    TrieNode[] children = new TrieNode[26];
    TrieNode(){
    }
    TrieNode(char ch){
        val = ch;
    }
}

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary = new WordDictionary();
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");