
def priority(operator):
    if operator == "+" or operator == "-":
        return 1
    elif operator == "*" or operator == "/":
        return 2


def main():
    str = input()
    stack = []
    result = ""

    for char in str:
        if char.isalpha():
            result += char

        elif char == '(':
            stack.append(char)

        elif priority(char) == 2:
            while stack and (priority(stack[-1]) == 2):
                result += stack.pop()
            stack.append(char)

        elif priority(char) == 1:
            while stack and stack[-1] != '(':
                result += stack.pop()
            stack.append(char)

        elif char == ')':
            while stack and stack[-1] != '(':
                result += stack.pop()
            stack.pop()

    while stack:
        result += stack.pop()

    print(result)

if __name__ == "__main__":
    main()