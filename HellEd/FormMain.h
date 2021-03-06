/////////////////////////////////////////////////////////////////////////////
//
// HellEd
//
// FormMain.h
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
#include "Utils.h"

#include "FormSettings.h"
#include "FormSplash.h"
#include "FormCreate.h"
#include "FormAbout.h"
#include "FormInputBox.h"
#include "FormPopup.h"

#ifdef GetCurrentDirectory
#undef GetCurrentDirectory
#endif


namespace HellEd {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::Runtime::InteropServices;

	using namespace DevExpress::XtraEditors;
	using namespace DevExpress::XtraEditors::Repository;
	using namespace DevExpress::XtraTreeList;
	using namespace DevExpress::XtraTreeList::Columns;
	using namespace DevExpress::XtraTreeList::Nodes;
	using namespace DevExpress::XtraGrid;
	using namespace DevExpress::XtraBars;
	using namespace DevExpress::XtraTab;
	using namespace mshtml;

	/// <summary>
	/// Summary for FormMain
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>

	public ref class FormMain : public System::Windows::Forms::Form
	{
		public: FormSettings^ frmSettings;
		public: FormSplash^ frmSplash;
		public: FormAbout^ frmAbout;
		public: FormInputBox^ InputBox;
		public: FormPopup^ frmPopup;
		public: Config^ ConfigForms;
		public: Config^ ConfigAreas;
		public: Config^ ConfigTosser;
		public: Config^ ConfigSkin;
		public: Config^ ConfigSmiles;
		public: Config^ ConfigFilter;
		public: Config^ ConfigHistory;
		
		public: StreamWriter^ LogHED;
		
		public: string^ HellEdDir;

		public: HAREA harea;
		public: word msgn;
		public: array<rtlMessages^> ^ msgs;
		public: string^ attributes;
		public: string^ text;
		public: Hashtable^ htkludges;
		public: Hashtable^ hteomkludges;
		public: string^ html;
		public: string^ oname;
		public: string^ dname;
		public: string^ oaddr;
		public: string^ daddr;
		public: string^ subject;
		public: System::DateTime odatetime;
		public: System::DateTime ddatetime;
		public:	int ni;
		public: int ani;
		public:	int si;
		public: string^ area;
		public: string^ nmsgid;
		public: int StartTick;
		public: int LastTosserTick;
		
		public: TreeListNode^ agn;
		public: bool rtTextFlag;
		public: bool LoadConfigTosserFlag;
		public: bool ShowMessagesFlag;
		public: bool ShowAreasFlag;
		public: bool CheckForUpdatesFlag;
		public: bool UpdateMessagesFlag;
		public: bool HistoryFlag;

		public: Hashtable^ htStrings;
		public: Hashtable^ htLanguage;
		public:	BarLoc^ bl;
		public:	LayoutLoc^ ll;
		public:	TreeListLoc^ tll;
		public:	SpellCheckerLoc^ scl;
		public:	EditorLoc^ el;

		public: string^ FilterFrom;
		public: string^ FilterTo;
		public: string^ FilterSubject;
		public: string^ FilterDateTime1;
		public: string^ FilterDateTime2;
		public: bool FilterFromEnabled;
		public: bool FilterToEnabled;
		public: bool FilterSubjectEnabled;
		public: bool FilterMarkEnabled;
		public: bool FilterDateTimeEnabled;

		public: FormWindowState previousState;
		public: System::Windows::Forms::NotifyIcon^ notifyicon;
		public: DevExpress::XtraEditors::Repository::RepositoryItemTextEdit^ rte;
		public: DevExpress::XtraEditors::Repository::RepositoryItemTextEdit^ rtero;
		public: DevExpress::XtraTreeList::TreeList^ tlAreas;

		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcName;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcDescription;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcNode;

		public: DevExpress::XtraTreeList::Blending::XtraTreeListBlending^ xtlbAreas;
		public: DevExpress::XtraTreeList::Blending::XtraTreeListBlending^ xtlbHistory;
		public: DevExpress::XtraTreeList::Blending::XtraTreeListBlending^ xtlbMessages;

		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcCount;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcNotRead;

		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcAddress;

		public: DevExpress::XtraBars::BarDockControl^ barDockControl1;
		public: DevExpress::XtraBars::BarDockControl^ barDockControl2;
		public: DevExpress::XtraBars::BarDockControl^ barDockControl3;
		public: DevExpress::XtraBars::BarDockControl^ barDockControl4;
		public: DevExpress::XtraBars::BarManager^ barManager;
		public: DevExpress::XtraBars::Bar^ barMenu;

		public: DevExpress::XtraBars::Bar^ barStatus;
		public: DevExpress::XtraBars::BarSubItem^ mFile;
		public: DevExpress::XtraBars::BarStaticItem^ sArea;
		public: DevExpress::XtraBars::BarSubItem^ mEdit;
		public: DevExpress::XtraBars::BarSubItem^ mMessage;
		public: DevExpress::XtraBars::BarSubItem^ mService;
		public: DevExpress::XtraBars::BarSubItem^ mHelp;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bNewGroup;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bDeleteGroup;

		public: DevExpress::XtraBars::BarLargeButtonItem^ bPreviousArea;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bNextArea;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bHistoryBack;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bHistoryForward;

		public: DevExpress::XtraBars::BarLargeButtonItem^ bSaveMessage;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bSaveAsTemplate;

		public: DevExpress::XtraBars::BarLargeButtonItem^ bPrint;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bExit;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bCopy;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bSelectAll;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bFind;
		public: DevExpress::XtraBars::BarSubItem^ mCreate;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bReply;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bForward;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bEdit;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bDelete;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bRestore;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bPrevious;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bNext;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bSettings;
		public: DevExpress::XtraBars::BarSubItem^ mSkin;
		public: DevExpress::XtraBars::BarSubItem^ mLanguage;
		public: DevExpress::XtraBars::BarSubItem^ mMessagesView;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bTosser;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bClearHistory;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bCustomize;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bHelp;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bAbout;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bCheckForUpdates;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bNew;
		public: DevExpress::XtraBars::BarListItem^ lTemplate;
		public: DevExpress::XtraBars::BarListItem^ lFilter;
		public: DevExpress::XtraBars::BarListItem^ lSkin;
		public: DevExpress::XtraBars::BarListItem^ lLanguage;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bList;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bTree;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bCreate;
		public: DevExpress::XtraTreeList::TreeList^ tlMessages;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcN;

		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcBaseType;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcAreaType;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcPath;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcAttributes;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcOName;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcDName;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcSubject;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcODateTime;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcDDateTime;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcArea;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcMSGID;



		public: System::Windows::Forms::ImageList^ iltlMessages;
		public: System::Windows::Forms::ImageList^ iltlAreas;
		public: System::Windows::Forms::ImageList^ iltlHistory;

		public: DevExpress::XtraBars::BarLargeButtonItem^ bMark;
		public: DevExpress::XtraBars::BarSubItem^ mView;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcMark;

		public: DevExpress::XtraEditors::Repository::RepositoryItemCheckEdit^ rche;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bDecryptROT13;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bMarkAll;
		public: DevExpress::XtraBars::BarSubItem^ mFilter;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bMarkAsRead;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bMarkAsUnread;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bMarkAllAsRead;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bUnmarkAll;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bHideUnmarked;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bInvertMark;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bShowAll;
		public: DevExpress::XtraBars::BarLargeButtonItem^ bFilterNone;

		public: DevExpress::XtraBars::PopupMenu^ pmCreate;
		public: DevExpress::XtraBars::PopupMenu^ pmAreas;
		public: DevExpress::XtraBars::PopupMenu^ pmEdit;
		public: DevExpress::XtraBars::PopupMenu^ pmNotify;
		public: DevExpress::XtraBars::Bar^ barMessage;
		public: DevExpress::XtraBars::Bar^ barService;

		public: DevExpress::XtraBars::BarSubItem^ mDisplay;

		public: DevExpress::XtraBars::BarStaticItem^ sN;
		public: DevExpress::XtraBars::BarStaticItem^ sCount;
		public: DevExpress::XtraBars::BarStaticItem^ sNotRead;
		public: DevExpress::XtraBars::BarSubItem^ mToolbars;
		public: DevExpress::XtraBars::BarToolbarsListItem^ lToolbars;
		public: DevExpress::XtraBars::Bar^ barFile;
		public: DevExpress::XtraBars::Bar^ barEdit;
		public: DevExpress::XtraBars::Bar^ barHelp;
		public: DevExpress::XtraBars::Docking::DockManager^  dockManager;

		public: DevExpress::XtraBars::Docking::DockPanel^  dpAreas;

		public: DevExpress::XtraSpellChecker::SpellChecker^  spell;

		public: DevExpress::XtraBars::Docking::ControlContainer^  dpAreas_Container;

		public: DevExpress::XtraBars::Docking::DockPanel^  dpMessages;
		public: DevExpress::XtraBars::Docking::ControlContainer^  dpMessages_Container;
		public: DevExpress::XtraBars::BarAndDockingController^  barAndDockingController;

		public: DevExpress::XtraBars::BarSubItem^  mArea;
		public: DevExpress::XtraBars::BarLargeButtonItem^  bSubscribe;
		public: DevExpress::XtraBars::Bar^  barArea;
		public: DevExpress::XtraBars::BarLargeButtonItem^  bUnsubscribe;
		public: DevExpress::XtraBars::BarLargeButtonItem^  bUseStyles;
		public: DevExpress::XtraBars::BarLargeButtonItem^  bNextUnread;
		public: DevExpress::XtraBars::BarSubItem^  mShowKludgesMode;
		public: DevExpress::XtraBars::BarListItem^  lShowKludgesMode;
		public: DevExpress::XtraBars::Bar^  barURL;
		public: DevExpress::XtraBars::BarEditItem^  beURL;
		public: DevExpress::XtraEditors::Repository::RepositoryItemComboBox^  rcbeURL;
		public: DevExpress::XtraBars::PopupMenu^  pmMessages;
		public: DevExpress::XtraBars::BarLargeButtonItem^  bAddressBook;
		public: DevExpress::XtraBars::Docking::DockPanel^  panelContainer;
		public: DevExpress::XtraBars::Docking::DockPanel^  dpHistory;
		public: DevExpress::XtraBars::Docking::ControlContainer^  dockPanel1_Container;
		public: DevExpress::XtraTreeList::TreeList^  tlHistory;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^  tlcURL;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^  tlcDateTime;
		public: DevExpress::XtraLayout::LayoutControl^  LayoutControl;
		public: DevExpress::XtraEditors::TextEdit^  teReceived;
		public: System::Windows::Forms::WebBrowser^  rtText;
		public: DevExpress::XtraEditors::TextEdit^  teWritten;
		public: DevExpress::XtraEditors::TextEdit^  teSubject;
		public: DevExpress::XtraEditors::TextEdit^  teFrom;
		public: DevExpress::XtraEditors::TextEdit^  teTo;
		public: DevExpress::XtraEditors::PictureEdit^  peFrom;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciReceived;
		public: DevExpress::XtraLayout::LayoutControlGroup^  lcgMain;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciFrom;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciWritten;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciPhoto;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciSubject;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciTo;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciText;
		public: DevExpress::XtraEditors::TextEdit^  teAttributes;
		public: DevExpress::XtraLayout::LayoutControlItem^  lciAttributes;
		public: System::Windows::Forms::Timer^  tiMain;
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected: ~FormMain()
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
			DevExpress::XtraSpellChecker::OptionsSpelling^  optionsSpelling1 = (gcnew DevExpress::XtraSpellChecker::OptionsSpelling());
			DevExpress::XtraSpellChecker::OptionsSpelling^  optionsSpelling2 = (gcnew DevExpress::XtraSpellChecker::OptionsSpelling());
			DevExpress::XtraSpellChecker::OptionsSpelling^  optionsSpelling3 = (gcnew DevExpress::XtraSpellChecker::OptionsSpelling());
			DevExpress::XtraSpellChecker::OptionsSpelling^  optionsSpelling4 = (gcnew DevExpress::XtraSpellChecker::OptionsSpelling());
			DevExpress::XtraSpellChecker::OptionsSpelling^  optionsSpelling5 = (gcnew DevExpress::XtraSpellChecker::OptionsSpelling());
			DevExpress::XtraSpellChecker::OptionsSpelling^  optionsSpelling6 = (gcnew DevExpress::XtraSpellChecker::OptionsSpelling());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMain::typeid));
			this->tiMain = (gcnew System::Windows::Forms::Timer(this->components));
			this->spell = (gcnew DevExpress::XtraSpellChecker::SpellChecker());
			this->teReceived = (gcnew DevExpress::XtraEditors::TextEdit());
			this->LayoutControl = (gcnew DevExpress::XtraLayout::LayoutControl());
			this->teAttributes = (gcnew DevExpress::XtraEditors::TextEdit());
			this->rtText = (gcnew System::Windows::Forms::WebBrowser());
			this->teWritten = (gcnew DevExpress::XtraEditors::TextEdit());
			this->teSubject = (gcnew DevExpress::XtraEditors::TextEdit());
			this->teFrom = (gcnew DevExpress::XtraEditors::TextEdit());
			this->teTo = (gcnew DevExpress::XtraEditors::TextEdit());
			this->peFrom = (gcnew DevExpress::XtraEditors::PictureEdit());
			this->lcgMain = (gcnew DevExpress::XtraLayout::LayoutControlGroup());
			this->lciFrom = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciWritten = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciPhoto = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciSubject = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciTo = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciText = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciReceived = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->lciAttributes = (gcnew DevExpress::XtraLayout::LayoutControlItem());
			this->rte = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemTextEdit());
			this->rtero = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemTextEdit());
			this->tlMessages = (gcnew DevExpress::XtraTreeList::TreeList());
			this->tlcN = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcMark = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->rche = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemCheckEdit());
			this->tlcAttributes = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcOName = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcDName = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcSubject = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcODateTime = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcDDateTime = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcArea = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcMSGID = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->iltlMessages = (gcnew System::Windows::Forms::ImageList(this->components));
			this->iltlAreas = (gcnew System::Windows::Forms::ImageList(this->components));
			this->iltlHistory = (gcnew System::Windows::Forms::ImageList(this->components));
			this->tlAreas = (gcnew DevExpress::XtraTreeList::TreeList());
			this->tlcName = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcCount = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcNotRead = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcDescription = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcPath = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcAddress = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcBaseType = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcAreaType = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcNode = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->xtlbAreas = (gcnew DevExpress::XtraTreeList::Blending::XtraTreeListBlending());
			this->xtlbHistory = (gcnew DevExpress::XtraTreeList::Blending::XtraTreeListBlending());
			this->xtlbMessages = (gcnew DevExpress::XtraTreeList::Blending::XtraTreeListBlending());
			this->barManager = (gcnew DevExpress::XtraBars::BarManager(this->components));
			this->barMenu = (gcnew DevExpress::XtraBars::Bar());
			this->mFile = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bSaveMessage = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bSaveAsTemplate = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bPrint = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bExit = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->mEdit = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bCopy = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bSelectAll = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bFind = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->mView = (gcnew DevExpress::XtraBars::BarSubItem());
			this->mSkin = (gcnew DevExpress::XtraBars::BarSubItem());
			this->lSkin = (gcnew DevExpress::XtraBars::BarListItem());
			this->mLanguage = (gcnew DevExpress::XtraBars::BarSubItem());
			this->lLanguage = (gcnew DevExpress::XtraBars::BarListItem());
			this->mMessagesView = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bList = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bTree = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->mDisplay = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bHideUnmarked = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bShowAll = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->mShowKludgesMode = (gcnew DevExpress::XtraBars::BarSubItem());
			this->lShowKludgesMode = (gcnew DevExpress::XtraBars::BarListItem());
			this->bDecryptROT13 = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bUseStyles = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->mToolbars = (gcnew DevExpress::XtraBars::BarSubItem());
			this->lToolbars = (gcnew DevExpress::XtraBars::BarToolbarsListItem());
			this->mArea = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bNewGroup = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bPreviousArea = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bNextArea = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bSubscribe = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bUnsubscribe = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->mMessage = (gcnew DevExpress::XtraBars::BarSubItem());
			this->mCreate = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bNew = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->lTemplate = (gcnew DevExpress::XtraBars::BarListItem());
			this->bReply = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bForward = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bEdit = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bDelete = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bRestore = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bMark = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->mFilter = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bFilterNone = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->lFilter = (gcnew DevExpress::XtraBars::BarListItem());
			this->bMarkAll = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bUnmarkAll = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bInvertMark = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bMarkAsRead = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bMarkAsUnread = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bMarkAllAsRead = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bPrevious = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bNext = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bNextUnread = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->mService = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bSettings = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bAddressBook = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bClearHistory = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bCustomize = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bTosser = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->mHelp = (gcnew DevExpress::XtraBars::BarSubItem());
			this->bHelp = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bAbout = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bCheckForUpdates = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->barMessage = (gcnew DevExpress::XtraBars::Bar());
			this->bCreate = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->pmCreate = (gcnew DevExpress::XtraBars::PopupMenu(this->components));
			this->barStatus = (gcnew DevExpress::XtraBars::Bar());
			this->sArea = (gcnew DevExpress::XtraBars::BarStaticItem());
			this->sN = (gcnew DevExpress::XtraBars::BarStaticItem());
			this->sCount = (gcnew DevExpress::XtraBars::BarStaticItem());
			this->sNotRead = (gcnew DevExpress::XtraBars::BarStaticItem());
			this->barService = (gcnew DevExpress::XtraBars::Bar());
			this->barFile = (gcnew DevExpress::XtraBars::Bar());
			this->barEdit = (gcnew DevExpress::XtraBars::Bar());
			this->barHelp = (gcnew DevExpress::XtraBars::Bar());
			this->barArea = (gcnew DevExpress::XtraBars::Bar());
			this->barURL = (gcnew DevExpress::XtraBars::Bar());
			this->bHistoryBack = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bHistoryForward = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->beURL = (gcnew DevExpress::XtraBars::BarEditItem());
			this->rcbeURL = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemComboBox());
			this->barAndDockingController = (gcnew DevExpress::XtraBars::BarAndDockingController(this->components));
			this->barDockControl1 = (gcnew DevExpress::XtraBars::BarDockControl());
			this->barDockControl2 = (gcnew DevExpress::XtraBars::BarDockControl());
			this->barDockControl3 = (gcnew DevExpress::XtraBars::BarDockControl());
			this->barDockControl4 = (gcnew DevExpress::XtraBars::BarDockControl());
			this->dockManager = (gcnew DevExpress::XtraBars::Docking::DockManager(this->components));
			this->panelContainer = (gcnew DevExpress::XtraBars::Docking::DockPanel());
			this->dpAreas = (gcnew DevExpress::XtraBars::Docking::DockPanel());
			this->dpAreas_Container = (gcnew DevExpress::XtraBars::Docking::ControlContainer());
			this->dpHistory = (gcnew DevExpress::XtraBars::Docking::DockPanel());
			this->dockPanel1_Container = (gcnew DevExpress::XtraBars::Docking::ControlContainer());
			this->tlHistory = (gcnew DevExpress::XtraTreeList::TreeList());
			this->tlcURL = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcDateTime = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->dpMessages = (gcnew DevExpress::XtraBars::Docking::DockPanel());
			this->dpMessages_Container = (gcnew DevExpress::XtraBars::Docking::ControlContainer());
			this->bDeleteGroup = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->pmEdit = (gcnew DevExpress::XtraBars::PopupMenu(this->components));
			this->pmNotify = (gcnew DevExpress::XtraBars::PopupMenu(this->components));
			this->pmAreas = (gcnew DevExpress::XtraBars::PopupMenu(this->components));
			this->notifyicon = (gcnew System::Windows::Forms::NotifyIcon(this->components));
			this->pmMessages = (gcnew DevExpress::XtraBars::PopupMenu(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teReceived->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->LayoutControl))->BeginInit();
			this->LayoutControl->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teAttributes->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teWritten->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teSubject->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teFrom->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teTo->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->peFrom->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lcgMain))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciFrom))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciWritten))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciPhoto))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciSubject))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciTo))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciText))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciReceived))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciAttributes))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rte))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rtero))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlMessages))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rche))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlAreas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barManager))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmCreate))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbeURL))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barAndDockingController))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dockManager))->BeginInit();
			this->panelContainer->SuspendLayout();
			this->dpAreas->SuspendLayout();
			this->dpAreas_Container->SuspendLayout();
			this->dpHistory->SuspendLayout();
			this->dockPanel1_Container->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlHistory))->BeginInit();
			this->dpMessages->SuspendLayout();
			this->dpMessages_Container->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmEdit))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmNotify))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmAreas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmMessages))->BeginInit();
			this->SuspendLayout();
			// 
			// tiMain
			// 
			this->tiMain->Tick += gcnew System::EventHandler(this, &FormMain::tiMain_Tick);
			// 
			// spell
			// 
			this->spell->Culture = (gcnew System::Globalization::CultureInfo(L"ru-RU"));
			// 
			// teReceived
			// 
			this->spell->SetCanCheckText(this->teReceived, false);
			this->teReceived->Location = System::Drawing::Point(67, 133);
			this->teReceived->Name = L"teReceived";
			this->teReceived->Properties->BorderStyle = DevExpress::XtraEditors::Controls::BorderStyles::NoBorder;
			this->teReceived->Properties->ReadOnly = true;
			this->spell->SetShowSpellCheckMenu(this->teReceived, true);
			this->teReceived->Size = System::Drawing::Size(602, 18);
			this->spell->SetSpellCheckerOptions(this->teReceived, optionsSpelling1);
			this->teReceived->StyleController = this->LayoutControl;
			this->teReceived->TabIndex = 13;
			// 
			// LayoutControl
			// 
			this->LayoutControl->Controls->Add(this->teAttributes);
			this->LayoutControl->Controls->Add(this->rtText);
			this->LayoutControl->Controls->Add(this->teWritten);
			this->LayoutControl->Controls->Add(this->teSubject);
			this->LayoutControl->Controls->Add(this->teReceived);
			this->LayoutControl->Controls->Add(this->teFrom);
			this->LayoutControl->Controls->Add(this->teTo);
			this->LayoutControl->Controls->Add(this->peFrom);
			this->LayoutControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->LayoutControl->Location = System::Drawing::Point(254, 262);
			this->LayoutControl->Name = L"LayoutControl";
			this->LayoutControl->Root = this->lcgMain;
			this->LayoutControl->Size = System::Drawing::Size(675, 348);
			this->LayoutControl->TabIndex = 11;
			// 
			// teAttributes
			// 
			this->spell->SetCanCheckText(this->teAttributes, false);
			this->teAttributes->Location = System::Drawing::Point(67, 162);
			this->teAttributes->Name = L"teAttributes";
			this->teAttributes->Properties->BorderStyle = DevExpress::XtraEditors::Controls::BorderStyles::NoBorder;
			this->teAttributes->Properties->ReadOnly = true;
			this->spell->SetShowSpellCheckMenu(this->teAttributes, true);
			this->teAttributes->Size = System::Drawing::Size(602, 18);
			this->spell->SetSpellCheckerOptions(this->teAttributes, optionsSpelling2);
			this->teAttributes->StyleController = this->LayoutControl;
			this->teAttributes->TabIndex = 14;
			// 
			// rtText
			// 
			this->rtText->AllowWebBrowserDrop = false;
			this->rtText->Location = System::Drawing::Point(7, 191);
			this->rtText->MinimumSize = System::Drawing::Size(20, 20);
			this->rtText->Name = L"rtText";
			this->rtText->Size = System::Drawing::Size(662, 151);
			this->rtText->TabIndex = 11;
			// 
			// teWritten
			// 
			this->spell->SetCanCheckText(this->teWritten, false);
			this->teWritten->Location = System::Drawing::Point(67, 75);
			this->teWritten->Name = L"teWritten";
			this->teWritten->Properties->BorderStyle = DevExpress::XtraEditors::Controls::BorderStyles::NoBorder;
			this->teWritten->Properties->ReadOnly = true;
			this->spell->SetShowSpellCheckMenu(this->teWritten, true);
			this->teWritten->Size = System::Drawing::Size(476, 18);
			this->spell->SetSpellCheckerOptions(this->teWritten, optionsSpelling3);
			this->teWritten->StyleController = this->LayoutControl;
			this->teWritten->TabIndex = 12;
			// 
			// teSubject
			// 
			this->spell->SetCanCheckText(this->teSubject, false);
			this->teSubject->Location = System::Drawing::Point(7, 7);
			this->teSubject->Name = L"teSubject";
			this->teSubject->Properties->Appearance->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Bold, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->teSubject->Properties->Appearance->Options->UseFont = true;
			this->teSubject->Properties->BorderStyle = DevExpress::XtraEditors::Controls::BorderStyles::NoBorder;
			this->teSubject->Properties->ReadOnly = true;
			this->spell->SetShowSpellCheckMenu(this->teSubject, true);
			this->teSubject->Size = System::Drawing::Size(536, 23);
			this->spell->SetSpellCheckerOptions(this->teSubject, optionsSpelling4);
			this->teSubject->StyleController = this->LayoutControl;
			this->teSubject->TabIndex = 10;
			// 
			// teFrom
			// 
			this->spell->SetCanCheckText(this->teFrom, false);
			this->teFrom->Location = System::Drawing::Point(7, 41);
			this->teFrom->Name = L"teFrom";
			this->teFrom->Properties->Appearance->Font = (gcnew System::Drawing::Font(L"Tahoma", 11.25F, System::Drawing::FontStyle::Regular, 
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(204)));
			this->teFrom->Properties->Appearance->Options->UseFont = true;
			this->teFrom->Properties->BorderStyle = DevExpress::XtraEditors::Controls::BorderStyles::NoBorder;
			this->teFrom->Properties->ReadOnly = true;
			this->spell->SetShowSpellCheckMenu(this->teFrom, true);
			this->teFrom->Size = System::Drawing::Size(536, 23);
			this->spell->SetSpellCheckerOptions(this->teFrom, optionsSpelling5);
			this->teFrom->StyleController = this->LayoutControl;
			this->teFrom->TabIndex = 9;
			// 
			// teTo
			// 
			this->spell->SetCanCheckText(this->teTo, false);
			this->teTo->Location = System::Drawing::Point(67, 104);
			this->teTo->Name = L"teTo";
			this->teTo->Properties->BorderStyle = DevExpress::XtraEditors::Controls::BorderStyles::NoBorder;
			this->teTo->Properties->ReadOnly = true;
			this->spell->SetShowSpellCheckMenu(this->teTo, true);
			this->teTo->Size = System::Drawing::Size(476, 18);
			this->spell->SetSpellCheckerOptions(this->teTo, optionsSpelling6);
			this->teTo->StyleController = this->LayoutControl;
			this->teTo->TabIndex = 10;
			// 
			// peFrom
			// 
			this->peFrom->Location = System::Drawing::Point(554, 7);
			this->peFrom->Name = L"peFrom";
			this->peFrom->Properties->AllowFocused = false;
			this->peFrom->Properties->BorderStyle = DevExpress::XtraEditors::Controls::BorderStyles::Simple;
			this->peFrom->Properties->NullText = L" ";
			this->peFrom->Properties->ReadOnly = true;
			this->peFrom->Properties->ShowMenu = false;
			this->peFrom->Properties->SizeMode = DevExpress::XtraEditors::Controls::PictureSizeMode::Stretch;
			this->peFrom->Size = System::Drawing::Size(115, 115);
			this->peFrom->StyleController = this->LayoutControl;
			this->peFrom->TabIndex = 1;
			// 
			// lcgMain
			// 
			this->lcgMain->CustomizationFormText = L"Root";
			this->lcgMain->Items->AddRange(gcnew cli::array< DevExpress::XtraLayout::BaseLayoutItem^  >(8) {this->lciFrom, this->lciWritten, 
				this->lciPhoto, this->lciSubject, this->lciTo, this->lciText, this->lciReceived, this->lciAttributes});
			this->lcgMain->Location = System::Drawing::Point(0, 0);
			this->lcgMain->Name = L"lcgMain";
			this->lcgMain->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lcgMain->Size = System::Drawing::Size(675, 348);
			this->lcgMain->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lcgMain->Text = L"lcgMain";
			this->lcgMain->TextVisible = false;
			// 
			// lciFrom
			// 
			this->lciFrom->Control = this->teFrom;
			this->lciFrom->CustomizationFormText = L"От:";
			this->lciFrom->Location = System::Drawing::Point(0, 34);
			this->lciFrom->Name = L"lciFrom";
			this->lciFrom->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciFrom->Size = System::Drawing::Size(547, 34);
			this->lciFrom->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciFrom->Text = L"От:";
			this->lciFrom->TextSize = System::Drawing::Size(0, 0);
			this->lciFrom->TextToControlDistance = 0;
			this->lciFrom->TextVisible = false;
			// 
			// lciWritten
			// 
			this->lciWritten->Control = this->teWritten;
			this->lciWritten->CustomizationFormText = L"Написано:";
			this->lciWritten->Location = System::Drawing::Point(0, 68);
			this->lciWritten->Name = L"lciWritten";
			this->lciWritten->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciWritten->Size = System::Drawing::Size(547, 29);
			this->lciWritten->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciWritten->Text = L"Написано:";
			this->lciWritten->TextSize = System::Drawing::Size(55, 20);
			// 
			// lciPhoto
			// 
			this->lciPhoto->Control = this->peFrom;
			this->lciPhoto->CustomizationFormText = L"Фото:";
			this->lciPhoto->Location = System::Drawing::Point(547, 0);
			this->lciPhoto->Name = L"lciPhoto";
			this->lciPhoto->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciPhoto->Size = System::Drawing::Size(126, 126);
			this->lciPhoto->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciPhoto->Text = L"Фото:";
			this->lciPhoto->TextSize = System::Drawing::Size(0, 0);
			this->lciPhoto->TextToControlDistance = 0;
			this->lciPhoto->TextVisible = false;
			// 
			// lciSubject
			// 
			this->lciSubject->Control = this->teSubject;
			this->lciSubject->CustomizationFormText = L"Тема:";
			this->lciSubject->Location = System::Drawing::Point(0, 0);
			this->lciSubject->Name = L"lciSubject";
			this->lciSubject->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciSubject->Size = System::Drawing::Size(547, 34);
			this->lciSubject->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciSubject->Text = L"Тема:";
			this->lciSubject->TextSize = System::Drawing::Size(0, 0);
			this->lciSubject->TextToControlDistance = 0;
			this->lciSubject->TextVisible = false;
			// 
			// lciTo
			// 
			this->lciTo->Control = this->teTo;
			this->lciTo->CustomizationFormText = L"Кому:";
			this->lciTo->Location = System::Drawing::Point(0, 97);
			this->lciTo->Name = L"lciTo";
			this->lciTo->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciTo->Size = System::Drawing::Size(547, 29);
			this->lciTo->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciTo->Text = L"Кому:";
			this->lciTo->TextSize = System::Drawing::Size(55, 20);
			// 
			// lciText
			// 
			this->lciText->Control = this->rtText;
			this->lciText->CustomizationFormText = L"Текст:";
			this->lciText->Location = System::Drawing::Point(0, 184);
			this->lciText->Name = L"lciText";
			this->lciText->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciText->Size = System::Drawing::Size(673, 162);
			this->lciText->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciText->Text = L"Текст:";
			this->lciText->TextSize = System::Drawing::Size(0, 0);
			this->lciText->TextToControlDistance = 0;
			this->lciText->TextVisible = false;
			// 
			// lciReceived
			// 
			this->lciReceived->Control = this->teReceived;
			this->lciReceived->CustomizationFormText = L"Получено:";
			this->lciReceived->Location = System::Drawing::Point(0, 126);
			this->lciReceived->Name = L"lciReceived";
			this->lciReceived->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciReceived->Size = System::Drawing::Size(673, 29);
			this->lciReceived->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciReceived->Text = L"Получено:";
			this->lciReceived->TextSize = System::Drawing::Size(55, 20);
			// 
			// lciAttributes
			// 
			this->lciAttributes->Control = this->teAttributes;
			this->lciAttributes->CustomizationFormText = L"Атрибуты:";
			this->lciAttributes->Location = System::Drawing::Point(0, 155);
			this->lciAttributes->Name = L"lciAttributes";
			this->lciAttributes->Padding = (gcnew DevExpress::XtraLayout::Utils::Padding(5, 5, 5, 5));
			this->lciAttributes->Size = System::Drawing::Size(673, 29);
			this->lciAttributes->Spacing = (gcnew DevExpress::XtraLayout::Utils::Padding(0, 0, 0, 0));
			this->lciAttributes->Text = L"Атрибуты:";
			this->lciAttributes->TextSize = System::Drawing::Size(55, 20);
			// 
			// rte
			// 
			this->rte->AutoHeight = false;
			this->rte->Name = L"rte";
			// 
			// rtero
			// 
			this->rtero->AutoHeight = false;
			this->rtero->Name = L"rtero";
			this->rtero->ReadOnly = true;
			// 
			// tlMessages
			// 
			this->tlMessages->Columns->AddRange(gcnew cli::array< DevExpress::XtraTreeList::Columns::TreeListColumn^  >(10) {this->tlcN, 
				this->tlcMark, this->tlcAttributes, this->tlcOName, this->tlcDName, this->tlcSubject, this->tlcODateTime, this->tlcDDateTime, 
				this->tlcArea, this->tlcMSGID});
			this->tlMessages->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tlMessages->Location = System::Drawing::Point(0, 0);
			this->tlMessages->Name = L"tlMessages";
			this->tlMessages->OptionsBehavior->AutoChangeParent = false;
			this->tlMessages->OptionsBehavior->DragNodes = true;
			this->tlMessages->OptionsBehavior->EnableFiltering = true;
			this->tlMessages->OptionsMenu->EnableFooterMenu = false;
			this->tlMessages->OptionsView->AutoWidth = false;
			this->tlMessages->OptionsView->EnableAppearanceEvenRow = true;
			this->tlMessages->OptionsView->EnableAppearanceOddRow = true;
			this->tlMessages->OptionsView->ShowHorzLines = false;
			this->tlMessages->OptionsView->ShowIndicator = false;
			this->tlMessages->OptionsView->ShowRoot = false;
			this->tlMessages->RepositoryItems->AddRange(gcnew cli::array< DevExpress::XtraEditors::Repository::RepositoryItem^  >(1) {this->rche});
			this->tlMessages->Size = System::Drawing::Size(669, 160);
			this->tlMessages->StateImageList = this->iltlMessages;
			this->tlMessages->TabIndex = 0;
			this->tlMessages->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FormMain::tlMessages_MouseUp);
			this->tlMessages->CustomDrawNodeCell += gcnew DevExpress::XtraTreeList::CustomDrawNodeCellEventHandler(this, &FormMain::tlMessages_CustomDrawNodeCell);
			this->tlMessages->FocusedNodeChanged += gcnew DevExpress::XtraTreeList::FocusedNodeChangedEventHandler(this, &FormMain::tlMessages_FocusedNodeChanged);
			this->tlMessages->FilterNode += gcnew DevExpress::XtraTreeList::FilterNodeEventHandler(this, &FormMain::tlMessages_FilterNode);
			// 
			// tlcN
			// 
			this->tlcN->Caption = L"№";
			this->tlcN->FieldName = L"N";
			this->tlcN->Name = L"tlcN";
			this->tlcN->OptionsColumn->AllowFocus = false;
			this->tlcN->OptionsColumn->ReadOnly = true;
			this->tlcN->Visible = true;
			this->tlcN->VisibleIndex = 3;
			// 
			// tlcMark
			// 
			this->tlcMark->Caption = L"Флаг";
			this->tlcMark->ColumnEdit = this->rche;
			this->tlcMark->FieldName = L"Mark";
			this->tlcMark->Name = L"tlcMark";
			this->tlcMark->Visible = true;
			this->tlcMark->VisibleIndex = 1;
			// 
			// rche
			// 
			this->rche->AutoHeight = false;
			this->rche->Name = L"rche";
			this->rche->NullStyle = DevExpress::XtraEditors::Controls::StyleIndeterminate::Unchecked;
			// 
			// tlcAttributes
			// 
			this->tlcAttributes->Caption = L"Атрибуты";
			this->tlcAttributes->FieldName = L"Attributes";
			this->tlcAttributes->Name = L"tlcAttributes";
			this->tlcAttributes->OptionsColumn->AllowFocus = false;
			this->tlcAttributes->OptionsColumn->ReadOnly = true;
			this->tlcAttributes->Visible = true;
			this->tlcAttributes->VisibleIndex = 5;
			// 
			// tlcOName
			// 
			this->tlcOName->Caption = L"От";
			this->tlcOName->FieldName = L"OName";
			this->tlcOName->MinWidth = 27;
			this->tlcOName->Name = L"tlcOName";
			this->tlcOName->OptionsColumn->AllowFocus = false;
			this->tlcOName->OptionsColumn->ReadOnly = true;
			this->tlcOName->Visible = true;
			this->tlcOName->VisibleIndex = 0;
			// 
			// tlcDName
			// 
			this->tlcDName->Caption = L"Кому";
			this->tlcDName->FieldName = L"DName";
			this->tlcDName->Name = L"tlcDName";
			this->tlcDName->OptionsColumn->AllowFocus = false;
			this->tlcDName->OptionsColumn->ReadOnly = true;
			this->tlcDName->Visible = true;
			this->tlcDName->VisibleIndex = 4;
			// 
			// tlcSubject
			// 
			this->tlcSubject->Caption = L"Тема";
			this->tlcSubject->FieldName = L"Subject";
			this->tlcSubject->Name = L"tlcSubject";
			this->tlcSubject->OptionsColumn->AllowFocus = false;
			this->tlcSubject->OptionsColumn->ReadOnly = true;
			this->tlcSubject->Visible = true;
			this->tlcSubject->VisibleIndex = 2;
			// 
			// tlcODateTime
			// 
			this->tlcODateTime->Caption = L"Написано";
			this->tlcODateTime->FieldName = L"ODateTime";
			this->tlcODateTime->Name = L"tlcODateTime";
			this->tlcODateTime->OptionsColumn->AllowFocus = false;
			this->tlcODateTime->OptionsColumn->ReadOnly = true;
			this->tlcODateTime->Visible = true;
			this->tlcODateTime->VisibleIndex = 6;
			// 
			// tlcDDateTime
			// 
			this->tlcDDateTime->Caption = L"Получено";
			this->tlcDDateTime->FieldName = L"DDateTime";
			this->tlcDDateTime->Name = L"tlcDDateTime";
			this->tlcDDateTime->OptionsColumn->AllowFocus = false;
			this->tlcDDateTime->OptionsColumn->ReadOnly = true;
			this->tlcDDateTime->Visible = true;
			this->tlcDDateTime->VisibleIndex = 7;
			// 
			// tlcArea
			// 
			this->tlcArea->Caption = L"Область";
			this->tlcArea->FieldName = L"Area";
			this->tlcArea->Name = L"tlcArea";
			this->tlcArea->OptionsColumn->AllowFocus = false;
			this->tlcArea->OptionsColumn->ReadOnly = true;
			this->tlcArea->Visible = true;
			this->tlcArea->VisibleIndex = 8;
			// 
			// tlcMSGID
			// 
			this->tlcMSGID->Caption = L"MSGID";
			this->tlcMSGID->FieldName = L"MSGID";
			this->tlcMSGID->Name = L"tlcMSGID";
			this->tlcMSGID->OptionsColumn->AllowFocus = false;
			this->tlcMSGID->OptionsColumn->ReadOnly = true;
			this->tlcMSGID->Visible = true;
			this->tlcMSGID->VisibleIndex = 9;
			// 
			// iltlMessages
			// 
			this->iltlMessages->ColorDepth = System::Windows::Forms::ColorDepth::Depth32Bit;
			this->iltlMessages->ImageSize = System::Drawing::Size(16, 16);
			this->iltlMessages->TransparentColor = System::Drawing::Color::Magenta;
			// 
			// iltlAreas
			// 
			this->iltlAreas->ColorDepth = System::Windows::Forms::ColorDepth::Depth32Bit;
			this->iltlAreas->ImageSize = System::Drawing::Size(16, 16);
			this->iltlAreas->TransparentColor = System::Drawing::Color::Magenta;
			// 
			// iltlHistory
			// 
			this->iltlHistory->ColorDepth = System::Windows::Forms::ColorDepth::Depth32Bit;
			this->iltlHistory->ImageSize = System::Drawing::Size(16, 16);
			this->iltlHistory->TransparentColor = System::Drawing::Color::Magenta;
			// 
			// tlAreas
			// 
			this->tlAreas->Columns->AddRange(gcnew cli::array< DevExpress::XtraTreeList::Columns::TreeListColumn^  >(9) {this->tlcName, 
				this->tlcCount, this->tlcNotRead, this->tlcDescription, this->tlcPath, this->tlcAddress, this->tlcBaseType, this->tlcAreaType, 
				this->tlcNode});
			this->tlAreas->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tlAreas->Location = System::Drawing::Point(0, 0);
			this->tlAreas->Name = L"tlAreas";
			this->tlAreas->OptionsBehavior->AutoChangeParent = false;
			this->tlAreas->OptionsBehavior->DragNodes = true;
			this->tlAreas->OptionsBehavior->ShowToolTips = false;
			this->tlAreas->OptionsMenu->EnableFooterMenu = false;
			this->tlAreas->OptionsView->AutoWidth = false;
			this->tlAreas->OptionsView->EnableAppearanceEvenRow = true;
			this->tlAreas->OptionsView->EnableAppearanceOddRow = true;
			this->tlAreas->OptionsView->ShowHorzLines = false;
			this->tlAreas->OptionsView->ShowIndicator = false;
			this->tlAreas->Size = System::Drawing::Size(248, 486);
			this->tlAreas->StateImageList = this->iltlAreas;
			this->tlAreas->TabIndex = 0;
			this->tlAreas->AfterDragNode += gcnew DevExpress::XtraTreeList::NodeEventHandler(this, &FormMain::tlAreas_AfterDragNode);
			this->tlAreas->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FormMain::tlAreas_MouseUp);
			this->tlAreas->CustomDrawNodeCell += gcnew DevExpress::XtraTreeList::CustomDrawNodeCellEventHandler(this, &FormMain::tlAreas_CustomDrawNodeCell);
			this->tlAreas->GetCustomNodeCellEdit += gcnew DevExpress::XtraTreeList::GetCustomNodeCellEditEventHandler(this, &FormMain::tlAreas_GetCustomNodeCellEdit);
			this->tlAreas->FocusedNodeChanged += gcnew DevExpress::XtraTreeList::FocusedNodeChangedEventHandler(this, &FormMain::tlAreas_FocusedNodeChanged);
			this->tlAreas->BeforeDragNode += gcnew DevExpress::XtraTreeList::BeforeDragNodeEventHandler(this, &FormMain::tlAreas_BeforeDragNode);
			this->tlAreas->BeforeFocusNode += gcnew DevExpress::XtraTreeList::BeforeFocusNodeEventHandler(this, &FormMain::tlAreas_BeforeFocusNode);
			this->tlAreas->CellValueChanged += gcnew DevExpress::XtraTreeList::CellValueChangedEventHandler(this, &FormMain::tlAreas_CellValueChanged);
			this->tlAreas->DragDrop += gcnew System::Windows::Forms::DragEventHandler(this, &FormMain::tlAreas_DragDrop);
			this->tlAreas->DragEnter += gcnew System::Windows::Forms::DragEventHandler(this, &FormMain::tlAreas_DragEnter);
			// 
			// tlcName
			// 
			this->tlcName->Caption = L"Название";
			this->tlcName->FieldName = L"Name";
			this->tlcName->MinWidth = 27;
			this->tlcName->Name = L"tlcName";
			this->tlcName->OptionsColumn->AllowFocus = false;
			this->tlcName->OptionsColumn->AllowSort = false;
			this->tlcName->Visible = true;
			this->tlcName->VisibleIndex = 0;
			this->tlcName->Width = 170;
			// 
			// tlcCount
			// 
			this->tlcCount->Caption = L"Сообщений";
			this->tlcCount->FieldName = L"Count";
			this->tlcCount->Name = L"tlcCount";
			this->tlcCount->OptionsColumn->AllowFocus = false;
			this->tlcCount->OptionsColumn->AllowSort = false;
			this->tlcCount->OptionsColumn->ReadOnly = true;
			this->tlcCount->Visible = true;
			this->tlcCount->VisibleIndex = 5;
			this->tlcCount->Width = 32;
			// 
			// tlcNotRead
			// 
			this->tlcNotRead->Caption = L"Не прочитано";
			this->tlcNotRead->FieldName = L"NotRead";
			this->tlcNotRead->Name = L"tlcNotRead";
			this->tlcNotRead->OptionsColumn->AllowFocus = false;
			this->tlcNotRead->OptionsColumn->AllowSort = false;
			this->tlcNotRead->OptionsColumn->ReadOnly = true;
			this->tlcNotRead->Visible = true;
			this->tlcNotRead->VisibleIndex = 6;
			this->tlcNotRead->Width = 32;
			// 
			// tlcDescription
			// 
			this->tlcDescription->Caption = L"Описание";
			this->tlcDescription->FieldName = L"Description";
			this->tlcDescription->Name = L"tlcDescription";
			this->tlcDescription->OptionsColumn->AllowFocus = false;
			this->tlcDescription->OptionsColumn->AllowSort = false;
			this->tlcDescription->Visible = true;
			this->tlcDescription->VisibleIndex = 7;
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
			this->tlcPath->VisibleIndex = 4;
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
			this->tlcAddress->VisibleIndex = 1;
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
			this->tlcBaseType->VisibleIndex = 2;
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
			this->tlcAreaType->VisibleIndex = 3;
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
			// 
			// xtlbAreas
			// 
			this->xtlbAreas->Enabled = false;
			this->xtlbAreas->TreeListControl = this->tlAreas;
			// 
			// xtlbHistory
			// 
			this->xtlbHistory->Enabled = false;
			// 
			// xtlbMessages
			// 
			this->xtlbMessages->Enabled = false;
			this->xtlbMessages->TreeListControl = this->tlMessages;
			// 
			// barManager
			// 
			this->barManager->AllowShowToolbarsPopup = false;
			this->barManager->Bars->AddRange(gcnew cli::array< DevExpress::XtraBars::Bar^  >(9) {this->barMenu, this->barMessage, this->barStatus, 
				this->barService, this->barFile, this->barEdit, this->barHelp, this->barArea, this->barURL});
			this->barManager->Controller = this->barAndDockingController;
			this->barManager->DockControls->Add(this->barDockControl1);
			this->barManager->DockControls->Add(this->barDockControl2);
			this->barManager->DockControls->Add(this->barDockControl3);
			this->barManager->DockControls->Add(this->barDockControl4);
			this->barManager->DockManager = this->dockManager;
			this->barManager->Form = this;
			this->barManager->Items->AddRange(gcnew cli::array< DevExpress::XtraBars::BarItem^  >(73) {this->mFile, this->mEdit, this->mMessage, 
				this->mService, this->mHelp, this->bSaveMessage, this->bSaveAsTemplate, this->bPrint, this->bExit, this->bCopy, this->bSelectAll, 
				this->bFind, this->mCreate, this->bReply, this->bForward, this->bEdit, this->bDelete, this->bRestore, this->bPrevious, this->bNext, 
				this->bSettings, this->mSkin, this->mLanguage, this->mMessagesView, this->bTosser, this->bClearHistory, this->bCustomize, this->bHelp, this->bAbout, 
				this->bCheckForUpdates, this->bNew, this->lTemplate, this->lSkin, this->lLanguage, this->bList, this->bTree, this->sArea, this->bCreate, 
				this->mView, this->mDisplay, this->bHideUnmarked, this->bMark, this->bDecryptROT13, this->bMarkAll, this->mFilter, this->bMarkAsRead,this->bMarkAllAsRead, 
				this->bMarkAsUnread, this->bUnmarkAll, this->bInvertMark, this->bShowAll, this->sN, this->sCount, this->sNotRead, this->mToolbars, 
				this->lToolbars, this->bNewGroup, this->bDeleteGroup, this->bPreviousArea, this->bNextArea, this->bHistoryBack, this->bHistoryForward, 
				this->bFilterNone, this->lFilter, this->mArea, this->bSubscribe, this->bUnsubscribe, this->bUseStyles, this->bAddressBook, this->bNextUnread, 
				this->mShowKludgesMode, this->lShowKludgesMode, this->beURL});
			this->barManager->MainMenu = this->barMenu;
			this->barManager->MaxItemId = 88;
			this->barManager->RepositoryItems->AddRange(gcnew cli::array< DevExpress::XtraEditors::Repository::RepositoryItem^  >(1) {this->rcbeURL});
			this->barManager->StatusBar = this->barStatus;
			// 
			// barMenu
			// 
			this->barMenu->BarName = L"barMenu";
			this->barMenu->DockCol = 0;
			this->barMenu->DockRow = 0;
			this->barMenu->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barMenu->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(7) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mFile)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mEdit)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->mView)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->mArea)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mMessage)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->mService)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mHelp))});
			this->barMenu->OptionsBar->AllowQuickCustomization = false;
			this->barMenu->OptionsBar->DisableClose = true;
			this->barMenu->OptionsBar->DisableCustomization = true;
			this->barMenu->OptionsBar->MultiLine = true;
			this->barMenu->Text = L"Menu";
			// 
			// mFile
			// 
			this->mFile->Caption = L"Файл";
			this->mFile->Id = 0;
			this->mFile->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(4) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSaveMessage)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSaveAsTemplate)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bPrint, 
				true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bExit, true))});
			this->mFile->Name = L"mFile";
			// 
			// bSaveMessage
			// 
			this->bSaveMessage->Caption = L"Сохранить сообщение";
			this->bSaveMessage->Id = 5;
			this->bSaveMessage->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::F7));
			this->bSaveMessage->Name = L"bSaveMessage";
			this->bSaveMessage->ShowCaptionOnBar = false;
			this->bSaveMessage->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bSaveMessage_ItemClick);
			// 
			// bSaveAsTemplate
			// 
			this->bSaveAsTemplate->Caption = L"Сохранить как шаблон";
			this->bSaveAsTemplate->Id = 6;
			this->bSaveAsTemplate->Name = L"bSaveAsTemplate";
			this->bSaveAsTemplate->ShowCaptionOnBar = false;
			this->bSaveAsTemplate->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bSaveAsTemplate_ItemClick);
			// 
			// bPrint
			// 
			this->bPrint->Caption = L"Печать...";
			this->bPrint->Id = 9;
			this->bPrint->Name = L"bPrint";
			this->bPrint->ShowCaptionOnBar = false;
			this->bPrint->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bPrint_ItemClick);
			// 
			// bExit
			// 
			this->bExit->Caption = L"Выход";
			this->bExit->Id = 10;
			this->bExit->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::X)));
			this->bExit->Name = L"bExit";
			this->bExit->ShowCaptionOnBar = false;
			this->bExit->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bExit_ItemClick);
			// 
			// mEdit
			// 
			this->mEdit->Caption = L"Правка";
			this->mEdit->Id = 1;
			this->mEdit->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(3) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bCopy)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSelectAll)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bFind, 
				true))});
			this->mEdit->Name = L"mEdit";
			// 
			// bCopy
			// 
			this->bCopy->Caption = L"Копировать";
			this->bCopy->Id = 11;
			this->bCopy->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::C)));
			this->bCopy->Name = L"bCopy";
			this->bCopy->ShowCaptionOnBar = false;
			this->bCopy->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bCopy_ItemClick);
			// 
			// bSelectAll
			// 
			this->bSelectAll->Caption = L"Выделить всё";
			this->bSelectAll->Id = 12;
			this->bSelectAll->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::A)));
			this->bSelectAll->Name = L"bSelectAll";
			this->bSelectAll->ShowCaptionOnBar = false;
			this->bSelectAll->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bSelectAll_ItemClick);
			// 
			// bFind
			// 
			this->bFind->Caption = L"Найти...";
			this->bFind->Id = 13;
			this->bFind->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F)));
			this->bFind->Name = L"bFind";
			this->bFind->ShowCaptionOnBar = false;
			this->bFind->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bFind_ItemClick);
			// 
			// mView
			// 
			this->mView->Caption = L"Вид";
			this->mView->Id = 47;
			this->mView->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(8) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mSkin)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mLanguage)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->mMessagesView)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mDisplay)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->mShowKludgesMode)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bDecryptROT13)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bUseStyles)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mToolbars))
			});
			this->mView->Name = L"mView";
			// 
			// mSkin
			// 
			this->mSkin->Caption = L"Оформление";
			this->mSkin->Id = 23;
			this->mSkin->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(1) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->lSkin))});
			this->mSkin->Name = L"mSkin";
			// 
			// lSkin
			// 
			this->lSkin->Id = 32;
			this->lSkin->Name = L"lSkin";
			this->lSkin->ShowChecks = true;
			this->lSkin->ListItemClick += gcnew DevExpress::XtraBars::ListItemClickEventHandler(this, &FormMain::lSkin_ListItemClick);
			// 
			// mLanguage
			// 
			this->mLanguage->Caption = L"Язык интерфейса";
			this->mLanguage->Id = 24;
			this->mLanguage->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(1) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->lLanguage))});
			this->mLanguage->Name = L"mLanguage";
			// 
			// lLanguage
			// 
			this->lLanguage->Id = 33;
			this->lLanguage->Name = L"lLanguage";
			this->lLanguage->ShowChecks = true;
			this->lLanguage->ListItemClick += gcnew DevExpress::XtraBars::ListItemClickEventHandler(this, &FormMain::lLanguage_ListItemClick);
			// 
			// mMessagesView
			// 
			this->mMessagesView->Caption = L"Вид панели сообщений";
			this->mMessagesView->Id = 25;
			this->mMessagesView->ImageIndex = 9;
			this->mMessagesView->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(2) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bList)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bTree))});
			this->mMessagesView->Name = L"mMessagesView";
			// 
			// bList
			// 
			this->bList->ButtonStyle = DevExpress::XtraBars::BarButtonStyle::Check;
			this->bList->Caption = L"Список";
			this->bList->Id = 34;
			this->bList->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::F9));
			this->bList->Name = L"bList";
			this->bList->ShowCaptionOnBar = false;
			this->bList->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bList_ItemClick);
			// 
			// bTree
			// 
			this->bTree->ButtonStyle = DevExpress::XtraBars::BarButtonStyle::Check;
			this->bTree->Caption = L"Древо";
			this->bTree->Id = 35;
			this->bTree->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::F8));
			this->bTree->Name = L"bTree";
			this->bTree->ShowCaptionOnBar = false;
			this->bTree->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bTree_ItemClick);
			// 
			// mDisplay
			// 
			this->mDisplay->Caption = L"Показывать";
			this->mDisplay->Id = 48;
			this->mDisplay->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(2) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bHideUnmarked)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bShowAll))});
			this->mDisplay->Name = L"mDisplay";
			// 
			// bHideUnmarked
			// 
			this->bHideUnmarked->ButtonStyle = DevExpress::XtraBars::BarButtonStyle::Check;
			this->bHideUnmarked->Caption = L"Скрывать неотмеченные";
			this->bHideUnmarked->Id = 50;
			this->bHideUnmarked->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::J)));
			this->bHideUnmarked->Name = L"bHideUnmarked";
			this->bHideUnmarked->ShowCaptionOnBar = false;
			this->bHideUnmarked->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bHideUnmarked_ItemClick);
			// 
			// bShowAll
			// 
			this->bShowAll->ButtonStyle = DevExpress::XtraBars::BarButtonStyle::Check;
			this->bShowAll->Caption = L"Показывать все";
			this->bShowAll->Down = true;
			this->bShowAll->Id = 61;
			this->bShowAll->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Alt | System::Windows::Forms::Keys::K)));
			this->bShowAll->Name = L"bShowAll";
			this->bShowAll->ShowCaptionOnBar = false;
			this->bShowAll->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bShowAll_ItemClick);
			// 
			// mShowKludgesMode
			// 
			this->mShowKludgesMode->Caption = L"Режим показа кладжей";
			this->mShowKludgesMode->Id = 85;
			this->mShowKludgesMode->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::F3));
			this->mShowKludgesMode->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(1) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->lShowKludgesMode))});
			this->mShowKludgesMode->Name = L"mShowKludgesMode";
			this->mShowKludgesMode->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::mShowKludgesMode_ItemClick);
			// 
			// lShowKludgesMode
			// 
			this->lShowKludgesMode->Id = 86;
			this->lShowKludgesMode->ItemIndex = 0;
			this->lShowKludgesMode->Name = L"lShowKludgesMode";
			this->lShowKludgesMode->ShowChecks = true;
			this->lShowKludgesMode->Strings->AddRange(gcnew cli::array< System::Object^  >(3) {L"Скрыть", L"Показать известные", L"Показать все"});
			this->lShowKludgesMode->ListItemClick += gcnew DevExpress::XtraBars::ListItemClickEventHandler(this, &FormMain::lShowKludgesMode_ListItemClick);
			// 
			// bDecryptROT13
			// 
			this->bDecryptROT13->ButtonStyle = DevExpress::XtraBars::BarButtonStyle::Check;
			this->bDecryptROT13->Caption = L"Расшифровать ROT13";
			this->bDecryptROT13->Id = 544;
			this->bDecryptROT13->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F3)));
			this->bDecryptROT13->Name = L"bDecryptROT13";
			this->bDecryptROT13->ShowCaptionOnBar = false;
			this->bDecryptROT13->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bDecryptROT13_ItemClick);
			// 
			// bUseStyles
			// 
			this->bUseStyles->ButtonStyle = DevExpress::XtraBars::BarButtonStyle::Check;
			this->bUseStyles->Caption = L"Использовать стилевыделение";
			this->bUseStyles->Id = 82;
			this->bUseStyles->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Shift | System::Windows::Forms::Keys::F3)));
			this->bUseStyles->Name = L"bUseStyles";
			this->bUseStyles->ShowCaptionOnBar = false;
			this->bUseStyles->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bDecryptROT13_ItemClick);
			// 
			// mToolbars
			// 
			this->mToolbars->Caption = L"Панели";
			this->mToolbars->Id = 70;
			this->mToolbars->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(2) 
			{(gcnew DevExpress::XtraBars::LinkPersistInfo(this->lToolbars)),
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bCustomize, true))});
			this->mToolbars->Name = L"mToolbars";
			// 
			// lToolbars
			// 
			this->lToolbars->Caption = L"lToolbars";
			this->lToolbars->Id = 76;
			this->lToolbars->Name = L"lToolbars";
			this->lToolbars->ShowCustomizationItem = false;
			this->lToolbars->ShowDockPanels = true;
			// 
			// mArea
			// 
			this->mArea->Caption = L"Область";
			this->mArea->Id = 77;
			this->mArea->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(5) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bNewGroup)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bPreviousArea, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bNextArea)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSubscribe, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bUnsubscribe))});
			this->mArea->Name = L"mArea";
			// 
			// bNewGroup
			// 
			this->bNewGroup->Caption = L"Новая группа";
			this->bNewGroup->Id = 555;
			this->bNewGroup->Name = L"bNewGroup";
			this->bNewGroup->ShowCaptionOnBar = false;
			this->bNewGroup->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bNewGroup_ItemClick);
			// 
			// bPreviousArea
			// 
			this->bPreviousArea->Caption = L"Предыдущая область";
			this->bPreviousArea->Id = 667;
			this->bPreviousArea->ImageIndex = 0;
			this->bPreviousArea->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::P)));
			this->bPreviousArea->Name = L"bPreviousArea";
			this->bPreviousArea->ShowCaptionOnBar = false;
			this->bPreviousArea->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bPreviousArea_ItemClick);
			// 
			// bNextArea
			// 
			this->bNextArea->Caption = L"Следующая область";
			this->bNextArea->Id = 668;
			this->bNextArea->ImageIndex = 0;
			this->bNextArea->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N)));
			this->bNextArea->Name = L"bNextArea";
			this->bNextArea->ShowCaptionOnBar = false;
			this->bNextArea->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bNextArea_ItemClick);
			// 
			// bSubscribe
			// 
			this->bSubscribe->Caption = L"Подписаться";
			this->bSubscribe->Id = 80;
			this->bSubscribe->Name = L"bSubscribe";
			this->bSubscribe->ShowCaptionOnBar = false;
			this->bSubscribe->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bSubscribe_ItemClick);
			// 
			// bUnsubscribe
			// 
			this->bUnsubscribe->Caption = L"Отписаться";
			this->bUnsubscribe->Id = 81;
			this->bUnsubscribe->Name = L"bUnsubscribe";
			this->bUnsubscribe->ShowCaptionOnBar = false;
			this->bUnsubscribe->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bUnsubscribe_ItemClick);
			// 
			// mMessage
			// 
			this->mMessage->Caption = L"Сообщение";
			this->mMessage->Id = 2;
			this->mMessage->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(17) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mCreate)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bReply)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bForward)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bEdit)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bDelete)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bRestore)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bMark, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->mFilter)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bMarkAll)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bUnmarkAll)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bInvertMark)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bMarkAsRead, 
				true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bMarkAsUnread)),
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bMarkAllAsRead)),
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bPrevious, 
				true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bNext)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bNextUnread))});
			this->mMessage->Name = L"mMessage";
			// 
			// mCreate
			// 
			this->mCreate->Caption = L"Создать";
			this->mCreate->Id = 14;
			this->mCreate->ImageIndex = 11;
			this->mCreate->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(2) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bNew)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->lTemplate, true))});
			this->mCreate->Name = L"mCreate";
			// 
			// bNew
			// 
			this->bNew->Caption = L"Новое";
			this->bNew->Id = 30;
			this->bNew->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::Insert));
			this->bNew->Name = L"bNew";
			this->bNew->ShowCaptionOnBar = false;
			this->bNew->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bNew_ItemClick);
			// 
			// lTemplate
			// 
			this->lTemplate->Id = 31;
			this->lTemplate->Name = L"lTemplate";
			this->lTemplate->ListItemClick += gcnew DevExpress::XtraBars::ListItemClickEventHandler(this, &FormMain::lTemplate_ListItemClick);
			// 
			// bReply
			// 
			this->bReply->Caption = L"Ответить";
			this->bReply->Id = 15;
			this->bReply->ImageIndex = 12;
			this->bReply->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::F4));
			this->bReply->Name = L"bReply";
			this->bReply->ShowCaptionOnBar = false;
			this->bReply->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bReply_ItemClick);
			// 
			// bForward
			// 
			this->bForward->Caption = L"Переслать";
			this->bForward->Id = 16;
			this->bForward->ImageIndex = 13;
			this->bForward->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Shift | System::Windows::Forms::Keys::F8)));
			this->bForward->Name = L"bForward";
			this->bForward->ShowCaptionOnBar = false;
			this->bForward->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bForward_ItemClick);
			// 
			// bEdit
			// 
			this->bEdit->Caption = L"Редактировать";
			this->bEdit->Id = 17;
			this->bEdit->ImageIndex = 14;
			this->bEdit->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::F2));
			this->bEdit->Name = L"bEdit";
			this->bEdit->ShowCaptionOnBar = false;
			this->bEdit->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bEdit_ItemClick);
			// 
			// bDelete
			// 
			this->bDelete->Caption = L"Удалить";
			this->bDelete->Id = 18;
			this->bDelete->ImageIndex = 15;
			this->bDelete->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::Delete));
			this->bDelete->Name = L"bDelete";
			this->bDelete->ShowCaptionOnBar = false;
			this->bDelete->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bDelete_ItemClick);
			// 
			// bRestore
			// 
			this->bRestore->Caption = L"Восстановить";
			this->bRestore->Enabled = false;
			this->bRestore->Id = 118;
			this->bRestore->Name = L"bRestore";
			this->bRestore->ShowCaptionOnBar = false;
			this->bRestore->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bRestore_ItemClick);
			// 
			// bMark
			// 
			this->bMark->Caption = L"Отметить";
			this->bMark->Id = 51;
			this->bMark->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::Add));
			this->bMark->Name = L"bMark";
			this->bMark->ShowCaptionOnBar = false;
			this->bMark->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bMark_ItemClick);
			// 
			// mFilter
			// 
			this->mFilter->Caption = L"Фильтр";
			this->mFilter->Id = 56;
			this->mFilter->ImageIndex = 16;
			this->mFilter->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(2) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bFilterNone)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->lFilter, true))});
			this->mFilter->Name = L"mFilter";
			// 
			// bFilterNone
			// 
			this->bFilterNone->ButtonStyle = DevExpress::XtraBars::BarButtonStyle::Check;
			this->bFilterNone->Caption = L"Нет";
			this->bFilterNone->Down = true;
			this->bFilterNone->Id = 611;
			this->bFilterNone->Name = L"bFilterNone";
			this->bFilterNone->ShowCaptionOnBar = false;
			this->bFilterNone->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bFilterNone_ItemClick);
			// 
			// lFilter
			// 
			this->lFilter->Id = 311;
			this->lFilter->Name = L"lFilter";
			this->lFilter->ShowChecks = true;
			this->lFilter->ListItemClick += gcnew DevExpress::XtraBars::ListItemClickEventHandler(this, &FormMain::lFilter_ListItemClick);
			// 
			// bMarkAll
			// 
			this->bMarkAll->Caption = L"Отметить все";
			this->bMarkAll->Id = 55;
			this->bMarkAll->ImageIndex = 17;
			this->bMarkAll->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Add)));
			this->bMarkAll->Name = L"bMarkAll";
			this->bMarkAll->ShowCaptionOnBar = false;
			this->bMarkAll->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bMarkAll_ItemClick);
			// 
			// bUnmarkAll
			// 
			this->bUnmarkAll->Caption = L"Снять отметку со всех";
			this->bUnmarkAll->Id = 59;
			this->bUnmarkAll->ImageIndex = 18;
			this->bUnmarkAll->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::Subtract)));
			this->bUnmarkAll->Name = L"bUnmarkAll";
			this->bUnmarkAll->ShowCaptionOnBar = false;
			this->bUnmarkAll->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bUnmarkAll_ItemClick);
			// 
			// bInvertMark
			// 
			this->bInvertMark->Caption = L"Обратить отметку";
			this->bInvertMark->Id = 60;
			this->bInvertMark->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::Multiply));
			this->bInvertMark->Name = L"bInvertMark";
			this->bInvertMark->ShowCaptionOnBar = false;
			this->bInvertMark->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bInvertMark_ItemClick);
			// 
			// bMarkAsRead
			// 
			this->bMarkAsRead->Caption = L"Пометить как прочитанные";
			this->bMarkAsRead->Id = 57;
			this->bMarkAsRead->ImageIndex = 19;
			this->bMarkAsRead->Name = L"bMarkAsRead";
			this->bMarkAsRead->ShowCaptionOnBar = false;
			this->bMarkAsRead->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bMarkAsRead_ItemClick);
			// 
			// bMarkAllAsRead
			// 
			this->bMarkAllAsRead->Caption = L"Пометить все как прочитанные";
			this->bMarkAllAsRead->Id = 157;
			this->bMarkAllAsRead->ImageIndex = 19;
			this->bMarkAllAsRead->Name = L"bMarkAllAsRead";
			this->bMarkAllAsRead->ShowCaptionOnBar = false;
			this->bMarkAllAsRead->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::R));
			this->bMarkAllAsRead->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bMarkAllAsRead_ItemClick);
			// 
			// bMarkAsUnread
			// 
			this->bMarkAsUnread->Caption = L"Пометить как непрочитанные";
			this->bMarkAsUnread->Id = 58;
			this->bMarkAsUnread->ImageIndex = 20;
			this->bMarkAsUnread->Name = L"bMarkAsUnread";
			this->bMarkAsUnread->ShowCaptionOnBar = false;
			this->bMarkAsUnread->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bMarkAsUnread_ItemClick);
			// 
			// bPrevious
			// 
			this->bPrevious->Caption = L"Предыдущее";
			this->bPrevious->Id = 19;
			this->bPrevious->ImageIndex = 21;
			this->bPrevious->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::Left));
			this->bPrevious->Name = L"bPrevious";
			this->bPrevious->ShowCaptionOnBar = false;
			this->bPrevious->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bPrevious_ItemClick);
			// 
			// bNext
			// 
			this->bNext->Caption = L"Следующее";
			this->bNext->Id = 20;
			this->bNext->ImageIndex = 22;
			this->bNext->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::Right));
			this->bNext->Name = L"bNext";
			this->bNext->ShowCaptionOnBar = false;
			this->bNext->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bNext_ItemClick);
			// 
			// bNextUnread
			// 
			this->bNextUnread->Caption = L"Следующее непрочтённое";
			this->bNextUnread->Id = 84;
			this->bNextUnread->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::Space));
			this->bNextUnread->Name = L"bNextUnread";
			this->bNextUnread->ShowCaptionOnBar = false;
			this->bNextUnread->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bNextUnread_ItemClick);
			// 
			// mService
			// 
			this->mService->Caption = L"Сервис";
			this->mService->Id = 3;
			this->mService->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(4) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSettings)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAddressBook)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bClearHistory)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bTosser, true))});
			this->mService->Name = L"mService";
			// 
			// bSettings
			// 
			this->bSettings->Caption = L"Настройки";
			this->bSettings->Id = 22;
			this->bSettings->Name = L"bSettings";
			this->bSettings->ShowCaptionOnBar = false;
			this->bSettings->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bSettings_ItemClick);
			// 
			// bAddressBook
			// 
			this->bAddressBook->Caption = L"Адресная книга";
			this->bAddressBook->Id = 83;
			this->bAddressBook->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::F6)));
			this->bAddressBook->Name = L"bAddressBook";
			this->bAddressBook->ShowCaptionOnBar = false;
			this->bAddressBook->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bAddressBook_ItemClick);
			// 
			// bClearHistory
			// 
			this->bClearHistory->Caption = L"Очистить журнал навигации";
			this->bClearHistory->Id = 1126;
			this->bClearHistory->Name = L"bClearHistory";
			this->bClearHistory->ShowCaptionOnBar = false;
			this->bClearHistory->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bClearHistory_ItemClick);
			// 
			// bCustomize
			// 
			this->bCustomize->Caption = L"Настроить";
			this->bCustomize->Id = 11126;
			this->bCustomize->Name = L"bCustomize";
			this->bCustomize->ShowCaptionOnBar = false;
			this->bCustomize->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bCustomize_ItemClick);
			// 
			// bTosser
			// 
			this->bTosser->Caption = L"Тоссер";
			this->bTosser->Id = 26;
			this->bTosser->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::T)));
			this->bTosser->Name = L"bTosser";
			this->bTosser->ShowCaptionOnBar = false;
			this->bTosser->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bTosser_ItemClick);
			// 
			// mHelp
			// 
			this->mHelp->Caption = L"Справка";
			this->mHelp->Id = 4;
			this->mHelp->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(3) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bHelp)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAbout)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bCheckForUpdates))});
			this->mHelp->Name = L"mHelp";
			// 
			// bHelp
			// 
			this->bHelp->Caption = L"Вызов справки";
			this->bHelp->Id = 28;
			this->bHelp->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut(System::Windows::Forms::Keys::F1));
			this->bHelp->Name = L"bHelp";
			this->bHelp->ShowCaptionOnBar = false;
			this->bHelp->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bHelp_ItemClick);
			// 
			// bAbout
			// 
			this->bAbout->Caption = L"О программе";
			this->bAbout->Id = 29;
			this->bAbout->Name = L"bAbout";
			this->bAbout->ShowCaptionOnBar = false;
			this->bAbout->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bAbout_ItemClick);
			// 
			// bCheckForUpdates
			// 
			this->bCheckForUpdates->Caption = L"Проверить обновления";
			this->bCheckForUpdates->Id = 291;
			this->bCheckForUpdates->Name = L"bCheckForUpdates";
			this->bCheckForUpdates->ShowCaptionOnBar = false;
			this->bCheckForUpdates->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bCheckForUpdates_ItemClick);
			// 
			// barMessage
			// 
			this->barMessage->BarName = L"barMessage";
			this->barMessage->DockCol = 0;
			this->barMessage->DockRow = 1;
			this->barMessage->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barMessage->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(8) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bCreate)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bReply)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bForward)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bEdit)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bDelete)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bRestore)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bPrevious, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bNext))});
		//	this->barMessage->OptionsBar->AllowQuickCustomization = false;
		//	this->barMessage->OptionsBar->DisableCustomization = true;
			this->barMessage->Text = L"Message";
			// 
			// bCreate
			// 
			this->bCreate->ButtonStyle = DevExpress::XtraBars::BarButtonStyle::DropDown;
			this->bCreate->Caption = L"Создать";
			this->bCreate->DropDownControl = this->pmCreate;
			this->bCreate->Id = 37;
			this->bCreate->ImageIndex = 11;
			this->bCreate->LargeImageIndex = 11;
			this->bCreate->Name = L"bCreate";
			this->bCreate->ShowCaptionOnBar = false;
			this->bCreate->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bNew_ItemClick);
			// 
			// pmCreate
			// 
			this->pmCreate->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(1) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->lTemplate))});
			this->pmCreate->Manager = this->barManager;
			this->pmCreate->Name = L"pmCreate";
			// 
			// barStatus
			// 
			this->barStatus->BarName = L"barStatus";
			this->barStatus->CanDockStyle = DevExpress::XtraBars::BarCanDockStyle::Bottom;
			this->barStatus->DockCol = 0;
			this->barStatus->DockRow = 0;
			this->barStatus->DockStyle = DevExpress::XtraBars::BarDockStyle::Bottom;
			this->barStatus->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(4) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->sArea)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->sN)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->sCount)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->sNotRead))});
			this->barStatus->OptionsBar->AllowQuickCustomization = false;
			this->barStatus->OptionsBar->DisableClose = true;
			this->barStatus->OptionsBar->DisableCustomization = true;
			this->barStatus->OptionsBar->DrawDragBorder = false;
			this->barStatus->OptionsBar->DrawSizeGrip = true;
			this->barStatus->OptionsBar->UseWholeRow = true;
			this->barStatus->Text = L"Status";
			// 
			// sArea
			// 
			this->sArea->AutoSize = DevExpress::XtraBars::BarStaticItemSize::Spring;
			this->sArea->Id = 36;
			this->sArea->Name = L"sArea";
			this->sArea->RightIndent = 8;
			this->sArea->TextAlignment = System::Drawing::StringAlignment::Near;
			this->sArea->Width = 32;
			// 
			// sN
			// 
			this->sN->AutoSize = DevExpress::XtraBars::BarStaticItemSize::Spring;
			this->sN->Id = 67;
			this->sN->Name = L"sN";
			this->sN->RightIndent = 8;
			this->sN->TextAlignment = System::Drawing::StringAlignment::Near;
			this->sN->Width = 32;
			// 
			// sCount
			// 
			this->sCount->AutoSize = DevExpress::XtraBars::BarStaticItemSize::Spring;
			this->sCount->Id = 68;
			this->sCount->Name = L"sCount";
			this->sCount->RightIndent = 8;
			this->sCount->TextAlignment = System::Drawing::StringAlignment::Near;
			this->sCount->Width = 32;
			// 
			// sNotRead
			// 
			this->sNotRead->AutoSize = DevExpress::XtraBars::BarStaticItemSize::Spring;
			this->sNotRead->Id = 69;
			this->sNotRead->Name = L"sNotRead";
			this->sNotRead->TextAlignment = System::Drawing::StringAlignment::Near;
			this->sNotRead->Width = 32;
			// 
			// barService
			// 
			this->barService->BarName = L"barService";
			this->barService->DockCol = 3;
			this->barService->DockRow = 1;
			this->barService->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barService->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(4) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSettings)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAddressBook)),
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bClearHistory)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bTosser, true))});
			this->barService->Offset = 176;
	//		this->barService->OptionsBar->AllowQuickCustomization = false;
	//		this->barService->OptionsBar->DisableCustomization = true;
			this->barService->Text = L"Service";
			// 
			// barFile
			// 
			this->barFile->BarName = L"barFile";
			this->barFile->DockCol = 1;
			this->barFile->DockRow = 1;
			this->barFile->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barFile->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(3)
			{(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSaveMessage)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSaveAsTemplate)),
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bPrint,true))});
		//	this->barFile->OptionsBar->AllowQuickCustomization = false;
		//	this->barFile->OptionsBar->DisableCustomization = true;
			this->barFile->Text = L"File";
			// 
			// barEdit
			// 
			this->barEdit->BarName = L"barEdit";
			this->barEdit->DockCol = 2;
			this->barEdit->DockRow = 1;
			this->barEdit->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barEdit->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(2) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bCopy)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bFind))});
		//	this->barEdit->OptionsBar->AllowQuickCustomization = false;
		//	this->barEdit->OptionsBar->DisableCustomization = true;
			this->barEdit->Text = L"Edit";
			// 
			// barHelp
			// 
			this->barHelp->BarName = L"barHelp";
			this->barHelp->DockCol = 1;
			this->barHelp->DockRow = 0;
			this->barHelp->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barHelp->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(1) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bHelp))});
			this->barHelp->Offset = 408;
		//	this->barHelp->OptionsBar->AllowQuickCustomization = false;
		//	this->barHelp->OptionsBar->DisableCustomization = true;
			this->barHelp->Text = L"Help";
			// 
			// barArea
			// 
			this->barArea->BarName = L"barArea";
			this->barArea->DockCol = 4;
			this->barArea->DockRow = 1;
			this->barArea->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barArea->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(5) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bNewGroup)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bPreviousArea, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bNextArea)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSubscribe, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bUnsubscribe))});
			this->barArea->Offset = 656;
		//	this->barArea->OptionsBar->AllowQuickCustomization = false;
		//	this->barArea->OptionsBar->DisableCustomization = true;
			this->barArea->Text = L"Area";
			// 
			// barURL
			// 
			this->barURL->BarName = L"barURL";
			this->barURL->DockCol = 0;
			this->barURL->DockRow = 2;
			this->barURL->DockStyle = DevExpress::XtraBars::BarDockStyle::Top;
			this->barURL->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(3) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bHistoryBack)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bHistoryForward)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->beURL))});
			this->barURL->Offset = 139;
		//	this->barURL->OptionsBar->AllowQuickCustomization = false;
		//	this->barURL->OptionsBar->DisableCustomization = true;
			this->barURL->Text = L"URL";
			// 
			// bHistoryBack
			// 
			this->bHistoryBack->Caption = L"Назад";
			this->bHistoryBack->Id = 1668;
			this->bHistoryBack->ImageIndex = 0;
			this->bHistoryBack->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N)));
			this->bHistoryBack->Name = L"bHistoryBack";
			this->bHistoryBack->ShowCaptionOnBar = false;
			this->bHistoryBack->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bHistoryBack_ItemClick);
			// 
			// bHistoryForward
			// 
			this->bHistoryForward->Caption = L"Вперед";
			this->bHistoryForward->Id = 1669;
			this->bHistoryForward->ImageIndex = 0;
			this->bHistoryForward->ItemShortcut = (gcnew DevExpress::XtraBars::BarShortcut((System::Windows::Forms::Keys::Control | System::Windows::Forms::Keys::N)));
			this->bHistoryForward->Name = L"bHistoryForward";
			this->bHistoryForward->ShowCaptionOnBar = false;
			this->bHistoryForward->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bHistoryForward_ItemClick);
			// 
			// beURL
			// 
			this->beURL->AutoFillWidth = true;
			this->beURL->Edit = this->rcbeURL;
			this->beURL->Id = 87;
			this->beURL->Name = L"beURL";
			// 
			// rcbeURL
			// 
			this->rcbeURL->AllowFocused = false;
			this->rcbeURL->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rcbeURL->CycleOnDblClick = false;
			this->rcbeURL->Name = L"rcbeURL";
			this->rcbeURL->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &FormMain::rcbeURL_KeyDown);
			this->rcbeURL->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMain::rcbeURL_SelectedItemChanged);
			// 
			// barAndDockingController
			// 
			this->barAndDockingController->PaintStyleName = L"Skin";
			this->barAndDockingController->PropertiesBar->AllowLinkLighting = false;
			// 
			// dockManager
			// 
			this->dockManager->Controller = this->barAndDockingController;
			this->dockManager->Form = this;
			this->dockManager->RootPanels->AddRange(gcnew cli::array< DevExpress::XtraBars::Docking::DockPanel^  >(2) {this->panelContainer, 
				this->dpMessages});
			this->dockManager->TopZIndexControls->AddRange(gcnew cli::array< System::String^  >(2) {L"DevExpress.XtraBars.BarDockControl", 
				L"System.Windows.Forms.StatusBar"});
			// 
			// panelContainer
			// 
			this->panelContainer->ActiveChild = this->dpAreas;
			this->panelContainer->Controls->Add(this->dpAreas);
			this->panelContainer->Controls->Add(this->dpMessages);
			this->panelContainer->Controls->Add(this->dpHistory);
			this->panelContainer->Dock = DevExpress::XtraBars::Docking::DockingStyle::Left;
			this->panelContainer->FloatVertical = true;
			this->panelContainer->ID = System::Guid(L"932df07f-3a20-43d3-ad3e-49426ae0162b");
			this->panelContainer->Location = System::Drawing::Point(0, 74);
			this->panelContainer->Name = L"panelContainer";
			this->panelContainer->Size = System::Drawing::Size(254, 536);
			this->panelContainer->Tabbed = true;
			this->panelContainer->Text = L"panelContainer";
			// 
			// dpAreas
			// 
			this->dpAreas->Controls->Add(this->dpAreas_Container);
			this->dpAreas->Dock = DevExpress::XtraBars::Docking::DockingStyle::Fill;
			this->dpAreas->FloatVertical = true;
			this->dpAreas->ID = System::Guid(L"6d66cd41-8763-4a4f-a960-0a1acc61f0e3");
			this->dpAreas->Location = System::Drawing::Point(3, 25);
			this->dpAreas->Name = L"dpAreas";
			this->dpAreas->Size = System::Drawing::Size(248, 486);
			this->dpAreas->Text = L"Области";
			// 
			// dpAreas_Container
			// 
			this->dpAreas_Container->Controls->Add(this->tlAreas);
			this->dpAreas_Container->Location = System::Drawing::Point(0, 0);
			this->dpAreas_Container->Name = L"dpAreas_Container";
			this->dpAreas_Container->Size = System::Drawing::Size(248, 486);
			this->dpAreas_Container->TabIndex = 0;
			// 
			// dpHistory
			// 
			this->dpHistory->Controls->Add(this->dockPanel1_Container);
			this->dpHistory->Dock = DevExpress::XtraBars::Docking::DockingStyle::Fill;
			this->dpHistory->ID = System::Guid(L"1226abb1-9bde-4ce6-b61c-176673f2c4dc");
			this->dpHistory->Location = System::Drawing::Point(3, 25);
			this->dpHistory->Name = L"dpHistory";
			this->dpHistory->Size = System::Drawing::Size(248, 486);
			this->dpHistory->Text = L"Журнал";
			// 
			// dockPanel1_Container
			// 
			this->dockPanel1_Container->Controls->Add(this->tlHistory);
			this->dockPanel1_Container->Location = System::Drawing::Point(0, 0);
			this->dockPanel1_Container->Name = L"dockPanel1_Container";
			this->dockPanel1_Container->Size = System::Drawing::Size(248, 486);
			this->dockPanel1_Container->TabIndex = 0;
			// 
			// tlHistory
			// 
			this->tlHistory->Columns->AddRange(gcnew cli::array< DevExpress::XtraTreeList::Columns::TreeListColumn^  >(2) {this->tlcURL, 
				this->tlcDateTime});
			this->tlHistory->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tlHistory->Location = System::Drawing::Point(0, 0);
			this->tlHistory->Name = L"tlHistory";
			this->tlHistory->OptionsBehavior->Editable = false;
			this->tlHistory->OptionsBehavior->ShowToolTips = false;
			this->tlHistory->OptionsMenu->EnableFooterMenu = false;
			this->tlHistory->OptionsView->AutoWidth = false;
			this->tlHistory->OptionsView->EnableAppearanceEvenRow = true;
			this->tlHistory->OptionsView->EnableAppearanceOddRow = true;
			this->tlHistory->OptionsView->ShowHorzLines = false;
			this->tlHistory->OptionsView->ShowIndicator = false;
			this->tlHistory->OptionsView->ShowRoot = false;
			this->tlHistory->Size = System::Drawing::Size(248, 486);
			this->tlHistory->TabIndex = 0;
			this->tlHistory->FocusedNodeChanged += gcnew DevExpress::XtraTreeList::FocusedNodeChangedEventHandler(this, &FormMain::tlHistory_FocusedNodeChanged);
			// 
			// tlcURL
			// 
			this->tlcURL->Caption = L"Адрес";
			this->tlcURL->FieldName = L"URL";
			this->tlcURL->Name = L"tlcURL";
			this->tlcURL->OptionsColumn->AllowEdit = false;
			this->tlcURL->OptionsColumn->AllowFocus = false;
			this->tlcURL->OptionsColumn->AllowSort = false;
			this->tlcURL->OptionsColumn->ReadOnly = true;
			this->tlcURL->Visible = true;
			this->tlcURL->VisibleIndex = 0;
			this->tlcURL->Width = 149;
			// 
			// tlcDateTime
			// 
			this->tlcDateTime->Caption = L"Дата посещения";
			this->tlcDateTime->FieldName = L"DateTime";
			this->tlcDateTime->Name = L"tlcDateTime";
			this->tlcDateTime->OptionsColumn->AllowEdit = false;
			this->tlcDateTime->OptionsColumn->AllowFocus = false;
			this->tlcDateTime->OptionsColumn->ReadOnly = true;
			this->tlcDateTime->SortOrder = System::Windows::Forms::SortOrder::Descending;
			this->tlcDateTime->Visible = true;
			this->tlcDateTime->VisibleIndex = 1;
			// 
			// dpMessages
			// 
			this->dpMessages->Controls->Add(this->dpMessages_Container);
			this->dpMessages->Dock = DevExpress::XtraBars::Docking::DockingStyle::Top;
			this->dpMessages->ID = System::Guid(L"1520b546-2be8-48b6-838b-72889c5c2f33");
			this->dpMessages->Location = System::Drawing::Point(254, 74);
			this->dpMessages->Name = L"dpMessages";
			this->dpMessages->Size = System::Drawing::Size(675, 188);
			this->dpMessages->Text = L"Сообщения";
			// 
			// dpMessages_Container
			// 
			this->dpMessages_Container->Controls->Add(this->tlMessages);
			this->dpMessages_Container->Location = System::Drawing::Point(3, 25);
			this->dpMessages_Container->Name = L"dpMessages_Container";
			this->dpMessages_Container->Size = System::Drawing::Size(669, 160);
			this->dpMessages_Container->TabIndex = 0;
			// 
			// bDeleteGroup
			// 
			this->bDeleteGroup->Caption = L"Удалить группу";
			this->bDeleteGroup->Id = 556;
			this->bDeleteGroup->Name = L"bDeleteGroup";
			this->bDeleteGroup->ShowCaptionOnBar = false;
			this->bDeleteGroup->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormMain::bDeleteGroup_ItemClick);
			// 
			// pmEdit
			// 
			this->pmEdit->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(9) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bCopy)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSelectAll)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bFind, 
				true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->mCreate, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bReply)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bForward)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bEdit)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bDelete)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bRestore))});
			this->pmEdit->Manager = this->barManager;
			this->pmEdit->Name = L"pmEdit";
			// 
			// pmNotify
			// 
			this->pmNotify->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(5) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSettings)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAddressBook)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bClearHistory)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bTosser)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bExit, true))});
			this->pmNotify->Manager = this->barManager;
			this->pmNotify->Name = L"pmNotify";
			// 
			// pmAreas
			// 
			this->pmAreas->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(6) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bNewGroup)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bDeleteGroup)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bPreviousArea, 
				true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bNextArea)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bSubscribe, 
				true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bUnsubscribe))});
			this->pmAreas->Manager = this->barManager;
			this->pmAreas->Name = L"pmAreas";
			// 
			// notifyicon
			// 
			this->notifyicon->Visible = true;
			this->notifyicon->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &FormMain::notifyicon_MouseClick);
			// 
			// pmMessages
			// 
			this->pmMessages->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(17) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->mCreate)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bReply)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bForward)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bEdit)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bDelete)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bRestore)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bMark, true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->mFilter)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bMarkAll)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bUnmarkAll)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bInvertMark)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bMarkAsRead, true)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bMarkAsUnread)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bMarkAllAsRead)),
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bPrevious, 
				true)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bNext)), (gcnew DevExpress::XtraBars::LinkPersistInfo(this->bNextUnread))});
			this->pmMessages->Manager = this->barManager;
			this->pmMessages->Name = L"pmMessages";
			// 
			// FormMain
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->BackColor = System::Drawing::SystemColors::Control;
			this->ClientSize = System::Drawing::Size(929, 635);
			this->Controls->Add(this->LayoutControl);
			this->Controls->Add(this->panelContainer);
			this->Controls->Add(this->barDockControl3);
			this->Controls->Add(this->barDockControl4);
			this->Controls->Add(this->barDockControl2);
			this->Controls->Add(this->barDockControl1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"FormMain";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"HellEd";
			this->Closed += gcnew System::EventHandler(this, &FormMain::FormMain_Closed);
			this->Closing += gcnew System::ComponentModel::CancelEventHandler(this, &FormMain::FormMain_Closing);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teReceived->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->LayoutControl))->EndInit();
			this->LayoutControl->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teAttributes->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teWritten->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teSubject->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teFrom->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->teTo->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->peFrom->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lcgMain))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciFrom))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciWritten))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciPhoto))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciSubject))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciTo))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciText))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciReceived))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->lciAttributes))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rte))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rtero))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlMessages))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rche))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlAreas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barManager))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmCreate))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbeURL))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barAndDockingController))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dockManager))->EndInit();
			this->panelContainer->ResumeLayout(false);
			this->dpAreas->ResumeLayout(false);
			this->dpAreas_Container->ResumeLayout(false);
			this->dpHistory->ResumeLayout(false);
			this->dockPanel1_Container->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlHistory))->EndInit();
			this->dpMessages->ResumeLayout(false);
			this->dpMessages_Container->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmEdit))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmNotify))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmAreas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmMessages))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		public: FormMain(string^ url)
		{
			InitializeComponent();

			StartTick=System::Environment::TickCount;
			HellEdDir = Directory::GetCurrentDirectory();
			
			LogHED = gcnew StreamWriter(string::Concat(HellEdDir,L"\\helled.log"),false,System::Text::Encoding::GetEncoding(65001));

			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	Starting HellEd...");
			LogHED->Flush();


			notifyicon->Icon = this->Icon;
			this->Text = string::Concat(L"HellEd ", System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Major,".",
				System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Minor,".",
				System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Build);
			this->rtText->DocumentCompleted += gcnew WebBrowserDocumentCompletedEventHandler(this,&FormMain::rtText_DocumentCompleted);
			this->rtText->Navigating += gcnew WebBrowserNavigatingEventHandler(this,&FormMain::rtText_Navigating);
			
			notifyicon->Text = this->Text;
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	MsgOpenApi()");
			LogHED->Flush();
			_minf m;
			m.req_version = 2;
			m.def_zone = 2;
			if (MsgOpenApi(&m)!= 0)
			{
				LogHED->Write((System::Environment::TickCount-StartTick).ToString());
				LogHED->WriteLine(L"	Error: MsgOpenApi() failed");
				LogHED->Flush();
				Close();
			}

			rtTextFlag=true;

			HistoryFlag=true;
			ShowAreasFlag=true;
		
            FilterMarkEnabled=false;
            FilterFromEnabled=false;
            FilterToEnabled=false;
            FilterSubjectEnabled=false;
            FilterDateTimeEnabled=false;
			FilterFrom=L"";
            FilterTo=L"";
            FilterSubject=L"";
			FilterDateTime1=L"";
			FilterDateTime2=L"";

			htkludges = gcnew Hashtable();
			hteomkludges = gcnew Hashtable();
			ConfigForms = gcnew Config();
			ConfigAreas = gcnew Config();
			ConfigTosser = gcnew Config();
			ConfigSkin = gcnew Config();
			ConfigSmiles = gcnew Config();
			ConfigFilter = gcnew Config();
			ConfigHistory = gcnew Config();
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	gcnew FormSettings()");
			LogHED->Flush();
			frmSettings = gcnew FormSettings(this);
			frmSettings_InitializeComponents();
			LoadConfigHED();
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	gcnew FormSearch()");
			LogHED->Flush();
//			frmSearch = gcnew FormSearch();
//			frmSearch_InitializeComponents();
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	gcnew FormAbout()");
			LogHED->Flush();
			frmAbout = gcnew FormAbout(this, HellEdDir);
			frmAbout_InitializeComponents();
			InputBox = gcnew FormInputBox();
			frmPopup = gcnew FormPopup(this);
			frmPopup->frmSettings=frmSettings;
			frmPopup->meMessage->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &FormMain::frmPopup_meMessage_MouseDown);

			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	gcnew FormSplash()");
			LogHED->Flush();
			frmSplash = gcnew FormSplash();

			LoadConfigFilter((string^)frmSettings->tlConfigHED->FindNodeByKeyID(301)->GetValue(1));
			LoadConfigSkin((string^)frmSettings->tlConfigHED->FindNodeByKeyID(501)->GetValue(1));
			peFrom->Image = Image::FromFile(string::Concat(HellEdDir, L"\\users\\0.0.0.0.jpg"));

			frmSplash->Show();
			frmSplash->Refresh();
			
			InitializehtLanguage();

			ni=-1;
			nmsgid=L"";
			harea=nullptr;
			frmSettings->echotoss=L"";
			LoadConfigTosser();
			ParseURL(url);
			frmSplash->Hide();
			LoadConfigForms();
			LoadConfigTosserFlag=false;
			if (ani!=-1){tlAreas->SetFocusedNode(tlAreas->FindNodeByID(ani));}
			LoadConfigTosserFlag=true;
			previousState = WindowState;

			LoadConfigLanguage((string^)frmSettings->tlConfigHED->FindNodeByKeyID(601)->GetValue(1));
			LoadConfigHistory();

			CheckForUpdatesFlag=true;
			if (*dynamic_cast<bool^>(frmSettings->tlConfigHED->FindNodeByKeyID(1102)->GetValue(1)))
			{
				CheckForUpdatesFlag=false;
				bCheckForUpdates_ItemClick(nullptr,nullptr);
			}
			tlMessages->Select();
			tlMessages->Focus();

			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	HellEd loaded");
			LogHED->Flush();
		}
		protected: virtual void WndProc(System::Windows::Forms::Message% m) override
		{
			if (m.Msg == WM_COPYDATA)
			{
				COPYDATASTRUCT* data = (COPYDATASTRUCT*)(void*)m.LParam;
				ParseURL(Marshal::PtrToStringAnsi((System::IntPtr)data->lpData,(int)data->cbData));
			}
			__super::WndProc(m);
		}

		protected: virtual void OnSizeChanged(EventArgs^ e) override
		{
			__super::OnSizeChanged(e);
			if (previousState != WindowState)
			{
				if (WindowState == System::Windows::Forms::FormWindowState::Minimized)
				{
					if (*dynamic_cast<bool^>(frmSettings->tlConfigHED->FindNodeByKeyID(1101)->GetValue(1)))
					{
						this->Visible=false;
					}
				}
				else {previousState = WindowState;}
			}
		}
		public: void notifyicon_MouseClick(object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			if((int)(e->Button & Windows::Forms::MouseButtons::Left) != 0)
			{
				if (!this->Visible)
				{
					Show();
					Focus();
					if (frmSettings->Visible)
					{
						frmSettings->Show();
						frmSettings->Focus();
					}
					if (frmAbout->Visible)
					{
						frmAbout->Show();
						frmAbout->Focus();
					}
					if (previousState==System::Windows::Forms::FormWindowState::Minimized)
						WindowState=System::Windows::Forms::FormWindowState::Normal;
					else WindowState = previousState;
				}
				else
				{
					if (WindowState==System::Windows::Forms::FormWindowState::Minimized)
						WindowState=System::Windows::Forms::FormWindowState::Normal;
					this->TopMost=true;
					Show();
					Focus();
					this->TopMost=false;
				}
			}
			else if((int)(e->Button & Windows::Forms::MouseButtons::Right) != 0)
			{
				pmNotify->ShowPopup(Control::MousePosition);
			}
		}
		public: void rtText_DocumentCompleted(object^ sender, WebBrowserDocumentCompletedEventArgs^ e)
		{
			if (rtTextFlag)
			{
				rtText->Document->ContextMenuShowing += gcnew HtmlElementEventHandler(this, &FormMain::rtText_MouseUp);
				rtTextFlag=false;
				ShowMessageText();
			}
		}
		public: void rtText_Navigating(object^ sender, WebBrowserNavigatingEventArgs ^ e)
		{
			if ((e->Url->ToString()->StartsWith(L"area:"))||
				(e->Url->ToString()->StartsWith(L"netmail:"))||
				(e->Url->ToString()->StartsWith(L"echomail:"))||
				(e->Url->ToString()->StartsWith(L"areafix:")))
			{
				e->Cancel = true;
				ParseURL(e->Url->ToString());
			}
			else if (!(e->Url->Equals(L"about:blank")))
			{
				e->Cancel=true;
				System::Diagnostics::Process::Start(e->Url->ToString());
			}
		}

		public: void bExit_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			Close();
		}
		
		public: void bPrint_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			string^ res;
			StreamReader^ sr = gcnew StreamReader(string::Concat(HellEdDir,L"\\skins\\",(string^)frmSettings->tlConfigHED->FindNodeByKeyID(501)->GetValue(1),L"\\message.css"),System::Text::Encoding::UTF8);
			string^ style = sr->ReadToEnd();
			sr->Close();
			
			res = GetFullText();
			res = Utils::ProcessFTN(res,HellEdDir,lShowKludgesMode->ItemIndex!=0,bDecryptROT13->Down,bUseStyles->Down);
			res = string::Concat(L"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"><html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"><style>",style,L"</style></head>\n<body><table class=\"header\">",
				L"<tr><td class=\"headerkey\">",htStrings[L"Area"]->ToString()->
					Replace("&","&amp;")-> 
					Replace("\"","&quot;")-> 
					Replace("'","&#039")-> 
					Replace("<","&lt;")-> 
					Replace(">","&gt;"),L"</td>",
				L"<td class=\"headervalue\">",((string^)tlAreas->FocusedNode->GetValue(0))->
					Replace("&","&amp;")-> 
					Replace("\"","&quot;")-> 
					Replace("'","&#039")-> 
					Replace("<","&lt;")-> 
					Replace(">","&gt;"),L"</td></tr>\n",
				L"</table>",res,L"</body></html>");
			frmSettings->wbTemp->DocumentText=res;
			frmSettings->wbTemp->ShowPrintDialog();
		}
		public: void bCheckForUpdates_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			frmSettings->wbTemp->Navigate(L"http://sourceforge.net/project/showfiles.php?group_id=214592");
		}
	
		public: void wbTemp_DocumentCompleted(object^ sender, WebBrowserDocumentCompletedEventArgs^ e)
		{
			if (frmSettings->wbTemp->Url->ToString()->StartsWith(L"http://sourceforge.net"))
			{
				Regex^ re = gcnew Regex(L"helled\\-([\\d]+)\\.([\\d]+)\\.([\\d]+)\\-update",RegexOptions::IgnoreCase);
				Match^ m = re->Match(frmSettings->wbTemp->DocumentText);		
				frmSettings->wbTemp->Navigate(L"about:blank");
				if(m->Success)
				{
					int ve1 = System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Major;
					int ve2 = System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Minor;
					int ve3 = System::Reflection::Assembly::GetExecutingAssembly()->GetName()->Version->Build;
					int v1 = Convert::ToInt32(m->Groups[1]->Value);
					int v2 = Convert::ToInt32(m->Groups[2]->Value);
					int v3 = Convert::ToInt32(m->Groups[3]->Value);
					bool flg=true;
					if (v1>ve1){flg=false;}
					else if (v2>ve2){flg=false;}
					else if (v3>ve3){flg=false;}

					if (flg)
					{
						if (CheckForUpdatesFlag){DevExpress::XtraEditors::XtraMessageBox::Show(htStrings[L"NoUpdates"]->ToString(),htStrings[L"CheckingForUpdates"]->ToString());}
						CheckForUpdatesFlag=true;
					}
					else if (DevExpress::XtraEditors::XtraMessageBox::Show(string::Concat(htStrings[L"CheckForUpdatesTextBegin"]->ToString(),v1,".",v2,".",v3,htStrings[L"CheckForUpdatesTextEnd"]->ToString()),htStrings[L"CheckingForUpdates"]->ToString(),MessageBoxButtons::YesNo)==System::Windows::Forms::DialogResult::Yes)
					{
						System::Diagnostics::Process::Start(L"https://sourceforge.net/project/showfiles.php?group_id=214592");
					}
				}
			}
		}

		public: void bCopy_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Document->ExecCommand("Copy", false, nullptr);
		}
		public: void bSelectAll_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			rtText->Document->ExecCommand("selectAll", false, nullptr);
		}

		public: void bFind_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
               System::Object^ o = gcnew System::Object();
               Guid *cmdGuid = new Guid("ED016940-BD5B-11CF-BA4E-00C04FD70816");
               ((IOleCommandTargetWrapper^)((mshtml::IHTMLDocument2^)rtText->Document->DomDocument))
                     ->Exec(cmdGuid, (System::UInt32)MiscCommandTargetWrapper::Find, 0, o, o);
		}

		public: void lSkin_ListItemClick(object^ sender, DevExpress::XtraBars::ListItemClickEventArgs^ e) 
		{
			frmSettings->tlConfigHED->FindNodeByKeyID(501)->SetValue(1,lSkin->Strings[e->Index]);
			LoadConfigSkin(lSkin->Strings[e->Index]);
			lSkin->ItemIndex=-1;
			lSkin->ItemIndex=e->Index;
		}

		public: void lLanguage_ListItemClick(object^ sender, DevExpress::XtraBars::ListItemClickEventArgs^ e) 
		{
			frmSettings->tlConfigHED->FindNodeByKeyID(601)->SetValue(1,lLanguage->Strings[e->Index]);
			LoadConfigLanguage(lLanguage->Strings[e->Index]);
			lLanguage->ItemIndex=-1;
			lLanguage->ItemIndex=e->Index;
		}
		
		public: System::Void lShowKludgesMode_ListItemClick(System::Object^  sender, DevExpress::XtraBars::ListItemClickEventArgs^  e)
		{
			lShowKludgesMode->ItemIndex=-1;
			lShowKludgesMode->ItemIndex=e->Index;
			ShowMessageText();
		}
		public: System::Void mShowKludgesMode_ItemClick(System::Object^  sender, DevExpress::XtraBars::ItemClickEventArgs^  e)
		{
			lShowKludgesMode->ItemIndex++;
			if (lShowKludgesMode->ItemIndex>2){lShowKludgesMode->ItemIndex=0;}
			ShowMessageText();
		}
	
		public: void bDecryptROT13_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			ShowMessageText();
		}


		public: void bList_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if ((bTree->Down==true)&&(harea))
			{
				bList->Down = true;
				bTree->Down = false;
				if (tlAreas->FocusedNode->GetValue(8)->Equals(L""))
				{
					ShowMessages();
				}
			}
			bList->Down = true;	
			bTree->Down = false;	
		}
		public: void bTree_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if ((bList->Down==true)&&(harea))
			{
				bList->Down = false;
				bTree->Down = true;
				if (tlAreas->FocusedNode->GetValue(8)->Equals(L""))
				{
					ShowMessages();
				}
			}
			bList->Down = false;
			bTree->Down = true;	
		}

		public: void bHideUnmarked_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			bHideUnmarked->Down = true;	
			bShowAll->Down = false;	
			FilterMarkEnabled = true;
			ShowMessagesFlag=false;
			tlMessages->FilterNodes();
			ShowMessagesFlag=true;
		}
		public: void bShowAll_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			bHideUnmarked->Down = false;	
			bShowAll->Down = true;	
			FilterMarkEnabled = false;
			ShowMessagesFlag=false;
			tlMessages->FilterNodes();
			ShowMessagesFlag=true;
		}
		public: void bFilterNone_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			frmSettings->tlConfigHED->FindNodeByKeyID(301)->SetValue(1,L"");
			bFilterNone->Down = true;	
			lFilter->ItemIndex=-1;
			LoadConfigFilter(L"");
		}
		public: void lFilter_ListItemClick(object^ sender, DevExpress::XtraBars::ListItemClickEventArgs^ e) 
		{
			frmSettings->tlConfigHED->FindNodeByKeyID(301)->SetValue(1,lFilter->Strings[e->Index]);
			lFilter->ItemIndex=-1;
			lFilter->ItemIndex=e->Index;
			bFilterNone->Down=false;
			LoadConfigFilter(lFilter->Strings[e->Index]);
		}

		public: void tlMessages_FilterNode(object^ sender, DevExpress::XtraTreeList::FilterNodeEventArgs^ e)
		{
			bool vis=true;
			if (FilterMarkEnabled){if (e->Node->GetValue(1)->Equals(false)){vis=false;}}
			if (vis)
			{	
				if (FilterFromEnabled){if (!e->Node->GetValue(3)->Equals(FilterFrom)){vis=false;}}			
				if (vis)
				{
					if (FilterToEnabled){if (!e->Node->GetValue(4)->Equals(FilterTo)){vis=false;}}			
					if (vis)
					{
						if (FilterSubjectEnabled){if (!e->Node->GetValue(5)->Equals(FilterSubject)){vis=false;}}			
						if (vis)
						{
							if (FilterDateTimeEnabled)
							{
							}
							if (vis)
							{
			vis=!(ConfigFilter->Rows);
			if (!vis)
			{
			for(int i=0;i<ConfigFilter->Count;i++)
			if (((array<string^> ^)ConfigFilter->Rows[i])->Length>=3)
			{
				bool vis1=false;
				int col=-1;
				object^ val;
				string^ act =((array<string^> ^)ConfigFilter->Rows[i])[0];

				string^ str =((array<string^> ^)ConfigFilter->Rows[i])[1]->ToLower();
				string^ str1 =((array<string^> ^)ConfigFilter->Rows[i])[3]->ToLower();
				if (str->Equals(L"attributes"))
				{
					col=2;
					val=str1;
				}
				else if (str->Equals(L"oname"))
				{
					col=3;
					val=str1;
				}
				else if (str->Equals(L"dname"))
				{
					col=4;
					val=str1;
				}
				else if (str->Equals(L"subject"))
				{
					col=5;
					val=str1;
				}
				else if (str->Equals(L"odatetime"))
				{
					col=6;
					val=str1;
				}
				else if (str->Equals(L"ddatetime"))
				{
					col=7;
					val=0;
				}
				else if (str->Equals(L"area"))
				{
					col=8;
					val=str1;
				}
				if (col>=0)
				{
					string^ str =((array<string^> ^)ConfigFilter->Rows[i])[2];
					if (str->Equals(L"="))
					{if (e->Node->GetValue(col)->ToString()->ToLower()->Equals(val)){vis1=true;}}
					else if (str->Equals(L"!="))
					{
						if (e->Node->GetValue(col)->ToString()->ToLower()->Equals(val))
						{vis1=false;}
						else {vis1=true;}
					}
					else if (str->Equals(L"~"))
					{if (e->Node->GetValue(col)->ToString()->ToLower()->IndexOf(val->ToString())>=0){vis1=true;}}
					else if (str->Equals(L"!~"))
					{
						if (e->Node->GetValue(col)->ToString()->ToLower()->IndexOf(val->ToString())>=0)
						{vis1=false;}
						else {vis1=true;}
					}
					if (act->Equals(L"|")){vis=vis||vis1;}
					else {vis=vis&&vis1;}
				}
			}
			}
							}
						}
					}
				}
			}
			e->Node->Visible=vis;
			e->Handled=true;
		}

		public: void tlMessages_CustomDrawNodeCell(object^ sender, DevExpress::XtraTreeList::CustomDrawNodeCellEventArgs^ e) 
		{
			if (((string^)e->Node->GetValue(2))->IndexOf(L"read")==-1 && ((string^)e->Node->GetValue(2))->IndexOf(L"loc")==-1)
			{
				e->Appearance->Font = gcnew System::Drawing::Font(e->Appearance->Font, FontStyle::Bold);
			}
		}

		public: void bNew_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				FormCreate^ frmCreate = gcnew FormCreate(frmSettings,spell);
				frmCreate_InitializeComponents(frmCreate, L"new", (string^)tlAreas->FocusedNode->GetValue(0),L"",L"All",L"",L"");
			}
		}

		public: void lTemplate_ListItemClick(object^ sender, DevExpress::XtraBars::ListItemClickEventArgs^ e) 
		{
			if (harea)
			{
				FormCreate^ frmCreate = gcnew FormCreate(frmSettings,spell);
				frmCreate_InitializeComponents(frmCreate, lTemplate->Strings[e->Index], (string^)tlAreas->FocusedNode->GetValue(0),L"",L"All",L"",L"");
			}
		}

		public: void bReply_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				FormCreate^ frmCreate = gcnew FormCreate(frmSettings,spell);
				string^ str=L"";
				if (tlAreas->FocusedNode->GetValue(7)->Equals(L"localarea")){str=L"replyfromlocal";}
				else {str=L"reply";}
				frmCreate_InitializeComponents(frmCreate, str, (string^)tlAreas->FocusedNode->GetValue(0),L"",L"",L"",L"");
			}
		}
		public: void bUnsubscribe_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				FormCreate^ frmCreate = gcnew FormCreate(frmSettings,spell);
				frmCreate_InitializeComponents(frmCreate, L"unsubscribe", (string^)tlAreas->FocusedNode->GetValue(0),L"",L"",L"",L"");
			}
		}
		public: void bForward_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				FormCreate^ frmCreate = gcnew FormCreate(frmSettings,spell);
				frmCreate_InitializeComponents(frmCreate, L"forward", (string^)tlAreas->FocusedNode->GetValue(0),L"",L"",L"",L"");
			}
		}
		public: void bEdit_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				FormCreate^ frmCreate = gcnew FormCreate(frmSettings,spell);
				frmCreate_InitializeComponents(frmCreate, L"edit", (string^)tlAreas->FocusedNode->GetValue(0),L"",L"",L"",L"");
			}
		}
		public: void bSubscribe_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				string ^ areaname=InputBox->ShowInput(this,htStrings[L"Subscribe"]->ToString(),htStrings[L"EnterAreaName"]->ToString(),L"");
				if (!areaname->Equals(L""))
				{
					FormCreate^ frmCreate = gcnew FormCreate(frmSettings,spell);
					frmCreate_InitializeComponents(frmCreate, L"Subscribe", (string^)tlAreas->FocusedNode->GetValue(0),L"",L"",L"",L"");
					frmCreate->rtText->Text=string::Concat(L"+",areaname);
				}
			}
		}

		public: void bRestore_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				ShowFreeMessage();
				
				int n=0;
				int ind=-1;
				if (tlMessages->FocusedNode)
				{ind=tlMessages->FocusedNode->Id;}
				bool fl=true;
				tlMessages->BeginUpdate();
				for(int i=tlMessages->AllNodesCount-1;i>=0;i--)
				{
					bool val =*dynamic_cast<bool^>(tlMessages->FindNodeByID(i)->GetValue(1));
					if (val)
					{
						if (fl)
						{
							ind=i;
							fl=false;
						}
						RestoreMessage(i);
						n++;
					}
				}
				if (n==0)
				if (tlMessages->FocusedNode)
				{RestoreMessage(tlMessages->FocusedNode->Id);}
				tlMessages->EndUpdate();
				RescanMessages(true);
				ShowMessages();
				if (ind>=tlMessages->AllNodesCount){ind--;}
				if (ind>=0){tlMessages->SetFocusedNode(tlMessages->FindNodeByID(ind));}
				tlMessages->Focus();
			}
		}
		
		public: void bDelete_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				ShowFreeMessage();
				
				int n=0;
				int ind=-1;
				if (tlMessages->FocusedNode)
				{ind=tlMessages->FocusedNode->Id;}
				bool fl=true;
				tlMessages->BeginUpdate();
				for(int i=tlMessages->AllNodesCount-1;i>=0;i--)
				{
					bool val =*dynamic_cast<bool^>(tlMessages->FindNodeByID(i)->GetValue(1));
					if (val)
					{
						if (fl)
						{
							ind=i;
							fl=false;
						}
						DeleteMessage(i);
						n++;
					}
				}
				if (n==0)
				if (tlMessages->FocusedNode)
				{DeleteMessage(tlMessages->FocusedNode->Id);}
				tlMessages->EndUpdate();
				RescanMessages(true);
				ShowMessages();
				if (ind>=tlMessages->AllNodesCount){ind--;}
				if (ind>=0){tlMessages->SetFocusedNode(tlMessages->FindNodeByID(ind));}
				tlMessages->Focus();
			}
		}
		public: void bMark_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if ((harea)&&(tlMessages->FocusedNode))
			{
				bool val =*dynamic_cast<bool^>(tlMessages->FocusedNode->GetValue(1));
				tlMessages->FocusedNode->SetValue(1,!val);
			}
		}

		public: void bPrevious_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if ((harea)&&(tlMessages->FocusedNode))
			{
				TreeListNode^ fn = tlMessages->FocusedNode;
				if (fn->Equals(tlMessages->MovePrevVisible()))
				{
					tlAreas->MovePrevVisible();
					tlMessages->MoveLastVisible();
				}
			}
			else if (tlAreas->FocusedNode){tlAreas->MovePrevVisible();}
		}
		public: void bNext_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if ((harea)&&(tlMessages->FocusedNode))
			{
				TreeListNode^ fn = tlMessages->FocusedNode;
				if (fn->Equals(tlMessages->MoveNextVisible()))
				{
					tlAreas->MoveNextVisible();
				}
			}
			else if (tlAreas->FocusedNode)
			{
				tlAreas->MoveNextVisible();
			}
		}
		public: void bNextUnread_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			bool fl=true;
			bool fl1=true;
			TreeListNode^ node1;
			TreeListNode^ node;
			if ((harea)&&(tlMessages->FocusedNode))
			{
				node1 = tlMessages->FocusedNode;
				TreeListNode^ fn = tlMessages->FocusedNode;
				if (tlAreas->FocusedNode->GetValue(2)->ToString()->Equals(L"0")){fl1=false;}
				tlMessages->BeginUpdate();
				ShowMessagesFlag=false;
				while((fl1)&&(fl))
				{
					if (fn->Equals(tlMessages->MoveNextVisible())){fl1=false;}
					fn = tlMessages->FocusedNode;
					bool read = (((string^)fn->GetValue(2))->IndexOf(L"read")==-1)&&
						(((string^)fn->GetValue(2))->IndexOf(L"loc")==-1);
					if (read){fl=false;}
				}
				tlMessages->EndUpdate();
				ShowMessagesFlag=true;
				if (!fl)
				{
					tlMessages->SetFocusedNode(fn);
					if (tlMessages->FocusedNode)
					{
						msgn = *dynamic_cast<word^>(tlMessages->FocusedNode->GetValue(0));	
						ShowMessage();
					}
				}
			}
			if (fl)
			{
				bool fl0=true;
				bool fl10=true;
				node = tlAreas->FocusedNode;
				TreeListNode^ fn = tlAreas->FocusedNode;
				ShowAreasFlag=false;
				while((fl10)&&(fl0))
				{
					fn = tlAreas->FocusedNode;
					bool read = !((fn->GetValue(2)->ToString()->Equals(L""))||
						(fn->GetValue(2)->ToString()->Equals(L"0")));
					if (read){fl0=false;}
					else if (fn->Equals(tlAreas->MoveNextVisible())){fl10=false;}
				}
				if (!fl10)
				{
					tlAreas->SetFocusedNode(node);
					ShowMessagesFlag=false;
					tlMessages->SetFocusedNode(node1);
					ShowMessagesFlag=true;
				}
				ShowAreasFlag=true;
				if ((fl10)&&(!fn->Equals(node)))
				{
					if (harea){MsgCloseArea(harea); harea=nullptr;}
					
					if (tlAreas->FocusedNode->GetValue(0)->Equals(L"deleted")){bRestore->Enabled=true;}
					else {bRestore->Enabled=false;}

					int area_select_mode = frmSettings->rcbearea_select_mode->Items->IndexOf(frmSettings->tlConfigHED->FindNodeByKeyID(1001)->GetValue(1));
					if (area_select_mode==2)
					{frmSettings->tlConfigHED->FindNodeByKeyID(1002)->SetValue(1,tlAreas->FocusedNode->GetValue(0)->ToString());}
					string^ url = string::Concat(L"area://",(string^)tlAreas->FocusedNode->GetValue(0))->ToLower();
					beURL->EditValue = url; 
 					if (!rcbeURL->Items->Contains(url)){rcbeURL->Items->Add(url);}
					
					HistoryFlag=false;
					TreeListNode^ node = tlHistory->AppendNode(gcnew array<object^>(2){url,System::DateTime::Now},-1);
					tlHistory->SetFocusedNode(node);

					RescanMessages(true);
					ShowMessages();
				}
			}
		}
		public: void bPreviousArea_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (tlAreas->FocusedNode)
			{
				tlAreas->MovePrevVisible();
			}
		}
		public: void bNextArea_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (tlAreas->FocusedNode)
			{
				tlAreas->MoveNextVisible();
			}
		}

		public: void bHistoryBack_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			tlHistory->MoveNextVisible();
		}
		public: void bHistoryForward_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			tlHistory->MovePrevVisible();
		}

		public: void bMarkAll_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				tlMessages->BeginUpdate();
				for(int i=0;i<tlMessages->AllNodesCount;i++)
				{
					((array<rtlMessages^>^)tlMessages->DataSource)[i]->Mark=true;
				}
				tlMessages->EndUpdate();
			}
		}
		public: void bUnmarkAll_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				tlMessages->BeginUpdate();
				for(int i=0;i<tlMessages->AllNodesCount;i++)
				{
					((array<rtlMessages^>^)tlMessages->DataSource)[i]->Mark=false;
				}
				tlMessages->EndUpdate();
			}
		}
		public: void bInvertMark_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				tlMessages->BeginUpdate();
				for(int i=0;i<tlMessages->AllNodesCount;i++)
				{
					((array<rtlMessages^>^)tlMessages->DataSource)[i]->Mark=!((array<rtlMessages^>^)tlMessages->DataSource)[i]->Mark;
				}
				tlMessages->EndUpdate();
			}
		}
		public: void bMarkAsRead_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				word NotRead = *dynamic_cast<word^>(tlAreas->FocusedNode->GetValue(2));
				tlMessages->BeginUpdate();
				if (MsgLock(harea)!=0){return;}
				for(int i=0;i<tlMessages->AllNodesCount;i++)
				{
					bool val = *dynamic_cast<bool^>(tlMessages->FindNodeByID(i)->GetValue(1));
					string^ attributes = (string^)tlMessages->FindNodeByID(i)->GetValue(2);
					bool read = ((attributes->IndexOf(L"read")==-1)&&(attributes->IndexOf(L"loc")==-1));
					if ((val)&&(read))
					{
						word mn = *dynamic_cast<word^>(tlMessages->FindNodeByID(i)->GetValue(0));
						XMSG xmsg;
						HMSG hmsg = MsgOpenMsg(harea,MOPEN_RW,mn);
						MsgReadMsg(hmsg, &xmsg, 0, 0, nullptr, 0, nullptr);
						if ((xmsg.attr & MSGREAD)==0 && (xmsg.attr & MSGLOCAL)==0)
						{
							xmsg.attr|=MSGREAD;
							MsgWriteMsg(hmsg, 0, &xmsg, nullptr, 0, 0, 0, nullptr);
							NotRead--;
							tlMessages->FindNodeByID(i)->StateImageIndex=1;
							string^ attributes = Utils::AttrToString(xmsg.attr);
							((array<rtlMessages^>^)tlMessages->DataSource)[i]->Attributes=attributes;
							msgs[i]->Attributes=attributes;
						}
						MsgCloseMsg(hmsg);
					}
				}
				if (MsgUnlock(harea)!=0){return;}
				tlMessages->EndUpdate();
				tlAreas->FocusedNode->SetValue(2,NotRead);
				sNotRead->Caption=NotRead.ToString();
			}
		}

		public: void bMarkAsUnread_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				word NotRead = *dynamic_cast<word^>(tlAreas->FocusedNode->GetValue(2));
				tlMessages->BeginUpdate();
				if (MsgLock(harea)!=0){return;}
				for(int i=0;i<tlMessages->AllNodesCount;i++)
				{
					bool val = *dynamic_cast<bool^>(tlMessages->FindNodeByID(i)->GetValue(1));
					bool read = (((string^)tlMessages->FindNodeByID(i)->GetValue(2))->IndexOf(L"read")!=-1);
					if ((val)&&(read))
					{
						word mn = *dynamic_cast<word^>(tlMessages->FindNodeByID(i)->GetValue(0));
						XMSG xmsg;
						char *text = NULL;
						dword  textLen = 0;
						HMSG hmsg = MsgOpenMsg(harea,MOPEN_RW,mn);
						MsgReadMsg(hmsg, &xmsg, 0, 0, nullptr, 0, nullptr);
						if (xmsg.attr & MSGREAD)
						{
							xmsg.attr&=~MSGREAD;
							MsgWriteMsg(hmsg, 0, &xmsg, nullptr, 0, 0, 0, nullptr);
							NotRead++;
							tlMessages->FindNodeByID(i)->StateImageIndex=0;
							string^ attributes = Utils::AttrToString(xmsg.attr);
							((array<rtlMessages^>^)tlMessages->DataSource)[i]->Attributes=attributes;
							msgs[i]->Attributes=attributes;
						}
						MsgCloseMsg(hmsg);
					}
				}
				if (MsgUnlock(harea)!=0){return;}
				tlMessages->EndUpdate();
				tlAreas->FocusedNode->SetValue(2,NotRead);
				sNotRead->Caption=NotRead.ToString();
			}
		}
		public: void bMarkAllAsRead_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (harea)
			{
				word NotRead = *dynamic_cast<word^>(tlAreas->FocusedNode->GetValue(2));
				tlMessages->BeginUpdate();
				if (MsgLock(harea)!=0){return;}
				for(int i=0;i<tlMessages->AllNodesCount;i++)
				{
					string^ attributes = (string^)tlMessages->FindNodeByID(i)->GetValue(2);
					bool read = ((attributes->IndexOf(L"read")==-1)&&(attributes->IndexOf(L"loc")==-1));
					if (read)
					{
						word mn = *dynamic_cast<word^>(tlMessages->FindNodeByID(i)->GetValue(0));
						XMSG xmsg;
						HMSG hmsg = MsgOpenMsg(harea,MOPEN_RW,mn);
						MsgReadMsg(hmsg, &xmsg, 0, 0, nullptr, 0, nullptr);
						if ((xmsg.attr & MSGREAD)==0 && (xmsg.attr & MSGLOCAL)==0)
						{
							xmsg.attr|=MSGREAD;
							MsgWriteMsg(hmsg, 0, &xmsg, nullptr, 0, 0, 0, nullptr);
							NotRead--;
							tlMessages->FindNodeByID(i)->StateImageIndex=1;
							string^ attributes = Utils::AttrToString(xmsg.attr);
							((array<rtlMessages^>^)tlMessages->DataSource)[i]->Attributes=attributes;
							msgs[i]->Attributes=attributes;
						}
						MsgCloseMsg(hmsg);
					}
				}
				if (MsgUnlock(harea)!=0){return;}
				tlMessages->EndUpdate();
				tlAreas->FocusedNode->SetValue(2,NotRead);
				sNotRead->Caption=NotRead.ToString();
			}
		}
		public: void bSettings_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			Enabled=false;
			frmSettings->SaveConfigHED();
			frmSettings->Show();
		}

		public: void bHelp_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			if (File::Exists(string::Concat(HellEdDir,L"\\HellEd.chm")))
			{System::Diagnostics::Process::Start(string::Concat(HellEdDir,L"\\HellEd.chm"));}
		}

		public: void bAbout_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			Enabled=false;
			frmAbout->Show();
		}
		
		public: void bAddressBook_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{

		}
		public: void bCustomize_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
 			barManager->Customize();
		}
		public: void bClearHistory_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			tlHistory->ClearNodes();
			rcbeURL->Items->Clear();
		}

		public: void bTosser_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			RunTosser();
		}

		public: void FormMain_Closing(object^ sender, System::ComponentModel::CancelEventArgs^ e)
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	FormMain_Closing()");
			LogHED->Flush();

			SaveConfigForms();
			SaveConfigAreas();
			SaveConfigHistory();
		}

		public: void FormMain_Closed(object^ sender, System::EventArgs^ e)
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	FormMain_Closed()");
			LogHED->Flush();

			string^ tosser_onexit = frmSettings->tlConfigHED->FindNodeByKeyID(205)->GetValue(1)->ToString();
			if (tosser_onexit->Equals(L"True")){RunTosser();}

			frmSettings->SaveConfigHED();
	//		SaveCustomDictionary();
			LogHED->Close();
			notifyicon->Visible=false;
			MsgCloseApi();
		}
        
		public: void tlAreas_DragEnter(object^ sender, System::Windows::Forms::DragEventArgs^ e)
		{
			if(e->Data->GetDataPresent("DevExpress.XtraTreeList.Nodes.TreeListNode", false))
				if(tlMessages->Focused)
			{	
//				DevExpress::XtraTreeList::TreeListHitInfo^ hi = tlAreas->CalcHitInfo(tlAreas->PointToClient(Point(Control::MousePosition.X,Control::MousePosition.Y)));
//				agn = hi->Node;
//				if(agn)
//				if (!agn->Equals(tlAreas->FocusedNode))
				{
					if ((e->KeyState & 8) == 8)
					{e->Effect = DragDropEffects::Copy;}
					else {e->Effect = DragDropEffects::Move;}
				}
			}
        }

		public: void tlAreas_CellValueChanged(object^ sender, DevExpress::XtraTreeList::CellValueChangedEventArgs^ e)
		{
			if (e->Node->GetValue(8)->Equals(L"g"))
			if (e->Column->FieldName->Equals(L"Name"))
			{e->Node->SetValue(3,e->Value);}
			else if (e->Column->FieldName->Equals(L"Description"))
			{e->Node->SetValue(0,e->Value);}
		}
		public: void tlAreas_DragDrop(object^ sender, System::Windows::Forms::DragEventArgs^ e)
		{
            if(e->Data->GetDataPresent("DevExpress.XtraTreeList.Nodes.TreeListNode", false))
				if(tlMessages->Focused)
			{
				DevExpress::XtraTreeList::TreeListHitInfo^ hi = tlAreas->CalcHitInfo(tlAreas->PointToClient(Point(Control::MousePosition.X,Control::MousePosition.Y)));
				agn = hi->Node;
				if(agn)
				if (!agn->Equals(tlAreas->FocusedNode))
				{
					if (agn->GetValue(8)->Equals(L""))
					{
						string^ areaname=agn->GetValue(0)->ToString();
						if (harea)
						{
							ShowFreeMessage();
				
							int n=0;
							int ind=-1;
							if (tlMessages->FocusedNode)
							{ind=tlMessages->FocusedNode->Id;}
							bool fl=true;
							tlMessages->BeginUpdate();
							for(int i=tlMessages->AllNodesCount-1;i>=0;i--)
							{
								bool val =*dynamic_cast<bool^>(tlMessages->FindNodeByID(i)->GetValue(1));
								if (val)
								{
									if (fl)
									{
										ind=i;
										fl=false;
									}
									if ((e->KeyState & 8) == 8)
									{CopyMessage(((string^)tlAreas->FocusedNode->GetValue(0)),areaname,i);}
									else {MoveMessage(((string^)tlAreas->FocusedNode->GetValue(0)),areaname,i);}
									n++;
								}
							}
							if (n==0)
							if (tlMessages->FocusedNode)
							{
								if ((e->KeyState & 8) == 8)
								{CopyMessage(((string^)tlAreas->FocusedNode->GetValue(0)),areaname,tlMessages->FocusedNode->Id);}
								else {MoveMessage(((string^)tlAreas->FocusedNode->GetValue(0)),areaname,tlMessages->FocusedNode->Id);}
							}
							tlMessages->EndUpdate();
							RescanMessages(true);
							ShowMessages();
							if (ind>=tlMessages->AllNodesCount){ind--;}
							if (ind>=0){tlMessages->SetFocusedNode(tlMessages->FindNodeByID(ind));}
							tlMessages->Focus();
						}
					}
				}
			}
        }

		public: void MoveMessage(string^ farea, string^ tarea, int id)
		{
			if (tlMessages->FindNodeByID(id))
			{
				CopyMessage(farea,tarea,id);
				word mn =*dynamic_cast<word^>(tlMessages->FindNodeByID(id)->GetValue(0));
				MsgKillMsg(harea,mn);
			}
		}

		public: void tlAreas_BeforeFocusNode(object^ sender, DevExpress::XtraTreeList::BeforeFocusNodeEventArgs^ e)
		{
			this->tlcName->Options = (DevExpress::XtraTreeList::Columns::ColumnOptions)
				(DevExpress::XtraTreeList::Columns::ColumnOptions::CanMoved | 
				DevExpress::XtraTreeList::Columns::ColumnOptions::CanMovedToCustomizationForm |
				DevExpress::XtraTreeList::Columns::ColumnOptions::ShowInCustomizationForm |
				DevExpress::XtraTreeList::Columns::ColumnOptions::CanResized);
			this->tlcDescription->Options = (DevExpress::XtraTreeList::Columns::ColumnOptions)
				(DevExpress::XtraTreeList::Columns::ColumnOptions::CanMoved | 
				DevExpress::XtraTreeList::Columns::ColumnOptions::CanMovedToCustomizationForm |
				DevExpress::XtraTreeList::Columns::ColumnOptions::ShowInCustomizationForm |
				DevExpress::XtraTreeList::Columns::ColumnOptions::CanResized);
			if (e->Node->GetValue(8)->Equals(L"g"))
			{
				e->CanFocus = true;
				this->tlcName->Options = (DevExpress::XtraTreeList::Columns::ColumnOptions)
					(DevExpress::XtraTreeList::Columns::ColumnOptions::CanMoved | 
					DevExpress::XtraTreeList::Columns::ColumnOptions::CanMovedToCustomizationForm |
					DevExpress::XtraTreeList::Columns::ColumnOptions::ShowInCustomizationForm |
					DevExpress::XtraTreeList::Columns::ColumnOptions::CanResized | 
					DevExpress::XtraTreeList::Columns::ColumnOptions::CanFocused);
				this->tlcDescription->Options = (DevExpress::XtraTreeList::Columns::ColumnOptions)
					(DevExpress::XtraTreeList::Columns::ColumnOptions::CanMoved | 
					DevExpress::XtraTreeList::Columns::ColumnOptions::CanMovedToCustomizationForm |
					DevExpress::XtraTreeList::Columns::ColumnOptions::ShowInCustomizationForm |
					DevExpress::XtraTreeList::Columns::ColumnOptions::CanResized | 
					DevExpress::XtraTreeList::Columns::ColumnOptions::CanFocused);
			}
		}
		public: void tlAreas_BeforeDragNode(object^ sender, DevExpress::XtraTreeList::BeforeDragNodeEventArgs^ e)
		{
			if ((e->Node->GetValue(8)->Equals(L"g"))||
				(e->Node->GetValue(8)->Equals(L"s")))
			{e->CanDrag = false;}
		}
		public: void tlAreas_AfterDragNode(object^ sender, DevExpress::XtraTreeList::NodeEventArgs^ e)
		{
			TreeListNode^ node = e->Node->ParentNode;
			if (node)
			{
				if (node->GetValue(8)->Equals(L""))
				{
					tlAreas->MoveNode(node->Nodes->FirstNode,node->ParentNode);
				}
				else if (node->GetValue(8)->Equals(L"s"))
				{
					tlAreas->MoveNode(node->Nodes->FirstNode,node->ParentNode);
				}
			}
		}
		public: void rtText_MouseUp(System::Object^  sender, HtmlElementEventArgs^  e)
		{
			e->ReturnValue = false;
			e->BubbleEvent = false;
			pmEdit->ShowPopup(Control::MousePosition);
		}

		public: void tlAreas_MouseUp(object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			if((int)(e->Button & System::Windows::Forms::MouseButtons::Right) != 0 && tlAreas->ClientRectangle.Contains(e->X, e->Y))
			{
				bDeleteGroup->Enabled = false;
				DevExpress::XtraTreeList::TreeListHitInfo^ hi = tlAreas->CalcHitInfo(tlAreas->PointToClient(Point(Control::MousePosition.X,Control::MousePosition.Y)));
				agn = hi->Node;
				if(agn)
				{
					if (agn->GetValue(8)->Equals(L"g"))
					{
						bDeleteGroup->Enabled = true;
					}
				}
				pmAreas->ShowPopup(Control::MousePosition);
			}
		}
		public: void tlMessages_MouseUp(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			tlMessages->Focus();
			if((int)(e->Button & System::Windows::Forms::MouseButtons::Right) != 0 && tlMessages->ClientRectangle.Contains(e->X, e->Y))
			{	
				pmMessages->ShowPopup(Control::MousePosition);
			}
		}
		public: void bNewGroup_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			array<object^> ^ data = gcnew array<object^>(9);
			data[0]=L"<>";
			data[1]=L"";
			data[2]=L"";
			data[3]=L"";
			data[4]=L"";
			data[5]=L"";
			data[6]=L"";
			data[7]=L"";
			data[8]=L"g";
			TreeListNode^ node =tlAreas->AppendNode(data,-1);
			node->StateImageIndex=0;
		}
		public: void bDeleteGroup_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			for (int i=0;i<agn->Nodes->Count;i++)
			{tlAreas->MoveNode(agn->Nodes[i],agn->ParentNode);}
            tlAreas->DeleteNode(agn);
		}

		public: void tlAreas_CustomDrawNodeCell(object^ sender, DevExpress::XtraTreeList::CustomDrawNodeCellEventArgs^ e)
		{
			if (!((e->Node->GetValue(2)->ToString()->Equals(L""))||
				  (e->Node->GetValue(2)->ToString()->Equals(L"0"))))
				e->Appearance->Font = gcnew System::Drawing::Font(e->Appearance->Font, FontStyle::Bold);
		}
		
		public: void tlAreas_GetCustomNodeCellEdit(object^ sender, DevExpress::XtraTreeList::GetCustomNodeCellEditEventArgs^ e) 
		{
			if((e->Column->FieldName->Equals(L"Name"))||
				(e->Column->FieldName->Equals(L"Description")))
			{
				if ((e->Node->GetValue(8)->Equals(L""))||
					(e->Node->GetValue(8)->Equals(L"s")))
				{e->RepositoryItem = rtero;}
				else
				{e->RepositoryItem = rte;}
			}
		}

		public: void tlAreas_FocusedNodeChanged(object^ sender, DevExpress::XtraTreeList::FocusedNodeChangedEventArgs^ e)
		{
			if (ShowAreasFlag)
			if (e->Node)
			{
				if (LoadConfigTosserFlag)
				{tlMessages->ClearNodes();}
				
				if (harea){MsgCloseArea(harea); harea=nullptr;}
				if (e->Node->GetValue(8)->Equals(L""))
				{
					if (e->Node->GetValue(0)->Equals(L"deleted")){bRestore->Enabled=true;}
					else {bRestore->Enabled=false;}

					int area_select_mode = frmSettings->rcbearea_select_mode->Items->IndexOf(frmSettings->tlConfigHED->FindNodeByKeyID(1001)->GetValue(1));
					if (area_select_mode==2)
					{frmSettings->tlConfigHED->FindNodeByKeyID(1002)->SetValue(1,e->Node->GetValue(0)->ToString());}
					string^ url = string::Concat(L"area://",(string^)tlAreas->FocusedNode->GetValue(0))->ToLower();
					beURL->EditValue = url; 
 					if (!rcbeURL->Items->Contains(url)){rcbeURL->Items->Add(url);}
					if (HistoryFlag)
					{
						HistoryFlag=false;
						TreeListNode^ node = tlHistory->AppendNode(gcnew array<object^>(2){url,System::DateTime::Now},-1);
						tlHistory->SetFocusedNode(node);
					}
					RescanMessages(true);
					ShowMessages();
				}
				else 
				{
					ShowFreeMessage();
					beURL->EditValue = L"";
				}
			}
		}
		
		public: void tlMessages_FocusedNodeChanged(object^ sender, DevExpress::XtraTreeList::FocusedNodeChangedEventArgs^ e)
		{
			if ((harea)&&(e->Node))
			if (ShowMessagesFlag)
			if (tlMessages->FocusedNode)
			{
				msgn = *dynamic_cast<word^>(tlMessages->FindNodeByID(e->Node->Id)->GetValue(0));
				ShowMessage();
			}
		}

		public: void tlHistory_FocusedNodeChanged(object^ sender, DevExpress::XtraTreeList::FocusedNodeChangedEventArgs^ e)
		{
			if (e->Node)
			if (HistoryFlag)
			{
				HistoryFlag=false;
				ParseURL(tlHistory->FindNodeByID(e->Node->Id)->GetValue(0)->ToString());
				HistoryFlag=true;
			}
			else
			{HistoryFlag=true;}
		}
		public: void bSaveMessage_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			SaveFileDialog^ dlg = gcnew SaveFileDialog();
			dlg->Filter = L"HTML|*.html";
			dlg->FileName = string::Concat(teSubject->Text->
				 Replace("/","_")->
				 Replace("\\","_")->
				 Replace(":","_")->
				 Replace("*","_")->
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
			
			res = GetFullText();
			res = Utils::ProcessFTN(res,HellEdDir,lShowKludgesMode->ItemIndex!=0,bDecryptROT13->Down,bUseStyles->Down);
			res = string::Concat(L"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"><html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"><style>",style,L"</style></head>\n<body><table class=\"header\">",
				L"<tr><td class=\"headerkey\">",htStrings[L"Area"]->ToString()->
					Replace("&","&amp;")-> 
					Replace("\"","&quot;")-> 
					Replace("'","&#039")-> 
					Replace("<","&lt;")-> 
					Replace(">","&gt;"),L"</td>",
				L"<td class=\"headervalue\">",((string^)tlAreas->FocusedNode->GetValue(0))->
					Replace("&","&amp;")-> 
					Replace("\"","&quot;")-> 
					Replace("'","&#039")-> 
					Replace("<","&lt;")-> 
					Replace(">","&gt;"),L"</td></tr>\n",
				L"</table>",res,L"</body></html>");
			if(dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				StreamWriter^ sw = gcnew StreamWriter(dlg->FileName,false,System::Text::Encoding::UTF8);
				sw->Write(res);
				sw->Close();
			}
		}

		public: void bSaveAsTemplate_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			SaveFileDialog^ dlg = gcnew SaveFileDialog();
			dlg->Filter = L"Template (*.txt)|*.txt";
			dlg->FileName = string::Concat(teSubject->Text->
				 Replace("/","_")->
				 Replace("\\","_")->
				 Replace(":","_")->
				 Replace("*","_")->
				 Replace("?","_")->
				 Replace("\"","_")->
				 Replace("<","_")->
				 Replace(">","_")->
				 Replace("|","_")
				 ,L".txt");
			if(dlg->ShowDialog() == System::Windows::Forms::DialogResult::OK)
			{
				string^ res;
				StreamWriter^ sw = gcnew StreamWriter(dlg->FileName,false,System::Text::Encoding::UTF8);
			
				res = GetFullText();
				res = string::Concat(L"Area ",(string^)tlAreas->FocusedNode->GetValue(0),
					L"\nOName ",oname,
					L"\nOAddr ",oaddr,
					L"\nDName ",dname,
					L"\nDAddr ",daddr,
					L"\nSubject ",subject,
					L"\nODateTime ",teWritten->Text,
					L"\nAttributes ",teAttributes->Text,
					L"\n",res);
				sw->Write(res);
				sw->Close();
			}
		}
		public: void rcbeURL_KeyDown(object^ sender, KeyEventArgs^ e)
		{
			DevExpress::XtraEditors::ComboBoxEdit^ edit = (DevExpress::XtraEditors::ComboBoxEdit^)sender;
			if(e->KeyData == Keys::Enter)
			{
				string^ url=beURL->EditValue->ToString()->ToLower();
				barManager->ActiveEditItemLink->PostEditor();
				edit->SelectAll();
				e->Handled = true;
				if ((url->StartsWith(L"area:"))||
					(url->StartsWith(L"netmail:"))||
					(url->StartsWith(L"echomail:"))||
					(url->StartsWith(L"areafix:")))
				{ParseURL(beURL->EditValue->ToString());}
				else if ((url->StartsWith(L"http:"))||
					(url->StartsWith(L"mailto:"))||
					(File::Exists(url))||
					(Directory::Exists(url)))
				{System::Diagnostics::Process::Start(beURL->EditValue->ToString());}
			}
		}
		public: void rcbeURL_SelectedItemChanged(object^ sender, System::EventArgs^ e)
		{
			if(barManager->ActiveEditor != nullptr)
				if(!((DevExpress::XtraEditors::ComboBoxEdit^)barManager->ActiveEditor)->IsPopupOpen &&
					((DevExpress::XtraEditors::ComboBoxEdit^)barManager->ActiveEditor)->SelectedIndex != -1)
				{
					string^ url=barManager->ActiveEditor->EditValue->ToString()->ToLower();
					if ((url->StartsWith(L"area:"))||
						(url->StartsWith(L"netmail:"))||
						(url->StartsWith(L"echomail:"))||
						(url->StartsWith(L"areafix:")))
					{ParseURL(barManager->ActiveEditor->EditValue->ToString());}
					else if ((url->StartsWith(L"http:"))||
						(url->StartsWith(L"mailto:"))||
						(File::Exists(url))||
						(Directory::Exists(url)))
					{System::Diagnostics::Process::Start(barManager->ActiveEditor->EditValue->ToString());}
				}
		}

		public: void ParseURL(string^ url)
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(string::Concat(L"	ParseURL(L\"",url,"\")"));
			LogHED->Flush();

			Regex^ re = gcnew Regex(L"area://((?:[A-Za-z0-9\\._\\-&\\+]|(?:%[0-9A-F]{2}))*)/?(?:\\?(?:&?(msgid|time|usetz|from|to|subject|subj|find|geomark|geofrom|kl)(?:=((?:[A-Za-z0-9\\.\\+/,!@$^\\*\\(\\)\\-=_:\\\"';]|(?:%[0-9A-F]{2}))*))?)*)?",RegexOptions::IgnoreCase);
			Match^ m = re->Match(url);		
			if(m->Success)
			{
				area = Utils::URLDecode(m->Groups[1]->Value->ToLower());
				if ((!area->Equals(L""))&&(area->IndexOf(L" ")<0))
				{
					ani=-1;
					for(int i=0;i<tlAreas->AllNodesCount;i++)
					{
					if (ani==-1)
					if (tlAreas->FindNodeByID(i)->GetValue(8)->Equals(L""))
					if (((string^)tlAreas->FindNodeByID(i)->GetValue(0))->ToLower()->Equals(area))
					{
						ani=i;
					}
					}
					if (ani==-1)
					{
						if (DevExpress::XtraEditors::XtraMessageBox::Show(string::Concat(htStrings[L"SubscribeText"]->ToString(),L"\n\n",area),htStrings[L"Subscribe"]->ToString(),MessageBoxButtons::YesNo)==System::Windows::Forms::DialogResult::Yes)
						{
							if (harea)
							{
								FormCreate^ frmCreate = gcnew FormCreate(frmSettings,spell);
								frmCreate_InitializeComponents(frmCreate, L"Subscribe",L"", L"",L"",L"",L"");
								frmCreate->rtText->Text=string::Concat(L"+",area);
							}
						}
					}
					else 
					{
						FilterFromEnabled=false;
		  			    FilterToEnabled=false;
						FilterSubjectEnabled=false;
						FilterDateTimeEnabled=false;
						ni=-1;
						for (int k=0;k<m->Groups[2]->Captures->Count;k++)
						{
							string^ keyy=m->Groups[2]->Captures[k]->Value->ToString();
							string^ vall=L"";
							if (k<m->Groups[3]->Captures->Count)
							{vall=Utils::URLDecode(m->Groups[3]->Captures[k]->Value->ToString());}
							nmsgid=L"";
							if (keyy->Equals(L"msgid"))
							{
								nmsgid=vall;
							}
							else if (keyy->Equals(L"from"))
							{
								FilterFrom=vall;
								FilterFromEnabled=true;
							}
							else if (keyy->Equals(L"to"))
							{
								FilterTo=vall;
								FilterToEnabled=true;
							}
							else if ((keyy->Equals(L"subj"))||(keyy->Equals(L"subject")))
							{
								FilterSubject=vall;
								FilterSubjectEnabled=true;
							}
							else if (keyy->Equals(L"time"))
							{
								FilterDateTimeEnabled=true;
							}
						}
						if (tlAreas->FocusedNode)
						{
							if (tlAreas->FocusedNode->Id==ani)
							{
								ShowMessagesFlag=false;
								tlMessages->FilterNodes();
								ShowMessagesFlag=true;
								
								bool pp=true;
								for (int q=0;(q<tlMessages->AllNodesCount)&&(pp);q++)
								{
									if (tlMessages->FindNodeByID(q)->GetValue(9)->Equals(nmsgid))
									{
										pp=false;
										ni=Convert::ToInt32(tlMessages->FindNodeByID(q)->GetValue(0))-1;
									}
								}
								if (ni!=-1)
								{
									tlMessages->SetFocusedNode(tlMessages->FindNodeByID(ni));
								}
							}
							else {tlAreas->SetFocusedNode(tlAreas->FindNodeByID(ani));}
						}
						else {tlAreas->SetFocusedNode(tlAreas->FindNodeByID(ani));}
					}
				}
			}
	
			re = gcnew Regex(L"areafix:((?:[A-Za-z0-9\\._\\-&\\+]|(?:%[0-9A-F]{2}))*)(?:\\?(?:&?(leave|unsubscribe|uplink)(?:=((?:[A-Za-z0-9\\.\\+/,!@$^\\*\\(\\)\\-=_:\\\"';]|(?:%[0-9A-F]{2}))*))?)*)?",(RegexOptions)(RegexOptions::Multiline|RegexOptions::IgnoreCase));
			m = re->Match(url);		
			if(m->Success)
			{
				string^ area=Utils::URLDecode(m->Groups[1]->Value);
				if (area->Equals(L"")){area=(string^)tlAreas->FocusedNode->GetValue(0);}
				string^ templ=L"Subscribe";
				string^ txt=L"";
				array<string^> ^strs = area->Split(((string^)L" ")->ToCharArray());
				for(int q=0;q<strs->Length;q++)if (strs[q]!="")
				{
					txt=string::Concat(txt,L"+",strs[q],L"\r\n");
				}
				string^ da=L"";
				for (int k=0;k<m->Groups[2]->Captures->Count;k++)
				{
					string^ keyy=m->Groups[2]->Captures[k]->Value->ToString();
					string^ vall=L"";
					if (k<m->Groups[3]->Captures->Count)
					{vall=Utils::URLDecode(m->Groups[3]->Captures[k]->Value->ToString());}
					if ((keyy->Equals(L"leave"))||(keyy->Equals(L"unsubscribe")))
					{
						templ=L"unsubscribe";
						txt=L"";
						for(int q=0;q<strs->Length;q++)if (strs[q]!="")
						{
							txt=string::Concat(txt,L"-",strs[q],L"\r\n");
						}
					}
					if (keyy->Equals(L"uplink")){da=vall;}
				}

				if (harea)
				{
					FormCreate^ frmCreate = gcnew FormCreate(frmSettings,spell);
					frmCreate_InitializeComponents(frmCreate, templ,L"", L"",L"",da,L"");
					frmCreate->rtText->Text=txt;
				}
			}

			re = gcnew Regex(L"netmail:(\\d{1,5}:\\d{1,5}/\\d{1,5}(?:\\.\\d{1,5})?)(?:\\?(?:&?(to|subject|subj|body|from)(?:=((?:[A-Za-z0-9\\.\\+/,!@$^\\*\\(\\)\\-=_:\\\"';]|(?:%[0-9A-F]{2}))*))?)*)?",(RegexOptions)(RegexOptions::Multiline|RegexOptions::IgnoreCase));
			m = re->Match(url);		
			if(m->Success)
			{
				string^ area=L"netmail";
				string^ su=L"";
				string^ dn=L"";
				string^ on=L"";
				string^ da = m->Groups[1]->Value;
				string^ txt;
				for (int k=0;k<m->Groups[2]->Captures->Count;k++)
				{
					string^ keyy=m->Groups[2]->Captures[k]->Value->ToString();
					string^ vall=L"";
					if (k<m->Groups[3]->Captures->Count)
					{vall=Utils::URLDecode(m->Groups[3]->Captures[k]->Value->ToString());}
					if ((keyy->Equals(L"subj"))||(keyy->Equals(L"subject"))){su=vall;}
					else if (keyy->Equals(L"to")){dn=vall;}
					else if (keyy->Equals(L"from")){on=vall;}
					else if (keyy->Equals(L"body")){txt=vall;}
				}

				if (harea)
				{
					FormCreate^ frmCreate = gcnew FormCreate(frmSettings,spell);
					frmCreate_InitializeComponents(frmCreate, L"new", L"netmail",on,dn,da,su);
					if (txt){frmCreate->rtText->Text=txt;}
				}
			}

			re = gcnew Regex(L"echomail:((?:[A-Za-z0-9\\._\\-&\\+]|(?:%[0-9A-F]{2}))+)(?:\\?(?:&?(to|subject|subj|body|from)(?:=((?:[A-Za-z0-9\\.\\+/,!@$^\\*\\(\\)\\-=_:\\\"';]|(?:%[0-9A-F]{2}))*))?)*)?",(RegexOptions)(RegexOptions::Multiline|RegexOptions::IgnoreCase));
			m = re->Match(url);		
			if(m->Success)
			{
				string^ area=Utils::URLDecode(m->Groups[1]->Value);
				string^ su=L"";
				string^ dn=L"";
				string^ on=L"";
				string^ da=L"";
				string^ txt;
				for (int k=0;k<m->Groups[2]->Captures->Count;k++)
				{
					string^ keyy=m->Groups[2]->Captures[k]->Value->ToString();
					string^ vall=L"";
					if (k<m->Groups[3]->Captures->Count)
					{vall=Utils::URLDecode(m->Groups[3]->Captures[k]->Value->ToString());}
					if ((keyy->Equals(L"subj"))||(keyy->Equals(L"subject"))){su=vall;}
					else if (keyy->Equals(L"to")){dn=vall;}
					else if (keyy->Equals(L"from")){on=vall;}
					else if (keyy->Equals(L"body")){txt=vall;}
				}

				if (harea)
				{
					FormCreate^ frmCreate = gcnew FormCreate(frmSettings,spell);
					frmCreate_InitializeComponents(frmCreate, L"new", area,on,dn,da,su);
					if (txt){frmCreate->rtText->Text=txt;}
				}
			}

			if (url->StartsWith(L"-rescan"))
			{
				string^ FileName = (string^)frmSettings->tlConfigHED->FindNodeByKeyID(208)->GetValue(1);
				bool fl1;
				array<string^> ^strs;
				if (!FileName->Equals(L""))
				{
					string^ import = L"";
					if (File::Exists(FileName))
					{
						StreamReader^ sr = gcnew StreamReader(FileName,System::Text::Encoding::UTF8);
						import = sr->ReadToEnd();
						sr->Close();
					}
					strs = import->Split(((string^)L"\r\n")->ToCharArray());
					StreamWriter^ sw = gcnew StreamWriter(FileName,false,System::Text::Encoding::GetEncoding(frmSettings->ConfigEncoding));
					sw->Write(L"");
					sw->Close();
					fl1=false;
				}
				else {fl1=true;}

				int nm=0;
				string^ nma=L"";
				for(int i=0;i<tlAreas->AllNodesCount;i++)
				if (tlAreas->FindNodeByID(i)->GetValue(8)->Equals(L""))
				if (!tlAreas->FindNodeByID(i)->Equals(tlAreas->FocusedNode))

				{
					bool fl=fl1;
					string^ areaname=tlAreas->FindNodeByID(i)->GetValue(0)->ToString();

					if (strs)
					{
						for(int p=0;(p<strs->Length)&&(!fl);p++)
							if (strs[p]->Equals(areaname)){fl=true;}
					}
					if (fl)
					{
						string^ Path = (string^)tlAreas->FindNodeByID(i)->GetValue(4);
						string^ Address = (string^)tlAreas->FindNodeByID(i)->GetValue(5);
						string^ BaseType = ((string^)tlAreas->FindNodeByID(i)->GetValue(6))->ToLower();
						word type;
						if (BaseType->Equals("msg")){type=MSGTYPE_SDM;}
						if (BaseType->Equals("squish")){type=MSGTYPE_SQUISH;}
						if (BaseType->Equals("jam")){type=MSGTYPE_JAM;}
						char* mas = (char*)(void*)Marshal::StringToHGlobalAnsi(Path);
						harea = MsgOpenArea((byte*)mas, MSGAREA_CRIFNEC, type);
						Marshal::FreeHGlobal((System::IntPtr)mas);
						if (harea==nullptr){return;}
						word count=MsgNumMsg(harea);
						word NotRead = *dynamic_cast<word^>(tlAreas->FindNodeByID(i)->GetValue(2)) + count - *dynamic_cast<word^>(tlAreas->FindNodeByID(i)->GetValue(1));
						int nm1=count - *dynamic_cast<word^>(tlAreas->FindNodeByID(i)->GetValue(1));
						nm+=nm1;
						if (nm1>0){nma=string::Concat(nma,tlAreas->FindNodeByID(i)->GetValue(0),L" (",nm1,L")\r\n");}

						tlAreas->FindNodeByID(i)->SetValue(1,count);
						tlAreas->FindNodeByID(i)->SetValue(2,NotRead);
						MsgCloseArea(harea);
						harea=nullptr;
					}
				}
				if (tlAreas->FocusedNode)
				if (tlAreas->FocusedNode->GetValue(8)->Equals(L""))
				{
					RescanMessages(false);
					if (tlMessages->FocusedNode)
						ni=tlMessages->FocusedNode->Id;
					if (UpdateMessagesFlag){ShowMessages();}
				}
				if (nm!=0)
				{
					int popup_time=	Convert::ToInt64(frmSettings->tlConfigHED->FindNodeByKeyID(1103)->GetValue(1));
					if (popup_time>0)
						frmPopup->ShowPopup(this->Text,string::Concat(htStrings[L"NewMessages"],L" ",nm,L"\r\n",nma));
				}
			}
		}
		public: System::Void tiMain_Tick(System::Object^  sender, System::EventArgs^  e)
		{
			int tosser_time=Convert::ToInt64(frmSettings->tlConfigHED->FindNodeByKeyID(209)->GetValue(1));
			if (tosser_time>0)
			if (System::Environment::TickCount - LastTosserTick>=tosser_time*1000*60)
			{
				LastTosserTick=System::Environment::TickCount;
				RunTosser();
			}
		}
		public: void DeleteMessage(int id)
		{
			if (tlMessages->FindNodeByID(id))
			{
				if (!((string^)tlAreas->FocusedNode->GetValue(0))->Equals(L"deleted"))
				{CopyMessage(((string^)tlAreas->FocusedNode->GetValue(0)),L"deleted", id);}
				word mn =*dynamic_cast<word^>(tlMessages->FindNodeByID(id)->GetValue(0));
				MsgKillMsg(harea,mn);
			}
		}
		public: void RestoreMessage(int id)
		{
			if (tlMessages->FindNodeByID(id))
			{
				if (((string^)tlAreas->FocusedNode->GetValue(0))->Equals(L"deleted"))
				MoveMessage(L"", L"", id);
			}
		}

		public: void CopyMessage(string^ farea, string^ tarea, int id)
		{
			if (tlMessages->FindNodeByID(id))
			{
				word mn =*dynamic_cast<word^>(tlMessages->FindNodeByID(id)->GetValue(0));
				if (MsgLock(harea)!=0){return;}
				XMSG xmsg;
				HMSG hmsg = MsgOpenMsg(harea,MOPEN_READ,mn);
				dword txtLen = MsgGetTextLen(hmsg);
				dword ctrlLen = MsgGetCtrlLen(hmsg);
				char* txt = new char[txtLen+1];
				char* ctrl = new char[ctrlLen+1];
				MsgReadMsg(hmsg, &xmsg, 0L, txtLen, (byte*)txt, ctrlLen, (byte*)ctrl);
				MsgCloseMsg(hmsg);
				if (MsgUnlock(harea)!=0){return;}
				txt[txtLen]=0;
				ctrl[ctrlLen]=0;

				System::Text::Encoding^ ew = System::Text::Encoding::Default;
				System::Text::Encoding^ ed = System::Text::Encoding::GetEncoding(frmSettings->MessagesEncoding);
				
				string^ qkludges = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)CvtCtrlToKludge((byte*)ctrl))))->TrimEnd('\r')->Replace(L"\r",L"\n");
				
				Regex^ re = gcnew Regex(L"^(?:FAREA):\\s([^]*?)$",RegexOptions::Multiline);
				Match^ m = re->Match(qkludges);
				if (m->Success)
				{
					if (tarea->Equals(L"")){tarea=m->Groups[1]->Value;}
					qkludges = string::Concat(qkludges->Substring(0,m->Index),
						qkludges->Substring(m->Index+m->Length),
						L"FAREA: ", farea);
				}
				else
				{qkludges = string::Concat(qkludges,L"FAREA: ", farea);}
				qkludges=qkludges->Replace("\n","\r");
				ctrlLen = qkludges->Length;

				bool b=false;
				int q=0;
				for(q=0;(q<tlAreas->AllNodesCount)&&(!b);q++)
				if (tlAreas->FindNodeByID(q)->GetValue(8)->Equals(L""))
				if (tlAreas->FindNodeByID(q)->GetValue(0)->Equals(tarea)){b=true;q--;}

				if (b)
				{

					string^ Path = (string^)tlAreas->FindNodeByID(q)->GetValue(4);
					string^ Address = (string^)tlAreas->FindNodeByID(q)->GetValue(5);
					string^ BaseType = ((string^)tlAreas->FindNodeByID(q)->GetValue(6))->ToLower();
					word type;
					if (BaseType->Equals("msg")){type=MSGTYPE_SDM;}
					if (BaseType->Equals("squish")){type=MSGTYPE_SQUISH;}
					if (BaseType->Equals("jam")){type=MSGTYPE_JAM;}

					char* mas = (char*)(void*)Marshal::StringToHGlobalAnsi(Path);
					HAREA harea2 = MsgOpenArea((byte*)mas, MSGAREA_CRIFNEC, type);
					Marshal::FreeHGlobal((System::IntPtr)mas);
					if (harea2==nullptr){return;}
					if (MsgLock(harea2)!=0){return;}
					hmsg=MsgOpenMsg(harea2,MOPEN_CREATE,0);
					char* mas2 = (char*)(void*)Marshal::StringToHGlobalAnsi(gcnew string(ew->GetChars(ed->GetBytes(qkludges))));
					if (MsgWriteMsg(hmsg, 0, &xmsg, (byte*)txt, txtLen,
						txtLen, ctrlLen, (byte*)mas2)!=0)
					{}
					Marshal::FreeHGlobal((System::IntPtr)mas2);
					MsgCloseMsg(hmsg);
					if (MsgUnlock(harea2)!=0){return;}
					MsgCloseArea(harea2);
					delete txt;
					delete ctrl;
					tlAreas->FindNodeByID(q)->SetValue(1,(word)(*dynamic_cast<word^>(tlAreas->FindNodeByID(q)->GetValue(1))+1));
				}
			}
		}

		public: void RunTosser()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	RunTosser()");
			LogHED->Flush();

			string^ FileName = (string^)frmSettings->tlConfigHED->FindNodeByKeyID(207)->GetValue(1);
			if (!FileName->Equals(L""))
			{
				StreamWriter^ sw = gcnew StreamWriter(FileName,false,System::Text::Encoding::GetEncoding(frmSettings->ConfigEncoding));
				sw->Write(frmSettings->echotoss);
				sw->Close();
			}
			frmSettings->echotoss=L"";
			if (File::Exists((string^)frmSettings->tlConfigHED->FindNodeByKeyID(203)->GetValue(1)))
			{System::Diagnostics::Process::Start((string^)frmSettings->tlConfigHED->FindNodeByKeyID(203)->GetValue(1));}
		}
