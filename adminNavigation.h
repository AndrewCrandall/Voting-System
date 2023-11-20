#pragma once

namespace VotingSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for adminNavigation
	/// </summary>
	public ref class adminNavigation : public System::Windows::Forms::Form
	{
	public:
		adminNavigation(void)
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
		~adminNavigation()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ updateCandBtn;
	protected:
	private: System::Windows::Forms::Button^ voteCountBtn;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ removeCandBtn;

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
			this->updateCandBtn = (gcnew System::Windows::Forms::Button());
			this->voteCountBtn = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->removeCandBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// updateCandBtn
			// 
			this->updateCandBtn->Location = System::Drawing::Point(157, 46);
			this->updateCandBtn->Name = L"updateCandBtn";
			this->updateCandBtn->Size = System::Drawing::Size(216, 47);
			this->updateCandBtn->TabIndex = 0;
			this->updateCandBtn->Text = L"Add New Candidate";
			this->updateCandBtn->UseVisualStyleBackColor = true;
			this->updateCandBtn->Click += gcnew System::EventHandler(this, &adminNavigation::updateCandBtn_Click);
			// 
			// voteCountBtn
			// 
			this->voteCountBtn->Location = System::Drawing::Point(157, 183);
			this->voteCountBtn->Name = L"voteCountBtn";
			this->voteCountBtn->Size = System::Drawing::Size(216, 47);
			this->voteCountBtn->TabIndex = 1;
			this->voteCountBtn->Text = L"Vote Count";
			this->voteCountBtn->UseVisualStyleBackColor = true;
			this->voteCountBtn->Click += gcnew System::EventHandler(this, &adminNavigation::voteCountBtn_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(121, 298);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(134, 43);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Exit";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &adminNavigation::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(302, 298);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(134, 43);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Logout";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &adminNavigation::button2_Click);
			// 
			// removeCandBtn
			// 
			this->removeCandBtn->Location = System::Drawing::Point(157, 114);
			this->removeCandBtn->Name = L"removeCandBtn";
			this->removeCandBtn->Size = System::Drawing::Size(216, 47);
			this->removeCandBtn->TabIndex = 4;
			this->removeCandBtn->Text = L"Remove Candidate";
			this->removeCandBtn->UseVisualStyleBackColor = true;
			this->removeCandBtn->Click += gcnew System::EventHandler(this, &adminNavigation::removeCandBtn_Click);
			// 
			// adminNavigation
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(577, 399);
			this->Controls->Add(this->removeCandBtn);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->voteCountBtn);
			this->Controls->Add(this->updateCandBtn);
			this->Name = L"adminNavigation";
			this->Text = L"adminNavigation";
			this->ResumeLayout(false);

		}
#pragma endregion

		//variables
	private: bool returnToAdminNav = false;
	private: bool closeApplication = false;
	private: bool addCand = false;
	private: bool removeCand = false;
	private: bool voteCount = false;


		//functions
	public: bool getAdminNavDecision();
	public: bool closeApplicationDecision();
	public: bool getCandAddDecision();
	public: bool getCandRemoveDecision();
	public: bool getVoteCountDecision();



	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		returnToAdminNav = true;
		this->Close();
		
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		closeApplication = true;
		this->Close();
	}
private: System::Void updateCandBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	addCand = true;
	this->Close();
}
private: System::Void voteCountBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	voteCount = true;
	this->Close();
}
private: System::Void removeCandBtn_Click(System::Object^ sender, System::EventArgs^ e) {
	removeCand = true;
	this->Close();
}
};
}
