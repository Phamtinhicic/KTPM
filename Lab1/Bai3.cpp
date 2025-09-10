#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

// ================== Hàm solveQuartic (theo ??) ==================
int solveQuartic(double a, double b, double c, double x[]) {
    if (a == 0) {
        if (b == 0) {
            if (c == 0) return -1;  // vô s? nghi?m
            else return 0;         // vô nghi?m
        }
        else {
            double y = -c / b;
            if (y < 0) return 0;
            else {
                x[0] = sqrt(y);
                x[1] = -sqrt(y);
                return 2;
            }
        }
    }
    else {
        double delta = b * b - 4 * a * c;
        if (delta < 0) return 0;
        double y1 = (-b + sqrt(delta)) / (2 * a);
        double y2 = (-b - sqrt(delta)) / (2 * a);
        int n = 0;
        if (y1 >= 0) {
            x[n++] = sqrt(y1);
            x[n++] = -sqrt(y1);
        }
        if (y2 >= 0 && y2 != y1) {
            x[n++] = sqrt(y2);
            x[n++] = -sqrt(y2);
        }
        return n;
    }
}

// ================== Hàm so sánh nghi?m (không c?n th? t?) ==================
bool compareSolutions(const vector<double>& got, const vector<double>& expected, double eps = 1e-6) {
    if (got.size() != expected.size()) return false;
    vector<bool> used(expected.size(), false);
    for (double g : got) {
        bool ok = false;
        for (size_t i = 0; i < expected.size(); i++) {
            if (!used[i] && fabs(g - expected[i]) < eps) {
                used[i] = true;
                ok = true;
                break;
            }
        }
        if (!ok) return false;
    }
    return true;
}

// ================== C?u trúc test-case ==================
struct TestCase {
    double a, b, c;
    int expectedCount;
    vector<double> expectedRoots;
    string desc;
};

int main() {
    // Danh sách test-case
    vector<TestCase> tests = {
        {0,0,0,-1,{},"Vo so nghiem"},
        {0,0,1,0,{},"Vo nghiem"},
        {0,1,-4,2,{2,-2},"Bac nhat y=4"},
        {0,1,0,2,{0,0},"Bac nhat y=0"},
        {1,0,-1,2,{1,-1},"y^2 - 1 = 0"},
        {1,-2,1,2,{1,-1},"Delta = 0"},
        {1,0,1,0,{},"Delta < 0"},
        {1,-5,4,4,{2,-2,1,-1},"4 nghiem thuc"}
    };

    int passed = 0;
    for (size_t i = 0; i < tests.size(); i++) {
        double x[4];
        int n = solveQuartic(tests[i].a, tests[i].b, tests[i].c, x);
        vector<double> got;
        for (int j = 0; j < n; j++) got.push_back(x[j]);

        cout << "Test " << i + 1 << " (" << tests[i].desc << "): ";
        if (n == tests[i].expectedCount &&
            compareSolutions(got, tests[i].expectedRoots)) {
            cout << "PASS" << endl;
            passed++;
        }
        else {
            cout << "FAIL (got n=" << n << ", expected n=" << tests[i].expectedCount << ")" << endl;
            if (n > 0) {
                cout << "  Roots got: ";
                for (double r : got) cout << r << " ";
                cout << endl;
            }
        }
    }

    cout << "==> Passed " << passed << "/" << tests.size() << " test cases." << endl;
    return 0;
}
