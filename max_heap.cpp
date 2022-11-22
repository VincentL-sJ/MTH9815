
//  max_heap.cpp
//  MTH9815 Quiz1 Exercise 2 & 3
//

#include "max_heap.h"
#include <stdexcept>
#include <iostream>

void MaxHeap::print() const {
    for (int elem : data_) {
        std::cout << elem << '\t';
    }
    std::cout << std::endl;
}

int MaxHeap::get_size() const {
    return data_.size();
}

std::size_t MaxHeap::get_parent(std::size_t idx) const {
    if (idx == 0) {
        throw std::out_of_range("Top element");
        return 0;
    }
    if (idx % 2) {
        return (idx - 1) >> 1;
    } else {
        return (idx - 2) >> 1;
    }
}
std::pair<std::size_t, std::size_t> MaxHeap::get_children(std::size_t idx) const {
    return std::make_pair((idx << 1) + 1, (idx << 1) + 2);
}

int MaxHeap::top() const {
    return data_.front();
}

void MaxHeap::add(int elem) {
    data_.push_back(elem);
    
    std::size_t curr = data_.size() - 1;
    
    while (curr && (data_[curr] > data_[this->get_parent(curr)])) {
        std::swap(data_[curr], data_[this->get_parent(curr)]);
        curr = this->get_parent(curr);
    }
}

int MaxHeap::pop() {
    
    int res = data_.front();
    
    data_.front() = data_.back();
    data_.resize(data_.size() - 1);
    
    std::size_t curr = 0;
    while (true) {
        std::size_t l_child;
        std::size_t r_child;
        std::tie(l_child, r_child) = this->get_children(curr);
        
        bool l_wrong = (l_child < data_.size()) && (data_[curr] < data_[l_child]);
        bool r_wrong = (r_child < data_.size()) && (data_[curr] < data_[r_child]);
        
        int switch_r;
        
        if (l_wrong && r_wrong) {
            if (data_[l_child] > data_[r_child]) {
                switch_r = 0;
            } else {
                switch_r = 1;
            }
        } else if (l_wrong) {
            switch_r = 0;
        } else if (r_wrong) {
            switch_r = 1;
        } else {
            break;
        }
        
        switch (switch_r) {
            case 0:
                std::swap(data_[curr], data_[l_child]);
                curr = l_child;
                break;
            case 1:
                std::swap(data_[curr], data_[r_child]);
                curr = r_child;
                break;
        }
    }
    return res;
}


bool MaxHeap::is_empty() const {
    return data_.size() == 0;
}
