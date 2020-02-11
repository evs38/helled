/////////////////////////////////////////////////////////////////////////////
//
// HellEd
//
// FormInputBox.h
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

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace HellEd {

	/// <summary>
	/// Summary for FormInputBox
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FormInputBox : public System::Windows::Forms::Form
	{
		public: System::Windows::Forms::Form^ frmParent;
		public: System::Windows::Forms::Label^  lblMessage;
		public: bool out;
		protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~FormInputBox()
		{
			if (components)
			{
				delete components;
			}
		}
		public: DevExpress::XtraEditors::TextEdit^  teValue;
		public: DevExpress::XtraEditors::SimpleButton^  btnOk;

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
			this->teValue = (gcnew DevExpress::XtraEditors::TextEdit());
			this->btnOk = (gcnew DevExpress::XtraEditors::SimpleButton());
			this->lblMessage = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teValue->Properties))->BeginInit();
			this->SuspendLayout();
			// 
			// teValue
			// 
			this->teValue->Location = System::Drawing::Point(12, 32);
			this->teValue->Name = L"teValue";
			this->teValue->Size = System::Drawing::Size(189, 20);
			this->teValue->TabIndex = 0;
			this->teValue->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormInputBox::teValue_KeyDown);
			// 
			// btnOk
			// 
			this->btnOk->Location = System::Drawing::Point(207, 29);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(75, 23);
			this->btnOk->TabIndex = 2;
			this->btnOk->Text = L"ÎÊ";
			this->btnOk->Click += gcnew System::EventHandler(this, &FormInputBox::btnOk_Click);
			// 
			// lblMessage
			// 
			this->lblMessage->AutoSize = true;
			this->lblMessage->Location = System::Drawing::Point(12, 9);
			this->lblMessage->Name = L"lblMessage";
			this->lblMessage->Size = System::Drawing::Size(0, 13);
			this->lblMessage->TabIndex = 3;
			// 
			// FormInputBox
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(294, 60);
			this->ControlBox = false;
			this->Controls->Add(this->lblMessage);
			this->Controls->Add(this->btnOk);
			this->Controls->Add(this->teValue);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormInputBox";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"";
			this->TopMost = true;
			this->Closing += gcnew System::ComponentModel::CancelEventHandler(this, &FormInputBox::FormInputBox_Closing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teValue->Properties))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	public:
		FormInputBox()
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
		string^ ShowInput(System::Windows::Forms::Form^ frm, string^ HeaderText, string^ MessageText, string^ Value)
		{
			frmParent = frm;
			frmParent->Enabled=false;
			Visible=true;
			Text=HeaderText;
			lblMessage->Text=MessageText;
			teValue->Text=Value;
			teValue->Focus();
			out=false;
			while (!out){Application::DoEvents();}
			return teValue->Text;
		}
		public: System::Void btnOk_Click(System::Object^ sender, System::EventArgs^ e)
		{
			Visible=false;
			frmParent->Enabled=true;
			bool tm=frmParent->TopMost;
			frmParent->TopMost=true;
			frmParent->Show();
			frmParent->Focus();
			frmParent->TopMost=tm;
			out=true;
		}
		public: void FormInputBox_Closing(object^ sender, System::ComponentModel::CancelEventArgs^ e)
		{
			e->Cancel=true;
		}
		public: System::Void teValue_KeyDown(System::Object^  sender, System::Windows::Forms::KeyEventArgs^  e)
		{
			e->Handled=false;
			if (e->KeyData==System::Windows::Forms::Keys::Enter)
			{
				e->Handled=true;
				btnOk_Click(nullptr,nullptr);
			}
		}
};
}
