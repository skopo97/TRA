#include <iostream>
#include <stack>

//Syötteen tarkastus funktio
void checkInput() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, enter an integral number.\n";
    }
}

std::stack<int> insertValues() {
    std::stack<int> integers;
    int n{};
    // Hoidetaan erikseen ensimmäien luku, koska se ei ole vertailtavissa
    while (true) {
        std::cin >>n;
        if (std::cin.fail()){
            checkInput();
        }else {
            integers.push(n);
            break;
        }
    }
    int prev = n;

    while (true) {
        std::cin >> n;
        if (std::cin.fail()) {
            checkInput();
        }
        if (n < prev) {
            //ei lisätä viimeistä lukua. Sillä jos halutaan nämä pienimmästä suurimpaan tulostaa
            //niin silloin täytyisi järjestellä stackki uudestaan mikä on hieman työlästä
            break;
        }
        integers.push(n);
        prev = n;
    }
    return integers;
}

void printReverseOrder(std::stack<int> integers) {
    while (!integers.empty()) {
        std::cout << integers.top() << " ";
        integers.pop();
    }
}

int main() {

    std::cout << "Enter integers. Input is terminated when the value of current "
                 "integer is less than the previous integer.\n";
    std::stack<int> integers = insertValues();
    printReverseOrder(integers);
    return 0;
}
