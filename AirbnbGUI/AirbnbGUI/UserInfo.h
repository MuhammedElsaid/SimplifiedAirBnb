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

			bookedApartmentsListview->View = View::Details;
			bookedApartmentsListview->FullRowSelect = true;
			bookedApartmentsListview->MultiSelect = false;
			bookedApartmentsListview->Columns->Add("City", 90);
			bookedApartmentsListview->Columns->Add("Address", 150);
			bookedApartmentsListview->Columns->Add("Price", 90);
			bookedApartmentsListview->Columns->Add("Number of rooms", 90);

			auto traveler = (Traveler*)Global::Users->currentSignedInUser;

			for (auto bookedApartment : traveler->getBookedApartments()) {

				auto arr = gcnew array<String^>(4);
				auto foundApartment = bookedApartment->getApartment();

				arr[0] = gcnew String(foundApartment->city.c_str());
				arr[1] = gcnew String(foundApartment->address.c_str());
				arr[2] = gcnew String(std::to_string((int)foundApartment->price).c_str());
				arr[3] = gcnew String(std::to_string(foundApartment->availableRooms).c_str());
				bookedApartmentsListview->Items->Add(gcnew ListViewItem(arr));
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
		private: System::Windows::Forms::Label^ label1;
		private: System::Windows::Forms::ListView^ bookedApartmentsListview;
		protected:

		private: System::Windows::Forms::PictureBox^ pictureBox1;
		private: System::Windows::Forms::Button^ button1;

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
			this->bookedApartmentsListview = (gcnew System::Windows::Forms::ListView());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->Location = System::Drawing::Point(12, 156);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(233, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Booked apartments";
			// 
			// bookedApartmentsListview
			// 
			this->bookedApartmentsListview->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->bookedApartmentsListview->HideSelection = false;
			this->bookedApartmentsListview->Location = System::Drawing::Point(12, 188);
			this->bookedApartmentsListview->Name = L"bookedApartmentsListview";
			this->bookedApartmentsListview->Size = System::Drawing::Size(693, 363);
			this->bookedApartmentsListview->TabIndex = 1;
			this->bookedApartmentsListview->UseCompatibleStateImageBehavior = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->ImageLocation = L"Airbnb_Logo.png";
			this->pictureBox1->Location = System::Drawing::Point(12, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(280, 137);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(585, 557);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(120, 35);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Delete bookinig";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &UserInfo::button1_Click);
			// 
			// UserInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(717, 601);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->bookedApartmentsListview);
			this->Controls->Add(this->label1);
			this->Name = L"UserInfo";
			this->Text = L"UserInfo";
			this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &UserInfo::UserInfo_FormClosed);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

			auto traveler = (Traveler*)Global::Users->currentSignedInUser;
			int counter = 0;
			for (auto bookedApartment : traveler->getBookedApartments()) {

				if (counter == bookedApartmentsListview->SelectedIndices[0]) {
					Global::BookedApartments->getValues()->remove(bookedApartment);
					Global::BookedApartments->Save();
					bookedApartmentsListview->Items->RemoveAt(counter);
					traveler->bookedApartmentIds.remove(bookedApartment->ID);
					Global::Users->Save();
					return;
				}

				counter++;
			}
		}
	private: System::Void UserInfo_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {

		Application::OpenForms[0]->Show();
	}
};
}
