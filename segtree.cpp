#include <bits/stdc++.h>
#define MAXN 100000

vector<int> seg(4 * MAXN + 2), lazy(4 * MAXN + 2);

int left(int i) {
	return 2*i+1;
}

int right(int i) {
	return 2*i+2;
}

void propagate(int idx) {
	seg[idx] += lazy[idx];
	lazy[left(idx)] += lazy[idx];
	lazy[right(idx)] += lazy[idx];
	lazy[idx] = 0;
}

void radd(int ql, int qr, int val, int l, int r, int idx) {
	if (l > r) return;
	if (l != r) propagate(idx);

	if (ql > r or qr < l) return;

	if (ql <= l and r <= qr) {
		lazy[idx] += val;
		if (l != r) propagate(idx);
		return;
	}

	int m = l + (r - l) / 2;
	radd(ql, qr, val, l, m, left(idx));
	radd(ql, qr, val, m+1, r, right(idx));
}

void radd(int ql, int qr, int val, int n) {
	radd(ql, qr, val, 0, n-1, 0);
}

int pquery(int pos, int l, int r, int idx) {
	if (l == r) {
		seg[idx] += lazy[idx];
		lazy[idx] = 0;
		return seg[idx];
	}
	propagate(idx);
	int m = l + (r - l) / 2;
	if (pos <= m) return pquery(pos, l, m, left(idx));
	return pquery(pos, m+1, r, right(idx));
}

int pquery(int pos, int n) {
	return pquery(pos, 0, n-1, 0);
}

void add(int pos, int val, int l, int r, int idx) {
	if (l == r) {
		seg[idx] += val;
		return;
	}
	int m = l + (r - l) / 2;
	if (pos <= m) add(pos, val, l, m, left(idx));
	else add(pos, val, m+1, r, right(idx));
	seg[idx] += val;
}

void add(int pos, int val, int n) {
	add(pos, val, 0, n-1, 0);
}

int query(int ql, int qr, int l, int r, int idx) {
	if (ql > r or qr < l or l > r) return 0;
	if (ql <= l and r <= qr) return seg[idx];
	if (l == r) return seg[l];
	int m = l + (r - l) / 2;
	return query(ql, qr, l, m, left(idx)) + query(ql, qr, m+1, r, right(idx));
}

int query(int ql, int qr, int n) {
	return query(ql, qr, 0, n-1, 0);
}
