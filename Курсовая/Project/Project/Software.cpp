
#include "Software.h"

Software::Software()
{
	this->name = "";
	this->version = "";
	this->cost = 0;
	this->size = 0;
}

Software::Software(std::string name, std::string version, int cost, int size)
{
	this->name = name;
	this->version = version;
	this->cost = cost;
	this->size = size;
}

std::string Software::GetName()
{
	return this->name;
}

std::string Software::GetVersion()
{
	return this->version;
}

int Software::GetCost()
{
	return this->cost;
}

void Software::SetName(std::string name)
{
	this->name = name;
}

void Software::SetVersion(std::string version)
{
	this->version = version;
}

void Software::SetCost(int cost)
{
	this->cost = cost;
}

void Software::SetSize(int size)
{
	this->size = size;
}

int Software::GetSize()
{
	return this->size;
}

void Software::Print(DataTable^ table)
{
	DataRow^ row;
	String^ str1 = "";
	String^ str2 = "";
	String^ str3 = "";
	String^ x = "";
	String^ y = "";
	str1 = "Неизвестно";
	str2 = gcnew String(GetName().c_str());
	str3 = gcnew String(GetVersion().c_str());
	x = GetCost() + "Рублей";
	y = GetSize() + "Мб";
	table->Rows->Add(str1, str2, str3, x, y);//записываем в таблицу
}
