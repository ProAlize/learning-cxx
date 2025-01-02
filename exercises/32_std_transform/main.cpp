#include "../exercise.h"
#include <algorithm>
#include <string>
#include <vector>
#include <sstream>

// READ: `std::transform` <https://zh.cppreference.com/w/cpp/algorithm/transform>
// READ: `std::vector::begin` <https://zh.cppreference.com/w/cpp/container/vector/begin>

int main(int argc, char **argv) {
    std::vector<int> val{8, 13, 21, 34, 55};
    
    // Initialize `ans` with the same size as `val` to ensure enough space
    std::vector<std::string> ans(val.size());

    // Use `std::transform` to multiply each element by 2 and convert to string
    std::transform(val.begin(), val.end(), ans.begin(), [](int x) -> std::string {
        return std::to_string(x * 2);
    });


    // Assertions to verify the results
    ASSERT(ans.size() == val.size(), "ans size should be equal to val size");
    ASSERT(ans[0] == "16", "ans[0] should be 16");
    ASSERT(ans[1] == "26", "ans[1] should be 26");
    ASSERT(ans[2] == "42", "ans[2] should be 42");
    ASSERT(ans[3] == "68", "ans[3] should be 68");
    ASSERT(ans[4] == "110", "ans[4] should be 110");

    return 0;
}
