def main():
    repeat = int(input())
    total = 0

    for i in range(repeat):
        str = input()
        stack = []
        for idx in range(0, len(str)):
            if len(stack) > 0:
                top = stack.pop()
                if str[idx] == top:
                    continue
                else:
                    stack.append(top)
                    stack.append(str[idx])
            else:
                stack.append(str[idx])
        if len(stack) == 0:
            total += 1

    print(total)

if __name__ == "__main__":
    main()