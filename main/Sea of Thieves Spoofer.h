#pragma once
#include <SOT_Spoofer.h>
#include <thread>
#include <msclr\marshal_cppstd.h>
#include "AboutForm.h"

namespace Spoofer {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;
    using namespace System::Threading;
    using namespace System::Threading::Tasks;
    using namespace System::Diagnostics;

    public ref class Spoof : public System::Windows::Forms::Form {
    public:
        Spoof(void) {
            InitializeComponent();
        }

    protected:
        ~Spoof() {
            if (components) {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ step1;
        System::Windows::Forms::Button^ step2;
        System::Windows::Forms::Button^ step3;
        System::Windows::Forms::Button^ step4; // Existing button for Step 4
        System::Windows::Forms::Button^ step5; // New button for Step 5
        System::Windows::Forms::Button^ btnAbout;
        System::Windows::Forms::Button^ btnExit;
        System::ComponentModel::Container^ components;
    private: System::Windows::Forms::Label^ lblCopyright;

           CancellationTokenSource^ cts;

           void InitializeComponent(void) {
               this->step1 = (gcnew System::Windows::Forms::Button());
               this->step2 = (gcnew System::Windows::Forms::Button());
               this->step3 = (gcnew System::Windows::Forms::Button());
               this->step4 = (gcnew System::Windows::Forms::Button());
               this->step5 = (gcnew System::Windows::Forms::Button());
               this->btnAbout = (gcnew System::Windows::Forms::Button());
               this->btnExit = (gcnew System::Windows::Forms::Button());
               this->lblCopyright = (gcnew System::Windows::Forms::Label());
               this->SuspendLayout();
               // 
               // step1
               // 
               this->step1->Location = System::Drawing::Point(189, 68);
               this->step1->Margin = System::Windows::Forms::Padding(4);
               this->step1->Name = L"step1";
               this->step1->Size = System::Drawing::Size(143, 39);
               this->step1->TabIndex = 0;
               this->step1->Text = L"Step 1";
               this->step1->UseVisualStyleBackColor = true;
               this->step1->Click += gcnew System::EventHandler(this, &Spoof::step1_Click);
               // 
               // step2
               // 
               this->step2->Location = System::Drawing::Point(189, 120);
               this->step2->Margin = System::Windows::Forms::Padding(4);
               this->step2->Name = L"step2";
               this->step2->Size = System::Drawing::Size(143, 39);
               this->step2->TabIndex = 1;
               this->step2->Text = L"Step 2";
               this->step2->UseVisualStyleBackColor = true;
               this->step2->Click += gcnew System::EventHandler(this, &Spoof::step2_Click);
               // 
               // step3
               // 
               this->step3->Location = System::Drawing::Point(189, 171);
               this->step3->Margin = System::Windows::Forms::Padding(4);
               this->step3->Name = L"step3";
               this->step3->Size = System::Drawing::Size(143, 39);
               this->step3->TabIndex = 2;
               this->step3->Text = L"Step 3";
               this->step3->UseVisualStyleBackColor = true;
               this->step3->Click += gcnew System::EventHandler(this, &Spoof::step3_Click);
               // 
               // step4
               // 
               this->step4->Location = System::Drawing::Point(189, 223);
               this->step4->Margin = System::Windows::Forms::Padding(4);
               this->step4->Name = L"step4";
               this->step4->Size = System::Drawing::Size(143, 39);
               this->step4->TabIndex = 3;
               this->step4->Text = L"Step 4";
               this->step4->UseVisualStyleBackColor = true;
               this->step4->Click += gcnew System::EventHandler(this, &Spoof::step4_Click);
               // 
               // step5
               // 
               this->step5->Location = System::Drawing::Point(189, 275);
               this->step5->Margin = System::Windows::Forms::Padding(4);
               this->step5->Name = L"step5";
               this->step5->Size = System::Drawing::Size(143, 39);
               this->step5->TabIndex = 4;
               this->step5->Text = L"Step 5";
               this->step5->UseVisualStyleBackColor = true;
               this->step5->Click += gcnew System::EventHandler(this, &Spoof::step5_Click);
               // 
               // btnAbout
               // 
               this->btnAbout->Location = System::Drawing::Point(423, 65);
               this->btnAbout->Margin = System::Windows::Forms::Padding(4);
               this->btnAbout->Name = L"btnAbout";
               this->btnAbout->Size = System::Drawing::Size(87, 31);
               this->btnAbout->TabIndex = 9;
               this->btnAbout->Text = L"About";
               this->btnAbout->UseVisualStyleBackColor = true;
               this->btnAbout->Click += gcnew System::EventHandler(this, &Spoof::btnAbout_Click);
               // 
               // btnExit
               // 
               this->btnExit->BackColor = System::Drawing::Color::Green;
               this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
               this->btnExit->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
               this->btnExit->Location = System::Drawing::Point(423, 15);
               this->btnExit->Margin = System::Windows::Forms::Padding(6);
               this->btnExit->Name = L"btnExit";
               this->btnExit->Size = System::Drawing::Size(87, 31);
               this->btnExit->TabIndex = 10;
               this->btnExit->Text = L"Exit";
               this->btnExit->UseVisualStyleBackColor = false;
               this->btnExit->Click += gcnew System::EventHandler(this, &Spoof::btnExit_Click);
               // 
               // lblCopyright
               // 
               this->lblCopyright->AutoSize = true;
               this->lblCopyright->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                   static_cast<System::Int32>(static_cast<System::Byte>(0)));
               this->lblCopyright->Location = System::Drawing::Point(171, 22);
               this->lblCopyright->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
               this->lblCopyright->Name = L"lblCopyright";
               this->lblCopyright->Size = System::Drawing::Size(176, 18);
               this->lblCopyright->TabIndex = 11;
               this->lblCopyright->Text = L"Sea of Thieves Spoofer";
               // 
               // Spoof
               // 
               this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
               this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
               this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
               this->ClientSize = System::Drawing::Size(525, 341);
               this->Controls->Add(this->lblCopyright);
               this->Controls->Add(this->btnExit);
               this->Controls->Add(this->btnAbout);
               this->Controls->Add(this->step5);
               this->Controls->Add(this->step4);
               this->Controls->Add(this->step3);
               this->Controls->Add(this->step2);
               this->Controls->Add(this->step1);
               this->Cursor = System::Windows::Forms::Cursors::Default;
               this->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                   static_cast<System::Byte>(0)));
               this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
               this->Margin = System::Windows::Forms::Padding(4);
               this->Name = L"Spoof";
               this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
               this->Text = L"Sea of Thieves Spoofer";
               this->ResumeLayout(false);
               this->PerformLayout();

           }

