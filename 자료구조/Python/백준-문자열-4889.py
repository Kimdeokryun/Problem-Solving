from sys import stdin

def main():

    c_list = []
    num = 0

    while True:
        str1 = stdin.readline().strip()
        if str1.find("-") != -1:
            break

        count1 = 0
        count2 = 0

        for c in str1:
            if c == '{':
                c_list.append(c)

            else:
                if c_list:
                    c_list.pop()
                else:
                    count1 += 1
                    c_list.append('{')

        while c_list:
            c_list.pop()
            if count2 % 2 == 0:
                pass
            else:
                count1 += 1
            count2 += 1

        num += 1

        print(str(num)+". "+str(count1))


if __name__ == "__main__":
    main()