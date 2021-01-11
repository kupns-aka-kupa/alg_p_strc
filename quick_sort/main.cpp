#include <iostream>
#include <chrono>
#include <algorithm>

#define ELAPSED(f) {auto time = std::chrono::system_clock::now();f; \
auto end_time = std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::system_clock::now() - time); \
std::cout << "Elapsed: " << end_time.count() << " mks" << std::endl;}

void print(int *p, int s) {
    for (int i = 0; i < s; i++) {
        std::cout << p[i] << ", ";
    }
    std::cout << std::endl;
}

/**
 *  @usage  quick_sort(ref, 0, s - 1);
 *          quick_sort(ref, 0, s - 1, std::greater());
 *  @brief  Return __p.
 *  @param  __p  Pointer to array.
 *  @param  s  Start index.
 *  @param  e  End index.
 *  @param  cmp  Comparer.
 */
template<typename T, typename Comparer = std::less<T>>
T* quick_sort(T* __p, int s, int e, Comparer cmp = Comparer()) {
    if(s >= e) return __p;
    int m = s;

    for (int i = s; i <= e; i++) {
        if (!cmp(__p[i], __p[e])) continue;
        std::swap(__p[m++], __p[i]);
    }
    std::swap(__p[m], __p[e]);

    quick_sort(__p, s, m - 1, cmp);
    quick_sort(__p, m + 1, e, cmp);
    return __p;
}

/**
 *  @brief  Return __p.
 *  @param  p  Pointer to array.
 *  @param  n  Heap size.
 *  @param  cmp  Comparer.
 */
template<typename T, typename Comparer = std::less<T>>
T* heapify(T* p, int n, int i, Comparer cmp = Comparer()) {

    static auto compare = [&](const T* a, const T* b) {
        if (b - p >= n) return false;
        return cmp(*a, *b);
    };

    T* array[] = {p + i, p + 2 * i + 1, p + 2 * i + 2};
    auto l = std::max_element(array, array + 3, compare);

    if(*l - p != i) {
        std::swap(**l, p[i]);
        heapify(p, n, *l - p, cmp);
    }

    return p;
}

/**
 *  @usage  heap_sort(ref, size);
 *          heap_sort(ref, size, std::greater());
 *  @brief  Return __p.
 *  @param  p  Pointer to array.
 *  @param  n  Array size.
 *  @param  cmp  Comparer.
 */
template<typename T, typename Comparer = std::less<T>>
T* heap_sort(T* __p, int n, Comparer cmp = Comparer()) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(__p, n, i, cmp);

    for (int i = n - 1; i >= 0; i--) {
        std::swap(__p[0], __p[i]);
        heapify(__p, i, 0, cmp);
    }
    return __p;
}

int main() {
    srand((unsigned)time(nullptr));
    int array []{32, 54, 87, 57, 11, 90, 0, 64, 88, 34, 7};

    std::cout << "Original:\n";
    int s = std::size(array);
    print(array, s);

    ELAPSED(heap_sort(array, s));
//    quick_sort(array, 0, s - 1);
//    quick_sort(array, 0, s - 1, std::greater());

    std::cout << "Sorted:\n";
    print(array, s);

    return 0;
}
