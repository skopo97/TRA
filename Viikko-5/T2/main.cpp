#include <iostream>
#include <stack>

enum class errorCode {
    success,
    pop_top_success,
    fail,
    pop_top_fail,
};

using Stack_entry = int;
//T2A
bool full(std::stack<int> &stack, size_t maxSize) {
    return stack.size() == maxSize;
}

//T2B
errorCode pop_top(std::stack<int> &stack, Stack_entry &t) {
    if (stack.empty()) {
        return errorCode::pop_top_fail;
    }
    t = stack.top();
    stack.pop();
    return errorCode::pop_top_success;
}

//T3C
void clear(std::stack<int> &stack) {
    while (!stack.empty()) {
        stack.pop();
    }
    std::cout << "Stack cleared.\n";
}

//T3D
int size(std::stack<int> &stack) {
    int size = static_cast<int>(stack.size());
    return size;
}

//T3E
void delete_all(std::stack<int> &stack, Stack_entry x) {
    std::stack<int> tmpStack{};

    while (!stack.empty()) {
        if (stack.top() != x ) {
            tmpStack.push(stack.top());
        }
        stack.pop();
    }

    while (!tmpStack.empty()) {
        stack.push(tmpStack.top());
        tmpStack.pop();
    }
}


int main() {
    size_t maxSize{10};

    std::stack<int> original{};
    //Lisätään pinoon ensin numeroita
    for (size_t i{0}; i < 5; ++i) {
        original.push(static_cast<int>(i));
    }
    //T2A
    if (full(original, maxSize) == 1) {
        std::cout << "Stack is full.\n";
    }else {
        std::cout << "Stack is not full.\n";
    }

    //T2B
    Stack_entry top{};
    if (pop_top(original, top) == errorCode::pop_top_success) {
        std::cout << "The top element of the stack was : " << top << '\n';
    }else {
        std::cout << static_cast<int>(errorCode::pop_top_fail) << '\n';
    }

    //T3C
    clear(original);


    //T3D
    int stackSize = size(original);
    std::cout << "Stack size: " << stackSize << '\n';


    //Lisätään pinoon numeroita uudetaan, koska se on tyhjä
    for (size_t i{0}; i < 5; ++i) {
        original.push(static_cast<int>(i));
    }
    original.push(3);

    delete_all(original, 3);

    while (!original.empty()) {
        std::cout << original.top() << " ";
        original.pop();
    }


    return 0;
}
