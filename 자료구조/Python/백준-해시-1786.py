T = input()
P = input()


def make_table():
    table = [0] * len(P)
    j = 0
    for i in range(1, len(P)):
        while j > 0 and P[i] != P[j]:
            j = table[j - 1]

        if P[i] == P[j]:
            j += 1
            table[i] = j

    return table


def main(table):
    result = []
    j = 0

    for i in range(len(T)):
        while j > 0 and T[i] != P[j]:
            j = table[j - 1]

        if T[i] == P[j]:
            if j == len(P) - 1:
                result.append(i - len(P) + 2)
                j = table[j]
            else:
                j += 1

    print(len(result))
    print(*result)


if __name__ == "__main__":
    main(make_table())
