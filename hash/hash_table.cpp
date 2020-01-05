#include "hash_table.h"

HashTable::HashTable() {
//    size = 5;
    key = 0;
    value = 0;
    capacity = 0;
    size = 5;
    is_null = true;
    hash_table.resize(size, {-1});
    for (int i = 0; i < size; ++i) {
        hash_table[i].is_null = true;
        hash_table[i].key = 0;
        hash_table[i].value = 0;
    }
}

HashTable::HashTable(int64_t length) : size(length) {
    for (int i = 0; i < size; ++i) {
        hash_table[i].is_null = true;
        hash_table[i].key = 0;
        hash_table[i].value = 0;
        ++capacity;
    }
}

int64_t HashTable::HashFunction(int64_t key) {
    int64_t hash = key % size; //TODO: think about smth really cool
    return hash;
}

int64_t HashTable::DoubleHashFunction(int64_t hash) {
    int64_t newhash = hash % capacity + 1; //TODO: think about smth really cool
    return newhash;
}

void HashTable::Add(int64_t key, int64_t value) {
    int64_t hashIndex = HashFunction(key);
    ++capacity;
    while (!hash_table[hashIndex].is_null) {
        if (capacity >= size) {
            Resize();
        }
        hashIndex = DoubleHashFunction(key);
    }
 

    hash_table[hashIndex].is_null = false;
    hash_table[hashIndex].key = key;
    hash_table[hashIndex].value = value;
}

HashTable* HashTable::Find(int64_t key) {
    int64_t hashIndex = HashFunction(key);
    while (!hash_table[hashIndex].is_null) {
        if (key == hash_table[hashIndex].key) {
            return &hash_table[hashIndex];
        } else {
            hashIndex = DoubleHashFunction(key);
        }
    }
    return nullptr;
}

bool HashTable::Delete(int64_t key) {
    HashTable* ht = Find(key);
    if (Find(key) != nullptr) {
        ht->key = NULL;
        ht->value = NULL;
        ht->is_null = true;
    } else {
        return false;
    }
    return true;
}

void HashTable::Resize() {
    size *= 2;  //TODO: change that pls
}

int64_t HashTable::GetValue() {
    return value;
}

HashTable::~HashTable() {
    
}



