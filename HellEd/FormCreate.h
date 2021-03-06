/////////////////////////////////////////////////////////////////////////////
//
// HellEd
//
// FormCreate.h
//
// Copyright (c) 2002-2008 by Alexey Bezugly
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version. See license.txt for details.
/////////////////////////////////////////////////////////////////////////////
#pragma once
#pragma warning(disable:4965)
#include "smapi/msgapi.h"
#include <windows.h>

typedef System::Object object;
typedef System::String string;

#include "Config.h"
#include "FormSettings.h"

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace DevExpress::XtraSpellChecker;


namespace HellEd {

	/// <summary>
	/// Summary for FormCreate
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FormCreate : public System::Windows::Forms::Form
	{
		public: FormSettings^ frmSettings;

		public: Config^ ConfigForms;
		public: string^ HellEdDir;
		public: int string_length;

		public: string^ temp;
		public: word msgn;
		public: dword replyto;
		public: string^ qtarea;
		public: string^ qarea;
		public: string^ qoname;
		public: string^ qofname;
		public: string^ qomname;
		public: string^ qolname;
		public: string^ qdname;
		public: string^ qdfname;
		public: string^ qdmname;
		public: string^ qdlname;
		public: string^ qoaddr;
		public: string^ qdaddr;
		public: string^ qsubject;
		public: string^ qtext;
		public: string^ qselectedtext;
		public: string^ quote;
		public: string^ qlite;
		public: string^ qattributes;
		public: string^ qmsgid;
		public: string^ qkludges;
		public: string^ qeomkludges;
		public: string^ qqkludges;
		public: string^ qqeomkludges;

		public: string^ qbegin;
		public: System::DateTime qodatetime;
		public: System::DateTime qddatetime;
		public: int uptime;

		public: string^ area;
		public: string^ oname;
		public: string^ ofname;
		public: string^ omname;
		public: string^ olname;
		public: string^ dname;
		public: string^ dfname;
		public: string^ dmname;
		public: string^ dlname;
		public: string^ oaddr;
		public: string^ daddr;
		public: string^ subject;
		public: string^ attributes;
		public: System::DateTime odatetime;
		public: string^ text;
		public: string^ tearline;
		public: string^ origin;
		public: string^ Vers;

		public: bool fl;
		
		public: Hashtable^ htStrings;
		public: Hashtable^ htLanguage;
		public: DevExpress::XtraSpellChecker::SpellChecker^  spell;
		public: DevExpress::XtraBars::BarManager^ barManager;
		public: DevExpress::XtraBars::BarDockControl^ barDockControlTop;
		public: DevExpress::XtraBars::BarDockControl^ barDockControlBottom;
		public: DevExpress::XtraBars::BarDockControl^ barDockControlLeft;
		public: DevExpress::XtraBars::BarDockControl^ barDockControlRight;
		public: DevExpress::XtraBars::Bar^ barMenu;

		public: DevExpress::XtraBars::BarSubItem^ mFile;
		public: DevExpress::XtraBars::BarSubItem^ mEdit;
		public: DevExpress::XtraBars::BarSubItem^ mInsert;
		public: DevExpress::XtraBars::BarSubItem^ mFormat;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bSend;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bSaveMessage;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bSaveAsTemplate;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bPrint;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bClose;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bUndo;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bCut;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bCopy;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bPaste;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bSelectAll;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bFind;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bReplace;
		public: DevExpress::XtraBars::BarSubItem^ mAdd;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bAdd1;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bAdd2;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bAdd3;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bAdd4;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bAdd5;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bAdd6;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bAdd7;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bAdd8;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bAdd9;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bAdd0;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bAttachFile;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bTextFromFile;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bUUEncode;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bBold;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bReverse;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bItalic;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bUnderline;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bCustomize;









		public: DevExpress::XtraBars::Bar^ barStatus;
		public: DevExpress::XtraBars::BarStaticItem^ sStatus;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bQuoteFromFile;
		public: DevExpress::XtraBars::BarLargeButtonItem^ lbMIMEncode;
		public: DevExpress::XtraBars::BarSubItem^ mService;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bEncryptROT13;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bSpellCheck;
		public: DevExpress::XtraTreeList::Blending::XtraTreeListBlending^ xtlbArea;
		public: DevExpress::XtraTreeList::Blending::XtraTreeListBlending^ xtlbDAddr;


		public: DevExpress::XtraEditors::PopupContainerControl^ pccArea;
		public: DevExpress::XtraTreeList::TreeList^ tlArea;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcName;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcDescription;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcPath;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcAddress;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcBaseType;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcAreaType;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcNode;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcMark;
		public: DevExpress::XtraEditors::PopupContainerControl^ pccDAddr;
		public: System::Windows::Forms::Panel^ pnlList;
		public: DevExpress::XtraTreeList::TreeList^ tlDAddr;
		public: System::Windows::Forms::Panel^ pnlFind;
		public: DevExpress::XtraEditors::TextEdit^ teDAddr;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcDAddr;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcStation;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcPlace;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcDName;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcPhone;
		public: DevExpress::XtraBars::Bar^ barFile;
		public: DevExpress::XtraBars::Bar^ barEdit;
		public: DevExpress::XtraBars::Bar^ barInsert;
		public: DevExpress::XtraBars::Bar^ barFormat;
		public: DevExpress::XtraBars::Bar^ barService;
		public: DevExpress::XtraEditors::PopupContainerControl^ pccAttributes;
		public: DevExpress::XtraEditors::CheckedListBoxControl^ clbAttributes;
		public: DevExpress::XtraBars::BarSubItem^ mView;
		public: DevExpress::XtraBars::BarSubItem^ mToolbars;
		public: DevExpress::XtraBars::BarToolbarsListItem^ lToolbars;
		public: DevExpress::XtraBars::PopupMenu^ pmEdit;
		public: DevExpress::XtraEditors::Repository::RepositoryItemCheckEdit^ rche;
		public: DevExpress::XtraEditors::Repository::RepositoryItemTextEdit^ rtero;
		public: QWhale::Editor::SyntaxEdit^  rtText;
		public: QWhale::Syntax::Parser^  parMessage;
		public: DevExpress::XtraLayout::LayoutControl^  LayoutControl;
		public: DevExpress::XtraLayout::LayoutControlGroup^  lcgMain;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciText;
		public: DevExpress::XtraEditors::PopupContainerEdit^  pceArea;
		public: DevExpress::XtraEditors::ComboBoxEdit^  cbeOrigin;
		public: DevExpress::XtraEditors::TextEdit^  teOriginEnd;
		public: DevExpress::XtraEditors::TextEdit^  teOriginBegin;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciOriginBegin;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciOriginEnd;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciOrigin;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciArea;
		public: DevExpress::XtraEditors::PopupContainerEdit^  pceToAddress;
		public: DevExpress::XtraEditors::TextEdit^  teTo;
		public: DevExpress::XtraEditors::ComboBoxEdit^  cbeFromAddress;
		public: DevExpress::XtraEditors::ComboBoxEdit^  cbeFrom;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciFrom;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciFromAddress;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciTo;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciToAddress;
		public: DevExpress::XtraEditors::TimeEdit^  teReceived;
		public: DevExpress::XtraEditors::DateEdit^  deReceived;
		public: DevExpress::XtraEditors::TimeEdit^  teWritten;
		public: DevExpress::XtraEditors::DateEdit^  deWritten;
		public: DevExpress::XtraEditors::TextEdit^  teSubject;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciSubject;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciWritten;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciWrittenTime;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciReceived;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciReceivedTime;
		public: DevExpress::XtraEditors::PopupContainerEdit^  pceAttributes;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciAttributes;
		public: DevExpress::XtraBars::BarListItem^ lSpelling;

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected: ~FormCreate()
		{
			if (components)
			{
				delete components;
			}
		}
private: System::ComponentModel::IContainer^  components;
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
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormCreate::typeid));
			this->barManager = (gcnew DevExpress::XtraBars::BarManager(this->components));
			this->barMenu = (gcnew DevExpress::XtraBars::Bar());
			this->mFile = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bSend = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bSaveMessage = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bSaveAsTemplate = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bPrint = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bClose = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->mView = (gcnew DevExpress::XtraBars::BarSubItem());
			this->mToolbars = (gcnew DevExpress::XtraBars::BarSubItem());
			this->lToolbars = (gcnew DevExpress::XtraBars::BarToolbarsListItem());
			this->mEdit = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bUndo = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bCut = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bCopy = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bPaste = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bSelectAll = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bFind = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bReplace = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->mInsert = (gcnew DevExpress::XtraBars::BarSubItem());
			this->mAdd = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bCustomize = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bAdd1 = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bAdd2 = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bAdd3 = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bAdd4 = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bAdd5 = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bAdd6 = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bAdd7 = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bAdd8 = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bAdd9 = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bAdd0 = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bAttachFile = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bTextFromFile = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bQuoteFromFile = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bUUEncode = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->mFormat = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bBold = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bReverse = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bItalic = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bUnderline = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->mService = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bSpellCheck = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bEncryptROT13 = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->barStatus = (gcnew DevExpress::XtraBars::Bar());
			this->sStatus = (gcnew DevExpress::XtraBars::BarStaticItem());
			this->barFile = (gcnew DevExpress::XtraBars::Bar());
			this->barEdit = (gcnew DevExpress::XtraBars::Bar());
			this->barInsert = (gcnew DevExpress::XtraBars::Bar());
			this->barFormat = (gcnew DevExpress::XtraBars::Bar());
			this->barService = (gcnew DevExpress::XtraBars::Bar());
			this->barDockControlTop = (gcnew DevExpress::XtraBars::BarDockControl());
			this->barDockControlBottom = (gcnew DevExpress::XtraBars::BarDockControl());
			this->barDockControlLeft = (gcnew DevExpress::XtraBars::BarDockControl());
			this->barDockControlRight = (gcnew DevExpress::XtraBars::BarDockControl());
			this->lSpelling = (gcnew DevExpress::XtraBars::BarListItem());
			this->xtlbArea = (gcnew DevExpress::XtraTreeList::Blending::XtraTreeListBlending());
			this->xtlbDAddr = (gcnew DevExpress::XtraTreeList::Blending::XtraTreeListBlending());
			this->pccDAddr = (gcnew DevExpress::XtraEditors::PopupContainerControl());
			this->pnlList = (gcnew System::Windows::Forms::Panel());
			this->tlDAddr = (gcnew DevExpress::XtraTreeList::TreeList());
			this->tlcDAddr = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcStation = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcPlace = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcDName = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcPhone = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->pnlFind = (gcnew System::Windows::Forms::Panel());
			this->teDAddr = (gcnew DevExpress::XtraEditors::TextEdit());
			this->pccAttributes = (gcnew DevExpress::XtraEditors::PopupContainerControl());
			this->clbAttributes = (gcnew DevExpress::XtraEditors::CheckedListBoxControl());
			this->pccArea = (gcnew DevExpress::XtraEditors::PopupContainerControl());
			this->tlArea = (gcnew DevExpress::XtraTreeList::TreeList());
			this->tlcName = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcDescription = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcPath = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcAddress = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcBaseType = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcAreaType = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcNode = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcMark = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->pmEdit = (gcnew DevExpress::XtraBars::PopupMenu(this->components));
			this->rche = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemCheckEdit());
			this->rtero = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemTextEdit());
			this->rtText = (gcnew QWhale::Editor::SyntaxEdit(this->components));
			this->parMessage = (gcnew QWhale::Syntax::Parser());
			this->LayoutControl = (gcnew DevExpress::XtraLayout::LayoutControl());
			this->pceAttributes = (gcnew DevExpress::XtraEditors::PopupContainerEdit());
			this->teReceived = (gcnew DevExpress::XtraEditors::TimeEdit());
			this->deReceived = (gcnew DevExpress::XtraEditors::DateEdit());
			this->teWritten = (gcnew DevExpress::XtraEditors::TimeEdit());
			this->deWritten = (gcnew DevExpress::XtraEditors::DateEdit());
			this->teSubject = (gcnew DevExpress::XtraEditors::TextEdit());
			this->pceToAddress = (gcnew DevExpress::XtraEditors::PopupContainerEdit());
			this->teTo = (gcnew DevExpress::XtraEditors::TextEdit());
			this->cbeFromAddress = (gcnew DevExpress::XtraEditors::ComboBoxEdit());
			this->cbeFrom = (gcnew DevExpress::XtraEditors::ComboBoxEdit());
			this->pceArea = (gcnew DevExpress::XtraEditors::PopupContainerEdit());
			this->cbeOrigin = (gcnew DevExpress::XtraEditors::ComboBoxEdit());
			this->teOriginEnd = (gcnew DevExpress::XtraEditors::TextEdit());
			this->teOriginBegin = (gcnew DevExpress::XtraEditors::TextEdit());
			this->lcgMain = (gcnew DevExpress::XtraLayout::LayoutControlGroup());
			this->lciText = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciOriginBegin = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciOriginEnd = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciOrigin = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciArea = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciFrom = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciFromAddress = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciTo = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciToAddress = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciSubject = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciWritten = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciWrittenTime = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciReceived = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciReceivedTime = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciAttributes = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barManager))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pccDAddr))->BeginInit();
			this->pccDAddr->SuspendLayout();
			this->pnlList->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlDAddr))->BeginInit();
			this->pnlFind->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teDAddr->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pccAttributes))->BeginInit();
			this->pccAttributes->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->clbAttributes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pccArea))->BeginInit();
			this->pccArea->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlArea))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmEdit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rche))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rtero))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->LayoutControl))->BeginInit();
			this->LayoutControl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pceAttributes->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teReceived->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->deReceived->Properties->VistaTimeProperties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->deReceived->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teWritten->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->deWritten->Properties->VistaTimeProperties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->deWritten->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teSubject->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pceToAddress->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teTo->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cbeFromAddress->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cbeFrom->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pceArea->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cbeOrigin->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teOriginEnd->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teOriginBegin->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lcgMain))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciText))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciOriginBegin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciOriginEnd))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciOrigin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciArea))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciFrom))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciFromAddress))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciTo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciToAddress))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciSubject))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciWritten))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciWrittenTime))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciReceived))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciReceivedTime))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciAttributes))->BeginInit();
			this->SuspendLayout();
			// 
			// barManager
			// 
			this->barManager->AllowCustomization = true;
			this->barManager->AllowQuickCustomization = true;
			this->barManager->AllowShowToolbarsPopup = false;
			this->barManager->Bars->AddRange(gcnew cli::array< DevExpress::XtraBars::Bar^  >(7) {this->barMenu, this->barStatus, this->barFile, 
				this->barEdit, this->barInsert, this->barFormat, this->barService});
			this->barManager->DockControls->Add(this->barDockControlTop);
			this->barManager->DockControls->Add(this->barDockControlBottom);
			this->barManager->DockControls->Add(this->barDockControlLeft);
			this->barManager->DockControls->Add(this->barDockControlRight);
			this->barManager->Form = this;
			this->barManager->Items->AddRange(gcnew cli::array< DevExpress::XtraBars::BarItem^  >(44) {this->mFile, this->mEdit, this->mInsert, 
				this->mFormat, this->bSend, this->bSaveMessage, this->bSaveAsTemplate, this->bPrint, this->bClose, this->bUndo, this->bCut, this->bCopy, 
				this->bPaste, this->bSelectAll, this->bFind, this->bReplace, this->bAttachFile, this->bTextFromFile, this->bUUEncode, this->bBold, 
				this->bReverse, this->bItalic, this->bUnderline, this->sStatus, this->bQuoteFromFile, this->mService, this->bSpellCheck, this->bEncryptROT13, 
				this->mView, this->mToolbars, this->lToolbars, this->lSpelling, this->mAdd, this->bAdd1, this->bAdd2, this->bAdd3, this->bAdd4, 
				this->bAdd5, this->bAdd6, this->bAdd7, this->bAdd8, this->bAdd9, this->bAdd0, this->bCustomize});
			this->barManager->MainMenu = this->barMenu;
			this->barManager->MaxItemId = 83;
			this->barManager->StatusBar = this->barStatus;
			// 
			// barMenu
			// 
			this->barMenu->BarName = L"barMenu";
			this->barMenu->DockCol = 0;
			this->barMenu->DockRow = 0;
			this->barMenu->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barMenu->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(6) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mFile)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mView)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->mEdit)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->mInsert)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mFormat)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->mService))});
			this->barMenu->OptionsBar->AllowQuickCustomization = false;
			this->barMenu->OptionsBar->DisableCustomization = true;
			this->barMenu->OptionsBar->MultiLine = true;
			this->barMenu->OptionsBar->UseWholeRow = true;
			this->barMenu->Text = L"Menu";
			// 
			// mFile
			// 
			this->mFile->Caption = L"Файл";
			this->mFile->Id = 0;
			this->mFile->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(5) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSend)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSaveMessage, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSaveAsTemplate)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bPrint, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bClose, 
				true))});
			this->mFile->Name = L"mFile";
			// 
			// bCustomize
			// 
			this->bCustomize->Caption = L"Настроить";
			this->bCustomize->Id = 11126;
			this->bCustomize->Name = L"bCustomize";
			this->bCustomize->ShowCaptionOnBar = false;
			this->bCustomize->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bCustomize_ItemClick);
			// 
			// bSend
			// 
			this->bSend->Caption = L"Отправить";
			this->bSend->Id = 4;
			this->bSend->ImageIndex = 0;
			this->bSend->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::F2));
			this->bSend->LargeImageIndex = 0;
			this->bSend->Name = L"bSend";
			this->bSend->ShowCaptionOnBar = false;
			this->bSend->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bSend_ItemClick);
			// 
			// bSaveMessage
			// 
			this->bSaveMessage->Caption = L"Сохранить сообщение";
			this->bSaveMessage->Id = 5;
			this->bSaveMessage->ImageIndex = 1;
			this->bSaveMessage->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::F7));
			this->bSaveMessage->LargeImageIndex = 1;
			this->bSaveMessage->Name = L"bSaveMessage";
			this->bSaveMessage->ShowCaptionOnBar = false;
			this->bSaveMessage->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bSaveMessage_ItemClick);
			// 
			// bSaveAsTemplate
			// 
			this->bSaveAsTemplate->Caption = L"Сохранить как шаблон";
			this->bSaveAsTemplate->Id = 6;
			this->bSaveAsTemplate->ImageIndex = 2;
			this->bSaveAsTemplate->LargeImageIndex = 2;
			this->bSaveAsTemplate->Name = L"bSaveAsTemplate";
			this->bSaveAsTemplate->ShowCaptionOnBar = false;
			this->bSaveAsTemplate->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bSaveAsTemplate_ItemClick);
			// 
			// bPrint
			// 
			this->bPrint->Caption = L"Печать...";
			this->bPrint->Id = 7;
			this->bPrint->ImageIndex = 3;
			this->bPrint->LargeImageIndex = 3;
			this->bPrint->Name = L"bPrint";
			this->bPrint->ShowCaptionOnBar = false;
			this->bPrint->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bPrint_ItemClick);
			// 
			// bClose
			// 
			this->bClose->Caption = L"Закрыть";
			this->bClose->Id = 8;
			this->bClose->ImageIndex = 4;
			this->bClose->LargeImageIndex = 4;
			this->bClose->Name = L"bClose";
			this->bClose->ShowCaptionOnBar = false;
			this->bClose->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bClose_ItemClick);
			// 
			// mView
			// 
			this->mView->Caption = L"Вид";
			this->mView->Id = 80;
			this->mView->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(1) 
			{(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mToolbars))
			});
			this->mView->Name = L"mView";
			// 
			// mToolbars
			// 
			this->mToolbars->Caption = L"Панели";
			this->mToolbars->Id = 81;
			this->mToolbars->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(2) 
			{(gcnew DevExpress::XtraBars::LinkPersistInfo(this->lToolbars)),
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bCustomize, true))});
			this->mToolbars->Name = L"mToolbars";
			// 
			// lToolbars
			// 
			this->lToolbars->Caption = L"lToolbars";
			this->lToolbars->Id = 82;
			this->lToolbars->Name = L"lToolbars";
			this->lToolbars->ShowCustomizationItem = false;
			// 
			// mEdit
			// 
			this->mEdit->Caption = L"Правка";
			this->mEdit->Id = 1;
			this->mEdit->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(7) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bUndo)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bCut, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bCopy)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bPaste)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSelectAll)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bFind, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bReplace))});
			this->mEdit->Name = L"mEdit";
			// 
			// bUndo
			// 
			this->bUndo->Caption = L"Отменить";
			this->bUndo->Id = 9;
			this->bUndo->ImageIndex = 5;
			this->bUndo->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Z)));
			this->bUndo->LargeImageIndex = 5;
			this->bUndo->Name = L"bUndo";
			this->bUndo->ShowCaptionOnBar = false;
			this->bUndo->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bUndo_ItemClick);
			// 
			// bCut
			// 
			this->bCut->Caption = L"Вырезать";
			this->bCut->Id = 10;
			this->bCut->ImageIndex = 6;
			this->bCut->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::X)));
			this->bCut->LargeImageIndex = 6;
			this->bCut->Name = L"bCut";
			this->bCut->ShowCaptionOnBar = false;
			this->bCut->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bCut_ItemClick);
			// 
			// bCopy
			// 
			this->bCopy->Caption = L"Копировать";
			this->bCopy->Id = 11;
			this->bCopy->ImageIndex = 7;
			this->bCopy->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C)));
			this->bCopy->LargeImageIndex = 7;
			this->bCopy->Name = L"bCopy";
			this->bCopy->ShowCaptionOnBar = false;
			this->bCopy->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bCopy_ItemClick);
			// 
			// bPaste
			// 
			this->bPaste->Caption = L"Вставить";
			this->bPaste->Id = 12;
			this->bPaste->ImageIndex = 8;
			this->bPaste->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::V)));
			this->bPaste->LargeImageIndex = 8;
			this->bPaste->Name = L"bPaste";
			this->bPaste->ShowCaptionOnBar = false;
			this->bPaste->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bPaste_ItemClick);
			// 
			// bSelectAll
			// 
			this->bSelectAll->Caption = L"Выделить всё";
			this->bSelectAll->Id = 13;
			this->bSelectAll->ImageIndex = 9;
			this->bSelectAll->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A)));
			this->bSelectAll->LargeImageIndex = 9;
			this->bSelectAll->Name = L"bSelectAll";
			this->bSelectAll->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bSelectAll_ItemClick);
			// 
			// bFind
			// 
			this->bFind->Caption = L"Найти...";
			this->bFind->Id = 14;
			this->bFind->ImageIndex = 10;
			this->bFind->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F)));
			this->bFind->LargeImageIndex = 10;
			this->bFind->Name = L"bFind";
			this->bFind->ShowCaptionOnBar = false;
			this->bFind->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bFind_ItemClick);
			// 
			// bReplace
			// 
			this->bReplace->Caption = L"Заменить";
			this->bReplace->Id = 15;
			this->bReplace->ImageIndex = 11;
			this->bReplace->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::H)));
			this->bReplace->LargeImageIndex = 11;
			this->bReplace->Name = L"bReplace";
			this->bReplace->ShowCaptionOnBar = false;
			this->bReplace->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bReplace_ItemClick);
			// 
			// mInsert
			// 
			this->mInsert->Caption = L"Вставка";
			this->mInsert->Id = 2;
			this->mInsert->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(5) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mAdd)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAttachFile)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bTextFromFile)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bQuoteFromFile)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bUUEncode))});
			this->mInsert->Name = L"mInsert";
			// 
			// mAdd
			// 
			this->mAdd->Caption = L"Вставка";
			this->mAdd->Id = 766;
			this->mAdd->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(10) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAdd1)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAdd2)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAdd3)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAdd4)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAdd5)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAdd6)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAdd7)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAdd8)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAdd9)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAdd0))});
			this->mAdd->Name = L"mAdd";
			// 
			// bAdd1
			// 
			this->bAdd1->Caption = L"Вставка";
			this->bAdd1->Id = 716;
			this->bAdd1->ImageIndex = 12;
			this->bAdd1->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D1)));
			this->bAdd1->LargeImageIndex = 12;
			this->bAdd1->Name = L"bAdd1";
			this->bAdd1->ShowCaptionOnBar = false;
			this->bAdd1->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bAdd1_ItemClick);
			// 
			// bAdd2
			// 
			this->bAdd2->Caption = L"Вставка";
			this->bAdd2->Id = 717;
			this->bAdd2->ImageIndex = 12;
			this->bAdd2->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D2)));
			this->bAdd2->LargeImageIndex = 12;
			this->bAdd2->Name = L"bAdd2";
			this->bAdd2->ShowCaptionOnBar = false;
			this->bAdd2->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bAdd2_ItemClick);
			// 
			// bAdd3
			// 
			this->bAdd3->Caption = L"Вставка";
			this->bAdd3->Id = 718;
			this->bAdd3->ImageIndex = 12;
			this->bAdd3->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D3)));
			this->bAdd3->LargeImageIndex = 12;
			this->bAdd3->Name = L"bAdd3";
			this->bAdd3->ShowCaptionOnBar = false;
			this->bAdd3->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bAdd3_ItemClick);
			// 
			// bAdd4
			// 
			this->bAdd4->Caption = L"Вставка";
			this->bAdd4->Id = 719;
			this->bAdd4->ImageIndex = 12;
			this->bAdd4->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D4)));
			this->bAdd4->LargeImageIndex = 12;
			this->bAdd4->Name = L"bAdd4";
			this->bAdd4->ShowCaptionOnBar = false;
			this->bAdd4->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bAdd4_ItemClick);
			// 
			// bAdd5
			// 
			this->bAdd5->Caption = L"Вставка";
			this->bAdd5->Id = 720;
			this->bAdd5->ImageIndex = 12;
			this->bAdd5->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D5)));
			this->bAdd5->LargeImageIndex = 12;
			this->bAdd5->Name = L"bAdd5";
			this->bAdd5->ShowCaptionOnBar = false;
			this->bAdd5->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bAdd5_ItemClick);
			// 
			// bAdd6
			// 
			this->bAdd6->Caption = L"Вставка";
			this->bAdd6->Id = 721;
			this->bAdd6->ImageIndex = 12;
			this->bAdd6->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D6)));
			this->bAdd6->LargeImageIndex = 12;
			this->bAdd6->Name = L"bAdd6";
			this->bAdd6->ShowCaptionOnBar = false;
			this->bAdd6->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bAdd6_ItemClick);
			// 
			// bAdd7
			// 
			this->bAdd7->Caption = L"Вставка";
			this->bAdd7->Id = 722;
			this->bAdd7->ImageIndex = 12;
			this->bAdd7->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D7)));
			this->bAdd7->LargeImageIndex = 12;
			this->bAdd7->Name = L"bAdd7";
			this->bAdd7->ShowCaptionOnBar = false;
			this->bAdd7->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bAdd7_ItemClick);
			// 
			// bAdd8
			// 
			this->bAdd8->Caption = L"Вставка";
			this->bAdd8->Id = 723;
			this->bAdd8->ImageIndex = 12;
			this->bAdd8->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D8)));
			this->bAdd8->LargeImageIndex = 12;
			this->bAdd8->Name = L"bAdd8";
			this->bAdd8->ShowCaptionOnBar = false;
			this->bAdd8->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bAdd8_ItemClick);
			// 
			// bAdd9
			// 
			this->bAdd9->Caption = L"Вставка";
			this->bAdd9->Id = 724;
			this->bAdd9->ImageIndex = 12;
			this->bAdd9->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D9)));
			this->bAdd9->LargeImageIndex = 12;
			this->bAdd9->Name = L"bAdd9";
			this->bAdd9->ShowCaptionOnBar = false;
			this->bAdd9->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bAdd9_ItemClick);
			// 
			// bAdd0
			// 
			this->bAdd0->Caption = L"Вставка";
			this->bAdd0->Id = 725;
			this->bAdd0->ImageIndex = 12;
			this->bAdd0->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::D0)));
			this->bAdd0->LargeImageIndex = 12;
			this->bAdd0->Name = L"bAdd0";
			this->bAdd0->ShowCaptionOnBar = false;
			this->bAdd0->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bAdd0_ItemClick);
			// 
			// bAttachFile
			// 
			this->bAttachFile->Caption = L"Вложение файла";
			this->bAttachFile->Id = 16;
			this->bAttachFile->ImageIndex = 12;
			this->bAttachFile->LargeImageIndex = 12;
			this->bAttachFile->Name = L"bAttachFile";
			this->bAttachFile->ShowCaptionOnBar = false;
			this->bAttachFile->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bAttachFile_ItemClick);
			// 
			// bTextFromFile
			// 
			this->bTextFromFile->Caption = L"Текст из файла";
			this->bTextFromFile->Id = 17;
			this->bTextFromFile->ImageIndex = 13;
			this->bTextFromFile->LargeImageIndex = 13;
			this->bTextFromFile->Name = L"bTextFromFile";
			this->bTextFromFile->ShowCaptionOnBar = false;
			this->bTextFromFile->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bTextFromFile_ItemClick);
			// 
			// bQuoteFromFile
			// 
			this->bQuoteFromFile->Caption = L"Цитированние из файла";
			this->bQuoteFromFile->Id = 33;
			this->bQuoteFromFile->ImageIndex = 14;
			this->bQuoteFromFile->LargeImageIndex = 14;
			this->bQuoteFromFile->Name = L"bQuoteFromFile";
			this->bQuoteFromFile->ShowCaptionOnBar = false;
			this->bQuoteFromFile->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bQuoteFromFile_ItemClick);
			// 
			// bUUEncode
			// 
			this->bUUEncode->Caption = L"Кодировать UU";
			this->bUUEncode->Id = 18;
			this->bUUEncode->ImageIndex = 15;
			this->bUUEncode->LargeImageIndex = 15;
			this->bUUEncode->Name = L"bUUEncode";
			this->bUUEncode->ShowCaptionOnBar = false;
			this->bUUEncode->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bUUEncode_ItemClick);
			// 
			// mFormat
			// 
			this->mFormat->Caption = L"Формат";
			this->mFormat->Id = 3;
			this->mFormat->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(4) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bBold)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bReverse)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bItalic)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bUnderline))});
			this->mFormat->Name = L"mFormat";
			// 
			// bBold
			// 
			this->bBold->Caption = L"Выделение";
			this->bBold->Id = 19;
			this->bBold->ImageIndex = 16;
			this->bBold->LargeImageIndex = 16;
			this->bBold->Name = L"bBold";
			this->bBold->ShowCaptionOnBar = false;
			this->bBold->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bBold_ItemClick);
			// 
			// bReverse
			// 
			this->bReverse->Caption = L"Инверсное выделенние";
			this->bReverse->Id = 20;
			this->bReverse->ImageIndex = 17;
			this->bReverse->LargeImageIndex = 17;
			this->bReverse->Name = L"bReverse";
			this->bReverse->ShowCaptionOnBar = false;
			this->bReverse->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bReverse_ItemClick);
			// 
			// bItalic
			// 
			this->bItalic->Caption = L"Курсив";
			this->bItalic->Id = 22;
			this->bItalic->ImageIndex = 18;
			this->bItalic->LargeImageIndex = 18;
			this->bItalic->Name = L"bItalic";
			this->bItalic->ShowCaptionOnBar = false;
			this->bItalic->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bItalic_ItemClick);
			// 
			// bUnderline
			// 
			this->bUnderline->Caption = L"Подчёркнутый";
			this->bUnderline->Id = 23;
			this->bUnderline->ImageIndex = 19;
			this->bUnderline->LargeImageIndex = 19;
			this->bUnderline->Name = L"bUnderline";
			this->bUnderline->ShowCaptionOnBar = false;
			this->bUnderline->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bUnderline_ItemClick);
			// 
			// mService
			// 
			this->mService->Caption = L"Сервис";
			this->mService->Id = 71;
			this->mService->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(2) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSpellCheck)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bEncryptROT13))});
			this->mService->Name = L"mService";
			// 
			// bSpellCheck
			// 
			this->bSpellCheck->Caption = L"Правописание";
			this->bSpellCheck->Id = 72;
			this->bSpellCheck->ImageIndex = 20;
			this->bSpellCheck->LargeImageIndex = 20;
			this->bSpellCheck->Name = L"bSpellCheck";
			this->bSpellCheck->ShowCaptionOnBar = false;
			this->bSpellCheck->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bSpellCheck_ItemClick);
			// 
			// bEncryptROT13
			// 
			this->bEncryptROT13->Caption = L"Зашифровать ROT13";
			this->bEncryptROT13->Id = 73;
			this->bEncryptROT13->ImageIndex = 21;
			this->bEncryptROT13->LargeImageIndex = 21;
			this->bEncryptROT13->Name = L"bEncryptROT13";
			this->bEncryptROT13->ShowCaptionOnBar = false;
			this->bEncryptROT13->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormCreate::bEncryptROT13_ItemClick);
			// 
			// barStatus
			// 
			this->barStatus->BarName = L"barStatus";
			this->barStatus->CanDockStyle = DevExpress::XtraBars::BarCanDockStyle::Bottom;
			this->barStatus->DockCol = 0;
			this->barStatus->DockRow = 0;
			this->barStatus->DockStyle = DevExpress::XtraBars::BarDockStyle::Bottom;
			this->barStatus->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(1) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->sStatus))});
			this->barStatus->OptionsBar->AllowQuickCustomization = false;
			this->barStatus->OptionsBar->DisableClose = true;
			this->barStatus->OptionsBar->DisableCustomization = true;
			this->barStatus->OptionsBar->DrawDragBorder = false;
			this->barStatus->OptionsBar->DrawSizeGrip = true;
			this->barStatus->OptionsBar->UseWholeRow = true;
			this->barStatus->Text = L"Status";
			// 
			// sStatus
			// 
			this->sStatus->Border = DevExpress::XtraEditors::Controls::BorderStyles::NoBorder;
			this->sStatus->Caption = L"Длина сообщения: 0";
			this->sStatus->Id = 32;
			this->sStatus->Name = L"sStatus";
			this->sStatus->TextAlignment = System::Drawing::StringAlignment::Near;
			// 
			// barFile
			// 
			this->barFile->BarName = L"barFile";
			this->barFile->DockCol = 0;
			this->barFile->DockRow = 1;
			this->barFile->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barFile->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(4) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSend)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSaveMessage)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSaveAsTemplate)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bPrint))});
		//	this->barFile->OptionsBar->AllowQuickCustomization = false;
		//	this->barFile->OptionsBar->DisableCustomization = true;
			this->barFile->Text = L"File";
			// 
			// barEdit
			// 
			this->barEdit->BarName = L"barEdit";
			this->barEdit->DockCol = 1;
			this->barEdit->DockRow = 1;
			this->barEdit->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barEdit->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(5) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bUndo)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bCut, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bCopy)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bPaste)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bFind, true))});
			this->barEdit->Offset = 11;
	//		this->barEdit->OptionsBar->AllowQuickCustomization = false;
	//		this->barEdit->OptionsBar->DisableCustomization = true;
			this->barEdit->Text = L"Edit";
			// 
			// barInsert
			// 
			this->barInsert->BarName = L"barInsert";
			this->barInsert->DockCol = 2;
			this->barInsert->DockRow = 1;
			this->barInsert->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barInsert->FloatLocation = System::Drawing::Point(198, 215);
			this->barInsert->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(4) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAttachFile)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bTextFromFile)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bQuoteFromFile)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bUUEncode))});
			this->barInsert->Offset = 51;
	//		this->barInsert->OptionsBar->AllowQuickCustomization = false;
	//		this->barInsert->OptionsBar->DisableCustomization = true;
			this->barInsert->Text = L"Insert";
			// 
			// barFormat
			// 
			this->barFormat->BarName = L"barFormat";
			this->barFormat->DockCol = 3;
			this->barFormat->DockRow = 1;
			this->barFormat->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barFormat->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(4) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bBold)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bReverse)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bItalic)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bUnderline))});
			this->barFormat->Offset = 92;
	//		this->barFormat->OptionsBar->AllowQuickCustomization = false;
	//		this->barFormat->OptionsBar->DisableCustomization = true;
			this->barFormat->Text = L"Format";
			// 
			// barService
			// 
			this->barService->BarName = L"barService";
			this->barService->DockCol = 4;
			this->barService->DockRow = 1;
			this->barService->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barService->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(2) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSpellCheck)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bEncryptROT13))});
			this->barService->Offset = 127;
			this->barService->Text = L"Service";
			// 
			// lSpelling
			// 
			this->lSpelling->Id = 666;
			this->lSpelling->Name = L"lSpelling";
			this->lSpelling->ShowChecks = true;
			this->lSpelling->ListItemClick += gcnew DevExpress::XtraBars::ListItemClickEventHandler(this, &FormCreate::lSpelling_ListItemClick);
			// 
			// pccDAddr
			// 
			this->pccDAddr->Appearance->BackColor = System::Drawing::SystemColors::Control;
			this->pccDAddr->Appearance->Options->UseBackColor = true;
			this->pccDAddr->Controls->Add(this->pnlList);
			this->pccDAddr->Controls->Add(this->pnlFind);
			this->pccDAddr->Location = System::Drawing::Point(496, 40);
			this->pccDAddr->Name = L"pccDAddr";
			this->pccDAddr->Size = System::Drawing::Size(168, 124);
			this->pccDAddr->TabIndex = 53;
			// 
			// pnlList
			// 
			this->pnlList->Controls->Add(this->tlDAddr);
			this->pnlList->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pnlList->Location = System::Drawing::Point(0, 0);
			this->pnlList->Name = L"pnlList";
			this->pnlList->Size = System::Drawing::Size(168, 105);
			this->pnlList->TabIndex = 2;
			// 
			// tlDAddr
			// 
			this->tlDAddr->Columns->AddRange(gcnew cli::array< DevExpress::XtraTreeList::Columns::TreeListColumn^  >(5) {this->tlcDAddr, 
				this->tlcStation, this->tlcPlace, this->tlcDName, this->tlcPhone});
			this->tlDAddr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tlDAddr->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(204)));
			this->tlDAddr->Location = System::Drawing::Point(0, 0);
			this->tlDAddr->Name = L"tlDAddr";
			this->tlDAddr->OptionsBehavior->AutoMoveRowFocus = true;
			this->tlDAddr->OptionsBehavior->Editable = false;
			this->tlDAddr->OptionsBehavior->ExpandNodeOnDrag = false;
			this->tlDAddr->OptionsBehavior->MoveOnEdit = false;
			this->tlDAddr->OptionsBehavior->ResizeNodes = false;
			this->tlDAddr->OptionsBehavior->ShowToolTips = false;
			this->tlDAddr->OptionsMenu->EnableFooterMenu = false;
			this->tlDAddr->OptionsView->AutoWidth = false;
			this->tlDAddr->OptionsView->EnableAppearanceEvenRow = true;
			this->tlDAddr->OptionsView->EnableAppearanceOddRow = true;
			this->tlDAddr->OptionsView->ShowHorzLines = false;
			this->tlDAddr->OptionsView->ShowIndicator = false;
			this->tlDAddr->ShowButtonMode = DevExpress::XtraTreeList::ShowButtonModeEnum::ShowAlways;
			this->tlDAddr->Size = System::Drawing::Size(168, 105);
			this->tlDAddr->TabIndex = 1;
			this->tlDAddr->FocusedNodeChanged += gcnew DevExpress::XtraTreeList::FocusedNodeChangedEventHandler(this, &FormCreate::tlDAddr_FocusedNodeChanged);
			// 
			// tlcDAddr
			// 
			this->tlcDAddr->Caption = L"Адрес";
			this->tlcDAddr->FieldName = L"DAddr";
			this->tlcDAddr->Name = L"tlcDAddr";
			this->tlcDAddr->OptionsColumn->AllowFocus = false;
			this->tlcDAddr->OptionsColumn->ReadOnly = true;
			this->tlcDAddr->Visible = true;
			this->tlcDAddr->VisibleIndex = 0;
			this->tlcDAddr->Width = 150;
			// 
			// tlcStation
			// 
			this->tlcStation->Caption = L"Станция";
			this->tlcStation->FieldName = L"Station";
			this->tlcStation->Name = L"tlcStation";
			this->tlcStation->OptionsColumn->AllowFocus = false;
			this->tlcStation->OptionsColumn->ReadOnly = true;
			this->tlcStation->Visible = true;
			this->tlcStation->VisibleIndex = 1;
			this->tlcStation->Width = 128;
			// 
			// tlcPlace
			// 
			this->tlcPlace->Caption = L"Место";
			this->tlcPlace->FieldName = L"Place";
			this->tlcPlace->Name = L"tlcPlace";
			this->tlcPlace->OptionsColumn->AllowFocus = false;
			this->tlcPlace->OptionsColumn->ReadOnly = true;
			this->tlcPlace->Visible = true;
			this->tlcPlace->VisibleIndex = 2;
			this->tlcPlace->Width = 128;
			// 
			// tlcDName
			// 
			this->tlcDName->Caption = L"Имя";
			this->tlcDName->FieldName = L"DName";
			this->tlcDName->Name = L"tlcDName";
			this->tlcDName->OptionsColumn->AllowFocus = false;
			this->tlcDName->OptionsColumn->ReadOnly = true;
			this->tlcDName->Visible = true;
			this->tlcDName->VisibleIndex = 3;
			this->tlcDName->Width = 128;
			// 
			// tlcPhone
			// 
			this->tlcPhone->Caption = L"Номер";
			this->tlcPhone->FieldName = L"Phone";
			this->tlcPhone->Name = L"tlcPhone";
			this->tlcPhone->OptionsColumn->AllowFocus = false;
			this->tlcPhone->OptionsColumn->ReadOnly = true;
			this->tlcPhone->Visible = true;
			this->tlcPhone->VisibleIndex = 4;
			this->tlcPhone->Width = 100;
			// 
			// pnlFind
			// 
			this->pnlFind->Controls->Add(this->teDAddr);
			this->pnlFind->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->pnlFind->Location = System::Drawing::Point(0, 105);
			this->pnlFind->Name = L"pnlFind";
			this->pnlFind->Size = System::Drawing::Size(168, 19);
			this->pnlFind->TabIndex = 1;
			// 
			// teDAddr
			// 
			this->teDAddr->Dock = System::Windows::Forms::DockStyle::Fill;
			this->teDAddr->EditValue = L"0:0/0.0";
			this->teDAddr->Location = System::Drawing::Point(0, 0);
			this->teDAddr->Name = L"teDAddr";
			this->teDAddr->Properties->Mask->BeepOnError = true;
			this->teDAddr->Properties->Mask->EditMask = L"\\d{1,5}:\\d{1,5}/\\d{1,5}(\\.\\d{1,5})\?";
			this->teDAddr->Properties->Mask->MaskType = DevExpress::XtraEditors::Mask::MaskType::RegEx;
			this->teDAddr->Size = System::Drawing::Size(168, 20);
			this->teDAddr->TabIndex = 0;
			this->teDAddr->EditValueChanged += gcnew System::EventHandler(this, &FormCreate::teDAddr_EditValueChanged);
			// 
			// pccAttributes
			// 
			this->pccAttributes->Controls->Add(this->clbAttributes);
			this->pccAttributes->Location = System::Drawing::Point(80, 16);
			this->pccAttributes->Name = L"pccAttributes";
			this->pccAttributes->Size = System::Drawing::Size(480, 88);
			this->pccAttributes->TabIndex = 1;
			// 
			// clbAttributes
			// 
			this->clbAttributes->CheckOnClick = true;
			this->clbAttributes->Dock = System::Windows::Forms::DockStyle::Fill;
			this->clbAttributes->ItemHeight = 17;
			this->clbAttributes->Items->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::CheckedListBoxItem^  >(18) {(gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), 
				(gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), (gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), 
				(gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), (gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), 
				(gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), (gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), 
				(gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), (gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), 
				(gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), (gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), 
				(gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), (gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), 
				(gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), (gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), 
				(gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), (gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0)), 
				(gcnew DevExpress::XtraEditors::Controls::CheckedListBoxItem(0))});
			this->clbAttributes->Location = System::Drawing::Point(0, 0);
			this->clbAttributes->Name = L"clbAttributes";
			this->clbAttributes->Size = System::Drawing::Size(480, 88);
			this->clbAttributes->TabIndex = 0;
			// 
			// pccArea
			// 
			this->pccArea->Appearance->BackColor = System::Drawing::SystemColors::Control;
			this->pccArea->Appearance->Options->UseBackColor = true;
			this->pccArea->Controls->Add(this->tlArea);
			this->pccArea->Location = System::Drawing::Point(80, 0);
			this->pccArea->Name = L"pccArea";
			this->pccArea->Size = System::Drawing::Size(480, 88);
			this->pccArea->TabIndex = 52;
			// 
			// tlArea
			// 
			this->tlArea->Columns->AddRange(gcnew cli::array< DevExpress::XtraTreeList::Columns::TreeListColumn^  >(8) {this->tlcName, 
				this->tlcDescription, this->tlcPath, this->tlcAddress, this->tlcBaseType, this->tlcAreaType, this->tlcNode, this->tlcMark});
			this->tlArea->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tlArea->Location = System::Drawing::Point(0, 0);
			this->tlArea->Name = L"tlArea";
			this->tlArea->OptionsBehavior->AutoMoveRowFocus = true;
			this->tlArea->OptionsBehavior->ExpandNodeOnDrag = false;
			this->tlArea->OptionsBehavior->MoveOnEdit = false;
			this->tlArea->OptionsBehavior->ResizeNodes = false;
			this->tlArea->OptionsBehavior->ShowToolTips = false;
			this->tlArea->OptionsMenu->EnableFooterMenu = false;
			this->tlArea->OptionsView->EnableAppearanceEvenRow = true;
			this->tlArea->OptionsView->EnableAppearanceOddRow = true;
			this->tlArea->OptionsView->ShowHorzLines = false;
			this->tlArea->OptionsView->ShowIndicator = false;
			this->tlArea->ShowButtonMode = DevExpress::XtraTreeList::ShowButtonModeEnum::ShowAlways;
			this->tlArea->Size = System::Drawing::Size(480, 88);
			this->tlArea->TabIndex = 0;
			this->tlArea->GetCustomNodeCellEdit += gcnew DevExpress::XtraTreeList::GetCustomNodeCellEditEventHandler(this, &FormCreate::tlArea_GetCustomNodeCellEdit);
			this->tlArea->BeforeFocusNode += gcnew DevExpress::XtraTreeList::BeforeFocusNodeEventHandler(this, &FormCreate::tlArea_BeforeFocusNode);
			// 
			// tlcName
			// 
			this->tlcName->Caption = L"Название";
			this->tlcName->FieldName = L"Name";
			this->tlcName->Name = L"tlcName";
			this->tlcName->OptionsColumn->AllowFocus = false;
			this->tlcName->OptionsColumn->AllowSort = false;
			this->tlcName->OptionsColumn->ReadOnly = true;
			this->tlcName->Visible = true;
			this->tlcName->VisibleIndex = 0;
			this->tlcName->Width = 170;
			// 
			// tlcDescription
			// 
			this->tlcDescription->Caption = L"Описание";
			this->tlcDescription->FieldName = L"Description";
			this->tlcDescription->Name = L"tlcDescription";
			this->tlcDescription->OptionsColumn->AllowFocus = false;
			this->tlcDescription->OptionsColumn->AllowSort = false;
			this->tlcDescription->OptionsColumn->ReadOnly = true;
			this->tlcDescription->Visible = true;
			this->tlcDescription->VisibleIndex = 2;
			// 
			// tlcPath
			// 
			this->tlcPath->Caption = L"Путь";
			this->tlcPath->FieldName = L"Path";
			this->tlcPath->Name = L"tlcPath";
			this->tlcPath->OptionsColumn->AllowFocus = false;
			this->tlcPath->OptionsColumn->AllowSort = false;
			this->tlcPath->OptionsColumn->ReadOnly = true;
			this->tlcPath->Visible = true;
			this->tlcPath->VisibleIndex = 3;
			// 
			// tlcAddress
			// 
			this->tlcAddress->Caption = L"Ваш адрес";
			this->tlcAddress->FieldName = L"Address";
			this->tlcAddress->Name = L"tlcAddress";
			this->tlcAddress->OptionsColumn->AllowFocus = false;
			this->tlcAddress->OptionsColumn->AllowSort = false;
			this->tlcAddress->OptionsColumn->ReadOnly = true;
			this->tlcAddress->Visible = true;
			this->tlcAddress->VisibleIndex = 4;
			// 
			// tlcBaseType
			// 
			this->tlcBaseType->Caption = L"Тип базы";
			this->tlcBaseType->FieldName = L"BaseType";
			this->tlcBaseType->Name = L"tlcBaseType";
			this->tlcBaseType->OptionsColumn->AllowFocus = false;
			this->tlcBaseType->OptionsColumn->AllowSort = false;
			this->tlcBaseType->OptionsColumn->ReadOnly = true;
			this->tlcBaseType->Visible = true;
			this->tlcBaseType->VisibleIndex = 5;
			// 
			// tlcAreaType
			// 
			this->tlcAreaType->Caption = L"Тип области";
			this->tlcAreaType->FieldName = L"AreaType";
			this->tlcAreaType->Name = L"tlcAreaType";
			this->tlcAreaType->OptionsColumn->AllowFocus = false;
			this->tlcAreaType->OptionsColumn->AllowSort = false;
			this->tlcAreaType->OptionsColumn->ReadOnly = true;
			this->tlcAreaType->Visible = true;
			this->tlcAreaType->VisibleIndex = 6;
			// 
			// tlcNode
			// 
			this->tlcNode->FieldName = L"Node";
			this->tlcNode->Name = L"tlcNode";
			this->tlcNode->OptionsColumn->AllowFocus = false;
			this->tlcNode->OptionsColumn->AllowMove = false;
			this->tlcNode->OptionsColumn->AllowSize = false;
			this->tlcNode->OptionsColumn->AllowSort = false;
			this->tlcNode->OptionsColumn->ShowInCustomizationForm = false;
			this->tlcNode->Visible = true;
			this->tlcNode->Width = 170;
			// 
			// tlcMark
			// 
			this->tlcMark->FieldName = L"Mark";
			this->tlcMark->Name = L"tlcMark";
			this->tlcMark->OptionsColumn->AllowFocus = false;
			this->tlcMark->OptionsColumn->AllowSort = false;
			this->tlcMark->Visible = true;
			this->tlcMark->VisibleIndex = 1;
			this->tlcMark->Width = 18;
			// 
			// pmEdit
			// 
			this->pmEdit->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(8) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->lSpelling)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bUndo, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bCut, 
				true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bCopy)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bPaste)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSelectAll)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bFind, 
				true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bReplace))});
			this->pmEdit->Manager = this->barManager;
			this->pmEdit->Name = L"pmEdit";
			// 
			// rche
			// 
			this->rche->AutoHeight = false;
			this->rche->Name = L"rche";
			this->rche->NullStyle = DevExpress::XtraEditors::Controls::StyleIndeterminate::Unchecked;
			// 
			// rtero
			// 
			this->rtero->AutoHeight = false;
			this->rtero->Name = L"rtero";
			this->rtero->ReadOnly = true;
			// 
			// rtText
			// 
			this->rtText->BackColor = System::Drawing::SystemColors::Window;
			this->rtText->Cursor = System::Windows::Forms::Cursors::IBeam;
			this->rtText->EditMargin->Position = 79;
			this->rtText->EditMargin->Visible = true;
			this->rtText->Font = (gcnew System::Drawing::Font(L"Courier New", 10));
			this->rtText->Gutter->Visible = false;
			this->rtText->Lexer = this->parMessage;
			this->rtText->Location = System::Drawing::Point(7, 193);
			this->rtText->Name = L"rtText";
			this->rtText->Size = System::Drawing::Size(662, 164);
			this->rtText->TabIndex = 12;
			this->rtText->Text = L"";
			this->rtText->UseDefaultMenu = false;
			this->rtText->WordWrap = true;
			this->rtText->WrapAtMargin = true;
			this->rtText->WordSpell += gcnew QWhale::Editor::WordSpellEvent(this, &FormCreate::rtText_WordSpell);
			this->rtText->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FormCreate::rtText_MouseUp);
			this->rtText->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormCreate::rtText_KeyDown);
			// 
			// parMessage
			// 
			this->parMessage->DefaultState = 0;
			this->parMessage->XmlScheme = resources->GetString(L"parMessage.XmlScheme");
			// 
			// LayoutControl
			// 
			this->LayoutControl->Controls->Add(this->pceAttributes);
			this->LayoutControl->Controls->Add(this->teReceived);
			this->LayoutControl->Controls->Add(this->deReceived);
			this->LayoutControl->Controls->Add(this->teWritten);
			this->LayoutControl->Controls->Add(this->deWritten);
			this->LayoutControl->Controls->Add(this->teSubject);
			this->LayoutControl->Controls->Add(this->pceToAddress);
			this->LayoutControl->Controls->Add(this->teTo);
			this->LayoutControl->Controls->Add(this->cbeFromAddress);
			this->LayoutControl->Controls->Add(this->cbeFrom);
			this->LayoutControl->Controls->Add(this->pceArea);
			this->LayoutControl->Controls->Add(this->cbeOrigin);
			this->LayoutControl->Controls->Add(this->teOriginEnd);
			this->LayoutControl->Controls->Add(this->teOriginBegin);
			this->LayoutControl->Controls->Add(this->rtText);
			this->LayoutControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LayoutControl->Location = System::Drawing::Point(0, 49);
			this->LayoutControl->Name = L"LayoutControl";
			this->LayoutControl->Root = this->lcgMain;
			this->LayoutControl->Size = System::Drawing::Size(675, 393);
			this->LayoutControl->TabIndex = 13;
			this->LayoutControl->Text = L"layoutControl1";
			// 
			// pceAttributes
			// 
			this->pceAttributes->Location = System::Drawing::Point(67, 162);
			this->pceAttributes->Name = L"pceAttributes";
			this->pceAttributes->Properties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->pceAttributes->Properties->PopupControl = this->pccAttributes;
			this->pceAttributes->Size = System::Drawing::Size(602, 20);
			this->pceAttributes->StyleController = this->LayoutControl;
			this->pceAttributes->TabIndex = 25;
			this->pceAttributes->QueryResultValue += gcnew DevExpress::XtraEditors::Controls::QueryResultValueEventHandler(this, &FormCreate::pceAttributes_QueryResultValue);
			// 
			// teReceived
			// 
			this->teReceived->EditValue = System::DateTime(2008, 3, 4, 0, 0, 0, 0);
			this->teReceived->Location = System::Drawing::Point(534, 131);
			this->teReceived->Name = L"teReceived";
			this->teReceived->Properties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton())});
			this->teReceived->Size = System::Drawing::Size(135, 20);
			this->teReceived->StyleController = this->LayoutControl;
			this->teReceived->TabIndex = 24;
			// 
			// deReceived
			// 
			this->deReceived->EditValue = nullptr;
			this->deReceived->Location = System::Drawing::Point(394, 131);
			this->deReceived->Name = L"deReceived";
			this->deReceived->Properties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->deReceived->Properties->VistaTimeProperties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton())});
			this->deReceived->Size = System::Drawing::Size(129, 20);
			this->deReceived->StyleController = this->LayoutControl;
			this->deReceived->TabIndex = 23;
			// 
			// teWritten
			// 
			this->teWritten->EditValue = System::DateTime(2008, 3, 4, 0, 0, 0, 0);
			this->teWritten->Location = System::Drawing::Point(192, 131);
			this->teWritten->Name = L"teWritten";
			this->teWritten->Properties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton())});
			this->teWritten->Size = System::Drawing::Size(131, 20);
			this->teWritten->StyleController = this->LayoutControl;
			this->teWritten->TabIndex = 22;
			// 
			// deWritten
			// 
			this->deWritten->EditValue = nullptr;
			this->deWritten->Location = System::Drawing::Point(67, 131);
			this->deWritten->Name = L"deWritten";
			this->deWritten->Properties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->deWritten->Properties->VistaTimeProperties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton())});
			this->deWritten->Size = System::Drawing::Size(114, 20);
			this->deWritten->StyleController = this->LayoutControl;
			this->deWritten->TabIndex = 21;
			// 
			// teSubject
			// 
			this->teSubject->Location = System::Drawing::Point(67, 100);
			this->teSubject->Name = L"teSubject";
			this->teSubject->Size = System::Drawing::Size(602, 20);
			this->teSubject->StyleController = this->LayoutControl;
			this->teSubject->TabIndex = 20;
			this->teSubject->EditValueChanged += gcnew System::EventHandler(this, &FormCreate::teSubject_EditValueChanged);
			// 
			// pceToAddress
			// 
			this->pceToAddress->Location = System::Drawing::Point(534, 69);
			this->pceToAddress->Name = L"pceToAddress";
			this->pceToAddress->Properties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->pceToAddress->Properties->PopupControl = this->pccDAddr;
			this->pceToAddress->Size = System::Drawing::Size(135, 20);
			this->pceToAddress->StyleController = this->LayoutControl;
			this->pceToAddress->TabIndex = 19;
			this->pceToAddress->QueryResultValue += gcnew DevExpress::XtraEditors::Controls::QueryResultValueEventHandler(this, &FormCreate::pceToAddress_QueryResultValue);
			// 
			// teTo
			// 
			this->teTo->Location = System::Drawing::Point(67, 69);
			this->teTo->Name = L"teTo";
			this->teTo->Size = System::Drawing::Size(456, 20);
			this->teTo->StyleController = this->LayoutControl;
			this->teTo->TabIndex = 18;
			// 
			// cbeFromAddress
			// 
			this->cbeFromAddress->Location = System::Drawing::Point(534, 38);
			this->cbeFromAddress->Name = L"cbeFromAddress";
			this->cbeFromAddress->Properties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->cbeFromAddress->Size = System::Drawing::Size(135, 20);
			this->cbeFromAddress->StyleController = this->LayoutControl;
			this->cbeFromAddress->TabIndex = 17;
			this->cbeFromAddress->EditValueChanged += gcnew System::EventHandler(this, &FormCreate::cbeFromAddress_EditValueChanged);
			// 
			// cbeFrom
			// 
			this->cbeFrom->Location = System::Drawing::Point(67, 38);
			this->cbeFrom->Name = L"cbeFrom";
			this->cbeFrom->Properties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->cbeFrom->Properties->MaxLength = 36;
			this->cbeFrom->Size = System::Drawing::Size(456, 20);
			this->cbeFrom->StyleController = this->LayoutControl;
			this->cbeFrom->TabIndex = 16;
			// 
			// pceArea
			// 
			this->pceArea->Location = System::Drawing::Point(67, 7);
			this->pceArea->Name = L"pceArea";
			this->pceArea->Properties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->pceArea->Properties->PopupControl = this->pccArea;
			this->pceArea->Size = System::Drawing::Size(602, 20);
			this->pceArea->StyleController = this->LayoutControl;
			this->pceArea->TabIndex = 15;
			this->pceArea->EditValueChanged += gcnew System::EventHandler(this, &FormCreate::pceArea_EditValueChanged);
			this->pceArea->QueryResultValue += gcnew DevExpress::XtraEditors::Controls::QueryResultValueEventHandler(this, &FormCreate::pceArea_QueryResultValue);
			// 
			// cbeOrigin
			// 
			this->cbeOrigin->Location = System::Drawing::Point(129, 368);
			this->cbeOrigin->Name = L"cbeOrigin";
			this->cbeOrigin->Properties->Appearance->Font = (gcnew System::Drawing::Font(L"Lucida Console", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->cbeOrigin->Properties->Appearance->Options->UseFont = true;
			this->cbeOrigin->Properties->BorderStyle = DevExpress::XtraEditors::Controls::BorderStyles::Simple;
			this->cbeOrigin->Properties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->cbeOrigin->Size = System::Drawing::Size(399, 19);
			this->cbeOrigin->StyleController = this->LayoutControl;
			this->cbeOrigin->TabIndex = 14;
			// 
			// teOriginEnd
			// 
			this->teOriginEnd->EditValue = L"";
			this->teOriginEnd->Location = System::Drawing::Point(539, 368);
			this->teOriginEnd->Name = L"teOriginEnd";
			this->teOriginEnd->Properties->Appearance->Font = (gcnew System::Drawing::Font(L"Lucida Console", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->teOriginEnd->Properties->Appearance->Options->UseFont = true;
			this->teOriginEnd->Properties->BorderStyle = DevExpress::XtraEditors::Controls::BorderStyles::Simple;
			this->teOriginEnd->Properties->ReadOnly = true;
			this->teOriginEnd->Size = System::Drawing::Size(130, 19);
			this->teOriginEnd->StyleController = this->LayoutControl;
			this->teOriginEnd->TabIndex = 14;
			// 
			// teOriginBegin
			// 
			this->teOriginBegin->EditValue = L" * Origin:";
			this->teOriginBegin->Location = System::Drawing::Point(7, 368);
			this->teOriginBegin->Name = L"teOriginBegin";
			this->teOriginBegin->Properties->Appearance->Font = (gcnew System::Drawing::Font(L"Lucida Console", 9.75F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->teOriginBegin->Properties->Appearance->Options->UseFont = true;
			this->teOriginBegin->Properties->BorderStyle = DevExpress::XtraEditors::Controls::BorderStyles::Simple;
			this->teOriginBegin->Properties->ReadOnly = true;
			this->teOriginBegin->Size = System::Drawing::Size(111, 19);
			this->teOriginBegin->StyleController = this->LayoutControl;
			this->teOriginBegin->TabIndex = 14;
			// 
			// lcgMain
			// 
			this->lcgMain->CustomizationFormText = L"Root";
			this->lcgMain->Items->AddRange(gcnew cli::array< DevExpress::XtraLayout::BaseLayoutItem^  >(15) {this->lciText, this->lciOriginBegin, 
				this->lciOriginEnd, this->lciOrigin, this->lciArea, this->lciFrom, this->lciFromAddress, this->lciTo, this->lciToAddress, this->lciSubject, 
				this->lciWritten, this->lciWrittenTime, this->lciReceived, this->lciReceivedTime, this->lciAttributes});
			this->lcgMain->Location = System::Drawing::Point(0, 0);
			this->lcgMain->Name = L"lcgMain";
			this->lcgMain->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lcgMain->Size = System::Drawing::Size(675, 393);
			this->lcgMain->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lcgMain->Text = L"lcgMain";
			this->lcgMain->TextVisible = false;
			// 
			// lciText
			// 
			this->lciText->Control = this->rtText;
			this->lciText->CustomizationFormText = L"Текст:";
			this->lciText->Location = System::Drawing::Point(0, 186);
			this->lciText->Name = L"lciText";
			this->lciText->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciText->Size = System::Drawing::Size(673, 175);
			this->lciText->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciText->Text = L"Текст:";
			this->lciText->TextSize = System::Drawing::Size(0, 0);
			this->lciText->TextToControlDistance = 0;
			this->lciText->TextVisible = false;
			// 
			// lciOriginBegin
			// 
			this->lciOriginBegin->Control = this->teOriginBegin;
			this->lciOriginBegin->CustomizationFormText = L"Начало ориджина";
			this->lciOriginBegin->Location = System::Drawing::Point(0, 361);
			this->lciOriginBegin->Name = L"lciOriginBegin";
			this->lciOriginBegin->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciOriginBegin->Size = System::Drawing::Size(122, 30);
			this->lciOriginBegin->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciOriginBegin->Text = L"Начало ориджина";
			this->lciOriginBegin->TextSize = System::Drawing::Size(0, 0);
			this->lciOriginBegin->TextToControlDistance = 0;
			this->lciOriginBegin->TextVisible = false;
			// 
			// lciOriginEnd
			// 
			this->lciOriginEnd->Control = this->teOriginEnd;
			this->lciOriginEnd->CustomizationFormText = L"Конец ориджина";
			this->lciOriginEnd->Location = System::Drawing::Point(532, 361);
			this->lciOriginEnd->Name = L"lciOriginEnd";
			this->lciOriginEnd->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciOriginEnd->Size = System::Drawing::Size(141, 30);
			this->lciOriginEnd->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciOriginEnd->Text = L"Конец ориджина";
			this->lciOriginEnd->TextSize = System::Drawing::Size(0, 0);
			this->lciOriginEnd->TextToControlDistance = 0;
			this->lciOriginEnd->TextVisible = false;
			// 
			// lciOrigin
			// 
			this->lciOrigin->Control = this->cbeOrigin;
			this->lciOrigin->CustomizationFormText = L"Ориджин";
			this->lciOrigin->Location = System::Drawing::Point(122, 361);
			this->lciOrigin->Name = L"lciOrigin";
			this->lciOrigin->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciOrigin->Size = System::Drawing::Size(410, 30);
			this->lciOrigin->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciOrigin->Text = L"Ориджин";
			this->lciOrigin->TextSize = System::Drawing::Size(0, 0);
			this->lciOrigin->TextToControlDistance = 0;
			this->lciOrigin->TextVisible = false;
			// 
			// lciArea
			// 
			this->lciArea->Control = this->pceArea;
			this->lciArea->CustomizationFormText = L"Область:";
			this->lciArea->Location = System::Drawing::Point(0, 0);
			this->lciArea->Name = L"lciArea";
			this->lciArea->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciArea->Size = System::Drawing::Size(673, 31);
			this->lciArea->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciArea->Text = L"Область:";
			this->lciArea->TextSize = System::Drawing::Size(55, 20);
			// 
			// lciFrom
			// 
			this->lciFrom->Control = this->cbeFrom;
			this->lciFrom->CustomizationFormText = L"От:";
			this->lciFrom->Location = System::Drawing::Point(0, 31);
			this->lciFrom->Name = L"lciFrom";
			this->lciFrom->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciFrom->Size = System::Drawing::Size(527, 31);
			this->lciFrom->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciFrom->Text = L"От:";
			this->lciFrom->TextSize = System::Drawing::Size(55, 20);
			// 
			// lciFromAddress
			// 
			this->lciFromAddress->Control = this->cbeFromAddress;
			this->lciFromAddress->CustomizationFormText = L"Адрес отправителя:";
			this->lciFromAddress->Location = System::Drawing::Point(527, 31);
			this->lciFromAddress->Name = L"lciFromAddress";
			this->lciFromAddress->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciFromAddress->Size = System::Drawing::Size(146, 31);
			this->lciFromAddress->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciFromAddress->Text = L"Адрес отправителя:";
			this->lciFromAddress->TextSize = System::Drawing::Size(0, 0);
			this->lciFromAddress->TextToControlDistance = 0;
			this->lciFromAddress->TextVisible = false;
			// 
			// lciTo
			// 
			this->lciTo->Control = this->teTo;
			this->lciTo->CustomizationFormText = L"Кому:";
			this->lciTo->Location = System::Drawing::Point(0, 62);
			this->lciTo->Name = L"lciTo";
			this->lciTo->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciTo->Size = System::Drawing::Size(527, 31);
			this->lciTo->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciTo->Text = L"Кому:";
			this->lciTo->TextSize = System::Drawing::Size(55, 20);
			// 
			// lciToAddress
			// 
			this->lciToAddress->Control = this->pceToAddress;
			this->lciToAddress->CustomizationFormText = L"Адрес получателя:";
			this->lciToAddress->Location = System::Drawing::Point(527, 62);
			this->lciToAddress->Name = L"lciToAddress";
			this->lciToAddress->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciToAddress->Size = System::Drawing::Size(146, 31);
			this->lciToAddress->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciToAddress->Text = L"Адрес получателя:";
			this->lciToAddress->TextSize = System::Drawing::Size(0, 0);
			this->lciToAddress->TextToControlDistance = 0;
			this->lciToAddress->TextVisible = false;
			// 
			// lciSubject
			// 
			this->lciSubject->Control = this->teSubject;
			this->lciSubject->CustomizationFormText = L"Тема:";
			this->lciSubject->Location = System::Drawing::Point(0, 93);
			this->lciSubject->Name = L"lciSubject";
			this->lciSubject->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciSubject->Size = System::Drawing::Size(673, 31);
			this->lciSubject->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciSubject->Text = L"Тема:";
			this->lciSubject->TextSize = System::Drawing::Size(55, 20);
			// 
			// lciWritten
			// 
			this->lciWritten->Control = this->deWritten;
			this->lciWritten->CustomizationFormText = L"Написано:";
			this->lciWritten->Location = System::Drawing::Point(0, 124);
			this->lciWritten->Name = L"lciWritten";
			this->lciWritten->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciWritten->Size = System::Drawing::Size(185, 31);
			this->lciWritten->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciWritten->Text = L"Написано:";
			this->lciWritten->TextSize = System::Drawing::Size(55, 20);
			// 
			// lciWrittenTime
			// 
			this->lciWrittenTime->Control = this->teWritten;
			this->lciWrittenTime->CustomizationFormText = L"Написано (время):";
			this->lciWrittenTime->Location = System::Drawing::Point(185, 124);
			this->lciWrittenTime->Name = L"lciWrittenTime";
			this->lciWrittenTime->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciWrittenTime->Size = System::Drawing::Size(142, 31);
			this->lciWrittenTime->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciWrittenTime->Text = L"Написано (время):";
			this->lciWrittenTime->TextSize = System::Drawing::Size(0, 0);
			this->lciWrittenTime->TextToControlDistance = 0;
			this->lciWrittenTime->TextVisible = false;
			// 
			// lciReceived
			// 
			this->lciReceived->Control = this->deReceived;
			this->lciReceived->CustomizationFormText = L"Получено:";
			this->lciReceived->Location = System::Drawing::Point(327, 124);
			this->lciReceived->Name = L"lciReceived";
			this->lciReceived->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciReceived->Size = System::Drawing::Size(200, 31);
			this->lciReceived->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciReceived->Text = L"Получено:";
			this->lciReceived->TextSize = System::Drawing::Size(55, 20);
			// 
			// lciReceivedTime
			// 
			this->lciReceivedTime->Control = this->teReceived;
			this->lciReceivedTime->CustomizationFormText = L"Получено (время):";
			this->lciReceivedTime->Location = System::Drawing::Point(527, 124);
			this->lciReceivedTime->Name = L"lciReceivedTime";
			this->lciReceivedTime->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciReceivedTime->Size = System::Drawing::Size(146, 31);
			this->lciReceivedTime->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciReceivedTime->Text = L"Получено (время):";
			this->lciReceivedTime->TextSize = System::Drawing::Size(0, 0);
			this->lciReceivedTime->TextToControlDistance = 0;
			this->lciReceivedTime->TextVisible = false;
			// 
			// lciAttributes
			// 
			this->lciAttributes->Control = this->pceAttributes;
			this->lciAttributes->CustomizationFormText = L"Атрибуты:";
			this->lciAttributes->Location = System::Drawing::Point(0, 155);
			this->lciAttributes->Name = L"lciAttributes";
			this->lciAttributes->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciAttributes->Size = System::Drawing::Size(673, 31);
			this->lciAttributes->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciAttributes->Text = L"Атрибуты:";
			this->lciAttributes->TextSize = System::Drawing::Size(55, 20);
			// 
			// FormCreate
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->ClientSize = System::Drawing::Size(675, 464);
			this->Controls->Add(this->LayoutControl);
			this->Controls->Add(this->barDockControlLeft);
			this->Controls->Add(this->barDockControlRight);
			this->Controls->Add(this->barDockControlBottom);
			this->Controls->Add(this->barDockControlTop);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"FormCreate";
			this->Closed += gcnew System::EventHandler(this, &FormCreate::FormCreate_Closed);
			this->Closing += gcnew System::ComponentModel::CancelEventHandler(this, &FormCreate::FormCreate_Closing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barManager))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pccDAddr))->EndInit();
			this->pccDAddr->ResumeLayout(false);
			this->pnlList->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlDAddr))->EndInit();
			this->pnlFind->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teDAddr->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pccAttributes))->EndInit();
			this->pccAttributes->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->clbAttributes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pccArea))->EndInit();
			this->pccArea->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlArea))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmEdit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rche))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rtero))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->LayoutControl))->EndInit();
			this->LayoutControl->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pceAttributes->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teReceived->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->deReceived->Properties->VistaTimeProperties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->deReceived->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teWritten->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->deWritten->Properties->VistaTimeProperties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->deWritten->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teSubject->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pceToAddress->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teTo->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cbeFromAddress->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cbeFrom->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pceArea->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cbeOrigin->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teOriginEnd->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teOriginBegin->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lcgMain))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciText))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciOriginBegin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciOriginEnd))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciOrigin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciArea))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciFrom))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciFromAddress))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciTo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciToAddress))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciSubject))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciWritten))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciWrittenTime))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciReceived))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciReceivedTime))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciAttributes))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		public:	FormCreate(FormSettings^ frm, DevExpress::XtraSpellChecker::SpellChecker^  sp)
		{
			InitializeComponent();
			Vers=string::Concat(System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Major,".",
			System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Minor,".",
			System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Build);
			
			fl=false;

			frmSettings = frm;
			spell=sp;
			HellEdDir = frmSettings->HellEdDir;
			string_length = Convert::ToInt64(frmSettings->tlConfigHED->FindNodeByKeyID(901)->GetValue(1));
			ConfigForms = gcnew Config();
			LoadConfigSkin((string^)frmSettings->tlConfigHED->FindNodeByKeyID(501)->GetValue(1));
			LoadConfigForms();
			tlDAddr->DataSource = frmSettings->NodelistData;
			InitializehtLanguage();
			LoadConfigLanguage((string^)frmSettings->tlConfigHED->FindNodeByKeyID(601)->GetValue(1));
			rtText->EditMargin->Position=Convert::ToInt32(frmSettings->tlConfigHED->FindNodeByKeyID(901)->GetValue(1));
			array<string^> ^ strs;
			cbeFrom->Properties->Items->Clear();
			strs = ((string^)frmSettings->tlConfigHED->FindNodeByKeyID(101)->GetValue(1))->Split(((string^)L"\r\n")->ToCharArray());
			for(int i=0;i<strs->Length;i++)if (strs[i]!=""){cbeFrom->Properties->Items->Add(strs[i]);}
			if (cbeFrom->Properties->Items->Count==0){cbeFrom->Properties->Items->Add(L"");}
			oname = (string^)cbeFrom->Properties->Items[0];
			ParseName(oname,qbegin,ofname,omname,olname);

			cbeFromAddress->Properties->Items->Clear();
			strs = ((string^)frmSettings->tlConfigHED->FindNodeByKeyID(102)->GetValue(1))->Split(((string^)L"\r\n")->ToCharArray());
			for(int i=0;i<strs->Length;i++)if (strs[i]!=""){cbeFromAddress->Properties->Items->Add(strs[i]);}
			if (cbeFromAddress->Properties->Items->Count==0){cbeFromAddress->Properties->Items->Add(L"0:0/0.0");}
			oaddr=(string^)cbeFromAddress->Properties->Items[0];

			cbeOrigin->Properties->Items->Clear();
			strs = ((string^)frmSettings->tlConfigHED->FindNodeByKeyID(402)->GetValue(1))->Split(((string^)L"\r\n")->ToCharArray());
			for(int i=0;i<strs->Length;i++)if (strs[i]!=""){cbeOrigin->Properties->Items->Add(ProcessText(strs[i]));}
			if (cbeOrigin->Properties->Items->Count==0)
			{
				cbeOrigin->Properties->Items->Add(L"");
			}
			System::Random^ rnd = gcnew System::Random();
			cbeOrigin->EditValue = strs[rnd->Next(strs->Length)];
			cbeOrigin->Text = strs[rnd->Next(strs->Length)];
			rtText->Select();
		}
		public: void FormCreate_Closed(object^ sender, System::EventArgs^ e)
		{
/*			frmFindDialog->Close();
			frmReplaceDialog->Close();
			frmSpelling->Close();*/
		}
		public: void FormCreate_Closing(object^ sender, System::ComponentModel::CancelEventArgs^ e)
		{
			SaveConfigForms();
		}

		public: void tlArea_GetCustomNodeCellEdit(object^ sender, DevExpress::XtraTreeList::GetCustomNodeCellEditEventArgs^ e) 
		{
			if(e->Column->FieldName->Equals(L"Mark"))
			{
				if (e->Node->GetValue(6)->Equals(L"g"))
				{e->RepositoryItem = rtero;}
				else
				{e->RepositoryItem = rche;}
			}
		}
		public: void tlArea_BeforeFocusNode(object^ sender, DevExpress::XtraTreeList::BeforeFocusNodeEventArgs^ e)
		{
			this->tlcMark->Options = (DevExpress::XtraTreeList::Columns::ColumnOptions)(DevExpress::XtraTreeList::Columns::ColumnOptions::CanResized);
			if (e->Node->GetValue(6)->Equals(L""))
			{
				e->CanFocus = true;
				this->tlcMark->Options = (DevExpress::XtraTreeList::Columns::ColumnOptions)(DevExpress::XtraTreeList::Columns::ColumnOptions::CanResized | DevExpress::XtraTreeList::Columns::ColumnOptions::CanFocused);
			}
		}

		public: void cbeOrigin_EditValueChanged(object^ sender, System::EventArgs^ e)
		{
			if (cbeOrigin->Text->Length > string_length-14-oaddr->Length)
			{cbeOrigin->Text = cbeOrigin->Text->Substring(0,string_length-14-oaddr->Length);}
			origin = cbeOrigin->Text;
		}
		public: System::Void teSubject_EditValueChanged(System::Object^  sender, System::EventArgs^  e)
		{
			Text = string::Concat(htStrings[L"frmCreate"],teSubject->EditValue->ToString());
		}
		public: System::Void cbeFromAddress_EditValueChanged(System::Object^  sender, System::EventArgs^  e)
		{
			oaddr = (string^)cbeFromAddress->EditValue;
			teOriginEnd->Text=string::Concat(L"(",oaddr,L")");
			if (cbeOrigin->Text->Length > 64-oaddr->Length)
			{cbeOrigin->Text = cbeOrigin->Text->Substring(0,64-oaddr->Length);}		
		}
		public: System::Void pceArea_EditValueChanged(System::Object^  sender, System::EventArgs^  e)
		{
/*			if(tlArea->FocusedNode->GetValue(6)->Equals(L""))
			if(!tlArea->FocusedNode->GetValue(3)->Equals(L""))
			{
				oaddr = (string^)tlArea->FocusedNode->GetValue(3);
				tlHeader->FindNodeByID(1)->SetValue(oaddr,2);
			}*/
		}

		public: void pceArea_QueryResultValue(object^ sender, DevExpress::XtraEditors::Controls::QueryResultValueEventArgs^ e) 
		{
			string^ n=L"";
			for(int i=0;i<tlArea->AllNodesCount;i++)
			if (tlArea->FindNodeByID(i)->GetValue(7))
			if ((*dynamic_cast<bool^>(tlArea->FindNodeByID(i)->GetValue(7)))==true){n=string::Concat(n,(string^)tlArea->FindNodeByID(i)->GetValue(0),L" ");}
			e->Value = n->TrimEnd(((string^)L" ")->ToCharArray());
		}

		public: void pceToAddress_QueryResultValue(object^ sender, DevExpress::XtraEditors::Controls::QueryResultValueEventArgs^ e) 
		{
			e->Value = (string^)teDAddr->EditValue;
			pceToAddress->EditValue=teDAddr->EditValue;
			daddr = (string^)teDAddr->EditValue;
			if (tlDAddr->FindNodeByKeyID(teDAddr->EditValue))
			{
				teTo->EditValue=tlDAddr->FindNodeByKeyID(teDAddr->EditValue)->GetValue(3);
			}
		}
		
		public: void teDAddr_EditValueChanged(object^ sender, System::EventArgs^ e)
		{
			if (tlDAddr->FindNodeByKeyID(teDAddr->EditValue))
			{tlDAddr->SetFocusedNode(tlDAddr->FindNodeByKeyID(teDAddr->EditValue));}
		}
		public: void tlDAddr_FocusedNodeChanged(object^ sender, DevExpress::XtraTreeList::FocusedNodeChangedEventArgs^ e)
		{
			if ((e->Node)&&(fl))
			{
				teDAddr->Text=(string^)e->Node->GetValue(0);
			}
			else
			{
				teDAddr_EditValueChanged(nullptr,nullptr);
			}
			fl=true;
		}

		public: void bSend_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			Regex^ re = gcnew Regex(L"\\d{1,5}:\\d{1,5}/\\d{1,5}(\\.\\d{1,5})\?");
			Match^ m = re->Match((string^)teDAddr->EditValue);						
			if (!m->Success){teDAddr->EditValue=pceToAddress->EditValue;}

			oname = cbeFrom->Text;
			oaddr = cbeFromAddress->Text;
			dname = teTo->Text;
			daddr = pceToAddress->Text;
			subject = teSubject->Text;
			origin = cbeOrigin->Text;
			System::DateTime dt1 =*dynamic_cast<System::DateTime^>(deWritten->EditValue);
			System::DateTime dt2 =*dynamic_cast<System::DateTime^>(teWritten->EditValue);
			odatetime = System::DateTime(dt1.Year,
										 dt1.Month,
										 dt1.Day,
										 dt2.Hour,
										 dt2.Minute,
										 dt2.Second);
			char* mas = (char*)(void*)Marshal::StringToHGlobalAnsi(string::Concat(HellEdDir,L"\\temp"));
			dword umsgid = GenMsgId(mas, 3ul*365*24*60*60);
			Marshal::FreeHGlobal((System::IntPtr)mas);
			StringBuilder^ sb = gcnew StringBuilder(L"");
			if (!temp->Equals(L"edit"))
			{
				sb->Append(L"MSGID: ");
				sb->Append(oaddr);
				sb->Append(L" ");
				sb->Append(umsgid.ToString(L"x"));
				sb->Append(L"PID: HellEd ");
				sb->Append(Vers);
			}
			
			text=rtText->Text->Replace(L"\r\n",L"\n");
			re = gcnew Regex(L"^\\u0001.*$",RegexOptions::Multiline);
			MatchCollection^ mc = re->Matches(text);
			bool rep=false;
			int q=0;
			int pos=text->Length;
			for(int i=0;i<mc->Count;i++)
			{
				if (mc[i]->Index+mc[i]->Length+q+1<text->Length)
				{
					text=string::Concat(text->Substring(0,mc[i]->Index+q),
					text->Substring(mc[i]->Index+mc[i]->Length+q+1));
				}
				else
				{
					text=text->Substring(0,mc[i]->Index+q);
				}
				q=text->Length-pos;
				sb->Append(mc[i]->Value);
				if (!rep)
				if (mc[i]->Value->StartsWith(L"REPLY: ")){rep=true;}
			}

			text=string::Concat(text,L"\n * Origin: ", origin, L" (",oaddr,L")");
			ParseName(oname,qbegin,ofname,omname,olname);
			ParseName(dname,qbegin,dfname,dmname,dlname);
			text = PostProcessText(text)->Replace("\n","\r");

			array<string^> ^ strs = ((string^)frmSettings->tlConfigHED->FindNodeByKeyID(1203)->GetValue(1))->Split(((string^)L"\r\n")->ToCharArray());
			for(int i=0;i<strs->Length;i++)
			if (strs[i]!=L"")
			{
				array<string^> ^ syms = strs[i]->Split(((string^)L" ")->ToCharArray());
				if (syms->Length>1)
				if (syms[0]->Length>0)
				{text=text->Replace(syms[0],syms[1]);}
			}
			dword txtLen = text->Length;
			dword ctrlLen = sb->Length;

			System::Text::Encoding^ ew = System::Text::Encoding::Default;
			System::Text::Encoding^ ed = System::Text::Encoding::GetEncoding(frmSettings->MessagesEncoding);

			for(int q=0;q<tlArea->AllNodesCount;q++)
			if (tlArea->FindNodeByID(q)->GetValue(7))
			if ((*dynamic_cast<bool^>(tlArea->FindNodeByID(q)->GetValue(7)))==true)
			{
				if (frmSettings->echotoss->IndexOf(string::Concat((string^)tlArea->FindNodeByID(q)->GetValue(0),"\n"))==-1){frmSettings->echotoss=string::Concat(frmSettings->echotoss,(string^)tlArea->FindNodeByID(q)->GetValue(0),"\n");}
				string^ Path = (string^)tlArea->FindNodeByID(q)->GetValue(2);
				string^ Address = (string^)tlArea->FindNodeByID(q)->GetValue(3);
				string^ BaseType = ((string^)tlArea->FindNodeByID(q)->GetValue(4))->ToLower();
				string^ AreaName = ((string^)tlArea->FindNodeByID(q)->GetValue(0))->ToLower();
				string^ AreaType = ((string^)tlArea->FindNodeByID(q)->GetValue(5))->ToLower();
			
				word type;
				if (BaseType->Equals("msg")){type=MSGTYPE_SDM;}
				if (BaseType->Equals("squish")){type=MSGTYPE_SQUISH;}
				if (BaseType->Equals("jam")){type=MSGTYPE_JAM;}
				StringBuilder^ sbn = sb;
				if ((AreaName->Equals("netmail"))||
					(AreaType->Equals("netmailarea")))
				{
					string^ fmnode = L"";
					string^ fmpt = L"";
					string^ tonode = L"";
					string^ topt = L"";
					oaddr=Utils::CompleteAddr2(oaddr);
					daddr=Utils::CompleteAddr2(daddr);
					re = gcnew Regex(L"(\\d{1,5}:\\d{1,5}/\\d{1,5})\\.(\\d{1,5})",RegexOptions::Multiline);
					m = re->Match(oaddr);		
					if(m->Success)
					{
						fmnode = m->Groups[1]->Value;
						fmpt = m->Groups[2]->Value;
					}
					m = re->Match(daddr);		
					if(m->Success)
					{
						tonode = m->Groups[1]->Value;
						topt = m->Groups[2]->Value;
					}
					sbn->Append(L"FMPT ");
					sbn->Append(fmpt);
					sbn->Append(L"TOPT ");
					sbn->Append(topt);
					sbn->Append(L"INTL ");
					sbn->Append(tonode);
					sbn->Append(L" ");
					sbn->Append(fmnode);
				}
				ctrlLen = sbn->Length;

				mas = (char*)(void*)Marshal::StringToHGlobalAnsi(Path);
				HAREA harea = MsgOpenArea((byte*)mas, MSGAREA_CRIFNEC, type);
				Marshal::FreeHGlobal((System::IntPtr)mas);
				if (harea==nullptr){return;}
				if (MsgLock(harea)!=0){return;}
				HMSG hmsg;
				XMSG xmsg;
				xmsg.__ftsc_date[0]='\0';
				xmsg.date_written = Utils::DateTimeTo_stamp(odatetime);
				xmsg.attr = Utils::StringToAttr(pceAttributes->Text);
				if (temp->Equals(L"edit"))
				{
					hmsg=MsgOpenMsg(harea,MOPEN_READ,msgn);
					MsgReadMsg(hmsg, &xmsg, 0, 0, nullptr, 0, nullptr);
					MsgCloseMsg(hmsg);
					hmsg=MsgOpenMsg(harea,MOPEN_CREATE,msgn);
				}
				else 
				{
					hmsg=MsgOpenMsg(harea,MOPEN_CREATE,0);
					xmsg.date_arrived = xmsg.date_written;
					xmsg.umsgid=umsgid;
					xmsg.attr|=MSGUID;
					if (rep){xmsg.replyto=replyto;}
					else {xmsg.replyto=0;}
				}
			
				mas = (char*)(void*)Marshal::StringToHGlobalAnsi(gcnew string(ew->GetChars(ed->GetBytes(oname))));
				strcpy_s((char*)(byte*)xmsg.from,36,mas);
				Marshal::FreeHGlobal((System::IntPtr)mas);
	
				mas = (char*)(void*)Marshal::StringToHGlobalAnsi(gcnew string(ew->GetChars(ed->GetBytes(dname))));
				strcpy_s((char*)(byte*)xmsg.to,36,mas);
				Marshal::FreeHGlobal((System::IntPtr)mas);

				xmsg.orig = Utils::StringToNETADDR(oaddr);
				xmsg.dest = Utils::StringToNETADDR(daddr);

				mas = (char*)(void*)Marshal::StringToHGlobalAnsi(gcnew string(ew->GetChars(ed->GetBytes(subject))));
				strcpy_s((char*)(byte*)xmsg.subj,72,mas);
				Marshal::FreeHGlobal((System::IntPtr)mas);
			
				mas = (char*)(void*)Marshal::StringToHGlobalAnsi(gcnew string(ew->GetChars(ed->GetBytes(text))));
				char* mas2 = (char*)(void*)Marshal::StringToHGlobalAnsi(gcnew string(ew->GetChars(ed->GetBytes(sbn->ToString()))));
				if (MsgWriteMsg(hmsg, 0, &xmsg, (byte*)mas, txtLen,
					txtLen, ctrlLen, (byte*)mas2)!=0)
				{
		
				}
				Marshal::FreeHGlobal((System::IntPtr)mas);
				Marshal::FreeHGlobal((System::IntPtr)mas2);
				MsgCloseMsg(hmsg);
				if (MsgUnlock(harea)!=0){return;}
				MsgCloseArea(harea);
			}
			string^ tosser_onsend = frmSettings->tlConfigHED->FindNodeByKeyID(204)->GetValue(1)->ToString();
			if (tosser_onsend->Equals(L"True"))
			{
				string^ FileName = (string^)frmSettings->tlConfigHED->FindNodeByKeyID(207)->GetValue(1);
				if (!FileName->Equals(L""))
				{
					StreamWriter^ sw = gcnew StreamWriter(FileName,false,System::Text::Encoding::GetEncoding(frmSettings->ConfigEncoding));
					sw->Write(frmSettings->echotoss);
					sw->Close();
				}
				if (File::Exists((string^)frmSettings->tlConfigHED->FindNodeByKeyID(203)->GetValue(1)))
				{System::Diagnostics::Process::Start((string^)frmSettings->tlConfigHED->FindNodeByKeyID(203)->GetValue(1));}		
			}
			Close();
		}
		public: void bCustomize_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
 			barManager->Customize();
		}

		public: void bClose_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			Close();
		}
		public: void bUndo_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (rtText->Source->CanUndo())
				rtText->Source->Undo();
		}
		public: void bCut_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (rtText->Selection->CanCut())
				rtText->Selection->Cut();
		}
		public: void bCopy_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (rtText->Selection->CanCopy())
				rtText->Selection->Copy();
		}
		public: void bPaste_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (rtText->Selection->CanPaste())
				rtText->Selection->Paste();
		}
		public: void bSelectAll_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Focus();
			rtText->Selection->SelectAll();
		}
		public: void bFind_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->DisplaySearchDialog();
