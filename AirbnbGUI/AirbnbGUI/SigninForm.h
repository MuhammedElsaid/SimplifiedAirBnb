#pragma once

namespace AirbnbGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class SigninForm : public System::Windows::Forms::Form
	{
		public:
		SigninForm(void) {
			InitializeComponent();
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
		private: System::Windows::Forms::TextBox^ textBox1;
		protected:
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::TextBox^ textBox2;
		private: System::Windows::Forms::LinkLabel^ linkLabel1;

		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::TextBox^ textBox3;
		private: System::Windows::Forms::Button^ button2;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(SigninForm::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(40, 234);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(284, 22);
			this->textBox1->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label1->Location = System::Drawing::Point(37, 211);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(46, 17);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Email:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8));
			this->label2->Location = System::Drawing::Point(37, 280);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(73, 17);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Password:";
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Location = System::Drawing::Point(40, 303);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(284, 22);
			this->textBox2->TabIndex = 2;
			this->textBox2->UseSystemPasswordChar = true;
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(138, 345);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(52, 16);
			this->linkLabel1->TabIndex = 4;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"Sign up";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &SigninForm::linkLabel1_LinkClicked);
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(267, 560);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(102, 35);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Sign in";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->ImageLocation = L"Airbnb_Logo.png";
			this->pictureBox1->Location = System::Drawing::Point(12, 27);
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
			this->label4->Location = System::Drawing::Point(35, 346);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(105, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Not a member\?";
			// 
			// textBox3
			// 
			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox3->Location = System::Drawing::Point(40, 369);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(284, 22);
			this->textBox3->TabIndex = 6;
			this->textBox3->UseSystemPasswordChar = true;
			this->textBox3->Visible = false;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button2->Location = System::Drawing::Point(12, 560);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(102, 35);
			this->button2->TabIndex = 10;
			this->button2->Text = L"Back";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Visible = false;
			this->button2->Click += gcnew System::EventHandler(this, &SigninForm::button2_Click);
			// 
			// SigninForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(381, 607);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Name = L"SigninForm";
			this->Text = L"Sign in";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		System::Boolean isSignIn = true;
		private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {

			textBox1->Focus();

			label4->Text = "Repeat password:";
			textBox3->Visible = true;
			button1->Text = "Sign up";
			linkLabel1->Visible = false;
			button2->Visible = true;

			isSignIn = false;
		}

		private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

			textBox1->Focus();

			label4->Text = "Not a member?";
			textBox3->Visible = false;
			button1->Text = "Sign in";
			linkLabel1->Visible = true;
			button2->Visible = false;

			isSignIn = true;
		}
};
}
