#include "SigninForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace AirbnbGUI;

[STAThreadAttribute]
void main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	SigninForm form;
	Application::Run(%form); 
}