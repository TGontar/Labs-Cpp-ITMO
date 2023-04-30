#ifndef LAB6_CUSTOM_ALGORITHMS_H
#define LAB6_CUSTOM_ALGORITHMS_H

#include "string"

//if all of container's elements correspond to predicate
template <typename It, typename P>
bool all_of(It first, It last, P predicate) {
    for (It i = first; i != last; i++) {
        if (predicate(*i) == false) {
            return false;
        }
    }

    return true;
}

//if the container is partitioned in 2 parts
template <typename It, typename P>
bool is_partitioned(It first, It last, P predicate) {
    //find the first one which doesn't correspond to pred
    for (first; first != last; first++) {
        if (predicate(*first) == false) {
            break;
        }
    }

    //the range is already partitioned
    if (first == last) {
        return true;
    }

    //if there's an element after current, which correspond to the predicate - the container isn't partitioned
    first++;
    for (first; first != last; first++) {
        if (predicate(*first) == true) {
            return false;
        }
    }

    return true;
}

//find first element from the end which is equal to given
template <typename It, typename P, typename V>
It find_backward(It begin, It end, P predicate, V value) {
    for (end; end != begin; end--) {
        if (predicate(*end, value)) {
            return end;
        }
    }

    //the element isn't in the range
    throw "The element isn't in range";
}

#endif //LAB6_CUSTOM_ALGORITHMS_H
