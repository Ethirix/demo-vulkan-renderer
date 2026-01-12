#include <iostream>

#include <vulcanuslucis/maths/matrix.hpp>

int main()
{
    std::cout << "Hello, world." << sizeof(void*) << '\n';

    constexpr maths::matrix i {{{1.0f, 1.0f, 1.0f, -1.0f}, {1.0f, 1.0f, -1.0f, 1.0f}, 
                                {1.0f, -1.0f, 1.0f, 1.0f}, {-1.0f, 1.0f, 1.0f, 1.0f}}};
    constexpr int f = i.determinant();
    constexpr int fz = i[0][1];
    std::cout << f << '\n';
    constexpr maths::matrix inv = i.inverse();
    for (std::size_t row = 0; row < 4; row++)
    {
        for (std::size_t column = 0; column < 4; column++)
        {
            std::cout << inv[row][column] << ' ';
        }
        std::cout << '\n';
    }
    
    return 0;
}