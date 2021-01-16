def solution(N):
    is_negative = False
    if N < 0:
        is_negative = True
        N = -N

    temp_N = N
    digits = []
    if temp_N == 0:
        digits = [0]
    else:
        while(temp_N):
            digits.insert(0, temp_N % 10)
            temp_N = temp_N // 10

    res = 0
    for i, d in enumerate(digits):
        if not is_negative:
            if d <= 5:
                digits.insert(i, 5)
                break
        else:
            if d >= 5:
                digits.insert(i, 5)
                break

    res = 0
    for i, d in enumerate(digits):
        res += d
        if i < len(digits) - 1:
            res *= 10

    if is_negative:
        res = -res

    return res


if __name__ == "__main__":
    print(solution(268))
    print(solution(670))
    print(solution(0))
    print(solution(-999))
