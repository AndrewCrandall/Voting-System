#pragma once

namespace VotingSystem {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for userNav
	/// </summary>
	public ref class userNav : public System::Windows::Forms::Form
	{
	public:
		userNav(void)
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
		~userNav()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ personImage;
	private: System::Windows::Forms::PictureBox^ statImage;

	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::TextBox^ managementHeading;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(userNav::typeid));
			this->personImage = (gcnew System::Windows::Forms::PictureBox());
			this->statImage = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->managementHeading = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->personImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->statImage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// personImage
			// 
			this->personImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"personImage.Image")));
			this->personImage->Location = System::Drawing::Point(100, 160);
			this->personImage->Name = L"personImage";
			this->personImage->Size = System::Drawing::Size(135, 136);
			this->personImage->TabIndex = 0;
			this->personImage->TabStop = false;
			this->personImage->Click += gcnew System::EventHandler(this, &userNav::pictureBox1_Click);
			// 
			// statImage
			// 
			this->statImage->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"statImage.Image")));
			this->statImage->Location = System::Drawing::Point(341, 170);
			this->statImage->Name = L"statImage";
			this->statImage->Size = System::Drawing::Size(121, 121);
			this->statImage->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->statImage->TabIndex = 1;
			this->statImage->TabStop = false;
			// 
			// pictureBox3
			// 
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(573, 168);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(128, 128);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
			this->pictureBox3->TabIndex = 3;
			this->pictureBox3->TabStop = false;
			// 
			// managementHeading
			// 
			this->managementHeading->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->managementHeading->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->managementHeading->Location = System::Drawing::Point(268, 60);
			this->managementHeading->Name = L"managementHeading";
			this->managementHeading->ReadOnly = true;
			this->managementHeading->Size = System::Drawing::Size(276, 38);
			this->managementHeading->TabIndex = 4;
			this->managementHeading->Text = L"Voting Management";
			this->managementHeading->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			this->managementHeading->Visible = false;
			// 
			// userNav
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(812, 443);
			this->Controls->Add(this->managementHeading);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->statImage);
			this->Controls->Add(this->personImage);
			this->Name = L"userNav";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"userNav";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->personImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->statImage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};
}
