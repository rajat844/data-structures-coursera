#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Bracket {
    Bracket(char type, int position) :
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    getline(std::cin, text);
    bool balance = true;
    int index;
    int a;

    std::stack <Bracket> opening_brackets_stack;
    for (index = 0; index < text.length(); ++index) {
        char next = text[index];

        if (opening_brackets_stack.empty())
            a = index;
        if (next == '(' || next == '[' || next == '{') {
            opening_brackets_stack.push(Bracket(next, index));
        }
        else {

            if (next == ')' || next == ']' || next == '}') {
                if (opening_brackets_stack.empty()) {
                    balance = false;
                    break;
                }
                Bracket temp = opening_brackets_stack.top();
                opening_brackets_stack.pop();
                if (temp.Matchc(next) == false) {
                    balance = false;
                    break;
                }
            }
        }
    }
    if (balance == true && opening_brackets_stack.empty()) {
        cout << "Success" << endl;
    }
    else {
        if ((index >= text.size()) && !opening_brackets_stack.empty())
            cout << a + 1 << endl;
        else
            cout << index + 1 << endl;
    }
    // Printing answer, write your code here

    return 0;
}
