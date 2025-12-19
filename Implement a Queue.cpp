Problem Link: https://www.codingninjas.com/codestudio/problems/implement-a-queue_8230848?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h> 
class Queue {
    private:
        vector<int> q;
public:
    Queue() {
        
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        return q.size() == 0;
    }

    void enqueue(int data) {
        q.push_back(data);
    }

    int dequeue() {
        if (q.size() == 0) return -1;
        int val = q[0];
        q.erase(q.begin());
        return val;
    }

    int front() {
        if (q.size() == 0) return -1;
        return q[0];
    }
};
