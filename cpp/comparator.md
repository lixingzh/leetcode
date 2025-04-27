# C++ Comparator
I'll explain C++ comparators and their use with priority_queue, providing practical examples.

## Basic Comparator Syntax:

``` c++
// Function-style comparator
bool compare(const Type& a, const Type& b) {
    return a < b; // for ascending order
}

// Class-style comparator
struct Compare {
    bool operator()(const Type& a, const Type& b) {
        return a < b; // for ascending order
    }
};
```

## Priority Queue with Custom Comparator

``` c++
#include <queue>
#include <vector>

// Example with a simple int priority queue
priority_queue<int> maxHeap; // Default: max heap
priority_queue<int, vector<int>, greater<int>> minHeap; // Min heap

// Custom comparator for a struct/class
struct Item {
    int value;
    string name;
};

struct CompareItems {
    bool operator()(const Item& a, const Item& b) {
        return a.value > b.value; // Min heap based on value
    }
};

// Using the custom comparator
priority_queue<Item, vector<Item>, CompareItems> pq;
```

## Practical Example with Custom Objects
``` c++
#include <queue>
#include <string>
#include <iostream>

struct Task {
    std::string name;
    int priority;
    int timestamp;
    
    Task(std::string n, int p, int t) : name(n), priority(p), timestamp(t) {}
};

// Comparator for task scheduling
struct TaskCompare {
    bool operator()(const Task& a, const Task& b) {
        if (a.priority != b.priority) {
            return a.priority < b.priority; // Higher priority first
        }
        return a.timestamp > b.timestamp; // Earlier timestamp if priorities equal
    }
};

int main() {
    priority_queue<Task, vector<Task>, TaskCompare> taskQueue;
    
    taskQueue.push(Task("Task1", 2, 100));
    taskQueue.push(Task("Task2", 1, 101));
    taskQueue.push(Task("Task3", 2, 102));
    
    while (!taskQueue.empty()) {
        Task t = taskQueue.top();
        cout << "Processing: " << t.name << " (Priority: " << t.priority << ")\n";
        taskQueue.pop();
    }
    
    return 0;
}
```

## Lambda Expression as Comparator (C++11 and later)
``` c++
    auto compare = [](const int& a, const int& b) { return a > b; };
    priority_queue<int, vector<int>, decltype(compare)> pq(compare);
```