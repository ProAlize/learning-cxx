#include "../exercise.h"
#include <numeric>
#include <functional> // Required for std::multiplies

// READ: `std::accumulate` <https://zh.cppreference.com/w/cpp/algorithm/accumulate>

int main(int argc, char **argv) {
    using DataType = float;
    int shape[]{1, 3, 224, 224};
    
    // Calculate the total number of elements in the tensor
    // std::accumulate takes the range [shape, shape + 4)
    // The initial value is 1, and we use std::multiplies to compute the product
    int total_elements = std::accumulate(shape, shape + 4, 1, std::multiplies<int>());
    
    // Calculate the total number of bytes
    // Multiply the total number of elements by the size of the data type
    int size = total_elements * sizeof(DataType);
    
    // Alternatively, you can perform the calculation in a single line:
    // int size = std::accumulate(shape, shape + 4, 1, std::multiplies<int>()) * sizeof(DataType);
    
    // Assertions to verify the result
    ASSERT(size == 602112, "4x1x3x224x224 = 602112");
    
    return 0;
}
