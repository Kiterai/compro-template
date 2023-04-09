#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
using namespace std;

struct {
    std::mt19937_64 mt{std::random_device()()};
    int64_t operator()(int64_t mn, int64_t mx) { return std::uniform_int_distribution<int64_t>(mn, mx)(mt); }
} Rand;

void gencase() {
    // output testcase to cout
    cout << Rand(0, 1'000'000'000) << endl;
}

void solve() {
    // solve
    int n;
    cin >> n;
    cout << n * 2 << endl;
}

bool validate(ifstream &out) {
    ostringstream outss, vss;
    outss << out.rdbuf();
    auto defout = cout.rdbuf();
    cout.rdbuf(vss.rdbuf());
    solve();
    cout.rdbuf(defout);
    return outss.str() == vss.str();
}

int main() {
    auto defout = cout.rdbuf();
    auto defin = cin.rdbuf();
    int wa = 0;
    for (int _ = 0; _ < 100; _++) {
        {
            ofstream ofs(R"(test\test.txt)");
            cout.rdbuf(ofs.rdbuf());
            gencase();
            cout.rdbuf(defout);
            if (ofs.tellp() == 0)
                cout << "empty case" << endl;
        }
        std::system(R"(.\build\Debug\compro < test\test.txt > test\out.txt)");
        {
            ifstream ifs(R"(test\test.txt)");
            ifstream outifs(R"(test\out.txt)");
            cin.rdbuf(ifs.rdbuf());
            if (!validate(outifs)) {
                ifs.seekg(0);
                outifs.seekg(0);
                wa++;
                cout << "WA" << endl;
                cout << "testcase:\n" << ifs.rdbuf() << endl;
                cout << "output:\n" << outifs.rdbuf() << endl;
            }
            cin.rdbuf(defin);
        }
    }
    if (wa > 0)
        cout << "WA: " << wa << endl;
    else
        cout << "all test passed" << endl;
}
