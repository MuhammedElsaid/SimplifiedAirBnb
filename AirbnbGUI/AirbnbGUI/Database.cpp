#include "Database.h"
#include "User.h"
#include <filesystem>
#include <fstream>

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