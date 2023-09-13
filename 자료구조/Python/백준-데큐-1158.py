from sys import stdin


def main():

    N, K = map(int, stdin.readline().split())
    arr = [i for i in range(1, N+1)]

    answer = []
    num = 0

    for i in range(N):
        num += (K-1)
        if num >= len(arr):
            num %= len(arr)
        answer.append(str(arr.pop(num)))

    print("<" + ", ".join(answer)[:] + ">")


if __name__ == "__main__":
    main()