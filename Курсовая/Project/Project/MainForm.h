#pragma once
#include "Externalfunction.h"
#include <vector>
#include <string>



namespace Project {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		
		MainForm(void)
		{
			InitializeComponent();
			LoadingFile();
			auto table = CreateTable();
			_table->DataSource = table;
			_table->ClearSelection();

			_softwareBox->SelectedIndex = 0;
			_systemBox->SelectedIndex = 0;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::ComboBox^ _softwareBox;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ text1;
	private: System::Windows::Forms::NumericUpDown^ numeric1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ _txt1;
	private: System::Windows::Forms::Label^ _txt2;
	private: System::Windows::Forms::Label^ _txt3;
	private: System::Windows::Forms::Label^ _txt4;
	private: System::Windows::Forms::TextBox^ _nameTxt;
	private: System::Windows::Forms::TextBox^ _versionTxt;
	private: System::Windows::Forms::NumericUpDown^ _costTxt;
	private: System::Windows::Forms::NumericUpDown^ _sizeTxt;
	private: System::Windows::Forms::TextBox^ text2;
	private: System::Windows::Forms::ComboBox^ _systemBox;
	private: System::Windows::Forms::Button^ _addButton;

	private: System::Windows::Forms::Label^ _txt5;
	private: System::Windows::Forms::Button^ _saveButton;
	private: System::Windows::Forms::TextBox^ _findingTxt;
	private: System::Windows::Forms::Button^ findButton;
	private: System::Windows::Forms::DataGridView^ _table;



	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->_softwareBox = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->text1 = (gcnew System::Windows::Forms::TextBox());
			this->numeric1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->_txt1 = (gcnew System::Windows::Forms::Label());
			this->_txt2 = (gcnew System::Windows::Forms::Label());
			this->_txt3 = (gcnew System::Windows::Forms::Label());
			this->_txt4 = (gcnew System::Windows::Forms::Label());
			this->_nameTxt = (gcnew System::Windows::Forms::TextBox());
			this->_versionTxt = (gcnew System::Windows::Forms::TextBox());
			this->_costTxt = (gcnew System::Windows::Forms::NumericUpDown());
			this->_sizeTxt = (gcnew System::Windows::Forms::NumericUpDown());
			this->text2 = (gcnew System::Windows::Forms::TextBox());
			this->_systemBox = (gcnew System::Windows::Forms::ComboBox());
			this->_addButton = (gcnew System::Windows::Forms::Button());
			this->_txt5 = (gcnew System::Windows::Forms::Label());
			this->_saveButton = (gcnew System::Windows::Forms::Button());
			this->_findingTxt = (gcnew System::Windows::Forms::TextBox());
			this->findButton = (gcnew System::Windows::Forms::Button());
			this->_table = (gcnew System::Windows::Forms::DataGridView());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_costTxt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_sizeTxt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_table))->BeginInit();
			this->SuspendLayout();
			// 
			// _softwareBox
			// 
			this->_softwareBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->_softwareBox->FormattingEnabled = true;
			this->_softwareBox->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->_softwareBox->ItemHeight = 13;
			this->_softwareBox->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"Прикладные программы", L"Cистемные программы",
					L"Операционная система", L"Утилита", L"Драйвера", L"Cистемы программирования", L"Программы специального назначения", L"Программы общего назначения"
			});
			this->_softwareBox->Location = System::Drawing::Point(26, 21);
			this->_softwareBox->MaximumSize = System::Drawing::Size(250, 0);
			this->_softwareBox->MaxLength = 250;
			this->_softwareBox->MinimumSize = System::Drawing::Size(170, 0);
			this->_softwareBox->Name = L"_softwareBox";
			this->_softwareBox->Size = System::Drawing::Size(192, 21);
			this->_softwareBox->TabIndex = 1;
			this->_softwareBox->SelectedIndexChanged += gcnew System::EventHandler(this, &MainForm::_softwareBox_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(448, 60);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"label1";
			// 
			// text1
			// 
			this->text1->Location = System::Drawing::Point(451, 84);
			this->text1->Name = L"text1";
			this->text1->Size = System::Drawing::Size(100, 20);
			this->text1->TabIndex = 3;
			// 
			// numeric1
			// 
			this->numeric1->Location = System::Drawing::Point(451, 85);
			this->numeric1->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->numeric1->Name = L"numeric1";
			this->numeric1->Size = System::Drawing::Size(100, 20);
			this->numeric1->TabIndex = 4;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(554, 60);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 5;
			this->label2->Text = L"label2";
			// 
			// _txt1
			// 
			this->_txt1->AutoSize = true;
			this->_txt1->Location = System::Drawing::Point(23, 60);
			this->_txt1->Name = L"_txt1";
			this->_txt1->Size = System::Drawing::Size(76, 13);
			this->_txt1->TabIndex = 6;
			this->_txt1->Text = L"Название ПО";
			// 
			// _txt2
			// 
			this->_txt2->AutoSize = true;
			this->_txt2->Location = System::Drawing::Point(130, 60);
			this->_txt2->Name = L"_txt2";
			this->_txt2->Size = System::Drawing::Size(44, 13);
			this->_txt2->TabIndex = 7;
			this->_txt2->Text = L"Версия";
			// 
			// _txt3
			// 
			this->_txt3->AutoSize = true;
			this->_txt3->Location = System::Drawing::Point(236, 60);
			this->_txt3->Name = L"_txt3";
			this->_txt3->Size = System::Drawing::Size(62, 13);
			this->_txt3->TabIndex = 8;
			this->_txt3->Text = L"Стоимость";
			// 
			// _txt4
			// 
			this->_txt4->AutoSize = true;
			this->_txt4->Location = System::Drawing::Point(342, 60);
			this->_txt4->Name = L"_txt4";
			this->_txt4->Size = System::Drawing::Size(65, 13);
			this->_txt4->TabIndex = 9;
			this->_txt4->Text = L"Размер ПО";
			// 
			// _nameTxt
			// 
			this->_nameTxt->Location = System::Drawing::Point(26, 85);
			this->_nameTxt->Name = L"_nameTxt";
			this->_nameTxt->Size = System::Drawing::Size(100, 20);
			this->_nameTxt->TabIndex = 10;
			// 
			// _versionTxt
			// 
			this->_versionTxt->Location = System::Drawing::Point(133, 85);
			this->_versionTxt->Name = L"_versionTxt";
			this->_versionTxt->Size = System::Drawing::Size(100, 20);
			this->_versionTxt->TabIndex = 11;
			// 
			// _costTxt
			// 
			this->_costTxt->Location = System::Drawing::Point(239, 85);
			this->_costTxt->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->_costTxt->Name = L"_costTxt";
			this->_costTxt->Size = System::Drawing::Size(100, 20);
			this->_costTxt->TabIndex = 14;
			// 
			// _sizeTxt
			// 
			this->_sizeTxt->Location = System::Drawing::Point(345, 85);
			this->_sizeTxt->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->_sizeTxt->Name = L"_sizeTxt";
			this->_sizeTxt->Size = System::Drawing::Size(100, 20);
			this->_sizeTxt->TabIndex = 15;
			// 
			// text2
			// 
			this->text2->Location = System::Drawing::Point(557, 84);
			this->text2->Name = L"text2";
			this->text2->Size = System::Drawing::Size(100, 20);
			this->text2->TabIndex = 16;
			// 
			// _systemBox
			// 
			this->_systemBox->AutoCompleteCustomSource->AddRange(gcnew cli::array< System::String^  >(3) { L"Всего", L"Программ", L"Устройств" });
			this->_systemBox->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->_systemBox->FormattingEnabled = true;
			this->_systemBox->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Всего", L"Программ", L"Устройств" });
			this->_systemBox->Location = System::Drawing::Point(557, 83);
			this->_systemBox->Name = L"_systemBox";
			this->_systemBox->Size = System::Drawing::Size(100, 21);
			this->_systemBox->TabIndex = 17;
			// 
			// _addButton
			// 
			this->_addButton->Location = System::Drawing::Point(258, 12);
			this->_addButton->Name = L"_addButton";
			this->_addButton->Size = System::Drawing::Size(100, 39);
			this->_addButton->TabIndex = 18;
			this->_addButton->Text = L"Добавить";
			this->_addButton->UseVisualStyleBackColor = true;
			this->_addButton->Click += gcnew System::EventHandler(this, &MainForm::_addButton_Click);
			// 
			// _txt5
			// 
			this->_txt5->AutoSize = true;
			this->_txt5->Location = System::Drawing::Point(23, 5);
			this->_txt5->Name = L"_txt5";
			this->_txt5->Size = System::Drawing::Size(146, 13);
			this->_txt5->TabIndex = 19;
			this->_txt5->Text = L"Программное обеспечение";
			// 
			// _saveButton
			// 
			this->_saveButton->Location = System::Drawing::Point(383, 12);
			this->_saveButton->Name = L"_saveButton";
			this->_saveButton->Size = System::Drawing::Size(100, 39);
			this->_saveButton->TabIndex = 20;
			this->_saveButton->Text = L"Сохранить";
			this->_saveButton->UseVisualStyleBackColor = true;
			this->_saveButton->Click += gcnew System::EventHandler(this, &MainForm::_saveButton_Click);
			// 
			// _findingTxt
			// 
			this->_findingTxt->Location = System::Drawing::Point(663, 31);
			this->_findingTxt->Name = L"_findingTxt";
			this->_findingTxt->Size = System::Drawing::Size(100, 20);
			this->_findingTxt->TabIndex = 21;
			// 
			// findButton
			// 
			this->findButton->Location = System::Drawing::Point(557, 12);
			this->findButton->Name = L"findButton";
			this->findButton->Size = System::Drawing::Size(100, 39);
			this->findButton->TabIndex = 22;
			this->findButton->Text = L"Найти";
			this->findButton->UseVisualStyleBackColor = true;
			this->findButton->Click += gcnew System::EventHandler(this, &MainForm::findButton_Click);
			// 
			// _table
			// 
			this->_table->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::AllCells;
			this->_table->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->_table->Location = System::Drawing::Point(26, 129);
			this->_table->Name = L"_table";
			this->_table->ReadOnly = true;
			this->_table->RowHeadersVisible = false;
			this->_table->Size = System::Drawing::Size(737, 209);
			this->_table->TabIndex = 23;
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(793, 350);
			this->Controls->Add(this->_table);
			this->Controls->Add(this->findButton);
			this->Controls->Add(this->_findingTxt);
			this->Controls->Add(this->_saveButton);
			this->Controls->Add(this->_txt5);
			this->Controls->Add(this->_addButton);
			this->Controls->Add(this->_systemBox);
			this->Controls->Add(this->text2);
			this->Controls->Add(this->_sizeTxt);
			this->Controls->Add(this->_costTxt);
			this->Controls->Add(this->_versionTxt);
			this->Controls->Add(this->_nameTxt);
			this->Controls->Add(this->_txt4);
			this->Controls->Add(this->_txt3);
			this->Controls->Add(this->_txt2);
			this->Controls->Add(this->_txt1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->numeric1);
			this->Controls->Add(this->text1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->_softwareBox);
			this->Name = L"MainForm";
			this->Text = L"MainForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numeric1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_costTxt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_sizeTxt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->_table))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

private: System::Void _softwareBox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		numeric1->Visible = false;
		text1->Visible = false;
		text2->Visible = false;
		label1->Visible = false;
		label2->Visible = false;
		_systemBox->Visible = false;
		switch (_softwareBox->SelectedIndex)//просмотр выбранного ПО для заполнения параметров
		{
		case 0://Прикладные программы
			label1->Visible = true;
			text1->Visible = true;
			label1->Text = "Специализация";
			break;
		case 1://Cистемные программы
			label1->Visible = true;
			text1->Visible = true;
			label1->Text = "Специализация";
			break;
		case 2://Операционная система
			label1->Visible = true;
			label2->Visible = true;
			text1->Visible = true;
			label1->Text = "Специализация";
			_systemBox->Visible = true;
			label2->Text = "Обеспечение работы";
			break;
		case 3://Утилита
			label1->Visible = true;
			label2->Visible = true;
			text1->Visible = true;
			label1->Text = "Специализация";
			_systemBox->Visible = true;
			label2->Text = "Обеспечение работы";
			break;
		case 4://Драйвера
			label1->Visible = true;
			label2->Visible = true;
			text1->Visible = true;
			label1->Text = "Специализация";
			_systemBox->Visible = true;
			label2->Text = "Обеспечение работы";
			break;
		case 5://Cистемы программирования
			label1->Visible = true;
			text1->Visible = true;
			label1->Text = "Язык/Среда программирования";
			break;
		case 6://Программы специального назначения
			label1->Visible = true;
			label2->Visible = true;
			text1->Visible = true;
			label1->Text = "Специализация";
			text2->Visible = true;
			label2->Text = "Сфера применения";
			break;
		case 7://Программы общего назначения
			label1->Visible = true;
			label2->Visible = true;
			text1->Visible = true;
			label1->Text = "Специализация";
			text2->Visible = true;
			label2->Text = "Виды";
			break;
		default:
			break;
			
		}
		auto table = CreateTable();
		_table->DataSource = table;
		_table->ClearSelection();
	}

	   

