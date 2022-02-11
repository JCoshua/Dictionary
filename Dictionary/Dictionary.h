#pragma once

template <typename TKey, typename TValue>
class Dictionary
{
public:
	Dictionary<TKey, TValue>() {};
	Dictionary<TKey, TValue>(const Dictionary<TKey, TValue>& other);
	~Dictionary<TKey, TValue>() {};
	void clear();
	bool containsKey(const TKey object) const;
	bool containsValue(const TValue object) const;
	bool tryGetValue(const TKey key, TValue& value) const;
	void addItem(const TKey& key, const TValue& value);
	bool remove(const TKey key);
	bool remove(const TKey key, TValue& value);
	int getCount() const;
	const Dictionary<TKey, TValue>& operator =(const Dictionary<TKey, TValue> other);
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
	for (int i = 0; i < m_count; i++)
		m_items[i] = nullptr;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsKey(const TKey object) const
{
	for (int i = 0; i < m_count; i++)
		if (m_items[i].itemKey == object)
			return true;
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::containsValue(const TValue object) const
{
	for (int i = 0; i < m_count; i++)
		if (m_items[i].itemValue == object)
			return true;
	return false;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::tryGetValue(const TKey key, TValue& value) const
{
	for (int i = 0; i < m_count; i++)
		if (m_items[i].itemKey == key)
		{
			value = m_items[i].itemValue;
			return true;
		}
	return false;
}

template<typename TKey, typename TValue>
inline void Dictionary<TKey, TValue>::addItem(const TKey& key, const TValue& value)
{
	if (containsKey(key))
		return;

	Item* tempArray = new Item[m_count + 1];

	for (int i = 0; i < m_count; i++)
		tempArray[i] = m_items[i];

	tempArray[m_count] = Item{ key,value };
	m_items = tempArray;
	m_count++;
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key)
{
	if (key == NULL || !containsKey(key))
		return false;

	Item* tempArray = new Item[m_count - 1];

	bool itemRemoved = false;
	int j = 0;
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

	if (itemRemoved)
	{
		m_items = tempArray;
		m_count--;
	}
}

template<typename TKey, typename TValue>
inline bool Dictionary<TKey, TValue>::remove(const TKey key, TValue& value)
{
	if (key == NULL || !containsKey(key))
		return false;

	Item* tempArray = new Item[m_count - 1];

	bool itemRemoved = false;
	int j = 0;
	for (int i = 0; i < m_count; i++)
	{
		if (m_items[i].itemKey != key)
		{
			tempArray[i] = m_items[j];
			j++;
		}
		else
		{
			itemRemoved = true;
			if(value != nullptr)
				value = m_items[i].itemValue;
		}
	}

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
