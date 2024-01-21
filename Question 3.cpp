#include <iostream>
using namespace std;
template <typename T>
struct rm {
    using type = T;
};

template <typename T>
struct rm<const T> {
    using type = T;
};

template <typename T>
struct rm<volatile T> {
    using type = T;
};

template <typename T>
struct rm<const volatile T> {
    using type = T;
};

template <typename T>
struct rmAll {
    using type = typename rm<T>::type;
};

template <typename T>
struct rmAll<T*> {
    using type = typename rmAll<T>::type;
};

template <typename T>
struct rmAll<T&> {
    using type = typename rmAll<T>::type;
};

template <typename T>
struct rmAll<T&&> {
    using type = typename rmAll<T>::type;
};

int main() {
    using Otype = const int* const;
    using Mtype = rmAll<Otype>::type;

    cout << "Original type: " << typeid(Otype).name() << endl;
    cout << "Modified type: " << typeid(Mtype).name() << endl;

    return 0;
}
