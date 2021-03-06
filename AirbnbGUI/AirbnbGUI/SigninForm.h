#pragma once
#include "User.h"
#include "Database.h"
#include "DataSets.h"
#include "SignupForm.h"
#include "ApartmentForm.h"
#include "ApartmentSearch.h"
#include "AdminPanel.h"
#include <msclr\marshal_cppstd.h>

namespace AirbnbGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace msclr::interop;

	
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class SigninForm : public System::Windows::Forms::Form
	{
		public:
		SigninForm(void) {

			InitializeComponent();

			this->Icon = gcnew System::Drawing::Icon("Airbnb_Icon.ico");
		}

		

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~SigninForm()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::TextBox^ emailTextBox;
		protected:

		protected:
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::TextBox^ passwordTextBox;
		private: System::Windows::Forms::LinkLabel^ signUpLinkLabel;
		private: System::Windows::Forms::Button^ SignInButton;





		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::Label^ label4;







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
			this->emailTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->passwordTextBox = (gcnew System::Windows::Forms::TextBox());
			this->signUpLinkLabel = (gcnew System::Windows::Forms::LinkLabel());
			this->SignInButton = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// emailTextBox
			// 
			this->emailTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->emailTextBox->Location = System::Drawing::Point(45, 267);
			this->emailTextBox->Name = L"emailTextBox";
			this->emailTextBox->Size = System::Drawing::Size(285, 22);
			this->emailTextBox->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label1->Location = System::Drawing::Point(42, 244);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Email:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label2->Location = System::Drawing::Point(42, 313);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password:";
			// 
			// passwordTextBox
			// 
			this->passwordTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->passwordTextBox->Location = System::Drawing::Point(45, 336);
			this->passwordTextBox->Name = L"passwordTextBox";
			this->passwordTextBox->Size = System::Drawing::Size(285, 22);
			this->passwordTextBox->TabIndex = 2;
			this->passwordTextBox->UseSystemPasswordChar = true;
			// 
			// signUpLinkLabel
			// 
			this->signUpLinkLabel->AutoSize = true;
			this->signUpLinkLabel->Location = System::Drawing::Point(143, 378);
			this->signUpLinkLabel->Name = L"signUpLinkLabel";
			this->signUpLinkLabel->Size = System::Drawing::Size(52, 16);
			this->signUpLinkLabel->TabIndex = 4;
			this->signUpLinkLabel->TabStop = true;
			this->signUpLinkLabel->Text = L"Sign up";
			this->signUpLinkLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SigninForm::signUpLinkLabel_LinkClicked);
			// 
			// SignInButton
			// 
			this->SignInButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->SignInButton->Location = System::Drawing::Point(268, 606);
			this->SignInButton->Name = L"SignInButton";
			this->SignInButton->Size = System::Drawing::Size(102, 35);
			this->SignInButton->TabIndex = 8;
			this->SignInButton->Text = L"Sign in";
			this->SignInButton->UseVisualStyleBackColor = true;
			this->SignInButton->Click += gcnew System::EventHandler(this, &SigninForm::signInButton_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBox1->ImageLocation = L"Airbnb_Logo.png";
			this->pictureBox1->Location = System::Drawing::Point(13, 27);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(357, 171);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label4->Location = System::Drawing::Point(40, 379);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(105, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Not a member\?";
			// 
			// SigninForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(382, 653);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->SignInButton);
			this->Controls->Add(this->signUpLinkLabel);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->passwordTextBox);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->emailTextBox);
			this->Name = L"SigninForm";
			this->Text = L"Sign in";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void signInButton_Click(System::Object^ sender, System::EventArgs^ e) {

			auto emailStr = marshal_as<std::string>(emailTextBox->Text->ToLower());
			auto passwordStr = marshal_as<std::string>(passwordTextBox->Text);

			DataItem* signinInfo = new DataItem;
			
			signinInfo->AddField("Email", emailStr);
			auto result = Global::Users->searchForDataItem(signinInfo);

			bool isSignedIn = false;

			if (result) {
				
				auto userId = std::stoi(result->at("ID"));

				for (UserKey* key : *Global::Keys->getValues()) {
					if (key->userId == userId && key->key == passwordStr)
						isSignedIn = true;
				}
			}
			else {
				System::Windows::Forms::MessageBox::Show("Email doesn't exist!!");
				emailTextBox->Focus();
				return;
			}

			if (isSignedIn) {

				System::Windows::Forms::MessageBox::Show("Logged in successfully!!");

				for (auto user : Global::Users->loadValues()) {
					if (user->ID == std::stoi(result->at("ID"))) {
						Global::Users->currentSignedInUser = user;
						break;
					}
				}

				ThreadStart^ threadStart;

				if ((int)Global::Users->currentSignedInUser->userType == User::Traveler)
					threadStart = gcnew ThreadStart(threadStartApartmentSearch);

				else if ((int)Global::Users->currentSignedInUser->userType == User::Host)
					threadStart = gcnew ThreadStart(threadStartApartmentForm);

				else if ((int)Global::Users->currentSignedInUser->userType == User::Admin)
					threadStart = gcnew ThreadStart(threadStartAdminPanel);

				Thread^ apartmentApplication = gcnew Thread(threadStart);
				apartmentApplication->Start();

				this->Close();
			}
			else {
				System::Windows::Forms::MessageBox::Show("Your password is incorrect!!");
				passwordTextBox->Focus();
			}
			//Global::Travelers->Push(traveler);
			//Global::Travelers->Save();
			
		}

		private: static void threadStartApartmentForm() {
			Application::Run(gcnew ApartmentForm());
		}

		private: static void threadStartApartmentSearch() {
			Application::Run(gcnew ApartmentSearch());
		}

		private: static void threadStartAdminPanel() {
			Application::Run(gcnew AdminPanel());
		}

		private: System::Void signUpLinkLabel_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {
			SignupForm^ signupForm = gcnew SignupForm;

			signupForm->Show();
			this->Hide();

		}
};
}
