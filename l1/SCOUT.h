#pragma once
#include <Windows.h>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <msclr\marshal_cppstd.h>
#include <vcclr.h>


namespace Sc {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// —водка дл€ SCOUT
	/// </summary>
	public ref class SCOUT : public System::Windows::Forms::Form
	{
	public:
		SCOUT(void)
		{
			InitializeComponent();
		}
		

	protected:
		/// <summary>
		/// ќсвободить все используемые ресурсы.
		/// </summary>
		~SCOUT()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::TextBox^ textBox1;

	protected:

	private:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Location = System::Drawing::Point(249, 13);
			this->button1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(57, 26);
			this->button1->TabIndex = 0;
			this->button1->Text = L"OK";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &SCOUT::Button1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Enabled = false;
			this->textBox1->Location = System::Drawing::Point(12, 13);
			this->textBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(229, 26);
			this->textBox1->TabIndex = 1;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &SCOUT::TextBox1_TextChanged);
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &SCOUT::TextBox1_KeyPress);
			// 
			// SCOUT
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 19);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(319, 69);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Font = (gcnew System::Drawing::Font(L"Times New Roman", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"SCOUT";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"SCOUT";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &SCOUT::SCOUT_FormClosing);
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SCOUT::SCOUT_FormClosed);
			this->Load += gcnew System::EventHandler(this, &SCOUT::SCOUT_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	
#pragma endregion
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
		System::Void logFile(const std::string& t) {
			HANDLE mut = OpenMutex(MUTEX_ALL_ACCESS, FALSE, L"mut");
			WaitForSingleObject(mut, INFINITE);
			std::ofstream("log.txt", std::ios::app) << t;
			ReleaseMutex(mut);
		}
		System::Void logFile(String^ t) {
			HANDLE mut = OpenMutex(MUTEX_ALL_ACCESS, FALSE, L"mut");
			WaitForSingleObject(mut, INFINITE);
			std::ofstream("log.txt", std::ios::app) << PredLog(t);
			ReleaseMutex(mut);
		}
		delegate System::Void enB();
		System::Void tenB() {
			if (textBox1->InvokeRequired || button1->InvokeRequired) Invoke(enBl);
			else {
				textBox1->Enabled = true;
				button1->Enabled = true;
			}
		}
		enB^ enBl = gcnew enB(this, &SCOUT::tenB);
		
		HANDLE hStart = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"start");
		HANDLE one = CreateEvent(NULL, TRUE, FALSE, L"one");
		HANDLE two = CreateEvent(NULL, TRUE, FALSE, L"two");
		HANDLE end = CreateEvent(NULL, TRUE, FALSE, L"end");
		HANDLE close = CreateEvent(NULL, TRUE, FALSE, L"cl");
		HANDLE s = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, L"s");
		HANDLE hShow = OpenEvent(EVENT_ALL_ACCESS, TRUE, L"SHOW");// —обытие Show будет сообщать клиенту о печати сервером '*'
		Void SCOUT::MF() {
			SetEvent(hStart);  // все создали засетили старт работаем
			if (s == NULL) { textBox1->Text = L"error" + GetLastError(); } // прочекали работает ли семафор
			wait = WaitForSingleObject(s, INFINITE);
			if (wait != WAIT_TIMEOUT) {
				tenB();
			}
		}
	DWORD wait;
	public:
	private: System::Void SCOUT_Load(System::Object^ sender, System::EventArgs^ e) {
		Thread^ thr = gcnew Thread(gcnew ThreadStart(this, &SCOUT::MF));
		thr->Start();
		//SetEvent(hStart);  // все создали засетили старт работаем
		//if (s == NULL) { textBox1->Text = L"error" + GetLastError(); } // прочекали работает ли семафор
		//wait = WaitForSingleObject(s, INFINITE);
		//if (wait != WAIT_TIMEOUT) {
		//	tenB();
		//}
		
	};

	private: System::Void Button1_Click(System::Object^ sender, System::EventArgs^ e) {	
		SetEvent(end);
		WaitForSingleObject(hShow, INFINITE);
	//	Close();
	}
	private: System::Void TextBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		if (e->KeyChar == 49) {	SetEvent(one); }
		else if (e->KeyChar == 50) { SetEvent(two); }
		else { e->Handled = true; }
	}
	private: System::Void SCOUT_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		
	}
	private: System::Void TextBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void SCOUT_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
	SetEvent(close);
	ReleaseSemaphore(s, 1, NULL);
}
};
}
