#pragma once
#include "Software.h"
class ProgrammingSystems : public Software
{
public:
	ProgrammingSystems() : Software() {
		_environment = "";
	}
	ProgrammingSystems(std::string name, std::string version, int cost, int size) :
		Software(name, version, cost, size) {
		_environment = "";
	}
	ProgrammingSystems(std::string name, std::string version, int cost, int size, std::string environment) :
		Software(name, version, cost, size) {
		_environment = environment;
	}


	std::string GetProgEnvironment() {
		return _environment;
	}

	void Print(DataTable^ table) override {
		String^ str1 = "";
		String^ str2 = "";
		String^ str3 = "";
		String^ txt = "";
		String^ x = "";
		String^ y = "";
		str1 = "C������ ����������������";
		str2 = gcnew String(GetName().c_str());
		str3 = gcnew String(GetVersion().c_str());
		x = GetCost() + "������";
		y = GetSize() + "��";
		txt = "����� ����������������: " + gcnew String(GetProgEnvironment().c_str());
		table->Rows->Add(str1, str2, str3, x, y, txt);//���������� � �������
	}

	void LoadingFile(String^ string) override {
		auto str = string->Split(';');
		auto Name = str[0];
		auto Version = str[1];
		auto Cost = str[2];
		auto Size = str[3];
		auto Environment = str[4];
		MarshalString(Name, name);
		MarshalString(Version, version);
		cost = Convert::ToInt32(Cost);
		size = Convert::ToInt32(Size);
		MarshalString(Environment, _environment);
	}

	void SavingFile() override {
		String^ str = "";
		str += gcnew String(GetName().c_str()) + ";";
		str += gcnew String(GetVersion().c_str()) + ";";
		str += GetCost() + ";";
		str += GetSize() + ";";
		str += gcnew String(GetProgEnvironment().c_str());
		
		StreamWriter^ file = gcnew StreamWriter("Programming.txt", true);
		file->WriteLine(str);
		file->Close();
	}

protected:
	std::string _environment = "";
};