#include <cstdio>
#include <string>
#include <iostream>

using namespace std;

int stack[10000];
int t;  //top

void push(int n){
    stack[t] = n;
    t++;
}

bool empty(){
    if(t <= 0)
        return 1;
    else
        return 0;
}

int pop(){
    if(empty() == 1)
        return -1;
    else
        return stack[--t];
}

int size(){
    return t;
} 

int top(){
    if(empty() == 1)
        return -1;
    else
        return stack[t-1];
}

int main(){
    int N; //Number of intruction

    scanf("%d", &N);

    for(int i = 0; i < N; i++){
        string str;
        cin >> str;

        if(str == "push"){
            int x;
            scanf("%d", &x);

            push(x);
        }
        else if(str == "pop"){
            printf("%d\n", pop());
        }
        else if(str == "size"){
            printf("%d\n", size());
        }
        else if(str == "empty"){
            printf("%d\n", empty());
        }  
        else if(str == "top"){
            printf("%d\n", top());
        }
    }
}
