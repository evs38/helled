/////////////////////////////////////////////////////////////////////////////
//
// HellEd
//
// FormPopup.h
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

#include "FormSettings.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace HellEd {

	/// <summary>
	/// Summary for FormPopup
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FormPopup : public DevExpress::XtraEditors::XtraForm
	{
		public: System::Windows::Forms::Form^ frmMain;
		public: FormSettings^ frmSettings;
		public: System::Windows::Forms::TextBox^  meMessage;
	private: System::Windows::Forms::CheckBox^  cheFocus;
	public: 
	public: int StartTick;
		protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormPopup()
		{
			if (components)
			{
				delete components;
			}
		}

		public: System::Windows::Forms::Timer^  tiMain;
		private: System::ComponentModel::IContainer^  components;

		private:
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
			this->components = (gcnew System::ComponentModel::Container());
			this->tiMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->meMessage = (gcnew System::Windows::Forms::TextBox());
			this->cheFocus = (gcnew System::Windows::Forms::CheckBox());
			this->SuspendLayout();
			// 
			// tiMain
			// 
			this->tiMain->Tick += gcnew System::EventHandler(this, &FormPopup::tiMain_Tick);
			// 
			// meMessage
			// 
			this->meMessage->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(51)), static_cast<System::Int32>(static_cast<System::Byte>(153)), 
				static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->meMessage->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->meMessage->Cursor = System::Windows::Forms::Cursors::Default;
			this->meMessage->Dock = System::Windows::Forms::DockStyle::Fill;
			this->meMessage->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold));
			this->meMessage->ForeColor = System::Drawing::SystemColors::Info;
			this->meMessage->Location = System::Drawing::Point(0, 0);
			this->meMessage->Multiline = true;
			this->meMessage->Name = L"meMessage";
			this->meMessage->ReadOnly = true;
			this->meMessage->ShortcutsEnabled = false;
			this->meMessage->Size = System::Drawing::Size(189, 83);
			this->meMessage->TabIndex = 1;
			// 
			// cheFocus
			// 
			this->cheFocus->AutoSize = true;
			this->cheFocus->Location = System::Drawing::Point(174, 69);
			this->cheFocus->Name = L"cheFocus";
			this->cheFocus->Size = System::Drawing::Size(15, 14);
			this->cheFocus->TabIndex = 2;
			this->cheFocus->UseVisualStyleBackColor = true;
			// 
			// FormPopup
			// 
			this->Appearance->Font = (gcnew System::Drawing::Font(L"Tahoma", 8.25F, System::Drawing::FontStyle::Bold));
			this->Appearance->Options->UseFont = true;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(189, 83);
			this->Controls->Add(this->meMessage);
			this->Controls->Add(this->cheFocus);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormPopup";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->TopMost = true;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &FormPopup::FormPopup_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		public:	FormPopup(System::Windows::Forms::Form^ frm)
		{
			InitializeComponent();
			frmMain = frm;
		}
		public:	void ShowPopup(string^ HeaderText, string^ MessageText)
		{
			this->Text=HeaderText;
			meMessage->Text=MessageText;
			int popup_location = frmSettings->rcbepopup_location->Items->IndexOf(frmSettings->tlConfigHED->FindNodeByKeyID(1104)->GetValue(1));
			if (popup_location==0){this->Location = (*dynamic_cast<Point^>(gcnew Point(0,0)));}
			else if (popup_location==1){this->Location = (*dynamic_cast<Point^>(gcnew Point(0,Screen::PrimaryScreen->WorkingArea.Bottom-this->Height)));}
			else if (popup_location==2){this->Location = (*dynamic_cast<Point^>(gcnew Point(Screen::PrimaryScreen->WorkingArea.Right-this->Width,0)));}
			else {this->Location = (*dynamic_cast<Point^>(gcnew Point(Screen::PrimaryScreen->WorkingArea.Right-this->Width,Screen::PrimaryScreen->WorkingArea.Bottom-this->Height)));}
			this->Visible=true;
			meMessage->SelectionStart=0;
			meMessage->SelectionLength=0;
			cheFocus->Focus();
			StartTick=System::Environment::TickCount;
			tiMain->Enabled=true;
		}
		public: System::Void FormPopup_FormClosing(System::Object^  sender, System::Windows::Forms::FormClosingEventArgs^  e) 
		{
			e->Cancel=true;
			this->Visible=false;
			tiMain->Enabled=false;
		}

		public: System::Void tiMain_Tick(System::Object^  sender, System::EventArgs^  e)
		{
			int popup_time=	Convert::ToInt64(frmSettings->tlConfigHED->FindNodeByKeyID(1103)->GetValue(1));
			if (System::Environment::TickCount - StartTick>=popup_time*1000)
			{
				this->Visible=false;
				tiMain->Enabled=false;
			}
		}
};
}
