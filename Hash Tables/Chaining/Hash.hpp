#include "Hash.h"

void Hash::insertItem(int key)
{
    int idx = hashFunction(key);
    hashTable[idx].push_back(key);
}

void Hash::deleteItem(int key)
{
    int idx = hashFunction(key);
    
    list<int> :: iterator i;
    
    for(i=hashTable[idx].begin(); i!=hashTable[idx].end(); i++)
    {
        if(*i == key)
            break;
    }
    
    if(i!= hashTable[idx].end())
        hashTable[idx].erase(i);
}

void Hash::displayHash()
{
    for(int i=0; i< buckets; i++)
    {
        cout<<i<<" | ";
        for(auto x: hashTable[i])
            cout<<"--> "<<x;
        cout<<endl;
    }
}