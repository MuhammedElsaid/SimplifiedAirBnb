#pragma once

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
		protected:
		private: System::Windows::Forms::ListView^ listView1;
		private: System::Windows::Forms::PictureBox^ pictureBox1;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(UserInfo::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->listView1 = (gcnew System::Windows::Forms::ListView());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15));
			this->label1->Location = System::Drawing::Point(12, 168);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(85, 29);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Hello, ";
			// 
			// listView1
			// 
			this->listView1->HideSelection = false;
			this->listView1->Location = System::Drawing::Point(12, 226);
			this->listView1->Name = L"listView1";
			this->listView1->Size = System::Drawing::Size(693, 363);
			this->listView1->TabIndex = 1;
			this->listView1->UseCompatibleStateImageBehavior = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->ImageLocation = L"Airbnb_Logo.png";
			this->pictureBox1->Location = System::Drawing::Point(12, 4);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(280, 137);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			// 
			// UserInfo
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(717, 601);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->listView1);
			this->Controls->Add(this->label1);
			this->Name = L"UserInfo";
			this->Text = L"UserInfo";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	};
}
