#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define vi vector<ll>
#define pp pair<ll,ll>
#define mp make_pair
#define PI acos(-1.0)
#define all(v) v.begin(),v.end()
#define pb push_back
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FREV(i,a,b) for(i=a;i>=b;i--)
#define INF 1e18

#ifndef ONLINE_JUDGE
#define gc getchar
#define pc putchar
#else
#define gc getchar_unlocked
#define pc putchar_unlocked
#endif

using namespace std;

int read_int() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    int ret = 0, neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

ll read_ll() {
    char c = gc();
    while((c < '0' || c > '9') && c != '-') c = gc();
    ll ret = 0;
    int neg = 0;
    if (c == '-') neg = 1, c = gc();
    while(c >= '0' && c <= '9') {
        ret = 10 * ret + c - 48;
        c = gc();
    }
    return neg ? -ret : ret;
}

struct node {
    node* left;
    node* right;

    node() {
        this->left = NULL;
        this->right = NULL;
    }
};

vi parent(300005);
string bit_string;
vector<node*> tree_roots;
map<ll,ll> get_index_from_id;

void create_tree(node* &root, ll key, ll parent_index) {
    node* temp = root;
    bit_string = bitset<32>(key).to_string();
    int i;
    if (parent_index == -1) {   
        FOR(i,0,32) {
            if (bit_string[i] == '0') {
                root->left = new node();
                root = root->left;
            }
            else {
                root->right = new node();
                root = root->right;
            }
        }
    }
    else {
        node* parent_root = tree_roots[parent_index];
        FOR(i,0,32) {
            if (bit_string[i] == '0') {
                root->left = new node();
                if (parent_root != NULL) {
                    root->right = parent_root->right;
                    parent_root = parent_root->left;
                }
                root = root->left;

            }
            else {
                root->right = new node();
                if (parent_root != NULL) {
                    root->left = parent_root->left;
                    parent_root = parent_root->right;
                }
                root = root->right;
            }
        }
    }
    root = temp;
}

void solve(ll v, ll k, ll &min_answer, ll &max_answer) {
    bit_string = bitset<32>(k).to_string();
    node* root = tree_roots[v];
    ll minim = 0, maxim = 0;
    int i;

    // find max
    FREV(i,31,0) {
        if (bit_string[31-i] == '0') {
            if (root->right != NULL) {
                maxim += (1<<i);
                root = root->right;
            }
            else {
                root = root->left;
            }
        }
        else {
            if (root->left != NULL) {
                maxim += (1<<i);
                root = root->left;
            }
            else {
                root = root->right;
            }
        }
    }

    root = tree_roots[v];

    // find min
    FREV(i,31,0) {
        if (bit_string[31-i] == '0') {
            if (root->left != NULL) {
                root = root->left;
            }
            else {
                minim += (1<<i);
                root = root->right;
            }
        }
        else {
            if (root->right != NULL) {
                root = root->right;
            }
            else {
                minim += (1<<i);
                root = root->left;
            }
        }
    }

    min_answer = minim;
    max_answer = maxim;
}

int main() {
	ll i,u,v,r,r_key,k,q,n,min_answer,max_answer,index=0;
    int t;
    n = read_ll();
    q = read_ll();
    r = read_ll();
    r_key = read_ll();
    tree_roots.pb(new node());
    get_index_from_id[r] = index;
    parent[index] = -1;
    create_tree(tree_roots[index], r_key, -1);
    index++;
    FOR(i,0,n-1) {
        u = read_ll();
        v = read_ll();
        k = read_ll();

        tree_roots.pb(new node());

        get_index_from_id[u] = index;
        parent[index] = get_index_from_id[v];
        create_tree(tree_roots[index], k, parent[index]);
        index++;
    }

    ll last_answer = 0;
    FOR(i,0,q) {
        t = read_int();
        t ^= last_answer;

        if(t == 0) {
            v = read_ll();
            u = read_ll();
            k = read_ll();

            u ^= last_answer;
            v ^= last_answer;
            k ^= last_answer;

            tree_roots.pb(new node());

            get_index_from_id[u] = index;
            parent[index] = get_index_from_id[v];
            create_tree(tree_roots[index], k, parent[index]);;
            index++;
        }
        else {
            v = read_ll();
            k = read_ll();

            v ^= last_answer;
            k ^= last_answer;

            solve(get_index_from_id[v],k,min_answer,max_answer);
            printf("%lld %lld\n", min_answer, max_answer);

            last_answer = min_answer^max_answer;
        }
    }
	return 0;
}