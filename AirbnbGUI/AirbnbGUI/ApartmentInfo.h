#pragma once

namespace AirbnbGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ApartmentInfo
	/// </summary>
	public ref class ApartmentInfo : public System::Windows::Forms::Form
	{
	public:
		ApartmentInfo(void)
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
		~ApartmentInfo()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::Button^ button1;




		private: System::Windows::Forms::Label^ label6;
		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::TextBox^ textBox2;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::TextBox^ textBox1;
		private: System::Windows::Forms::TextBox^ textBox3;
		private: System::Windows::Forms::TextBox^ textBox4;
		private: System::Windows::Forms::TextBox^ textBox5;
		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::Label^ label8;
		private: System::Windows::Forms::TextBox^ textBox6;
		private: System::Windows::Forms::TextBox^ textBox7;
		private: System::Windows::Forms::Label^ label1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ApartmentInfo::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->ImageLocation = L"Airbnb_Logo.png";
			this->pictureBox1->Location = System::Drawing::Point(15, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(348, 150);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(581, 422);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(126, 37);
			this->button1->TabIndex = 15;
			this->button1->Text = L"Book";
			this->button1->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(474, 238);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 16);
			this->label6->TabIndex = 27;
			this->label6->Text = L"Price:";
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(348, 238);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(92, 16);
			this->label5->TabIndex = 25;
			this->label5->Text = L"Capacity (m3):";
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(592, 237);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(108, 16);
			this->label4->TabIndex = 23;
			this->label4->Text = L"Available rooms:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 240);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 16);
			this->label3->TabIndex = 22;
			this->label3->Text = L"City:";
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Location = System::Drawing::Point(9, 259);
			this->textBox2->Name = L"textBox2";
			this->textBox2->ReadOnly = true;
			this->textBox2->Size = System::Drawing::Size(319, 22);
			this->textBox2->TabIndex = 21;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 294);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 16);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Address:";
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(9, 313);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->ReadOnly = true;
			this->textBox1->Size = System::Drawing::Size(319, 78);
			this->textBox1->TabIndex = 19;
			// 
			// textBox3
			// 
			this->textBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox3->Location = System::Drawing::Point(351, 259);
			this->textBox3->Name = L"textBox3";
			this->textBox3->ReadOnly = true;
			this->textBox3->Size = System::Drawing::Size(112, 22);
			this->textBox3->TabIndex = 33;
			// 
			// textBox4
			// 
			this->textBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox4->Location = System::Drawing::Point(477, 257);
			this->textBox4->Name = L"textBox4";
			this->textBox4->ReadOnly = true;
			this->textBox4->Size = System::Drawing::Size(105, 22);
			this->textBox4->TabIndex = 34;
			// 
			// textBox5
			// 
			this->textBox5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox5->Location = System::Drawing::Point(595, 256);
			this->textBox5->Name = L"textBox5";
			this->textBox5->ReadOnly = true;
			this->textBox5->Size = System::Drawing::Size(112, 22);
			this->textBox5->TabIndex = 35;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(349, 294);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(67, 16);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Start date:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(348, 345);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(64, 16);
			this->label8->TabIndex = 32;
			this->label8->Text = L"End date:";
			// 
			// textBox6
			// 
			this->textBox6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox6->Location = System::Drawing::Point(351, 313);
			this->textBox6->Name = L"textBox6";
			this->textBox6->ReadOnly = true;
			this->textBox6->Size = System::Drawing::Size(356, 22);
			this->textBox6->TabIndex = 36;
			// 
			// textBox7
			// 
			this->textBox7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox7->Location = System::Drawing::Point(351, 364);
			this->textBox7->Name = L"textBox7";
			this->textBox7->ReadOnly = true;
			this->textBox7->Size = System::Drawing::Size(356, 22);
			this->textBox7->TabIndex = 37;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->Location = System::Drawing::Point(4, 183);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(185, 29);
			this->label1->TabIndex = 38;
			this->label1->Text = L"Apartment info:";
			// 
			// ApartmentInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(719, 471);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox7);
			this->Controls->Add(this->textBox6);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"ApartmentInfo";
			this->Text = L"ApartmentInfo";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
