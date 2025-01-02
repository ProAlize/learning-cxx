#include "../exercise.h"
#include <cstring>
#include <memory>
#include <string>
#include <vector>
#include <iostream> // 添加用于调试的输出

// READ: `std::unique_ptr` <https://zh.cppreference.com/w/cpp/memory/unique_ptr>

std::vector<std::string> RECORDS;

class Resource {
    std::string _records;

public:
    void record(char record) {
        _records.push_back(record);
    }

    ~Resource() {
        RECORDS.push_back(_records);
    }
};

using Unique = std::unique_ptr<Resource>;

Unique reset(Unique ptr) {
    if (ptr) ptr->record('r');
    return std::make_unique<Resource>();
}

Unique drop(Unique ptr) {
    if (ptr) ptr->record('d');
    return nullptr;
}

Unique forward(Unique ptr) {
    if (ptr) ptr->record('f');
    return ptr;
}

int main(int argc, char **argv) {
    std::vector<std::string> problems[3];

    // 第一条操作
    drop(forward(reset(nullptr)));
    problems[0] = std::move(RECORDS);
    // 调试输出
    std::cout << "problems[0]: ";
    for(const auto &s : problems[0]) std::cout << s << " ";
    std::cout << std::endl;

    // 第二条操作
    forward(drop(reset(forward(forward(reset(nullptr))))));
    problems[1] = std::move(RECORDS);
    // 调试输出
    std::cout << "problems[1]: ";
    for(const auto &s : problems[1]) std::cout << s << " ";
    std::cout << std::endl;

    // 第三条操作
    drop(drop(reset(drop(reset(reset(nullptr))))));
    problems[2] = std::move(RECORDS);
    // 调试输出
    std::cout << "problems[2]: ";
    for(const auto &s : problems[2]) std::cout << s << " ";
    std::cout << std::endl;



    // ---- 不要修改以下代码 ----

    for (auto i = 0; i < 3; ++i) {
        ASSERT(problems[i].size() == answers[i].size(), "wrong size");
        for (auto j = 0; j < problems[i].size(); ++j) {
            ASSERT(std::strcmp(problems[i][j].c_str(), answers[i][j]) == 0, "wrong location");
        }
    }

    return 0;
}
