#pragma once
#include "DataSets.h"
#include "User.h"
#include "Admin.h"
#include "Apartment.h"

namespace AirbnbGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for AdminPanel
	/// </summary>
	public ref class AdminPanel : public System::Windows::Forms::Form
	{
	public:
		AdminPanel(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//

			auto userDataSource = gcnew System::ComponentModel::BindingList<UserDataCell^>();

			for (auto user : Global::Users->loadValues())
				userDataSource->Add(gcnew UserDataCell(user));

			auto apartmentDataSource = gcnew System::ComponentModel::BindingList<ApartmentDataCell^>();

			for (auto apartment : *Global::Apartments->getValues())
				apartmentDataSource->Add(gcnew ApartmentDataCell(apartment));

			userDataGrid->DataSource = userDataSource;
			apartmentDataGridView->DataSource = apartmentDataSource;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~AdminPanel()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::Windows::Forms::TabControl^ tabControl1;
		protected:

		protected:

		protected:
		private: System::Windows::Forms::TabPage^ tabPage4;
		private: System::Windows::Forms::TabPage^ tabPage1;
		private: System::Windows::Forms::DataGridView^ userDataGrid;

		private: System::Windows::Forms::TabPage^ tabPage2;
		private: System::Windows::Forms::DataGridView^ apartmentDataGridView;

		private: System::Windows::Forms::TabPage^ tabPage3;
		private: System::Windows::Forms::DataGridView^ bookedApartmentDataGridView;

		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::Button^ button3;
		private: System::Windows::Forms::Button^ button2;
		private: System::Windows::Forms::Button^ button4;

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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->userDataGrid = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->apartmentDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->bookedApartmentDataGridView = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userDataGrid))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->apartmentDataGridView))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bookedApartmentDataGridView))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Location = System::Drawing::Point(12, 12);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(801, 632);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage4
			// 
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(793, 603);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Analysis";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->button3);
			this->tabPage1->Controls->Add(this->userDataGrid);
			this->tabPage1->Location = System::Drawing::Point(4, 25);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(793, 603);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Users";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button3->Location = System::Drawing::Point(6, 567);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(126, 35);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Delete";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AdminPanel::button3_Click);
			// 
			// userDataGrid
			// 
			this->userDataGrid->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->userDataGrid->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->userDataGrid->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->userDataGrid->Location = System::Drawing::Point(0, 0);
			this->userDataGrid->Name = L"userDataGrid";
			this->userDataGrid->RowHeadersWidth = 51;
			this->userDataGrid->RowTemplate->Height = 24;
			this->userDataGrid->Size = System::Drawing::Size(793, 561);
			this->userDataGrid->TabIndex = 0;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->apartmentDataGridView);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(793, 603);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Apartments";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button2->Location = System::Drawing::Point(6, 565);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(126, 36);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Delete";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &AdminPanel::button2_Click);
			// 
			// apartmentDataGridView
			// 
			this->apartmentDataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->apartmentDataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->apartmentDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->apartmentDataGridView->Location = System::Drawing::Point(0, 0);
			this->apartmentDataGridView->Name = L"apartmentDataGridView";
			this->apartmentDataGridView->RowHeadersWidth = 51;
			this->apartmentDataGridView->RowTemplate->Height = 24;
			this->apartmentDataGridView->Size = System::Drawing::Size(793, 562);
			this->apartmentDataGridView->TabIndex = 0;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button4);
			this->tabPage3->Controls->Add(this->bookedApartmentDataGridView);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(793, 603);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Booked Apartments";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->button4->Location = System::Drawing::Point(3, 567);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(126, 33);
			this->button4->TabIndex = 3;
			this->button4->Text = L"Delete";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &AdminPanel::button4_Click);
			// 
			// bookedApartmentDataGridView
			// 
			this->bookedApartmentDataGridView->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->bookedApartmentDataGridView->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->bookedApartmentDataGridView->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->bookedApartmentDataGridView->Location = System::Drawing::Point(0, 0);
			this->bookedApartmentDataGridView->Name = L"bookedApartmentDataGridView";
			this->bookedApartmentDataGridView->RowHeadersWidth = 51;
			this->bookedApartmentDataGridView->RowTemplate->Height = 24;
			this->bookedApartmentDataGridView->Size = System::Drawing::Size(793, 563);
			this->bookedApartmentDataGridView->TabIndex = 0;
			// 
			// button1
			// 
			this->button1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->button1->Location = System::Drawing::Point(700, 646);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(113, 34);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Save";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &AdminPanel::button1_Click);
			// 
			// AdminPanel
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(825, 692);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->tabControl1);
			this->Name = L"AdminPanel";
			this->Text = L"Admin Dashboard";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userDataGrid))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->apartmentDataGridView))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bookedApartmentDataGridView))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {

			auto selectedRows = userDataGrid->SelectedRows;
			auto enumerator = selectedRows->GetEnumerator();

			while (enumerator->MoveNext()) {

				DataGridViewRow^ row = (DataGridViewRow^)enumerator->Current;

				auto userDataCell = (UserDataCell^)row->DataBoundItem;
				userDataCell->Remove();

				userDataGrid->Rows->Remove(row);
			}
		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

		switch (tabControl1->SelectedIndex) {
		case 1:
			Global::Users->Save();
			break;

		case 2:
			Global::Apartments->Save();
			break;

		case 3:
			Global::BookedApartments->Save();
			break;
		}
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

		auto selectedRows = apartmentDataGridView->SelectedRows;
		auto enumerator = selectedRows->GetEnumerator();

		while (enumerator->MoveNext()) {

			DataGridViewRow^ row = (DataGridViewRow^)enumerator->Current;

			auto apartmentDataCell = (ApartmentDataCell^)row->DataBoundItem;
			apartmentDataCell->Remove();

			apartmentDataGridView->Rows->Remove(row);
		}
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

		auto selectedRows = bookedApartmentDataGridView->SelectedRows;
		auto enumerator = selectedRows->GetEnumerator();

		while (enumerator->MoveNext()) {

			DataGridViewRow^ row = (DataGridViewRow^)enumerator->Current;

			auto bookedApartmentDataCell = (BookedApartmentDataCell^)row->DataBoundItem;
			bookedApartmentDataCell->Remove();

			bookedApartmentDataGridView->Rows->Remove(row);
		}
	}
};
}
