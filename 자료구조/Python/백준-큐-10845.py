from sys import stdin


def main():
    N = int(stdin.readline())

    queue = []

    for i in range(N):
        command = stdin.readline()
        if command.find("push") != -1:
            com = command.split()
            number = int(com[1])
            queue.append(number)
        elif command.find("front") != -1:
            if queue:
                print(queue[0])
            else:
                print(-1)
        elif command.find("back") != -1:
            if queue:
                print(queue[-1])
            else:
                print(-1)
        elif command.find("size") != -1:
            print(len(queue))
        elif command.find("pop") != -1:
            if queue:
                print(queue.pop(0))
            else:
                print(-1)
        elif command.find("empty") != -1:
            if queue:
                print(0)
            else:
                print(1)

if __name__ == "__main__":
    main()