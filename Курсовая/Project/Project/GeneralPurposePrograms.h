#pragma once
#include "ApplicationSoftware.h"
class GeneralPurposePrograms : public ApplicationSoftware
{
public:
	GeneralPurposePrograms() : ApplicationSoftware() {
		_kind = "����������";
	}
	GeneralPurposePrograms(std::string name, std::string version, int cost, int size, std::string specialization) :
		ApplicationSoftware(name, version, cost, size, specialization) {
		_kind = "����������";
	}
	GeneralPurposePrograms(std::string name, std::string version, int cost, int size, std::string specialization, std::string kind) :
		ApplicationSoftware(name, version, cost, size, specialization) {
		_kind = kind;
	}
	std::string GetKind() {
		return _kind;
	}

	void Print(DataTable^ table) override {
		String^ str1 = "";
		String^ str2 = "";
		String^ str3 = "";
		String^ txt = "";
		String^ x = "";
		String^ y = "";
		str1 = "��������� ������ ����������";
		str2 = gcnew String(GetName().c_str());
		str3 = gcnew String(GetVersion().c_str());
		x = GetCost() + "������";
		y = GetSize() + "��";
		txt = "�������������: " + gcnew String(GetSpecialization().c_str()) + ";���: " + gcnew String(GetKind().c_str());
		table->Rows->Add(str1, str2, str3, x, y, txt);//���������� � �������
	}

	void LoadingFile(String^ string) override {
		auto str = string->Split(';');
		auto Name = str[0];
		auto Version = str[1];
		auto Cost = str[2];
		auto Size = str[3];
		auto specialization = str[4];
		auto kind = str[5];
		MarshalString(Name, name);
		MarshalString(Version, version);
		cost = Convert::ToInt32(Cost);
		size = Convert::ToInt32(Size);
		MarshalString(specialization, _specialization);
		MarshalString(kind, _kind);
	}

	void SavingFile() override {
		String^ str = "";
		str += gcnew String(GetName().c_str()) + ";";
		str += gcnew String(GetVersion().c_str()) + ";";
		str += GetCost() + ";";
		str += GetSize() + ";";
		str += gcnew String(GetSpecialization().c_str()) + ";";
		str += gcnew String(GetKind().c_str());
		StreamWriter^ file = gcnew StreamWriter("GeneralProg.txt", true);
		file->WriteLine(str);
		file->Close();
	}

protected:
	std::string _kind = "";
};