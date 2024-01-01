// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

int main() {
    priority_queue<int> pq;  // Default is a max heap
    pq.push(5);
    pq.push(3);
    pq.push(8);
    vector<int> v= {5,4,1,9,3,2,0,6,11,8};
    int arr={5,4,1,9,3,2,0,6,11,8};
    // priority_queue<int,<vector<int>,less<int>> qu; // default priority queue, has maximum element as the priority
    priority_queue<int, std::vector<int>, std::greater<int> > qu; // priority is minimum element
    for(int i = 0; i < arr.size(); i++) {
        qu.push(arr[i]); // O(logn)
    }
    // priority_queue<int,vector<int>,greater<int>> pq(v.begin(),v.end());
    priority_queue<int,vector<int>,greater<int>> pq(arr,arr+9);
    // highest priority element
    int size = pq.size();
    bool isEmpty = pq.empty();
    cout<<qu.top()<<"\n"; // O(1)
    // remove some elements
    qu.pop(); // 11 // O(logn)
    qu.pop(); // 9
    cout<<qu.top()<<"\n";

}

// custom comparator cpp
#include <iostream>
#include <queue>  // for std::priority_queue
#include <vector>

struct Person {
    std::string name;
    int age;
    
    Person(const std::string& n, int a) : name(n), age(a) {}
};

struct AgeComparator {
    bool operator()(const Person& p1, const Person& p2) const {
        return p1.age > p2.age;  // Change > to < for min heap based on age
    }
};

int main() {
    std::priority_queue<Person, std::vector<Person>, AgeComparator> peopleQueue;

    peopleQueue.push(Person("Alice", 25));
    peopleQueue.push(Person("Bob", 20));
    peopleQueue.push(Person("Charlie", 30));

    while (!peopleQueue.empty()) {
        std::cout << peopleQueue.top().name << " (" << peopleQueue.top().age << ") ";
        peopleQueue.pop();
    }

    return 0;
}