/*			if (frmReplaceDialog->Visible==true){frmReplaceDialog->Visible=false;}
			if (frmSpelling->Visible==true){frmSpelling->Visible=false;}
			frmFindDialog->Show();
*/		}
		public: void bReplace_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->DisplayReplaceDialog();
/*			if (frmFindDialog->Visible==true){frmFindDialog->Visible=false;}
			if (frmSpelling->Visible==true){frmSpelling->Visible=false;}
			frmReplaceDialog->Show();
*/		}
		public: void bSpellCheck_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			string^ st = spell->Check(rtText->Text);
			rtText->Text=st;
/*			if (frmReplaceDialog->Visible==true){frmReplaceDialog->Visible=false;}
			if (frmFindDialog->Visible==true){frmFindDialog->Visible=false;}
/*			if (spell->MainDictionaryPath)
			{
				frmSpelling->Show();
				frmSpelling->GetNextWord();
			}
*/		}
		public: void bEncryptROT13_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Selection->SelectedText=Utils::rot13(rtText->Selection->SelectedText);
		}
		public: void rtText_MouseUp(object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			if((int)(e->Button & Windows::Forms::MouseButtons::Right) != 0 && rtText->ClientRectangle.Contains(e->X, e->Y))
			{
//				lSpelling->Strings->Clear();
//				if (spell->MainDictionaryPath)
//				{
//					string^ words[] = spell->GetCorrectWordList(rtText->Selection->SelectedText);
//					if (words!=null){lSpelling->Strings->AddRange(words);}
//				}
				pmEdit->ShowPopup(Control::MousePosition);
			}
		}
		public: void bTextFromFile_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			OpenFileDialog^ dlg = gcnew OpenFileDialog();
			dlg->Filter = L"All Files(*.*)|*.*";
			if(dlg->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				StreamReader^ sr = gcnew StreamReader(dlg->FileName,System::Text::Encoding::GetEncoding(frmSettings->FilesEncoding));
				string^ str = string::Concat(L"=== ", dlg->FileName->Substring(dlg->FileName->LastIndexOf(L"\\")+1),L" ===\n",
					sr->ReadToEnd(),
					L"\n==============================================================================\n");
				int s=rtText->Selection->SelectionStart;
				rtText->Text=rtText->Text->Insert(rtText->Selection->SelectionStart,str);
				sr->Close();
				rtText->Selection->SelectionStart=s+str->Length+2;
			}
		}
		public: void bQuoteFromFile_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			OpenFileDialog^ dlg = gcnew OpenFileDialog();
			dlg->Filter = L"All Files(*.*)|*.*";
			if(dlg->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				StreamReader^ sr = gcnew StreamReader(dlg->FileName,System::Text::Encoding::GetEncoding(frmSettings->FilesEncoding));
				string^ str = string::Concat(L"=== ", dlg->FileName->Substring(dlg->FileName->LastIndexOf(L"\\")+1),L" ===\n",
					QuoteText(L"",sr->ReadToEnd()->Replace(L"\r\n",L"\n")),
					L"\n==============================================================================\n");
				int s=rtText->Selection->SelectionStart;
				rtText->Text=rtText->Text->Insert(rtText->Selection->SelectionStart,str);
				sr->Close();
				rtText->Selection->SelectionStart=s+str->Length+2;
			}
		}
		public: void bUUEncode_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			OpenFileDialog^ dlg = gcnew OpenFileDialog();
			dlg->Filter = L"All Files(*.*)|*.*";
			if(dlg->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				string^ str = Utils::uu_encode(dlg->FileName);
				int s=rtText->Selection->SelectionStart;
				rtText->Text=rtText->Text->Insert(rtText->Selection->SelectionStart,str);
				rtText->Selection->SelectionStart=s+str->Length;
			}			
		}
		
		public: void bAdd1_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Selection->SelectedText=bAdd1->Caption;
			rtText->Selection->SelectionStart=rtText->Selection->SelectionStart+
				bAdd1->Caption->Length;
		}
		public: void bAdd2_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Selection->SelectedText=bAdd2->Caption;
			rtText->Selection->SelectionStart=rtText->Selection->SelectionStart+
				bAdd2->Caption->Length;
		}

		public: void bAdd3_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Selection->SelectedText=bAdd3->Caption;
			rtText->Selection->SelectionStart=rtText->Selection->SelectionStart+
				bAdd3->Caption->Length;
		}

		public: void bAdd4_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Selection->SelectedText=bAdd4->Caption;
			rtText->Selection->SelectionStart=rtText->Selection->SelectionStart+
				bAdd4->Caption->Length;
		}

		public: void bAdd5_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Selection->SelectedText=bAdd5->Caption;
			rtText->Selection->SelectionStart=rtText->Selection->SelectionStart+
				bAdd5->Caption->Length;
		}
		public: void bAdd6_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Selection->SelectedText=bAdd6->Caption;
			rtText->Selection->SelectionStart=rtText->Selection->SelectionStart+
				bAdd6->Caption->Length;
		}

		public: void bAdd7_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Selection->SelectedText=bAdd7->Caption;
			rtText->Selection->SelectionStart=rtText->Selection->SelectionStart+
				bAdd7->Caption->Length;
		}
		public: void bAdd8_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Selection->SelectedText=bAdd8->Caption;
			rtText->Selection->SelectionStart=rtText->Selection->SelectionStart+
				bAdd8->Caption->Length;
		}
		public: void bAdd9_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Selection->SelectedText=bAdd9->Caption;
			rtText->Selection->SelectionStart=rtText->Selection->SelectionStart+
				bAdd9->Caption->Length;
		}

		public: void bAdd0_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Selection->SelectedText=bAdd0->Caption;
			rtText->Selection->SelectionStart=rtText->Selection->SelectionStart+
				bAdd0->Caption->Length;
		}

		public: void bAttachFile_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			OpenFileDialog^ dlg = gcnew OpenFileDialog();
			dlg->Filter = L"All Files(*.*)|*.*";
			if(dlg->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				subject=dlg->FileName;
				teSubject->EditValue=subject;
				Text = string::Concat(htStrings[L"frmCreate"],subject);
				clbAttributes->SetItemChecked(4,true);
				pceAttributes->EditValue=Utils::CLBToString(clbAttributes);
			}			
		}

		public: void bBold_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			__wchar_t cl = ' ';
			__wchar_t c = ' ';
			__wchar_t cr = ' ';
			int i = rtText->Selection->SelectionStart;
			int sl = rtText->Selection->SelectionLength;
			if (i>0){cl=rtText->Text->ToCharArray()[i-1];}else{cl=' ';}
			c=rtText->Text->ToCharArray()[i];
			if (i<rtText->Text->Length-1){cr=rtText->Text->ToCharArray()[i+1];}else{cr=' ';}
			if ((cl!='^')&&(cr!='^')&&((gcnew string(L" !\"$%&()+,.:;<=>@[\\]^`{|}~*#/_\r"))->IndexOf(cl)!=-1))
			{rtText->Text=rtText->Text->Insert(i,L"*");i+=sl+1;}
			else {rtText->Text=rtText->Text->Insert(i,L"*");i+=sl+2;}
			if (sl>0)
			{
				i--;
				if (i>0){cl=rtText->Text->ToCharArray()[i-1];}else{cl=' ';}
				c=rtText->Text->ToCharArray()[i];
				if (i<rtText->Text->Length-1){cr=rtText->Text->ToCharArray()[i+1];}else{cr=' ';}
				if ((cl!='^')&&(cr!='^')&&((gcnew string(L" !\"$%&()+,.:;<=>@[\\]^`{|}~*#/_\r"))->IndexOf(cr)!=-1))
				{rtText->Text=rtText->Text->Insert(++i,L"*");i++;}
				else {rtText->Text=rtText->Text->Insert(++i,L"* ");i+=2;}
			}
			rtText->Selection->SelectionStart=i;
		}
		public: void bReverse_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			__wchar_t cl = ' ';
			__wchar_t c = ' ';
			__wchar_t cr = ' ';
			int i = rtText->Selection->SelectionStart;
			int sl = rtText->Selection->SelectionLength;
			if (i>0){cl=rtText->Text->ToCharArray()[i-1];}else{cl=' ';}
			c=rtText->Text->ToCharArray()[i];
			if (i<rtText->Text->Length-1){cr=rtText->Text->ToCharArray()[i+1];}else{cr=' ';}
			if ((cl!='#')&&(cr!='#')&&((gcnew string(L" !\"$%&()+,.:;<=>@[\\]^`{|}~*#/_\r"))->IndexOf(cl)!=-1))
			{rtText->Text=rtText->Text->Insert(i,L"#");i+=sl+1;}
			else {rtText->Text=rtText->Text->Insert(i,L" #");i+=sl+2;}
			if (sl>0)
			{
				i--;
				if (i>0){cl=rtText->Text->ToCharArray()[i-1];}else{cl=' ';}
				c=rtText->Text->ToCharArray()[i];
				if (i<rtText->Text->Length-1){cr=rtText->Text->ToCharArray()[i+1];}else{cr=' ';}
				if ((cl!='#')&&(cr!='#')&&((gcnew string(L" !\"$%&()+,.:;<=>@[\\]^`{|}~*#/_\r"))->IndexOf(cr)!=-1))
				{rtText->Text=rtText->Text->Insert(++i,L"#");i++;}
				else {rtText->Text=rtText->Text->Insert(++i,L"# ");i+=2;}
			}
			rtText->Selection->SelectionStart=i;
		}
		public: void bItalic_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			__wchar_t cl = ' ';
			__wchar_t c = ' ';
			__wchar_t cr = ' ';
			int i = rtText->Selection->SelectionStart;
			int sl = rtText->Selection->SelectionLength;
			if (i>0){cl=rtText->Text->ToCharArray()[i-1];}else{cl=' ';}
			c=rtText->Text->ToCharArray()[i];
			if (i<rtText->Text->Length-1){cr=rtText->Text->ToCharArray()[i+1];}else{cr=' ';}
			if ((cl!='/')&&(cr!='/')&&((gcnew string(L" !\"$%&()+,.:;<=>@[\\]^`{|}~*#/_\r"))->IndexOf(cl)!=-1))
			{rtText->Text=rtText->Text->Insert(i,L"/");i+=sl+1;}
			else {rtText->Text=rtText->Text->Insert(i,L" /");i+=sl+2;}
			if (sl>0)
			{
				i--;
				if (i>0){cl=rtText->Text->ToCharArray()[i-1];}else{cl=' ';}
				c=rtText->Text->ToCharArray()[i];
				if (i<rtText->Text->Length-1){cr=rtText->Text->ToCharArray()[i+1];}else{cr=' ';}
				if ((cl!='/')&&(cr!='/')&&((gcnew string(L" !\"$%&()+,.:;<=>@[\\]^`{|}~*#/_\r"))->IndexOf(cr)!=-1))
				{rtText->Text=rtText->Text->Insert(++i,L"/");i++;}
				else {rtText->Text=rtText->Text->Insert(++i,L"/ ");i+=2;}
			}
			rtText->Selection->SelectionStart=i;
		}
		public: void bUnderline_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			__wchar_t cl = ' ';
			__wchar_t c = ' ';
			__wchar_t cr = ' ';
			int i = rtText->Selection->SelectionStart;
			int sl = rtText->Selection->SelectionLength;
			if (i>0){cl=rtText->Text->ToCharArray()[i-1];}else{cl=' ';}
			c=rtText->Text->ToCharArray()[i];
			if (i<rtText->Text->Length-1){cr=rtText->Text->ToCharArray()[i+1];}else{cr=' ';}
			if ((cl!='_')&&(cr!='_')&&((gcnew string(L" !\"$%&()+,.:;<=>@[\\]^`{|}~*#/_\r"))->IndexOf(cl)!=-1))
			{rtText->Text=rtText->Text->Insert(i,L"_");i+=sl+1;}
			else {rtText->Text=rtText->Text->Insert(i,L" _");i+=sl+2;}
			if (sl>0)
			{
				i--;
				if (i>0){cl=rtText->Text->ToCharArray()[i-1];}else{cl=' ';}
				c=rtText->Text->ToCharArray()[i];
				if (i<rtText->Text->Length-1){cr=rtText->Text->ToCharArray()[i+1];}else{cr=' ';}
				if ((cl!='_')&&(cr!='_')&&((gcnew string(L" !\"$%&()+,.:;<=>@[\\]^`{|}~*#/_\r"))->IndexOf(cr)!=-1))
				{rtText->Text=rtText->Text->Insert(++i,L"_");i++;}
				else {rtText->Text=rtText->Text->Insert(++i,L"_ ");i+=2;}
			}
			rtText->Selection->SelectionStart=i;
		}
		public: void rtText_KeyDown(object^ sender, KeyEventArgs^ e)
		{
			e->Handled=false;
			if (e->KeyData==System::Windows::Forms::Keys::Enter)
			{
				int j=rtText->Selection->SelectionStart;
				int i=rtText->Text->Substring(0,rtText->Selection->SelectionStart+rtText->Selection->SelectionLength)->
					LastIndexOf(L"\n");
				i=rtText->Text->Substring(0,i)->LastIndexOf(L"\n");
				i++;
				int z=rtText->Text->Substring(rtText->Selection->SelectionStart+rtText->Selection->SelectionLength)->
					IndexOf(L"\n");
				if (z==-1){z=rtText->Text->Length-rtText->Selection->SelectionStart;}
				if (z!=0)
				{
					Regex^ re = gcnew Regex(L"^\\s*([A-Za-zА-Яа-я]*>+\\s)",RegexOptions::Multiline);
					Match^ m = re->Match(rtText->Text->Substring(i,j-i));						
					if (m->Success)
					{
						int s = rtText->Selection->SelectionStart;
						rtText->Text=rtText->Text->Insert(rtText->Selection->SelectionStart,string::Concat(m->Groups[1]->Value));
						rtText->Selection->SelectionStart=s+m->Groups[1]->Length;
						e->Handled=true;
					}
				}
			}
			if (e->KeyData==System::Windows::Forms::Keys::Back)
			if (rtText->Selection->SelectionStart>=2)
			{
				int q=rtText->Text->Substring(0,rtText->Selection->SelectionStart+rtText->Selection->SelectionLength)->LastIndexOf(L"\n");
				q++;
				if (rtText->Selection->SelectionStart-q>0)
				{
					Regex^ re = gcnew Regex(L"^\\s*([A-Za-zА-Яа-я]*>+)",RegexOptions::Multiline);
					Match^ m = re->Match(rtText->Text->Substring(q));						
					if (m->Success)
					if ((rtText->Selection->SelectionStart==q+m->Length)&&(q>0))
					{
						string^ in1=m->Groups[1]->Value;
						int p=rtText->Text->Substring(0,q-2)->LastIndexOf(L"\n");
						p++;
						if (p>=0)
						{
							re = gcnew Regex(L"^\\s*([A-Za-zА-Яа-я]*>+)\\s",RegexOptions::Multiline);
							m = re->Match(rtText->Text->Substring(p,q-p));
							if (m->Success)
							{
								string^ in2 = m->Groups[1]->Value;
								if (in2->Equals(in1))
								{
									int s1 = rtText->Selection->SelectionStart;
									rtText->Selection->SelectionStart=q-2;
									rtText->Selection->SelectionLength=s1-(q-2);
									rtText->Selection->SelectedText=L"";
									e->Handled=true;
								}
							}
						}
					}
				}
			}
			if (e->KeyData==(System::Windows::Forms::Keys)(System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Y))
			{
				int z=rtText->Text->Substring(0,rtText->Selection->SelectionStart+rtText->Selection->SelectionLength)->LastIndexOf(L"\n");
				int z1=rtText->Selection->SelectionStart+rtText->Selection->SelectionLength+rtText->Text->Substring(rtText->Selection->SelectionStart+rtText->Selection->SelectionLength)->IndexOf(L"\n");
				z++;
				z1++;
				if (z1==rtText->Selection->SelectionStart+rtText->Selection->SelectionLength){z1=rtText->Text->Length;}
				rtText->Selection->SelectionLength=0;
				rtText->Selection->SelectionStart=z;
				rtText->Selection->SelectionLength=z1-z;
				rtText->Selection->SelectedText=L"";
			}
			sStatus->Caption=string::Concat(htStrings[L"MessageLength"],L" ",rtText->Text->Length.ToString());
		}
		public: void rtText_WordSpell(object^ sender, QWhale::Editor::WordSpellEventArgs^ e)
		{
	//		string^ st = SpellCheckerBase::Check(e->Text);
	//		e->Correct = st->Equals(e->Text);
		}

		public: void lSpelling_ListItemClick(object^ sender, DevExpress::XtraBars::ListItemClickEventArgs^ e) 
		{
			rtText->Selection->SelectedText=lSpelling->Strings[e->Index];
		}

		public: string^ ProcessMacros(string^ str, string^ a, string^ b)
		{
			string^ res=str;
			int posBegin = 0;
			int posEnd = 0;
			if (res->Length>0)
			for(posBegin=res->ToLower()->IndexOf(a);(posBegin!=posEnd-1)&&(posEnd<res->Length);posBegin=posEnd + res->Substring(posEnd)->ToLower()->IndexOf(a))
			{
				posBegin.ToString();
				posEnd = posBegin + a->Length;
				res=string::Concat(res->Substring(0,posBegin),
					b,
					res->Substring(posEnd));
				posEnd = posBegin + b->Length;
			}
			return res;
		}
		public: string^ ProcessStr(string^ str)
		{
			string^ res = str;
			res = ProcessMacros(res,L"%area",area);
			res = ProcessMacros(res,L"%oname",oname);
			res = ProcessMacros(res,L"%ofname",ofname);
			res = ProcessMacros(res,L"%omname",omname);
			res = ProcessMacros(res,L"%olname",olname);
			res = ProcessMacros(res,L"%dname",dname);
			res = ProcessMacros(res,L"%dfname",dfname);
			res = ProcessMacros(res,L"%dmname",dmname);
			res = ProcessMacros(res,L"%dlname",dlname);
			res = ProcessMacros(res,L"%oaddr",oaddr);
			res = ProcessMacros(res,L"%daddr",daddr);
			res = ProcessMacros(res,L"%odatetime",odatetime.ToString());
			res = ProcessMacros(res,L"%attributes",attributes);
			res = ProcessMacros(res,L"%subject",subject);
			res = ProcessMacros(res,L"%qtarea",qtarea);
			res = ProcessMacros(res,L"%qarea",qarea);
			res = ProcessMacros(res,L"%qoname",qoname);
			res = ProcessMacros(res,L"%qofname",qofname);
			res = ProcessMacros(res,L"%qomname",qomname);
			res = ProcessMacros(res,L"%qolname",qolname);
			res = ProcessMacros(res,L"%qdname",qdname);
			res = ProcessMacros(res,L"%qdfname",qdfname);
			res = ProcessMacros(res,L"%qdmname",qdmname);
			res = ProcessMacros(res,L"%qdlname",qdlname);
			res = ProcessMacros(res,L"%qoaddr",qoaddr);
			res = ProcessMacros(res,L"%qdaddr",qdaddr);
			res = ProcessMacros(res,L"%qodatetime",qodatetime.ToString());
			res = ProcessMacros(res,L"%qddatetime",qddatetime.ToString());
			res = ProcessMacros(res,L"%qattributes",qattributes);
			res = ProcessMacros(res,L"%qmsgid",qmsgid);
			res = ProcessMacros(res,L"%qsubject",qsubject);
			res = ProcessMacros(res,L"%uptimedays",(uptime/1000/60/60/24).ToString());
			res = ProcessMacros(res,L"%uptimehours",(uptime/1000/60/60%24).ToString());
			res = ProcessMacros(res,L"%uptimeminutes",(uptime/1000/60%60).ToString());
			res = ProcessMacros(res,L"%uptimeseconds",(uptime/1000%60).ToString());
			res = ProcessMacros(res,L"%version",Vers);
			return res;
		}
		public: string^ ProcessText(string^ str)
		{
			string^ res = str;
			res = ProcessStr(res);
			res = ProcessMacros(res,L"%qkludges",qkludges);
			res = ProcessMacros(res,L"%qeomkludges",qeomkludges);
			res = ProcessMacros(res,L"%qqkludges",qqkludges);
			res = ProcessMacros(res,L"%qqeomkludges",qqeomkludges);
			res = ProcessMacros(res,L"%qsubject",qsubject);
			res = ProcessMacros(res,L"%qtext",qtext);
			res = ProcessMacros(res,L"%qselectedtext",qselectedtext);
			res = ProcessMacros(res,L"%quote",quote);
			res = ProcessMacros(res,L"%qlite",qlite);
			res = ProcessMacros(res,L"%tearline",tearline);

			Regex ^ re = gcnew Regex(L"%put=\"([^\"]*)\"",RegexOptions::IgnoreCase);
			MatchCollection^ mc = re->Matches(res);		
			int q=0;
			int pos=res->Length;
			for(int i=0;i<mc->Count;i++)
			{
				string^ FileName=mc[i]->Groups[1]->Value;
				string^ txt=L"";
				if (File::Exists(FileName))
				{
					StreamReader^ sr = gcnew StreamReader(FileName,System::Text::Encoding::GetEncoding(frmSettings->FilesEncoding));
					txt=sr->ReadToEnd();
					sr->Close();
				}
				res = string::Concat(res->Substring(0,mc[i]->Index+q),
					txt,
					res->Substring(mc[i]->Index+mc[i]->Length+q));
				q = res->Length-pos;
			}
			re = gcnew Regex(L"%random=\"([^\"]*)\"",RegexOptions::IgnoreCase);
			mc = re->Matches(res);		
			q=0;
			pos=res->Length;
			for(int i=0;i<mc->Count;i++)
			{
				string^ FileName=mc[i]->Groups[1]->Value;
				string^ txt=L"";
				if (File::Exists(FileName))
				{
					StreamReader^ sr = gcnew StreamReader(FileName,System::Text::Encoding::GetEncoding(frmSettings->FilesEncoding));
					txt=sr->ReadToEnd();
					sr->Close();
				}
				array<string^> ^ strs;
				strs = txt->Split(((string^)L"\n")->ToCharArray());
				System::Random^ rnd = gcnew System::Random();
				res = string::Concat(res->Substring(0,mc[i]->Index+q),
					strs[rnd->Next(strs->Length)],
					res->Substring(mc[i]->Index+mc[i]->Length+q));
				q = res->Length-pos;
			}
			return res;
		}
		public: string^ PostProcessText(string^ str)
		{
			string^ res = str;
			res = ProcessMacros(res,L"%area",area);
			res = ProcessMacros(res,L"%oname",oname);
			res = ProcessMacros(res,L"%ofname",ofname);
			res = ProcessMacros(res,L"%omname",omname);
			res = ProcessMacros(res,L"%olname",olname);
			res = ProcessMacros(res,L"%dname",dname);
			res = ProcessMacros(res,L"%dfname",dfname);
			res = ProcessMacros(res,L"%dmname",dmname);
			res = ProcessMacros(res,L"%dlname",dlname);
			res = ProcessMacros(res,L"%oaddr",oaddr);
			res = ProcessMacros(res,L"%daddr",daddr);
			res = ProcessMacros(res,L"%odatetime",odatetime.ToString());
			res = ProcessMacros(res,L"%attributes",attributes);
			res = ProcessMacros(res,L"%subject",subject);
			return res;
		}

		public: void pceAttributes_QueryResultValue(object^ sender, DevExpress::XtraEditors::Controls::QueryResultValueEventArgs^ e) 
		{
			e->Value = Utils::CLBToString(clbAttributes);
		}

		public: StringBuilder^ QuoteBlock(string^ in, string^ txt)
		{
			StringBuilder^ res = gcnew StringBuilder(L"");
			int posBegin = 0;
			int posEnd = 0;
			for(posBegin=0;posEnd<txt->Length;posBegin = posEnd + 1)
			{			
				if (posBegin + string_length - in->Length - 3 > txt->Length){posEnd=txt->Length;}
				else {posEnd = posBegin + txt->Substring(posBegin,string_length - in->Length - 3)->LastIndexOf(L" ");}
				if (posEnd==posBegin-1)
				{posEnd=posBegin + string_length - in->Length - 3;}
				res->Append(L" ");
				res->Append(in);
				res->Append(L"> ");
				res->AppendLine(txt->Substring(posBegin,posEnd-posBegin));
			}
			return res;
		}

		public: string^ QuoteText(string^ innew, string^ txt)
		{
			StringBuilder^ res = gcnew StringBuilder(L"");
			string^ in = L"";
			StringBuilder^ block = gcnew StringBuilder(L"");
			int posBegin = 0;
			int posEnd = 0;
			if (txt->Length>0)
			for(posBegin=0;posEnd<txt->Length;posBegin=posBegin+1 + txt->Substring(posBegin)->IndexOf(L"\n"))
			{
				posEnd = posBegin + txt->Substring(posBegin)->IndexOf(L"\n");
				if (posEnd==posBegin-1){posEnd=txt->Length;}
				string^ str = txt->Substring(posBegin,posEnd - posBegin);
				if (str->Length==0) //&&(block->Length!=0))
				{
					if (!in->Equals(L""))
					{
						res->Append(QuoteBlock(in,block->ToString()));
						block=gcnew StringBuilder(L"");
						in=L"";
					}
					res->AppendLine();
				}
				else
				{
					Regex^ re = gcnew Regex(L"^\\s*([A-Za-zА-Яа-я]*>+)\\s",RegexOptions::Multiline);
					Match^ m = re->Match(str);
					if (m->Success)
					{
						if (in->Equals(m->Groups[1]->Value))
						{
							if (m->Length<=str->Length)
							{
								if ((str->Substring(m->Length)->StartsWith(L" "))||
									(str->Substring(m->Length)->StartsWith(L"	")))
								{
									res->Append(QuoteBlock(in,block->ToString()));
									block=gcnew StringBuilder(str->Substring(str->Length));
								}
								else
								{
									block->Append(L" ");
									block->Append(str->Substring(m->Length));
								}
							}
							else
							{
								block->Append(L" ");
								block->Append(str->Substring(m->Length));}
						}
						else
						{
							res->Append(QuoteBlock(in,block->ToString()));
							block=gcnew StringBuilder(str->Substring(m->Length));
							in=m->Groups[1]->Value;
						}
					}
					else
					{
						if (!in->Equals(L""))
						{
							res->Append(QuoteBlock(in,block->ToString()));
							block=gcnew StringBuilder(L"");
							in=L"";
						}
						res->Append(QuoteBlock(innew,str));
					}
				}
			}
			return res->ToString()->Trim(((string^)L"\n")->ToCharArray());
		}
		public: void ParseName(string^ name, string^% begin, string^% fname, string^% mname, string^% lname)
		{
			begin = L"";
			fname = L"";
			mname = L"";
			lname = L"";
			Regex^ re = gcnew Regex(L"([^\\s]+)(?:(?:\\s(.+))?\\s([^\\s]+))?");
			Match^ m = re->Match(name);
			if (m->Success)
			{
				fname=m->Groups[1]->Value;
				begin=fname->Substring(0,1);
				if (!m->Groups[2]->Value->Equals(L"")){mname=m->Groups[2]->Value;}
				if (!m->Groups[3]->Value->Equals(L""))
				{
					lname=m->Groups[3]->Value;
					begin=string::Concat(begin,lname->Substring(0,1));
				}
			}
		}


		public: void LoadTemplate(string^ temp, HAREA harea)
		{
			uptime = System::Environment::TickCount;
			System::Text::Encoding^ ew = System::Text::Encoding::Default;
			System::Text::Encoding^ ed = System::Text::Encoding::GetEncoding(frmSettings->MessagesEncoding);
			quote = L"";
			qlite = L"";
			qmsgid = L"";
			qtarea = L"";
			string^ str;
			if (msgn>0)
			{
				XMSG xmsg;
				HMSG hmsg = MsgOpenMsg(harea,MOPEN_READ,msgn);
				replyto = xmsg.umsgid;
				dword txtLen = MsgGetTextLen(hmsg);
				dword ctrlLen = MsgGetCtrlLen(hmsg);
				char* txt = new char[txtLen+1];
				char* ctrl = new char[ctrlLen+1];
				MsgReadMsg(hmsg, &xmsg, 0L, txtLen, (byte*)txt, ctrlLen, (byte*)ctrl);
				MsgCloseMsg(hmsg);
				txt[txtLen]=0;
				ctrl[ctrlLen]=0;
				qattributes = Utils::AttrToString(xmsg.attr);
				qoname = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)xmsg.from)));
				qdname = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)xmsg.to)));
				qoaddr = Utils::NETADDRToString(xmsg.orig);
				qdaddr = Utils::NETADDRToString(xmsg.dest);
				qsubject = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)xmsg.subj)));
				qodatetime = Utils::_stampToDateTime(xmsg.date_written);
				qddatetime = Utils::_stampToDateTime(xmsg.date_arrived);

				qtext = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)txt)))->TrimEnd('\r')->Replace(L"\r",L"\n")->Trim(((string^)L"\n")->ToCharArray());
				Regex^ re = gcnew Regex(L"^(SEEN\\-BY|PATH|Via)([:\\s].*?)$",RegexOptions::Multiline);
				MatchCollection^ mc = re->Matches(qtext);
				StringBuilder^ sb = gcnew StringBuilder(L"");
				int q=0;
				int pos=qtext->Length;
				for(int i=0;i<mc->Count;i++)
				{
					qtext=string::Concat(qtext->Substring(0,mc[i]->Index+q - (mc[i]->Index > 0 ? 1 : 0)),
						qtext->Substring(mc[i]->Index+q+mc[i]->Length));
					sb->Append(mc[i]->Groups[1]->Value);
					sb->Append(mc[i]->Groups[2]->Value);
					if (i!=mc->Count-1){sb->Append(L"\n");}
					q=qtext->Length-pos;
				}

				qeomkludges = sb->ToString();
				qkludges = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)CvtCtrlToKludge((byte*)ctrl))))->TrimEnd('\r')->Replace(L"\r",L"\n");
				
				re = gcnew Regex(L"^(?:MSGID):\\s(.*?)$",RegexOptions::Multiline);
				Match^ m = re->Match(qkludges);
				if (m->Success){qmsgid = m->Groups[1]->Value;}
				re = gcnew Regex(L"^(?:AREA):(.*?)$",RegexOptions::Multiline);
				m = re->Match(qkludges);
				if (m->Success){qtarea = m->Groups[1]->Value;}

				delete txt;
				delete ctrl;
				
				if (!qtext->Equals(L""))
				{
					if (temp->Equals(L"edit"))
					{
						Regex^ re = gcnew Regex(L"^\\s\\*\\sOrigin:\\s(.*)\\s(\\((?:\\d{1,5}:)?\\d{1,5}/\\d{1,5}(?:\\.\\d{1,5})?\\))$",RegexOptions::Multiline);
						MatchCollection^ mc = re->Matches(qtext);
						if (mc->Count>0)
						{
							qtext=qtext->Substring(0,mc[mc->Count-1]->Index - (mc[mc->Count-1]->Index > 0 ? 1 : 0));
							origin=mc[mc->Count-1]->Groups[1]->Value;
						}
					}
					else
					{
						qtext=qtext->Replace(L"",L"@")->
							Replace(L"\n--- ",L"\n-+- ")->
							Replace(L"\n * Origin: ",L"\n + Origin: ");
						qselectedtext=qselectedtext->Replace(L"☺",L"@")->
							Replace(L"\n--- ",L"\n-+- ")->
							Replace(L"\n * Origin: ",L"\n + Origin: ");
						qkludges=qkludges->Replace(L"",L"@");
						qeomkludges=qeomkludges->Replace(L"",L"@");
					}

					ParseName(qoname,qbegin,qofname,qomname,qolname);
				}
			}

			StreamReader^ sr = gcnew StreamReader(string::Concat(HellEdDir,L"\\templates\\",temp,L".txt"),System::Text::Encoding::UTF8);
			str = sr->ReadLine();
			area = ProcessStr(str->Substring(str->IndexOf(L" ")+1))->ToLower();
			StringBuilder^ ar = gcnew StringBuilder(L"");
			array<string^> ^ strs;
			strs = area->Split(((string^)L" ")->ToCharArray());
			for(int i=0;i<tlArea->AllNodesCount;i++)
			{
				for(int j=0;j<strs->Length;j++)
				if (tlArea->FindNodeByID(i)->GetValue(6)->Equals(L""))
				{
					if (((string^)tlArea->FindNodeByID(i)->GetValue(0))->ToLower()->Equals(strs[j]))
					{
						if (ar->Length!=0){ar->Append(L" ");}
						ar->Append((string^)tlArea->FindNodeByID(i)->GetValue(0));
						tlArea->FindNodeByID(i)->SetValue(7,true);
						if(!tlArea->FindNodeByID(i)->GetValue(3)->Equals(L""))
						{oaddr = (string^)tlArea->FindNodeByID(i)->GetValue(3);}
						if (tlArea->FindNodeByID(i)->GetValue(5)->Equals(L"netmailarea"))
						{attributes = L"pvt loc";}
					}
					else {tlArea->FindNodeByID(i)->SetValue(7,false);}
				}
			}
			area = ar->ToString();

			pceArea->EditValue=area;
			str = sr->ReadLine();
			oname = ProcessStr(str->Substring(str->IndexOf(L" ")+1));
			ParseName(oname,qbegin,ofname,omname,olname);
			cbeFrom->EditValue=oname;
			str = sr->ReadLine();
			oaddr = ProcessStr(str->Substring(str->IndexOf(L" ")+1));
			cbeFromAddress->EditValue=oaddr;
			str = sr->ReadLine();
			dname = ProcessStr(str->Substring(str->IndexOf(L" ")+1));
			ParseName(dname,qbegin,dfname,dmname,dlname);
			teTo->EditValue=dname;
			str = sr->ReadLine();
			daddr = ProcessStr(str->Substring(str->IndexOf(L" ")+1))->Replace(L".0",L"");
			pceToAddress->EditValue=daddr;
			teDAddr->EditValue=daddr;
			teDAddr_EditValueChanged(nullptr,nullptr);
			str = sr->ReadLine();
			subject = ProcessStr(str->Substring(str->IndexOf(L" ")+1));
			Text = string::Concat(htStrings[L"frmCreate"],subject);
			str = sr->ReadLine();
