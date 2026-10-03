#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

bool compareX(const Point& a, const Point& b) {
    if (a.x != b.x) return a.x < b.x;
    return a.y < b.y;
}

bool compareY(const Point& a, const Point& b) {
    return a.y < b.y;
}

double dist(const Point& a, const Point& b) {
    return sqrt(static_cast<double>(a.x - b.x) * (a.x - b.x) + 
                static_cast<double>(a.y - b.y) * (a.y - b.y));
}

double work(vector<Point>& points, int left, int right) {
    if (left + 1 == right) return dist(points[left], points[right]);
    
    if (left + 2 == right) {
        return min({dist(points[left], points[left+1]), 
                    dist(points[left+1], points[right]), 
                    dist(points[left], points[right])});
    }

    int mid = left + (right - left) / 2;
    int midX = points[mid].x;

    double dl = work(points, left, mid);
    double dr = work(points, mid + 1, right);
    double d = min(dl, dr);

    vector<Point> strip;
    for (int i = left; i <= right; i++) {
        if (abs(points[i].x - midX) < d) {
            strip.push_back(points[i]);
        }
    }

    sort(strip.begin(), strip.end(), compareY);

    for (size_t i = 0; i < strip.size(); i++) {
        for (size_t j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < d; j++) {
            d = min(d, dist(strip[i], strip[j]));
        }
    }

    return d;
}

void solve() {
    int n;
    cin >> n ;
    
    vector<Point> points(n);
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    sort(points.begin(), points.end(), compareX);

    double ans = work(points, 0, n - 1);
    printf("%.2f\n", ans) ;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t ;
    while (t--) {
        solve();
    }
    
    return 0;
}