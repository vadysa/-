#pragma once
#include "ISoftware.h"
#include <string>
/*
	������� ����� ����������� �� ����������
*/
class Software :public ISoftware
{
public:
	Software();
	Software(std::string name, std::string version, int cost, int size);
	std::string GetName() override; // ��������������� �������� ��
	void SetName(std::string name) override;

	std::string GetVersion() override; // ��������������� ������ ��
	void SetVersion(std::string version) override;

	int GetCost() override; // ��������������� ��������� ��
	void SetCost(int cost) override;

	int GetSize() override; // ��������������� ������� ��
	void SetSize(int size) override;

	void Print(DataTable^)  override; // ��������������� ������

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