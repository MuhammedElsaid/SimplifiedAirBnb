#pragma once
#include <msclr\marshal_cppstd.h>
#include "UserInfo.h"
#include "ApartmentInfo.h"

namespace AirbnbGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace msclr::interop;

	std::list<Apartment*> currentResult;

	/// <summary>
	/// Summary for ApartmentSearch
	/// </summary>
	public ref class ApartmentSearch : public System::Windows::Forms::Form
	{
	public:
		ApartmentSearch(void)
		{
			InitializeComponent();

			this->Text = "Welcome " + gcnew String(Global::Users->currentSignedInUser->fullName.c_str());
			searchListView->View = View::Details;
			searchListView->FullRowSelect = true;
			searchListView->MultiSelect = false;
			searchListView->Columns->Add("City", 90);
			searchListView->Columns->Add("Address", 150);
			searchListView->Columns->Add("Price", 90);
			searchListView->Columns->Add("Number of rooms", 90);
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
		private: System::Windows::Forms::NumericUpDown^ numberOfRoomsBox;

		private: System::Windows::Forms::Label^ label8;
		private: System::Windows::Forms::Label^ label7;
		private: System::Windows::Forms::DateTimePicker^ endDateBox;

		private: System::Windows::Forms::DateTimePicker^ startDateBox;

		private: System::Windows::Forms::NumericUpDown^ priceBox;

		private: System::Windows::Forms::ListView^ searchListView;
		private: System::Windows::Forms::Button^ searchButton;


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
			this->numberOfRoomsBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->endDateBox = (gcnew System::Windows::Forms::DateTimePicker());
			this->startDateBox = (gcnew System::Windows::Forms::DateTimePicker());
			this->priceBox = (gcnew System::Windows::Forms::NumericUpDown());
			this->searchListView = (gcnew System::Windows::Forms::ListView());
			this->searchButton = (gcnew System::Windows::Forms::Button());
			this->linkLabel1 = (gcnew System::Windows::Forms::LinkLabel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numberOfRoomsBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->priceBox))->BeginInit();
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
			this->cityTextBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
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
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(460, 161);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Price:";
			// 
			// label3
			// 
			this->label3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(608, 161);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(113, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Number of rooms:";
			// 
			// numberOfRoomsBox
			// 
			this->numberOfRoomsBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->numberOfRoomsBox->Location = System::Drawing::Point(611, 180);
			this->numberOfRoomsBox->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			this->numberOfRoomsBox->Name = L"numberOfRoomsBox";
			this->numberOfRoomsBox->Size = System::Drawing::Size(127, 22);
			this->numberOfRoomsBox->TabIndex = 3;
			this->numberOfRoomsBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 1, 0, 0, 0 });
			// 
			// label8
			// 
			this->label8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(358, 227);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(64, 16);
			this->label8->TabIndex = 22;
			this->label8->Text = L"End date:";
			// 
			// label7
			// 
			this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(21, 227);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(67, 16);
			this->label7->TabIndex = 21;
			this->label7->Text = L"Start date:";
			// 
			// endDateBox
			// 
			this->endDateBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->endDateBox->Location = System::Drawing::Point(361, 246);
			this->endDateBox->Name = L"endDateBox";
			this->endDateBox->Size = System::Drawing::Size(377, 22);
			this->endDateBox->TabIndex = 5;
			// 
			// startDateBox
			// 
			this->startDateBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->startDateBox->Location = System::Drawing::Point(24, 246);
			this->startDateBox->Name = L"startDateBox";
			this->startDateBox->Size = System::Drawing::Size(313, 22);
			this->startDateBox->TabIndex = 4;
			// 
			// priceBox
			// 
			this->priceBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->priceBox->DecimalPlaces = 2;
			this->priceBox->Increment = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			this->priceBox->Location = System::Drawing::Point(463, 180);
			this->priceBox->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4) { 99999999, 0, 0, 0 });
			this->priceBox->Name = L"priceBox";
			this->priceBox->Size = System::Drawing::Size(115, 22);
			this->priceBox->TabIndex = 2;
			this->priceBox->Value = System::Decimal(gcnew cli::array< System::Int32 >(4) { 100, 0, 0, 0 });
			// 
			// searchListView
			// 
			this->searchListView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->searchListView->HideSelection = false;
			this->searchListView->Location = System::Drawing::Point(12, 340);
			this->searchListView->Name = L"searchListView";
			this->searchListView->Size = System::Drawing::Size(747, 262);
			this->searchListView->TabIndex = 7;
			this->searchListView->UseCompatibleStateImageBehavior = false;
			this->searchListView->MouseDoubleClick += gcnew System::Windows::Forms::MouseEventHandler(this, &ApartmentSearch::searchListView_MouseDoubleClick);
			// 
			// searchButton
			// 
			this->searchButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->searchButton->Location = System::Drawing::Point(622, 285);
			this->searchButton->Name = L"searchButton";
			this->searchButton->Size = System::Drawing::Size(116, 31);
			this->searchButton->TabIndex = 6;
			this->searchButton->Text = L"Search";
			this->searchButton->UseVisualStyleBackColor = true;
			this->searchButton->Click += gcnew System::EventHandler(this, &ApartmentSearch::button1_Click);
			// 
			// linkLabel1
			// 
			this->linkLabel1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->linkLabel1->AutoSize = true;
			this->linkLabel1->Location = System::Drawing::Point(619, 12);
			this->linkLabel1->Name = L"linkLabel1";
			this->linkLabel1->Size = System::Drawing::Size(145, 16);
			this->linkLabel1->TabIndex = 26;
			this->linkLabel1->TabStop = true;
			this->linkLabel1->Text = L"My booked apartments";
			this->linkLabel1->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &ApartmentSearch::linkLabel1_LinkClicked);
			// 
			// ApartmentSearch
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(771, 616);
			this->Controls->Add(this->linkLabel1);
			this->Controls->Add(this->searchButton);
			this->Controls->Add(this->searchListView);
			this->Controls->Add(this->priceBox);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->endDateBox);
			this->Controls->Add(this->startDateBox);
			this->Controls->Add(this->numberOfRoomsBox);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->cityTextBox);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"ApartmentSearch";
			this->Text = L"ApartmentSearch";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->numberOfRoomsBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->priceBox))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			auto cityStr = marshal_as<std::string>(cityTextBox->Text);
			auto priceStr = marshal_as<std::string>(priceBox->Text);
			auto numberOfRoomsStr = marshal_as<std::string>(numberOfRoomsBox->Text);

			auto startDate = marshal_as<std::string>(startDateBox->Value.ToString());
			auto endDate = marshal_as<std::string>(endDateBox->Value.ToString());

			auto timeSpan = endDateBox->Value - startDateBox->Value;
			
			currentResult.clear();
			searchListView->Items->Clear();

			for (Apartment* apartment : *Global::Apartments->getValues()) {

				if (apartment->city == cityStr &&
					apartment->availableRooms >= std::stoi(numberOfRoomsStr) &&
					apartment->price <= std::stod(priceStr)) {

					currentResult.push_back(apartment);
				}
			}

			auto tempResult = currentResult;

			for (auto foundApartment : currentResult) {
			
				for (BookedApartment* bookedApartment : *Global::BookedApartments->getValues()) {
			
					if (foundApartment->ID == bookedApartment->apartmentID) {
			
						auto dateParse = DateTime::ParseExact(gcnew String(bookedApartment->startDate.c_str()), "dd/MM/yyyy", nullptr);
						auto endDateParse = dateParse.AddDays(bookedApartment->numberOfDays);
			
						auto startDate = DateTime::ParseExact(startDateBox->Value.ToString("dd/MM/yyyy"), "dd/MM/yyyy", nullptr);
						auto endDate = DateTime::ParseExact(endDateBox->Value.ToString("dd/MM/yyyy"), "dd/MM/yyyy", nullptr);
			
						if (dateParse <= startDate && startDate <= endDateParse
							|| dateParse <= endDate && endDate <= endDateParse) {
			
							tempResult.remove(foundApartment);
							continue;
						}
					}
				}
			}

			currentResult = tempResult;

			for (auto foundApartment : currentResult) {
				auto arr = gcnew array<String^>(4);

				arr[0] = gcnew String(foundApartment->city.c_str());
				arr[1] = gcnew String(foundApartment->address.c_str());
				arr[2] = gcnew String(std::to_string((int)foundApartment->price).c_str());
				arr[3] = gcnew String(std::to_string(foundApartment->availableRooms).c_str());
				searchListView->Items->Add(gcnew ListViewItem(arr));
			}
			

		}
	private: System::Void searchListView_MouseDoubleClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {

		int counter = 0;
		for (auto apartment : currentResult) {

			if (counter == searchListView->SelectedIndices[0]) {
				
				auto numberOfDays = (DateTime::ParseExact(endDateBox->Value.ToString("dd/MM/yyyy"), "dd/MM/yyyy", nullptr) - DateTime::ParseExact(startDateBox->Value.ToString("dd/MM/yyyy"), "dd/MM/yyyy", nullptr)).Days;
				
				ApartmentInfo^ apartmentInfo = gcnew ApartmentInfo(startDateBox->Value.ToString("dd/MM/yyyy"), endDateBox->Value.ToString("dd/MM/yyyy"), apartment);
				auto result = apartmentInfo->ShowDialog();

				if (result != System::Windows::Forms::DialogResult::OK)
					return;
				
				auto bookedApartment = new BookedApartment(apartment->ID, marshal_as<std::string>(startDateBox->Value.ToString("dd/MM/yyyy")), numberOfDays);
				
				Global::BookedApartments->Push(bookedApartment);
				Global::BookedApartments->Save();
				
				currentResult.clear();
				searchListView->Items->Clear();

				auto traveler = (Traveler*)Global::Users->currentSignedInUser;

				traveler->bookedApartmentIds.push_back(bookedApartment->ID);

				Global::Users->Save();
				return;
			}

			counter++;
		}
	}
	private: System::Void linkLabel1_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e) {

		this->Hide();

		auto userInfo = gcnew UserInfo();
		userInfo->Show();
	}
};
}
