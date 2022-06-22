#pragma once
#include <Windows.h>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <vcclr.h>
namespace ossen {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Сводка для BOSS
	/// </summary>
	public ref class BOSS : public System::Windows::Forms::Form
	{
	public:
		BOSS(void)
		{
			InitializeComponent();
			std::ofstream("log.txt");
			logFile("Сервер запущен ");
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~BOSS()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(174, 51);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(84, 27);
			this->button1->TabIndex = 0;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &BOSS::Button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(14, 85);
			this->textBox1->Margin = System::Windows::Forms::Padding(4);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->textBox1->Size = System::Drawing::Size(244, 163);
			this->textBox1->TabIndex = 1;
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->numericUpDown1->Location = System::Drawing::Point(174, 18);
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(84, 27);
			this->numericUpDown1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(10, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(161, 19);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Количество клиентов";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(14, 255);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(92, 46);
			this->button2->TabIndex = 5;
			this->button2->Text = L"ЛОГ";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &BOSS::Button2_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(163, 255);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(95, 46);
			this->button3->TabIndex = 6;
			this->button3->Text = L"ВЫХОД";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &BOSS::Button3_Click);
			// 
			// BOSS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(274, 313);
			this->ControlBox = false;
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"BOSS";
			this->Text = L" ";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &BOSS::BOSS_FormClosing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public: int n;
				int numcl;
	private:
		HANDLE hShow = CreateEvent(NULL, FALSE, FALSE, L"SHOW");       // создаем событие указывающее что символ напечатан
		HANDLE hStart = CreateEvent(NULL, FALSE, FALSE, L"start");      // создаем событие указывающее на начало работы ??
		HANDLE s = CreateSemaphore(NULL, 2, 2, L"s");
		HANDLE mut = CreateMutex(NULL, FALSE, L"mut");
		std::string PredLog(String^& t) {

			SYSTEMTIME st;
			std::stringstream ss;
			GetLocalTime(&st);
			msclr::interop::marshal_context cont;
			ss << '[' << std::setfill('0') << std::setw(2) << st.wMinute
				<< ':' << std::setw(2) << st.wSecond << ':' << std::setw(3) << st.wMilliseconds << ']'
				<< ' ' << cont.marshal_as<std::string>(t) << "\r\n";
			return ss.str();
		}
		System::Void logFile(String^ t) {
			HANDLE mut = OpenMutex(MUTEX_ALL_ACCESS, FALSE, L"mut");
			WaitForSingleObject(mut, INFINITE);
			std::ofstream("log.txt", std::ios::app) << PredLog(t);
			ReleaseMutex(mut);

		}
		System::Void logFile(const std::string& t) {
			HANDLE mut = OpenMutex(MUTEX_ALL_ACCESS, FALSE, L"mut");
			WaitForSingleObject(mut, INFINITE);
			std::ofstream("log.txt", std::ios::app) << t;
			ReleaseMutex(mut);

		}

		delegate System::Void log(String^ t);
		System::Void tlog(String^ t) {
			if (textBox1->InvokeRequired) Invoke(lg, t);
			else {
				std::string s = PredLog(t);
				logFile(s);
				textBox1->Text += gcnew System::String(s.c_str());
			}
		}
		log^ lg = gcnew log(this, &BOSS::tlog);

		
		Void BOSS::MainF();
	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {

		 n = System::Convert::ToDouble(numericUpDown1->Value);
		 numcl = n;
		STARTUPINFO si;
		PROCESS_INFORMATION pi;
		ZeroMemory(&si, sizeof(si));
		ZeroMemory(&pi, sizeof(pi));
		for (int i = 0; i < n; i++) {
			(CreateProcess(L"c:\\Users\\User\\source\\repos\\ossen\\Debug\\Sc.exe",
				NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi));    // запускаем процессы
			
		}
		
		logFile("Босс запустил " + n + " клиентов");
		Thread^ thr = gcnew Thread(gcnew ThreadStart(this, &BOSS::MainF));
		thr->Start();
	};
	private: System::Void Button3_Click(System::Object^ sender, System::EventArgs^ e) {
		Close();
	}
private: System::Void Button2_Click(System::Object^ sender, System::EventArgs^ e) {
	logFile("Пользователь открыл журнал событий");
	system("log.txt");
}

private: System::Void BOSS_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	logFile("Сервер завершил свою работу");
	system("log.txt");
}

};


}