//
// Сообщения
//
		public: void RescanMessages(bool Full)
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(string::Concat(L"	RescanMessages(",Full.ToString(),")"));
			LogHED->Flush();
			
			string^ area = (string^)tlAreas->FocusedNode->GetValue(0);
			string^ Path = (string^)tlAreas->FocusedNode->GetValue(4);
			string^ Address = (string^)tlAreas->FocusedNode->GetValue(5);
			string^ BaseType = ((string^)tlAreas->FocusedNode->GetValue(6))->ToLower();
			word type=MSGTYPE_SQUISH;
			if (BaseType->Equals("msg")){type=MSGTYPE_SDM;}
			else if (BaseType->Equals("squish")){type=MSGTYPE_SQUISH;}
			else if (BaseType->Equals("jam")){type=MSGTYPE_JAM;}

			char* mas = (char*)(void*)Marshal::StringToHGlobalAnsi(Path);
			harea = MsgOpenArea((byte*)mas, MSGAREA_CRIFNEC, type);
			Marshal::FreeHGlobal((System::IntPtr)mas);
			if (harea==nullptr){return;}
			word count=MsgNumMsg(harea);
			word oldcount=0;
			if (msgs){oldcount=msgs->Length;}

			if (Full)
			{
				FilterFromEnabled=false;
	            FilterToEnabled=false;
		        FilterSubjectEnabled=false;
			    FilterDateTimeEnabled=false;
				msgs = gcnew array<rtlMessages^>(count);
			}
			else if (oldcount==count)
			{
				UpdateMessagesFlag=false;
				return;
			}
			else
			{
				Array::Resize(msgs,count);
			}

			System::Text::Encoding^ ew = System::Text::Encoding::Default;
			System::Text::Encoding^ ed = System::Text::Encoding::GetEncoding(frmSettings->MessagesEncoding);

			word NotRead = Full ? 0 :*dynamic_cast<word^>(tlAreas->FocusedNode->GetValue(2));

			int badcount=0;
			ni=-1;
			UpdateMessagesFlag=true;

			for(int i = Full ? 0 : oldcount;i<count;i++)
			{
				XMSG xmsg;
				HMSG hmsg = MsgOpenMsg(harea,MOPEN_READ,i+1);
				if (hmsg)
				{
					dword ctrlLen = MsgGetCtrlLen(hmsg);
					char* ctrl = new char[ctrlLen+1];
					MsgReadMsg(hmsg, &xmsg, 0, 0, nullptr, ctrlLen, (byte*)ctrl);
					ctrl[ctrlLen]=0;
					string^ attributes = Utils::AttrToString(xmsg.attr);
					string^ oname = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)xmsg.from)));
					string^ dname = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)xmsg.to)));
					string^ subject = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)xmsg.subj)));
					System::DateTime odatetime = Utils::_stampToDateTime(xmsg.date_written);
					System::DateTime ddatetime = Utils::_stampToDateTime(xmsg.date_arrived);
					dword msgidi = xmsg.umsgid;
					dword replyto = xmsg.replyto;
					string^ fghimsgid=L"";
					MsgCloseMsg(hmsg);

					string^ kludges = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)CvtCtrlToKludge((byte*)ctrl))));
					int ind = kludges->IndexOf(L"MSGID: ");
					if (ind!=-1)
					{
						int ind2 = kludges->Substring(ind+8)->IndexOf(L"\r");
						if (ind2==-1){ind2=kludges->Length-ind-8;}
						fghimsgid = kludges->Substring(ind+8,ind2)->Trim()->ToLower();
					}

					if (msgidi==0)
					{
						char* mas = (char*)(void*)Marshal::StringToHGlobalAnsi(string::Concat(HellEdDir,L"\\temp"));
						msgidi=GenMsgId(mas, 3ul*365*24*60*60);
					}
					else
					{
						bool fla=true;
						for (int p=0;(p<i)&&(fla==true);p++)
						if (msgidi==msgs[p]->ID)
						{
							char* mas = (char*)(void*)Marshal::StringToHGlobalAnsi(string::Concat(HellEdDir,L"\\temp"));
							msgidi=GenMsgId(mas, 3ul*365*24*60*60);
							fla=false;
						}
					}
					msgs[i]= gcnew rtlMessages(msgidi,replyto,i+1,false,attributes,oname,dname,
						subject,odatetime,ddatetime,area,fghimsgid);
					if ((xmsg.attr & MSGREAD)==0 & (xmsg.attr & MSGLOCAL)==0)
					{
						NotRead++;
					}
					if (fghimsgid->Equals(nmsgid))
					{
						ni=i;
					}
				}
				else {badcount++;}
			}
			if (badcount>0)
			{
				count-=badcount;
				Array::Resize(msgs,count);
			}

			tlAreas->FocusedNode->SetValue(1,count);
			tlAreas->FocusedNode->SetValue(2,NotRead);
			sArea->Caption=((string^)tlAreas->FocusedNode->GetValue(0))->Replace(L"&",L"&&");
			sCount->Caption=count.ToString();
			sNotRead->Caption=NotRead.ToString();
		}

		public: void ShowMessages()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	ShowMessages()");
			LogHED->Flush();

			if (bList->Down)
			{
				tlMessages->KeyFieldName=L"ID";
				tlMessages->ParentFieldName=L"";
			}
			else
			{
				tlMessages->KeyFieldName=L"ID";
				tlMessages->ParentFieldName=L"ParentID";
			}
			int nni=ni;
			ShowMessagesFlag=false;
			tlMessages->DataSource=nullptr;
			tlMessages->DataSource=msgs;
			tlMessages->BeginUpdate();
			tlMessages->ExpandAll();
			ni=nni;
			bool unreadexists=false;
			if (msgs)
			for (int i=0;i<msgs->Length;i++)
			{
				if ((msgs[i]->Attributes->IndexOf(L"read")==-1)&&(msgs[i]->Attributes->IndexOf(L"loc")==-1))
				{
					tlMessages->FindNodeByID(i)->StateImageIndex = 0;
					if (ni==-1){unreadexists=true;}
				}
				else 
				{tlMessages->FindNodeByID(i)->StateImageIndex = 1;}
			}
			if ((msgs->Length>0)&&(unreadexists))
			{
				TreeListNode^ fn = tlMessages->MoveFirst();
				ni=fn->Id;
				string^ attrs = (string^)tlMessages->FocusedNode->GetValue(2);
				bool read = (attrs->IndexOf(L"read")==-1)&&
							(attrs->IndexOf(L"loc")==-1);
				if(!read)
				{
					fn = tlMessages->FocusedNode;
					bool fl=true;
					while(fl)
					{
						if (fn->Equals(tlMessages->MoveNextVisible())){fl=false;}
						fn = tlMessages->FocusedNode;
						int i=fn->Id;
						if ((msgs[i]->Attributes->IndexOf(L"read")==-1)&&(msgs[i]->Attributes->IndexOf(L"loc")==-1))
						{fl=false;}
					}
					ni=fn->Id;
				}
			}
			else 
			{if (ni==-1){ni=msgs->Length-1;}}
			tlMessages->SetFocusedNode(tlMessages->FindNodeByID(ni));
			tlMessages->EndUpdate();
			ShowMessagesFlag=true;
			if ((ni>=0)&&(tlMessages->FocusedNode))
			{
				msgn = *dynamic_cast<word^>(tlMessages->FindNodeByID(ni)->GetValue(0));
				ShowMessage();
			}
			else
			{
				ShowFreeMessage();
			}
		}
		
		public: void ShowMessage()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	ShowMessage()");
			LogHED->Flush();

			XMSG xmsg;
			if (MsgLock(harea)!=0){return;}
			HMSG hmsg = MsgOpenMsg(harea,MOPEN_RW,msgn);
			dword txtLen = MsgGetTextLen(hmsg);
			dword ctrlLen = MsgGetCtrlLen(hmsg);
			char* txt = new char[txtLen+1];
			char* ctrl = new char[ctrlLen+1];
			MsgReadMsg(hmsg, &xmsg, 0L, txtLen, (byte*)txt, ctrlLen, (byte*)ctrl);
			if ((xmsg.attr & MSGREAD)==0 && (xmsg.attr & MSGLOCAL)==0)
			{
				xmsg.attr|=MSGREAD;
				tlMessages->FocusedNode->StateImageIndex=1;
				word NotRead =*dynamic_cast<word^>(tlAreas->FocusedNode->GetValue(2));
				tlAreas->FocusedNode->SetValue(2,--NotRead);
				sNotRead->Caption=NotRead.ToString();
				MsgWriteMsg(hmsg, 0, &xmsg, nullptr, 0, 0, 0, nullptr);
			}
			MsgCloseMsg(hmsg);
			if (MsgUnlock(harea)!=0){return;}
			txt[txtLen]=0;
			ctrl[ctrlLen]=0;
			System::Text::Encoding^ ew = System::Text::Encoding::Default;
			System::Text::Encoding^ ed = System::Text::Encoding::GetEncoding(frmSettings->MessagesEncoding);
			attributes = Utils::AttrToString(xmsg.attr);
			oname = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)xmsg.from)));
			dname = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)xmsg.to)));
			oaddr = Utils::NETADDRToString(xmsg.orig);
			daddr = Utils::NETADDRToString(xmsg.dest);
			subject = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)xmsg.subj)));
			odatetime = Utils::_stampToDateTime(xmsg.date_written);
			ddatetime = Utils::_stampToDateTime(xmsg.date_arrived);
			text = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)txt)))->TrimEnd('\r')->Replace("\r","\n");;
			hteomkludges->Clear();
			Regex^ re = gcnew Regex(L"^(SEEN\\-BY|PATH|Via)([:\\s].*?)$",RegexOptions::Multiline);
			MatchCollection^ mc = re->Matches(text);
			int q=0;
			int pos=text->Length;
			for(int i=0;i<mc->Count;i++)
			{
				text=string::Concat(text->Substring(0,mc[i]->Index+q - (mc[i]->Index > 0 ? 1 : 0)),
					text->Substring(mc[i]->Index+q+mc[i]->Length));
				if (!hteomkludges->ContainsKey(mc[i]->Groups[1]->Value))
				hteomkludges->Add(mc[i]->Groups[1]->Value,
					mc[i]->Groups[2]->Value);
				q=text->Length-pos;
			}
			string^ fghimsgid=L"";
			string^ kludges = ed->GetString(ew->GetBytes(gcnew string((LPCSTR)CvtCtrlToKludge((byte*)ctrl))));
			htkludges->Clear();
			array<string^> ^strs = kludges->Split(((string^)L"\r\n")->ToCharArray());
			for(int i=0;i<strs->Length;i++)if (strs[i]!="")
			{
				string^ key;
				string^ val;
				int ind = strs[i]->IndexOf(L":");
				if (ind!=-1){ind = strs[i]->IndexOf(L" ");}
				if (ind!=-1)
				{
					key = strs[i]->Substring(0,ind-1);
					val = strs[i]->Substring(ind-1);
				}
				else
				{
					key = strs[i];
					val = L"";
				}
				if (!htkludges->ContainsKey(key))
				htkludges->Add(key,val);
				if (key->Equals("MSGID")){fghimsgid=val->Substring(2)->Trim();}
			}

			delete txt;
			delete ctrl;
			text=text->Replace(L"",L"☺");
			tlMessages->FocusedNode->SetValue(2,attributes);
			tlMessages->FocusedNode->SetValue(3,oname);
			tlMessages->FocusedNode->SetValue(4,dname);
			tlMessages->FocusedNode->SetValue(5,subject);
