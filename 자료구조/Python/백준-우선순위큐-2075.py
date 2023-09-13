from sys import stdin
import heapq

def main():
    N = int(stdin.readline())

    number_pq = []

    for i in range(N):
        numbers = stdin.readline().split()
        for number in numbers:
            heapq.heappush(number_pq, int(number))
            if len(number_pq) > N:
                heapq.heappop(number_pq)

    print(heapq.heappop(number_pq))

if __name__ == "__main__":
    main()