#include <iostream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

/* =======================
   TOKENIZER
   ======================= */

vector<string> tokens;
int indexPos = 0;

vector<string> tokenize(const string& input) {
    vector<string> result;

    for (size_t i = 0; i < input.length(); i++) {
        if (isspace(input[i])) continue;

        // Integer → id
        if (isdigit(input[i])) {
            while (i < input.length() && isdigit(input[i])) {
                i++;
            }
            i--;
            result.push_back("id");
        }
        // Plus operator
        else if (input[i] == '+') {
            result.push_back("+");
        }
        else {
            cout << "Invalid character: " << input[i] << endl;
            exit(1);
        }
    }

    result.push_back("$"); // End marker
    return result;
}

/* =======================
   LL(1) PARSER FUNCTIONS
   Grammar:
   E  → T E'
   E' → + T E' | ε
   T  → id
   ======================= */

void match(const string& expected) {
    if (tokens[indexPos] == expected) {
        indexPos++;
    } else {
        cout << "Syntax Error: expected '" << expected
             << "' but found '" << tokens[indexPos] << "'\n";
        exit(1);
    }
}

void E();
void EPrime();
void T();

void E() {
    T();
    EPrime();
}

void EPrime() {
    if (tokens[indexPos] == "+") {
        match("+");
        T();
        EPrime();
    }
    // ε production (do nothing)
}

void T() {
    match("id");
}

/* =======================
   MAIN FUNCTION
   ======================= */

int main() {
    string input;

    cout << "Enter expression: ";
    getline(cin, input);

    tokens = tokenize(input);

    E();

    if (tokens[indexPos] == "$") {
        cout << "Parsing successful\n";
    } else {
        cout << "Parsing failed\n";
    }

    return 0;
}