//			tlMessages->FocusedNode->SetValue(6,odatetime);
//			tlMessages->FocusedNode->SetValue(7,ddatetime);
			msgs[msgn-1]->Attributes=attributes;
			msgs[msgn-1]->OName=oname;
			msgs[msgn-1]->DName=dname;
			msgs[msgn-1]->Subject=subject;
			msgs[msgn-1]->ODateTime=odatetime;
			msgs[msgn-1]->DDateTime=ddatetime;

			ShowMessageHeader();
			ShowMessageText();

			string^ url = string::Concat(L"area://",(string^)tlAreas->FocusedNode->GetValue(0),
				L"/?msgid=",Utils::URLEncode(fghimsgid)->ToLower());
			if (FilterFromEnabled)
			{url = string::Concat(url,L"&from=",Utils::URLEncode(FilterFrom));}
			if (FilterToEnabled)
			{url = string::Concat(url,L"&to=",Utils::URLEncode(FilterTo));}
			if (FilterSubjectEnabled)
			{url = string::Concat(url,L"&subject=",Utils::URLEncode(FilterSubject));}
			if (FilterDateTimeEnabled)
			{url = string::Concat(url,L"&time=");}

			beURL->EditValue = url; 
			if (!rcbeURL->Items->Contains(url)){rcbeURL->Items->Add(url);}
			if (HistoryFlag)
			{
				HistoryFlag=false;
				TreeListNode^ node = tlHistory->AppendNode(gcnew array<object^>(2){url,System::DateTime::Now},-1);
				tlHistory->SetFocusedNode(node);
			}
		}

		public: void ShowMessageHeader()
		{
		//	LogHED->Write((System::Environment::TickCount-StartTick).ToString());
		//	LogHED->WriteLine(L"	ShowMessageHeader()");
		//	LogHED->Flush();

			string^ fn = Utils::CompleteAddr(oaddr)->
				Replace(L":",L".")->
				Replace(L"/",L".");
			if (File::Exists(string::Concat(HellEdDir, L"\\users\\",fn, L".jpg")))
			{peFrom->Image = Image::FromFile(string::Concat(HellEdDir, L"\\users\\",fn, L".jpg"));}
			else {peFrom->Image = Image::FromFile(string::Concat(HellEdDir, L"\\users\\0.0.0.0.jpg"));}
			
			teFrom->Text=string::Concat(oname, L" [", oaddr ,L"]");
			if (daddr->Equals(L""))
			{teTo->Text=dname;}
			else {teTo->Text=string::Concat(dname, L" [", daddr ,L"]");}
			teSubject->Text=subject;
			teWritten->Text=odatetime.ToString();
			teReceived->Text=ddatetime.ToString();
			teAttributes->Text=attributes;
			sN->Caption = msgn.ToString();
		}

		public: string^ GetFullText()
		{
			if (lShowKludgesMode->ItemIndex==0){return text;}
			else if (lShowKludgesMode->ItemIndex==1)
			{
				StringBuilder^ sb = gcnew StringBuilder(L"");
				IDictionaryEnumerator^ i = htkludges->GetEnumerator();
				string^ known_kludge = (string^)frmSettings->tlConfigHED->FindNodeByKeyID(801)->GetValue(1);
				array<string^> ^ strs = known_kludge->Split(((string^)L"\r\n")->ToCharArray());
				while(i->MoveNext())
				for(int j=0;j<strs->Length;j++)
				if (i->Key->Equals(strs[j]))
				{
					sb->Append(((string^)i->Key)->Replace(L"",L"☺"));
					sb->AppendLine((string^)i->Value);
				}
				sb->AppendLine(text);
				i = hteomkludges->GetEnumerator();
				while(i->MoveNext())
				for(int j=0;j<strs->Length;j++)
				if (i->Key->Equals(strs[j]))
				{
					sb->Append(((string^)i->Key)->Replace(L"",L"☺"));
					sb->AppendLine((string^)i->Value);
				}
				return sb->ToString()->TrimEnd();
			}
			else
			{
				StringBuilder^ sb = gcnew StringBuilder(L"");
				IDictionaryEnumerator^ i = htkludges->GetEnumerator();
				while(i->MoveNext())
				{
					sb->Append(((string^)i->Key)->Replace(L"",L"☺"));
					sb->Append((string^)i->Value);
					sb->Append("\n");
				}
				sb->Append(text);
				sb->Append("\n");
				i = hteomkludges->GetEnumerator();
				while(i->MoveNext())
				{
					sb->Append(((string^)i->Key)->Replace(L"",L"☺"));
					sb->Append((string^)i->Value);
					sb->Append("\n");
				}
				return sb->ToString();
			}
		}

		public: void ShowMessageText() 
		{
			html = GetFullText();
			html = Utils::ProcessFTN(html,HellEdDir,lShowKludgesMode->ItemIndex!=0,bDecryptROT13->Down,bUseStyles->Down);
			if (bUseStyles->Down)
			for(int i=0;i<ConfigSmiles->Rows->Length;i++)
			{
				html=html->Replace(((string^)((array<string^> ^)ConfigSmiles->Rows[i])->GetValue(0))->
				Replace("&","&amp;")-> 
				Replace("\"","&quot;")-> 
				Replace("'","&#039")-> 
				Replace("<","&lt;")-> 
				Replace(">","&gt;"),
				string::Concat(L"<img src=\"file://localhost/",(gcnew Uri(HellEdDir))->AbsolutePath,L"/skins/",
				(string^)frmSettings->tlConfigHED->FindNodeByKeyID(501)->GetValue(1),L"/smiles/",
				((array<string^> ^)ConfigSmiles->Rows[i])->GetValue(1),L"\">"));
			}
			StreamReader^ sr = gcnew StreamReader(string::Concat(HellEdDir,L"\\skins\\",(string^)frmSettings->tlConfigHED->FindNodeByKeyID(501)->GetValue(1),L"\\message.css"),System::Text::Encoding::UTF8);
			string^ style = sr->ReadToEnd();
			sr->Close();
			html = string::Concat(L"<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.01 Transitional//EN\"><html><head><meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"><style>",style,"</style></head>\n<body>",html,L"</body></html>");
			rtText->DocumentText=html;
		}

		public: void ShowFreeMessage()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	ShowFreeMessage()");
			LogHED->Flush();

			rtText->Navigate(gcnew string(L"about:blank"));
			frmSettings->wbTemp->Navigate(gcnew string(L"about:blank"));
			sArea->Caption = L"";
			sN->Caption = L"";
			sCount->Caption = L"";
			sNotRead->Caption = L"";
			msgn=0;
			text = L"";
			html = L"";
			oname = L"";
			dname = L"";
			oaddr = L"";
			daddr = L"";
			subject = L"";
			htkludges->Clear();
			hteomkludges->Clear();
			peFrom->Image = Image::FromFile(string::Concat(HellEdDir, L"\\users\\0.0.0.0.jpg"));
			teFrom->Text=L"";
			teTo->Text=L"";
			teSubject->Text=L"";
			teWritten->Text=L"";
			teReceived->Text=L"";
			teAttributes->Text=L"";
		}
