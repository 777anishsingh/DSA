#include <bits/stdc++.h>
using namespace std;

// CREATION CODE
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

// INSERTION CODE
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

void storeString(trieNode *root, vector<string> &ans, string &input, string &prefix)
{
    // base case
    if (root->isTerminal)
    {
        // ans.store
        ans.push_back(prefix + input);
    }

    for (char ch = 'a'; ch <= 'z'; ch++)
    {
        int index = ch - 'a';
        trieNode *next = root->children[index];
        if (next != NULL)
        {
            // child exist
            input.push_back(ch);
            // baki recursion smbhal lega
            storeString(next, ans, input, prefix);
            // backtrack
            input.pop_back();
        }
    }
}

void findPrefixString(trieNode *root, string input, vector<string> &ans, string &prefix)
{
    // base case
    if (input.length() == 0)
    {
        trieNode *lastChar = root;
        storeString(lastChar, ans, input, prefix);
        return;
    }

    char ch = input[0];
    int index = ch - 'a';
    trieNode *child;
    if (root->children[index] != NULL)
    {
        // child present
        child = root->children[index];
    }
    else
    {   
        cout<<"No Matching String Exist";
        return;
    }

    // recursion
    findPrefixString(child, input.substr(1), ans, prefix);
}

int main()
{
    // INSERTION CODE
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

    string input = "c";
    string prefix = input;
    vector<string> ans;

    findPrefixString(root, input, ans, prefix);

    for (auto i : ans)
    {
        cout << i << " ";
    }

    cout << endl;

    return 0;
}
