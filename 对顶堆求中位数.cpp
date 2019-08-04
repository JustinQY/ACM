#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1e5 + 7;
int num[maxn];
int ans[maxn];

int main() {
    int n;
    cin >> n;
    while(n--){
        priority_queue<int, vector<int>, greater<int> > small;
        priority_queue<int, vector<int>, less<int> > big;
        int x, y, cnt = 1;
        cin >> x >> y;
        for(int i = 1; i <= y; i++){
            cin >> num[i];
            if(i == 1){
                small.push(num[i]);
            }
            else{
                if(num[i] > small.top())
                    small.push(num[i]);
                else
                    big.push(num[i]);
            }
            if(i & 1){
                int c = small.size();
                int d = big.size();
                int flag;
                if(c > d)
                    flag = 1;
                else
                    flag = 0;
                while(abs(c - d) != 1){
                    if(c > d){
                        big.push(small.top());
                        small.pop();
                        flag = 1;
                    }
                    else if(d > c){
                        small.push(big.top());
                        big.pop();
                        flag = 0;
                    }
                    c = small.size();
                    d = big.size();
                }
                if(flag == 1)
                    ans[cnt++] = small.top();
                else if(flag == 0)
                    ans[cnt++] = big.top();
            }
        }
        cout << x << " " << cnt - 1 << endl;
        cout << ans[1];
        for(int j = 2; j < cnt; j++){
            if((j - 1) % 10 == 0)
                cout << endl;
            else
                cout << " ";
            cout << ans[j];
        }
        if(n != 0)
            cout << endl;
    }
    return 0;
}