//
// Загрузка и сохранение
//
		public: void LoadConfigFilter(string^ Name)
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(string::Concat(L"	LoadConfigFilter(L\"",Name,"\")"));
			LogHED->Flush();
			if (Name->Equals(L""))
			{ConfigFilter = gcnew Config();}
			else 
			{
				ConfigFilter->Load(string::Concat(HellEdDir,L"\\filters\\",Name,L".cfg"),true,65001);
				while(ConfigFilter->LoadRow());
			
			}
			ShowMessagesFlag=false;
			tlMessages->FilterNodes();
			ShowMessagesFlag=true;
		}

		public: void LoadConfigSkin(string^ Name)
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(string::Concat(L"	LoadConfigSkin(L\"",Name,"\")"));
			LogHED->Flush();
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
			for(int i=0;i<frmSettings->barManager->Items->Count;i++)
			{
				if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\small\\",frmSettings->barManager->Items[i]->Name,L".png")))
				{frmSettings->barManager->Items[i]->Glyph = (System::Drawing::Bitmap^)Image::FromFile(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\small\\",frmSettings->barManager->Items[i]->Name, L".png"));}
				else {frmSettings->barManager->Items[i]->Glyph = nullptr;}
				if (frmSettings->barManager->Items[i]->GetType()->ToString()->Equals(
					L"DevExpress.XtraBars.BarLargeButtonItem"))
				if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\large\\",frmSettings->barManager->Items[i]->Name,L".png")))
				{((DevExpress::XtraBars::BarLargeButtonItem^)frmSettings->barManager->Items[i])->LargeGlyph = (System::Drawing::Bitmap^)Image::FromFile(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\large\\",frmSettings->barManager->Items[i]->Name, L".png"));}
				else {((DevExpress::XtraBars::BarLargeButtonItem^)frmSettings->barManager->Items[i])->LargeGlyph = nullptr;}
			}

			iltlMessages->Images->Clear();
			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\messages\\unread.png")))
				{iltlMessages->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\messages\\unread.png")));}
			else {iltlMessages->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\default\\messages\\unread.png")));}
			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\messages\\read.png")))
				{iltlMessages->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\messages\\read.png")));}
			else {iltlMessages->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\default\\messages\\read.png")));}

			iltlAreas->Images->Clear();
			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\areas\\group.png")))
				{iltlAreas->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\areas\\group.png")));}
			else {iltlAreas->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\default\\areas\\group.png")));}
			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\areas\\area.png")))
				{iltlAreas->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\areas\\area.png")));}
			else {iltlAreas->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\default\\areas\\area.png")));}
			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\areas\\searchgroup.png")))
				{iltlAreas->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\areas\\searchgroup.png")));}
			else {iltlAreas->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\default\\areas\\searchgroup.png")));}

			iltlHistory->Images->Clear();
			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\messages\\read.png")))
				{iltlHistory->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\messages\\read.png")));}
			else {iltlHistory->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\default\\messages\\read.png")));}
			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\areas\\area.png")))
				{iltlHistory->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\areas\\area.png")));}
			else {iltlHistory->Images->Add(Image::FromFile(string::Concat(HellEdDir,L"\\skins\\default\\areas\\area.png")));}

			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\tlAreas.xml")))
			{tlAreas->Appearance->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\tlAreas.xml"));}
			else {tlAreas->Appearance->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\skins\\default\\tlAreas.xml"));}
 			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\tlHistory.xml")))
			{tlHistory->Appearance->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\tlHistory.xml"));}
			else {tlHistory->Appearance->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\skins\\default\\tlHistory.xml"));}
			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\tlMessages.xml")))
			{tlMessages->Appearance->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\tlMessages.xml"));}
			else {tlMessages->Appearance->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\skins\\default\\tlMessages.xml"));}

			if (File::Exists(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\frmSplash.jpg")))
				{frmSplash->BackgroundImage = (System::Drawing::Bitmap^)Image::FromFile(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\frmSplash.jpg"));}
			else {frmSplash->BackgroundImage = nullptr;}

			ConfigSmiles->Load(string::Concat(HellEdDir,L"\\skins\\",Name,L"\\smiles.cfg"),true,65001);
			while(ConfigSmiles->LoadRow());
			ConfigSmiles->EndLoad();
			
			barManager->GetController()->PaintStyleName = L"Skin";
			DevExpress::LookAndFeel::UserLookAndFeel::Default->SetSkinStyle(Name); 
		}
		public: void InitializehtLanguage()
		{
			bl = gcnew BarLoc();
			ll = gcnew LayoutLoc();
			tll = gcnew TreeListLoc();
			el = gcnew EditorLoc();
			scl = gcnew SpellCheckerLoc();
			
			htStrings = gcnew Hashtable();
			htStrings->Add(L"Area",L"");
			htStrings->Add(L"MessageLength",L"");
			htStrings->Add(L"Scanning",L"");
			htStrings->Add(L"LoadingSpell",L"");
			htStrings->Add(L"Subscribe",L"");
			htStrings->Add(L"SubscribeText",L"");
			htStrings->Add(L"EnterAreaName",L"");
			htStrings->Add(L"Filter",L"");
			htStrings->Add(L"EnterName",L"");
			htStrings->Add(L"CheckingForUpdates",L"");
			htStrings->Add(L"CheckForUpdatesTextBegin",L"");
			htStrings->Add(L"CheckForUpdatesTextEnd",L"");
			htStrings->Add(L"NoUpdates",L"");
			htStrings->Add(L"NewMessages",L"");

			htLanguage = gcnew Hashtable();
			for(int i=0;i<lcgMain->Items->Count;i++)
			htLanguage->Add(string::Concat(L"frmMain.",lcgMain->Items[i]->Name),lcgMain->Items[i]);
			for(int i=0;i<barManager->Items->Count;i++)
			{htLanguage->Add(string::Concat(L"frmMain.",barManager->Items[i]->Name),barManager->Items[i]);}
			for(int i=0;i<tlAreas->Columns->Count;i++)
			{htLanguage->Add(string::Concat(L"frmMain.",tlAreas->Columns[i]->Name),tlAreas->Columns[i]);}
			for(int i=0;i<tlMessages->Columns->Count;i++)
			{htLanguage->Add(string::Concat(L"frmMain.",tlMessages->Columns[i]->Name),tlMessages->Columns[i]);}
			for(int i=0;i<tlHistory->Columns->Count;i++)
			{htLanguage->Add(string::Concat(L"frmMain.",tlHistory->Columns[i]->Name),tlHistory->Columns[i]);}
			for(int i=0;i<barManager->Bars->Count;i++)
			{htLanguage->Add(string::Concat(L"frmMain.",barManager->Bars[i]->BarName),barManager->Bars[i]);}
			for(int i=0;i<dockManager->Panels->Count;i++)
			{htLanguage->Add(string::Concat(L"frmMain.",dockManager->Panels[i]->Name),dockManager->Panels[i]);}
			for(int i=0;i<panelContainer->Controls->Count;i++)
			{htLanguage->Add(string::Concat(L"frmMain.",panelContainer->Controls[i]->Name),panelContainer->Controls[i]);}
			
			htLanguage->Add(L"frmSettings",frmSettings);
			for(int i=0;i<frmSettings->Controls->Count;i++)
			if (!htLanguage->Contains(string::Concat(L"frmSettings.",frmSettings->Controls[i]->Name)))
			{htLanguage->Add(string::Concat(L"frmSettings.",frmSettings->Controls[i]->Name),frmSettings->Controls[i]);}
			for(int i=0;i<frmSettings->barManager->Items->Count;i++)
			{htLanguage->Add(string::Concat(L"frmSettings.",frmSettings->barManager->Items[i]->Name),frmSettings->barManager->Items[i]);}

			for(int i=0;i<frmSettings->tpFilters->Controls->Count;i++)
			if (!htLanguage->Contains(string::Concat(L"frmSettings.",frmSettings->tpFilters->Controls[i]->Name)))
			{htLanguage->Add(string::Concat(L"frmSettings.",frmSettings->tpFilters->Controls[i]->Name),frmSettings->tpFilters->Controls[i]);}

			for(int i=0;i<frmSettings->tlFilter->Columns->Count;i++)
			{htLanguage->Add(string::Concat(L"frmSettings.",frmSettings->tlFilter->Columns[i]->Name),frmSettings->tlFilter->Columns[i]);}

			for(int i=0;i<frmSettings->tabControl->TabPages->Count;i++)
			{htLanguage->Add(string::Concat(L"frmSettings.",frmSettings->tabControl->TabPages[i]->Name),frmSettings->tabControl->TabPages[i]);}
			for(int i=0;i<frmSettings->tlConfigHED->Columns->Count;i++)
			{htLanguage->Add(string::Concat(L"frmSettings.",frmSettings->tlConfigHED->Columns[i]->Name),frmSettings->tlConfigHED->Columns[i]);}
			for(int i=0;i<frmSettings->tlConfigHED->AllNodesCount;i++)
			{
				int keyid = *dynamic_cast<int^>(frmSettings->tlConfigHED->FindNodeByID(i)->GetValue(2));
				htLanguage->Add(string::Concat(L"frmSettings.tlConfigHED.FindNodeByKeyID(",keyid.ToString(),")"),frmSettings->tlConfigHED->FindNodeByID(i));
			}
			
			htLanguage->Add(L"frmAbout",frmAbout);				
			htLanguage->Add(L"frmAbout.lblVersionBegin",frmAbout->lblVersionBegin);				
			htLanguage->Add(L"frmAbout.lblAuthorBegin",frmAbout->lblAuthorBegin);				
			htLanguage->Add(L"frmAbout.lblSMAPIBegin",frmAbout->lblSMAPIBegin);				
			htLanguage->Add(L"frmAbout.btnOk",frmAbout->btnOk);				
			htLanguage->Add(L"frmAbout.lnkLicense",frmAbout->lnkLicense);		
			
			htLanguage->Add(L"InputBox.btnOk",InputBox->btnOk);
		}
		
		public: void LoadConfigLanguage(string^ Name)
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(string::Concat(L"	LoadConfigLanguage(L\"",Name,"\")"));
			LogHED->Flush();

			int area_select_mode = frmSettings->rcbearea_select_mode->Items->IndexOf(frmSettings->tlConfigHED->FindNodeByKeyID(1001)->GetValue(1));
			int popup_location = frmSettings->rcbepopup_location->Items->IndexOf(frmSettings->tlConfigHED->FindNodeByKeyID(1104)->GetValue(1));

			frmSettings->ConfigLanguage->Load(string::Concat(HellEdDir,L"\\languages\\",Name,L".cfg"),true,65001);
			while(frmSettings->ConfigLanguage->LoadRow())
			if (frmSettings->ConfigLanguage->CurRow->Length>1)
			{
				if (htLanguage[frmSettings->ConfigLanguage->CurRow[0]])
				{Utils::SetValueLanguage(htLanguage[frmSettings->ConfigLanguage->CurRow[0]],frmSettings->ConfigLanguage->CurRow[1]);}
				else if (el->htStrings[frmSettings->ConfigLanguage->CurRow[0]])
				{el->htStrings[frmSettings->ConfigLanguage->CurRow[0]]=frmSettings->ConfigLanguage->CurRow[1];}
				else if (ll->htStrings[frmSettings->ConfigLanguage->CurRow[0]])
				{ll->htStrings[frmSettings->ConfigLanguage->CurRow[0]]=frmSettings->ConfigLanguage->CurRow[1];}
				else if (bl->htStrings[frmSettings->ConfigLanguage->CurRow[0]])
				{bl->htStrings[frmSettings->ConfigLanguage->CurRow[0]]=frmSettings->ConfigLanguage->CurRow[1];}
				else if (tll->htStrings[frmSettings->ConfigLanguage->CurRow[0]])
				{tll->htStrings[frmSettings->ConfigLanguage->CurRow[0]]=frmSettings->ConfigLanguage->CurRow[1];}
				else if (scl->htStrings[frmSettings->ConfigLanguage->CurRow[0]])
				{scl->htStrings[frmSettings->ConfigLanguage->CurRow[0]]=frmSettings->ConfigLanguage->CurRow[1];}
				else if (htStrings[frmSettings->ConfigLanguage->CurRow[0]])
				{htStrings[frmSettings->ConfigLanguage->CurRow[0]]=frmSettings->ConfigLanguage->CurRow[1];}

				else if (frmSettings->ConfigLanguage->CurRow[0]->Equals(L"First"))
				{frmSettings->rcbearea_select_mode->Items[0]=frmSettings->ConfigLanguage->CurRow[1];}
				else if (frmSettings->ConfigLanguage->CurRow[0]->Equals(L"FirstUnread"))
				{frmSettings->rcbearea_select_mode->Items[1]=frmSettings->ConfigLanguage->CurRow[1];}
				else if (frmSettings->ConfigLanguage->CurRow[0]->Equals(L"LastShowed"))
				{frmSettings->rcbearea_select_mode->Items[2]=frmSettings->ConfigLanguage->CurRow[1];}
				else if (frmSettings->ConfigLanguage->CurRow[0]->Equals(L"Assigned"))
				{frmSettings->rcbearea_select_mode->Items[3]=frmSettings->ConfigLanguage->CurRow[1];}

				else if (frmSettings->ConfigLanguage->CurRow[0]->Equals(L"LeftTopCorner"))
				{frmSettings->rcbepopup_location->Items[0]=frmSettings->ConfigLanguage->CurRow[1];}
				else if (frmSettings->ConfigLanguage->CurRow[0]->Equals(L"LeftBottomCorner"))
				{frmSettings->rcbepopup_location->Items[1]=frmSettings->ConfigLanguage->CurRow[1];}
				else if (frmSettings->ConfigLanguage->CurRow[0]->Equals(L"RightTopCorner"))
				{frmSettings->rcbepopup_location->Items[2]=frmSettings->ConfigLanguage->CurRow[1];}
				else if (frmSettings->ConfigLanguage->CurRow[0]->Equals(L"RightBottomCorner"))
				{frmSettings->rcbepopup_location->Items[3]=frmSettings->ConfigLanguage->CurRow[1];}

				else if (frmSettings->ConfigLanguage->CurRow[0]->Equals(L"Hide"))
				{lShowKludgesMode->Strings[0]=frmSettings->ConfigLanguage->CurRow[1];}
				else if (frmSettings->ConfigLanguage->CurRow[0]->Equals(L"ShowKnown"))
				{lShowKludgesMode->Strings[1]=frmSettings->ConfigLanguage->CurRow[1];}
				else if (frmSettings->ConfigLanguage->CurRow[0]->Equals(L"ShowAll"))
				{lShowKludgesMode->Strings[2]=frmSettings->ConfigLanguage->CurRow[1];}
				
				else if (frmSettings->ConfigLanguage->CurRow[0]->Equals(L"SearchFolders"))
				{
					tlAreas->FindNodeByID(si)->SetValue(0,frmSettings->ConfigLanguage->CurRow[1]);
					tlAreas->FindNodeByID(si)->SetValue(3,frmSettings->ConfigLanguage->CurRow[1]);
				}
			}
			frmSettings->tlConfigHED->FindNodeByKeyID(1001)->SetValue(1,frmSettings->rcbearea_select_mode->Items[area_select_mode]);
			frmSettings->tlConfigHED->FindNodeByKeyID(1104)->SetValue(1,frmSettings->rcbepopup_location->Items[popup_location]);
			frmSettings->ConfigLanguage->EndLoad();
			DevExpress::XtraLayout::Localization::LayoutLocalizer::Active = ll;
			DevExpress::XtraLayout::Localization::LayoutResLocalizer::Active = ll;
			DevExpress::XtraBars::Localization::BarLocalizer::Active = bl;
			DevExpress::XtraBars::Localization::BarResLocalizer::Active = bl;
			DevExpress::XtraTreeList::Localization::TreeListLocalizer::Active = tll;
			DevExpress::XtraTreeList::Localization::TreeListResLocalizer::Active = tll;
			DevExpress::XtraSpellChecker::Localization::SpellCheckerLocalizer::Active = scl;
			DevExpress::XtraSpellChecker::Localization::SpellCheckerResLocalizer::Active = scl;
			DevExpress::XtraEditors::Controls::Localizer::Active = el;

			string^ st=L"en";
			if (Name->Equals(L"English")){st=L"en";}
			else if (Name->Equals(L"Russian")){st=L"ru";}
			spell->Culture = (gcnew System::Globalization::CultureInfo(st));
		}
		public: void LoadConfigTosser()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	LoadConfigTosser()");
			LogHED->Flush();
			LoadConfigTosserFlag=false;
			tlMessages->ClearNodes();
			ShowFreeMessage();

			if (harea)
			{
				MsgCloseArea(harea);
				harea=nullptr;
			}

			tlAreas->ClearNodes();
			tlAreas->BeginUnboundLoad();
			array<object^> ^ data = gcnew array<object^>(9);
			data[0]=L"Папки поиска";
			data[1]=L"";
			data[2]=L"";
			data[3]=L"Папки поиска";
			data[4]=L"";
			data[5]=L"";
			data[6]=L"";
			data[7]=L"";
			data[8]=L"s";
			TreeListNode^ node = tlAreas->AppendNode(data, -1);
			node->StateImageIndex=2;
			si=node->Id;

			ConfigAreas->Load(string::Concat(HellEdDir, L"\\areas.cfg"),false,65001);
			array<string^,2> ^ areas = gcnew array<string^,2>(1000,2);
			int count=0;
			while(ConfigAreas->LoadRow())
			{
				if(((string^)ConfigAreas->CurRow[0])->ToLower()->Equals(L"group"))
				{
					array<object^> ^ data = gcnew array<object^>(9);
					data[0]=ConfigAreas->CurRow[2];
					data[1]=L"";
					data[2]=L"";
					data[3]=ConfigAreas->CurRow[2];
					data[4]=L"";
					data[5]=L"";
					data[6]=L"";
					data[7]=L"";
					data[8]=L"g";
					TreeListNode^ node = tlAreas->AppendNode(data, -1);
					node->StateImageIndex = 0;
				}
				if(((string^)ConfigAreas->CurRow[0])->ToLower()->Equals(L"area"))
				{
					areas[count,0] = (string^)ConfigAreas->CurRow[1];
					areas[count,1] = (string^)ConfigAreas->CurRow[2];
					count++;
				}
			}
			System::Text::Encoding^ ew = System::Text::Encoding::Default;
			System::Text::Encoding^ ed = System::Text::Encoding::GetEncoding(frmSettings->MessagesEncoding);
			ani=-1;
			if (File::Exists((string^)frmSettings->tlConfigHED->FindNodeByKeyID(202)->GetValue(1)))
			{
				bool flag=true;
				int area_select_mode = frmSettings->rcbearea_select_mode->Items->IndexOf(frmSettings->tlConfigHED->FindNodeByKeyID(1001)->GetValue(1));
				string^ Tosser=((string^)frmSettings->tlConfigHED->FindNodeByKeyID(201)->GetValue(1))->ToLower();
				ConfigTosser->Load((string^)frmSettings->tlConfigHED->FindNodeByKeyID(202)->GetValue(1),false,frmSettings->ConfigEncoding);
				while(ConfigTosser->LoadRow())
				{
					array<object^> ^ data;
					bool add = false;
					if (Tosser->Equals(L"hpt"))
					{
						string^ areatype = ConfigTosser->CurRow[0]->ToLower();
						if ((ConfigTosser->CurRow->Length>=3)&&(
							(areatype->Equals(L"netmailarea"))||	
							(areatype->Equals(L"localarea"))||	
							(areatype->Equals(L"dupearea"))||	
							(areatype->Equals(L"badarea"))||	
							(areatype->Equals(L"echoarea"))))	
						{
							data = gcnew array<object^>(9);
							data[0]=ConfigTosser->CurRow[1];	
							data[1]=L"";
							data[2]=L"";
							data[3]=ConfigTosser->CurRow[1];
							data[4]=ConfigTosser->CurRow[2];
							if (ConfigTosser->CurRow[2]->ToLower()->Equals(L"passthrough"))
							{add=false;}
							else {add=true;}
							data[5]=L"";
							data[6]=L"Squish";
							data[7]=areatype;
							data[8]=L"";
							for(int j=1;j<ConfigTosser->CurRow->Length;j++)
							{
								if (j<ConfigTosser->CurRow->Length-1)
								{
									if (ConfigTosser->CurRow[j]->Equals(L"-a")){data[5]=ConfigTosser->CurRow[j+1];}
									else if (ConfigTosser->CurRow[j]->Equals(L"-b")){data[6]=ConfigTosser->CurRow[j+1];}
									else if (ConfigTosser->CurRow[j]->Equals(L"-d")){data[3]=ConfigTosser->CurRow[j+1];}
								}
							}
						}
					}
					else if (Tosser->Equals(L"partoss"))
					{
						string^ areatype = ConfigTosser->CurRow[0]->ToLower();
						if ((ConfigTosser->CurRow->Length>=3)&&(
							(areatype->Equals(L"netarea"))||	
							(areatype->Equals(L"localarea"))||	
							(areatype->Equals(L"dupearea"))||	
							(areatype->Equals(L"badarea"))||	
							(areatype->Equals(L"echoarea"))))	
						{
							add=true;
							data = gcnew array<object^>(9);
							data[0]=ConfigTosser->CurRow[1];	
							data[1]=L"";
							data[2]=L"";
							data[3]=ConfigTosser->CurRow[1];	
							data[4]=ConfigTosser->CurRow[2];
							data[5]=L"";
							if (areatype->Equals(L"netarea")){data[6]=L"Msg";}
							else {data[6]=L"Squish";}
							if (areatype->Equals(L"netarea")){data[7]="netmailarea";}
							else {data[7]=areatype;}
							data[8]=L"";
							for(int j=1;j<ConfigTosser->CurRow->Length;j++)
							{
								if (ConfigTosser->CurRow[j]->StartsWith(L"-p"))
								{
									if (j+1<ConfigTosser->CurRow->Length)
									data[5]=ConfigTosser->CurRow[j+1]->Substring(2);
								}
								else if (ConfigTosser->CurRow[j]->Equals(L"-$n"))
								{
									if (j+1<ConfigTosser->CurRow->Length)
									data[3]=ConfigTosser->CurRow[j+1]->Substring(3)->Trim(((string^)L"\"")->ToCharArray())->Replace("\\\"","\"");
								}
								else if (ConfigTosser->CurRow[j]->ToLower()->Equals(L"-0")){add=false;}
							}
						}
					}
					else if (Tosser->Equals(L"bb-toss"))
					{
						string^ st = L"";
						for(int j=0;j<ConfigTosser->CurRow->Length;j++)
						{st=string::Concat(st, (j==0) ? L"" : L" ", ConfigTosser->CurRow[j]);}
						if (st->StartsWith(L"["))
						{
							data = gcnew array<object^>(9);
							data[0]=st->Substring(1,st->Length-2);
							data[1]=L"";
							data[2]=L"";
							data[3]=st->Substring(1,st->Length-2);
							data[4]=L"";
							data[5]=L"";
							data[6]=L"";
							data[7]=L"";
							data[8]=L"";
						}
						else if (st->StartsWith(L"Path="))
						{data[4]=st->Substring(((string^)L"Path=")->Length);}
						else if (st->StartsWith(L"Typ="))
						{
							if (st->Substring(((string^)L"Typ=")->Length)->Equals(L"E")){data[7]=L"echoarea";}
							else if (st->Substring(((string^)L"Typ=")->Length)->Equals(L"N")){data[7]=L"netmailarea";}
							else if (st->Substring(((string^)L"Typ=")->Length)->Equals(L"L")){data[7]=L"localarea";}
							else if (st->Substring(((string^)L"Typ=")->Length)->Equals(L"B")){data[7]=L"badarea";}
							else if (st->Substring(((string^)L"Typ=")->Length)->Equals(L"D")){data[7]=L"dupearea";}
						}
						else if (st->StartsWith(L"Basetyp="))
						{
							if (st->Substring(((string^)L"Basetyp=")->Length)->Equals(L"P")){data[6]=L"P";}
							else if (st->Substring(((string^)L"Basetyp=")->Length)->Equals(L"S")){data[6]=L"Squish";}
							else if (st->Substring(((string^)L"Basetyp=")->Length)->Equals(L"J")){data[6]=L"Jam";}
							else if (st->Substring(((string^)L"Basetyp=")->Length)->Equals(L"N")){data[6]=L"Msg";}
						}
						else if (st->StartsWith(L"Mainaka="))
						{data[5]=st->Substring(((string^)L"Mainaka=")->Length);}
						else if (st->StartsWith(L"Desc="))
						{
							data[3]=ed->GetString(ew->GetBytes(st->Substring(((string^)L"Desc=")->Length)));
							if (data[6]!=L"P"){add=true;}
						}
					}
					else if (Tosser->Equals(L"areas.bbs"))
					{
						if ((ConfigTosser->CurRow->Length>=2) &&
							!((ConfigTosser->CurRow[0]->StartsWith(L";"))||
							(ConfigTosser->CurRow[0]->StartsWith(L"P"))||
							(ConfigTosser->CurRow[0]->StartsWith(L"1"))||
							(ConfigTosser->CurRow[0]->StartsWith(L"2"))||
							(ConfigTosser->CurRow[0]->StartsWith(L"3"))||
							(ConfigTosser->CurRow[0]->StartsWith(L"4"))||
							(ConfigTosser->CurRow[0]->StartsWith(L"5"))||
							(ConfigTosser->CurRow[0]->StartsWith(L"6"))||
							(ConfigTosser->CurRow[0]->StartsWith(L"7"))||
							(ConfigTosser->CurRow[0]->StartsWith(L"8"))||
							(ConfigTosser->CurRow[0]->StartsWith(L"9"))||
							(ConfigTosser->CurRow[0]->StartsWith(L"0"))))
						{
							data = gcnew array<object^>(9);
							data[0]=ConfigTosser->CurRow[1];
							data[1]=L"";
							data[2]=L"";
							data[3]=ConfigTosser->CurRow[1];
							data[4]=L"";
							data[5]=L"";
							data[6]=L"";
							data[7]=L"";
							data[8]=L"";
							if (ConfigTosser->CurRow[0]->StartsWith(L"$"))
							{
								data[4]=ConfigTosser->CurRow[0]->Substring(1);
								data[6]=L"Squish";
							}
							else if (ConfigTosser->CurRow[0]->StartsWith(L"!"))
							{
								data[4]=ConfigTosser->CurRow[0]->Substring(1);
								data[6]=L"Jam";
							}
							else
							{
								data[4]=ConfigTosser->CurRow[0];
								data[6]=L"Msg";
							}
							add=true;
						}
					}
					if (add)
					{	
						int group=-1;
						for(int j=0;j<count;j++)
						if (areas[j,0]->Equals(data[0]))
						{group=Convert::ToInt32(areas[j,1])+1;}
						TreeListNode^ node = tlAreas->AppendNode(data, group);
						node->StateImageIndex = 1;
						if (frmSettings->tlConfigHED->FindNodeByKeyID(206)->GetValue(1)->ToString()->Equals(L"True"))
						{
							frmSplash->lblMessage->Text=string::Concat(htStrings[L"Scanning"],((string^)node->GetValue(0))->Replace(L"&",L"&&"));
							frmSplash->lblMessage->Refresh();

							string^ Path = (string^)node->GetValue(4);
							string^ Address = (string^)node->GetValue(5);
							string^ BaseType = ((string^)node->GetValue(6))->ToLower();
							word type;
							if (BaseType->Equals("msg")){type=MSGTYPE_SDM;}
							if (BaseType->Equals("squish")){type=MSGTYPE_SQUISH;}
							if (BaseType->Equals("jam")){type=MSGTYPE_JAM;}
	
							char* mas = (char*)(void*)Marshal::StringToHGlobalAnsi(Path);
							harea = MsgOpenArea((byte*)mas, MSGAREA_CRIFNEC, type);
							Marshal::FreeHGlobal((System::IntPtr)mas);
							if (harea==nullptr){return;}
							word count=MsgNumMsg(harea);

							word NotRead=0;
							int newcount=0;
							for(int i=0;i<count;i++)
							{
								XMSG xmsg;
								HMSG hmsg = MsgOpenMsg(harea,MOPEN_READ,i+1);
								if (hmsg)
								{
									MsgReadMsg(hmsg, &xmsg, 0, 0, nullptr, 0, nullptr);
									MsgCloseMsg(hmsg);
									if ((xmsg.attr & MSGREAD)==0 & (xmsg.attr & MSGLOCAL)==0)
									{NotRead++;}
								}
								else {newcount++;}
							}
							if (newcount>0){count-=newcount;}
							node->SetValue(1,count);
							node->SetValue(2,NotRead);
							MsgCloseArea(harea);
							harea=nullptr;

							if ((flag)&&(NotRead>0))
							if (area_select_mode==1)
							{
								ani=node->Id;
								flag=false;
							}
						}
						else
						{
							node->SetValue(1,0);
							node->SetValue(2,0);
						}
						if ((area_select_mode==2)||
							(area_select_mode==3))
						if (frmSettings->tlConfigHED->FindNodeByKeyID(1002)->GetValue(1)->ToString()->Equals(data[0]))
						{
							ani=node->Id;
						}
					}
				}
			}
			tlAreas->EndUnboundLoad();
			tlAreas->ExpandAll();
			LoadConfigTosserFlag=true;
		}
		public: void LoadTemplates()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	LoadTemplates()");
			LogHED->Flush();

			lTemplate->Strings->Clear();
			array<string^> ^ templates = Directory::GetFiles(string::Concat(HellEdDir, L"\\templates"), L"*.txt");
			for(int i=0;i<templates->Length;i++)
			if (!((Path::GetFileNameWithoutExtension(templates[i])->Equals(L"new"))||
				(Path::GetFileNameWithoutExtension(templates[i])->Equals(L"edit"))||
				(Path::GetFileNameWithoutExtension(templates[i])->Equals(L"forward"))||
				(Path::GetFileNameWithoutExtension(templates[i])->Equals(L"reply"))||
				(Path::GetFileNameWithoutExtension(templates[i])->Equals(L"replyfromlocal"))||
				(Path::GetFileNameWithoutExtension(templates[i])->Equals(L"subscribe"))||
				(Path::GetFileNameWithoutExtension(templates[i])->Equals(L"unsubscribe"))))
			{lTemplate->Strings->Add(Path::GetFileNameWithoutExtension(templates[i]));}
		}

		public: void LoadSkins()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	LoadSkins()");
			LogHED->Flush();

			frmSettings->rcbeskin->Items->Clear();
			lSkin->Strings->Clear();
			array<string^> ^ skins = Directory::GetDirectories(string::Concat(HellEdDir, L"\\skins"));
			for(int i=0;i<skins->Length;i++)
			if (!(Path::GetFileNameWithoutExtension(skins[i])->Equals(L"default")))
			{
				frmSettings->rcbeskin->Items->Add(Path::GetFileNameWithoutExtension(skins[i]));
				lSkin->Strings->Add(Path::GetFileNameWithoutExtension(skins[i]));
			}
		}

		public: void LoadFilters()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	LoadFilters()");
			LogHED->Flush();

			frmSettings->rcbefilter->Items->Clear();
			lFilter->Strings->Clear();
			frmSettings->cbeFilter->Properties->Items->Clear();
			frmSettings->rcbefilter->Items->Add(L"");
			array<string^> ^ filters = Directory::GetFiles(string::Concat(HellEdDir, L"\\filters"), L"*.cfg");
			for(int i=0;i<filters->Length;i++)
			{
				frmSettings->rcbefilter->Items->Add(Path::GetFileNameWithoutExtension(filters[i]));
				frmSettings->cbeFilter->Properties->Items->Add(Path::GetFileNameWithoutExtension(filters[i]));
				lFilter->Strings->Add(Path::GetFileNameWithoutExtension(filters[i]));
			}
			frmSettings->cbeFilter->SelectedIndex=filters->Length-1;
		}

		public: void LoadLanguages()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	LoadLanguages()");
			LogHED->Flush();
			frmSettings->rcbelanguage->Items->Clear();
			lLanguage->Strings->Clear();
			array<string^> ^ languages = Directory::GetFiles(string::Concat(HellEdDir, L"\\languages"), L"*.cfg");
			string^ st=L"en";
			for(int i=0;i<languages->Length;i++)
			{
				frmSettings->rcbelanguage->Items->Add(Path::GetFileNameWithoutExtension(languages[i]));
				lLanguage->Strings->Add(Path::GetFileNameWithoutExtension(languages[i]));
				if (Path::GetFileNameWithoutExtension(languages[i])->Equals(L"English")){st=L"en";}
				else if (Path::GetFileNameWithoutExtension(languages[i])->Equals(L"Russian")){st=L"ru";}
				spell->Dictionaries->Add(gcnew SpellCheckerISpellDictionary(
				string::Concat(HellEdDir,L"\\spell\\",Path::GetFileNameWithoutExtension(languages[i]),".dic"),
				string::Concat(HellEdDir,L"\\spell\\",Path::GetFileNameWithoutExtension(languages[i]),".aff"),
				gcnew System::Globalization::CultureInfo(st)));
				spell->Dictionaries->Add(gcnew SpellCheckerCustomDictionary(
					string::Concat(HellEdDir,L"\\spell\\",Path::GetFileNameWithoutExtension(languages[i]),".cus"),
					gcnew System::Globalization::CultureInfo(st)));
			}
		}
		public: void LoadConfigHED()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	LoadConfigHED()");
			LogHED->Flush();

			LoadSkins();
			LoadLanguages();
			LoadTemplates();
			LoadFilters();

			string^ name=L"";
			string^ address=L"";
			string^ tosser_name=L"";
			string^ tosser_config_path=L"";
			string^ tosser_path=L"";
			string^ tosser_onsend=L"0";
			string^ tosser_onexit=L"0";
			string^ scanmsgbase_onstart=L"0";
			string^ echotoss_log_path=L"";
			string^ import_log_path=L"";
			string^ tosser_time=L"0";
			string^ tearline=L"";
			string^ origin=L"";
			string^ filter=L"";
			string^ skin=L"Blue";
			string^ language=L"Russian";
			string^ nodelist=L"";
			string^ known_kludge=L"";
			string^ string_length=L"79";
			string^ area_select_mode=L"0";
			string^ area_name=L"";
			string^ minimize_to_tray=L"0";
			string^ check_for_updates_onstart=L"0";
			string^ popup_time=L"10";
			string^ popup_location=L"3";
			string^ config_encoding=L"1251";
			string^ messages_encoding=L"866";
			string^ replace=L"";
			string^ files_encoding=L"1251";

			frmSettings->ConfigHED->Load(string::Concat(HellEdDir, L"\\helled.cfg"),false,65001);
			while(frmSettings->ConfigHED->LoadRow())
			if (frmSettings->ConfigHED->CurRow->Length>1)
			{
				if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"name")){name=string::Concat(name,(name->Equals(L"") ? L"" : L"\r\n"),frmSettings->ConfigHED->CurRow[1]);}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"address")){address=string::Concat(address,(address->Equals(L"") ? L"" : L"\r\n"),frmSettings->ConfigHED->CurRow[1]);}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"tosser_name")){tosser_name=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"tosser_config_path")){tosser_config_path=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"tosser_path")){tosser_path=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"tosser_onsend")){tosser_onsend=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"tosser_onexit")){tosser_onexit=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"scanmsgbase_onstart")){scanmsgbase_onstart=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"echotoss_log_path")){echotoss_log_path=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"import_log_path")){import_log_path=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"tosser_time")){tosser_time=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"tearline")){tearline=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"origin")){origin=string::Concat(origin,(origin->Equals(L"") ? L"" : L"\r\n"),frmSettings->ConfigHED->CurRow[1]);}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"filter"))
				{
					if (File::Exists(string::Concat(HellEdDir,L"\\filters\\",(string^)frmSettings->ConfigHED->CurRow[1],L".cfg")))
					filter=(string^)frmSettings->ConfigHED->CurRow[1];
				}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"skin"))
				{
					if (Directory::Exists(string::Concat(HellEdDir,L"\\skins\\",(string^)frmSettings->ConfigHED->CurRow[1])))	
					skin=(string^)frmSettings->ConfigHED->CurRow[1];
				}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"language")){language=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"nodelist")){nodelist=string::Concat(nodelist,(nodelist->Equals(L"") ? L"" : L"\r\n"),frmSettings->ConfigHED->CurRow[1]);}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"known_kludge")){known_kludge=string::Concat(known_kludge,(known_kludge->Equals(L"") ? L"" : L"\r\n"),frmSettings->ConfigHED->CurRow[1]);}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"string_length")){string_length=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"area_select_mode")){area_select_mode=(string^)frmSettings->ConfigHED->CurRow[1];}
				if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"area_name")){area_name=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"minimize_to_tray")){minimize_to_tray=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"check_for_updates_onstart")){check_for_updates_onstart=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"popup_time")){popup_time=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"popup_location")){popup_location=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"config_encoding")){config_encoding=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"messages_encoding")){messages_encoding=(string^)frmSettings->ConfigHED->CurRow[1];}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"replace")){replace=string::Concat(replace,(replace->Equals(L"") ? L"" : L"\r\n"),frmSettings->ConfigHED->CurRow[1]);}
				else if (frmSettings->ConfigHED->CurRow[0]->ToLower()->Equals(
					L"files_encoding")){files_encoding=(string^)frmSettings->ConfigHED->CurRow[1];}
			}

			frmSettings->tlConfigHED->FindNodeByKeyID(101)->SetValue(1,name);
			frmSettings->tlConfigHED->FindNodeByKeyID(102)->SetValue(1,address);
			frmSettings->tlConfigHED->FindNodeByKeyID(201)->SetValue(1,tosser_name);
			frmSettings->tlConfigHED->FindNodeByKeyID(202)->SetValue(1,tosser_config_path);
			frmSettings->tlConfigHED->FindNodeByKeyID(203)->SetValue(1,tosser_path);
			frmSettings->tlConfigHED->FindNodeByKeyID(204)->SetValue(1,!tosser_onsend->Equals(L"0"));
			frmSettings->tlConfigHED->FindNodeByKeyID(205)->SetValue(1,!tosser_onexit->Equals(L"0"));
			frmSettings->tlConfigHED->FindNodeByKeyID(206)->SetValue(1,!scanmsgbase_onstart->Equals(L"0"));
			frmSettings->tlConfigHED->FindNodeByKeyID(207)->SetValue(1,echotoss_log_path);
			frmSettings->tlConfigHED->FindNodeByKeyID(208)->SetValue(1,import_log_path);
			frmSettings->tlConfigHED->FindNodeByKeyID(209)->SetValue(1,tosser_time);
			frmSettings->tlConfigHED->FindNodeByKeyID(301)->SetValue(1,filter);
			frmSettings->tlConfigHED->FindNodeByKeyID(401)->SetValue(1,tearline);
			frmSettings->tlConfigHED->FindNodeByKeyID(402)->SetValue(1,origin);
			frmSettings->tlConfigHED->FindNodeByKeyID(501)->SetValue(1,skin);
			frmSettings->tlConfigHED->FindNodeByKeyID(601)->SetValue(1,language);
			frmSettings->tlConfigHED->FindNodeByKeyID(701)->SetValue(1,nodelist);
			frmSettings->tlConfigHED->FindNodeByKeyID(801)->SetValue(1,known_kludge);
			frmSettings->tlConfigHED->FindNodeByKeyID(901)->SetValue(1,string_length);
			if ((area_select_mode->Equals(L"0"))||
				(area_select_mode->Equals(L"1"))||
				(area_select_mode->Equals(L"2"))||
				(area_select_mode->Equals(L"3")))
			{frmSettings->tlConfigHED->FindNodeByKeyID(1001)->SetValue(1,frmSettings->rcbearea_select_mode->Items[Convert::ToInt64(area_select_mode)]);}
			else {frmSettings->tlConfigHED->FindNodeByKeyID(1001)->SetValue(1,frmSettings->rcbearea_select_mode->Items[0]);}
			frmSettings->tlConfigHED->FindNodeByKeyID(1002)->SetValue(1,area_name);
			frmSettings->tlConfigHED->FindNodeByKeyID(1101)->SetValue(1,!minimize_to_tray->Equals(L"0"));
			frmSettings->tlConfigHED->FindNodeByKeyID(1102)->SetValue(1,!check_for_updates_onstart->Equals(L"0"));
			frmSettings->tlConfigHED->FindNodeByKeyID(1103)->SetValue(1,popup_time);
			if ((popup_location->Equals(L"0"))||
				(popup_location->Equals(L"1"))||
				(popup_location->Equals(L"2"))||
				(popup_location->Equals(L"3")))
			{frmSettings->tlConfigHED->FindNodeByKeyID(1104)->SetValue(1,frmSettings->rcbepopup_location->Items[Convert::ToInt64(popup_location)]);}
			else {frmSettings->tlConfigHED->FindNodeByKeyID(1104)->SetValue(1,frmSettings->rcbepopup_location->Items[3]);}

			frmSettings->tlConfigHED->FindNodeByKeyID(1201)->SetValue(1,config_encoding);
			frmSettings->tlConfigHED->FindNodeByKeyID(1202)->SetValue(1,messages_encoding);
			frmSettings->tlConfigHED->FindNodeByKeyID(1203)->SetValue(1,replace);
			frmSettings->tlConfigHED->FindNodeByKeyID(1204)->SetValue(1,files_encoding);

			frmSettings->ConfigEncoding = Convert::ToInt64(frmSettings->tlConfigHED->FindNodeByKeyID(1201)->GetValue(1));
			frmSettings->MessagesEncoding = Convert::ToInt64(frmSettings->tlConfigHED->FindNodeByKeyID(1202)->GetValue(1));
			frmSettings->FilesEncoding = Convert::ToInt64(frmSettings->tlConfigHED->FindNodeByKeyID(1204)->GetValue(1));

			lFilter->ItemIndex=lFilter->Strings->IndexOf(filter);
			if (lFilter->ItemIndex==-1){bFilterNone->Down=true;}
			else {bFilterNone->Down=false;}
			lSkin->ItemIndex=lSkin->Strings->IndexOf(skin);
			lLanguage->ItemIndex=lLanguage->Strings->IndexOf(language);

			if (*dynamic_cast<bool^>(frmSettings->tlConfigHED->FindNodeByKeyID(1101)->GetValue(1)))
			{
				notifyicon->Visible=true;
				this->ShowInTaskbar=false;
			}
			else
			{
				notifyicon->Visible=false;
				this->ShowInTaskbar=true;
			}
			int tt=Convert::ToInt64(frmSettings->tlConfigHED->FindNodeByKeyID(209)->GetValue(1));
			if (tt>0)
			{
				LastTosserTick=System::Environment::TickCount;
				tiMain->Enabled=true;
			}
			else {tiMain->Enabled=false;}
		}

		public: void LoadConfigForms()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	LoadConfigForms()");
			LogHED->Flush();

			if (File::Exists(string::Concat(HellEdDir,L"\\bars.xml")))
				barManager->RestoreFromXml(string::Concat(HellEdDir,L"\\bars.xml"));
			if (File::Exists(string::Concat(HellEdDir,L"\\panels.xml")))
				dockManager->RestoreFromXml(string::Concat(HellEdDir,L"\\panels.xml"));
			if (File::Exists(string::Concat(HellEdDir,L"\\tlareas.xml")))
				tlAreas->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\tlareas.xml"));
			if (File::Exists(string::Concat(HellEdDir,L"\\tlhistory.xml")))
				tlHistory->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\tlhistory.xml"));
			if (File::Exists(string::Concat(HellEdDir,L"\\tlmessages.xml")))
				tlMessages->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\tlmessages.xml"));
			if (File::Exists(string::Concat(HellEdDir,L"\\frmmain.xml")))
				LayoutControl->RestoreLayoutFromXml(string::Concat(HellEdDir,L"\\frmmain.xml"));

			ConfigForms->Load(string::Concat(HellEdDir,L"\\frmmain.cfg"),false,65001);
			while(ConfigForms->LoadRow())
			if (ConfigForms->CurRow->Length>1)
			{
				if (ConfigForms->CurRow[0]->Equals(L"frmMain.Width"))
				{Width=Convert::ToInt32(ConfigForms->CurRow[1]);}
				else if (ConfigForms->CurRow[0]->Equals(L"frmMain.Height"))
				{Height=Convert::ToInt32(ConfigForms->CurRow[1]);}
				else if (ConfigForms->CurRow[0]->Equals(L"frmMain.Location.X"))
				{Location = (*dynamic_cast<Point^>(gcnew Point(Convert::ToInt32(ConfigForms->CurRow[1]),Location.Y)));}
				else if (ConfigForms->CurRow[0]->Equals(L"frmMain.Location.Y"))
				{Location = (*dynamic_cast<Point^>(gcnew Point(Location.X,Convert::ToInt32(ConfigForms->CurRow[1]))));}

				else if (ConfigForms->CurRow[0]->Equals(L"frmMain.WindowState"))
				{
					if (ConfigForms->CurRow[1]->Equals(L"Maximized"))
					{WindowState=System::Windows::Forms::FormWindowState::Maximized;}
					if (ConfigForms->CurRow[1]->Equals(L"Minimized"))
					{WindowState=System::Windows::Forms::FormWindowState::Minimized;}
					if (ConfigForms->CurRow[1]->Equals(L"Normal"))
					{WindowState=System::Windows::Forms::FormWindowState::Normal;}
				}
				else if (ConfigForms->CurRow[0]->Equals(L"frmMain.bList.Down"))
				{
					bList->Down = ConfigForms->CurRow[1]->Equals(L"1");
					bTree->Down = !ConfigForms->CurRow[1]->Equals(L"1");
				}
				else if (ConfigForms->CurRow[0]->Equals(L"frmMain.lShowKludgesMode.ItemIndex"))
				{lShowKludgesMode->ItemIndex = Convert::ToInt32(ConfigForms->CurRow[1]);}

				else if (ConfigForms->CurRow[0]->Equals(L"frmMain.bDecryptROT13.Down"))
				{this->bDecryptROT13->Down = ConfigForms->CurRow[1]->Equals(L"1");}
				else if (ConfigForms->CurRow[0]->Equals(L"frmMain.bUseStyles.Down"))
				{this->bUseStyles->Down = ConfigForms->CurRow[1]->Equals(L"1");}
			}
		}
		public: void LoadConfigHistory()
		{
			ConfigHistory->Load(string::Concat(HellEdDir,L"\\history.cfg"),false,65001);
			tlHistory->BeginUnboundLoad();
			while(ConfigHistory->LoadRow())
			if (ConfigHistory->CurRow->Length>1)
			{
				tlHistory->AppendNode(gcnew array<object^>(2)
				{ConfigHistory->CurRow[1],System::DateTime(Convert::ToInt64(ConfigHistory->CurRow[0]))},-1);
			}
			tlHistory->EndUnboundLoad();
		}

		public: void SaveConfigHistory()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	SaveConfigHistory()");
			LogHED->Flush();
			ConfigHistory->BeginSave(string::Concat(HellEdDir,L"\\history.cfg"),false,65001);
			for(int i=0;i<tlHistory->AllNodesCount;i++)
			{
				System::DateTime dt = *dynamic_cast<System::DateTime^>(tlHistory->FindNodeByID(i)->GetValue(1));
				ConfigHistory->Add(dt.Ticks.ToString(),
					tlHistory->FindNodeByID(i)->GetValue(0)->ToString());
			}
			ConfigHistory->EndSave();
		}
		public: void SaveConfigForms()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	SaveConfigForms()");
			LogHED->Flush();

			ConfigForms->BeginSave(string::Concat(HellEdDir,L"\\frmmain.cfg"),false,65001);
			ConfigForms->Add(L"#frmMain");
			ConfigForms->Add(L"frmMain.WindowState",WindowState.ToString());
			this->Visible=true;
			WindowState=System::Windows::Forms::FormWindowState::Normal;
			barManager->SaveToXml(string::Concat(HellEdDir,L"\\bars.xml"));
			dockManager->SaveToXml(string::Concat(HellEdDir,L"\\panels.xml"));
			tlAreas->SaveLayoutToXml(string::Concat(HellEdDir,L"\\tlareas.xml"));
			tlHistory->SaveLayoutToXml(string::Concat(HellEdDir,L"\\tlhistory.xml"));
			tlMessages->SaveLayoutToXml(string::Concat(HellEdDir,L"\\tlmessages.xml"));
			LayoutControl->SaveLayoutToXml(string::Concat(HellEdDir,L"\\frmmain.xml"));
			ConfigForms->Add(L"frmMain.Width",Width.ToString());
			ConfigForms->Add(L"frmMain.Height",Height.ToString());
			ConfigForms->Add(L"frmMain.Location.X",Location.X.ToString());
			ConfigForms->Add(L"frmMain.Location.Y",Location.Y.ToString());
			ConfigForms->Add(L"frmMain.bList.Down",bList->Down==true ? L"1" : L"0");
			ConfigForms->Add(L"frmMain.lShowKludgesMode.ItemIndex",lShowKludgesMode->ItemIndex.ToString());
			ConfigForms->Add(L"frmMain.bDecryptROT13.Down",bDecryptROT13->Down==true ? L"1" : L"0");
			ConfigForms->Add(L"frmMain.bUseStyles.Down",bUseStyles->Down==true ? L"1" : L"0");
			ConfigForms->EndSave();
		}

		public: void SaveConfigAreas()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	SaveConfigAreas()");
			LogHED->Flush();

			ConfigAreas->BeginSave(string::Concat(HellEdDir,L"\\areas.cfg"),false,65001);
			int j=-1;
			for(int i=0;i<tlAreas->Nodes->Count;i++)
			{
				if (tlAreas->Nodes[i]->GetValue(8)->Equals(L"g"))
				{
					ConfigAreas->Add(string::Concat(L"#",(string^)tlAreas->Nodes[i]->GetValue(0)),L"");
					j++;
					ConfigAreas->Add(L"group",
									j.ToString(),
									(string^)tlAreas->Nodes[i]->GetValue(0));
					for (int q=0;q<tlAreas->Nodes[i]->Nodes->Count;q++)
					{
						ConfigAreas->Add(L"area",
										(string^)tlAreas->Nodes[i]->Nodes[q]->GetValue(0),
										j.ToString());
					}
				}
			}
			ConfigAreas->EndSave();
		}
