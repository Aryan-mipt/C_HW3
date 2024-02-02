#include <iostream>
using namespace std;
template <int N, int K>
struct Sm {
    static constexpr int value = N + Sm<N, K - 1>::value * N;
};

template <int N>
struct Sm<N, 1> {
    static constexpr int value = N;
};

int main() {
    constexpr int result = Sm<2, 3>::value;
    cout << "Sum: " << result << endl;

    return 0;
}