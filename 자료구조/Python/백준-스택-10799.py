def main():
    str = input()
    stack = []
    total = 0
    for i in range(len(str)):
        if str[i] == '(':
            stack.append(str[i])
        elif str[i] == ')' and str[i-1] == '(':
            stack.pop()
            total += len(stack)
        else:
            total += 1
            stack.pop()
    print(total)

if __name__ == "__main__":
    main()