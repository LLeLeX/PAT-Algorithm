
#include <bits/stdc++.h>
int cnt[10005];
int n, arr[100005];
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
        cnt[arr[i]]++;
    }
    bool have = false;
    for(int i = 0; i < n; i++) {
        if(cnt[arr[i]] == 1) {
            have = true;
            printf("%d\n", arr[i]);
            break;
        }
    } 
    if(!have) {
        printf("None\n");
    }
    return 0;
}

