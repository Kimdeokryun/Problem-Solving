import sys

def main():
    N, plat_N = map(int, input().split())

    stack = [[] for _ in range(7)]
    total = 0

    for i in range(N):
        num, plat = map(int, sys.stdin.readline().split())
        if not stack[num]:
            stack[num].append(plat)
            total += 1
        else:
            while stack[num] and plat < stack[num][-1]:
                stack[num].pop()
                total += 1
            if not stack[num] or plat > stack[num][-1]:
                stack[num].append(plat)
                total += 1
            else:
                continue
    print(total)


if __name__ == "__main__":
    main()