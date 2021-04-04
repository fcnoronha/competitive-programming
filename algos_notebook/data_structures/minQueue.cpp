// MIN QUEUE
// Maintain the minimum value in the queue

#include<bits/stdc++.h>
using namespace std;

struct MinQueue {
    
    stack<pair<int, int>> s1, s2;

    int getMin() {
        if (s1.empty()) return s2.top().second;
        if (s2.empty()) return s1.top().second;
        return min(s1.top().second, s2.top().second);
    }

    void insert(int val) {
        int mn = val;
        if (!s1.empty()) mn = min(mn, s1.top().second);
        s1.push({val, mn});
    }

    int pop() {
        if (s2.empty()) {
            while (!s1.empty() ){
                int val = s1.top().first;
                s1.pop();
                int mn = val;
                if (!s2.empty()) mn = min(mn, s2.top().second);
                s2.push({val, mn});
            }
        }
        int ret = s2.top().second;
        s2.pop();
        return ret;
    }
};
