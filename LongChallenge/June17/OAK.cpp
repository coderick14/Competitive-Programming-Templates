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
#define SULL(n) scanf("%llu", &n)
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

struct treenode {
	vi adj;
};

struct node {
	node *left, *right;
	ll data;

	node(node* left, node* right, ll data) {
		this->left = left;
		this->right = right;
		this->data = data;
	}
};

vi start_time(100005), end_time(100005), parent(100005), span_parent(100005), capacity(100005), min_from_root(100005);
vector<treenode> tree;
ll timer = 0;
vector<node*> state(100005);

void build_trees(node* &root,ll l,ll r) {
    if (l==r) {
        root->data = 0;
        return;
    }
    ll mid = l + (r-l) / 2;
    root->left = new node(NULL, NULL, 0);
    root->right = new node(NULL, NULL, 0);
    build_trees(root->left, l, mid);
    build_trees(root->right, mid+1, r);
    root->data = root->left->data + root->right->data;
}

void range_update_tree(node* &prev, node* &cur, ll l, ll r, ll start, ll end) {
    if (l > end or  r < start or l > r)
        return;
    if (start <= l and r <= end) {
        cur->data = 0;
        return;
    }
    ll mid = l + (r-l) / 2;

    if (end <= mid) {
        cur->left = new node(NULL, NULL, 0);
        if (prev->data == 0) {
        	cur->right = new node(NULL, NULL, 0);
        	range_update_tree(cur->left,cur->left, l, mid, start, end);
        }
        else {
            cur->right = prev->right; 
            range_update_tree(prev->left,cur->left, l, mid, start, end);
        }
        
    }
    else if (start > mid) {
        cur->right = new node(NULL, NULL, 0);
        if (prev->data == 0) {
        	cur->left = new node(NULL, NULL, 0);
        	range_update_tree(cur->right,cur->right, mid+1, r, start, end);
        }
        else {
            cur->left = prev->left;
            range_update_tree(prev->right, cur->right, mid+1, r, start, end);   
        }
    }
    else {
        cur->left = new node(NULL, NULL, 0);
        cur->right = new node(NULL, NULL, 0);
        if (prev->data == 0) {
            range_update_tree(cur->left,cur->left, l, mid, start, end);
            range_update_tree(cur->right, cur->right, mid+1, r, start, end);
        }
        else {
            range_update_tree(prev->left,cur->left, l, mid, start, end);
            range_update_tree(prev->right, cur->right, mid+1, r, start, end);   
        }
    }

    cur->data = cur->left->data + cur->right->data;
}

void update_tree(node* &prev, node* &cur, ll l, ll r, ll idx, ll value) {
    if (idx > r or idx < l or l > r)
        return;
    if (l == r) {
        cur->data = value + prev->data;
        return;
    }
    ll mid = l + (r-l) / 2;
    if (idx <= mid) {
        cur->left = new node(NULL, NULL, 0);

        if (prev->data == 0) {
        	cur->right = new node(NULL, NULL, 0);
        	update_tree(cur->left,cur->left, l, mid, idx, value);
        }
        else {
	        cur->right = prev->right;
	        update_tree(prev->left,cur->left, l, mid, idx, value);
        }
    }
    else {
        cur->right = new node(NULL, NULL, 0);

        if (prev->data == 0) {
        	cur->left = new node(NULL, NULL, 0);
        	update_tree(cur->right,cur->right, mid+1, r, idx, value);
        }
        else {
	        cur->left = prev->left;
	        update_tree(prev->right,cur->right, mid+1, r, idx, value);
        }
    }
    cur->data = cur->left->data + cur->right->data;
}

ll query(node* root, ll low, ll high, ll start, ll end) {
    if (start > high or end < low or low > high)
       return 0;
    if (start <= low and high <= end)
       return root->data;
    if (root->data == 0) {
    	return 0;
    }
    ll mid = (low+high) / 2;
    ll p1 = query(root->left,low,mid,start,end);
    ll p2 = query(root->right,mid+1,high,start,end);
    return p1+p2;
}

