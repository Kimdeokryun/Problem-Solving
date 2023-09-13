from sys import stdin
import queue

def main():
    sentence = stdin.readline().strip()

    stack = []
    queue = []

    for alpha in sentence:

        if alpha == '<':
            while stack:
                print(stack.pop(), end="")
            queue.append(alpha)
            continue
        if queue:
            if alpha == '>':
                while queue:
                    print(queue.pop(0), end="")
                print(alpha, end="")
            else:
                queue.append(alpha)
        else:
            if alpha == ' ':
                while stack:
                    print(stack.pop(), end="")
                print(alpha, end="")
            elif alpha == '\n':
                continue
            else:
                stack.append(alpha)

    while queue:
        print(queue.pop(0), end="")

    while stack:
        print(stack.pop(), end="")


if __name__ == "__main__":
    main()