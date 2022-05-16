#pragma once

namespace AirbnbGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ApartmentForm
	/// </summary>
	public ref class ApartmentForm : public System::Windows::Forms::Form
	{
	public:
		ApartmentForm(void)
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
		~ApartmentForm()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::Label^ label1;
		protected:
		private: System::Windows::Forms::TextBox^ textBox1;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::TextBox^ textBox2;
		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
		private: System::Windows::Forms::NumericUpDown^ numericUpDown3;
		private: System::Windows::Forms::Label^ label6;
		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
		private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::Label^ label8;

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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->numericUpDown3 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->Location = System::Drawing::Point(7, 186);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(270, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Register an apartment:";
			// 
			// textBox1
			// 
			this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox1->Location = System::Drawing::Point(12, 312);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(313, 78);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(9, 293);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(61, 16);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Address:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(9, 239);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(32, 16);
			this->label3->TabIndex = 4;
			this->label3->Text = L"City:";
			// 
			// textBox2
			// 
			this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->textBox2->Location = System::Drawing::Point(12, 258);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(313, 22);
			this->textBox2->TabIndex = 3;
			// 
			// label4
			// 
			this->label4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(345, 348);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(108, 16);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Available rooms:";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown1->Location = System::Drawing::Point(349, 367);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(377, 22);
			this->numericUpDown1->TabIndex = 7;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label5
			// 
			this->label5->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(345, 237);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(92, 16);
			this->label5->TabIndex = 9;
			this->label5->Text = L"Capacity (m3):";
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown2->DecimalPlaces = 2;
			this->numericUpDown2->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->numericUpDown2->Location = System::Drawing::Point(349, 257);
			this->numericUpDown2->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 999999, 0, 0, 0 });
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 250, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(378, 22);
			this->numericUpDown2->TabIndex = 10;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 250, 0, 0, 0 });
			// 
			// numericUpDown3
			// 
			this->numericUpDown3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->numericUpDown3->DecimalPlaces = 2;
			this->numericUpDown3->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->numericUpDown3->Location = System::Drawing::Point(349, 312);
			this->numericUpDown3->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->numericUpDown3->Name = L"numericUpDown3";
			this->numericUpDown3->Size = System::Drawing::Size(378, 22);
			this->numericUpDown3->TabIndex = 12;
			// 
			// label6
			// 
			this->label6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(345, 293);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(41, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Price:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = System::Windows::Forms::AnchorStyles::Top;
			this->pictureBox1->ImageLocation = L"Airbnb_Logo.png";
			this->pictureBox1->Location = System::Drawing::Point(17, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(335, 143);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 13;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(611, 500);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 38);
			this->button1->TabIndex = 14;
			this->button1->Text = L"Register";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ApartmentForm::button1_Click);
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(13, 428);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(313, 22);
			this->dateTimePicker1->TabIndex = 15;
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(350, 428);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(377, 22);
			this->dateTimePicker2->TabIndex = 16;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(10, 409);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(67, 16);
			this->label7->TabIndex = 17;
			this->label7->Text = L"Start date:";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(347, 409);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(64, 16);
			this->label8->TabIndex = 18;
			this->label8->Text = L"End date:";
			// 
			// ApartmentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 550);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->numericUpDown3);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Name = L"ApartmentForm";
			this->Text = L"ApartmentForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
};
}
