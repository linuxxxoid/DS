#ifndef hash_table_h
#define hash_table_h

#include <iostream>
#include <vector>
#include <string>


class HashTable {
public:
    bool operator [](HashTable const& i);
    
    HashTable();
    HashTable(int64_t length);
    int64_t HashFunction(int64_t key);
    int64_t DoubleHashFunction(int64_t hash);
    
    void Add(int64_t key, int64_t value);
    HashTable* Find(int64_t key);
    bool Delete(int64_t key);
    
    void Resize();
    
    int64_t GetValue();
    ~HashTable();
private:
    std::vector<HashTable> hash_table;
    int64_t size;
    int64_t capacity;
    int64_t key;
    int64_t value;
    bool is_null;
};

#endif /* hash_table_h */
