#pragma once
#include "DataSets.h"

namespace AirbnbGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for UserInfo
	/// </summary>
	public ref class UserInfo : public System::Windows::Forms::Form
	{
	public:
		UserInfo(void)
		{
			InitializeComponent();
			this->Icon = gcnew System::Drawing::Icon("Airbnb_Icon.ico");

			listview->View = View::Details;
			listview->FullRowSelect = true;
			listview->MultiSelect = false;
			listview->Columns->Add("City", 90);
			listview->Columns->Add("Address", 150);
			listview->Columns->Add("Price", 90);
			listview->Columns->Add("Number of rooms", 90);

			auto user = Global::Users->currentSignedInUser;


			if (user->userType == User::Traveler) {

				listview->Columns->Add("Start date", 100);
				listview->Columns->Add("Number of days", 100);

				auto traveler = (Traveler*)user;

				double totalCost = 0;

				fullNameLabel->Text = "Booked Apartments";

				for (auto bookedApartment : traveler->getBookedApartments()) {

					auto arr = gcnew array<String^>(6);
					auto foundApartment = bookedApartment->getApartment();

					totalCost += bookedApartment->numberOfDays * foundApartment->price;

					arr[0] = gcnew String(foundApartment->city.c_str());
					arr[1] = gcnew String(foundApartment->address.c_str());
					arr[2] = gcnew String(std::to_string((int)foundApartment->price * bookedApartment->numberOfDays).c_str());
					arr[3] = gcnew String(std::to_string(foundApartment->availableRooms).c_str());
					arr[4] = gcnew String(bookedApartment->startDate.c_str());
					arr[5] = gcnew String(std::to_string(bookedApartment->numberOfDays).c_str());
					listview->Items->Add(gcnew ListViewItem(arr));
				}

				fullNameLabel->Text += " Total Price: " + totalCost;
			}
			else {

				auto host = (Host*)user;

				fullNameLabel->Text = "Owned Apartments";


				for (auto foundApartment : host->getOwnedApartments()) {

					auto arr = gcnew array<String^>(4);

					arr[0] = gcnew String(foundApartment->city.c_str());
					arr[1] = gcnew String(foundApartment->address.c_str());
					arr[2] = gcnew String(std::to_string((int)foundApartment->price).c_str());
					arr[3] = gcnew String(std::to_string(foundApartment->availableRooms).c_str());
					listview->Items->Add(gcnew ListViewItem(arr));
				}

			}

			
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~UserInfo()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::Label^ fullNameLabel;
		private: System::Windows::Forms::ListView^ listview;
		protected:


		protected:

		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::Button^ deleteButton;


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
			this->fullNameLabel = (gcnew System::Windows::Forms::Label());
			this->listview = (gcnew System::Windows::Forms::ListView());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->deleteButton = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// fullNameLabel
			// 
			this->fullNameLabel->AutoSize = true;
			this->fullNameLabel->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->fullNameLabel->Location = System::Drawing::Point(12, 131);
			this->fullNameLabel->Name = L"fullNameLabel";
			this->fullNameLabel->Size = System::Drawing::Size(134, 29);
			this->fullNameLabel->TabIndex = 0;
			this->fullNameLabel->Text = L"Welcome, ";
			// 
			// listview
			// 
			this->listview->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->listview->HideSelection = false;
			this->listview->Location = System::Drawing::Point(12, 188);
			this->listview->Name = L"listview";
			this->listview->Size = System::Drawing::Size(693, 363);
			this->listview->TabIndex = 1;
			this->listview->UseCompatibleStateImageBehavior = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->ImageLocation = L"Airbnb_Logo.png";
			this->pictureBox1->Location = System::Drawing::Point(12, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(280, 124);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// deleteButton
			// 
			this->deleteButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->deleteButton->Location = System::Drawing::Point(585, 557);
			this->deleteButton->Name = L"deleteButton";
			this->deleteButton->Size = System::Drawing::Size(120, 35);
			this->deleteButton->TabIndex = 3;
			this->deleteButton->Text = L"Delete";
			this->deleteButton->UseVisualStyleBackColor = true;
			this->deleteButton->Click += gcnew System::EventHandler(this, &UserInfo::button1_Click);
			// 
			// UserInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(717, 601);
			this->Controls->Add(this->deleteButton);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->listview);
			this->Controls->Add(this->fullNameLabel);
			this->Name = L"UserInfo";
			this->Text = L"UserInfo";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &UserInfo::UserInfo_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			auto user = Global::Users->currentSignedInUser;
			int counter = 0;

			if (user->userType == User::Traveler) {
				auto traveler = (Traveler*)user;
				for (auto bookedApartment : traveler->getBookedApartments()) {

					if (counter == listview->SelectedIndices[0]) {
						Global::BookedApartments->getValues()->remove(bookedApartment);
						Global::BookedApartments->Save();
						listview->Items->RemoveAt(counter);
						traveler->bookedApartmentIds.remove(bookedApartment->ID);
						Global::Users->Save();
						return;
					}

					counter++;
				}
			}
			else {

				auto host = (Host*)user;
				for (auto apartment : host->getOwnedApartments()) {

					if (counter == listview->SelectedIndices[0]) {
						Global::Apartments->getValues()->remove(apartment);
						Global::Apartments->Save();
						listview->Items->RemoveAt(counter);
						host->ownedApartmentsIds.remove(apartment->ID);
						Global::Users->Save();
						return;
					}

					counter++;
				}
			}
		}
	private: System::Void UserInfo_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {

		Application::OpenForms[0]->Show();
	}
};
}
