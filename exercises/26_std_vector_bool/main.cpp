#include "../exercise.h"
#include <vector>
#include <iostream> // 确保包含 <iostream> 以使用 std::cout

// READ: std::vector <https://zh.cppreference.com/w/cpp/container/vector_bool>
// READ: 模板特化 <https://zh.cppreference.com/w/cpp/language/template_specialization>

// TODO: 将下列 `?` 替换为正确的代码
int main(int argc, char **argv) {
    // 初始化一个包含100个 `true` 的 std::vector<bool>
    std::vector<bool> vec(100, true); // 正确调用构造函数
    ASSERT(vec[0], "Make this assertion pass.");    // vec[0] 应该为 true
    ASSERT(vec[99], "Make this assertion pass.");   // vec[99] 应该为 true
    ASSERT(vec.size() == 100, "Make this assertion pass."); // 大小应该为 100

    // NOTICE: 平台相关！注意 CI:Ubuntu 上的值。
    std::cout << "sizeof(std::vector<bool>) = " << sizeof(std::vector<bool>) << std::endl;
    ASSERT(sizeof(vec) == 40, "Fill in the correct value."); // 根据您的输出，大小为 40 字节

    {
        vec[20] = false; // 将第21个元素设为 false
        ASSERT(!vec[20], "Fill in `vec[20]` or `!vec[20]`."); // vec[20] 现在应该为 false
    }
    {
        vec.push_back(false); // 在末尾添加一个 `false`
        ASSERT(vec.size() == 101, "Fill in the correct value."); // 大小现在应为 101
        ASSERT(!vec[100], "Fill in `vec[100]` or `!vec[100]`."); // 新添加的元素应为 false
    }
    {
        auto ref = vec[30]; // 获取第31个元素的引用
        ASSERT(ref, "Fill in `ref` or `!ref`"); // 初始时 vec[30] 应为 true
        ref = false; // 将引用设为 false
        ASSERT(!ref, "Fill in `ref` or `!ref`"); // ref 现在应为 false
        // THINK: WHAT and WHY?
        ASSERT(!vec[30], "Fill in `vec[30]` or `!vec[30]`."); // vec[30] 应反映更改，变为 false
    }
    return 0;
}
