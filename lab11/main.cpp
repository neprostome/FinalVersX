#include "utils/xrange.h"
#include "utils/zip.h"

#include <iostream>
#include <vector>
#include <list>

int main() {
    auto x = xrange(1.5, 5.5);
    std::vector<int> v{x.begin(), x.end()}; // 1.5 2.5 3.5 4.5

    auto x2 = xrange(4);
    std::vector<int> v2{x.begin(), x.end()}; // 0 1 2 3

    // 1 3 5
    for(auto i : xrange(1, 6, 2)) {
        std::cout << i <<  " ";
    }
    
    std::cout << std::endl;

    std::list l = {1, 2, 3, 4, 5};
    std::vector v3 = {"a", "b", "c", "d"};
    /*
    1 a
    2 b
    3 c
    4 d
    */
    for(auto value : zip(l, v)) {
        std::cout << value.first << " " << value.second << std::endl;
    }

    return 0;
}
