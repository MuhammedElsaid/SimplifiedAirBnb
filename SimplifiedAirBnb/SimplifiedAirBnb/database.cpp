#include "database.h"
#include <filesystem>
#include <fstream>
#include <windows.h>

void DataSet::Save()
{
	std::ofstream fileStream;
	fileStream.open(path, std::ofstream::out | std::ofstream::trunc);

	for (auto item : items) {

		for (auto key : *item)
		{
			fileStream << key.first << "=" << key.second << std::endl;
		}

		fileStream << "-" << std::endl;
	}

	fileStream.close();
}

DataSet::DataSet(std::string path)
{
	this->path = path;

	std::ifstream fileStream(path);
	if (!fileStream)
	{
		std::ofstream outFileStream(path, std::ofstream::out);
		outFileStream.close();
		return;
	}

	std::string currentLine;

	DataItem* currentDataItem = new DataItem();

	while (std::getline(fileStream, currentLine))
	{
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
}

void DataSet::Push(DataItem* dataItem)
{
	this->items.push_back(dataItem);
}

void DataItem::AddField(std::string key, std::string value)
{
	this->insert({ key, value });
}
