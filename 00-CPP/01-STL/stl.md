## STL

### 1. Pairs

A pair of integers can be defined as follows:

```CPP
pair<int, int> p2 = {1, 2};
```

A pair of integer and strings can be defined similarly:

```CPP
pair<int, string> p2 = {1, "Hello Vansh!"};
```

We can also create an array of pairs:

```CPP
pair<int, int> p3[] = {{1, 5}, {2, 3}, {6, 4}};
```

And you can also create a pair of pairs, or a pair of pair of pairs (also called nested pairs)

```CPP
pair<int, pair<int, int>> p4 = {1, {2, 3}};
```

To swap the content of a pair

```CPP
pair<int, int> p5 = {1, 2};
pair<int, int> p6 = {3, 4};
cout<<"\nBefore Swapping:\n\tp5: "<<p5.first<<" "<<p5.second<<"\n\tp6: "<<p6.first<<" "<<p6.second;
p6.swap(p5);
cout<<"\nAfter Swapping:\n\tp5: "<<p5.first<<" "<<p5.second<<"\n\tp6: "<<p6.first<<" "<<p6.second<<"\n";
```

You can use auto and make_pair() function to define a pair easily.

```CPP
auto p7 = make_pair(1, 2);
```

Pairs

```CPP
void PairsFunction() {
// A pair stores 2 values of same or different data types.
pair<int, int> p2 = {{1, 2}, {4, 3}};        // initializing with multiple elements
pair<int, int> p1 = {1, 3};                  // p1 is a pair of 2 integers
// We can get the first value using p1.first and the second value using p1.second
cout<<"\nPair p1:\n\tFirst value: "<<p1.first<<"\n\tSecond value: "<<p1.second<<"\n";

pair<int, string> p2 = {1, "Hello Vansh!"};
cout<<"\nPair p2:\n\tFirst value: "<<p2.first<<"\n\tSecond value: "<<p2.second<<"\n";

// We can create an array of pairs
pair<int, int> p3[] = {{1, 5}, {2, 3}, {6, 4}};
cout<<"\nArray of pairs p3:\n\tPair 1: "<<p3[0].first<<" "<<p3[0].second<<"\n\tPair 2: "<<p3[1].first<<" "<<p3[1].second<<"\n\tPair 3: "<<p3[2].first<<" "<<p3[2].second<<"\n";

// We can also have nested pairs
pair<int, pair<int, int>> p4 = {1, {2, 3}};
cout<<"\nNested pair p4:\n\tFirst value: "<<p4.first<<"\n\tSecond value: "<<p4.second.first<<" "<<p4.second.second<<"\n";

// To swap the content of a pair
pair<int, int> p5 = {1, 2};
pair<int, int> p6 = {3, 4};
cout<<"\nBefore Swapping:\n\tp5: "<<p5.first<<" "<<p5.second<<"\n\tp6: "<<p6.first<<" "<<p6.second;
p6.swap(p5);
cout<<"\nAfter Swapping:\n\tp5: "<<p5.first<<" "<<p5.second<<"\n\tp6: "<<p6.first<<" "<<p6.second<<"\n";

// We can create pairs without explicitly defining the data types (automatic type deduction)
auto p7 = make_pair(1, 2);
cout<<"\nPair p7 with Automatic Type Deduction:\n\tFirst value: "<<p7.first<<"\n\tSecond value: "<<p7.second<<"\n";
}
```

### 2. Vectors

`vector<int> v(3, 10);` will define a vector v of size 3 where all the elements are 10.
`vector<int> v(5);`will define a vector v of size 5 where all the elements are 0.
To ‘copy’ a vector, you can simply do `vector<int> v2(v);`. v2 will contain all the elements of vector v.

Adding and Deleting Elements:
Whenever an element is added to the vector, the size of the vector is dynamically increased.
We can add elements to the end of the vector using `push_back()` and `emplace_back()` functions.
`emplace_back()` uses constructors to add an element, which is why it is faster than `push_back()`, which passes a copy of the element.
To initialize a vector with multiple elements:

