#pragma once
#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>

using namespace System::Data;
using namespace System;
using namespace System::IO;

/*
	Интерфейс для базового класса
*/
class ISoftware
{
public:
	std::string virtual GetName() = 0; // Получение и установка названия ПО
	void virtual SetName(std::string) = 0;

	std::string virtual GetVersion() = 0; // Получение и установка версии ПО
	void virtual SetVersion(std::string) = 0; 

	int virtual GetCost() = 0; // Получение и установка стоимости ПО
	void virtual SetCost(int) = 0;

	int virtual GetSize() = 0; // Получение и установка размера ПО
	void virtual SetSize(int) = 0;

	void virtual Print(DataTable^) = 0; // Вывод информации об объекте
	void virtual SavingFile() = 0; //Сохранение в файл
	void virtual LoadingFile(String^) = 0;  //Загрузка из файла
};
