#include <iostream>
#include <stack>

enum class errorCode {
    success,
    fail
};

//T1A
errorCode copyStack(std::stack<int> original, std::stack<int> dest) {
    if (original.empty()) {
        return errorCode::fail;
    } else {
        dest = original;
        return errorCode::success;
    }
}
int main() {
    std::stack<int> original{};
    //Lisätään pinoon ensin numeroita
    for (int i{0}; i < 10; ++i) {
        original.push(i);
    }

    std::stack<int> dest{};

    errorCode result = copyStack(original, dest);

    if (result == errorCode::success) {
        std::cout << "Kopiointi onnistui.\n";
    }else {
        std::cout << "Kopiointi epäonnistui.\n";
    }
    return 0;
}
