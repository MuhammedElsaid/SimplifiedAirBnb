#pragma once
#include "Database.h"
#include "DataSets.h"
#include <msclr\marshal_cppstd.h>

namespace AirbnbGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for SignupForm
	/// </summary>
	public ref class SignupForm : public System::Windows::Forms::Form
	{
	public:
		SignupForm(void)
		{
			InitializeComponent();
			this->Icon = gcnew System::Drawing::Icon("Airbnb_Icon.ico");

			//
			//TODO: Add the constructor code here
			//
			accountTypeCombobox->SelectedIndex = 0;
			accountTypeCombobox->DropDownStyle = ComboBoxStyle::DropDownList;

			genderComboBox->SelectedIndex = 0;
			genderComboBox->DropDownStyle = ComboBoxStyle::DropDownList;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SignupForm()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::ComboBox^ accountTypeCombobox;
		private: System::Windows::Forms::Button^ backButton;
		protected:




		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::Button^ signUpButton;


		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::TextBox^ emailTextBox;

		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::TextBox^ fullNameTextBox;

		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::ComboBox^ genderComboBox;

		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::TextBox^ passTextBox;

		private: System::Windows::Forms::Label^ label6;
		private: System::Windows::Forms::TextBox^ repeatPassTextBox;

		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::NumericUpDown^ ageNumBox;


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
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->accountTypeCombobox = (gcnew System::Windows::Forms::ComboBox());
			this->backButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->signUpButton = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->fullNameTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->genderComboBox = (gcnew System::Windows::Forms::ComboBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->passTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->repeatPassTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->ageNumBox = (gcnew System::Windows::Forms::NumericUpDown());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ageNumBox))->BeginInit();
			this->SuspendLayout();
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label3->Location = System::Drawing::Point(37, 203);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(99, 17);
			this->label3->TabIndex = 24;
			this->label3->Text = L"Account Type:";
			// 
			// accountTypeCombobox
			// 
			this->accountTypeCombobox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->accountTypeCombobox->DisplayMember = L"Traveler";
			this->accountTypeCombobox->FormattingEnabled = true;
			this->accountTypeCombobox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Traveler", L"Host" });
			this->accountTypeCombobox->Location = System::Drawing::Point(40, 228);
			this->accountTypeCombobox->Name = L"accountTypeCombobox";
			this->accountTypeCombobox->Size = System::Drawing::Size(284, 24);
			this->accountTypeCombobox->TabIndex = 23;
			// 
			// backButton
			// 
			this->backButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->backButton->Location = System::Drawing::Point(13, 615);
			this->backButton->Name = L"backButton";
			this->backButton->Size = System::Drawing::Size(102, 35);
			this->backButton->TabIndex = 22;
			this->backButton->Text = L"Back";
			this->backButton->UseVisualStyleBackColor = true;
			this->backButton->Click += gcnew System::EventHandler(this, &SignupForm::backButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBox1->ImageLocation = L"Airbnb_Logo.png";
			this->pictureBox1->Location = System::Drawing::Point(13, 19);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(357, 171);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 19;
			this->pictureBox1->TabStop = false;
			// 
			// signUpButton
			// 
			this->signUpButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->signUpButton->Location = System::Drawing::Point(268, 615);
			this->signUpButton->Name = L"signUpButton";
			this->signUpButton->Size = System::Drawing::Size(102, 35);
			this->signUpButton->TabIndex = 20;
			this->signUpButton->Text = L"Sign up";
			this->signUpButton->UseVisualStyleBackColor = true;
			this->signUpButton->Click += gcnew System::EventHandler(this, &SignupForm::signUpButton_Click);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label2->Location = System::Drawing::Point(37, 329);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(46, 17);
			this->label2->TabIndex = 16;
			this->label2->Text = L"Email:";
			// 
			// emailTextBox
			// 
			this->emailTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->emailTextBox->Location = System::Drawing::Point(40, 352);
			this->emailTextBox->Name = L"emailTextBox";
			this->emailTextBox->Size = System::Drawing::Size(285, 22);
			this->emailTextBox->TabIndex = 15;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label1->Location = System::Drawing::Point(37, 266);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(73, 17);
			this->label1->TabIndex = 14;
			this->label1->Text = L"Full name:";
			// 
			// fullNameTextBox
			// 
			this->fullNameTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->fullNameTextBox->Location = System::Drawing::Point(40, 289);
			this->fullNameTextBox->Name = L"fullNameTextBox";
			this->fullNameTextBox->Size = System::Drawing::Size(285, 22);
			this->fullNameTextBox->TabIndex = 13;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label4->Location = System::Drawing::Point(37, 391);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(60, 17);
			this->label4->TabIndex = 25;
			this->label4->Text = L"Gender:";
			// 
			// genderComboBox
			// 
			this->genderComboBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->genderComboBox->FormattingEnabled = true;
			this->genderComboBox->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"Male", L"Female" });
			this->genderComboBox->Location = System::Drawing::Point(40, 411);
			this->genderComboBox->Name = L"genderComboBox";
			this->genderComboBox->Size = System::Drawing::Size(133, 24);
			this->genderComboBox->TabIndex = 16;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label5->Location = System::Drawing::Point(37, 455);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(73, 17);
			this->label5->TabIndex = 28;
			this->label5->Text = L"Password:";
			// 
			// passTextBox
			// 
			this->passTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->passTextBox->Location = System::Drawing::Point(40, 478);
			this->passTextBox->Name = L"passTextBox";
			this->passTextBox->Size = System::Drawing::Size(285, 22);
			this->passTextBox->TabIndex = 18;
			this->passTextBox->UseSystemPasswordChar = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label6->Location = System::Drawing::Point(37, 515);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(123, 17);
			this->label6->TabIndex = 30;
			this->label6->Text = L"Repeat Password:";
			// 
			// repeatPassTextBox
			// 
			this->repeatPassTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->repeatPassTextBox->Location = System::Drawing::Point(40, 538);
			this->repeatPassTextBox->Name = L"repeatPassTextBox";
			this->repeatPassTextBox->Size = System::Drawing::Size(285, 22);
			this->repeatPassTextBox->TabIndex = 19;
			this->repeatPassTextBox->UseSystemPasswordChar = true;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label7->Location = System::Drawing::Point(176, 391);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(37, 17);
			this->label7->TabIndex = 32;
			this->label7->Text = L"Age:";
			// 
			// ageNumBox
			// 
			this->ageNumBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->ageNumBox->Location = System::Drawing::Point(179, 411);
			this->ageNumBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
			this->ageNumBox->Name = L"ageNumBox";
			this->ageNumBox->Size = System::Drawing::Size(146, 22);
			this->ageNumBox->TabIndex = 17;
			this->ageNumBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 16, 0, 0, 0 });
			// 
			// SignupForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(382, 670);
			this->Controls->Add(this->ageNumBox);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->repeatPassTextBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->passTextBox);
			this->Controls->Add(this->genderComboBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->accountTypeCombobox);
			this->Controls->Add(this->backButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->signUpButton);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->emailTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->fullNameTextBox);
			this->Name = L"SignupForm";
			this->Text = L"Sign up";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &SignupForm::SignupForm_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ageNumBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void SignupForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {

			Application::OpenForms[0]->Show();
		}

		private: System::Void backButton_Click(System::Object^ sender, System::EventArgs^ e) {

			this->Close();
		}

		private: bool userExists(std::string email) {

			bool exists = false;

			

			return exists;
		}

		private: System::Void signUpButton_Click(System::Object^ sender, System::EventArgs^ e) {


			auto emailStr = marshal_as<std::string>(emailTextBox->Text->ToLower());
			auto fullNameStr = marshal_as<std::string>(fullNameTextBox->Text);
			auto passwordStr = marshal_as<std::string>(passTextBox->Text);
			auto genderStr = marshal_as<std::string>(genderComboBox->Text);
			auto age = Decimal::ToInt32(ageNumBox->Value);

			if (passTextBox->Text != repeatPassTextBox->Text) {

				System::Windows::Forms::MessageBox::Show("Passwords don't match!!");
				passTextBox->Focus();
				repeatPassTextBox->Clear();
				return;
			}

			for (User* user : *Global::Users->getValues()) {
				if (user->email == emailStr) {
					emailTextBox->Focus();
					System::Windows::Forms::MessageBox::Show("A user with that email already exists!! Try another email.");
					return;
				}
			}

			User* user = nullptr;

			user = accountTypeCombobox->SelectedIndex == 0 ? (User*)
				new Traveler({ fullNameStr, emailStr, genderStr, age }) :
				new Host({ fullNameStr, emailStr, genderStr, age });
			
			Global::Users->Push(user);
			Global::Users->Save();

			UserKey* userKey = new UserKey(user->ID, passwordStr);
			Global::Keys->Push(userKey);
			Global::Keys->Save();

			System::Windows::Forms::MessageBox::Show("Account has been created successfully!!");
			this->Close();

		}
};
}
