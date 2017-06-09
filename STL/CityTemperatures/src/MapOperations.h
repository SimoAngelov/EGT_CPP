/*
 * MapOperations.h
 *
 *  Created on: Jun 9, 2017
 *      Author: SimoAngelov
 */

#ifndef MAPOPERATIONS_H_
#define MAPOPERATIONS_H_

#include <iostream>
using std::string;
using std::pair;
using std::cout;
using std::endl;
#include <vector>
using std::vector;
#include <map>
using std::map;
using std::multimap;

template <typename K, typename V> vector<pair<K, V> > SortMultimapByValue(multimap<K, V>& unsortedMap)
{
	vector<pair<K, V> > result;
	multimap<V, K> valToKey;
	typename multimap<K, V>::iterator unsortedIt;
	//push the key-value pairs from the original map into into a multimap
	//switching the positions of the value and key. that way the multimap
	//will sort the map by values.
	for(unsortedIt = unsortedMap.begin(); unsortedIt != unsortedMap.end(); ++unsortedIt)
	{
		K currentKey = unsortedIt->first;
		V currentValue = unsortedIt->second;
		pair<V, K> currentPair = make_pair(currentValue, currentKey);
		valToKey.insert(currentPair);
	}
	typename multimap<V, K>::iterator sortedIt;
	for(sortedIt = valToKey.begin(); sortedIt != valToKey.end(); ++sortedIt)
	{
		K currentKey = sortedIt->second;
		V currentValue = sortedIt->first;
		pair<K, V> currentPair = make_pair(currentKey, currentValue);
		result.push_back(currentPair);
	}
	return result;
}

template <typename K, typename V> void PrintVectorOfPairs(const vector<pair<K, V> >& vectPairs)
{
	typename vector<pair<K, V> >::const_iterator it;
	cout << "Key\t  Value" << endl;
	for(it = vectPairs.begin(); it != vectPairs.end(); ++it)
	{
		K key = it->first;
		V val = it->second;
		cout << key << "\t  " << val << endl;
	}
}

template <typename K, typename V> void PrintMultimap(const multimap<K, V>& mapArg)
{
	typename multimap<K, V>::const_iterator mapIt;
	cout << "Key\t   Value" << endl;
	for(mapIt = mapArg.begin(); mapIt != mapArg.end(); ++mapIt)
	{
		K key = mapIt->first;
		V val = mapIt->second;
		cout << key << "\t   " << val << endl;
	}
}



#endif /* MAPOPERATIONS_H_ */
