#pragma once

template <typename TKey, typename TValue>
class Dictionary
{
public:

	Dictionary<TKey, TValue>() {};
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other);
	~Dictionary<TKey, TValue>() {};

	/// <summary>
	/// Clears the Dictionary
	/// </summary>
	void clear();

	/// <summary>
	/// Checks the dictionary for an Item with the key given
	/// </summary>
	/// <param name="object">The key of the item</param>
	/// <returns>If the dictionary contains an Item with the key</returns>
	bool containsKey(const TKey object) const;

	/// <summary>
	/// Checks the dictionary for an Item with the value given
	/// </summary>
	/// <param name="object">The value of the item</param>
	/// <returns>If the dictionary contains an Item with the value</returns>
	bool containsValue(const TValue object) const;

	/// <summary>
	/// Gets the value of an Item with the key and stores it into the given pointer
	/// </summary>
	/// <param name="key">The key of the value</param>
	/// <param name="value">The pointer to store the value</param>
	/// <returns>If the value was found</returns>
	bool tryGetValue(const TKey key, TValue& value) const;

	/// <summary>
	/// Adds an Item with the value and key given
	/// </summary>
	/// <param name="key">The key assigned to the new item</param>
	/// <param name="value">The value to give to the new item</param>
	void addItem(const TKey& key, const TValue& value);

	/// <summary>
	/// Remove the Item with the key given
	/// </summary>
	/// <param name="key">The key of the Item to remove</param>
	/// <returns>If the item was removed</returns>
	bool remove(const TKey key);

	/// <summary>
	/// Remove the Item with the key given and stores the value
	/// </summary>
	/// <param name="key">The key of the Item to remove</param>
	/// <param name="value">The pointer to store the value</param>
	/// <returns>If the item was removed</returns>
	bool remove(const TKey key, TValue& value);

	/// <summary>
	/// Returns the number of items in the Dictionary
	/// </summary>
	int getCount() const;

	const Dictionary<TKey, TValue>& operator =(const Dictionary<TKey, TValue> other);
	TValue operator [](const TKey& key);

private:
	struct Item
	{
		TKey itemKey;
		TValue itemValue;
	};

	Item* m_items = nullptr;
	int m_count = 0;
};

template<typename TKey, typename TValue>
inline Dictionary<TKey, TValue>::Dictionary(const Dictionary<TKey, TValue>& other)
{
	for (int i = 0; i < other.m_count; i++)
		m_items[i] = other.m_items[i];

	m_count = other.m_count;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::clear()
{
	m_items = nullptr;
	m_count = 0;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	//Iterrates through the dictionary to find the key given
	for (int i = 0; i < m_count; i++)
		if (m_items[i].itemKey == object)
			return true;
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	//Iterrates through the dictionary to find the value given
	for (int i = 0; i < m_count; i++)
		if (m_items[i].itemValue == object)
			return true;
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value) const
{
	bool returnValue = false;
	//Iterrates through the dictionary to find the key given
	for (int i = 0; i < m_count; i++)
		if (m_items[i].itemKey == key)
		{
			//Makes the value equal to the value of the item found by the key
			value = m_items[i].itemValue;
			returnValue = true;
		}
	return returnValue;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
	//If the dictionary already contains the key given, return
	if (containsKey(key))
		return;

	//Create a new Item Array that is one item bigger than the current array
	Item* tempArray = new Item[m_count + 1];

	//Copy the values of the current array into the new array
	for (int i = 0; i < m_count; i++)
		tempArray[i] = m_items[i];

	//At the final value of the new array, create an item using the given key and value
	tempArray[m_count] = Item{ key,value };

	//Make the new array become the current array
	m_items = tempArray;
	m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	//If the dictionary contains the key or does not exist, return false
	if (key == NULL || !containsKey(key))
		return false;

	//Create a new Item Array that is one item smaller than the current array
	Item* tempArray = new Item[m_count - 1];

	bool itemRemoved = false;
	int j = 0;

	//Copy the values of the current array into the new array if they are not the value to remove
	for (int i = 0; i < m_count; i++)
	{
		if (m_items[i].itemKey != key)
		{
			tempArray[i] = m_items[j];
			j++;
		}
		else
			itemRemoved = true;
	}

	//If the Item was removed, make the new array the current array
	if (itemRemoved)
	{
		m_items = tempArray;
		m_count--;
	}
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	//If the dictionary contains the key or does not exist, return false
	if (key == NULL || !containsKey(key))
		return false;

	//Create a new Item Array that is one item smaller than the current array
	Item* tempArray = new Item[m_count - 1];

	bool itemRemoved = false;
	int j = 0;

	//Copy the values of the current array into the new array if they are not the value to remove
	for (int i = 0; i < m_count; i++)
	{
		if (m_items[i].itemKey != key)
		{
			tempArray[j] = m_items[i];
			j++;
		}
		else
		{
			//Makes the value passed in the item's value
			value = m_items[i].itemValue;
			itemRemoved = true;
		}
	}

	//If the Item was removed, make the new array the current array
	if (itemRemoved)
	{
		m_items = tempArray;
		m_count--;
	}
}

template<typename TKey, typename TValue>
inline int Dictionary<TKey, TValue>::getCount() const
{
	return m_count;
}

template<typename TKey, typename TValue>
inline const Dictionary<TKey, TValue>& Dictionary<TKey, TValue>::operator=(const Dictionary<TKey, TValue> other)
{
	return Dictionary(other);
}

template<typename TKey, typename TValue>
inline TValue Dictionary<TKey, TValue>::operator[](const TKey& key)
{
	TValue returnValue;
	tryGetValue(key, returnValue);

	return returnValue;
}
