
#include <iostream>
#include "hash_table.h"

int main(int argc, const char * argv[]) {
    bool flag = true;
    HashTable* ht = new HashTable();
    while(flag) {
        std::cout << "Hello, enter what do you want to do!\n";
        std::cout << "1 - ADD element!\n";
        std::cout << "2 - FIND element!\n";
        std::cout << "3 - DELETE element\n";
        std::cout << "4 - SHOW the hash table\n";
        std::cout << "0 - EXIT\n";

        int choice;
        std::cin >> choice;
        int64_t value, key;
        if (choice == 1) {
            std::cout << "ENTER   [key]   [value]: \n";
            std::cin >> key >> value;
            ht->Add(key, value);
        } else if (choice == 2) {
            std::cout << "ENTER   [key] :\n";
            std::cin >> key;
            if (ht->Find(key) != nullptr) {
                std::cout << ht->GetValue();
            } else {
                std::cout << "The element doesn't exist!\n";
            }
        } else if (choice == 3) {
            std::cout << "ENTER   [key] :\n";
            std::cin >> key;
            if (ht->Delete(key)) {
                std::cout << "The element was removed!\n";
            } else {
                std::cout << "The element doesn't exist!\n";
            }
        } else {
            flag = false;
        }
    }
    
    return 0;
}
