# include <iostream>
# include <string>
# include <stack>
using namespace std;

// �������� �켱������ ��ȯ�ϴ� �Լ�
int getPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0; // �����ڰ� �ƴϸ� �켱���� 0
}

// ���� ǥ����� ���� ǥ������� ��ȯ�ϴ� �Լ�
string infixToPostfix(string infix) {
    stack<char> opStack;
    string postfix = "";

    for (char c : infix) {
        if (isalnum(c)) {
            postfix += c; // �ǿ����ڴ� �״�� ���
        }
        else if (c == '(') {
            opStack.push(c);
        }
        else if (c == ')') {
            while (!opStack.empty() && opStack.top() != '(') {
                postfix += opStack.top();
                opStack.pop();
            }
            opStack.pop(); // '(' ����
        }
        else { // �������� ���
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