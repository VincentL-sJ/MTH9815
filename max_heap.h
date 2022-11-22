//
//  max_heap.hpp
//  MTH9815 Quiz1 Exercixe 2 & 3
//

#ifndef max_heap_hpp
#define max_heap_hpp

#include <vector>
#include <utility>

class MaxHeap {
private:
    std::vector<int> data_;
    
    std::size_t get_parent(std::size_t idx) const;
    std::pair<std::size_t, std::size_t> get_children(std::size_t idx) const;
    
    void print() const;
    
public:
    MaxHeap() = default;
    ~MaxHeap() = default;
    int get_size();
    int top() const;
    void add(int elem);
    int pop();
    
    bool is_empty() const;
};

#endif /* max_heap_hpp */

