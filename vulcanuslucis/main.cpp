#include <iostream>

#include <vulcanuslucis/maths/matrix.hpp>

int main()
{
    std::cout << "Hello, world." << sizeof(void*) << '\n';

    constexpr maths::matrix i {{{1, 5}, {1, 6}}};
    constexpr int f = i.determinant();
    constexpr int fz = i[0][1];
    std::cout << f + fz;
    
    return 0;
}