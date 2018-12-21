#include "World2D.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThread]

void main()
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	laboratorna8::World2D form(true, "");
	Application::Run(%form);
}
