#include <stack>
#include <iostream>
#include <string>

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
    std::cout << '\n';
}