#include <bits/stdc++.h>
using namespace std;

class trieNode
{
public:
    char value;
    trieNode *children[26];
    bool isTerminal;

    trieNode(char val)
    {
        this->value = val;
        for (int i = 0; i < 26; i++)
        {
            children[i] = NULL;
        }
        this->isTerminal = false;
    }
};

// insertion
void insertWord(trieNode *root, string word)
{

    // base case
    if (word.length() == 0)
    {
        root->isTerminal = true;
        return;
    }

    char ch = word[0];
    int index = ch - 'a';
    trieNode *child;

    if (root->children[index] != NULL)
    {
        // child present
        child = root->children[index];
    }
    else
    {
        // character not present
        child = new trieNode(ch);
        root->children[index] = child;
    }

    // recursion
    insertWord(child, word.substr(1)); // substr returnes charcetrs from index to end index = 1 in this case
}

int main()
{

    trieNode *root = new trieNode('-');
    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, "loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");

    cout << "Insertion Done" << endl;

    return 0;
}
