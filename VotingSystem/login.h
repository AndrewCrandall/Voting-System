/*
Title : Login
Summary : Initial interface of program, allows for user to login
Author : Andrew Crandall
Co Author : N/A
Date Created 10/30/2023
Last Updated 11/20/2023
*/

#pragma once
#include "voter.h"


namespace VotingSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient; //SQL connection

	/// <summary>
	/// Summary for login
	/// </summary>
	public ref class login : public System::Windows::Forms::Form
	{
	public:
		login(void)
		{
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// </summary>
		~login()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ LFNameTxt;
	protected:

	protected:

	private: System::Windows::Forms::Label^ FNameLabel;
	private: System::Windows::Forms::Label^ LNameLabel;
	private: System::Windows::Forms::TextBox^ LLNameTxt;

	private: System::Windows::Forms::Label^ PasswordLabel;
	private: System::Windows::Forms::TextBox^ LPasswordTxt;

	private: System::Windows::Forms::Button^ LoginBtn;
	private: System::Windows::Forms::Button^ RegisterBtn;
	private: System::Windows::Forms::Label^ label1;





	protected:

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
			this->LFNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->FNameLabel = (gcnew System::Windows::Forms::Label());
			this->LNameLabel = (gcnew System::Windows::Forms::Label());
			this->LLNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->PasswordLabel = (gcnew System::Windows::Forms::Label());
			this->LPasswordTxt = (gcnew System::Windows::Forms::TextBox());
			this->LoginBtn = (gcnew System::Windows::Forms::Button());
			this->RegisterBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// LFNameTxt
			// 
			this->LFNameTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LFNameTxt->Location = System::Drawing::Point(290, 113);
			this->LFNameTxt->Name = L"LFNameTxt";
			this->LFNameTxt->Size = System::Drawing::Size(242, 26);
			this->LFNameTxt->TabIndex = 0;
			this->LFNameTxt->TextChanged += gcnew System::EventHandler(this, &login::textBox1_TextChanged);
			// 
			// FNameLabel
			// 
			this->FNameLabel->AutoSize = true;
			this->FNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FNameLabel->Location = System::Drawing::Point(111, 113);
			this->FNameLabel->Name = L"FNameLabel";
			this->FNameLabel->Size = System::Drawing::Size(101, 24);
			this->FNameLabel->TabIndex = 1;
			this->FNameLabel->Text = L"First Name";
			// 
			// LNameLabel
			// 
			this->LNameLabel->AutoSize = true;
			this->LNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LNameLabel->Location = System::Drawing::Point(111, 203);
			this->LNameLabel->Name = L"LNameLabel";
			this->LNameLabel->Size = System::Drawing::Size(99, 24);
			this->LNameLabel->TabIndex = 2;
			this->LNameLabel->Text = L"Last Name";
			// 
			// LLNameTxt
			// 
			this->LLNameTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LLNameTxt->Location = System::Drawing::Point(290, 203);
			this->LLNameTxt->Name = L"LLNameTxt";
			this->LLNameTxt->Size = System::Drawing::Size(242, 26);
			this->LLNameTxt->TabIndex = 3;
			// 
			// PasswordLabel
			// 
			this->PasswordLabel->AutoSize = true;
			this->PasswordLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->PasswordLabel->Location = System::Drawing::Point(60, 286);
			this->PasswordLabel->Name = L"PasswordLabel";
			this->PasswordLabel->Size = System::Drawing::Size(200, 24);
			this->PasswordLabel->TabIndex = 4;
			this->PasswordLabel->Text = L"Password (Fingerprint)";
			// 
			// LPasswordTxt
			// 
			this->LPasswordTxt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LPasswordTxt->Location = System::Drawing::Point(290, 286);
			this->LPasswordTxt->Name = L"LPasswordTxt";
			this->LPasswordTxt->Size = System::Drawing::Size(242, 26);
			this->LPasswordTxt->TabIndex = 5;
			// 
			// LoginBtn
			// 
			this->LoginBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->LoginBtn->Location = System::Drawing::Point(398, 363);
			this->LoginBtn->Name = L"LoginBtn";
			this->LoginBtn->Size = System::Drawing::Size(104, 34);
			this->LoginBtn->TabIndex = 6;
			this->LoginBtn->Text = L"Login";
			this->LoginBtn->UseVisualStyleBackColor = true;
			this->LoginBtn->Click += gcnew System::EventHandler(this, &login::LoginBtn_Click);
			// 
			// RegisterBtn
			// 
			this->RegisterBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->RegisterBtn->Location = System::Drawing::Point(208, 363);
			this->RegisterBtn->Name = L"RegisterBtn";
			this->RegisterBtn->Size = System::Drawing::Size(104, 34);
			this->RegisterBtn->TabIndex = 7;
			this->RegisterBtn->Text = L"Register";
			this->RegisterBtn->UseVisualStyleBackColor = true;
			this->RegisterBtn->Click += gcnew System::EventHandler(this, &login::RegisterBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 30, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(182, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(130, 46);
			this->label1->TabIndex = 8;
			this->label1->Text = L"Log In";
			// 
			// login
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(655, 438);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->RegisterBtn);
			this->Controls->Add(this->LoginBtn);
			this->Controls->Add(this->LPasswordTxt);
			this->Controls->Add(this->PasswordLabel);
			this->Controls->Add(this->LLNameTxt);
			this->Controls->Add(this->LNameLabel);
			this->Controls->Add(this->FNameLabel);
			this->Controls->Add(this->LFNameTxt);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"login";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion


	// Variables
		private: bool switchToRegister = false; 
		private: bool adminLogin = false;
		private: voter user;

	// Functions
		public: bool getRegisterDeision();
		public: bool getAdminLogin();

		public: int getVoterID();
		public: int getVoterStatus();
		public: String^ getFirstName();
		public: String^ getPassword();
		public: String^ getLastName();

	
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	/*
	Login Button
	Returns Void
	Takes user input and determines if it is valid
	if so, user is logged in if not more input is requested
	*/
	private: System::Void LoginBtn_Click(System::Object^ sender, System::EventArgs^ e) {

		String^ firstName = LFNameTxt->Text;
		String^ lastName = LLNameTxt->Text;
		String^ fingerprint = LPasswordTxt->Text;
		String^ adminFName = "Admin";
		String^ adminLName = "Admin";
		String^ adminFPrint = "test";

		//To Do, add more input validation
		if (firstName->Length <= 0 || lastName->Length <= 0) {
			MessageBox::Show("You must enter all values! ", "Error ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		try {
			//conectionString variable for database
			String^ connString = "Data Source=localhost;Initial Catalog=FingerPrintVoting;Integrated Security=True";
			//sqlConn is connected to database using connString
			SqlConnection sqlConn(connString);
			//Open Connection
			sqlConn.Open();

			//Query to select all usernames and passwords where they equal users information
			String^ sqlQuery = "Select voter_id, voter_firstName, voter_lastName, voter_fingerprint, voter_castVote from voters WHERE voter_firstName=@voter_firstName AND voter_lastName=@voter_lastName AND voter_fingerprint=@voter_fingerprint";
			SqlCommand command(sqlQuery, % sqlConn);

			//Pass By Data
			command.Parameters->AddWithValue("@voter_firstName", firstName);
			command.Parameters->AddWithValue("@voter_lastName", lastName);
			command.Parameters->AddWithValue("@voter_fingerprint", fingerprint);

			//Execute query
			SqlDataReader^ reader = command.ExecuteReader();
			if (reader->Read()) { //login is valid
				
				//Data
				int tmpId;
				String^ tmpFirst;
				String^ tmpLast;
				String^ tmpPass;
				int tmpVote;

				//Placing data into variables
				tmpId = reader->GetInt32(0);
				tmpFirst = reader->GetString(1);
				tmpLast = reader->GetString(2);
				tmpPass = reader->GetString(3);
				tmpVote = reader->GetInt32(4);

				//Setting user information
				user.setId(tmpId);
				user.setFirstName(tmpFirst);
				user.setLastName(tmpLast);
				user.setPassword(tmpPass);
				user.setVoteStatus(tmpVote);

				//User loggin in is an Admin
				if (user.getId() == 1) {
					adminLogin = true;
				}
				this->Close();
			}
			//No valid login found
			else
				//Login infromation is incorrect
				MessageBox::Show("Invalid login, please try again", "Error ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
		//Error connecting to database
		catch (Exception^ e) { //Any error not being able to connect to database
			MessageBox::Show("Could not connect to database, try again! ", "Error ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}
	private: System::Void RegisterBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		switchToRegister = true; //used in main.cpp
		this->Close();//closes current form
	}
	};
}
