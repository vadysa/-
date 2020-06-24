#pragma once
#include "ApplicationSoftware.h"
class SpecialPurposePrograms : public ApplicationSoftware
{
public:
	SpecialPurposePrograms() : ApplicationSoftware() {
		_scope = "Неизвестно";
	}
	SpecialPurposePrograms(std::string name, std::string version, int cost, int size, std::string specialization) :
		ApplicationSoftware(name, version, cost, size, specialization) {
		_scope = "Неизвестно";
	}
	SpecialPurposePrograms(std::string name, std::string version, int cost, int size, std::string specialization, std::string scope) :
		ApplicationSoftware(name, version, cost, size, specialization) {
		_scope = scope;
	}
	std::string GetScope() {
		return _scope;
	}

	void Print(DataTable^ table) override {
		String^ str1 = "";
		String^ str2 = "";
		String^ str3 = "";
		String^ txt = "";
		String^ x = "";
		String^ y = "";
		str1 = "Программы специального назначения";
		str2 = gcnew String(GetName().c_str());
		str3 = gcnew String(GetVersion().c_str());
		x = GetCost() + "Рублей";
		y = GetSize() + "Мб";
		txt = "Специализация: " + gcnew String(GetSpecialization().c_str()) + ";Cфера применения: " + gcnew String(GetScope().c_str());
		table->Rows->Add(str1, str2, str3, x, y, txt);//записываем в таблицу
	}

	void LoadingFile(String^ string) override {
		auto str = string->Split(';');
		auto Name = str[0];
		auto Version = str[1];
		auto Cost = str[2];
		auto Size = str[3];
		auto specialization = str[4];
		auto scope = str[5];
		MarshalString(Name, name);
		MarshalString(Version, version);
		cost = Convert::ToInt32(Cost);
		size = Convert::ToInt32(Size);
		MarshalString(specialization, _specialization);
		MarshalString(scope, _scope);
	}

	void SavingFile() override {
		String^ str = "";
		str += gcnew String(GetName().c_str()) + ";";
		str += gcnew String(GetVersion().c_str()) + ";";
		str += GetCost() + ";";
		str += GetSize() + ";";
		str += gcnew String(GetSpecialization().c_str()) + ";";
		str += gcnew String(GetScope().c_str());
		StreamWriter^ file = gcnew StreamWriter("SpecialProg.txt", true);
		file->WriteLine(str);
		file->Close();
	}

protected:
	std::string _scope = "";
};