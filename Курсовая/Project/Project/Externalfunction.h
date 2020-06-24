#pragma once
#include "Storage.h"
using namespace System::Data;
using namespace System::IO;


/*
	Запись содержимого динамических векторов в статический
*/
template<typename T>
void InputContainer(DinamicVector<T> list) {
	for (size_t i = 0; i < list.size(); i++) {
		Storage::StaticContainer.Push(list.at(i));
	}
}

/*
	Генерирует таблицу запоминающих устройств для DataGridView
*/
DataTable^ CreateTable() {
	DataTable^ table = gcnew DataTable();
	table->Columns->Add("Тип");
	table->Columns->Add("Название");
	table->Columns->Add("Версия");
	table->Columns->Add("Стоимость");
	table->Columns->Add("Размер занимаемого места");
	table->Columns->Add("Дополнительно");

	Storage::StaticContainer.Clear();
	InputContainer(Storage::OperatingSystem);
	InputContainer(Storage::Utilities);
	InputContainer(Storage::DeviceDriver);
	InputContainer(Storage::GeneralPurposeProgram);
	InputContainer(Storage::SpecialPurposeProgram);
	InputContainer(Storage::ProgrammingSystem);
	InputContainer(Storage::SystemSoftwares);
	InputContainer(Storage::ApplicationSoftwares);

	/*
	Создание таблицы
	*/
	for (size_t i = 0; i < Storage::StaticContainer.Size(); i++)
	{
		if (Storage::StaticContainer.At(i) != nullptr) {
			Storage::StaticContainer.At(i)->Print(table);

		}
	}
	return table;
}
/*
	Поиск названия объекта в таблице
*/
int Finding(std::string soft) {
	for (size_t i = 0; i < Storage::StaticContainer.Size(); i++) {
		if (Storage::StaticContainer.At(i) != nullptr) {
			if (Storage::StaticContainer.At(i)->GetName() == soft)
				return i;
		}
	}
	return -1;
}
/*
	Сохранение объектов в файл
*/
void SavingFile() {
	Storage::StaticContainer.Clear();
	InputContainer(Storage::OperatingSystem);
	InputContainer(Storage::Utilities);
	InputContainer(Storage::DeviceDriver);
	InputContainer(Storage::GeneralPurposeProgram);
	InputContainer(Storage::SpecialPurposeProgram);
	InputContainer(Storage::ProgrammingSystem);
	InputContainer(Storage::SystemSoftwares);
	InputContainer(Storage::ApplicationSoftwares);
	File::Delete("Operating.txt");
	File::Delete("Utility.txt");
	File::Delete("Driver.txt");
	File::Delete("Programming.txt");
	File::Delete("GeneralProg.txt");
	File::Delete("SpecialProg.txt");
	File::Delete("SystemSoft.txt");
	File::Delete("ApplicationSoft.txt");

	for (size_t i = 0; i < Storage::StaticContainer.Size(); i++) {
		if (Storage::StaticContainer.At(i) != nullptr) {
			Storage::StaticContainer.At(i)->SavingFile();
		}
	}

}
/*
	Загрузка объектов из файла
*/
void LoadingFile() 
{

	String^ path = "Operating.txt";
	StreamReader^ reader = gcnew StreamReader(path);
	auto operat = std::make_shared<OperatingSystems>();
	while (!reader->EndOfStream) {
		operat->LoadingFile(reader->ReadLine());
		Storage::OperatingSystem.push_back(*operat);
	}
	reader->Close();

	path = "Utility.txt";
	reader = gcnew StreamReader(path);
	auto util = std::make_shared<Utility>();
	while (!reader->EndOfStream) {
		util->LoadingFile(reader->ReadLine());
		Storage::Utilities.push_back(*util);
	}
	reader->Close();

	path = "Driver.txt";
	reader = gcnew StreamReader(path);
	auto driv = std::make_shared<DeviceDrivers>();
	while (!reader->EndOfStream) {
		driv->LoadingFile(reader->ReadLine());
		Storage::DeviceDriver.push_back(*driv);
	}
	reader->Close();

	path = "GeneralProg.txt";
	reader = gcnew StreamReader(path);
	auto prog = std::make_shared<GeneralPurposePrograms>();
	while (!reader->EndOfStream) {
		prog->LoadingFile(reader->ReadLine());
		Storage::GeneralPurposeProgram.push_back(*prog);
	}
	reader->Close();

	path = "SpecialProg.txt";
	reader = gcnew StreamReader(path);
	auto gener = std::make_shared<SpecialPurposePrograms>();
	while (!reader->EndOfStream) {
		gener->LoadingFile(reader->ReadLine());
		Storage::SpecialPurposeProgram.push_back(*gener);
	}
	reader->Close();

	path = "Programming.txt";
	reader = gcnew StreamReader(path);
	auto spec = std::make_shared<ProgrammingSystems>();
	while (!reader->EndOfStream) {
		spec->LoadingFile(reader->ReadLine());
		Storage::ProgrammingSystem.push_back(*spec);
	}
	reader->Close();

	path = "SystemSoft.txt";
	reader = gcnew StreamReader(path);
	auto systs = std::make_shared<SystemSoftware>();
	while (!reader->EndOfStream) {
		systs->LoadingFile(reader->ReadLine());
		Storage::SystemSoftwares.push_back(*systs);
	}
	reader->Close();

	path = "ApplicationSoft.txt";
	reader = gcnew StreamReader(path);
	auto app = std::make_shared<ApplicationSoftware>();
	while (!reader->EndOfStream) {
		app->LoadingFile(reader->ReadLine());
		Storage::ApplicationSoftwares.push_back(*app);
	}
	reader->Close();
}
