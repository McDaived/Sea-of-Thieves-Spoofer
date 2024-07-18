namespace Spoofer {
    public ref class AboutForm : public System::Windows::Forms::Form
    {
    public:
        AboutForm(void)
        {
            InitializeComponent();
        }

    protected:
        ~AboutForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private: System::Windows::Forms::Label^ lblCopyright;
    private: System::Windows::Forms::Label^ lblDeveloper;
    private: System::Windows::Forms::LinkLabel^ linkWebsite;
    private: System::Windows::Forms::Button^ btnExit;




    private: System::ComponentModel::IContainer^ components;

    private:
        void InitializeComponent(void)
        {
            this->lblCopyright = (gcnew System::Windows::Forms::Label());
            this->lblDeveloper = (gcnew System::Windows::Forms::Label());
            this->linkWebsite = (gcnew System::Windows::Forms::LinkLabel());
            this->btnExit = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // lblCopyright
            // 
            this->lblCopyright->AutoSize = true;
            this->lblCopyright->ForeColor = System::Drawing::SystemColors::ButtonFace;
            this->lblCopyright->Location = System::Drawing::Point(92, 63);
            this->lblCopyright->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblCopyright->Name = L"lblCopyright";
            this->lblCopyright->Size = System::Drawing::Size(300, 18);
            this->lblCopyright->TabIndex = 0;
            this->lblCopyright->Text = L"Copyright © 2024 Sea of Thieves Spoofer";
            this->lblCopyright->Click += gcnew System::EventHandler(this, &AboutForm::lblCopyright_Click);
            // 
            // lblDeveloper
            // 
            this->lblDeveloper->AutoSize = true;
            this->lblDeveloper->ForeColor = System::Drawing::SystemColors::ButtonFace;
            this->lblDeveloper->Location = System::Drawing::Point(158, 120);
            this->lblDeveloper->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->lblDeveloper->Name = L"lblDeveloper";
            this->lblDeveloper->Size = System::Drawing::Size(160, 18);
            this->lblDeveloper->TabIndex = 1;
            this->lblDeveloper->Text = L"Developed by Daived";
            // 
            // linkWebsite
            // 
            this->linkWebsite->ActiveLinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->linkWebsite->AutoSize = true;
            this->linkWebsite->LinkColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
                static_cast<System::Int32>(static_cast<System::Byte>(0)));
            this->linkWebsite->Location = System::Drawing::Point(181, 177);
            this->linkWebsite->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
            this->linkWebsite->Name = L"linkWebsite";
            this->linkWebsite->Size = System::Drawing::Size(110, 18);
            this->linkWebsite->TabIndex = 2;
            this->linkWebsite->TabStop = true;
            this->linkWebsite->Text = L"Visit main post";
            this->linkWebsite->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &AboutForm::linkWebsite_LinkClicked);
            // 
            // btnExit
            // 
            this->btnExit->BackColor = System::Drawing::Color::Green;
            this->btnExit->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
            this->btnExit->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
            this->btnExit->Location = System::Drawing::Point(161, 223);
            this->btnExit->Margin = System::Windows::Forms::Padding(4);
            this->btnExit->Name = L"btnExit";
            this->btnExit->Size = System::Drawing::Size(150, 42);
            this->btnExit->TabIndex = 4;
            this->btnExit->Text = L"Exit";
            this->btnExit->UseVisualStyleBackColor = false;
            this->btnExit->Click += gcnew System::EventHandler(this, &AboutForm::btnExit_Click);
            // 
            // AboutForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(9, 18);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
            this->ClientSize = System::Drawing::Size(483, 326);
            this->Controls->Add(this->btnExit);
            this->Controls->Add(this->linkWebsite);
            this->Controls->Add(this->lblDeveloper);
            this->Controls->Add(this->lblCopyright);
            this->Font = (gcnew System::Drawing::Font(L"Arial", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Margin = System::Windows::Forms::Padding(4);
            this->Name = L"AboutForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"About";
            this->ResumeLayout(false);
            this->PerformLayout();

        }

        void linkWebsite_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
        {
            System::Diagnostics::Process::Start("https://www.unknowncheats.me/forum/sea-of-thieves/649766-sea-thieves-spoofer.html#post4146053");
        }

        void btnExit_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->Close();
        }
    private: System::Void lblCopyright_Click(System::Object^ sender, System::EventArgs^ e) {
    }
};
}
