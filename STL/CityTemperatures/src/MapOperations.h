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
#include <iomanip>
using std::setw;
#include <vector>
using std::vector;
#include <map>
using std::map;
using std::multimap;
#include <algorithm>
using std::sort;

template <typename K, typename V>
multimap<K, V> ValueFromVectorToElements(const map<K, vector<V> >& mapArg)
{
	multimap<K, V> result;
	typename map<K, vector<V> >::const_iterator mapIt;
	typename vector<V>::const_iterator vecIt;

	for (mapIt = mapArg.begin(); mapIt != mapArg.end(); ++mapIt)
	{
		K key = mapIt->first;
		vector<int> vectorV = mapIt->second;
		for (vecIt = vectorV.begin(); vecIt != vectorV.end(); ++vecIt)
		{
			V value = *vecIt;
			result.insert(make_pair(key, value));
		}
	}
	return result;
}


template <typename K, typename V>
vector<pair<K, V> > SortMultimapByValue(const multimap<K, V>& unsortedMap)
{
	//vector of pairs to keep the sorted order by values;
	vector<pair<K, V> > result;
	multimap<V, K> valToKey;
	typename multimap<K, V>::const_iterator unsortedIt;
	//push the key-value pairs from the original map into into a multimap
	//switching the positions of the value and key. that way the multimap
	//will sort the map by values.
	for(unsortedIt = unsortedMap.begin(); unsortedIt != unsortedMap.end();
			++unsortedIt)
	{
		K currentKey = unsortedIt->first;
		V currentValue = unsortedIt->second;
		pair<V, K> currentPair = make_pair(currentValue, currentKey);
		valToKey.insert(currentPair);
	}
	typename multimap<V, K>::iterator sortedIt;
	for(sortedIt = valToKey.begin(); sortedIt != valToKey.end();
			++sortedIt)
	{
		K currentKey = sortedIt->second;
		V currentValue = sortedIt->first;
		pair<K, V> currentPair = make_pair(currentKey, currentValue);
		result.push_back(currentPair);
	}
	return result;
}


template <typename K, typename V>
vector<pair<K, V> > SortMapByValue(const map<K, V>& unsortedMap)
{
	//vector of pairs to keep the sorted order by values;
	vector<pair<K, V> > result;
	map<V, K> valToKey;
	typename map<K, V>::iterator unsortedIt;
	//push the key-value pairs from the original map into into a imap
	//switching the positions of the value and key. that way the map
	//will sort the map by values.
	for(unsortedIt = unsortedMap.begin(); unsortedIt != unsortedMap.end();
			++unsortedIt)
	{
		K currentKey = unsortedIt->first;
		V currentValue = unsortedIt->second;
		pair<V, K> currentPair = make_pair(currentValue, currentKey);
		valToKey.insert(currentPair);
	}
	typename multimap<V, K>::iterator sortedIt;
	for(sortedIt = valToKey.begin(); sortedIt != valToKey.end();
			++sortedIt)
	{
		K currentKey = sortedIt->second;
		V currentValue = sortedIt->first;
		pair<K, V> currentPair = make_pair(currentKey, currentValue);
		result.push_back(currentPair);
	}
	return result;
}

//if the value of a map is a vector
template<typename K, typename V>
void SortMapByVector(map<K, vector<V> >& unsortedMap)
{
	typename map<K, vector<V> >::iterator mapIt;
	for(mapIt = unsortedMap.begin(); mapIt != unsortedMap.end();
			++mapIt)
	{
		vector<V> currentVector = mapIt->second;
		sort(currentVector.begin(), currentVector.end());
		mapIt->second = currentVector;
	}
}


//Printing functions
template <typename K, typename V>
void PrintVectorOfPairs(const vector<pair<K, V> >& vectPairs,
		const string& keyName, const string& valName)
{
	typename vector<pair<K, V> >::const_iterator it;
	cout << left << setw(15) << keyName << setw(15) << valName << endl;
	for(it = vectPairs.begin(); it != vectPairs.end(); ++it)
	{
		K key = it->first;
		V val = it->second;
		cout << left << setw(15) << key << setw(15)<< val << endl;
	}
}

template <typename K, typename V>
void PrintMap(const multimap<K, V>& mapArg,
		const string& keyName, const string& valName)
{
	typename map<K, V>::const_iterator mapIt;
	cout << left << setw(15) << keyName << setw(15) << valName << endl;
	for(mapIt = mapArg.begin(); mapIt != mapArg.end(); ++mapIt)
	{
		K key = mapIt->first;
		V val = mapIt->second;
		cout << left << setw(15) << key << setw(15)<< val << endl;
	}
}

template <typename K, typename V>
void PrintMultimap(const multimap<K, V>& mapArg,
		const string& keyName, const string& valName)
{
	typename multimap<K, V>::const_iterator mapIt;

	cout << left << setw(15) << keyName << setw(15) << valName << endl;
	for(mapIt = mapArg.begin(); mapIt != mapArg.end(); ++mapIt)
	{
		K key = mapIt->first;
		V val = mapIt->second;
		cout << left << setw(15) << key << setw(15)<< val << endl;
	}
}

template <typename K, typename V>
void PrintMapVector(const map<K, vector<V> >& mapArg,
		const string& keyName, const string& valName)
{
	typename map<K, vector<V> >::const_iterator mapIt;
	typename vector<V>::const_iterator vectorIt;

	cout << left << setw(15) << keyName << setw(15) << valName << endl;
	for (mapIt = mapArg.begin(); mapIt != mapArg.end(); ++mapIt)
	{
		K key = mapIt->first;
		vector<V> vec = mapIt->second;
		for(vectorIt = vec.begin(); vectorIt != vec.end(); ++vectorIt)
		{
			V val = *vectorIt;
			cout << left << setw(15) << key << setw(15)<< val << endl;
		}
	}
}


#endif /* MAPOPERATIONS_H_ */
