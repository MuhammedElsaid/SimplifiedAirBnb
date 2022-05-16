#pragma once

namespace AirbnbGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for ApartmentSearch
	/// </summary>
	public ref class ApartmentSearch : public System::Windows::Forms::Form
	{
	public:
		ApartmentSearch(void)
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
		~ApartmentSearch()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::TextBox^ cityTextBox;


		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::Label^ label2;

		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::NumericUpDown^ numericUpDown1;
		private: System::Windows::Forms::Label^ label8;
		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::DateTimePicker^ dateTimePicker2;
		private: System::Windows::Forms::DateTimePicker^ dateTimePicker1;
		private: System::Windows::Forms::NumericUpDown^ numericUpDown2;
		private: System::Windows::Forms::ListView^ listView1;
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::LinkLabel^ linkLabel1;
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->cityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->numericUpDown1 = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dateTimePicker2 = (gcnew System::Windows::Forms::DateTimePicker());
			this->dateTimePicker1 = (gcnew System::Windows::Forms::DateTimePicker());
			this->numericUpDown2 = (gcnew System::Windows::Forms::NumericUpDown());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->ImageLocation = L"Airbnb_Logo.png";
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(335, 114);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// cityTextBox
			// 
			this->cityTextBox->Location = System::Drawing::Point(23, 179);
			this->cityTextBox->Name = L"cityTextBox";
			this->cityTextBox->Size = System::Drawing::Size(401, 22);
			this->cityTextBox->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(20, 160);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(32, 16);
			this->label1->TabIndex = 2;
			this->label1->Text = L"City:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(460, 161);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Price:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(608, 161);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Number of rooms:";
			// 
			// numericUpDown1
			// 
			this->numericUpDown1->Location = System::Drawing::Point(611, 180);
			this->numericUpDown1->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown1->Name = L"numericUpDown1";
			this->numericUpDown1->Size = System::Drawing::Size(127, 22);
			this->numericUpDown1->TabIndex = 6;
			this->numericUpDown1->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(358, 227);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(64, 16);
			this->label8->TabIndex = 22;
			this->label8->Text = L"End date:";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(21, 227);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(67, 16);
			this->label7->TabIndex = 21;
			this->label7->Text = L"Start date:";
			// 
			// dateTimePicker2
			// 
			this->dateTimePicker2->Location = System::Drawing::Point(361, 246);
			this->dateTimePicker2->Name = L"dateTimePicker2";
			this->dateTimePicker2->Size = System::Drawing::Size(377, 22);
			this->dateTimePicker2->TabIndex = 20;
			// 
			// dateTimePicker1
			// 
			this->dateTimePicker1->Location = System::Drawing::Point(24, 246);
			this->dateTimePicker1->Name = L"dateTimePicker1";
			this->dateTimePicker1->Size = System::Drawing::Size(313, 22);
			this->dateTimePicker1->TabIndex = 19;
			// 
			// numericUpDown2
			// 
			this->numericUpDown2->DecimalPlaces = 2;
			this->numericUpDown2->Location = System::Drawing::Point(463, 180);
			this->numericUpDown2->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numericUpDown2->Name = L"numericUpDown2";
			this->numericUpDown2->Size = System::Drawing::Size(115, 22);
			this->numericUpDown2->TabIndex = 23;
			this->numericUpDown2->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 20, 0, 0, 0 });
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(12, 340);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(747, 262);
			this->listView1->TabIndex = 24;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(622, 285);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(116, 31);
			this->button1->TabIndex = 25;
			this->button1->Text = L"Search";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ApartmentSearch::button1_Click);
			// 
			// linkLabel1
			// 
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(619, 12);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(145, 16);
			this->linkLabel1->TabIndex = 26;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"My booked apartments";
			// 
			// ApartmentSearch
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(771, 616);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->numericUpDown2);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->dateTimePicker2);
			this->Controls->Add(this->dateTimePicker1);
			this->Controls->Add(this->numericUpDown1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cityTextBox);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"ApartmentSearch";
			this->Text = L"ApartmentSearch";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numericUpDown2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		}
};
}
