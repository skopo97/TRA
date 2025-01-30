#include <iostream>
#include <stack>
#include <string>


std::string readLine() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

std::stack<char> populateStack(const std::string& line) {
    std::stack<char> words;

    for (char c : line) {
        words.push(c);
    }

    return words;
}

int main() {

    std::cout << "Write a line of text: ";
    std::string textLine {readLine()};

    populateStack(textLine);

    std::stack<char> chars = populateStack(textLine);

    while (!chars.empty()) {
        std::cout << chars.top();
        chars.pop();
    }
    return 0;
}
