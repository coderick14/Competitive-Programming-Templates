/*
 * Deleted code is debugged code :)
 */
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
#define READ(a,i,n) FOR(i,0,n) { a[i] = read_ll();}
#define DEBUG(x) cerr<<"In file "<< __FILE__ <<" at line "<< __LINE__ <<" :: "<< #x <<" = "<<x<<endl
#define S(n) scanf("%lld", &n)
#define INF 1e18
#define MOD 1000000007

// #ifndef ONLINE_JUDGE
// #define gc getchar
// #define pc putchar
// #else
// #define gc getchar_unlocked
// #define pc putchar_unlocked
// #endif

using namespace std;

// int read_int() {
//     char c = gc();
//     while((c < '0' || c > '9') && c != '-') c = gc();
//     int ret = 0, neg = 0;
//     if (c == '-') neg = 1, c = gc();
//     while(c >= '0' && c <= '9') {
//         ret = 10 * ret + c - 48;
//         c = gc();
//     }
//     return neg ? -ret : ret;
// }

// ll read_ll() {
//     char c = gc();
//     while((c < '0' || c > '9') && c != '-') c = gc();
//     ll ret = 0;
//     int neg = 0;
//     if (c == '-') neg = 1, c = gc();
//     while(c >= '0' && c <= '9') {
//         ret = 10 * ret + c - 48;
//         c = gc();
//     }
//     return neg ? -ret : ret;
// }

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

struct trie_node {
    ll word_count;
    ll prefix_count;
    trie_node* edges[10];

    trie_node() {
        this->word_count = 0;
        this->prefix_count = 0;
        for(int i = 0; i < 10; i++) {
            this->edges[i] = NULL;
        }
    }
};

map<string, trie_node*> phonebook;
map<string, trie_node*>::iterator it;
map<string, vector<string> > ordered_phonebook;

void add_word(trie_node* &root, string &str, int index) {
    if (index == str.length()) {
        root->word_count += 1;
        return;
    }
    root->prefix_count += 1;
    int i = int(str[index] - '0'); 
    if (root->edges[i] == NULL) {
        root->edges[i] = new trie_node();
    }
    add_word(root->edges[i], str, index+1);
}

void printrev(string name, string str) {
	reverse(all(str));
	ordered_phonebook[name].pb(str);
	// int i, n =str.length();
	// FREV(i,n-1,0) {
	// 	printf("%c", str[i]);
	// }
	// printf(" ");
}

void store_nums(trie_node* root, string str, ll index, string name) 
{
  if (root==NULL) 
    return;
 
  /* append this node to the path array */
  str += ('0' + index);
 
  /* it's a leaf, so print the path that led to here  */
  ll i;
  bool flag = false;
  FOR(i,0,10) {
  	if (root->edges[i] != NULL) {
  		flag = true;
  		store_nums(root->edges[i], str, i, name);
  	}
  }
  if (flag == false) {
  	printrev(name, str);
  }
}

int main() {
	ll i,j,t,n, num;
	char s[20], ph[20];
	string str, phone;
	S(n);
	FOR(i,0,n) {
		scanf("%s", s);
		str = s;
		if (phonebook.find(str) == phonebook.end()) {
			phonebook[str] = new trie_node();
		}
		S(num);
		FOR(j,0,num) {
			scanf("%s", ph);
			phone = ph;
			reverse(all(phone));
			add_word(phonebook[str], phone, 0);
		}
	}
	printf("%lu\n", phonebook.size());
	for(it = phonebook.begin(); it != phonebook.end(); it++) {
		cout << it->first << " ";
		for(i=0;i<10;i++) {
			if (it->second->edges[i] != NULL) {
				store_nums(it->second->edges[i], "", i, it->first);
			}
		}
		printf("%lu ", ordered_phonebook[it->first].size());
		FOR(i,0,ordered_phonebook[it->first].size()) {
			cout << ordered_phonebook[it->first][i] << " ";
		}
		printf("\n");
	}
	return 0;
}