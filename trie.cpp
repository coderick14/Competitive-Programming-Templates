#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct trie_node {
    ll word_count;
    ll prefix_count;
    trie_node* edges[26];

    trie_node() {
        this->word_count = 0;
        this->prefix_count = 0;
        for(int i = 0; i < 26; i++) {
            this->edges[i] = NULL;
        }
    }
};

void add_word(trie_node* &root, string &str, int index) {
    if (index == str.length()) {
        root->word_count += 1;
        return;
    }
    root->prefix_count += 1;
    int i = int(str[index] - 'a'); 
    if (root->edges[i] == NULL) {
        root->edges[i] = new trie_node();
    }
    add_word(root->edges[i], str, index+1);
}

ll count_prefix(trie_node* root, string &prefix, int index) {
    if (index == prefix.length()) {
        return root->prefix_count;
    }
    int i = int(prefix[index] - 'a');
    if (root->edges[i] == NULL) {
        return 0;
    }
    return count_prefix(root->edges[i], prefix, index+1);
}

int main() {
    trie_node* root = new trie_node();
    string s = "codechef";
    add_word(root, s, 0);
    s = "codeforces";
    add_word(root, s, 0);
    s = "youtube";
    add_word(root, s, 0);
    s = "google";
    add_word(root, s, 0);
    s = "code"; 
    cout<<count_prefix(root, s, 0)<<endl;
    return 0;
}