private: System::Void _addButton_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string name = "";
	std::string version = "";
	std::string txt = "";
	std::string txt2 = "";
	MarshalString(_nameTxt->Text, name);
	MarshalString(_versionTxt->Text, version);
	MarshalString(text1->Text, txt);

	if (name == "" || version == "" || txt == "") {
		MessageBox::Show("Не заполены все поля!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		return;
	}
	switch (_softwareBox->SelectedIndex)//просмотр выбранного ПО для заполнения параметров
	{
	case 0://Прикладные программы
		Storage::ApplicationSoftwares.push_back(*(new ApplicationSoftware(name, version,
			(int)_costTxt->Value, (int)_sizeTxt->Value,txt)));
		break;
	case 1://Cистемные программы
		Storage::SystemSoftwares.push_back(*(new SystemSoftware(name, version,
			(int)_costTxt->Value, (int)_sizeTxt->Value, txt)));
		break;
	case 2://Операционная система
		MarshalString(_systemBox->Text, txt2);
		if (txt2 == "") {
			MessageBox::Show("Не заполены все поля!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}
		Storage::OperatingSystem.push_back(*(new OperatingSystems(name, version,
			(int)_costTxt->Value, (int)_sizeTxt->Value, txt, txt2)));
		break;
	case 3://Утилита
		MarshalString(_systemBox->Text, txt2);
		if (txt2 == "") {
			MessageBox::Show("Не заполены все поля!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error); 
			return;
		}
		Storage::Utilities.push_back(*(new Utility(name, version,
			(int)_costTxt->Value, (int)_sizeTxt->Value, txt, txt2)));
		break;
	case 4://Драйвера
		MarshalString(_systemBox->Text, txt2);
		if (txt2 == "") {
			MessageBox::Show("Не заполены все поля!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error); 
			return;
		}
		Storage::DeviceDriver.push_back(*(new DeviceDrivers(name, version,
			(int)_costTxt->Value, (int)_sizeTxt->Value, txt, txt2)));
		break;
	case 5://Cистемы программирования
		Storage::ProgrammingSystem.push_back(*(new ProgrammingSystems(name, version,
			(int)_costTxt->Value, (int)_sizeTxt->Value, txt)));
		break;
	case 6://Программы специального назначения
		MarshalString(text2->Text, txt2);
		if (txt2 == "") {
			MessageBox::Show("Не заполены все поля!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error); 
			return;
		}
		Storage::SpecialPurposeProgram.push_back(*(new SpecialPurposePrograms(name, version,
			(int)_costTxt->Value, (int)_sizeTxt->Value, txt, txt2)));
		break;
	case 7://Программы общего назначения
		MarshalString(text2->Text, txt2);
		if (txt2 == "") {
			MessageBox::Show("Не заполены все поля!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error); 
			return;
		}
		Storage::GeneralPurposeProgram.push_back(*(new GeneralPurposePrograms(name, version, (int)_costTxt->Value, (int)_sizeTxt->Value, txt, txt2)));
		break;
	}
	auto table = CreateTable();
	_table->DataSource = table;
	_table->ClearSelection();
}

private: System::Void _saveButton_Click(System::Object^ sender, System::EventArgs^ e) {
	SavingFile();
}
private: System::Void findButton_Click(System::Object^ sender, System::EventArgs^ e) {
	std::string txt = ""; 
	MarshalString(_findingTxt->Text, txt);

	int number = Finding(txt);
	_table->ClearSelection();

	if (number != -1) {
		_table->Rows[number]->Selected = true;
	}
	else {
		MessageBox::Show("Ничего не найдено!", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
	}
}
};
}
