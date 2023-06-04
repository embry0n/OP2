#pragma once
#include <msclr/marshal_cppstd.h> 

namespace news {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::OpenFileDialog^ openFileDialog1;
	protected:
	private: System::Windows::Forms::Button^ button1;

	private: System::DirectoryServices::DirectoryEntry^ directoryEntry1;
	private: System::Windows::Forms::ListBox^ listBox1;
	private: System::Windows::Forms::ListBox^ listBox2;

	private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
	private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->directoryEntry1 = (gcnew System::DirectoryServices::DirectoryEntry());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(334, 453);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(312, 64);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Удалить файлы старше заданной даты";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// listBox1
			// 
			this->listBox1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox1->FormattingEnabled = true;
			this->listBox1->ItemHeight = 19;
			this->listBox1->Location = System::Drawing::Point(508, 85);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(459, 327);
			this->listBox1->TabIndex = 2;
			// 
			// listBox2
			// 
			this->listBox2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->listBox2->FormattingEnabled = true;
			this->listBox2->ItemHeight = 19;
			this->listBox2->Location = System::Drawing::Point(12, 85);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(459, 327);
			this->listBox2->TabIndex = 3;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Format = System::Windows::Forms::DateTimePickerFormat::Short;
			this->dateTimePicker1->Location = System::Drawing::Point(355, 21);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(126, 22);
			this->dateTimePicker1->TabIndex = 5;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Format = System::Windows::Forms::DateTimePickerFormat::Time;
			this->dateTimePicker2->Location = System::Drawing::Point(487, 21);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(126, 22);
			this->dateTimePicker2->TabIndex = 6;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(153, 57);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(131, 25);
			this->label1->TabIndex = 7;
			this->label1->Text = L"До очистки";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Times New Roman", 13.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(670, 57);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(168, 25);
			this->label2->TabIndex = 8;
			this->label2->Text = L"После очистки";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(979, 529);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->listBox2);
			this->Controls->Add(this->listBox1);
			this->Controls->Add(this->button1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		DateTime selectedDate = dateTimePicker1->Value.Date; // Получаем выбранную дату из datePicker.    Get the selected date from datePicker.
		TimeSpan selectedTime = dateTimePicker2->Value.TimeOfDay;
		DateTime selectedDateTime(selectedDate.Year, selectedDate.Month, selectedDate.Day, selectedTime.Hours, selectedTime.Minutes, selectedTime.Seconds);

		String^ directoryPath = " "; // Путь к каталогу.	Directory path.
		FolderBrowserDialog^ folderDlg = gcnew FolderBrowserDialog();
		if (Windows::Forms::DialogResult::OK == folderDlg->ShowDialog())
		{
			directoryPath = folderDlg->SelectedPath;
		}

		try
		{
			DirectoryInfo^ dirInfo = gcnew DirectoryInfo(directoryPath); // Создаем экземпляр класса DirectoryInfo для выбранного каталога.    Create an instance of the DirectoryInfo class for the selected directory

			listBox2->Items->Clear();

			// Выводим файлы и каталоги до удаления.    Display files and directories before deletion.
			for each (FileInfo ^ file in dirInfo->GetFiles())
			{
				String^ fileName = file->Name; // Получаем имя файла.    Getting the file name.
				listBox2->Items->Add("[Файл] " + fileName); // Добавляем имя файла в listBox2 с префиксом [Файл].    Add filename to listBox2 with [File] prefix.
			}

			for each (DirectoryInfo ^ dir in dirInfo->GetDirectories())
			{
				String^ directoryName = dir->Name; // Получаем имя каталога.    Get the directory name.
				listBox2->Items->Add("[Каталог] " + directoryName); // Добавляем имя каталога в listBox2 с префиксом [Каталог].    Add directory name to listBox2 with [Directory] prefix.
			}

			RemoveOldFilesAndDirectories(dirInfo, selectedDateTime);

			listBox1->Items->Clear();

			DateTime directoryCreationDate = Directory::GetCreationTime(directoryPath);
			if (directoryCreationDate < selectedDateTime)
			{
				// Каталог создан раньше заданной даты, удаляем его.    The catalog was created earlier than the specified date, delete it.
				Directory::Delete(directoryPath, true); // Удаляем каталог рекурсивно.    Delete a directory recursively.
				listBox1->Items->Add("Каталог удален");
			}
			else
			{
				// Каталог удовлетворяет заданной дате, выполняем другие действия.    The catalog satisfies the specified date, perform other actions.
				// Выводим файлы и каталоги после удаления.    Display files and directories after deletion.
				for each (FileInfo ^ file in dirInfo->GetFiles())
				{
					String^ fileName = file->Name; // Получаем имя файла.    Getting the file name.
					listBox1->Items->Add("[Файл] " + fileName); // Добавляем имя файла в listBox1 с префиксом [Файл].    Add filename to listBox1 with [File] prefix.
				}

				for each (DirectoryInfo ^ dir in dirInfo->GetDirectories())
				{
					String^ directoryName = dir->Name; // Получаем имя каталога.    Get the directory name.
					listBox1->Items->Add("[Каталог] " + directoryName); // Добавляем имя каталога в listBox1 с префиксом [Каталог].    Add directory name to listBox1 with [Directory] prefix.
				}
			}
		}
		catch (Exception^ ex)
		{
			MessageBox::Show(this, "Не удалось прочитать каталог", "Ошибка", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	void RemoveOldFilesAndDirectories(DirectoryInfo^ dirInfo, DateTime thresholdDateTime)
	{
		// Удаляем файлы, старше заданной даты.    Delete files older than a given date.
		for each (FileInfo ^ file in dirInfo->GetFiles())
		{
			if (file->CreationTime <= thresholdDateTime)
			{
				file->Delete();
			}
		}

		// Рекурсивно удаляем каталоги, старше заданной даты.    Recursively remove directories older than a given date.
		for each (DirectoryInfo ^ dir in dirInfo->GetDirectories())
		{
			if (dir->CreationTime <= thresholdDateTime)
			{
				RemoveOldFilesAndDirectories(dir, thresholdDateTime);
				dir->Delete(true); // Указываем параметр true для удаления каталога, включая все его подкаталоги и файлы.    Specify the parameter true to delete the directory, including all its subdirectories and files.
			}
		}
	}
	};
}