//
//frmSettings
//
		public: void frmSettings_InitializeComponents()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	frmSettings_InitializeComponents()");
			LogHED->Flush();
			
			frmSettings->wbTemp->DocumentCompleted += gcnew WebBrowserDocumentCompletedEventHandler(this,&FormMain::wbTemp_DocumentCompleted);
			frmSettings->wbTemp->ScriptErrorsSuppressed = true;
			frmSettings->wbTemp->Size = System::Drawing::Size(664, 141);

			frmSettings->btnSave->Click += gcnew System::EventHandler(this, &FormMain::frmSettings_btnSave_Click);
			frmSettings->btnCancel->Click += gcnew System::EventHandler(this, &FormMain::frmSettings_btnCancel_Click);

			frmSettings->cbeFilter->ButtonClick += gcnew DevExpress::XtraEditors::Controls::ButtonPressedEventHandler(this, &FormMain::frmSettings_cbeFilter_ButtonClick);
		}

		public: void frmSettings_btnCancel_Click(object^ sender, System::EventArgs^ e)
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	frmSettings_btnCancel_Click()");
			LogHED->Flush();
			frmSettings->Visible=false;
			this->Enabled=true;
			if (WindowState != System::Windows::Forms::FormWindowState::Minimized)
			if (!(*dynamic_cast<bool^>(frmSettings->tlConfigHED->FindNodeByKeyID(1101)->GetValue(1))))
			{
				this->TopMost=true;
				this->Show();
				this->Focus();
				this->TopMost=false;
			}

			LoadConfigHED();
			LoadConfigFilter((string^)frmSettings->tlConfigHED->FindNodeByKeyID(301)->GetValue(1));
		}

		public: void frmSettings_btnSave_Click(object^ sender, System::EventArgs^ e)
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	frmSettings_btnSave_Click()");
			LogHED->Flush();

			frmSettings->Visible=false;
			this->Enabled=true;
			if (WindowState != System::Windows::Forms::FormWindowState::Minimized)
			if (!(*dynamic_cast<bool^>(frmSettings->tlConfigHED->FindNodeByKeyID(1101)->GetValue(1))))
			{
				this->TopMost=true;
				this->Show();
				this->Focus();
				this->TopMost=false;
			}
			frmSettings->SaveConfigHED();	
			LoadConfigHED();
			LoadConfigTosser();
			LoadConfigTosserFlag=false;
			if (ani!=-1){tlAreas->SetFocusedNode(tlAreas->FindNodeByID(ani));}
			LoadConfigTosserFlag=true;
			LoadConfigFilter((string^)frmSettings->tlConfigHED->FindNodeByKeyID(301)->GetValue(1));
			LoadConfigSkin((string^)frmSettings->tlConfigHED->FindNodeByKeyID(501)->GetValue(1));
			LoadConfigLanguage((string^)frmSettings->tlConfigHED->FindNodeByKeyID(601)->GetValue(1));
		}

		public: void frmSettings_cbeFilter_ButtonClick(object^ sender, DevExpress::XtraEditors::Controls::ButtonPressedEventArgs^ e)
		{
			string^ fna;
			string^ fnanew;
			switch(frmSettings->cbeFilter->Properties->Buttons->IndexOf(e->Button)) 
			{
				case 0:
					break;
				case 1:
					fnanew=InputBox->ShowInput(frmSettings,htStrings[L"Filter"]->ToString(),htStrings[L"EnterName"]->ToString(),L"");
					if (!fnanew->Equals(L""))
					if (!File::Exists(string::Concat(HellEdDir,L"\\filters\\",fnanew,L".cfg")))
					{
						File::CreateText(string::Concat(HellEdDir,L"\\filters\\",fnanew,L".cfg"))->Close();
						frmSettings->cbeFilter->SelectedIndex=frmSettings->cbeFilter->Properties->Items->Add(fnanew);
						frmSettings->rcbefilter->Items->Add(fnanew);
						lFilter->Strings->Add(fnanew);
					}
					else ;
					break;
				case 2:
					if (frmSettings->cbeFilter->SelectedIndex!=-1)
					{
						fna=frmSettings->cbeFilter->Properties->Items[frmSettings->cbeFilter->SelectedIndex]->ToString();
						if (File::Exists(string::Concat(HellEdDir,L"\\filters\\",fna,L".cfg")))
							File::Delete(string::Concat(HellEdDir,L"\\filters\\",fna,L".cfg"));
						frmSettings->cbeFilter->Properties->Items->Remove(frmSettings->cbeFilter->Properties->Items[frmSettings->cbeFilter->SelectedIndex]);
						frmSettings->cbeFilter->SelectedIndex=frmSettings->cbeFilter->Properties->Items->Count-1;
						for (int i=0;i<frmSettings->rcbefilter->Items->Count;i++)
						if (frmSettings->rcbefilter->Items[i]->Equals(fna))
						{
							if (((string^)frmSettings->tlConfigHED->FindNodeByKeyID(301)->GetValue(1))->Equals(fna))
							{frmSettings->tlConfigHED->FindNodeByKeyID(301)->SetValue(1,L"");}
							frmSettings->rcbefilter->Items->Remove(frmSettings->rcbefilter->Items[i]);	
						}
					}
					break;
				case 3:
					if (frmSettings->cbeFilter->SelectedIndex!=-1)
					{
						fna=frmSettings->cbeFilter->Properties->Items[frmSettings->cbeFilter->SelectedIndex]->ToString();
						fnanew=InputBox->ShowInput(frmSettings,htStrings[L"Filter"]->ToString(),htStrings[L"EnterName"]->ToString(),fna);
						if (!fnanew->Equals(L""))
						if (File::Exists(string::Concat(HellEdDir,L"\\filters\\",fna,L".cfg")))
						{
							File::Move(string::Concat(HellEdDir,L"\\filters\\",fna,L".cfg"),
							string::Concat(HellEdDir,L"\\filters\\",fnanew,L".cfg"));
							frmSettings->cbeFilter->Properties->Items[frmSettings->cbeFilter->SelectedIndex]=fnanew;
							frmSettings->cbeFilter->Text=fnanew;
							for (int i=0;i<lFilter->Strings->Count;i++)
							if (lFilter->Strings[i]->Equals(fna))
								lFilter->Strings[i]=fnanew;
							for (int i=0;i<frmSettings->rcbefilter->Items->Count;i++)
							if (frmSettings->rcbefilter->Items[i]->Equals(fna))
								frmSettings->rcbefilter->Items[i]=fnanew;
						}
					}
					break;
				case 4:
					if (frmSettings->cbeFilter->SelectedIndex!=-1)
					{
						fna=frmSettings->cbeFilter->Properties->Items[frmSettings->cbeFilter->SelectedIndex]->ToString();
						frmSettings->SaveConfigFilter(fna);
						if (lFilter->ItemIndex!=-1)
						if (lFilter->Strings[lFilter->ItemIndex]->Equals(fna))
							LoadConfigFilter(lFilter->Strings[lFilter->ItemIndex]);
					}
					break;
			}
		}
