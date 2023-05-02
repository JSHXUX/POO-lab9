#pragma once
#include <iostream>
template <typename K, typename V>
class Map
{
private:
    struct harta
    {
        K key;
        V value;
        int index;
    }*h;
    int count;
    int index_mod;
public:
    Map() :h(nullptr), count(0), index_mod(0) {}
    Map& operator[](K x)
    {
        for (int i = 0; i < this->count; i++)
            if (this->h[i].key == x)
            {
                this->index_mod = i;
                return (*this);
            }
        harta* aux = new harta[count + 1];
        for (int i = 0; i < this->count; i++)
        {
            aux[i].key = this->h[i].key;
            aux[i].value = this->h[i].value;
            aux[i].index = this->h[i].index;
        }
        aux[this->count].key = x;
        aux[this->count].index = count;
        delete[] this->h;
        this->h = aux;
        this->index_mod = this->count;
        this->count++;
        return (*this);
    }
    void operator=(V x)
    {
        this->h[this->index_mod].value = x;
    }
    harta* begin()
    {
        return &(this->h[0]);
    }
    harta* end()
    {
        return &(this->h[this->count]);
    }
    void Set(K x, V y)
    {
        (*this)[x] = y;
    }
    bool Get(const K& key, V& value)
    {
        for (int i = 0; i < this->count; i++)
            if (this->h[i].key == key)
            {
                value = this->h[i].value;
                return true;
            }
        return false;
    }
    int Count()
    {
        return this->count;
    }
    void Clear()
    {
        delete[] this->h;
        this->count = 0;
        this->index_mod = 0;
    }
    bool Delete(const K& key)
    {
        for (int i = 0; i < this->count; i++)
            if (this->h[i].key == key)
            {
                harta* aux = new harta[count - 1];
                for (int j = 0; j < i; j++)
                {
                    aux[j].key = this->h[j].key;
                    aux[j].value = this->h[j].value;
                    aux[j].index = this->h[j].index;
                }
                for (int j = i+1; j < this->count; j++)
                {
                    aux[j-1].key = this->h[j].key;
                    aux[j-1].value = this->h[j].value;
                    aux[j-1].index = this->h[j].index-1;
                }
                delete[] this->h;
                this->h = aux;
                this->count--;
                return true;
            }
        return false;
    }
    bool Includes(const Map<K, V>& map)
    {
        V aux;
        for (int i = 0; i < map.count; i++)
            if (!this->Get(map.h[i].key, aux))
                return false;
        return true;
    }
};