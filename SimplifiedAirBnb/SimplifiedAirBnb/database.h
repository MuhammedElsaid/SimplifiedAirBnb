#pragma once
#include <string>
#include <list>
#include <map>

class DataItem : public std::map<std::string, std::string>
{
	public:
	void AddField(std::string key, std::string value);
};

class Dataset
{
public:
	//Saving the dataset
	virtual void Save();
	void Push(DataItem* dataItem);
	
	//Loading data set from the path
	Dataset(std::string path);

private:
	std::string path;
	std::list<DataItem*> items;
};