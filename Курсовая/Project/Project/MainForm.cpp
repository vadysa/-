#include "MainForm.h"


using namespace System;
using namespace System::Windows::Forms;


[STAThreadAttribute]

int main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project::MainForm form;
	Application::Run(% form);
}