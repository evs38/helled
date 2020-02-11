/////////////////////////////////////////////////////////////////////////////
//
// HellEd
//
// FormAbout.h
//
// Copyright (c) 2002-2008 by Alexey Bezugly
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version. See license.txt for details.
/////////////////////////////////////////////////////////////////////////////
#pragma once
typedef System::Object object;
typedef System::String string;

namespace HellEd {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Summary for FormAbout
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FormAbout : public System::Windows::Forms::Form
	{
		public: System::Windows::Forms::Form^ frmMain;
		public: string^ HellEdDir;

		public: DevExpress::XtraEditors::SimpleButton^ btnOk;
		public: DevExpress::XtraEditors::PanelControl^  panelControl1;
		public: System::Windows::Forms::Label^  lblAuthorBegin;
		public: System::Windows::Forms::Label^  lblVersionBegin;
		public: System::Windows::Forms::Label^  lblFTNSMAPI;
		public: System::Windows::Forms::LinkLabel^  lnkFTNSMAPI;
		public: System::Windows::Forms::Label^  lblEMailSMAPI;
		public: System::Windows::Forms::LinkLabel^  lnkEMailSMAPI;
		public: System::Windows::Forms::Label^  lblURLSMAPI;
		public: System::Windows::Forms::LinkLabel^  lnkURLSMAPI;
		public: System::Windows::Forms::Label^  lblFTN;
		public: System::Windows::Forms::LinkLabel^  lnkFTN;
		public: System::Windows::Forms::Label^  lblEMail;
		public: System::Windows::Forms::LinkLabel^  lnkEMail;
		public: System::Windows::Forms::Label^  lblURL;
		public: System::Windows::Forms::LinkLabel^  lnkURL;
		public: System::Windows::Forms::LinkLabel^  lnkLicense;
		public: System::Windows::Forms::Label^  lblAuthor;
		public: System::Windows::Forms::Label^  LBLSMAPI;
		public: System::Windows::Forms::Label^  lblSMAPIBegin;
		public: System::Windows::Forms::Label^  lblCopyright;
		public: System::Windows::Forms::Label^  lblVersion;
		public: System::Windows::Forms::Label^  lblProgramName;
		public: DevExpress::XtraEditors::PictureEdit^  peIcon;
		public: DevExpress::XtraEditors::PictureEdit^  peHeader;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected: ~FormAbout()
		{
			if (components)
			{
				delete components;
			}
		}
		private: System::ComponentModel::IContainer^ components;

		protected: 
		/// <summary>
		/// Required designer variable.
		/// </summary>

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormAbout::typeid));
			this->btnOk = (gcnew DevExpress::XtraEditors::SimpleButton());
			this->peHeader = (gcnew DevExpress::XtraEditors::PictureEdit());
			this->panelControl1 = (gcnew DevExpress::XtraEditors::PanelControl());
			this->lblAuthorBegin = (gcnew System::Windows::Forms::Label());
			this->lblVersionBegin = (gcnew System::Windows::Forms::Label());
			this->lblFTNSMAPI = (gcnew System::Windows::Forms::Label());
			this->lnkFTNSMAPI = (gcnew System::Windows::Forms::LinkLabel());
			this->lblEMailSMAPI = (gcnew System::Windows::Forms::Label());
			this->lnkEMailSMAPI = (gcnew System::Windows::Forms::LinkLabel());
			this->lblURLSMAPI = (gcnew System::Windows::Forms::Label());
			this->lnkURLSMAPI = (gcnew System::Windows::Forms::LinkLabel());
			this->lblFTN = (gcnew System::Windows::Forms::Label());
			this->lnkFTN = (gcnew System::Windows::Forms::LinkLabel());
			this->lblEMail = (gcnew System::Windows::Forms::Label());
			this->lnkEMail = (gcnew System::Windows::Forms::LinkLabel());
			this->lblURL = (gcnew System::Windows::Forms::Label());
			this->lnkURL = (gcnew System::Windows::Forms::LinkLabel());
			this->lnkLicense = (gcnew System::Windows::Forms::LinkLabel());
			this->lblAuthor = (gcnew System::Windows::Forms::Label());
			this->LBLSMAPI = (gcnew System::Windows::Forms::Label());
			this->lblSMAPIBegin = (gcnew System::Windows::Forms::Label());
			this->lblCopyright = (gcnew System::Windows::Forms::Label());
			this->lblVersion = (gcnew System::Windows::Forms::Label());
			this->lblProgramName = (gcnew System::Windows::Forms::Label());
			this->peIcon = (gcnew DevExpress::XtraEditors::PictureEdit());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->peHeader->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->panelControl1))->BeginInit();
			this->panelControl1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->peIcon->Properties))->BeginInit();
			this->SuspendLayout();
			// 
			// btnOk
			// 
			this->btnOk->Location = System::Drawing::Point(331, 293);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(75, 23);
			this->btnOk->TabIndex = 43;
			this->btnOk->Text = L"ОК";
			this->btnOk->Click += gcnew System::EventHandler(this, &FormAbout::btnOk_Click);
			// 
			// peHeader
			// 
			this->peHeader->Dock = System::Windows::Forms::DockStyle::Top;
			this->peHeader->EditValue = (cli::safe_cast<System::Object^  >(resources->GetObject(L"peHeader.EditValue")));
			this->peHeader->Location = System::Drawing::Point(0, 0);
			this->peHeader->Name = L"peHeader";
			this->peHeader->Properties->AllowFocused = false;
			this->peHeader->Properties->BorderStyle = DevExpress::XtraEditors::Controls::BorderStyles::NoBorder;
			this->peHeader->Properties->ReadOnly = true;
			this->peHeader->Properties->ShowMenu = false;
			this->peHeader->Size = System::Drawing::Size(414, 67);
			this->peHeader->TabIndex = 46;
			// 
			// panelControl1
			// 
			this->panelControl1->Controls->Add(this->lblAuthorBegin);
			this->panelControl1->Controls->Add(this->lblVersionBegin);
			this->panelControl1->Controls->Add(this->lblFTNSMAPI);
			this->panelControl1->Controls->Add(this->lnkFTNSMAPI);
			this->panelControl1->Controls->Add(this->lblEMailSMAPI);
			this->panelControl1->Controls->Add(this->lnkEMailSMAPI);
			this->panelControl1->Controls->Add(this->lblURLSMAPI);
			this->panelControl1->Controls->Add(this->lnkURLSMAPI);
			this->panelControl1->Controls->Add(this->lblFTN);
			this->panelControl1->Controls->Add(this->lnkFTN);
			this->panelControl1->Controls->Add(this->lblEMail);
			this->panelControl1->Controls->Add(this->lnkEMail);
			this->panelControl1->Controls->Add(this->lblURL);
			this->panelControl1->Controls->Add(this->lnkURL);
			this->panelControl1->Controls->Add(this->lnkLicense);
			this->panelControl1->Controls->Add(this->lblAuthor);
			this->panelControl1->Controls->Add(this->LBLSMAPI);
			this->panelControl1->Controls->Add(this->lblSMAPIBegin);
			this->panelControl1->Controls->Add(this->lblCopyright);
			this->panelControl1->Controls->Add(this->lblVersion);
			this->panelControl1->Controls->Add(this->lblProgramName);
			this->panelControl1->Location = System::Drawing::Point(49, 73);
			this->panelControl1->Name = L"panelControl1";
			this->panelControl1->Size = System::Drawing::Size(276, 243);
			this->panelControl1->TabIndex = 47;
			// 
			// lblAuthorBegin
			// 
			this->lblAuthorBegin->BackColor = System::Drawing::Color::Transparent;
			this->lblAuthorBegin->Location = System::Drawing::Point(7, 61);
			this->lblAuthorBegin->Name = L"lblAuthorBegin";
			this->lblAuthorBegin->Size = System::Drawing::Size(48, 16);
			this->lblAuthorBegin->TabIndex = 66;
			this->lblAuthorBegin->Text = L"Автор:";
			// 
			// lblVersionBegin
			// 
			this->lblVersionBegin->BackColor = System::Drawing::Color::Transparent;
			this->lblVersionBegin->Location = System::Drawing::Point(7, 21);
			this->lblVersionBegin->Name = L"lblVersionBegin";
			this->lblVersionBegin->Size = System::Drawing::Size(48, 16);
			this->lblVersionBegin->TabIndex = 65;
			this->lblVersionBegin->Text = L"Версия";
			// 
			// lblFTNSMAPI
			// 
			this->lblFTNSMAPI->BackColor = System::Drawing::Color::Transparent;
			this->lblFTNSMAPI->Location = System::Drawing::Point(7, 221);
			this->lblFTNSMAPI->Name = L"lblFTNSMAPI";
			this->lblFTNSMAPI->Size = System::Drawing::Size(48, 16);
			this->lblFTNSMAPI->TabIndex = 64;
			this->lblFTNSMAPI->Text = L"FidoNet:";
			// 
			// lnkFTNSMAPI
			// 
			this->lnkFTNSMAPI->ActiveLinkColor = System::Drawing::Color::Blue;
			this->lnkFTNSMAPI->BackColor = System::Drawing::Color::Transparent;
			this->lnkFTNSMAPI->LinkColor = System::Drawing::Color::Blue;
			this->lnkFTNSMAPI->Location = System::Drawing::Point(55, 221);
			this->lnkFTNSMAPI->Name = L"lnkFTNSMAPI";
			this->lnkFTNSMAPI->Size = System::Drawing::Size(214, 16);
			this->lnkFTNSMAPI->TabIndex = 63;
			this->lnkFTNSMAPI->TabStop = true;
			this->lnkFTNSMAPI->Text = L"1:249/106";
			this->lnkFTNSMAPI->VisitedLinkColor = System::Drawing::Color::Blue;
			// 
			// lblEMailSMAPI
			// 
			this->lblEMailSMAPI->BackColor = System::Drawing::Color::Transparent;
			this->lblEMailSMAPI->Location = System::Drawing::Point(7, 205);
			this->lblEMailSMAPI->Name = L"lblEMailSMAPI";
			this->lblEMailSMAPI->Size = System::Drawing::Size(48, 16);
			this->lblEMailSMAPI->TabIndex = 62;
			this->lblEMailSMAPI->Text = L"E-Mail:";
			// 
			// lnkEMailSMAPI
			// 
			this->lnkEMailSMAPI->ActiveLinkColor = System::Drawing::Color::Blue;
			this->lnkEMailSMAPI->BackColor = System::Drawing::Color::Transparent;
			this->lnkEMailSMAPI->LinkColor = System::Drawing::Color::Blue;
			this->lnkEMailSMAPI->Location = System::Drawing::Point(55, 205);
			this->lnkEMailSMAPI->Name = L"lnkEMailSMAPI";
			this->lnkEMailSMAPI->Size = System::Drawing::Size(214, 16);
			this->lnkEMailSMAPI->TabIndex = 61;
			this->lnkEMailSMAPI->TabStop = true;
			this->lnkEMailSMAPI->Text = L"Scott.Dudley@f106.n249.z1.fidonet.org";
			this->lnkEMailSMAPI->VisitedLinkColor = System::Drawing::Color::Blue;
			this->lnkEMailSMAPI->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &FormAbout::lnkEMailSMAPI_LinkClicked);
			// 
			// lblURLSMAPI
			// 
			this->lblURLSMAPI->BackColor = System::Drawing::Color::Transparent;
			this->lblURLSMAPI->Location = System::Drawing::Point(7, 189);
			this->lblURLSMAPI->Name = L"lblURLSMAPI";
			this->lblURLSMAPI->Size = System::Drawing::Size(48, 16);
			this->lblURLSMAPI->TabIndex = 60;
			this->lblURLSMAPI->Text = L"URL:";
			// 
			// lnkURLSMAPI
			// 
			this->lnkURLSMAPI->ActiveLinkColor = System::Drawing::Color::Blue;
			this->lnkURLSMAPI->BackColor = System::Drawing::Color::Transparent;
			this->lnkURLSMAPI->LinkColor = System::Drawing::Color::Blue;
			this->lnkURLSMAPI->Location = System::Drawing::Point(55, 189);
			this->lnkURLSMAPI->Name = L"lnkURLSMAPI";
			this->lnkURLSMAPI->Size = System::Drawing::Size(214, 16);
			this->lnkURLSMAPI->TabIndex = 59;
			this->lnkURLSMAPI->TabStop = true;
			this->lnkURLSMAPI->Text = L"http://www.sourceforge.net/projects/husky";
			this->lnkURLSMAPI->VisitedLinkColor = System::Drawing::Color::Blue;
			this->lnkURLSMAPI->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &FormAbout::lnkURLSMAPI_LinkClicked);
			// 
			// lblFTN
			// 
			this->lblFTN->BackColor = System::Drawing::Color::Transparent;
			this->lblFTN->Location = System::Drawing::Point(7, 133);
			this->lblFTN->Name = L"lblFTN";
			this->lblFTN->Size = System::Drawing::Size(48, 16);
			this->lblFTN->TabIndex = 58;
			this->lblFTN->Text = L"FidoNet:";
			// 
			// lnkFTN
			// 
			this->lnkFTN->BackColor = System::Drawing::Color::Transparent;
			this->lnkFTN->LinkColor = System::Drawing::Color::Red;
			this->lnkFTN->Location = System::Drawing::Point(55, 133);
			this->lnkFTN->Name = L"lnkFTN";
			this->lnkFTN->Size = System::Drawing::Size(214, 16);
			this->lnkFTN->TabIndex = 57;
			this->lnkFTN->TabStop = true;
			this->lnkFTN->Text = L"2:5030/1520.9";
			this->lnkFTN->VisitedLinkColor = System::Drawing::Color::Red;
			// 
			// lblEMail
			// 
			this->lblEMail->BackColor = System::Drawing::Color::Transparent;
			this->lblEMail->Location = System::Drawing::Point(7, 117);
			this->lblEMail->Name = L"lblEMail";
			this->lblEMail->Size = System::Drawing::Size(48, 16);
			this->lblEMail->TabIndex = 56;
			this->lblEMail->Text = L"E-Mail:";
			// 
			// lnkEMail
			// 
			this->lnkEMail->BackColor = System::Drawing::Color::Transparent;
			this->lnkEMail->LinkColor = System::Drawing::Color::Red;
			this->lnkEMail->Location = System::Drawing::Point(55, 117);
			this->lnkEMail->Name = L"lnkEMail";
			this->lnkEMail->Size = System::Drawing::Size(214, 16);
			this->lnkEMail->TabIndex = 55;
			this->lnkEMail->TabStop = true;
			this->lnkEMail->Text = L"helleditor@gmail.com";
			this->lnkEMail->VisitedLinkColor = System::Drawing::Color::Red;
			this->lnkEMail->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &FormAbout::lnkEMail_LinkClicked);
			// 
			// lblURL
			// 
			this->lblURL->BackColor = System::Drawing::Color::Transparent;
			this->lblURL->Location = System::Drawing::Point(7, 101);
			this->lblURL->Name = L"lblURL";
			this->lblURL->Size = System::Drawing::Size(48, 16);
			this->lblURL->TabIndex = 54;
			this->lblURL->Text = L"URL:";
			// 
			// lnkURL
			// 
			this->lnkURL->BackColor = System::Drawing::Color::Transparent;
			this->lnkURL->LinkColor = System::Drawing::Color::Red;
			this->lnkURL->Location = System::Drawing::Point(55, 101);
			this->lnkURL->Name = L"lnkURL";
			this->lnkURL->Size = System::Drawing::Size(214, 16);
			this->lnkURL->TabIndex = 53;
			this->lnkURL->TabStop = true;
			this->lnkURL->Text = L"http://helled.sf.net";
			this->lnkURL->VisitedLinkColor = System::Drawing::Color::Red;
			this->lnkURL->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &FormAbout::lnkURL_LinkClicked);
			// 
			// lnkLicense
			// 
			this->lnkLicense->ActiveLinkColor = System::Drawing::Color::Navy;
			this->lnkLicense->BackColor = System::Drawing::Color::Transparent;
			this->lnkLicense->LinkColor = System::Drawing::Color::Navy;
			this->lnkLicense->Location = System::Drawing::Point(7, 77);
			this->lnkLicense->Name = L"lnkLicense";
			this->lnkLicense->Size = System::Drawing::Size(262, 16);
			this->lnkLicense->TabIndex = 52;
			this->lnkLicense->TabStop = true;
			this->lnkLicense->Text = L"Лицензионное соглашение";
			this->lnkLicense->VisitedLinkColor = System::Drawing::Color::Navy;
			this->lnkLicense->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &FormAbout::lnkLicense_LinkClicked);
			// 
			// lblAuthor
			// 
			this->lblAuthor->BackColor = System::Drawing::Color::Transparent;
			this->lblAuthor->Location = System::Drawing::Point(55, 61);
			this->lblAuthor->Name = L"lblAuthor";
			this->lblAuthor->Size = System::Drawing::Size(214, 16);
			this->lblAuthor->TabIndex = 51;
			this->lblAuthor->Text = L"Alexey Bezugly AKA Trooper";
			// 
			// LBLSMAPI
			// 
			this->LBLSMAPI->BackColor = System::Drawing::Color::Transparent;
			this->LBLSMAPI->Location = System::Drawing::Point(7, 173);
			this->LBLSMAPI->Name = L"LBLSMAPI";
			this->LBLSMAPI->Size = System::Drawing::Size(262, 16);
			this->LBLSMAPI->TabIndex = 50;
			this->LBLSMAPI->Text = L"SMAPI © Scott J. Dudley, 1991";
			// 
			// lblSMAPIBegin
			// 
			this->lblSMAPIBegin->BackColor = System::Drawing::Color::Transparent;
			this->lblSMAPIBegin->Location = System::Drawing::Point(7, 157);
			this->lblSMAPIBegin->Name = L"lblSMAPIBegin";
			this->lblSMAPIBegin->Size = System::Drawing::Size(262, 16);
			this->lblSMAPIBegin->TabIndex = 49;
			this->lblSMAPIBegin->Text = L"Программа использует библиотеку";
			// 
			// lblCopyright
			// 
			this->lblCopyright->BackColor = System::Drawing::Color::Transparent;
			this->lblCopyright->Location = System::Drawing::Point(7, 45);
			this->lblCopyright->Name = L"lblCopyright";
			this->lblCopyright->Size = System::Drawing::Size(262, 16);
			this->lblCopyright->TabIndex = 48;
			this->lblCopyright->Text = L"© Alexey Bezugly, 2002-2008";
			// 
			// lblVersion
			// 
			this->lblVersion->BackColor = System::Drawing::Color::Transparent;
			this->lblVersion->Location = System::Drawing::Point(55, 21);
			this->lblVersion->Name = L"lblVersion";
			this->lblVersion->Size = System::Drawing::Size(214, 16);
			this->lblVersion->TabIndex = 47;
			this->lblVersion->Text = L"1.1";
			// 
			// lblProgramName
			// 
			this->lblProgramName->BackColor = System::Drawing::Color::Transparent;
			this->lblProgramName->Location = System::Drawing::Point(7, 5);
			this->lblProgramName->Name = L"lblProgramName";
			this->lblProgramName->Size = System::Drawing::Size(262, 16);
			this->lblProgramName->TabIndex = 46;
			this->lblProgramName->Text = L"HellNet® HellEd";
			// 
			// peIcon
			// 
			this->peIcon->EditValue = (cli::safe_cast<System::Object^  >(resources->GetObject(L"peIcon.EditValue")));
			this->peIcon->Location = System::Drawing::Point(11, 73);
			this->peIcon->Name = L"peIcon";
			this->peIcon->Properties->AllowFocused = false;
			this->peIcon->Properties->BorderStyle = DevExpress::XtraEditors::Controls::BorderStyles::NoBorder;
			this->peIcon->Properties->ReadOnly = true;
			this->peIcon->Properties->ShowMenu = false;
			this->peIcon->Size = System::Drawing::Size(32, 32);
			this->peIcon->TabIndex = 48;
			// 
			// FormAbout
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(414, 328);
			this->ControlBox = false;
			this->Controls->Add(this->peIcon);
			this->Controls->Add(this->panelControl1);
			this->Controls->Add(this->peHeader);
			this->Controls->Add(this->btnOk);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormAbout";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"О программе";
			this->TopMost = true;
			this->Closing += gcnew System::ComponentModel::CancelEventHandler(this, &FormAbout::FormAbout_Closing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->peHeader->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->panelControl1))->EndInit();
			this->panelControl1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->peIcon->Properties))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		public: FormAbout(System::Windows::Forms::Form^ frm, string^ Dir)
		{
			InitializeComponent();
			frmMain = frm;
			HellEdDir=Dir;
			lblVersion->Text = string::Concat(System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Major,".",
				System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Minor,".",
				System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Build);
		}

		public: System::Void lnkLicense_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
		{
			System::Diagnostics::Process::Start(string::Concat(HellEdDir,L"\\license.txt"));
		}

		public: System::Void lnkURL_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
		{
			System::Diagnostics::Process::Start(L"http://helled.sf.net");
		}

		public: System::Void lnkEMail_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
		{
			System::Diagnostics::Process::Start(L"mailto:helleditor@gmail.com?subject=HellEd");
		}

		public: System::Void lnkURLSMAPI_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
		{
			System::Diagnostics::Process::Start(L"http://www.sourceforge.net/projects/husky");
		}

		public: System::Void lnkEMailSMAPI_LinkClicked(System::Object^ sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
		{
			System::Diagnostics::Process::Start(L"mailto:Scott.Dudley@f106.n249.z1.fidonet.org");
		}
		
		public: System::Void btnOk_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Visible=false;
			frmMain->Enabled=true;
			frmMain->TopMost=true;
			frmMain->Show();
			frmMain->Focus();
			frmMain->TopMost=false;
		}
		public: void FormAbout_Closing(object^ sender, System::ComponentModel::CancelEventArgs^ e)
		{
			e->Cancel=true;
		}
};
}
