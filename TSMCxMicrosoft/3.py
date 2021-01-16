def solution(S):
    char_dict = {}
    # upper, lower, both
    res = -1
    for c in S:
        if c.isupper():
            if c.upper() in char_dict:
                if char_dict[c.upper()] == "lower":
                    char_dict[c.upper()] = "both"
                    res = max(res, ord(c.upper()))
            else:
                char_dict[c.upper()] = "upper"
        else:
            if c.upper() in char_dict:
                if char_dict[c.upper()] == "upper":
                    char_dict[c.upper()] = "both"
                    res = max(res, ord(c.upper()))
            else:
                char_dict[c.upper()] = "lower"

    if res == -1:
        return "NO"
    else:
        return chr(res)


if __name__ == "__main__":
    print(solution("Codility"))
    print(solution("WeTestCodErs"))
    print(solution("aaBabcDaA"))
