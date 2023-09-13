def main():
    N = int(input())
    K = int(input())
    S = input()

    count_n, i, result = 0, 0, 0

    while i < K-1:
        if S[i:i+3] == 'IOI':
            i += 2
            count_n += 1

            if count_n == N:
                result += 1
                count_n -= 1
        else:
            i += 1
            count_n = 0

    print(result)

if __name__ == "__main__":
    main()