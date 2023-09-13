from sys import stdin

def main():

    N = int(input())
    car_list = []
    j = 0
    result = 0

    for i in range(N):
        car = stdin.readline().strip()
        car_list.append(car)

    for i in range(N):
        car = stdin.readline().strip()

        if car_list[j] == car:
            j += 1
            continue
        else:
            car_list.pop(car_list.index(car))
            result += 1

    print(result)

if __name__ == "__main__":
    main()