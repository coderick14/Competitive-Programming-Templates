// Taken from https://github.com/chemthan/chemthan/blob/master/Computational%20Geometry/ConvexHull.cpp
#include <bits/stdc++.h>
using namespace std;

#define RL double
#define EPS 1e-9
struct point_t {
    RL x, y;
    point_t() : x(0), y(0) {}
    point_t(RL x, RL y) : x(x), y(y) {}
    point_t(const point_t& p) : x(p.x), y(p.y) {}
    int operator < (const point_t& rhs) const {return make_pair(y, x) < make_pair(rhs.y, rhs.x);}
    int operator == (const point_t& rhs) const {return make_pair(y, x) == make_pair(rhs.y, rhs.x);}
    point_t operator + (const point_t& p) const {return point_t(x + p.x, y + p.y);}
    point_t operator - (const point_t& p) const {return point_t(x - p.x, y - p.y);}
    point_t operator * (RL c) const {return point_t(x * c, y * c);}
    point_t operator / (RL c) const {return point_t(x / c, y / c);}
};
RL cross(point_t p, point_t q) {return p.x * q.y - p.y * q.x;}
RL area(point_t a, point_t b, point_t c) {return fabs(cross(a, b) + cross(b, c) + cross(c, a)) / 2;}
// ans > 0 => counterclockwise, ans < 0 => clockwise, ans = 0 => collinear
RL area2(point_t a, point_t b, point_t c) {return cross(a, b) + cross(b, c) + cross(c, a);}
RL dot(point_t p, point_t q) {return p.x * q.x + p.y * q.y;}
RL dist(point_t p, point_t q) {return sqrt(dot(p - q, p - q));}
RL dist2(point_t p, point_t q) {return dot(p - q, p - q);}
point_t RotateCCW90(point_t p) {return point_t(-p.y, p.x);}
point_t RotateCW90(point_t p) {return point_t(p.y, -p.x);}
point_t RotateCCW(point_t p, RL t) {return point_t(p.x * cos(t) - p.y * sin(t), p.x * sin(t) + p.y * cos(t));}
int sign(RL x) {return x < -EPS ? -1 : x > EPS;}
int sign(RL x, RL y) {return sign(x - y);}
ostream& operator << (ostream& os, const point_t& p) {
    os << "(" << p.x << "," << p.y << ")";
    return os;
}

// Returns points of the convex hull in counterclockwise order in O(nlgn)
void ConvexHull(vector<point_t>& pts) {
    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());
    vector<point_t> up, dn;
    for (int i = 0; i < pts.size(); i++) {
        // If we want to include collinear points in the hull (i.e. points lying on the boundary),
        // make the inequality checks strict.
        while (up.size() > 1 && area2(up[up.size() - 2], up.back(), pts[i]) >= 0) up.pop_back();
        while (dn.size() > 1 && area2(dn[dn.size() - 2], dn.back(), pts[i]) <= 0) dn.pop_back();
        up.push_back(pts[i]);
        dn.push_back(pts[i]);
    }
    pts = dn;
    for (int i = up.size() - 2; i >= 1; i--) pts.push_back(up[i]);
}

int main() {
    int n = 10;
    vector<point_t> pts;
    for (int i = 0; i < n; i++) {
        pts.push_back(point_t(rand() % 100, rand() % 100));
    }
    cout << "Points:\n";
    for (const auto& pt : pts) cout << pt << " ";
    ConvexHull(pts);
    cout << "\nHull:\n";
    for (const auto& pt : pts) cout << pt << " ";
    return 0;
}