#include <iostream>
#include <stack>
enum class errorCode {
    success,
    fail
};


errorCode copyStackTemp(std::stack<int> original, std::stack<int> &dest){
    if (original.empty()) {
        return errorCode::fail;
    }else {
        //Tehdään väliaikainen pino, johon lisätään alkuperäisen pinon arvot.
        //nämä menevät käänteiseen järjestekyseen kuin alkuperäisessä pinossa.
        //Joten kun uudestaan väliaikaisesta pinosta lisätään dest pinoon,
        //niin järjestys on sama kuin alkuperäisessä pinossa.
        std::stack<int> tmp{};
        while (!original.empty()) {
            tmp.push(original.top());
            original.pop();
        }
        while (!tmp.empty()) {
            dest.push(tmp.top());
            tmp.pop();
        }
        return errorCode::success;
    }
}

void printStack(std::stack<int> s) {
    while (!s.empty()) {
        std::cout << s.top() << " ";
        s.pop();
    }
    std::cout << '\n';
}

int main() {
    std::stack<int> original{};
    //Lisätään pinoon ensin numeroita
    for (int i{0}; i < 10; ++i) {
        original.push(i);
    }

    std::stack<int> dest{};

    errorCode result = copyStackTemp(original, dest);

    if (result == errorCode::success) {
        std::cout << "Kopiointi onnistui.\n";
    }else {
        std::cout << "Kopiointi epäonnistui.\n";
        return 0;
    }

    std::cout << "original stack: ";
    printStack(original);
    std::cout << "dest stack: ";
    printStack(dest);
}