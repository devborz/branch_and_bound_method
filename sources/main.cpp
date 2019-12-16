#include <iostream>
#include <vector>
using namespace std;

double iterate_variations(const vector<vector<double>>& a,
                                  const vector<double>& b,
                                  const vector<double>& c,
                                  vector<unsigned int>& x) {
    double b_max = b[0];
    double f_max = 0;

    for (const auto& e: b) {
        if (e > b_max) {
            b_max = e;
        }
    }

    for (int i = 0; i <= b_max; i++) {
        for (int j = 0; j <= b_max; j++) {
            for (int k = 0; k <= b_max; k++) {
                bool inequality_1 = false;
                bool inequality_2 = false;
                bool inequality_3 = false;

                if (a[0][0] * i + a[0][1] * j + a[0][2] * k <= b[0]) {
                    inequality_1 = true;
                }
                if (a[1][0] * i + a[1][1] * j + a[1][2] * k <= b[1]) {
                    inequality_2 = true;
                }
                if (a[2][0] * i + a[2][1] * j + a[2][2] * k <= b[2]) {
                    inequality_3 = true;
                }

                if (inequality_1 && inequality_2 && inequality_3) {
                    int f = c[0] * i + c[1] * j + c[2] * k;
                    std::cout << "F = " << f << " x1=" << i << " x2=" << j
                              << " x3=" << k << std::endl;
                    if (f > f_max) {
                        f_max = f;
                        x[0] = i;
                        x[1] = j;
                        x[2] = k;
                    }
                }
            }
        }
    }

    return f_max;
}

int main() {
    vector<double> c = {1, 3, 8};
    vector<vector<double>> a = {{1,  1,  1},
                                {1,  1,  0},
                                {0, 0.5, 2}};
    vector<double> b = {7, 2, 4};
    vector<unsigned int> x;
    x.resize(3);

    int f_max = iterate_variations(a, b, c, x);
    
    std::cout << "MAX: F = " << f_max << " x1=" << x[0] << " x2=" << x[1]
              << " x3=" << x[2] << std::endl;
}
