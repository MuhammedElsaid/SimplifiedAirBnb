#pragma once
#include <string>
#include <list>
#include <map>

#include <filesystem>
#include <fstream>

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

	Serializable();
	int ID;
	virtual DataItem* Serialize();
};

template <class T> class DataSet
{
public:
	//Saving the dataset
	void Save() {
		std::ofstream fileStream;
		fileStream.open(path, std::ofstream::out | std::ofstream::trunc);

		for (auto value : values) {

			for (auto key : *((Serializable*)value)->Serialize())
				fileStream << key.first << "=" << key.second << std::endl;

			fileStream << "-" << std::endl;
		}

		fileStream.close();
	}

	void Push(T* item) {
		values.push_back(item);
	}
	
	//Loading data set from the path
	DataSet(std::string path) {
		this->path = path;
		this->values = loadValues();
	}

	DataItem* searchForDataItem(DataItem* dataItem) {

		DataItem* currentDataItem = nullptr;

		auto tempItems = Open();

		for (auto dataValue : tempItems) {
			for (auto dataItemValues : *dataItem) {
				
				currentDataItem = dataValue;

				if (dataValue->empty())
					break;

				auto it = dataValue->find(dataItemValues.first);

				if (it != dataValue->end()) {
					if (it->second != dataItemValues.second) {
						currentDataItem = nullptr;
						break;
					}
				}
			}

			if (currentDataItem)
				break;
		}

		if (!currentDataItem)
			return nullptr;

		auto foundItem = new DataItem(*currentDataItem);
		Close();

		return foundItem;
	}

	std::list<T*>* getValues() {

		return &values;
	}

	virtual const std::list<T*> loadValues(){

		auto readItems = Open();

		for (auto readItem : readItems) {

			values.push_back(new T(readItem));
		}
		Close();
		return values;
	}

protected:
	void loadDataItems() {}
	std::string path;
	std::list<DataItem*> items;
	std::list<T*> values;

	std::list<DataItem*> Open() {

		std::ifstream fileStream(path);
		if (!fileStream) {
			std::ofstream outFileStream(path, std::ofstream::out);
			outFileStream.close();
			items.clear();
			return items;
		}

		std::string currentLine;

		DataItem* currentDataItem = new DataItem();

		while (std::getline(fileStream, currentLine)) {
			if (currentLine == "-") {
				this->items.push_back(currentDataItem);

				currentDataItem = new DataItem();
				continue;
			}

			size_t deliPos = currentLine.find("=");

			std::string key = currentLine.substr(0, deliPos);
			std::string value = currentLine.substr(deliPos + 1, currentLine.length());

			currentDataItem->insert({ key, value });
		}

		fileStream.close();
		return items;
	}

	void Close() {

		for (auto item : items)
			delete item;

		items.clear();
	}

};