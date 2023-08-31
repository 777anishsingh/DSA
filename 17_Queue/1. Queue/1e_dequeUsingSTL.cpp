#include <bits/stdc++.h>
using namespace std;

int main()
{

    deque<int> dq;
    // push front
    dq.push_front(14);
    dq.push_front(15);
    dq.push_front(16);
    dq.push_front(17);

    // push back
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_back(4);

    // size
    cout << "size -> " << dq.size() << endl;

    // popfront
    dq.pop_front();

    // pop back
    dq.pop_back();

    // front view
    cout << "Front element -> " << dq.front() << endl;
    // back view
    cout << "Rear element -> " << dq.back() << endl;

    return 0;
}