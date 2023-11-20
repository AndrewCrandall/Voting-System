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
	/// Summary for candidateRemove
	/// </summary>
	public ref class candidateRemove : public System::Windows::Forms::Form
	{
	public:
		candidateRemove(void)
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
		~candidateRemove()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(391, 152);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(176, 41);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Cancel";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &candidateRemove::button1_Click);
			// 
			// candidateRemove
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(701, 368);
			this->Controls->Add(this->button1);
			this->Name = L"candidateRemove";
			this->Text = L"candidateRemove";
			this->Load += gcnew System::EventHandler(this, &candidateRemove::candidateRemove_Load);
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void candidateRemove_Load(System::Object^ sender, System::EventArgs^ e) {
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
			Button^ button2 = gcnew Button();
			//  this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,

			button2->Location = System::Drawing::Point(Left, Top);
			button2->Name = L"candidate";
			button2->Size = System::Drawing::Size(182, 48);
			button2->TabIndex = 0;
			button2->Text = values[i];
			button2->UseVisualStyleBackColor = true;
			button2->Click += gcnew System::EventHandler(this, &candidateRemove::button2_Click);

			Top += 50;

			Controls->Add(button2);
		}
	}

			private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

				try {
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

					for (int i = space1 +1; i < space2; i++) {
						lastName = lastName + data[i];
					}

					for (int i = space2 +1; i < size; i++) {
						party = party + data[i];
					}

					//connection string to database
					String^ connString = "Data Source=localhost;Initial Catalog=FingerPrintVoting;Integrated Security=True";
					SqlConnection sqlConn(connString);

					sqlConn.Open(); //Opens server

					//Query to select all usernames and passwords where they equal users information
					String^ sqlQuery3 = "DELETE FROM candidates WHERE candidate_firstName = @firstName AND candidate_lastName = @lastName AND candidate_party = @candParty;";
					SqlCommand command(sqlQuery3, % sqlConn);

					//Pass By Data
					command.Parameters->AddWithValue("@firstName", firstName);
					command.Parameters->AddWithValue("@lastName", lastName);
					command.Parameters->AddWithValue("@candParty", party);
					command.ExecuteNonQuery();

					MessageBox::Show("Removed the candidate, " + firstName + " " + lastName, "Success", MessageBoxButtons::OK, MessageBoxIcon::Error);
				
					this->Close();
				}

				catch (Exception^ e) { //Any error not being able to connect to database
					MessageBox::Show("Unable to remove the candidate", "Error ", MessageBoxButtons::OK, MessageBoxIcon::Error);
				}

			}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
};
}
