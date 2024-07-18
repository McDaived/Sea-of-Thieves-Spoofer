#include "Sea of Thieves Spoofer.h"


using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    Spoofer::Spoof form;
    Application::Run(% form);
}