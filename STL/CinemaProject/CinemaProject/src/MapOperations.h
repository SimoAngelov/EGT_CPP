/*
 * MapOperations.h
 *
 *  Created on: Jun 3, 2017
 *      Author: SimoAngelov
 */

#ifndef MAPOPERATIONS_H_
#define MAPOPERATIONS_H_

template <typename Key, typename Value>
bool isKeyInMap(std::map<Key, Value> &theMap, const Key &key) {
    return theMap.find(key) != theMap.end();
}

template <typename Key, typename Value>
Value &getFromMap(std::map<Key, Value> &theMap, const Key &key) {
    return theMap.find(key)->second;
}

template <typename Key, typename Value>
void putInMap(std::map<Key, Value> &theMap, const Key &key, const Value &val) {
    theMap[key] = val;
    // theMap.insert(make_pair(key, val));
}

template <typename Key, typename Value>
void delKeyInMap(std::map<Key, Value> theMap, const Key &key) {
    theMap.erase(theMap.find(key));
}

template <typename T> bool compare (T i, T j)
{
	return (i < j);
}



#endif /* MAPOPERATIONS_H_ */
