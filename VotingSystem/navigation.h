/*
Title : Navigation Page
Summary : Users ability to decide on where to navigate to
Author : Andrew Crandall
Co Author : N/A
Date Created 10/30/2023
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

	/// <summary>
	/// Summary for navigation
	/// </summary>
	public ref class navigation : public System::Windows::Forms::Form
	{
	public:
		navigation(void)
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
		~navigation()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ voteBtn;
	private: System::Windows::Forms::Button^ statusBtn;
	private: System::Windows::Forms::Button^ logoutBtn;
	protected:

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
			this->voteBtn = (gcnew System::Windows::Forms::Button());
			this->statusBtn = (gcnew System::Windows::Forms::Button());
			this->logoutBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// voteBtn
			// 
			this->voteBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->voteBtn->Location = System::Drawing::Point(167, 101);
			this->voteBtn->Name = L"voteBtn";
			this->voteBtn->Size = System::Drawing::Size(293, 65);
			this->voteBtn->TabIndex = 0;
			this->voteBtn->Text = L"Vote";
			this->voteBtn->UseVisualStyleBackColor = true;
			this->voteBtn->Click += gcnew System::EventHandler(this, &navigation::button1_Click);
			// 
			// statusBtn
			// 
			this->statusBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->statusBtn->Location = System::Drawing::Point(167, 202);
			this->statusBtn->Name = L"statusBtn";
			this->statusBtn->Size = System::Drawing::Size(293, 65);
			this->statusBtn->TabIndex = 1;
			this->statusBtn->Text = L"View Status";
			this->statusBtn->UseVisualStyleBackColor = true;
			this->statusBtn->Click += gcnew System::EventHandler(this, &navigation::statusBtn_Click);
			// 
			// logoutBtn
			// 
			this->logoutBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->logoutBtn->Location = System::Drawing::Point(228, 314);
			this->logoutBtn->Name = L"logoutBtn";
			this->logoutBtn->Size = System::Drawing::Size(166, 40);
			this->logoutBtn->TabIndex = 2;
			this->logoutBtn->Text = L"Logout";
			this->logoutBtn->UseVisualStyleBackColor = true;
			this->logoutBtn->Click += gcnew System::EventHandler(this, &navigation::logoutBtn_Click);
			// 
			// navigation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(655, 438);
			this->Controls->Add(this->logoutBtn);
			this->Controls->Add(this->statusBtn);
			this->Controls->Add(this->voteBtn);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"navigation";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->ResumeLayout(false);

		}
#pragma endregion
	
	// Variables
	private: bool switchToVote = false;
	private: bool switchToStatus = false;
	private: bool switchToLogout = false;

	// Functions
	public: bool getVoteDecision();
	public: bool getStatusDecision();
	public: bool getLogoutDecision();

	//Function that brings user to voting interface
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		switchToVote = true;
		this->Close();//closes current form
	}
	 //Function that brings user to status interface
	private: System::Void statusBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		switchToStatus = true;
		this->Close();
	}
	//Function that brings user to logout
	private: System::Void logoutBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		switchToLogout = true;
			this->Close();
	}
};
}
