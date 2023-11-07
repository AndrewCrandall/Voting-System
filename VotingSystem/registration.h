#pragma once

namespace VotingSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for registration
	/// </summary>
	public ref class registration : public System::Windows::Forms::Form
	{
	public:
		registration(void)
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
		~registration()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ LNameLabel;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ RLNameTxt;
	private: System::Windows::Forms::TextBox^ RPasswordTxt;



	private: System::Windows::Forms::TextBox^ RFNameTxt;
	private: System::Windows::Forms::Button^ RCancelBtn;

	private: System::Windows::Forms::Button^ RRegisterBtn;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->LNameLabel = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->RLNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->RPasswordTxt = (gcnew System::Windows::Forms::TextBox());
			this->RFNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->RCancelBtn = (gcnew System::Windows::Forms::Button());
			this->RRegisterBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(193, 24);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Register";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(64, 93);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(0, 13);
			this->label2->TabIndex = 1;
			// 
			// LNameLabel
			// 
			this->LNameLabel->AutoSize = true;
			this->LNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LNameLabel->Location = System::Drawing::Point(63, 163);
			this->LNameLabel->Name = L"LNameLabel";
			this->LNameLabel->Size = System::Drawing::Size(86, 20);
			this->LNameLabel->TabIndex = 3;
			this->LNameLabel->Text = L"Last Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(63, 106);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 20);
			this->label3->TabIndex = 4;
			this->label3->Text = L"First Name";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(64, 226);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(85, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Fingerprint";
			// 
			// RLNameTxt
			// 
			this->RLNameTxt->Location = System::Drawing::Point(224, 165);
			this->RLNameTxt->Name = L"RLNameTxt";
			this->RLNameTxt->Size = System::Drawing::Size(162, 20);
			this->RLNameTxt->TabIndex = 6;
			// 
			// RPasswordTxt
			// 
			this->RPasswordTxt->Location = System::Drawing::Point(224, 226);
			this->RPasswordTxt->Name = L"RPasswordTxt";
			this->RPasswordTxt->Size = System::Drawing::Size(162, 20);
			this->RPasswordTxt->TabIndex = 7;
			// 
			// RFNameTxt
			// 
			this->RFNameTxt->Location = System::Drawing::Point(224, 108);
			this->RFNameTxt->Name = L"RFNameTxt";
			this->RFNameTxt->Size = System::Drawing::Size(162, 20);
			this->RFNameTxt->TabIndex = 8;
			// 
			// RCancelBtn
			// 
			this->RCancelBtn->Location = System::Drawing::Point(135, 289);
			this->RCancelBtn->Name = L"RCancelBtn";
			this->RCancelBtn->Size = System::Drawing::Size(104, 34);
			this->RCancelBtn->TabIndex = 9;
			this->RCancelBtn->Text = L"Cancel";
			this->RCancelBtn->UseVisualStyleBackColor = true;
			this->RCancelBtn->Click += gcnew System::EventHandler(this, &registration::RCancelBtn_Click);
			// 
			// RRegisterBtn
			// 
			this->RRegisterBtn->Location = System::Drawing::Point(282, 289);
			this->RRegisterBtn->Name = L"RRegisterBtn";
			this->RRegisterBtn->Size = System::Drawing::Size(104, 34);
			this->RRegisterBtn->TabIndex = 10;
			this->RRegisterBtn->Text = L"Register";
			this->RRegisterBtn->UseVisualStyleBackColor = true;
			this->RRegisterBtn->Click += gcnew System::EventHandler(this, &registration::RRegisterBtn_Click);
			// 
			// registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(610, 382);
			this->Controls->Add(this->RRegisterBtn);
			this->Controls->Add(this->RCancelBtn);
			this->Controls->Add(this->RFNameTxt);
			this->Controls->Add(this->RPasswordTxt);
			this->Controls->Add(this->RLNameTxt);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->LNameLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"registration";
			this->Text = L"registration";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


		// Variables
		private: bool returnToLogin = false;

		// Function Declaration
		public: bool getReturnDecision();

	
private: System::Void RCancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	returnToLogin = true;
	this->Close();
}
private: System::Void RRegisterBtn_Click(System::Object^ sender, System::EventArgs^ e) {


}
};
}
