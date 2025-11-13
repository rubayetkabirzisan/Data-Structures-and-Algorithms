#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int evaluate(int a, int b, char op) {
    switch (op) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b;
        case '%': return a % b;
    }
    return 0;
}

pair<int, string> calculateExpression(const string& expr, int start, int end) {
    int maxResult = INT_MIN;
    string maxExpression = "";

    if (start == end) {
        int num = expr[start] - '0';
        return make_pair(num, to_string(num));
    }

    for (int i = start + 1; i < end; i += 2) {
        auto left = calculateExpression(expr, start, i - 1);
        auto right = calculateExpression(expr, i + 1, end);

        for (char op : {'+', '-', '*', '/', '%'}) {
            if ((op == '+' || op == '*') && i % 2 == 1)
                continue; // Priority check for addition and multiplication

            int result = evaluate(left.first, right.first, op);
            if (result > maxResult) {
                maxResult = result;
                if (op == '+' || op == '-')
                    maxExpression = "(" + left.second + " " + op + " " + right.second + ")";
                else
                    maxExpression = left.second + " " + op + " " + right.second;
            }
        }
    }

    return make_pair(maxResult, maxExpression);
}

int main() {
    string expression;
    cin >> expression;

    int queries;
    cin >> queries;

    while (queries--) {
        int start, end;
        cin >> start >> end;

        auto result = calculateExpression(expression, start, end);
        cout << "Query: " << start << " " << end << endl;
        cout << result.first << endl;
        cout << result.second << endl;
    }

    return 0;
}

