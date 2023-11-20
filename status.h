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
	/// Summary for status
	/// </summary>



	public ref class status : public System::Windows::Forms::Form
	{
	public:
		status(int userID, int userVote, int candID)
		{
			this->userId = userID;
			this->userCastVote = userVote;
			this->candId = candID;
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~status()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ returnBtn;

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
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->returnBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(218, 59);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(157, 25);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Previous Votes";
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::SystemColors::ButtonFace;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(112, 108);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(344, 153);
			this->textBox1->TabIndex = 1;
			// 
			// returnBtn
			// 
			this->returnBtn->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->returnBtn->Location = System::Drawing::Point(216, 305);
			this->returnBtn->Name = L"returnBtn";
			this->returnBtn->Size = System::Drawing::Size(159, 38);
			this->returnBtn->TabIndex = 2;
			this->returnBtn->Text = L"Return";
			this->returnBtn->UseVisualStyleBackColor = true;
			this->returnBtn->Click += gcnew System::EventHandler(this, &status::returnBtn_Click);
			// 
			// status
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(607, 417);
			this->Controls->Add(this->returnBtn);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"status";
			this->Text = L"status";
			this->Load += gcnew System::EventHandler(this, &status::status_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	//Variables
	private: int userId;
	private: int userCastVote;
	private: int candId;
	private: bool returnToNav = false;

	//Functions
	public: bool getReturnDeision();

	private: System::Void status_Load(System::Object^ sender, System::EventArgs^ e) {
		try {
			//connection string to database
			String^ connString = "Data Source=localhost;Initial Catalog=FingerPrintVoting;Integrated Security=True";
			SqlConnection sqlConn(connString);

			sqlConn.Open(); //Opens server
			
			//Query to match userID with what candidate they voted for
			String^ sqlQuery3 = "SELECT candidate_firstName, candidate_lastName, candidate_party FROM candidates INNER JOIN voters ON voter_id = @voterID AND candidate_id = @voteID";

			SqlCommand command(sqlQuery3, % sqlConn);
	
			command.Parameters->AddWithValue("@voterID", userId);
			command.Parameters->AddWithValue("@voteID", userCastVote);
			//command.Parameters->AddWithValue("@candidate_id", candId);

			SqlDataReader^ reader = command.ExecuteReader();

			String^ data = "You have already voted for candidate ";

			while (reader->Read()) {
				data = data + reader->GetString(0);
				data = data + " ";
				data = data + reader->GetString(1);
				data = data + " ";
				data = data + reader->GetString(2);
			}
			textBox1->Text = data;


		}

		catch (Exception^ e) { //Any error not being able to connect to database
			MessageBox::Show("Unable to show candidates", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			this->Close();
		}


	}
	private: System::Void returnBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		returnToNav = true;
		this->Close();
	}
};
}
