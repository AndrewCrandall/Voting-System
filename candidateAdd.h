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
	/// Summary for candidateUpdate
	/// </summary>
	public ref class candidateUpdate : public System::Windows::Forms::Form
	{
	public:
		candidateUpdate(void)
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
		~candidateUpdate()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ firstNameTxt;
	private: System::Windows::Forms::TextBox^ lastNameTxt;
	private: System::Windows::Forms::TextBox^ partyTxt;
	private: System::Windows::Forms::TextBox^ electionTxt;
	private: System::Windows::Forms::Button^ submitBtn;
	private: System::Windows::Forms::Button^ cancelBtn;


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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->firstNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->lastNameTxt = (gcnew System::Windows::Forms::TextBox());
			this->partyTxt = (gcnew System::Windows::Forms::TextBox());
			this->electionTxt = (gcnew System::Windows::Forms::TextBox());
			this->submitBtn = (gcnew System::Windows::Forms::Button());
			this->cancelBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(112, 53);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(101, 24);
			this->label1->TabIndex = 0;
			this->label1->Text = L"First Name";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(112, 104);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(99, 24);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Last Name";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(112, 206);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(78, 24);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Election";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(112, 155);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(129, 24);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Party Affiliation";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(112, 192);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(0, 24);
			this->label5->TabIndex = 4;
			// 
			// firstNameTxt
			// 
			this->firstNameTxt->Location = System::Drawing::Point(293, 58);
			this->firstNameTxt->Name = L"firstNameTxt";
			this->firstNameTxt->Size = System::Drawing::Size(228, 20);
			this->firstNameTxt->TabIndex = 5;
			// 
			// lastNameTxt
			// 
			this->lastNameTxt->Location = System::Drawing::Point(293, 109);
			this->lastNameTxt->Name = L"lastNameTxt";
			this->lastNameTxt->Size = System::Drawing::Size(228, 20);
			this->lastNameTxt->TabIndex = 6;
			// 
			// partyTxt
			// 
			this->partyTxt->Location = System::Drawing::Point(293, 159);
			this->partyTxt->Name = L"partyTxt";
			this->partyTxt->Size = System::Drawing::Size(228, 20);
			this->partyTxt->TabIndex = 7;
			// 
			// electionTxt
			// 
			this->electionTxt->Location = System::Drawing::Point(293, 206);
			this->electionTxt->Name = L"electionTxt";
			this->electionTxt->Size = System::Drawing::Size(228, 20);
			this->electionTxt->TabIndex = 8;
			// 
			// submitBtn
			// 
			this->submitBtn->Location = System::Drawing::Point(388, 273);
			this->submitBtn->Name = L"submitBtn";
			this->submitBtn->Size = System::Drawing::Size(147, 41);
			this->submitBtn->TabIndex = 9;
			this->submitBtn->Text = L"Submit";
			this->submitBtn->UseVisualStyleBackColor = true;
			this->submitBtn->Click += gcnew System::EventHandler(this, &candidateUpdate::submitBtn_Click);
			// 
			// cancelBtn
			// 
			this->cancelBtn->Location = System::Drawing::Point(185, 273);
			this->cancelBtn->Name = L"cancelBtn";
			this->cancelBtn->Size = System::Drawing::Size(147, 41);
			this->cancelBtn->TabIndex = 10;
			this->cancelBtn->Text = L"Cancel";
			this->cancelBtn->UseVisualStyleBackColor = true;
			this->cancelBtn->Click += gcnew System::EventHandler(this, &candidateUpdate::cancelBtn_Click);
			// 
			// candidateUpdate
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(712, 355);
			this->Controls->Add(this->cancelBtn);
			this->Controls->Add(this->submitBtn);
			this->Controls->Add(this->electionTxt);
			this->Controls->Add(this->partyTxt);
			this->Controls->Add(this->lastNameTxt);
			this->Controls->Add(this->firstNameTxt);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"candidateUpdate";
			this->Text = L"candidateUpdate";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//variables
		private: bool returnToAdminNav = false;
		//functions
		public: bool getAdminNavDecision();


	private: System::Void submitBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ firstName;
		String^ lastName;
		String^ candParty;
		String^ tmpCandElection;
		int voteCount = 0;

		firstName = firstNameTxt->Text;
		lastName = lastNameTxt->Text;
		candParty = partyTxt->Text;
		tmpCandElection = electionTxt->Text;

		int candElection = Convert::ToInt32(tmpCandElection);

		//Data Validation

		try {
			//conectionString variable for database
			String^ connString = "Data Source=localhost;Initial Catalog=FingerPrintVoting;Integrated Security=True";
			//sqlConn is connected to database using connString
			SqlConnection sqlConn(connString);
			//Open Connection
			sqlConn.Open();

			//Query to select all usernames and passwords where they equal users information
			String^ sqlQuery = "INSERT INTO candidates (candidate_firstName, candidate_lastName, candidate_voteCount, candidate_party, candidate_election) VALUES (@firstName, @lastName, @voteCount, @candParty, @candElection);";
			SqlCommand command(sqlQuery, % sqlConn);

			//Pass By Data
			command.Parameters->AddWithValue("@id", 20);
			command.Parameters->AddWithValue("@firstName", firstName);
			command.Parameters->AddWithValue("@lastName", lastName);
			command.Parameters->AddWithValue("@voteCount", voteCount);
			command.Parameters->AddWithValue("@candParty", candParty);
			command.Parameters->AddWithValue("@candElection", candElection);

			command.ExecuteNonQuery();//execute query
			MessageBox::Show("Successfully added new candidate", "Error ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		catch (Exception^ e) { //Any error not being able to connect to database
			MessageBox::Show("Could not add the new candidate, try again ", "Error ", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}

		returnToAdminNav = true;

		this->Close();

	}
	private: System::Void cancelBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		returnToAdminNav = true;
		this->Close();
	}
};
}
