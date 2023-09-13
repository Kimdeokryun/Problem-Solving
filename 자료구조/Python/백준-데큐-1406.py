from sys import stdin


def main():

    st1 = list(stdin.readline().replace("\n", ""))
    st2 = []
    N = int(stdin.readline())

    for i in range(N):
        command = stdin.readline().replace("\n", "")
        if command.find("P") != -1:
            alpha = command.split()[1]
            st1.append(alpha)
        elif command == "L":
            if st1:
                st2.append(st1.pop())

        elif command == "D":
            if st2:
                st1.append(st2.pop())

        elif command == "B":
            if st1:
                st1.pop()

    st1.extend(reversed(st2))
    print(''.join(st1))

# 내 풀이
"""
def main():

    sentence = stdin.readline().replace("\n", "")
    N = int(stdin.readline())
    cursor = len(sentence)

    for i in range(N):
        command = stdin.readline().replace("\n", "")
        if command.find("P") != -1:
            alpha = command.split()[1]
            sentence = sentence[:cursor] + alpha + sentence[cursor:]
            cursor += 1
        elif command == "L":
            if cursor == 0:
                pass
            else:
                cursor -= 1

        elif command == "D":
            if cursor == len(sentence):
                pass
            else:
                cursor += 1

        elif command == "B":
            if cursor == 0:
                pass
            else:
                sentence = sentence[:cursor-1] + sentence[cursor:]
                cursor -= 1

    print(sentence)
"""

if __name__ == "__main__":
    main()