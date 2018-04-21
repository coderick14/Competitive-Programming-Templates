/*
 * Deleted code is debugged code :)
 */
#include <bits/stdc++.h>
#define ll long
#define ull unsigned long long
#define vi vector<ll>
#define pp pair<ll,ll>
#define mp make_pair
#define PI acos(-1.0)
#define all(v) v.begin(),v.end()
#define pb push_back
#define FOR(i,a,b) for(i=a;i<b;i++)
#define FREV(i,a,b) for(i=a;i>=b;i--)
#define FORI(a) for(auto it=a.begin();it!=a.end();it++)
#define READ(a,i,n) FOR(i,0,n) { a[i] = read_ll();}
#define DEBUG(x) cerr<<"In file "<< __FILE__ <<" at line "<< __LINE__ <<" :: "<< #x <<" = "<<x<<endl
#define sll(n) scanf("%ld", &n)
#define si(n) scanf("%d", &n)
#define ss(n) scanf("%s", n)
#define INF 1e18
#define MOD 1000000007

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

/*******************************************RANDOM STUFF BEGINS HERE**************************************************/

struct node {
	vi val;
	node* left;
	node* right;

	node() {
		val.resize(50,0);
		this->left = this->right = NULL;
	}
};

ll n,q;
vi zero_vector(50,0);

void printresp(vi resp) {
	ll i;
	FOR(i,0,resp.size()) {
		cout << resp[i] << " ";
	}
	cout << endl;
}

node* build(ll l=0, ll r=n) {
	node* newnode = new node();
	if (l == r) {
		return newnode;
	}
	ll mid = l + (r-l)/2;
	newnode->left = build(l,mid);
	newnode->right = build(mid+1,r);
	return newnode;
}

void update(node* &root, ll &index, ll &newval, ll l = 0, ll r = n) {
	if (l == r) {
		// printf("Updated %ld to %ld. l = %ld  r = %ld\n", index, newval, l ,r);
		// printresp(root->val+49,50);
		root->val[49] = newval;
		// printresp(root->val+49,50);
		return;
	}
	ll mid = l + (r-l)/2;
	if (index <= mid) {
		update(root->left, index, newval, l, mid);
	}
	else {
		update(root->right, index, newval, mid+1, r);
	}
	ll i=49,j=49,k=49;
	while(k >= 0) {
		if (root->left->val[i] > root->right->val[j]) {
			root->val[k--] = root->left->val[i--];
		}
		else {
			root->val[k--] = root->right->val[j--];	
		}
	}
	// printf("Updated %ld to %ld. l = %ld  r = %ld\n", index, newval, l ,r);
	// printresp(root->val+49,50);
}

vi query(node* root, ll ql, ll qr, ll l = 0, ll r = n) {
	if (ql > r or qr < l or l > r) {
		return zero_vector;
	}
	if (ql <= l && r <= qr) {
        // cout<<l<<" "<<r<<endl;
        // cout << ";;;;;;;;;;;;;;;;;;\n";
        // printf("l : %ld  r : %ld\n", l, r);
        // printresp(root->val+49,50);
		return root->val;
	}

	ll mid = l + (r-l)/2;
	vi left = query(root->left, ql, qr, l, mid);
	vi right = query(root->right, ql, qr, mid+1,r);

	if (left == zero_vector) {
		return right;
	}
	if (right == zero_vector) {
		return left;
	}
	vi merged(50);
	
	ll i=49,j=49,k=49;
	// printf("Merging\n");
	// printresp(left);
	// printresp(right);
	while(k >= 0) {
		// printf("left : %ld right : %ld\n", *left, *right);
		if (left[i] > right[j]) {
			merged[k--] = left[i--];
		}
		else {
			merged[k--] = right[j--];
		}
		// printf("merged : %ld\n", merged[k+1]);
	}
	// printf("l : %ld  r : %ld\n", l, r);;
	// printresp(merged);
	return merged;
}

ll get_ans(vi resp) {
	ll i;
	FREV(i,resp.size()-1,2) {
		if (resp[i] < resp[i-1] + resp[i-2]) {
			// printf("Sides : %ld %ld %ld\n", resp[i], resp[i-1], resp[i-2]);
			return (resp[i] + resp[i-1] + resp[i-2]);
		}
	}
	return 0;
}

int main() {
	ll i,j,t,ql,qr,ch,idx,val;
	sll(n);sll(q);

	node* root = build();
	FOR(i,0,n) {
		sll(j);
		update(root,i,j);
	}
    FOR(i,0,q) {
    	sll(ch);
    	if (ch == 1) {
    		sll(idx);sll(val);
    		idx -= 1;
    		update(root, idx, val);
    	}
    	else {	
	        sll(ql);sll(qr);
	        ql -= 1; qr -= 1;
	        vi resp = query(root,ql,qr);
	        printf("%ld\n",get_ans(resp));
    	}
    }	
	return 0;
}