//
//frmAbout
//
		public: void frmAbout_InitializeComponents()
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	frmAbout_InitializeComponents()");
			LogHED->Flush();

			frmAbout->lnkFTN->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &FormMain::frmAbout_lnkFTN_LinkClicked);
			frmAbout->lnkFTNSMAPI->LinkClicked += gcnew System::Windows::Forms::LinkLabelLinkClickedEventHandler(this, &FormMain::frmAbout_lnkFTNSMAPI_LinkClicked);
		}
		public: System::Void frmAbout_lnkFTN_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	frmAbout_lnkFTN_LinkClicked()");
			LogHED->Flush();

			if (harea)
			{
				FormCreate^ frmCreate = gcnew FormCreate(frmSettings,spell);
				frmCreate_InitializeComponents(frmCreate, L"new", L"netmail",L"",L"Trooper",L"2:5030/1520.9",L"HellEd");
			}
		}
		public: System::Void frmAbout_lnkFTNSMAPI_LinkClicked(System::Object^  sender, System::Windows::Forms::LinkLabelLinkClickedEventArgs^ e)
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString()); 
			LogHED->WriteLine(L"	frmAbout_lnkFTNSMAPI_LinkClicked()");
			LogHED->Flush();

			if (harea)
			{
				FormCreate^ frmCreate = gcnew FormCreate(frmSettings,spell);
				frmCreate_InitializeComponents(frmCreate, L"new", L"netmail",L"",L"Scott J. Dudley",L"1:249/106",L"SMAPI");
			}
		}
