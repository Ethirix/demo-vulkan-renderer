#ifndef VULCANUSLUCIS_MATRIX_IPP
#define VULCANUSLUCIS_MATRIX_IPP

#include <memory>

#include <vulcanuslucis/maths/matrix.hpp>

namespace maths
{
    template <typename Type, std::size_t Rows, std::size_t Columns> requires (std::is_arithmetic_v<Type> && Rows > 1 &&
        Columns >= 1)
    constexpr matrix<Type, Rows, Columns>::matrix()
    {
        if constexpr (Rows != Columns) return;
        
        for (std::size_t x = 0; x < Rows || x < Columns; x++)
        {
            arr_[x][x] = 1;
        }
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> requires (std::is_arithmetic_v<Type> && Rows > 1 &&
        Columns >= 1)
    constexpr matrix<Type, Rows, Columns>::matrix(std::array<std::array<Type, Columns>, Rows> array)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                arr_[x][y] = array[x][y];
            }
        }
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> requires (std::is_arithmetic_v<Type> && Rows > 1 &&
        Columns >= 1)
    constexpr matrix<Type, Rows, Columns>::matrix(const Type(&matrix)[Rows][Columns])
    {
        for (std::size_t row = 0; row < Rows; row++)
        {
            for (std::size_t column = 0; column < Columns; column++)
            {
                arr_[row][column] = matrix[row][column];
            }
        }
    }
    
    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    matrix<Type, Rows, Columns>::operator std::array<std::array<Type, Columns>, Rows>() const
    {
        return arr_;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr std::array<Type, Columns> matrix<Type, Rows, Columns>::operator[](std::size_t index)
    {
        return arr_[index];
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> requires (std::is_arithmetic_v<Type> && Rows > 1 &&
        Columns >= 1)
    constexpr std::array<Type, Columns> matrix<Type, Rows, Columns>::operator[](std::size_t index) const
    {
        return arr_[index];
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns> matrix<Type, Rows, Columns>::operator+(const matrix& other)
    {
        matrix m = {};
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                m[x][y] = arr_[x][y] + other[x][y];
            }
        }
            
        return m;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns> matrix<Type, Rows, Columns>::operator-(const matrix& other)
    {
        matrix m = {};
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                m[x][y] = arr_[x][y] - other[x][y];
            }
        }
            
        return m;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns> matrix<Type, Rows, Columns>::operator*(const matrix& other)
    {
        matrix m = {};
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                m[x][y] = arr_[x][y] * other[x][y];
            }
        }
            
        return m;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns> matrix<Type, Rows, Columns>::operator/(const matrix& other)
    {
        matrix m = {};
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                m[x][y] = arr_[x][y] / other[x][y];
            }
        }
            
        return m;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns>& matrix<Type, Rows, Columns>::operator+=(const matrix& other)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                arr_[x][y] += other[x][y];
            }
        }
            
        return *this;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns>& matrix<Type, Rows, Columns>::operator-=(const matrix& other)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                arr_[x][y] -= other[x][y];
            }
        }
            
        return *this;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns>& matrix<Type, Rows, Columns>::operator*=(const matrix& other)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                arr_[x][y] *= other[x][y];
            }
        }
            
        return *this;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr matrix<Type, Rows, Columns>& matrix<Type, Rows, Columns>::operator/=(const matrix& other)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                arr_[x][y] /= other[x][y];
            }
        }
            
        return *this;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr bool matrix<Type, Rows, Columns>::operator==(const matrix& other)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                if (arr_[x][y] != other[x][y])
                    return false;
            }
        }
            
        return true;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr bool matrix<Type, Rows, Columns>::operator!=(const matrix& other)
    {
        for (std::size_t x = 0; x < Rows; x++)
        {
            for (std::size_t y = 0; y < Columns; y++)
            {
                if (arr_[x][y] == other[x][y])
                    return true;
            }
        }
            
        return false;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr Type matrix<Type, Rows, Columns>::determinant() const
    {
        if constexpr (Rows != Columns)
        {
            return 0;
        }
        if constexpr (Rows == 2 && Columns == 2)
        {
            return arr_[0][0] * arr_[1][1] - arr_[1][0] * arr_[0][1];
        }
        
        // Laplace Expansion (modified to stop infinitely recurring templates)
        Type det = 0;
        for (std::size_t column = 0; column < Columns; column++)
        {
            std::array<std::array<Type, Columns - 1>, Rows - 1> minor = get_minor(column);
            
            Type minorDet = 0;
            if constexpr (Rows > 3 && Columns > 3)
            {
                minorDet = static_cast<matrix<Type, Rows - 1, Columns - 1>>(minor).determinant();
            }
            else
            {
                minorDet = minor[0][0] * minor[1][1] - minor[1][0] * minor[0][1];
            }
            
            int sign = column % 2 == 0 ? 1 : -1;
            det += sign * arr_[0][column] * minorDet;
        }
        
        return det;
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> requires (std::is_arithmetic_v<Type> && Rows > 1 &&
        Columns >= 1)
    constexpr matrix<Type, Rows, Columns> matrix<Type, Rows, Columns>::inverse() const
    {
        Type det = determinant();
        if (det == 0)
            return {};
        
        //https://semath.info/src/inverse-cofactor-ex4.html
        
        return {};
    }

    template <typename Type, std::size_t Rows, std::size_t Columns> 
        requires (std::is_arithmetic_v<Type> && Rows > 1 && Columns >= 1)
    constexpr std::array<std::array<Type, Columns - 1>, Rows - 1> 
        matrix<Type, Rows, Columns>::get_minor(const std::size_t x) const
    {
        std::array<std::array<Type, Columns - 1>, Rows - 1> out;
        for (std::size_t row = 1; row < Rows; row++)
        {
            for (std::size_t column = 0; column < Columns - 1; column++)
            {
                const bool offset = column >= x;
                out[row - 1][column] = arr_[row][column + offset];
            }
        }
        
        return out;
    }
}

#endif
