#include <stack>
#include <iostream>
#include <string>
bool isPalindrome(std::string string) {
    std::stack<char> characters;
    for (auto c : string) {
        characters.push(c);
    }
    for (auto c : string) {
        if ( c != characters.top()) {
            return false;
        }
        characters.pop();
    }
    return true;
}

int main( )

{

    std::string item{};
    std::stack<std::string> characters;
    std::cout << " Type in a string, it will be reversed\n";

    std::getline(std::cin >> std::ws, item);
    for (auto c : item) {
        characters.push(&c);
    }
    std::cout << '\n' << '\n';

    while (!characters.empty( )) {
        std::cout << characters.top( );
        characters.pop( );
    }
    std::cout << '\n' << '\n';

    if (isPalindrome(item)) {
        std::cout << item << " is a palindrome";
    }else {
        std::cout << item << " is not a palindrome";
    }
    std::cout << '\n';
}