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

vector<string> result;
bool flag = true;

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

void dfs(trie_node* root_allowed, trie_node* root_blocked, string s) {
    int i;
    bool is_prefix = true;
    string filter;
    if (root_blocked->word_count > 0) {
        flag = false;
        return;
    }
    for(i = 0; i < 26; i++) {
        if(root_blocked->edges[i] != NULL && root_allowed->edges[i] != NULL) {
            is_prefix = false;
            filter = s + char(97+i);
            dfs(root_allowed->edges[i], root_blocked->edges[i], filter);
        }
        else if (root_blocked->edges[i] != NULL && root_allowed->edges[i] == NULL) {
            is_prefix = false;
            filter = s + char(97+i); 
            result.push_back(filter);
        } 
    }
    if (is_prefix) {
        flag = false;
    }
}

int main() {
    ll i,n;
    string s;
    char ch;
    cin>>n;
    trie_node* root_allowed = new trie_node();
    trie_node* root_blocked = new trie_node();

    for(i=0; i<n; i++) {
        cin>>ch>>s;
        if (ch == '+') {
            add_word(root_allowed, s, 0);
        }
        else {
            add_word(root_blocked, s, 0);
        }
    }
    s = "";
    dfs(root_allowed, root_blocked, s);
    int len = result.size();
    if (flag == false) {
        cout<<-1<<endl;
    }
    else if (len == 0) {
        cout<<0<<endl;
    }
    else {
        cout<<len<<endl;
        for(i = 0; i < len; i++) {
            cout<<result[i]<<endl;
        }
    }
    return 0;
}