           void step1_Click(System::Object^ sender, System::EventArgs^ e) {
               cts = gcnew CancellationTokenSource();
               CancellationToken ct = cts->Token;
               Task::Run(gcnew Action(this, &Spoof::ExecuteCleaning), ct);

               System::Threading::Timer^ timer = gcnew System::Threading::Timer(gcnew TimerCallback(this, &Spoof::StopCleaning), nullptr, 10000, Timeout::Infinite);
           }

           void ExecuteCleaning() {
               while (!cts->Token.IsCancellationRequested) {
                   cleaner::execute_cleaning();
               }
           }

           void StopCleaning(Object^ state) {
               if (cts != nullptr) {
                   cts->Cancel();
                   Console::Clear();
                   Console::WriteLine("Step 1 Done");
               }
           }

           void step2_Click(System::Object^ sender, System::EventArgs^ e) {
               try {
                   String^ tempBatchFile = System::IO::Path::GetTempFileName();
                   tempBatchFile = System::IO::Path::ChangeExtension(tempBatchFile, ".bat");

                   array<String^>^ batchContent = {
                       "@echo off",
                       "cmdkey.exe /list > \"%TEMP%\\List.txt\"",
                       "findstr.exe Target \"%TEMP%\\List.txt\" > \"%TEMP%\\tokensonly.txt\"",
                       "FOR /F \"tokens=1,2 delims= \" %%G IN (%TEMP%\\tokensonly.txt) DO cmdkey.exe /delete:%%H",
                       "del \"%TEMP%\\List.txt\" /s /f /q",
                       "del \"%TEMP%\\tokensonly.txt\" /s /f /q",
                       "echo Step 2 Done",
                       "echo.",
                       "echo.",
                       "echo.",
                       "echo."
                   };

                   System::IO::File::WriteAllLines(tempBatchFile, batchContent);

                   ProcessStartInfo^ psi = gcnew ProcessStartInfo();
                   psi->FileName = "cmd.exe";
                   psi->Arguments = "/c \"" + tempBatchFile + "\"";
                   psi->CreateNoWindow = false;
                   psi->UseShellExecute = false;
                   Process^ proc = Process::Start(psi);
                   proc->WaitForExit();

                   System::IO::File::Delete(tempBatchFile);
               }
               catch (Exception^ ex) {
                   MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
               }
           }

