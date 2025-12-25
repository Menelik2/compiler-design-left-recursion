#include <iostream>
#include <vector>
#include <cctype>
using namespace std;

vector<string> tokenize(const string& input) {
    vector<string> tokens;
    for (size_t i = 0; i < input.length(); i++) {
        if (isspace(input[i])) continue;

        if (isdigit(input[i])) {
            string num;
            while (i < input.length() && isdigit(input[i])) {
                num += input[i++];
            }
            i--;
            tokens.push_back("id");
        } else if (input[i] == '+') {
            tokens.push_back("+");
        }
    }
    tokens.push_back("$");
    return tokens;
}
