#ifndef HASH_H
#define HASH_H

#include <bits/stdc++.h>
using namespace std;

class Hash
{
    int buckets;
    list<int> *hashTable;
    
    public:
        // Constructor
        Hash(int V): buckets(V), hashTable(new list<int>[buckets]) {}
        
        // Insert key into hash table
        void insertItem(int key);
        
        // Delete a key from hash table
        void deleteItem(int key);
        
        // Hash function to map values to hashTable
        int hashFunction(int key) { return (key % buckets);}
        
        // Display hashTable
        void displayHash();
    
};


#include "Hash.hpp"
#endif