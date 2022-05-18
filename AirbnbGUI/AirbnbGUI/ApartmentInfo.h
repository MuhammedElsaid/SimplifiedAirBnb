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
			this->Icon = gcnew System::Drawing::Icon("Airbnb_Icon.ico");

			//
			//TODO: Add the constructor code here
			//

			this->DialogResult = System::Windows::Forms::DialogResult::Abort;
		}

		ApartmentInfo(String^ startDate, String^ endDate, Apartment* apartmentInfo) {
			InitializeComponent();

			this->DialogResult = System::Windows::Forms::DialogResult::Abort;

			startDateBox->Text = startDate;
			endDateBox->Text = endDate;

			cityBox->Text = gcnew String(apartmentInfo->city.c_str());
			addressBox->Text = gcnew String(apartmentInfo->address.c_str());
			priceBox->Text = gcnew String(std::to_string(apartmentInfo->price).c_str());
			capacityBox->Text = gcnew String(std::to_string(apartmentInfo->capacity).c_str());
			availableRoomsBox->Text = gcnew String(std::to_string(apartmentInfo->availableRooms).c_str());
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
		private: System::Windows::Forms::Button^ bookButton;





		private: System::Windows::Forms::Label^ label6;
		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::TextBox^ cityBox;

		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::TextBox^ addressBox;
		private: System::Windows::Forms::TextBox^ capacityBox;
		private: System::Windows::Forms::TextBox^ priceBox;
		private: System::Windows::Forms::TextBox^ availableRoomsBox;




		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::Label^ label8;
		private: System::Windows::Forms::TextBox^ startDateBox;
		private: System::Windows::Forms::TextBox^ endDateBox;


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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->bookButton = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cityBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->addressBox = (gcnew System::Windows::Forms::TextBox());
			this->capacityBox = (gcnew System::Windows::Forms::TextBox());
			this->priceBox = (gcnew System::Windows::Forms::TextBox());
			this->availableRoomsBox = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->startDateBox = (gcnew System::Windows::Forms::TextBox());
			this->endDateBox = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->ImageLocation = L"Airbnb_Logo.png";
			this->pictureBox1->Location = System::Drawing::Point(15, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(348, 150);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 14;
			this->pictureBox1->TabStop = false;
			// 
			// bookButton
			// 
			this->bookButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->bookButton->Location = System::Drawing::Point(581, 422);
			this->bookButton->Name = L"bookButton";
			this->bookButton->Size = System::Drawing::Size(126, 37);
			this->bookButton->TabIndex = 15;
			this->bookButton->Text = L"Book";
			this->bookButton->UseVisualStyleBackColor = true;
			this->bookButton->Click += gcnew System::EventHandler(this, &ApartmentInfo::bookButton_Click);
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
			// cityBox
			// 
			this->cityBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->cityBox->Location = System::Drawing::Point(9, 259);
			this->cityBox->Name = L"cityBox";
			this->cityBox->ReadOnly = true;
			this->cityBox->Size = System::Drawing::Size(319, 22);
			this->cityBox->TabIndex = 21;
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
			// addressBox
			// 
			this->addressBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->addressBox->Location = System::Drawing::Point(9, 313);
			this->addressBox->Multiline = true;
			this->addressBox->Name = L"addressBox";
			this->addressBox->ReadOnly = true;
			this->addressBox->Size = System::Drawing::Size(319, 78);
			this->addressBox->TabIndex = 19;
			// 
			// capacityBox
			// 
			this->capacityBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->capacityBox->Location = System::Drawing::Point(351, 259);
			this->capacityBox->Name = L"capacityBox";
			this->capacityBox->ReadOnly = true;
			this->capacityBox->Size = System::Drawing::Size(112, 22);
			this->capacityBox->TabIndex = 33;
			// 
			// priceBox
			// 
			this->priceBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->priceBox->Location = System::Drawing::Point(477, 257);
			this->priceBox->Name = L"priceBox";
			this->priceBox->ReadOnly = true;
			this->priceBox->Size = System::Drawing::Size(105, 22);
			this->priceBox->TabIndex = 34;
			// 
			// availableRoomsBox
			// 
			this->availableRoomsBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->availableRoomsBox->Location = System::Drawing::Point(595, 256);
			this->availableRoomsBox->Name = L"availableRoomsBox";
			this->availableRoomsBox->ReadOnly = true;
			this->availableRoomsBox->Size = System::Drawing::Size(112, 22);
			this->availableRoomsBox->TabIndex = 35;
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(349, 294);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(67, 16);
			this->label7->TabIndex = 31;
			this->label7->Text = L"Start date:";
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(348, 345);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(64, 16);
			this->label8->TabIndex = 32;
			this->label8->Text = L"End date:";
			// 
			// startDateBox
			// 
			this->startDateBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->startDateBox->Location = System::Drawing::Point(351, 313);
			this->startDateBox->Name = L"startDateBox";
			this->startDateBox->ReadOnly = true;
			this->startDateBox->Size = System::Drawing::Size(356, 22);
			this->startDateBox->TabIndex = 36;
			// 
			// endDateBox
			// 
			this->endDateBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->endDateBox->Location = System::Drawing::Point(351, 364);
			this->endDateBox->Name = L"endDateBox";
			this->endDateBox->ReadOnly = true;
			this->endDateBox->Size = System::Drawing::Size(356, 22);
			this->endDateBox->TabIndex = 37;
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
			this->Controls->Add(this->endDateBox);
			this->Controls->Add(this->startDateBox);
			this->Controls->Add(this->availableRoomsBox);
			this->Controls->Add(this->priceBox);
			this->Controls->Add(this->capacityBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->cityBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->addressBox);
			this->Controls->Add(this->bookButton);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"ApartmentInfo";
			this->Text = L"Book Info";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void bookButton_Click(System::Object^ sender, System::EventArgs^ e) {

		this->DialogResult = System::Windows::Forms::DialogResult::OK;
		this->Close();
	}
};
}
