#include "leetcode.h"

int* build_kmp_table(string needle) {
    int nsize = needle.length();
    int* F = new int[nsize];
    memset(F, 0, sizeof(int)*nsize);
    // building kmp table is use only needle string to find largest prefix
    // i for original string, j for finding pattern
    for(int i=1, j=0; i<nsize;) {
        if(needle[i] != needle[j]) {
            if(j!=0)
                j = F[j-1];  // find F(j-1)
            else
                i++;  // if j==0, no need to roll back
        }
        else {  // find match, record the F(i) = j+1
            F[i] = j+1;
            i++;
            j++;
        }
    }
    return F;
}

int main() {
    string needle = "ababaabab";
    int* F = build_kmp_table(needle);
    for(int i=0; i<needle.length(); i++)
        cout << F[i] << " ";
    cout << endl;
}