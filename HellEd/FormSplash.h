/////////////////////////////////////////////////////////////////////////////
//
// HellEd
//
// FormSplash.h
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
	/// Summary for FormSplash
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FormSplash : public DevExpress::XtraEditors::XtraForm
	{
		public: System::Windows::Forms::Label^  lblMessage;
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected: ~FormSplash()
		{
			if (components)
			{
				delete components;
			}
		}

		/// <summary>
		/// Required designer variable.
		/// </summary>
		private: System::ComponentModel::Container ^components;
		protected: 
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = gcnew System::ComponentModel::Container();
			this->lblMessage = gcnew System::Windows::Forms::Label();
			this->SuspendLayout();
			// 
			// lblMessage
			// 
			this->lblMessage->BackColor = System::Drawing::SystemColors::Window;
			this->lblMessage->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->lblMessage->Location = System::Drawing::Point(0, 84);
			this->lblMessage->Name = L"lblMessage";
			this->lblMessage->Size = System::Drawing::Size(300, 16);
			this->lblMessage->TabIndex = 0;
			// 
			// FormSplash
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->ClientSize = System::Drawing::Size(300, 100);
			this->Controls->Add(this->lblMessage);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"FormSplash";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FormSplash";
			this->TopMost = true;
        }
#pragma endregion
		public:	FormSplash(void)
		{
			InitializeComponent();
		}
	};
}
