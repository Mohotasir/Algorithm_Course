#include<bits/stdc++.h>
using namespace std;

void search(string text , string pat) {
    int patSize= pat.size();
    int textSize = text.size();
    for (int i = 0; i <= textSize-patSize; i++) {
        int j;
        for (j = 0; j < patSize; j++) {
            if (text[i + j] != pat[j]) {
                break;
            }
        }
        if (j == patSize) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text,pat;
    cin>>text>>pat;
    search(text,pat);

    return 0;
}