//			odatetime = ProcessStr(str->Substring(str->IndexOf(L" ")+1));
			deWritten->EditValue=odatetime;
			teWritten->EditValue=odatetime;
			str = sr->ReadLine();
			teSubject->EditValue=subject;
			attributes = ProcessStr(str->Substring(str->IndexOf(L" ")+1));
			Utils::StringToCLB(attributes,clbAttributes);
			pceAttributes->EditValue=Utils::CLBToString(clbAttributes);
			str = sr->ReadToEnd()->Replace("\r\n","\n");
			if ((msgn>0)&& (!qtext->Equals(L"")))
			{
				if (str->ToLower()->IndexOf(L"%quote")>=0)
				{quote = QuoteText(qbegin, qtext);}
				if (str->ToLower()->IndexOf(L"%qqkludges")>=0)
				{qqkludges = QuoteText(qbegin, qkludges);}
				if (str->ToLower()->IndexOf(L"%qqeomkludges")>=0)
				{qqeomkludges = QuoteText(qbegin, qeomkludges);}
				if (str->ToLower()->IndexOf(L"%qlite")>=0)
				if (!qselectedtext->Equals(L"")){qlite=QuoteText(qbegin, qselectedtext);}
				else
				{
					int pb = qtext->IndexOf(L"\n\n");
					int pe = qtext->LastIndexOf(L"\n\n");
					if (pe==pb)
					{
						pe = qtext->LastIndexOf(L"\n-+-");
						if (pe==-1)
						{
							pe = qtext->LastIndexOf(L"\n + Origin: ");
							if (pe==-1){pe = qtext->Length;}
						}
						if ((pb==-1)||(pb+1==pe)){pb=0;}
						else {pb+=2;}

						if (pe>pb)
						{
							if ((qtext->Substring(pb,pe-pb)->Replace(L"\n",L"")->Trim()->Length==0)||
								(pe-pb<pb))
							{
								pe=pb;
								pb=0;
							}
							else {pb=0;}
						}
					}
					else {pb+=2;}
					if (pe>pb){qlite=QuoteText(qbegin, qtext->Substring(pb,pe-pb)->Trim(((string^)L"\n")->ToCharArray()));}
				}
			}
			rtText->Text = ProcessText(str);
			int curpos = rtText->Text->IndexOf(L"%Cursor");
			if (curpos!=-1)
			{
				rtText->Text = rtText->Text->Replace(L"%Cursor", L"");
				rtText->Selection->SelectionStart=curpos;
			}
			sStatus->Caption=string::Concat(htStrings[L"MessageLength"],L" ",rtText->Text->Length.ToString());
			cbeOrigin->Text = origin;
			teOriginEnd->Text=string::Concat(L"(",oaddr,L")");
			sr->Close();
		}


		public: void bSaveMessage_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			SaveFileDialog^ dlg = gcnew SaveFileDialog();
			dlg->Filter = L"HTML|^.html";
			dlg->FileName = string::Concat(teSubject->EditValue->ToString()->
				 Replace("/","_")->
				 Replace("\\","_")->
				 Replace(":","_")->
				 Replace("^","_")->
				 Replace("?","_")->
				 Replace("\"","_")->
				 Replace("<","_")->
				 Replace(">","_")->
				 Replace("|","_")
				,L".html");
			string^ res;
			StreamReader^ sr = gcnew StreamReader(string::Concat(HellEdDir,L"\\skins\\",(string^)frmSettings->tlConfigHED->FindNodeByKeyID(501)->GetValue(1),L"\\message.css"),System::Text::Encoding::UTF8);
			string^ style = sr->ReadToEnd();
			sr->Close();
			res=string::Concat(rtText->Text,L"\n");
			res = Utils::ProcessFTN(res,HellEdDir,true,false,true);
			res = string::Concat(L"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"><html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"><style>",style,L"</style></head>\n<body><table class=\"header\">",
				L"</table>",res,L"</body></html>");
			if(dlg->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				StreamWriter^ sw = gcnew StreamWriter(dlg->FileName,false,System::Text::Encoding::UTF8);
				sw->Write(res);
				sw->Close();
			}
		}
		public: void bPrint_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			string^ res;
			StreamReader^ sr = gcnew StreamReader(string::Concat(HellEdDir,L"\\skins\\",(string^)frmSettings->tlConfigHED->FindNodeByKeyID(501)->GetValue(1),L"\\message.css"),System::Text::Encoding::UTF8);
			string^ style = sr->ReadToEnd();
			sr->Close();
			res=string::Concat(rtText->Text,L"\n");
			res = Utils::ProcessFTN(res,HellEdDir,true,false,true);
			res = string::Concat(L"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"><html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"><style>",style,L"</style></head>\n<body><table class=\"header\">",
				L"</table>",res,L"</body></html>");
			frmSettings->wbTemp->DocumentText=res;
			frmSettings->wbTemp->ShowPrintDialog();
		}
		public: void bSaveAsTemplate_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			SaveFileDialog^ dlg = gcnew SaveFileDialog();
			dlg->Filter = L"Template (^.txt)|^.txt";
			dlg->FileName = string::Concat(teSubject->EditValue->ToString()->
				 Replace("/","_")->
				 Replace("\\","_")->
				 Replace(":","_")->
				 Replace("^","_")->
				 Replace("?","_")->
				 Replace("\"","_")->
				 Replace("<","_")->
				 Replace(">","_")->
				 Replace("|","_")
				,L".txt");
			if(dlg->ShowDialog() == Windows::Forms::DialogResult::OK)
			{
				string^ res;
				StreamWriter^ sw = gcnew StreamWriter(dlg->FileName,false,System::Text::Encoding::UTF8);
				res=rtText->Text;
				res = string::Concat(L"Area ",pceArea->EditValue,
					L"\nOName ",cbeFrom->EditValue,
					L"\nOAddr ",cbeFromAddress->EditValue,
					L"\nDName ",teTo->EditValue,
					L"\nDAddr ",pceToAddress->EditValue,
					L"\nSubject ",teSubject->EditValue,
					L"\nODateTime ",deWritten->ToString(),
					L"\nAttributes ",pceAttributes->EditValue,
					L"\n",res->Replace("\r","\r\n"));
				sw->Write(res);
				sw->Close();
			}
		}
		public: void InitializehtLanguage()
		{
			htStrings = gcnew Hashtable();
			htStrings->Add(L"MessageLength", L"");
			htStrings->Add(L"frmCreate", L"");

			htLanguage = gcnew Hashtable();
			for(int i=0;i<lcgMain->Items->Count;i++)
			{htLanguage->Add(string::Concat(L"frmCreate.",lcgMain->Items[i]->Name),lcgMain->Items[i]);}
			for(int i=0;i<barManager->Items->Count;i++)
			{htLanguage->Add(string::Concat(L"frmCreate.",barManager->Items[i]->Name),barManager->Items[i]);}
			for(int i=0;i<tlArea->Columns->Count;i++)
			{htLanguage->Add(string::Concat(L"frmCreate.",tlArea->Columns[i]->Name),tlArea->Columns[i]);}
			for(int i=0;i<tlDAddr->Columns->Count;i++)
			{htLanguage->Add(string::Concat(L"frmCreate.",tlDAddr->Columns[i]->Name),tlDAddr->Columns[i]);}
			for(int i=0;i<barManager->Bars->Count;i++)
			{htLanguage->Add(string::Concat(L"frmCreate.",barManager->Bars[i]->BarName),barManager->Bars[i]);}
			for(int i=0;i<clbAttributes->Items->Count;i++)
			{htLanguage->Add(string::Concat(L"frmCreate.clbAttributes.Items[",i.ToString(),"]"),clbAttributes->Items[i]);}
		}
		public: void LoadConfigLanguage(string^ Name)
		{
			for(int i=0;i<frmSettings->ConfigLanguage->Rows->Length;i++)
			if (((array<string^> ^)frmSettings->ConfigLanguage->Rows[i])->Length>1)
			{
				if (htLanguage[((array<string^> ^)frmSettings->ConfigLanguage->Rows[i])[0]])
				{Utils::SetValueLanguage(htLanguage[((array<string^> ^)frmSettings->ConfigLanguage->Rows[i])[0]],((array<string^> ^)frmSettings->ConfigLanguage->Rows[i])[1]);}
				else if (htStrings[((array<string^> ^)frmSettings->ConfigLanguage->Rows[i])[0]])
				{htStrings[((array<string^> ^)frmSettings->ConfigLanguage->Rows[i])[0]]=((array<string^> ^)frmSettings->ConfigLanguage->Rows[i])[1];}
			}
			string^ st=L"en";
			if (Name->Equals(L"English")){st=L"en";}
			else if (Name->Equals(L"Russian")){st=L"ru";}
			QWhale::Common::StringConsts::Localize(gcnew System::Globalization::CultureInfo(st));
		}

		public: void LoadConfigSkin(string^ Name)
		{
			for(int i=0;i<barManager->Items->Count;i++)
			{
				if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\small\\",barManager->Items[i]->Name,L".png")))
				{barManager->Items[i]->Glyph = (System::Drawing::Bitmap^)Image::FromFile(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\small\\",barManager->Items[i]->Name, L".png"));}
				else {barManager->Items[i]->Glyph = nullptr;}
				if (barManager->Items[i]->GetType()->ToString()->Equals(
					L"DevExpress.XtraBars.BarLargeButtonItem"))
				if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\large\\",barManager->Items[i]->Name,L".png")))
				{((DevExpress::XtraBars::BarLargeButtonItem^)barManager->Items[i])->LargeGlyph = (System::Drawing::Bitmap^)Image::FromFile(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\large\\",barManager->Items[i]->Name, L".png"));}
				else {((DevExpress::XtraBars::BarLargeButtonItem^)barManager->Items[i])->LargeGlyph = nullptr;}
			}

			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\tlArea.xml")))
			{tlArea->Appearance->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\tlArea.xml"));}
			else {tlArea->Appearance->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\skins\\default\\tlArea.xml"));}

			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\tlDAddr.xml")))
			{tlDAddr->Appearance->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\tlDAddr.xml"));}
			else {tlDAddr->Appearance->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\skins\\default\\tlDAddr.xml"));}

			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\message.xml")))
				{rtText->Lexer->LoadScheme(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\message.xml"));}
			else {rtText->Lexer->LoadScheme(string::Concat(HellEdDir,L"\\skins\\default\\message.xml"));}
		}
		
		public: void LoadConfigForms()
		{
			ConfigForms->Load(string::Concat(HellEdDir,L"\\frmcreate.cfg"),false,65001);
			while(ConfigForms->LoadRow())
			if (ConfigForms->CurRow->Length>1)
			{
				if (ConfigForms->CurRow[0]->Equals(
					L"frmCreate.WindowState"))
				{
					if (ConfigForms->CurRow[1]->Equals(
						L"Maximized")){WindowState=System::Windows::Forms::FormWindowState::Maximized;}
					if (ConfigForms->CurRow[1]->Equals(
						L"Minimized")){WindowState=System::Windows::Forms::FormWindowState::Minimized;}
					if (ConfigForms->CurRow[1]->Equals(
						L"Normal")){WindowState=System::Windows::Forms::FormWindowState::Normal;}
				}
				if (ConfigForms->CurRow[0]->Equals(
					L"frmCreate.Width")){Width=Convert::ToInt32(ConfigForms->CurRow[1]);}
				if (ConfigForms->CurRow[0]->Equals(
					L"frmCreate.Height")){Height=Convert::ToInt32(ConfigForms->CurRow[1]);}
				if (ConfigForms->CurRow[0]->Equals(
					L"frmCreate.pccArea.Width"))
				{pccArea->Size=System::Drawing::Size(Convert::ToInt32(ConfigForms->CurRow[1]),pccArea->Size.Height);}
				if (ConfigForms->CurRow[0]->Equals(
					L"frmCreate.pccArea.Height"))
				{pccArea->Size=System::Drawing::Size(pccArea->Size.Width,Convert::ToInt32(ConfigForms->CurRow[1]));}
				if (ConfigForms->CurRow[0]->Equals(
					L"frmCreate.pccDAddr.Width"))
				{pccDAddr->Size=System::Drawing::Size(Convert::ToInt32(ConfigForms->CurRow[1]),pccDAddr->Size.Height);}
				if (ConfigForms->CurRow[0]->Equals(
					L"frmCreate.pccDAddr.Height"))
				{pccDAddr->Size=System::Drawing::Size(pccDAddr->Size.Width,Convert::ToInt32(ConfigForms->CurRow[1]));}
				if (ConfigForms->CurRow[0]->Equals(
					L"frmCreate.pccAttributes.Width"))
				{pccAttributes->Size=System::Drawing::Size(Convert::ToInt32(ConfigForms->CurRow[1]),pccAttributes->Size.Height);}
				if (ConfigForms->CurRow[0]->Equals(
					L"frmCreate.pccAttributes.Height"))
				{pccAttributes->Size=System::Drawing::Size(pccAttributes->Size.Width,Convert::ToInt32(ConfigForms->CurRow[1]));}
			}
			if (File::Exists(string::Concat(HellEdDir,L"\\barscreate.xml")))
				barManager->RestoreFromXml(string::Concat(HellEdDir,L"\\barscreate.xml"));
			if (File::Exists(string::Concat(HellEdDir,L"\\tlarea.xml")))
				tlArea->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\tlarea.xml"));
			if (File::Exists(string::Concat(HellEdDir,L"\\tldaddr.xml")))
				tlDAddr->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\tldaddr.xml"));
			if (File::Exists(string::Concat(HellEdDir,L"\\frmcreate.xml")))
				LayoutControl->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\frmcreate.xml"));
		}
		public: void SaveConfigForms()
		{
			barManager->SaveToXml(string::Concat(HellEdDir,L"\\barscreate.xml"));
			tlArea->SaveLayoutToXml(string::Concat(HellEdDir,L"\\tlarea.xml"));
			tlDAddr->SaveLayoutToXml(string::Concat(HellEdDir,L"\\tldaddr.xml"));
			LayoutControl->SaveLayoutToXml(string::Concat(HellEdDir,L"\\frmcreate.xml"));
			ConfigForms->BeginSave(string::Concat(HellEdDir,L"\\frmcreate.cfg"),false,65001);
			ConfigForms->Add(L"#frmCreate");
			ConfigForms->Add(L"frmCreate.WindowState",this->WindowState.ToString());
			WindowState=System::Windows::Forms::FormWindowState::Normal;
			ConfigForms->Add(L"frmCreate.Width",Width.ToString());
			ConfigForms->Add(L"frmCreate.Height",Height.ToString());
			ConfigForms->Add(L"frmCreate.pccArea.Width",pccArea->Size.Width.ToString());
			ConfigForms->Add(L"frmCreate.pccArea.Height",pccArea->Size.Height.ToString());
			ConfigForms->Add(L"frmCreate.pccDAddr.Width",pccDAddr->Size.Width.ToString());
			ConfigForms->Add(L"frmCreate.pccDAddr.Height",pccDAddr->Size.Height.ToString());
			ConfigForms->Add(L"frmCreate.pccAttributes.Width",pccAttributes->Size.Width.ToString());
			ConfigForms->Add(L"frmCreate.pccAttributes.Height",pccAttributes->Size.Height.ToString());
			ConfigForms->EndSave();
		}
};
}