```CPP
vector<int> v = {1, 5, 3, 2};
```

Adding an element is also called as ‘pushing’ an element.
To add an element using push_back():

```CPP
v.push_back(1); // Slower
```

To add an element using emplace_back():

```CPP
v.emplace_back(2); // Faster
```

insert() has a higher time complexity than both emplace_back and push_back().
To add an element in the beginning, we an use the insert() function.

```CPP
v.insert(5);
```

Vector of pairs

```CPP
vector<pair<int, int>> v_pair;
```

You can add elements at the end of the vector using push_back() and emplace() .
To push an element using push_back():

```CPP
v_pair.push_back({2, 4}); // NOTE: you need to wrap the pair in {}
```

To push an element using emplace():

```CPP
v_pair.emplace(5,10); // NOTE: you don't need to wrap the pair in {}
```

Indexing in Vectors:

```CPP
v.at(3); // To get the 3rd element
```

Size in vector

```CPP
v.size(); // Gives the number of elements in vector v
```

Iterators in Vectors:
Iterators are a very important concept in vectors as well as other containers in STL.
An iterator points to the memory location where the data is stored.
NOTE: iterators store the memory location, not the data.
A vector iterator can be used to traverse through all or some of the elements in a vector.
An iterator can be defined as follows:

```CPP
vector<int>::iterator it = v.begin()
```

This will initiate a vector iterator which points to the 1st element in the vector v.
NOTE: `v.begin()` will point to the memory location where the 1st element of the vector v is stored, while v.end() will point to the memory location just after the location of the final vector element.
An easier way to define a vector iterator is:

```CPP
auto it = v.begin();
```

Vector iterators are very useful when printing the elements in a vector, or performing any operation which requires traversal (and therefore, a for or while loop).
Similar to v.end(), there exists v.rend() which starts from the last element and moves towards the 1st element.

```CPP
vector<int>::iterator it = v.begin() + 1;       // Iterator pointing to the 2nd element of the vector
v.emplace(it, 103);                             // Adds 103 before the 2nd element of the vector

// An iterator points to the memory position where an element is stored, to access the element we use * before the iterator
cout<<"\nThe elements of vector v are:\n";
vector<int>::iterator it1 = v.begin();                      // Iterator pointing to the first element of the vector
for (it1 = v.begin(); it1 != v.end(); it1++) {              // the loop will run till we reach the end of the vector
  cout << *it1 << " ";                                    // prints the value stored at the address pointed by the iterator
}

vector<int>::iterator it2 = v.end();                // Will point at the memory location AFTER the last element
auto it3 = v.begin();                               // Will automatically detect the data type of the iterator, so same as vector<int>::iterator it = v.begin()

// Easier way to traverse through a vector
/*/
for (auto it : v) {
  cout<<it<<" ";
}
*/
```

Deleting Elements from a Vector:
To delete the last element from a vector, we can use the pop_back() function.
There are multiple ways to delete 1 or more elements from a vector using iterators.
We use the erase() function to delete elements using iterators.
For example, to delete the 1st element from the vector:

```CPP
v.erase(v.begin())
```

To delete the first 3 elements:

```CPP
v.erase(v.begin(), v.begin() + 3).
```

Note that the first value is inclusive but the 2nd value is not inclusive. So the elements deleted will be the ones stored at v.begin(), v.begin() + 1, and v.begin() + 2.

To empty the entire vector v, we use the `v.clear()` function.
To check if a vector is empty, we use the empty() function.
`v.empty()` will return True if the vector v is empty and False if the vector v contains 1 or more elements.
Entire code for Vectors:

