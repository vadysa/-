#pragma once
#include "Software.h"
class SystemSoftware : public Software
{
public:
	SystemSoftware() : Software() {
		_specialization = "Неизвестно";
	}
	SystemSoftware(std::string name, std::string version, int cost, int size, std::string specialization) :
		Software(name, version, cost, size) {
		_specialization = specialization;
	}

	std::string GetSystSpecialization() {
		return _specialization;
	}

	void Print(DataTable^ table) override {
		String^ str1 = "";
		String^ str2 = "";
		String^ str3 = "";
		String^ txt = "";
		String^ x = "";
		String^ y = "";
		str1 = "Cистемные программы";
		str2 = gcnew String(GetName().c_str());
		str3 = gcnew String(GetVersion().c_str());
		x = GetCost() + "Рублей";
		y = GetSize() + "Мб";
		txt = "Специализация: " + gcnew String(GetSystSpecialization().c_str()); 
		table->Rows->Add(str1, str2, str3, x, y, txt);//записываем в таблицу
	}

	void LoadingFile(String^ string) override {
		auto str = string->Split(';');
		auto Name = str[0];
		auto Version = str[1];
		auto Cost = str[2];
		auto Size = str[3];
		String^ specialization = str[4];
		MarshalString(Name, name);
		MarshalString(Version, version);
		cost = Convert::ToInt32(Cost);
		size = Convert::ToInt32(Size);
		MarshalString(specialization, _specialization);
	}

	void SavingFile() override {
		String^ str = "";
		str += gcnew String(GetName().c_str()) + ";";
		str += gcnew String(GetVersion().c_str()) + ";";
		str += GetCost() + ";";
		str += GetSize() + ";";
		str += gcnew String(GetSystSpecialization().c_str());

		StreamWriter^ file = gcnew StreamWriter("SystemSoft.txt", true);
		file->WriteLine(str);
		file->Close();
	}

protected:
	std::string _specialization = "";
};