           void step3_Click(System::Object^ sender, System::EventArgs^ e) {
               try {
                   String^ tempBatchFile = System::IO::Path::GetTempFileName();
                   tempBatchFile = System::IO::Path::ChangeExtension(tempBatchFile, ".bat");

                   array<String^>^ batchContent = {
                       "@echo off",
                       "reg delete \"HKEY_CURRENT_USER\\Software\\Microsoft\\IdentityCRL\" /f",
                       "reg delete \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\OneSettings\\xbox\" /f",
                       "reg delete \"HKEY_USERS\\.DEFAULT\\Software\\Microsoft\\IdentityCRL\" /f",
                       "reg delete \"HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\XboxLive\" /f",
                       "cmdkey.exe /list > \"%TEMP%\\List.txt\"",
                       "findstr.exe Target \"%TEMP%\\List.txt\" > \"%TEMP%\\tokensonly.txt\"",
                       "FOR /F \"tokens=1,2 delims= \" %%G IN (%TEMP%\\tokensonly.txt) DO cmdkey.exe /delete:%%H",
                       "del \"%TEMP%\\List.txt\" /s /f /q",
                       "del \"%TEMP%\\tokensonly.txt\" /s /f /q",
                       "echo Step 3 Done",
                       "echo.",
                       "echo.",
                       "echo.",
                       "echo."
                   };

                   System::IO::File::WriteAllLines(tempBatchFile, batchContent);

                   ProcessStartInfo^ psi = gcnew ProcessStartInfo();
                   psi->FileName = "cmd.exe";
                   psi->Arguments = "/c \"" + tempBatchFile + "\"";
                   psi->CreateNoWindow = false;
                   psi->UseShellExecute = false;
                   Process^ proc = Process::Start(psi);
                   proc->WaitForExit();

                   System::IO::File::Delete(tempBatchFile);
               }
               catch (Exception^ ex) {
                   MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
               }
           }

