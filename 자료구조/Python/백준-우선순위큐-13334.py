from sys import stdin
import heapq

def main():
    N = int(stdin.readline())

    road_list = []
    roads = []
    pq = []
    result = 0

    for i in range(N):
        road_list.append(list(map(int, stdin.readline().split())))

    d = int(stdin.readline())

    for road in road_list:
        house, office = road
        if abs(house - office) <= d:
            road = sorted(road)
            roads.append(road)

    roads.sort(key=lambda x:x[1])

    for road in roads:
        if not pq:
            heapq.heappush(pq, road)
        else:
            while pq[0][0] < road[1] - d:
                heapq.heappop(pq)
                if not pq:
                    break
            heapq.heappush(pq, road)
        result = max(result, len(pq))

    print(result)

if __name__ == "__main__":
    main()