```CPP
void VectorsFunction() {
    vector<int> v;
    v.push_back(1);            // Adds 1 to the end of the vector (Slower)
    v.emplace_back(2);         // Adds 2 to the end of the vector (Faster)

    vector<pair<int, int>> v2;          // Will define a vector of pairs of 2 integers
    v2.push_back({1, 2});               // You have to use {} to push a pair using push_back
    v2.emplace_back(4,5);               // You can directly push a pair using emplace_back

    vector<int> v3(5, 100);    // Will define a vector of size 5 with all values as 100: {100, 100, 100, 100, 100}
    vector<int> v4(v3);        // Will define a vector v4 with the same values as v3
    vector<int> v5(5);         // Will define a vector of size 5 with all values as 0

    cout<<"\nThe 2nd element of vector v is " << v[1] << endl;          // To print the 2nd element


    v.pop_back();               // Removes the last element
    v.push_back(25);
    v.emplace_back(50);
    v.emplace_back(75);

    // Iterators in vectors
    vector<int>::iterator it = v.begin() + 1;       // Iterator pointing to the 2nd element of the vector
    v.emplace(it, 103);                             // Adds 103 before the 2nd element of the vector

    // An iterator points to the memory position where an element is stored, to access the element we use * before the iterator
    cout<<"\nThe elements of vector v are:\n";
    vector<int>::iterator it1 = v.begin();                      // Iterator pointing to the first element of the vector
    for (it1 = v.begin(); it1 != v.end(); it1++) {              // the loop will run till we reach the end of the vector
        cout << *it1 << " ";                                    // prints the value stored at the address pointed by the iterator
    }

    vector<int>::iterator it2 = v.end();                // Will point at the memory location AFTER the last element
    auto it3 = v.begin();                               // Will automatically detect the data type of the iterator, so same as vector<int>::iterator it = v.begin()

    // Easier way to traverse through a vector
    /*/
    for (auto it : v) {
        cout<<it<<" ";
    }
    */

   cout<<"\n\nThe element at index position 2 in vector v is: "<<v.at(2);       // To access an element at a specified index position, we use .at()
   cout<<"\nThe size of the vector after some operations: "<<v.size();          // Will tell the number of elements in vector v

   // There are multiple ways to delete elements
   v.pop_back();                            // Will delete the last element in the vector
   v.erase(v.begin() + 1);                  // Will delete the 2nd element of the vector
   v.erase(v.begin(), v.begin() + 3);       // Will delete the first 3 elements of the vector, sp index posn 0, 1 and 2 (end posn is not included)

   v.insert(v.begin(), 7);                  // Will insert 7 at the beginning of the vector
   v.insert(v.begin(), 2, 3);               // Will insert 3 twice in the beginning of the vector

   v.clear();                   // It will empty the entire vector
   v.empty();                   // It will return true if the vector is empty, else it will return false

}
```

### 3. List

List allows operations like insertion and deletion from the front (beginning).
While a vector is a dynamic array internally, a list is similar to a doubly linked list.
Therefore, random access is not available in lists. This means that you cannot access any element you want using indexing.
Other than that, a list and a vector are pretty similar!
A list can be defined as follows:

```CPP
list<int> l1 = {1, 5, 67, 3, 7);
```

Insertion and Deletion from the Front:
To add an element in the front (beginning), we can simply use `push_front()` or `emplace_front()` functions.
To delete an element from the beginning, we can use the `pop_front()` function. It is faster than erase().

```CPP
list<int> l;
l.push_back(1);             // Adds 1 to the end of the list (Slower)
l.emplace_back(2);          // Adds 2 to the end of the list (Faster)
l.push_front(20);           // Adds 20 to the beginning of the list (not available in vectors)
l.emplace_front(50);        // Adds 50 to the beginning of the list (not available in vectors)
l.pop_front();              // Removes the first element of the list (not available in vectors)
```

Iterators in List:
As you cannot access elements by indexing in lists, elements are usually accessed in lists using iterators.
advance(iter, 2) will move the iterator 2 elements ahead.

```CPP
list<int>::iterator it = l.begin(); // Will define a list iterator pointing to the 1st element
advance(it, 2); // Will move the iterator 2 positions ahead, cannot use + operator in list iterators
cout<<"\nThe 3rd element in the list is "<<\*it; // Will print the 3rd element of the list

// Traversal using for loop in a list
cout<<"\nThe elements of list l are:\n";
for (auto it : l) {
cout<<it<<" ";
}
```

