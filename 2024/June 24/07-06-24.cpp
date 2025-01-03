class TrieNode
{
public:
    unordered_map<char, TrieNode *> children;
    string word = "";
};

class Trie
{
public:
    TrieNode *root;

    Trie()
    {
        root = new TrieNode();
    }

    void insert(string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->word = word;
    }

    string searchRoot(string &word)
    {
        TrieNode *node = root;
        for (char c : word)
        {
            if (node->children.find(c) == node->children.end())
            {
                return word;
            }
            node = node->children[c];
            if (node->word != "")
            {
                return node->word;
            }
        }
        return word;
    }
};

class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        Trie trie;
        for (string &root : dictionary)
        {
            trie.insert(root);
        }

        istringstream iss(sentence);
        string word;
        vector<string> words;

        while (iss >> word)
        {
            words.push_back(trie.searchRoot(word));
        }

        string result = "";
        for (int i = 0; i < words.size(); i++)
        {
            if (i > 0)
            {
                result += " ";
            }
            result += words[i];
        }

        return result;
    }
};
