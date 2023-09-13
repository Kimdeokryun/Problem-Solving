# include <iostream>
# include <string>
# include <stack>
using namespace std;

// 연산자의 우선순위를 반환하는 함수
int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // 연산자가 아니면 우선순위 0
}

// 중위 표기식을 후위 표기식으로 변환하는 함수
string infixToPostfix(string infix) {
    stack<char> opStack;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c; // 피연산자는 그대로 출력
        }
        else if (c == '(') {
            opStack.push(c);
        }
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // '(' 제거
        }
        else { // 연산자일 경우
            while (!opStack.empty() && getPriority(opStack.top()) >= getPriority(c)) {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.push(c);
        }
    }

    while (!opStack.empty()) {
        postfix += opStack.top();
        opStack.pop();
    }

    return postfix;
}



int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	string str;
	cin >> str;
	
    string postfix = infixToPostfix(str);

    cout << postfix << endl;

	return 0;
}