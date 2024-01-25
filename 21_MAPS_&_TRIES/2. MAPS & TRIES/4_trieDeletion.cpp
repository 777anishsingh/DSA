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

// SEARCHING CODE
bool searchWord(trieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        return root->isTerminal;
    }

    char ch = word[0];    // to be found
    int index = ch - 'a'; // what index
    trieNode *child;

    if (root->children[index] != NULL)
    {
        // present or found
        child = root->children[index];
    }
    else
    {
        // not found
        return false;
    }

    // baki recursion
    bool recursionAns = searchWord(child, word.substr(1));
    return recursionAns;
}

// DELETION CODE
void deleteNode(trieNode *root, string word)
{
    // base case
    if (word.length() == 0)
    {
        root->isTerminal = false;
        return;
    }

    // 1case
    char ch = word[0];
    int index = ch - 'a';
    trieNode *child;

    if (root->children[index] != NULL)
    {
        // present
        child = root->children[index];
    }
    else
    {
        // not present
        return;
    }
    // recursion
    deleteNode(child, word.substr(1));
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

    cout << "Insertion Done" << endl;

    // SEARCHING CODE
    string str;
    cout << "Enter the Word to be searched: " << endl;
    getline(cin, str);

    while (str != "-1")
    {
        if (searchWord(root, str))
        {
            cout << "Found" << endl;
        }
        else
        {
            cout << "Not Found" << endl;
        }

        cout << "Enter the Word to be searched: " << endl;
        getline(cin, str);
    }

    // DELETION CODE
    cout << "Enter the Word to be deleted: " << endl;
    string deleteWord;
    getline(cin, deleteWord);
    deleteNode(root, deleteWord);
    cout << "After deletion" << endl;
    cout << "Enter the Word to be searched after deletion: " << endl;
    getline(cin, str);
    if (searchWord(root, str))
    {
        cout << "Found" << endl;
    }
    else
    {
        cout << "Not Found" << endl;
    }

    return 0;
}