Entire Code for Lists:

```CPP
void ListFunction() {
list<int> l;
l.push_back(1); // Adds 1 to the end of the list (Slower)
l.emplace_back(2); // Adds 2 to the end of the list (Faster)
l.push_front(20); // Adds 20 to the beginning of the list (not available in vectors)
l.emplace_front(50); // Adds 50 to the beginning of the list (not available in vectors)
l.pop_front(); // Removes the first element of the list (not available in vectors)

    list<int>::iterator it = l.begin();                 // Will define a list iterator pointing to the 1st element
    advance(it, 2);                                     // Will move the iterator 2 positions ahead, cannot use + operator in list iterators
    cout<<"\nThe 3rd element in the list is "<<*it;     // Will print the 3rd element of the list

    // Traversal using for loop in a list
    cout<<"\nThe elements of list l are:\n";
    for (auto it : l) {
        cout<<it<<" ";
    }

}
```

### 4. Deque

A deque is similar to lists when it comes to functionality.
While a list is implemented as a doubly linked list, a deque is implemented using a dynamic array.
So, random access is available in deque, meaning you can access elements by indexing.
Also, insertion and deletion at the beginning is faster in Deque than Lists.
Entire Code for Deque:

```CPP
void DequeFunction() {
deque<int> dq;
dq.push_back(10); // Adds 10 to the end of the deque (slower)
dq.emplace_back(100); // Adds 100 to the end of the deque (faster)
dq.push_front(20); // Adds 20 to the beginning of the deque (slower)
dq.insert(dq.begin() + 1, 6); // Adds 6 to the 2nd position of the deque

    cout<<"The 4th element of the deque is "<<dq[3];        // Will print the 4th element of the deque

}
```

### 5. Stack:

To understand how a stack works, imagine a can of Pringles. The chip which is put last in the can will be eaten (removed) first.
So we can say the last chip to get into the can will be the first one to get out. This is called LIFO (Last In First Out).
A stack follows a similar mechanism, the last element to be pushed into it will be the 1st to be removed.
In a stack, you cannot remove any element of your choice, like we could in deque, list and vectors. It has to follow the LIFO mechanism.
Random access, insertion in the beginning, etc. is not available in stacks.
There are 3 main functions in a stack:
push(): Will push an element to the top (end) of the stack. You can also use emplace().
pop(): Will remove the topmost (last) element from the stack.
top(): Will return the value of the topmost (last) element. This value will be removed from the stack if we perform pop() now.
But why would we use something with less functionality? Sometimes the restrictions in functionality help make the code less error-prone and more efficient.
Stacks are extremely powerful when it comes to time complexity. All the above stack operations have the time complexity O(1), which is the lowest time complexity possible. This means that the operations in stacks are extremely fast.
Some common functions of a stack are parenthesis matching and undo-redo in word processors, image editors, etc.
Entire Code for Stacks:

```CPP
void StackFunction() {
stack<int> stk;
stk.push(10); // Will push 10 to the end of the stack (slower)
stk.emplace(11); // Will push 11 to the end of the stack (faster)
stk.push(20);
stk.push(30);
cout<<"\nThe top element of the stack is "<<stk.top(); // Will print the top element of the stack

    cout<<"\nThe elements of a stack are:\n";
    while(!stk.empty()) {               // checks if the stack is empty
        cout<<stk.top()<<" ";           // prints the top element of the stack
        stk.pop();                      // Will remove the top element of the stack
    }

}
```

### 6. Queue:

Like a stack, a queue has some restrictions.
A queue is pretty self-explanatory, to understand the mechanism of a queue, you can simply imagine the line at a McDonald’s. The first person in the line gets served first and every new person joins the queue at the end.
Similarly, the first element in the queue will be removed first and new elements will be added in the end.
So a queue follows FIFO (First In First Out), the element first in the queue go out first.
You can access the first (front) and last (back) element in a queue. Insertion is from the front and deletion from the back.
There are 4 main functions in a queue:
push(): Will push an element to the back (end) of the queue. You can also use emplace().
pop(): Will remove the frontmost (1st) element from the stack.
front(): Will return the value of the frontmost (first) element. This value will be removed from the queue if we perform pop() now.
back(): Will return the value of the backmost (last) element. If we push a new element in the queue, it will inserted after this element.
Like stack, the restrictions make the available operations in queue extremely efficient and the time complexity of the above-mentioned queue operations is O(1).
Entire Code for Queues:

```CPP
void QueueFunction() {
queue<int> q;
q.push(10); // Will push 10 to the end of the queue (slower)
q.emplace(11); // Will push 11 to the end of the queue (faster)
q.push(20);
q.push(30);
cout<<"\nThe front element of the queue is "<<q.front(); // Will print the front element of the queue
cout<<"\nThe back element of the queue is "<<q.back(); // Will print the back element of the queue

    cout<<"\nThe elements of a queue are:\n";
    while(!q.empty()) {               // checks if the queue is empty
        cout<<q.front()<<" ";         // prints the front element of the queue
        q.pop();                      // Will remove the front element of the queue
    }

}
```

### 7. Priority Queue:

Despite being a ‘queue’, it is simple to visualize a priority queue (PQ) as a stack. The defining difference here is that the largest element will be at the top.
If it is a PQ of integers, the largest integer will be at the top. Similarly, if it a PQ of characters, the largest character will be at the top.
If it is a PQ of strings, the largest string lexicographically (alphabetically) will be at the top.
When you pop an element in a PQ, the largest element will be removed.
Similarly, top() will return the largest element.
A priority queue which has the largest element at the top is known as the maximum heap.
We can also define a priority queue in which the smallest element is at the top, this is known as the minimum heap.
Entire code for Priority Queue:

```CPP
void PriorityQueueFunction() {
// Maximum Heap (largest element at the top)
priority_queue<char> pq;
pq.push('x');
pq.emplace('s');
pq.emplace('a');
pq.emplace('g');
pq.emplace('z');

    cout<<"\nThe top element of the priority queue is "<<pq.top();      // Will print the top element of the priority queue
    pq.pop();

    cout<<"\nPrinting all the elements of the maximum heap priority queue:\n";
    while(!pq.empty()) {
        cout<<pq.top()<<" ";
        pq.pop();
    }

    // Minimum Heap (smallest element at the top)
    priority_queue<char, vector<char>, greater<char>> pq1;
    pq1.push('x');
    pq1.emplace('s');
    pq1.emplace('a');
    pq1.emplace('g');
    cout<<"\n\nPrinting all the elements of the minimum heap priority queue:\n";
    while(!pq1.empty()) {
        cout<<pq1.top()<<" ";
        pq1.pop();
    }

}
```

### 8. Set:

A set contains only unique elements, and they are sorted.
Internally, a set is maintained using the tree data structure but you can imagine it as a bucket containing only unique elements sorted in ascending order.
Everything in sets has the time complexity O(log(n)).
We can define a set as follows: set<int> s;
To insert an element, we can use insert() (which is slower), as well as emplace() (which is faster).
We can delete one or more elements with iterators using the erase() function.
We can also directly insert the value of an element in the erase() function to delete it.
Iterators in Set:
Similar to some other containers we learnt about earlier, iterators can be used for traversal as well as finding a specific element.
find() function takes an element as an input and returns the memory location (iterator) of the element in the set.
If the element is not available in the set, then it returns the value of iter.end().
So we can create an if else condition to check if an element is present.
// We can use iterators to traverse through the set or find a specific element

```CPP
set<int>::iterator it = s.begin(); // Iterator pointing to the first element of the set
cout<<"\nThe elements of the set are:\n";
for (it = s.begin(); it != s.end(); it++) {
cout<<\*it<<" ";
}

auto it2 = s.find(5); // Will return an iterator pointing to the element 20 in the set
auto it3 = s.find(14); // Will return an iterator pointing to the end of the set as 14 is not present in the set
if (it3 == s.end()) {
cout<<"\n14 is not present in the set";
}
else {
cout<<"\nElement Found!";
}
```