//
//frmCreate
//
		public: void frmCreate_InitializeComponents(FormCreate^ frmCreate, string^ Temp, string^ Area, string^ OName, string^ DName, string^ DAddr, string^ Subject)
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	frmCreate_InitializeComponents()");
			LogHED->Flush();

			frmCreate->Closed += gcnew System::EventHandler(this, &FormMain::frmCreate_Closed);
			frmCreate->tlArea->StateImageList = this->iltlAreas;
			frmCreate->tlArea->BeginUnboundLoad();
			for(int i=0;i<tlAreas->Nodes->Count;i++)
			{
				TreeListNode^ node = tlAreas->Nodes[i];
				if ((node->GetValue(8)->Equals(L""))||
					(node->GetValue(8)->Equals(L"g")))
				{
					array<object^> ^ data = gcnew array<object^>(8);
					data[0]=node->GetValue(0);
					data[1]=node->GetValue(3);
					data[2]=node->GetValue(4);
					data[3]=node->GetValue(5);
					data[4]=node->GetValue(6);
					data[5]=node->GetValue(7);
					data[6]=node->GetValue(8);
					TreeListNode^ n = frmCreate->tlArea->AppendNode(data, -1);
					n->StateImageIndex=node->StateImageIndex;
					if (node->HasChildren)
					for(int j=0;j<node->Nodes->Count;j++)
					{
						TreeListNode^ node1 = node->Nodes[j];
						array<object^> ^ data = gcnew array<object^>(8);
						data[0]=node1->GetValue(0);
						data[1]=node1->GetValue(3);
						data[2]=node1->GetValue(4);
						data[3]=node1->GetValue(5);
						data[4]=node1->GetValue(6);
						data[5]=node1->GetValue(7);
						data[6]=node1->GetValue(8);
						TreeListNode^ n1 = frmCreate->tlArea->AppendNode(data, n->Id);
						n1->StateImageIndex=node1->StateImageIndex;
					}
				}
			}
			frmCreate->tlArea->EndUnboundLoad();
			frmCreate->tlArea->ExpandAll();
			if (Temp->Equals(L"edit")){frmCreate->pccArea->Enabled=false;}
			
			IHTMLDocument2^ doc = (IHTMLDocument2^)rtText->Document->DomDocument;
			IHTMLSelectionObject^ selection = doc->selection;
			IHTMLTxtRange^ range = (IHTMLTxtRange^)selection->createRange();
			if (range->text){frmCreate->qselectedtext = string::Concat(range->text->Replace("\r\n","\n"),L"\n");}
			else {frmCreate->qselectedtext = L"";}
			frmCreate->msgn = msgn;
			frmCreate->temp = Temp;
			frmCreate->qarea = Area;
			frmCreate->area = Area;
			frmCreate->dname = DName;
			if (!OName->Equals(L"")){frmCreate->oname = OName;}
			frmCreate->daddr = DAddr;
			frmCreate->subject = Subject;
			frmCreate->attributes = L"loc";
			frmCreate->tearline = (string^)frmSettings->tlConfigHED->FindNodeByKeyID(401)->GetValue(1);
			frmCreate->odatetime = System::DateTime::Now;
			frmCreate->origin = (string^)frmCreate->cbeOrigin->Properties->Items[0];
			frmCreate->LoadTemplate(Temp, harea);
			frmCreate->TopMost=true;
			frmCreate->Show();
			frmCreate->Focus();
			frmCreate->TopMost=false;
		}
		public: void frmCreate_Closed(object^ sender, System::EventArgs^ e)
		{
			LogHED->Write((System::Environment::TickCount-StartTick).ToString());
			LogHED->WriteLine(L"	frmCreate_Closed()");
			LogHED->Flush();
			
			for(int i=0;i<tlAreas->AllNodesCount;i++)
			if (tlAreas->FindNodeByID(i)->GetValue(8)->Equals(L""))
			if (!tlAreas->FindNodeByID(i)->Equals(tlAreas->FocusedNode))
			if (frmSettings->echotoss->IndexOf(string::Concat((string^)tlAreas->FindNodeByID(i)->GetValue(0),"\n"))>=0)
				tlAreas->FindNodeByID(i)->SetValue(1,(word)(*dynamic_cast<word^>(tlAreas->FindNodeByID(i)->GetValue(1))+1));
			
			if (tlAreas->FocusedNode->GetValue(8)->Equals(L""))
			if (frmSettings->echotoss->IndexOf(string::Concat((string^)tlAreas->FocusedNode->GetValue(0),"\n"))>=0)
			{
				int ind=-1;
				if (tlMessages->FocusedNode)
				{
					ind=tlMessages->FocusedNode->Id;
				}
				RescanMessages(false);
				if (UpdateMessagesFlag){ShowMessages();}
				if (ind>=tlMessages->AllNodesCount){ind--;}
				if (ind>=0){tlMessages->SetFocusedNode(tlMessages->FindNodeByID(ind));}
				tlMessages->Focus();
			}
			string^ tosser_onsend = frmSettings->tlConfigHED->FindNodeByKeyID(204)->GetValue(1)->ToString();
			if (tosser_onsend->Equals(L"True"))		frmSettings->echotoss=L"";
		}
//
// frmPopup
//
		public: System::Void frmPopup_meMessage_MouseDown(System::Object^  sender, System::Windows::Forms::MouseEventArgs^  e)
		{
			if((int)(e->Button & Windows::Forms::MouseButtons::Left) != 0)
			{
				frmPopup->Visible=false;
				frmPopup->tiMain->Enabled=false;
				if (!this->Visible)
				{
					Show();
					Focus();
					if (previousState==System::Windows::Forms::FormWindowState::Minimized)
						WindowState=System::Windows::Forms::FormWindowState::Normal;
					else WindowState = previousState;
				}
			}
			else if((int)(e->Button & Windows::Forms::MouseButtons::Right) != 0)
			{
				frmPopup->Visible=false;
				frmPopup->tiMain->Enabled=false;
			}
		}
};
}

