#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class CharStack {
private:
    char* stack;
    int top;
    int capacity;

public:
    // Constructor
    CharStack(int capacity) {
        this->capacity = capacity;
        stack = new char[capacity];
        top = -1;
    }

    // Destructor
    ~CharStack() {
        delete[] stack;
    }

    // Push a character onto the stack
    void push(char ch) {
        if (top == capacity - 1) {
            cout << "Stack overflow! Cannot push more elements.\n";
            return;
        }
        stack[++top] = ch;
    }

    // Pop a character from the stack
    char pop() {
        if (top == -1) {
            cout << "Stack underflow! Cannot pop elements.\n";
            return '\0';
        }
        return stack[top--];
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == -1;
    }
};

int main() {
    // Initialize bag of words for NLP-style frequency counting (Dataset words from Kaggle)
    unordered_map<string, int> bagOfWords = {
        {"hello", 2},
        {"world", 3},
        {"C++", 1},
        {"programming", 2},
        {"fun", 1},
        {"chat", 1},
        {"code", 1},
        {"learning", 2},
        {"development", 1},
        {"AI", 2},
        {"machine", 1},
        {"learning", 1},
        {"algorithm", 1},
        {"data", 3},
        {"structures", 2},
        {"stack", 1},
        {"queue", 1},
        {"tree", 1},
        {"graph", 1}
    };

    // Extract words for random selection
    vector<string> words;
    for (const auto& pair : bagOfWords) {
        for (int i = 0; i < pair.second; ++i) {
            words.push_back(pair.first);
        }
    }

    // Randomize a string of 3 words
    srand(time(0));
    string randomizedString;
    for (int i = 0; i < 3; ++i) {
        if (i > 0) randomizedString += " ";
        randomizedString += words[rand() % words.size()];
    }

    cout << "Randomized string: " << randomizedString << endl;

    // Create a CharStack with enough capacity
    int length = randomizedString.length();
    CharStack charStack(length);

    // Push characters onto the stack
    for (char ch : randomizedString) {
        charStack.push(ch);
    }

    // Pop characters to reverse the string
    cout << "Reversed string: ";
    while (!charStack.isEmpty()) {
        cout << charStack.pop();
    }
    cout << endl;

    return 0;
}

/*

@NottKoneko ➜ /workspaces/cppclass2/p6 (main) $ ./CharStack
Randomized string: chat AI learning
Reversed string: gninrael IA tahc
@NottKoneko ➜ /workspaces/cppclass2/p6 (main) $ ./CharStack
Randomized string: world queue hello
Reversed string: olleh eueuq dlrow
@NottKoneko ➜ /workspaces/cppclass2/p6 (main) $ ./CharStack
Randomized string: programming structures machine
Reversed string: enihcam serutcurts gnimmargorp


*/