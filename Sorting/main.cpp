#include <vector>
#include <iostream>
// {2, 1}
std::vector<int> bubble_sort(std::vector<int> v) {
    for (int step = 0; step < v.size(); ++step) {

        // loop to compare array elements
        for (int i = 0; i < v.size() - step; ++i) {

            // compare two adjacent elements
            // change > to < to sort in descending order
            if (v[i] > v[i + 1]) {

                // swapping elements if elements
                // are not in the intended order
                int temp = v[i];
                v[i] = v[i + 1];
                v[i + 1] = temp;
            }
        }
    }
    return v;
}

// Virtualization of the bubble sort algorithm
// @pre: None
// @post: Returns a sorted vector
// 11, 5,1,10,11,1
// 5, 1,10,11,1,11
// 1, 5,10,11,1,11
// 1, 5,10,1,11,11
// 1, 5,1,10,11,11
// 1, 1,5,10,11,11
// 1, 1,5,10,11,11


std::vector<int> quick_sort(std::vector<int> v) {
    if (v.size() <= 1) {
        return v;
    }
    int pivot = v[v.size() / 2];
    std::vector<int> left;
    std::vector<int> right;
    for (int i : v) {
        if (i < pivot) {
            left.push_back(i);
        } else if (i > pivot) {
            right.push_back(i);
        }
    }
    std::vector<int> result;
    std::vector<int> left_sorted = quick_sort(left);
    std::vector<int> right_sorted = quick_sort(right);
    result.insert(result.end(), left_sorted.begin(), left_sorted.end());
    result.push_back(pivot);
    result.insert(result.end(), right_sorted.begin(), right_sorted.end());
    return result;
}

int masin() {
    std::vector<int> arr = {11, 5,1,10,11,1};
    for( auto i : bubble_sort(arr)) {
        std::cout << i << " ";
    }
//    std::cout << "Hello, World!" << std::endl;
    return 0;
}

// Q: What are shared pointers?
// A: Shared pointers are a smart pointer that keeps track of the number of references to a pointer. When the number of references reaches 0, the pointer is deleted.

// Q: What are weak pointers?
// A: Weak pointers are a smart pointer that does not increase the reference count of the pointer it points to. This is useful when you want to check if a pointer is still valid without increasing the reference count.

// Q: What is the reference count of a pointer?
// A: The reference count of a pointer is the number of references to that pointer. When the reference count reaches 0, the pointer is deleted.

// Q: What is the difference between a shared pointer and a weak pointer?
// A: A shared pointer increases the reference count of the pointer it points to. A weak pointer does not increase the reference count of the pointer it points to.

int main()
{
std::shared_ptr<int> w = std::make_shared<int>(10);
auto k = w; // k is a shared pointer that points to the same object as w
std::shared_ptr<int> k1 = w; // k1 is a shared pointer that points to the same object as w
std::shared_ptr<int> k3 = w;  // k3 is a shared pointer that points to the same object as w
std::weak_ptr<int> w2 = w; // w2 is a weak pointer that points to the same object as w
std::cout << w.use_count() << std::endl; // 4
std::cout << w2.use_count() << std::endl; // 1
//std::cout << w2.expired() << std::endl; // 0
w2.reset(); // w2 is no longer pointing to the object w points to and the reference count of the object w points to is now 3
std::cout << w.use_count() << std::endl; //
//w.reset();
//std::cout << w2.use_count() << std::endl; // 0
//std::cout << w2.expired() << std::endl; // 1
return 0;
}


// Q: Why does the reference count of the object w points to do not decrease when w2 is reset?
// A: The reference count of the object w points to does not decrease when w2 is reset because w2 is a weak pointer and does not increase the reference count of the object it points to.