#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
    bool operator<(const Point& other) const {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }
};

long long cp(const Point& A, const Point& B, const Point& C) {
    return (long long)(B.x - A.x) * (C.y - A.y) - (long long)(B.y - A.y) * (C.x - A.x);
}

void solve(int case_num) {
    int n;
    if (!(cin >> n)) return;

    vector<Point> pts(n);
    for (int i = 0; i < n; ++i) {
        cin >> pts[i].x >> pts[i].y;
    }

    sort(pts.begin(), pts.end());
    pts.erase(unique(pts.begin(), pts.end()), pts.end());

    if (pts.size() < 3) {
        cout << "case " << case_num << ":\n";
        for (const auto& p : pts) cout << p.x << " " << p.y << endl ;
        return;
    }

    vector<Point> hull;
    for (int i = 0; i < pts.size(); ++i) {
        while (hull.size() >= 2 && cp(hull[hull.size() - 2], hull.back(), pts[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }

    size_t lower_size = hull.size();
    for (int i = (int)pts.size() - 2; i >= 0; --i) {
        while (hull.size() > lower_size && cp(hull[hull.size() - 2], hull.back(), pts[i]) <= 0) {
            hull.pop_back();
        }
        hull.push_back(pts[i]);
    }
    if (!hull.empty()) hull.pop_back();

    int start_idx = 0;
    for (int i = 1; i < hull.size(); ++i) {
        if (hull[i].y < hull[start_idx].y || (hull[i].y == hull[start_idx].y && hull[i].x < hull[start_idx].x)) {
            start_idx = i;
        }
    }

    cout << "case " << case_num << ":\n";
    for (size_t i = 0; i < hull.size(); ++i) {
        int idx = (start_idx + i) % hull.size();
        cout << hull[idx].x << " " << hull[idx].y << endl ;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int m; cin >> m ;
    
    for (int i = 1; i <= m; ++i) {
        solve(i);
    }
    
    return 0;
}