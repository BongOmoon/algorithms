#include<iostream>
#include<string>

int main() {
    int t_cases;
    std::cin >> t_cases;

    while(t_cases--) {
        std::string name;
        std::cin >> name;
        std::cout << "Hello, " << name << "!" << std::endl;     
    }
}
