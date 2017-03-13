#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node {
    char letter;
    ll freq;
    struct node* left;
    struct node* right;

    node(char letter, ll freq) {
        this->letter = letter;
        this->freq = freq;
        this->left = this->right = NULL;
    }
};

/*
 * Comparison function for min_heap
 */
class Prioritize {
    public:
        int operator() (struct node* a, struct node* b) {
            return a->freq > b->freq;
        }
};

/*
 * function to build the huffman tree
 * time complexity : O(nlogn) as each heap operation takes O(logn) time
 */ 
struct node* build_huffman(vector<pair<char,ll> > &chars, int n) {
    int i;
    priority_queue<node*, vector<node*>, Prioritize> min_heap;
    for(i=0; i<n; i++) {
        min_heap.push(new node(chars[i].first, chars[i].second));
    }
    for(i=0; i<n-1; i++) {
        struct node* left_child = min_heap.top();
        min_heap.pop();
        struct node* right_child = min_heap.top();
        min_heap.pop();
        struct node* new_node = new node('$', left_child->freq + right_child->freq);
        new_node->left = left_child;
        new_node->right = right_child;
        min_heap.push(new_node);
    }
    struct node* root = min_heap.top();
    min_heap.pop();
    return root;
}

/*
 * function to print huffman codes for the characters
 * time complexity : O(n) as there are 2n-1 nodes in the tree (n leaf nodes and n-1 internal nodes)
 *                   and each node is visited only once
 */
void print_huffman_codes(struct node* root, string str) {
    if(root == NULL) {
        return;
    }
    if(root->letter == '$') {
        print_huffman_codes(root->left, str+"0");
        print_huffman_codes(root->right, str+"1");
    }
    else {
        cout<<root->letter<<" : "<<str<<endl;
    }
}

int main() {
    int i,n;
    cin>>n; //number of characters
    vector<pair<char,ll> > chars(n);
    for(i=0; i<n; i++) {
        cin>>chars[i].first>>chars[i].second;
    }
    struct node* root = build_huffman(chars, n);
    print_huffman_codes(root, "");
    return 0;
}
