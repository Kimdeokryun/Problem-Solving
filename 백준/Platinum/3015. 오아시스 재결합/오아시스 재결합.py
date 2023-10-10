import sys

def main():
    N = int(input())
    stack = []
    result = 0

    for i in range(N):
        height = int(sys.stdin.readline())

        while stack and height > stack[-1][0]:
            result += stack.pop()[1]

        if not stack:
            stack.append((height, 1))
        else:
            if stack[-1][0] == height:
                cnt = stack.pop()[1]
                result += cnt

                if stack:
                    result += 1

                stack.append((height, cnt + 1))
            else:
                stack.append((height, 1))
                result += 1

    print(result)

if __name__ == "__main__":
    main()