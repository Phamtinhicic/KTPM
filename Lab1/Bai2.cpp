#include <iostream>
#include <cmath>
using namespace std;

// ================== a) f1 ==================
int f1(int x) {
    if (x > 10)
        return 2 * x;
    else
        return -x;
}

void test_f1(int input, int expected) {
    int output = f1(input);
    cout << "f1(" << input << ") -> got: " << output
        << ", expected: " << expected << " => "
        << (output == expected ? "PASS" : "FAIL") << endl;
}

// ================== b) f1_buggy ==================
int f1_buggy(int x) {
    if (x > 10)
        return 2 * x;
    else if (x > 0)
        return -x;
    else
        return 2 * x;
}

void test_f1_buggy(int input, int expected) {
    int output = f1_buggy(input);
    cout << "f1_buggy(" << input << ") -> got: " << output
        << ", expected: " << expected << " => "
        << (output == expected ? "PASS" : "FAIL") << endl;
}

// ================== c) f2 ==================
int f2(int x) {
    if (x < 10)
        return 2 * x;
    else if (x < 2)
        return -x;
    else
        return 2 * x;
}

void test_f2(int input, int expected) {
    int output = f2(input);
    cout << "f2(" << input << ") -> got: " << output
        << ", expected: " << expected << " => "
        << (output == expected ? "PASS" : "FAIL") << endl;
}

// ================== d) f3 ==================
int f3(int x) {
    if (log(x * x * cos(x)) < 3 * x)
        return 2 * x;
    else
        return 2 * x;
}

void test_f3(int input, int expected) {
    try {
        int output = f3(input);
        cout << "f3(" << input << ") -> got: " << output
            << ", expected: " << expected << " => "
            << (output == expected ? "PASS" : "FAIL") << endl;
    }
    catch (...) {
        cout << "f3(" << input << ") -> runtime error (log domain)" << endl;
    }
}

// ================== e) findMax_buggy ==================
int findMax_buggy(int num1, int num2, int num3) {
    int max = 0;
    if ((num1 > num2) && (num1 > num3))
        max = num1;
    if ((num2 > num1) && (num2 > num3))
        max = num2;
    if ((num3 > num1) && (num3 > num2))
        max = num3;
    return max;
}

void test_findMax_buggy(int a, int b, int c, int expected) {
    int output = findMax_buggy(a, b, c);
    cout << "findMax_buggy(" << a << "," << b << "," << c << ") -> got: "
        << output << ", expected: " << expected << " => "
        << (output == expected ? "PASS" : "FAIL") << endl;
}

// ================== MAIN ==================
int main() {
    cout << "===== Test-case Bài II =====" << endl;

    // a) f1
    cout << "\n[a] Test f1" << endl;
    test_f1(11, 22);   // nhánh true
    test_f1(10, -10);  // nhánh false

    // b) f1_buggy
    cout << "\n[b] Test f1_buggy" << endl;
    test_f1_buggy(11, 22);   // ?úng
    test_f1_buggy(5, -5);    // ?úng
    test_f1_buggy(-1, 1);    // FAIL (bug)

    // c) f2
    cout << "\n[c] Test f2" << endl;
    test_f2(1, -1);   // ý ??nh: -1 (code hi?n t?i sai)
    test_f2(5, 10);   // ?úng
    test_f2(10, 20);  // ?úng

    // d) f3
    cout << "\n[d] Test f3" << endl;
    test_f3(1, 2);   // h?p l? -> 2
    test_f3(0, 0);   // log(0) -> runtime error
    test_f3(3, 6);   // cos(3)<0 -> log âm -> runtime error

    // e) findMax_buggy
    cout << "\n[e] Test findMax_buggy" << endl;
    test_findMax_buggy(3, 2, 1, 3);     // ?úng
    test_findMax_buggy(3, 3, 1, 3);     // FAIL (bug tie)
    test_findMax_buggy(-1, -2, -3, -1); // FAIL (bug s? âm)

    return 0;
}
