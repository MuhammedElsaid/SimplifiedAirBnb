#include "SigninForm.h"
#include "DataSets.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace AirbnbGUI;

[STAThreadAttribute]
void main(array<String^>^ args) {

	Global::LoadSets();

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SigninForm form; 
	Application::Run(%form); 
}