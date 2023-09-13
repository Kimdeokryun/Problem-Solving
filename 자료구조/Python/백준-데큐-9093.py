from sys import stdin

def main():
    N = int(stdin.readline())

    stack = []

    for i in range(N):
        sentence = stdin.readline()
        for alpha in sentence:
            if alpha == ' ':
                while stack:
                    print(stack.pop(), end="")
                print(alpha, end="")
            elif alpha == '\n':
                continue
            else:
                stack.append(alpha)

        while stack:
            print(stack.pop(), end="")
        print("")
if __name__ == "__main__":
    main()