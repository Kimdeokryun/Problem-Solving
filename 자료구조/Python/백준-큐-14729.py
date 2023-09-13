from sys import stdin

def main():
    N = int(stdin.readline())

    scores = []

    for i in range(N):
        scores.append(float(stdin.readline()))

    scores.sort()

    for i in range(7):
        print("{:.3f}".format(scores[i]))

if __name__ == "__main__":
    main()