```CPP
Entire Code for Sets:
void SetFunction() {
set<int> s;
s.insert(10); // Will insert 10 to the set (Slower)
s.insert(5);
s.insert(20);
s.emplace(30); // Will insert 30 to the set (Faster)
s.emplace(60);
s.emplace(5); // Will not be inserted as 5 is already in the set

    // We can use iterators to traverse through the set or find a specific element
    set<int>::iterator it = s.begin();          // Iterator pointing to the first element of the set
    cout<<"\nThe elements of the set are:\n";
    for (it = s.begin(); it != s.end(); it++) {
        cout<<*it<<" ";
    }

    auto it2 = s.find(5);           // Will return an iterator pointing to the element 20 in the set
    auto it3 = s.find(14);          // Will return an iterator pointing to the end of the set as 14 is not present in the set
    if (it3 == s.end()) {
        cout<<"\n14 is not present in the set";
    }

    s.erase(30);                        // Removes 30 from the set
    s.erase(s.begin());                 // Removes the first element of the set
    s.erase(s.begin(), s.end());        // Removes all the elements of the set

}
```

### 9. Multiset:

A multiset stores elements in an ordered fashion. Unlike sets, a multiset can have the same element more than once.
Insertion is similar to sets, where you can use insert() as well as emplace().
To delete elements, again, we use the erase() function.
We can use this function to delete elements by passing in the element as the argument or the pointer.
erase(100): ALL the occurrences of 100 will be deleted from the multiset.
To delete, say, only the 1st occurrence of 100 in a multiset ms, we can write:
ms.erase(ms.find(100));
We can use the count() function to count the number of occurrences of a specific element.
Entire Code for Multiset:

```CPP
void MultiSetFuction() {
multiset<int> ms;
ms.insert(10); // Will insert 10 to the multiset (Slower)
ms.insert(5);
ms.emplace(20); // Will insert 20 to the multiset (Faster)
ms.emplace(10); // A multiset can have duplicate elements
    ms.emplace(5);
ms.emplace(5);

    cout<<ms.count(10)<<endl;       // Will return the number of times 10 occurs in the multiset

    ms.erase(10);                   // Will erase ALL the occurences of 10
    auto it1 = ms.find(5);
    advance(it1, 2);
    ms.erase(ms.find(5), it1);      // Will erase the 1st 2 occurences of 5 as we erase the elements stored at the memory location pointed by the iterators
    cout<<ms.count(10)<<endl;       // Will return 0 as all occurences of 10 have been deleted

}
```

### 10. Unordered Set:

It stores only unique elements like a set.
Unlike sets, it stores elements in a random order.
So, if you insert the elements 10, 20, 30, in that order, inside the unordered set, they may be stored as 20, 10, 30, or any other random order.
All the operations are similar to sets.
Entire code for Unordered Set:

```CPP
void UnorderedSetFunction() {
unordered_set<int> us;
us.insert(10); // Will insert 10 to the unordered set (Slower)
us.insert(20);
us.insert(30);
us.insert(40);
us.emplace(50); // Will insert 50 to the unordered set (Faster)

    cout<<"\nThe elements of the unordered set are:\n";
    for (auto it : us) {
        cout<<it<<" ";
    }

}
```

### 11. Map:

A map contains a key and a value, they can be of any data type.
A key has to be unique while values can be duplicates.
A map stores elements in a sorted order (according to keys).
It is comparable to phone number and name in real life. Keys can be considered as phone numbers, which are always unique, while the name of the person owning the phone number can be considered values, which may repeat.
To delete an element, we can use the erase() function.
m.erase(1) will erase the element with the key = 1 from the map.
We can also delete elements using iterators in the erase() functions as we’ve done earlier with other data structures.
m.lower_bound(5); points to the smallest element whose key is greater than 5. So if m contains {1, 2}, {4, 10}, {6, 29}, {19, 3}, then, the above statement will point at the element {6, 29}.
m.upper_bound(10); points to the largest element whose key is less than 10. If m contains {2, 5}, {5, 14}, {30, 2}, {56, 1}, then, the above statement will point at the element {5, 14}.
Insertion in Maps:
You can add elements into the map using the insert() function, enclosing the key and value in { }.
m.insert({5, 10}); will insert an element with key = 5 and value = 10.
You can insert elements into the map similarly using emplace(). Here, you do not need to use the { }.
m.insert(1, 5); will add an element whose key = 1 and value = 5.
A simpler way to add elements is this:
m[7] = 74;

