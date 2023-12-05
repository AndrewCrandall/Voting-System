/*
Title : Administrator Vote Count
Summary : Ability for administrator to see all of the candidates votes
Author : Andrew Crandall
Co Author : N/A
Date Created 11/20/2023
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
	/// Summary for voteCount
	/// </summary>
	public ref class voteCount : public System::Windows::Forms::Form
	{
	public:
		voteCount(void)
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
		~voteCount()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::TextBox^ voteCountDisplay;
	private: System::Windows::Forms::Button^ returnNavBtn;
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
			this->voteCountDisplay = (gcnew System::Windows::Forms::TextBox());
			this->returnNavBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// voteCountDisplay
			// 
			this->voteCountDisplay->AcceptsReturn = true;
			this->voteCountDisplay->AcceptsTab = true;
			this->voteCountDisplay->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->voteCountDisplay->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->voteCountDisplay->Cursor = System::Windows::Forms::Cursors::No;
			this->voteCountDisplay->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->voteCountDisplay->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->voteCountDisplay->Location = System::Drawing::Point(128, 71);
			this->voteCountDisplay->Multiline = true;
			this->voteCountDisplay->Name = L"voteCountDisplay";
			this->voteCountDisplay->ReadOnly = true;
			this->voteCountDisplay->Size = System::Drawing::Size(319, 199);
			this->voteCountDisplay->TabIndex = 1;
			// 
			// returnNavBtn
			// 
			this->returnNavBtn->Location = System::Drawing::Point(202, 293);
			this->returnNavBtn->Name = L"returnNavBtn";
			this->returnNavBtn->Size = System::Drawing::Size(158, 35);
			this->returnNavBtn->TabIndex = 2;
			this->returnNavBtn->Text = L"Return";
			this->returnNavBtn->UseVisualStyleBackColor = true;
			this->returnNavBtn->Click += gcnew System::EventHandler(this, &voteCount::returnNavBtn_Click);
			// 
			// voteCount
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(655, 438);
			this->Controls->Add(this->returnNavBtn);
			this->Controls->Add(this->voteCountDisplay);
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"voteCount";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Load += gcnew System::EventHandler(this, &voteCount::voteCount_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		//Variables
	private: bool returnToAdminNav = false;
		
		   //Functions
	public: bool getAdminNavDecision();

	//Function to load the candidates vote count
	private: System::Void voteCount_Load(System::Object^ sender, System::EventArgs^ e) {
		//try statement to get the vote counts

		//voteCountDisplay

		voteCountDisplay->Text = "Candidate" + "\t" + "Vote Count" + "\r\n" + "\r\n";

		try {
			//conectionString variable for database
			String^ connString = "Data Source=localhost;Initial Catalog=FingerPrintVoting;Integrated Security=True";
			//sqlConn is connected to database using connString
			SqlConnection sqlConn(connString);
			//Open Connection
			sqlConn.Open();

			//Query to select all usernames and passwords where they equal users information
			String^ sqlQuery = "SELECT candidate_firstName, candidate_lastName, candidate_voteCount FROM candidates";
			SqlCommand command(sqlQuery, % sqlConn);

			//Execute query
			SqlDataReader^ reader = command.ExecuteReader();
			while (reader->Read()) { //login is valid

				String^ tmpFirst;
				String^ tmpLast;
				int tmpVote;

				//Reading data
				tmpFirst = reader->GetString(0);
				tmpLast = reader->GetString(1);
				tmpVote = reader->GetInt32(2);

				//Tmp Data, used to place in textbox
				String^ tmpVoteStr = tmpVote.ToString();
				String^ tmpString = tmpFirst + " " + tmpLast + "\t     " + tmpVoteStr + "\r\n";

				//Displays vote count
				voteCountDisplay->Text += tmpString;
			}	
		}
		catch (Exception^ e) { //Any error not being able to connect to database
			MessageBox::Show("Could not connect to database, try again! ", "Error ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}
	
	private: System::Void returnNavBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		returnToAdminNav = true;
		this->Close();
	}
};
}
