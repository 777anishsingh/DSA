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
        trieNode *lastChar = root; // it stores 'a' for input 'ca'
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
        cout << "No Matching String Exist";
        return;
    }

    // recursion
    findPrefixString(child, input.substr(1), ans, prefix);
}

vector<vector<string>> getSuggestions(trieNode *root, string input)
{
        cout<<"1ewe"<<endl;

    vector<vector<string>> output;
    trieNode *prev = root;
    string inputHelper = "";

    for (int i = 0; i < input.length(); i++)
    {
        char lastChar = input[i];
        int index = lastChar - 'a';
        trieNode *curr = prev->children[index];
        cout<<"10"<<endl;

        if (curr == NULL)
        {        cout<<"1"<<endl;

            break;
        }
        else
        {
            vector<string> bakiKaAns;
            inputHelper.push_back(lastChar);
            string dummy = "";
            storeString(curr, bakiKaAns, inputHelper, dummy);
            output.push_back(bakiKaAns);
            prev = curr; // important
        }
        cout<<"1"<<endl;
    }
    return output;
}

int main()
{
    // INSERTION CODE
    trieNode *root = new trieNode('-');
    insertWord(root, "cater");
    insertWord(root, "care");
    insertWord(root, "com");
    insertWord(root, "lover");
    insertWord(root, " loved");
    insertWord(root, "load");
    insertWord(root, "lov");
    insertWord(root, "bat");
    insertWord(root, "cat");
    insertWord(root, "car");

    vector<vector<string>> ans = getSuggestions(root, "loa");

    // print
    for (int i = 0; i < ans.size(); i++)
    {
        cout << i << "->";
        for (auto str : ans[i])
        {
            cout << str << ", ";
        }
        cout << endl;
    }

    return 0;
}