where a new element is added with 7 as the key and 74 as the value.

```CPP
Entire Code for Maps:
void MapFunction() {
map<int, int> m;
m.insert({1, 0}); // Here, 1 is the key and 0 is value
m.emplace(10, 58); // Here, 10 is the key and 58 is the value
m[8] = 3; // Here, 8 is the key and 3 is the value
m[5] = 0;
m[100] = 53;

    m.erase(10);                // Will delete the element with key = 10
    auto it = m.begin();
    advance(it, 2);
    m.erase(m.begin(), it);     // Will delete the first 2 elements in the map

    // Printing all the elements in the map m
    cout<<"\nPrinting all the elements in a map:\n";
    for (auto it : m) {
        cout<<"Key: "<<it.first<<" Value: "<<it.second<<endl;
    }

}
```

### 12. Multimap:

A multimap is like maps with one key difference: multimaps can have duplicate keys with different values.
This means that all the keys in a multimap need not be unique. The multimap stores elements in a sorted order though, like a map.
Most operations of a multimap are similar to those of maps.
In multimap, you cannot define new elements in the following way: mm[5] = 2;.
You can still use insert() and emplace().
Entire code for Multimaps:

```CPP
void MultiMapFunction() {
multimap<int, int> mm;
mm.emplace(10, 20); // Adds 10, 20 to the multimap (faster)
mm.emplace(10, 30);
 mm.insert({1, 3}); // Adds 1, 3 to the multimap (slower)
mm.insert({2, 5});

    // Printing all the elements in the multimap mm
    cout<<"\nPrinting all the elements in a multimap:\n";
    for (auto it : mm) {
        cout<<"Key: "<<it.first<<" Value: "<<it.second<<endl;
    }

}
```

### 13. Unordered Map:

Unordered maps are similar to maps with one key difference: unordered maps are not sorted.
For most operations, the time complexity of any operation on an unordered map is O(1), but it can be O(n) in some edge-cases.
An unordered map can only contain unique keys, like a map.
Entire Code for Unordered Map:

```CPP
void UnorderedMapFunction() {
unordered_map<int, int> um;
um.emplace(10, 20); // Will insert 10, 20 in the unordered map (faster)
um.emplace(1, 4);
um.insert({2, 5}); // Will insert 2, 5 in the unordered map (slower)
um.insert({6, 5});

    // Printing all the elements in the unordered map um
    cout<<"\nPrinting all the elements in an unordered map:\n";
    for (auto it : um) {
        cout<<"Key: "<<it.first<<" Value: "<<it.second<<endl;
    }

}
```

### 14. Sorting:

In C++ STL, you can sort various data structures like stacks, vectors, etc. using the sort() function.
STL already uses the best implementation of sorting, making sorting data very efficient in C++.
To sort the entire vector v in ascending order:

```CPP
sort(v.begin(), v.end()); // Will sort the vector in ascending order
```

To sort the entire vector v in descending order:

```CPP
sort(v.begin(), v.end(), greater<int>()); // Will sort the vector in descending order
```

To sort the 1st to 3rd element in ascending order:

```CPP
auto it2 = v.begin();
advance(it2, 4); // We advance by 4 as 2nd element is non-inclusive in .sort()
sort(v.begin(), it2); // Will sort the vector from the 1st to 3rd element in ascending order
cout<<"\n\nPrinting the elements of the vector after sorting from the 1st to 3rd element in ascending order:\n";
for (auto it : v) {
cout<<it<<" ";
}
```
