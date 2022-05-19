#pragma once
#include "Database.h"
#include "DataSets.h"
#include "Apartment.h"
#include <msclr\marshal_cppstd.h>
#include "UserInfo.h"

namespace AirbnbGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	/// <summary>
	/// Summary for ApartmentForm
	/// </summary>
	public ref class ApartmentForm : public System::Windows::Forms::Form
	{
	public:
		ApartmentForm(void)
		{
			InitializeComponent();
			this->Icon = gcnew System::Drawing::Icon("Airbnb_Icon.ico");
			//
			//TODO: Add the constructor code here
			//

			this->Text = "Welcome " + gcnew String(Global::Users->currentSignedInUser->fullName.c_str());
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
		private: System::Windows::Forms::TextBox^ addressBox;
		protected:

		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::TextBox^ cityTextBox;

		private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::NumericUpDown^ availableRoomsBox;

		private: System::Windows::Forms::Label^ label5;
		private: System::Windows::Forms::NumericUpDown^ capacityBox;
		private: System::Windows::Forms::NumericUpDown^ priceBox;


		private: System::Windows::Forms::Label^ label6;
		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::LinkLabel^ myApartmentsLinkLabel;





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
			this->addressBox = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->cityTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->availableRoomsBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->capacityBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->priceBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->myApartmentsLinkLabel = (gcnew System::Windows::Forms::LinkLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->availableRoomsBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->capacityBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->priceBox))->BeginInit();
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
			// addressBox
			// 
			this->addressBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->addressBox->Location = System::Drawing::Point(12, 312);
			this->addressBox->Multiline = true;
			this->addressBox->Name = L"addressBox";
			this->addressBox->Size = System::Drawing::Size(313, 78);
			this->addressBox->TabIndex = 4;
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
			// cityTextBox
			// 
			this->cityTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->cityTextBox->Location = System::Drawing::Point(12, 258);
			this->cityTextBox->Name = L"cityTextBox";
			this->cityTextBox->Size = System::Drawing::Size(313, 22);
			this->cityTextBox->TabIndex = 3;
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
			// availableRoomsBox
			// 
			this->availableRoomsBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->availableRoomsBox->Location = System::Drawing::Point(349, 367);
			this->availableRoomsBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->availableRoomsBox->Name = L"availableRoomsBox";
			this->availableRoomsBox->Size = System::Drawing::Size(377, 22);
			this->availableRoomsBox->TabIndex = 7;
			this->availableRoomsBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
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
			// capacityBox
			// 
			this->capacityBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->capacityBox->DecimalPlaces = 2;
			this->capacityBox->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->capacityBox->Location = System::Drawing::Point(349, 257);
			this->capacityBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 999999, 0, 0, 0 });
			this->capacityBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 250, 0, 0, 0 });
			this->capacityBox->Name = L"capacityBox";
			this->capacityBox->Size = System::Drawing::Size(378, 22);
			this->capacityBox->TabIndex = 5;
			this->capacityBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 250, 0, 0, 0 });
			// 
			// priceBox
			// 
			this->priceBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->priceBox->DecimalPlaces = 2;
			this->priceBox->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 5, 0, 0, 0 });
			this->priceBox->Location = System::Drawing::Point(349, 312);
			this->priceBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1000000, 0, 0, 0 });
			this->priceBox->Name = L"priceBox";
			this->priceBox->Size = System::Drawing::Size(378, 22);
			this->priceBox->TabIndex = 6;
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
			this->button1->Location = System::Drawing::Point(611, 451);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(125, 38);
			this->button1->TabIndex = 8;
			this->button1->Text = L"Register";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &ApartmentForm::button1_Click);
			// 
			// myApartmentsLinkLabel
			// 
			this->myApartmentsLinkLabel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->myApartmentsLinkLabel->AutoSize = true;
			this->myApartmentsLinkLabel->Location = System::Drawing::Point(632, 9);
			this->myApartmentsLinkLabel->Name = L"myApartmentsLinkLabel";
			this->myApartmentsLinkLabel->Size = System::Drawing::Size(95, 16);
			this->myApartmentsLinkLabel->TabIndex = 14;
			this->myApartmentsLinkLabel->TabStop = true;
			this->myApartmentsLinkLabel->Text = L"My apartments";
			this->myApartmentsLinkLabel->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &ApartmentForm::myApartmentsLinkLabel_LinkClicked);
			// 
			// ApartmentForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(748, 501);
			this->Controls->Add(this->myApartmentsLinkLabel);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->priceBox);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->capacityBox);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->availableRoomsBox);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->cityTextBox);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->addressBox);
			this->Controls->Add(this->label1);
			this->Name = L"ApartmentForm";
			this->Text = L"ApartmentForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->availableRoomsBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->capacityBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->priceBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			auto cityStr = marshal_as<std::string>(cityTextBox->Text);
			auto addressStr = marshal_as<std::string>(addressBox->Text);
			auto availableRooms = Decimal::ToInt32(availableRoomsBox->Value);
			auto capacity = Decimal::ToDouble(capacityBox->Value);
			auto price = Decimal::ToDouble(priceBox->Value);

			Apartment* apartment = new Apartment(addressStr, cityStr, availableRooms, capacity, price);

			Host* signedInHost = (Host*)Global::Users->currentSignedInUser;

			Global::Apartments->Push(apartment);
			Global::Apartments->Save();

			signedInHost->ownedApartmentsIds.push_back(apartment->ID);
			Global::Users->Save();

			cityTextBox->Clear();
			addressBox->Clear();
			availableRoomsBox->Value = 1;
			capacityBox->Value = 250;
			priceBox->Value = 0;

			cityTextBox->Focus();
		}
	private: System::Void myApartmentsLinkLabel_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {

		this->Hide();

		auto userInfo = gcnew UserInfo();

		userInfo->Show();
	}
};
}
