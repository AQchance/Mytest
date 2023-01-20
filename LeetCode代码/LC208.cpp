#include <string>
#include <iostream>
#include <vector>
using namespace std;

// 构建了一棵字典树，通过字典树的检索来查找一个字符串，效率比较高
class Trie
{
private:
    bool isLeafNode;
    vector<Trie *> children;

public:
    Trie() : isLeafNode(false), children(26){};

    void insert(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            if (node->children[ch - 'a'] == nullptr)
                node->children[ch - 'a'] = new Trie();
            node = node->children[ch - 'a'];
        }
        node->isLeafNode = true;
    }

    bool search(string word)
    {
        Trie *node = this;
        for (char ch : word)
        {
            if (node->children[ch - 'a'] != nullptr)
                node = node->children[ch - 'a'];
            else
                return false;
        }
        if (node->isLeafNode)
            return true;
        else
            return false;
    }

    bool startsWith(string prefix)
    {
        Trie *node = this;
        for (char ch : prefix)
        {
            if (node->children[ch - 'a'] != nullptr)
                node = node->children[ch - 'a'];
            else
                return false;
        }
        return true;
    }
};

int main()
{
    cout << "我是真的没写主函数233" << endl;
    return 0;
}