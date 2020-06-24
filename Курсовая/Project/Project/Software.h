#pragma once
#include "ISoftware.h"
#include <string>
/*
	Базовый класс наследуемый от интерфейса
*/
class Software :public ISoftware
{
public:
	Software();
	Software(std::string name, std::string version, int cost, int size);
	std::string GetName() override; // Переопределение названия ПО
	void SetName(std::string name) override;

	std::string GetVersion() override; // Переопределение версии ПО
	void SetVersion(std::string version) override;

	int GetCost() override; // Переопределение стоимости ПО
	void SetCost(int cost) override;

	int GetSize() override; // Переопределение размера ПО
	void SetSize(int size) override;

	void Print(DataTable^)  override; // Переопределение вывода

protected:
	std::string name = "";
	std::string version = "";
	int cost = 0;
	int size = 0;
};

void static MarshalString(String^ s, std::string& os) {
	using namespace Runtime::InteropServices;
	const char* chars =(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
	os = chars;
	Marshal::FreeHGlobal(IntPtr((void*)chars));
}