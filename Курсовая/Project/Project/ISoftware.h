#pragma once
#include <string>
#include <sstream>
#include <msclr/marshal_cppstd.h>

using namespace System::Data;
using namespace System;
using namespace System::IO;

/*
	��������� ��� �������� ������
*/
class ISoftware
{
public:
	std::string virtual GetName() = 0; // ��������� � ��������� �������� ��
	void virtual SetName(std::string) = 0;

	std::string virtual GetVersion() = 0; // ��������� � ��������� ������ ��
	void virtual SetVersion(std::string) = 0; 

	int virtual GetCost() = 0; // ��������� � ��������� ��������� ��
	void virtual SetCost(int) = 0;

	int virtual GetSize() = 0; // ��������� � ��������� ������� ��
	void virtual SetSize(int) = 0;

	void virtual Print(DataTable^) = 0; // ����� ���������� �� �������
	void virtual SavingFile() = 0; //���������� � ����
	void virtual LoadingFile(String^) = 0;  //�������� �� �����
};
