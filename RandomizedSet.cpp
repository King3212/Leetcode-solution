#include<vector>
#include<cmath>
using namespace std;

#define hashSize 65536

class RandomizedSet {
public:
    vector<vector<int>*> *nums;
    
    int notEmptySet = 0;

    RandomizedSet() {
        nums = new vector<vector<int>*>(hashSize,nullptr);
    }
    
    bool insert(int val) {
        int index = val % hashSize;
        if(index < 0) index += hashSize;
        if((*nums)[index] == nullptr){
            (*nums)[index] = new vector<int>();
            (*nums)[index]->push_back(val);
            notEmptySet += 1;
            return true;
            
        }
        for (auto i : *((*nums)[index]))
        {
            if (i == val)
            {
                return false;
            }
            
        }
        (*nums)[index]->push_back(val);
        return true;
    }
    
    bool remove(int val) {
        int index = val % hashSize;
        if(index < 0) index += hashSize;
        if((*nums)[index] == nullptr){
            return false;
        }
        for (auto i = (*nums)[index]->begin(); i != (*nums)[index]->end(); i++)
        {
            if (*i == val)
            {
                (*nums)[index]->erase(i);
                if ((*nums)[index]->size() == 0)
                {
                    delete (*nums)[index];
                    (*nums)[index] = nullptr;
                }
                
                return true;
            }
            
        }
        return false;
    }
    
    int getRandom() {
    // 选择一个随机的非空bucket
    int index = rand() % notEmptySet;

    // 遍历寻找非空的bucket
    for (int i = 0; i < nums->size(); i++) {
        if ((*nums)[i] != nullptr) {
            if (index == 0) {
                // 从找到的非空bucket中随机选择一个元素
                int elementIndex = rand() % (*nums)[i]->size();
                return (*(*nums)[i])[elementIndex];
            }
            index--; // 仅当遇到非空bucket时才递减
        }
    }

    // 正常情况下代码不会到达这里，因为总会有非空bucket
    return -1;
}

};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */

#include <iostream>
using namespace std;

int main() {
    RandomizedSet* obj = new RandomizedSet();
    cout << boolalpha; // 输出布尔值为 true/false 而不是 1/0

    // 执行操作并输出结果
    cout << "insert(-1): " << obj->insert(-1) << endl; // 应输出 true
    cout << "remove(-2): " << obj->remove(-2) << endl; // 应输出 false
    cout << "insert(-2): " << obj->insert(-2) << endl; // 应输出 true
    cout << "getRandom(): " << obj->getRandom() << endl; // 应输出 -1 或 -2
    cout << "remove(-1): " << obj->remove(-1) << endl; // 应输出 true
    cout << "insert(-2): " << obj->insert(-2) << endl; // 应输出 false
    cout << "getRandom(): " << obj->getRandom() << endl; // 应输出 -2

    delete obj;
    return 0;
}