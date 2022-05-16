#include "Database.h"
#include "User.h"
#include <filesystem>
#include <fstream>

template<class T> void DataSet<T>::Save()
{
	std::ofstream fileStream;
	fileStream.open(path, std::ofstream::out | std::ofstream::trunc);

	for (auto value : values) {

		for (auto key : *((Serializable*)value)->Serialize())
			fileStream << key.first << "=" << key.second << std::endl;

		fileStream << "-" << std::endl;
	}

	fileStream.close();
}

template<class T> DataSet<T>::DataSet(std::string path)
{
	this->path = path;
}

template<class T> DataItem* DataSet<T>::searchForDataItem(DataItem* dataItem) {

	DataItem* currentDataItem = nullptr;

	for (auto dataValue : items) {
		for (auto dataItemValues : *dataItem) {

			currentDataItem = dataValue;
			if (dataValue->at(dataItemValues.first) != dataItemValues.second) {
				currentDataItem = nullptr;
				break;
			}
		}
	}

	return currentDataItem;
}

template<class T>
std::list<DataItem*>& DataSet<T>::Open() {
	
	std::list<DataItem*> dataItems;

	std::ifstream fileStream(path);
	if (!fileStream) {
		std::ofstream outFileStream(path, std::ofstream::out);
		outFileStream.close();
		return;
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

template<class T>
void DataSet<T>::Close() {

	for (auto item : items)
		delete item;
}

template<class T>
const std::list<T*> DataSet<T>::getValues() {
	return values;
}

void DataItem::AddField(std::string key, std::string value)
{
	this->insert({ key, value });
}
const std::string space_delimiter = ",";

void DataItem::AddField(std::string key, std::list<std::string> values) {

	std::string str = "";
	for (auto value : values) {

		str += value;
		str += space_delimiter;
	}

	this->AddField(key, str);
}

std::list<std::string> DataItem::getListValues(std::string key) {

	std::list<std::string> values;
	std::string str = this->at(key);
	size_t pos = 0;
	while ((pos = str.find(space_delimiter)) != std::string::npos) {
		values.push_back(str.substr(0, pos));
		str.erase(0, pos + space_delimiter.length());
	}
	return values;
}