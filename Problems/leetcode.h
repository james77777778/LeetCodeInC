#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>
#include <limits.h>
#include <stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};