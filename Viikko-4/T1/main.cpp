#include <stack>
#include <iostream>

int main( )

{

    int n{};
    double item{};
    std::stack<double> numbers;
    std::cout << " Type in an integer n followed by n decimal numbers.\n The numbers will be printed in reverse order.\n";

    std::cin >> n;
    for (int i{0}; i < n; ++i) {
        std::cin >> item;
        numbers.push(item);
    }
    std::cout << '\n' << '\n';

    while (!numbers.empty( )) {
        std::cout << numbers.top( ) << " ";
        numbers.pop( );
    }
    std::cout << '\n';
}