           void step4_Click(System::Object^ sender, System::EventArgs^ e) {
               try {
                   String^ tempScriptFile = System::IO::Path::GetTempFileName();
                   tempScriptFile = System::IO::Path::ChangeExtension(tempScriptFile, ".ps1");

                   array<String^>^ scriptContent = {
                       "$inputXML = @\"",
                       "<Window x:Name=\"DeleteCreds_Frm\" x:Class=\"DeleteCreds_PS.MainWindow\"",
                       "        xmlns=\"http://schemas.microsoft.com/winfx/2006/xaml/presentation\"",
                       "        xmlns:x=\"http://schemas.microsoft.com/winfx/2006/xaml\"",
                       "        xmlns:d=\"http://schemas.microsoft.com/expression/blend/2008\"",
                       "        xmlns:mc=\"http://schemas.openxmlformats.org/markup-compatibility/2006\"",
                       "        xmlns:local=\"clr-namespace:DeleteCreds_PS\"",
                       "        mc:Ignorable=\"d\"",
                       "        Title=\"Delete Credintials\" Height=\"591.008\" Width=\"627.112\" IsEnabled=\"True\">",
                       "    <Grid>",
                       "        <ListBox x:Name=\"Credintial_lst_box\" HorizontalAlignment=\"Left\" Height=\"497\" Margin=\"10,10,0,0\" VerticalAlignment=\"Top\" Width=\"599\" SelectionMode=\"Multiple\"/>",
                       "        <Button x:Name=\"Delete_btn\" Content=\"Delete Selected\" HorizontalAlignment=\"Left\" Margin=\"507,512,0,0\" VerticalAlignment=\"Top\" Width=\"102\" Height=\"38\"/>",
                       "        <Button x:Name=\"Refresh_btn\" Content=\"Refresh List\" HorizontalAlignment=\"Left\" Margin=\"409,512,0,0\" VerticalAlignment=\"Top\" Width=\"93\" Height=\"38\"/>",
                       "        <Button x:Name=\"SelectAll_btn\" Content=\"Select All\" HorizontalAlignment=\"Left\" Margin=\"10,512,0,0\" VerticalAlignment=\"Top\" Width=\"96\" Height=\"38\"/>",
                       "    </Grid>",
                       "</Window>",
                       "\"@",
                       "$inputXML = $inputXML -replace 'mc:Ignorable=\"d\"', '' -replace \"x:N\", 'N' -replace '^<Win.*', '<Window'",
                       "[void][System.Reflection.Assembly]::LoadWithPartialName('presentationframework')",
                       "[xml]$XAML = $inputXML",
                       "#Read XAML",
                       "$reader = (New-Object System.Xml.XmlNodeReader $xaml)",
                       "try { $CreateGUI = [Windows.Markup.XamlReader]::Load( $reader ) }",
                       "catch { Write-Host \"Unable to load Windows.Markup.XamlReader. Double-check syntax and ensure .net is installed.\" }",
                       "$xaml.SelectNodes(\"//*[@Name]\") | % { Set-Variable -Name \"WPF$($_.Name)\" -Value $CreateGUI.FindName($_.Name) }",
                       "Function Get-FormVariables {",
                       "    if ($global:ReadmeDisplay -ne $true) { Write-host \"How to use :\" -ForegroundColor Yellow; $global:ReadmeDisplay = $true }",
                       "    write-host \"Go to 'Select ALL' and then 'Delete Selected'\" -ForegroundColor Cyan",
                       "    get-variable WPF*",
                       "}",
                       "Get-FormVariables",
                       "$WPFCredintial_lst_box.Add_Loaded({",
                       "        Refresh-List",
                       "    })",
                       "$WPFSelectAll_btn.Add_Click({",
                       "        $WPFCredintial_lst_box.SelectAll()",
                       "    })",
                       "$WPFDelete_btn.Add_Click({",
                       "        foreach ($item in $WPFCredintial_lst_box.SelectedItems) {",
                       "            cmdkey /del:$item",
                       "        }",
                       "        Refresh-List",
                       "        CheckIfFinished",
                       "    })",
                       "function Refresh-List {",
                       "    $WPFCredintial_lst_box.Items.Clear()",
                       "    cmdkey /list | ForEach-Object { if ($_ -like \"*WindowsLive:*\" -or $_ -like \"*MicrosoftAccount:user*\" -or $_ -like \"*Xbl*\" -or $_ -like \"*SSO_POP*\") { $WPFCredintial_lst_box.Items.Add($($_ -replace \" \", \"\" -replace \"Target:\", \"\")) } }",
                       "}",
                       "function CheckIfFinished {",
                       "    $msgBoxInput = [System.Windows.MessageBox]::Show('Would you like to delete the reg keys as well?', 'Delete Keys?', 'YesNoCancel', 'Error')",
                       "    switch ($msgBoxInput) {",
                       "        'Yes' {",
                       "            $ScriptBlock = {",
                       "                Remove-Item HKCU:\\Software\\Microsoft\\IdentityCRL -Force -Recurse",
                       "                Remove-Item HKLM:\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\OneSettings\\xbox -Force -Recurse",
                       "                New-PSDrive -PSProvider Registry -Name HKU -Root HKEY_USERS",
                       "                Remove-Item HKU:\\.DEFAULT\\Software\\Microsoft\\IdentityCRL -Force -Recurse",
                       "                Remove-Item HKLM:\\SOFTWARE\\Microsoft\\XboxLive -Force -Recurse",
                       "                $msgBoxInput2 = [System.Windows.MessageBox]::Show('Restart PC Now?', 'Reboot?', 'YesNoCancel', 'Error')",
                       "                switch ($msgBoxInput2) {",
                       "                    'Yes' {",
                       "                        Restart-Computer -Force",
                       "                    }",
                       "                    'No' {",
                       "                        return",
                       "                    }",
                       "                    'Cancel' {",
                       "                        return",
                       "                    }",
                       "                }",
                       "                Start-Process powershell -ArgumentList \"-command & {$ScriptBlock}\" -Verb runas",
                       "            }",
                       "        }",
                       "        'No' {",
                       "            ## Do something",
                       "            return",
                       "        }",
                       "        'Cancel' {",
                       "            ## Do something",
                       "            return",
                       "        }",
                       "    }",
                       "}",
                       "################",
                       "# Display Form #",
                       "################",
                       "$CreateGUI.ShowDialog() | Out-Null"
                   };

                   System::IO::File::WriteAllLines(tempScriptFile, scriptContent);

                   ProcessStartInfo^ psi = gcnew ProcessStartInfo();
                   psi->FileName = "powershell.exe";
                   psi->Arguments = "-NoProfile -ExecutionPolicy Bypass -File \"" + tempScriptFile + "\"";
                   psi->CreateNoWindow = false;
                   psi->UseShellExecute = false;
                   Process^ proc = Process::Start(psi);
                   proc->WaitForExit();

                   System::IO::File::Delete(tempScriptFile);
               }
               catch (Exception^ ex) {
                   MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
               }
           }

