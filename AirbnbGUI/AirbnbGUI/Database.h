#pragma once
#include <string>
#include <list>
#include <map>

class Global;

class DataItem : public std::map<std::string, std::string>
{
public:
	void AddField(std::string key, std::string value);
	void AddField(std::string key, std::list<std::string> values);

	std::list<std::string> getListValues(std::string key);
};

class Serializable
{
public:
	virtual DataItem* Serialize();
};

template <class T> class DataSet
{
public:
	//Saving the dataset
	void Save();
	virtual void Push(T* item) {}
	
	//Loading data set from the path
	DataSet(std::string path);
	DataItem* searchForDataItem(DataItem* dataItem);

	const std::list<T*> getValues();

protected:
	void loadDataItems() {}
	std::string path;
	std::list<DataItem*> items;
	std::list<T*> values;

private:
	std::list<DataItem*>& Open();
	void Close();

};