from sys import stdin

def main():
    N = int(stdin.readline())
    height = [int(stdin.readline()) for _ in range(N)]
    stack = []
    result = 0

    height.append(0)
    stack.append((0, height[0]))

    for i in range(1, N+1):
        left = i
        while stack and stack[-1][1] > height[i]:
            left, h = stack.pop()
            result = max(result, (i-left)*h)
        stack.append((left, height[i]))

    print(result)

if __name__ == "__main__":
    main()