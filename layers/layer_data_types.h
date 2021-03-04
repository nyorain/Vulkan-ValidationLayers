#pragma once
#include <iterator>
#include "robin_hood.h"

namespace layers {
template <typename Key, typename Hash = robin_hood::hash<Key>, typename KeyEqual = std::equal_to<Key> >
using unordered_set = robin_hood::unordered_set<Key, Hash, KeyEqual>;

template <typename Key, typename T, typename Hash = robin_hood::hash<Key>, typename KeyEqual = std::equal_to<Key> >
using unordered_map = robin_hood::unordered_map<Key, T, Hash, KeyEqual>;

template <typename T>
class insert_iterator : public std::iterator<std::output_iterator_tag, void,void,void,void > {
public:
    typedef typename T::value_type value_type;
    typedef typename T::iterator iterator;
    insert_iterator(T& t, iterator i)
      : container(&t), iter(i) {}

    insert_iterator& operator=(const value_type& value)
    {
        auto result = container->insert(value);
        iter = result.first;
        ++iter;
        return *this;
    }

   insert_iterator& operator=(value_type&& value)
      {
        auto result = container->insert(std::move(value));
        iter = result.first;
        ++iter;
        return *this;
      }

      insert_iterator& operator*() { return *this; }

      insert_iterator& operator++() { return *this; }

      insert_iterator& operator++(int) { return *this; }
private:
    T* container;
    typename T::iterator iter;
};

};