void dfs(ll u, ll min_till_now) {
	ll i, v, len = tree[u].adj.size();
	min_from_root[u] = (capacity[u] < capacity[min_till_now] ? u : min_till_now);
	start_time[u] = ++timer;

	ll temp_u = u;
	while (span_parent[temp_u] != -1 && capacity[u] < capacity[span_parent[temp_u]]) {
		temp_u = span_parent[temp_u];
	}
	span_parent[u] = span_parent[temp_u];

	FOR(i,0,len) {
		v = tree[u].adj[i];
		dfs(v, min_from_root[u]);
	}
	end_time[u] = timer;
}

ll breaking_point(ll u, ll x, ll n, ll version) {
	ll query_u, query_spu, temp_u = u;
	
	while (temp_u != 0 && query(state[version], 1, n, start_time[min_from_root[temp_u]], end_time[min_from_root[temp_u]]) + x <= capacity[min_from_root[temp_u]]) {
		temp_u = parent[min_from_root[temp_u]];
	}

	if (temp_u == 0) {
		return -1;
	}
    
    u = temp_u;
	while (u != -1) {
		query_u = query(state[version], 1, n, start_time[u], end_time[u]);
		if (query_u + x > capacity[u])
			break;
		while (span_parent[u] != -1) {
			query_u = query(state[version], 1, n, start_time[u], end_time[u]);
			query_spu = query(state[version], 1, n, start_time[span_parent[u]], end_time[span_parent[u]]);
			if (query_u + x <= capacity[u] && query_spu + x > capacity[span_parent[u]])
				break;
			u = span_parent[u];
		}
		u = parent[u];
	}
	return u;
}

void print_tree(node* root, ll l, ll r) {
	if (root == NULL || l > r) {
		return;
	}
	ll mid = l + (r-l)/2;
    cout << "[" << l << "," << r << "] ---> " << root->data << endl;
	print_tree(root->left, l, mid);
	
	print_tree(root->right, mid+1, r);
}

int main() {
	ll i,j,t,n,q,prev_state,type,u,x;
	t = read_ll();
	while (t--) {
		n = read_ll();
		q = read_ll();
        tree.clear();
		tree.resize(n+1);
	    FOR(i,1,n+1) {
	        j = read_ll();
	        capacity[i] = read_ll();
	        tree[j].adj.pb(i);
	        span_parent[i] = parent[i] = j;
	    }
	    
	    capacity[0] = INF;
	    span_parent[0] = parent[0] = -1;

        timer = 0;
	    dfs(0,0);

	    // FOR(i,1,n+1) {
	    // 	cout << i << " min_node_from_root = " << min_from_root[i] << " span_parent = " << span_parent[i] <<  endl;
	    // }
	    state[0] = new node(NULL, NULL, 0);
	    build_trees(state[0], 1, n+1);
	    
	    FOR(i,1,q+1) {
	    	prev_state = read_ll();
	    	type = read_ll();

	    	state[i] = new node(NULL, NULL ,0);

	    	if (type == 1) {
	    		u = read_ll();
	    		x = read_ll();
                
	   		ll broken_node = breaking_point(u, x, n+1, prev_state);
            //std::cout << i << " ::::::::: " << broken_node << std::endl;
                
	    		if (broken_node == -1) {
	    			update_tree(state[prev_state], state[i], 1, n+1, start_time[u], x);
	    			printf("0\n");
	    		}
	    		else {
	    			range_update_tree(state[prev_state], state[i], 1, n+1, start_time[broken_node], end_time[broken_node]);
	    			printf("%lld\n", broken_node);
	    		}
	    	}
	    	else {
	    		u = read_ll();
	    		ll query_ans = query(state[prev_state], 1, n+1, start_time[u], end_time[u]);
	    		printf("%lld\n", query_ans);

	    		range_update_tree(state[prev_state], state[i], 1, n+1, start_time[u], end_time[u]);
	    	}
            // cout << "================================================\n";
            // print_tree(state[i], 1, n+1);
            // cout << "================================================\n";
	    }
	}
	return 0;
}