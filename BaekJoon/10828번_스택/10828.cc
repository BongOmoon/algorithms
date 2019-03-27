#include <iostream>
#include <string>

typedef struct Stack {
    int stack[10000];
    int top = -1;
};

void push(Stack *stack);
bool empty();
int pop();
int size();
int top();

int main(){
    int exec_num; //Number of instruction
    scanf("%d", &exec_num);

    std::string str;
    for(int iter = 0; iter < exec_num; ++iter){
        std::cin >> str;

        if(str == "push"){
            int data;
            std::cin >> data;
            push(data);
        }
        else if(str == "pop"){
            std::cout << pop() << std::endl;
        }
        else if(str == "size"){
            std::cout << size() << std::endl;
        }
        else if(str == "empty"){
            std::cout << empty() << std::endl;
        }  
        else if(str == "top"){
            std::cout << top() << std::endl;
        }
    }
}

void push(int data) {
    stack[t++] = data;
}

bool empty() {
    if(t <= 0){
        return true;
    }
    else{
        return false;
    }
}

int pop() {
    if(empty()) {
        return -1;
    }
    else {
        return stack[--t];
    }
}

int size() {
    return t;
} 

int top() {
    if(empty()) {
        return -1;
    }
    else {
        return stack[t-1];
    }
}

