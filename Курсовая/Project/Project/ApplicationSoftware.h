#pragma once
#include "Software.h"
class ApplicationSoftware : public Software
{
public:
	ApplicationSoftware() : Software() {
		_specialization = "����������";
	}
	ApplicationSoftware(std::string name, std::string version, int cost, int size, std::string specialization) :
		Software(name, version, cost, size) {
		_specialization = specialization;
	}

	std::string GetSpecialization() {
		return _specialization;
	}

	void Print(DataTable^ table) override {
		DataRow^ row;
		row = table->NewRow();
		int indx = 0;
		std::string x = "���������� ���������";//��� ������ �� � x ��������� ���
		row[indx++] = gcnew String(x.c_str());
		row[indx++] = gcnew String(GetName().c_str());//��� ������� �������� ������
		row[indx++] = gcnew String(GetVersion().c_str());
		row[indx++] = GetCost() + "������";
		row[indx++] = GetSize() + "��";
		row[indx++] = "�������������: " + gcnew String(GetSpecialization().c_str());
		table->Rows->Add(row);
	}

	void LoadingFile(String^ string) override {
		auto str = string->Split(';');
		auto Name = str[0];
		auto Version = str[1];
		auto Cost = str[2];
		auto Size = str[3];
		auto specialization = str[4];
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
		str += gcnew String(GetSpecialization().c_str());
		StreamWriter^ file = gcnew StreamWriter("ApplicationSoft.txt", true);
		file->WriteLine(str);
		file->Close();
	}

protected:
	std::string _specialization = "";
};