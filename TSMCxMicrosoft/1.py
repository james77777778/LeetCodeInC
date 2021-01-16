import sys


def solution(N):
    for i in range(1, N + 1):
        res = ""
        is_printed = False
        if i % 2 == 0:
            res += "Codility"
            is_printed = True
        if i % 3 == 0:
            res += "Test"
            is_printed = True
        if i % 5 == 0:
            res += "Coders"
            is_printed = True
        if not is_printed:
            res += str(i)
        sys.stdout.write("{}\n".format(res))


if __name__ == "__main__":
    solution(10)