           void step5_Click(System::Object^ sender, System::EventArgs^ e) {
               try {
                   String^ tempBatchFile = System::IO::Path::GetTempFileName();
                   tempBatchFile = System::IO::Path::ChangeExtension(tempBatchFile, ".bat");

                   array<String^>^ batchContent = {
                       "@echo off",
                       "echo. > C:\\Windows\\System32\\drivers\\etc\\hosts",
                       "echo Step 5 Done",
                       "timeout /t 20 /nobreak",
                       "shutdown /r /f /t 0"

                   };

                   System::IO::File::WriteAllLines(tempBatchFile, batchContent);

                   ProcessStartInfo^ psi = gcnew ProcessStartInfo();
                   psi->FileName = "cmd.exe";
                   psi->Arguments = "/c \"" + tempBatchFile + "\"";
                   psi->CreateNoWindow = false;
                   psi->UseShellExecute = false;
                   Process^ proc = Process::Start(psi);
                   proc->WaitForExit();

                   System::IO::File::Delete(tempBatchFile);
               }
               catch (Exception^ ex) {
                   MessageBox::Show(ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
               }
           }

           void btnAbout_Click(System::Object^ sender, System::EventArgs^ e) {
               AboutForm^ aboutForm = gcnew AboutForm();
               aboutForm->ShowDialog();
           }

           void btnExit_Click(System::Object^ sender, System::EventArgs^ e) {
               Application::Exit();
           }
    };
}
