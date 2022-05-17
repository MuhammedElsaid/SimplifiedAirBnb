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
	using namespace System::Windows::Forms::DataVisualization::Charting;

	/// <summary>
	/// Summary for AdminPanel
	/// </summary>
	public ref class AdminPanel : public System::Windows::Forms::Form
	{
	public:

		public: void updateCharts() {

			int travelersCount = 0;
			int hostCount = 0;

			auto agesDic = gcnew System::Collections::Generic::Dictionary<Int32, Int32>();


			for (User* user : *Global::Users->getValues()) {

				if ((int)user->userType == User::Traveler)
					travelersCount++;
				else if ((int)user->userType == User::Host)
					hostCount++;

				if (!agesDic->ContainsKey(user->age))
					agesDic->Add(user->age, 1);
				else
					agesDic[user->age] += 1;
			}

			userTypeChart->Series[0]->Points->Clear();
			userTypeChart->Series[1]->Points->Clear();

			userTypeChart->Series[0]->Points->AddXY(0, travelersCount);
			userTypeChart->Series[1]->Points->AddXY(0, hostCount);

			ageChart->Series[0]->Points->Clear();
			ageChart->Series[0]->Points->DataBindXY(agesDic->Keys, agesDic->Values);

			int prices[] = { 500, 1000, 1500, 2000, 3000 };
			auto priceDic = gcnew System::Collections::Generic::Dictionary<Int32, Int32>();

			for (auto priceKey : prices)
				priceDic->Add(priceKey, 0);

			for (Apartment* apartment : *Global::Apartments->getValues()) {

				auto enumrator = priceDic->Keys->GetEnumerator();
				while (enumrator.MoveNext()) {
				}

				if (apartment->price > enumrator.Current) {

					if (!priceDic->ContainsKey(apartment->price))
						priceDic->Add(apartment->price, 1);
					else
						priceDic[apartment->price] += 1;
					continue;
				}

				for (auto priceKey : prices) {

					if (apartment->price <= priceKey) {
						priceDic[priceKey] += 1;
						break;	
					}
				}
			}

			apartmentPricesChart->Series[0]->Points->Clear();
			apartmentPricesChart->Series[0]->Points->DataBindXY(priceDic->Keys, priceDic->Values);

			totalUsersLabel->Text = "" + (travelersCount + hostCount);
			totalUsersLabel->Text = "" + (travelersCount + hostCount);

			totalApartmentsLabel->Text = "" + Global::Apartments->getValues()->size();
			bookedApartmentsLabel->Text = "" + Global::BookedApartments->getValues()->size();

			double moneySpent = 0;

			for (BookedApartment* bookedApartment : *Global::BookedApartments->getValues()) {
				moneySpent += bookedApartment->CalculateTotalPrice();
			}

			moneySpentLabel->Text = "" + moneySpent + " EGP";
		}
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

			auto bookedApartmentDataSource = gcnew System::ComponentModel::BindingList<BookedApartmentDataCell^>();

			for (auto bookedApartment : *Global::BookedApartments->getValues())
				bookedApartmentDataSource->Add(gcnew BookedApartmentDataCell(bookedApartment));

			userDataGrid->DataSource = userDataSource;
			apartmentDataGridView->DataSource = apartmentDataSource;
			bookedApartmentDataGridView->DataSource = bookedApartmentDataSource;


			try {
				updateCharts();
			
			}
			catch (System::Exception^ ex) {
			
				System::Windows::Forms::MessageBox::Show(ex->Message);
			
			}
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
		private: System::Windows::Forms::DataVisualization::Charting::Chart^ userTypeChart;
		private: System::Windows::Forms::DataVisualization::Charting::Chart^ ageChart;
		private: System::Windows::Forms::DataVisualization::Charting::Chart^ apartmentPricesChart;
		private: System::Windows::Forms::Label^ totalUsersLabel;
		private: System::Windows::Forms::Label^ totalApartmentsLabel;
		private: System::Windows::Forms::Label^ bookedApartmentsLabel;
		private: System::Windows::Forms::Label^ moneySpentLabel;
	private: System::Windows::Forms::Label^ label4;
		private: System::Windows::Forms::Label^ label3;
		private: System::Windows::Forms::Label^ label2;
		private: System::Windows::Forms::Label^ label1;





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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea7 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend7 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea8 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend8 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series10 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea9 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend9 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series11 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series12 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->moneySpentLabel = (gcnew System::Windows::Forms::Label());
			this->bookedApartmentsLabel = (gcnew System::Windows::Forms::Label());
			this->totalApartmentsLabel = (gcnew System::Windows::Forms::Label());
			this->totalUsersLabel = (gcnew System::Windows::Forms::Label());
			this->apartmentPricesChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->ageChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->userTypeChart = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
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
			this->tabPage4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->apartmentPricesChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ageChart))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userTypeChart))->BeginInit();
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
			this->tabControl1->SelectedIndexChanged += gcnew System::EventHandler(this, &AdminPanel::tabControl1_SelectedIndexChanged);
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->label4);
			this->tabPage4->Controls->Add(this->label3);
			this->tabPage4->Controls->Add(this->label2);
			this->tabPage4->Controls->Add(this->label1);
			this->tabPage4->Controls->Add(this->moneySpentLabel);
			this->tabPage4->Controls->Add(this->bookedApartmentsLabel);
			this->tabPage4->Controls->Add(this->totalApartmentsLabel);
			this->tabPage4->Controls->Add(this->totalUsersLabel);
			this->tabPage4->Controls->Add(this->apartmentPricesChart);
			this->tabPage4->Controls->Add(this->ageChart);
			this->tabPage4->Controls->Add(this->userTypeChart);
			this->tabPage4->Location = System::Drawing::Point(4, 25);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(793, 603);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Analysis";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(504, 450);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(127, 24);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Money spent:";
			// 
			// label3
			// 
			this->label3->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(504, 411);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(147, 24);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Bookings made:";
			// 
			// label2
			// 
			this->label2->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(504, 372);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(211, 24);
			this->label2->TabIndex = 8;
			this->label2->Text = L"Registered apartments:";
			// 
			// label1
			// 
			this->label1->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(504, 336);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(106, 24);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Total users:";
			// 
			// moneySpentLabel
			// 
			this->moneySpentLabel->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->moneySpentLabel->AutoSize = true;
			this->moneySpentLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->moneySpentLabel->Location = System::Drawing::Point(666, 450);
			this->moneySpentLabel->Name = L"moneySpentLabel";
			this->moneySpentLabel->Size = System::Drawing::Size(21, 24);
			this->moneySpentLabel->TabIndex = 6;
			this->moneySpentLabel->Text = L"0";
			// 
			// bookedApartmentsLabel
			// 
			this->bookedApartmentsLabel->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->bookedApartmentsLabel->AutoSize = true;
			this->bookedApartmentsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->bookedApartmentsLabel->Location = System::Drawing::Point(694, 411);
			this->bookedApartmentsLabel->Name = L"bookedApartmentsLabel";
			this->bookedApartmentsLabel->Size = System::Drawing::Size(21, 24);
			this->bookedApartmentsLabel->TabIndex = 5;
			this->bookedApartmentsLabel->Text = L"0";
			// 
			// totalApartmentsLabel
			// 
			this->totalApartmentsLabel->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->totalApartmentsLabel->AutoSize = true;
			this->totalApartmentsLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->totalApartmentsLabel->Location = System::Drawing::Point(744, 372);
			this->totalApartmentsLabel->Name = L"totalApartmentsLabel";
			this->totalApartmentsLabel->Size = System::Drawing::Size(21, 24);
			this->totalApartmentsLabel->TabIndex = 4;
			this->totalApartmentsLabel->Text = L"0";
			// 
			// totalUsersLabel
			// 
			this->totalUsersLabel->Anchor = System::Windows::Forms::AnchorStyles::Right;
			this->totalUsersLabel->AutoSize = true;
			this->totalUsersLabel->Font = (gcnew System::Drawing::Font(L"Microsoft YaHei UI", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->totalUsersLabel->Location = System::Drawing::Point(637, 336);
			this->totalUsersLabel->Name = L"totalUsersLabel";
			this->totalUsersLabel->Size = System::Drawing::Size(21, 24);
			this->totalUsersLabel->TabIndex = 3;
			this->totalUsersLabel->Text = L"0";
			// 
			// apartmentPricesChart
			// 
			this->apartmentPricesChart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea7->Name = L"ChartArea1";
			this->apartmentPricesChart->ChartAreas->Add(chartArea7);
			legend7->Name = L"Legend1";
			this->apartmentPricesChart->Legends->Add(legend7);
			this->apartmentPricesChart->Location = System::Drawing::Point(6, 295);
			this->apartmentPricesChart->Name = L"apartmentPricesChart";
			series9->ChartArea = L"ChartArea1";
			series9->LabelForeColor = System::Drawing::Color::Transparent;
			series9->Legend = L"Legend1";
			series9->Name = L"Price per night";
			series9->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::String;
			series9->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			this->apartmentPricesChart->Series->Add(series9);
			this->apartmentPricesChart->Size = System::Drawing::Size(492, 305);
			this->apartmentPricesChart->TabIndex = 2;
			// 
			// ageChart
			// 
			this->ageChart->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			chartArea8->Name = L"ChartArea1";
			this->ageChart->ChartAreas->Add(chartArea8);
			legend8->Name = L"Legend1";
			this->ageChart->Legends->Add(legend8);
			this->ageChart->Location = System::Drawing::Point(410, 6);
			this->ageChart->Name = L"ageChart";
			series10->ChartArea = L"ChartArea1";
			series10->LabelForeColor = System::Drawing::Color::Transparent;
			series10->Legend = L"Legend1";
			series10->Name = L"Age";
			series10->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::String;
			series10->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			this->ageChart->Series->Add(series10);
			this->ageChart->Size = System::Drawing::Size(380, 290);
			this->ageChart->TabIndex = 1;
			// 
			// userTypeChart
			// 
			chartArea9->Name = L"ChartArea1";
			this->userTypeChart->ChartAreas->Add(chartArea9);
			legend9->Name = L"Legend1";
			this->userTypeChart->Legends->Add(legend9);
			this->userTypeChart->Location = System::Drawing::Point(6, 6);
			this->userTypeChart->Name = L"userTypeChart";
			series11->ChartArea = L"ChartArea1";
			series11->LabelForeColor = System::Drawing::Color::Transparent;
			series11->Legend = L"Legend1";
			series11->Name = L"Traveler";
			series11->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::String;
			series11->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			series12->ChartArea = L"ChartArea1";
			series12->Legend = L"Legend1";
			series12->Name = L"Host";
			series12->XValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::String;
			series12->YValueType = System::Windows::Forms::DataVisualization::Charting::ChartValueType::Int32;
			this->userTypeChart->Series->Add(series11);
			this->userTypeChart->Series->Add(series12);
			this->userTypeChart->Size = System::Drawing::Size(398, 283);
			this->userTypeChart->TabIndex = 0;
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
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->apartmentPricesChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ageChart))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->userTypeChart))->EndInit();
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

	private: System::Void tabControl1_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {

		if (tabControl1->SelectedIndex == 0)
			updateCharts();
	}
};
}
