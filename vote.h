#pragma once

#include <iostream>

namespace VotingSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Data::SqlClient; //SQL connection


	/// <summary>
	/// Summary for vote
	/// </summary>
	public ref class vote : public System::Windows::Forms::Form
	{
	public:
		vote(void)
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
		~vote()
		{
			if (components)
			{
				delete components;
			}
		}

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
			this->SuspendLayout();
			// 
			// vote
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(599, 342);
			this->Name = L"vote";
			this->Text = L"vote";
			this->Load += gcnew System::EventHandler(this, &vote::vote_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

		//variables
		private:bool voted = false;
		private:String^ candFirstName;
		private:String^ candLastName;
		private:String^ candParty;

		//functions

		public:bool getVote();

		public:String^ getVoteFName();
		public:String^ getVoteLName();
		public:String^ getParty();
		




	private: System::Void vote_Load(System::Object^ sender, System::EventArgs^ e) {

		int counter;
		//conectionString variable for database
		String^ connString = "Data Source=localhost;Initial Catalog=FingerPrintVoting;Integrated Security=True";
		//sqlConn is connected to database using connString
		SqlConnection sqlConn(connString);
		//Open Connection

		sqlConn.Open(); //Opens server

		//Query to select all usernames and passwords where they equal users information
		String^ sqlQuery = "SELECT COUNT(*) FROM candidates;";
		SqlCommand command(sqlQuery, % sqlConn);

		counter = (Int32)command.ExecuteScalar();

		String^ tmp = counter.ToString();

		String^ sqlQuery2 = "SELECT candidate_firstName, candidate_lastName, candidate_party AS Candidate FROM candidates;";

		String^ data;
		array<String^>^ values = gcnew array<String^>(counter);

		String^ firstName;
		String^ lastName;
		String^ party;



		SqlCommand command2(sqlQuery2, % sqlConn);

		SqlDataReader^ reader2 = command2.ExecuteReader();
		int tmpCounter = 0;
		while (reader2->Read() && tmpCounter < counter) {
			data = data + reader2->GetString(0);
			data = data + " ";
			data = data + reader2->GetString(1);
			data = data + " ";
			data = data + reader2->GetString(2);
			
			values[tmpCounter] = data;
			data = "";
			tmpCounter = tmpCounter + 1;

		}

		int DisUnit = 1;
		int Top = 70;
		int Left = 150;


		


		for (int i = 0; i < counter; i++) {
			Button^ button1 = gcnew Button();
		//  this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
			
			button1->Location = System::Drawing::Point(Left, Top);
			button1->Name = L"button1";
			button1->Size = System::Drawing::Size(182, 48);
			button1->TabIndex = 0;
			button1->Text = values[i];
			button1->UseVisualStyleBackColor = true;
			button1->Click += gcnew System::EventHandler(this, &vote::button1_Click);


			Top += 50;


			Controls->Add(button1);
		}

	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		try {

			//connection string to database
			String^ connString = "Data Source=localhost;Initial Catalog=FingerPrintVoting;Integrated Security=True";
			SqlConnection sqlConn(connString);

			sqlConn.Open(); //Opens server

			Button^ currentButton = (Button^)sender;
			String^ data = currentButton->Text;
			String^ firstName;
			String^ lastName;
			String^ party;
			int size = data->Length;

			int space1 = -1;
			int space2 = -1;
			bool firstFound = false;
			bool secondFound = false;
			bool thirdFound = false;


			// Loop through each character in the string
			for (int i = 0; i < size; ++i) {
				// Check if the character is a space
				if (data[i] == ' ') {
					// If first space is found
					if (space1 == -1) {
						space1 = i;
					}
					else {  // If second space is found
						space2 = i;
						break;  // Break out of the loop after finding the second space
					}
				}

			}


			//Setting words

			for (int i = 0; i < space1; i++) {
				firstName = firstName + data[i];
			}

			for (int i = space1; i < space2; i++) {
				lastName = lastName + data[i];
			}

			for (int i = space2; i < size; i++) {
				party = party + data[i];
			}

			voted = true;
			candFirstName = firstName;
			candLastName = lastName;
			candParty = party;
			this->Close();

		}
		catch (Exception^ ex) { //otherwise show to user that there was an error
			MessageBox::Show("Failed to vote, try again. ", "Error ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

	}

};
}
