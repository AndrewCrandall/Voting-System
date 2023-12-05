/*
Title : Registration Page
Summary : Users ability to register for voting
Author : Andrew Crandall
Co Author : N/A
Date Created 10/31/2023
Last Updated 11/20/2023
*/

#pragma once

namespace VotingSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient; //SQL connection

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
	private: System::Windows::Forms::TextBox^ RPhoneTxt;




	private: System::Windows::Forms::TextBox^ RFNameTxt;
	private: System::Windows::Forms::Button^ RCancelBtn;

	private: System::Windows::Forms::Button^ RRegisterBtn;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ RAddressTxt;



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
			this->RPhoneTxt = (gcnew System::Windows::Forms::TextBox());
			this->RFNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->RCancelBtn = (gcnew System::Windows::Forms::Button());
			this->RRegisterBtn = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->RAddressTxt = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(80, 21);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(233, 46);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Registration";
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
			this->LNameLabel->Location = System::Drawing::Point(74, 162);
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
			this->label3->Location = System::Drawing::Point(74, 96);
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
			this->label4->Location = System::Drawing::Point(58, 223);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(115, 20);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Phone Number";
			// 
			// RLNameTxt
			// 
			this->RLNameTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RLNameTxt->Location = System::Drawing::Point(225, 159);
			this->RLNameTxt->Name = L"RLNameTxt";
			this->RLNameTxt->Size = System::Drawing::Size(259, 26);
			this->RLNameTxt->TabIndex = 6;
			// 
			// RPhoneTxt
			// 
			this->RPhoneTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RPhoneTxt->Location = System::Drawing::Point(225, 220);
			this->RPhoneTxt->Name = L"RPhoneTxt";
			this->RPhoneTxt->Size = System::Drawing::Size(259, 26);
			this->RPhoneTxt->TabIndex = 7;
			// 
			// RFNameTxt
			// 
			this->RFNameTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RFNameTxt->Location = System::Drawing::Point(225, 93);
			this->RFNameTxt->Name = L"RFNameTxt";
			this->RFNameTxt->Size = System::Drawing::Size(259, 26);
			this->RFNameTxt->TabIndex = 8;
			// 
			// RCancelBtn
			// 
			this->RCancelBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RCancelBtn->Location = System::Drawing::Point(225, 356);
			this->RCancelBtn->Name = L"RCancelBtn";
			this->RCancelBtn->Size = System::Drawing::Size(104, 34);
			this->RCancelBtn->TabIndex = 9;
			this->RCancelBtn->Text = L"Cancel";
			this->RCancelBtn->UseVisualStyleBackColor = true;
			this->RCancelBtn->Click += gcnew System::EventHandler(this, &registration::RCancelBtn_Click);
			// 
			// RRegisterBtn
			// 
			this->RRegisterBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RRegisterBtn->Location = System::Drawing::Point(380, 356);
			this->RRegisterBtn->Name = L"RRegisterBtn";
			this->RRegisterBtn->Size = System::Drawing::Size(104, 34);
			this->RRegisterBtn->TabIndex = 10;
			this->RRegisterBtn->Text = L"Register";
			this->RRegisterBtn->UseVisualStyleBackColor = true;
			this->RRegisterBtn->Click += gcnew System::EventHandler(this, &registration::RRegisterBtn_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(74, 284);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(68, 20);
			this->label5->TabIndex = 11;
			this->label5->Text = L"Address";
			// 
			// RAddressTxt
			// 
			this->RAddressTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RAddressTxt->Location = System::Drawing::Point(225, 281);
			this->RAddressTxt->Name = L"RAddressTxt";
			this->RAddressTxt->Size = System::Drawing::Size(259, 26);
			this->RAddressTxt->TabIndex = 12;
			// 
			// registration
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(655, 438);
			this->Controls->Add(this->RAddressTxt);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->RRegisterBtn);
			this->Controls->Add(this->RCancelBtn);
			this->Controls->Add(this->RFNameTxt);
			this->Controls->Add(this->RPhoneTxt);
			this->Controls->Add(this->RLNameTxt);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->LNameLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"registration";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		// Variables
	private: bool returnToLogin = false;

		// Functions
	public:  bool getReturnDecision();
	private: bool nameValidation(String^ name);
	private: bool phoneValidation(String^ phone);
	private: bool addressValidation(String^ address);



	private: System::Void RCancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		returnToLogin = true;
		this->Close();
	}

	private: System::Void RRegisterBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		//Pass By Data
		String^ fName = RFNameTxt->Text;
		String^ lName = RLNameTxt->Text;
		String^ phone = RPhoneTxt->Text;
		String^ address = RAddressTxt->Text;
		String^ fingerprint = "Test";
		int vote = 0;
		
		//Add Data Validation

		// Creating a new voter
		try {
			//connection string to database
			String^ connString = "Data Source=localhost;Initial Catalog=FingerPrintVoting;Integrated Security=True";
			SqlConnection sqlConn(connString);

			sqlConn.Open(); //Opens server

				String^ sqlQuery2 = "INSERT INTO voters " + "(voter_firstName, voter_lastName, voter_phoneNumber, voter_fingerprint, voter_address, voter_castVote) VALUES " + "(@firstName, @lastName, @phoneNumber,@fingerprint, @fullAddress, @castvote)";
				SqlCommand command(sqlQuery2, % sqlConn);

				//ADDITION OF FINGERPRINT CODE
				// don't forget to reassign 'fingerprint'

				//Pass By Values
				command.Parameters->AddWithValue("@firstName", fName);
				command.Parameters->AddWithValue("@lastName", lName);
				command.Parameters->AddWithValue("@phoneNumber", phone);
				command.Parameters->AddWithValue("@fingerprint", fingerprint);
				command.Parameters->AddWithValue("@fullAddress", address);
				command.Parameters->AddWithValue("@castVote", vote);

				//Command Execution
				command.ExecuteNonQuery(); //execute query

				returnToLogin = true;
				this->Close();//closes current form, user is successfully created
		}
		//Unable to connect to database
		catch (Exception^ ex) { //otherwise show to user that there was an error
			MessageBox::Show("Failed to Create New User ", "Error ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	};
	};
}
