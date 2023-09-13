from sys import stdin

tree = [[] for _ in range(51)]

def solve(node):
    if not tree[node]:
        return 1

    child = []
    for i in range(len(tree[node])):
        child.append(solve(tree[node][i]) + 1)

    child.sort(reverse=True)

    ret = 0
    for i in range(len(child)):
        ret = max(ret, child[i] + i)

    return ret

def main():
    N = int(stdin.readline())
    numbers = list(map(int, stdin.readline().split()))

    for i in range(1, len(numbers)):
        tree[numbers[i]].append(i)

    print(solve(0) - 1)


if __name__ == "__main__":
    main()