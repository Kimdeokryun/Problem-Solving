def isPalindrome(sentence, start, end):
    while start < end:
        if sentence[start] != sentence[end]:
            return False
        start += 1
        end -= 1

    return True


def main():

    str1 = input()
    str1_len = len(str1)
    result = str1_len

    for i in range(str1_len):
        if isPalindrome(str1, i, str1_len-1):
            result = str1_len + i
            break

    print(result)


if __name__ == "__main__":
    main()