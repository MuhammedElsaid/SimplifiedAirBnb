#pragma once
#include "DataSets.h"
#include "User.h"
#include "Admin.h"

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

			for (auto user : Global::Users->loadValues()) {

				userDataSource->Add(gcnew UserDataCell(user));
			}

			userDataGrid->DataSource = userDataSource;
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
		private: System::Windows::Forms::TabPage^ tabPage4;
		private: System::Windows::Forms::TabPage^ tabPage1;
		private: System::Windows::Forms::DataGridView^ userDataGrid;

		private: System::Windows::Forms::TabPage^ tabPage2;
		private: System::Windows::Forms::DataGridView^ dataGridView2;
		private: System::Windows::Forms::TabPage^ tabPage3;
		private: System::Windows::Forms::DataGridView^ dataGridView3;
		private: System::Windows::Forms::Button^ button1;
		private: System::Windows::Forms::Button^ button3;

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
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userDataGrid))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
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
			this->button3->Location = System::Drawing::Point(6, 567);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(126, 33);
			this->button3->TabIndex = 2;
			this->button3->Text = L"Delete";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &AdminPanel::button3_Click);
			// 
			// userDataGrid
			// 
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
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Location = System::Drawing::Point(4, 25);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(793, 603);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Apartments";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Location = System::Drawing::Point(0, 0);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(793, 639);
			this->dataGridView2->TabIndex = 0;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridView3);
			this->tabPage3->Location = System::Drawing::Point(4, 25);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(793, 603);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Booked Apartments";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Location = System::Drawing::Point(0, 0);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->RowHeadersWidth = 51;
			this->dataGridView3->RowTemplate->Height = 24;
			this->dataGridView3->Size = System::Drawing::Size(793, 639);
			this->dataGridView3->TabIndex = 0;
			// 
			// button1
			// 
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
			this->Text = L"AdminPanel";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userDataGrid))->EndInit();
			this->tabPage2->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
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

		Global::Users->Save();
	}
};
}
