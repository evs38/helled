/////////////////////////////////////////////////////////////////////////////
//
// HellEd
//
// FormSettings.h
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

#include "Config.h"
#include "Utils.h"

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

	using namespace DevExpress::XtraEditors;
	using namespace DevExpress::XtraEditors::Repository;
	using namespace DevExpress::XtraTreeList::Columns;
	using namespace DevExpress::XtraTreeList::Nodes;
	using namespace DevExpress::XtraBars;
	using namespace DevExpress::XtraTab;

	/// <summary>
	/// Summary for FormSettings
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class FormSettings : public System::Windows::Forms::Form
	{
		public: System::Windows::Forms::Form^ frmMain;
		public: array<rtlConfig^> ^ rtlcfgHED;
		public: array<rtlNodelist^> ^ NodelistData;
		public: string^ HellEdDir;
		public: int ConfigEncoding;
		public: int MessagesEncoding;
		public: int FilesEncoding;
		public: Config^ ConfigHED;
		public: Config^ ConfigLanguage;
		public: Config^ ConfigNodelist;
		public: Config^ ConfigFilter;

		public: string^ echotoss;
		public: TreeListNode^ agn;

		public: System::Windows::Forms::WebBrowser^  wbTemp;
		public: DevExpress::XtraEditors::SimpleButton^ btnSave;
		public: DevExpress::XtraEditors::SimpleButton^ btnCancel;
		public: DevExpress::XtraEditors::Repository::RepositoryItemComboBox^ rcbetosser_name;
		public: DevExpress::XtraEditors::Repository::RepositoryItemComboBox^ rcbearea_select_mode;
		public: DevExpress::XtraEditors::Repository::RepositoryItemComboBox^ rcbepopup_location;
		public: DevExpress::XtraEditors::Repository::RepositoryItemComboBox^ rcbeskin;
		public: DevExpress::XtraEditors::Repository::RepositoryItemComboBox^ rcbefilter;
		public: DevExpress::XtraEditors::Repository::RepositoryItemComboBox^ rcbelanguage;
		public: DevExpress::XtraEditors::Repository::RepositoryItemMemoExEdit^ rmee;
		public: DevExpress::XtraEditors::Repository::RepositoryItemCheckEdit^ rche;
		public: DevExpress::XtraEditors::Repository::RepositoryItemTextEdit^ rte;
		public: DevExpress::XtraEditors::Repository::RepositoryItemTextEdit^ rtero;
		public: DevExpress::XtraEditors::Repository::RepositoryItemDateEdit^ rde;
		public: DevExpress::XtraEditors::Repository::RepositoryItemColorEdit^ rcoe;
		public: DevExpress::XtraEditors::Repository::RepositoryItemButtonEdit^ rbeOpenFile;
		public: DevExpress::XtraEditors::Repository::RepositoryItemButtonEdit^ rbeFolderBrowser;
		public: DevExpress::XtraEditors::Repository::RepositoryItemMemoExEdit^ rmeenodelist;
		public: DevExpress::XtraEditors::Repository::RepositoryItemComboBox^ rcbeANDOR;
		public: DevExpress::XtraEditors::Repository::RepositoryItemComboBox^ rcbeField;
		public: DevExpress::XtraEditors::Repository::RepositoryItemComboBox^ rcbeString;
		public: DevExpress::XtraEditors::Repository::RepositoryItemComboBox^ rcbeInt;
		public: DevExpress::XtraBars::PopupMenu^ pmConditions;
		public: DevExpress::XtraBars::BarManager^ barManager;
		public: DevExpress::XtraBars::BarDockControl^ barDockControlTop;
		public: DevExpress::XtraBars::BarDockControl^ barDockControlBottom;
		public: DevExpress::XtraBars::BarDockControl^ barDockControlLeft;
		public: DevExpress::XtraBars::BarLargeButtonItem^  bAddCondition;
		public: DevExpress::XtraBars::BarLargeButtonItem^  bDeleteCondition;

		public: DevExpress::XtraTab::XtraTabControl^ tabControl;
		public: DevExpress::XtraTab::XtraTabPage^ tpConfigHED;
		public: DevExpress::XtraTab::XtraTabPage^ tpFilters;
		public: DevExpress::XtraTreeList::TreeList^ tlConfigHED;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcConfigHEDKey;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcConfigHEDValue;


		public: DevExpress::XtraEditors::ComboBoxEdit^ cbeFilter;
		public: System::Windows::Forms::Label^ lblFilter;
		public: DevExpress::XtraTreeList::TreeList^ tlFilter;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcANDOR;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcField;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcOperation;
		public: DevExpress::XtraEditors::Repository::RepositoryItemSpinEdit^  rse;
		public: DevExpress::XtraEditors::Repository::RepositoryItemSpinEdit^  rse2;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^  tlcConfigHEDID;
		public: DevExpress::XtraTreeList::Columns::TreeListColumn^ tlcValue;
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected: ~FormSettings()
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
			this->rmee = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemMemoExEdit());
			this->rcbetosser_name = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemComboBox());
			this->rcbearea_select_mode = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemComboBox());
			this->rcbepopup_location = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemComboBox());
			this->rbeOpenFile = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemButtonEdit());
			this->rche = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemCheckEdit());
			this->rbeFolderBrowser = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemButtonEdit());
			this->rte = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemTextEdit());
			this->rtero = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemTextEdit());
			this->rde = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemDateEdit());
			this->rcbeskin = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemComboBox());
			this->rcbelanguage = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemComboBox());
			this->rcbefilter = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemComboBox());
			this->rcoe = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemColorEdit());
			this->rcbeANDOR = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemComboBox());
			this->rcbeField = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemComboBox());
			this->rcbeString = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemComboBox());
			this->rcbeInt = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemComboBox());
			this->btnSave = (gcnew DevExpress::XtraEditors::SimpleButton());
			this->btnCancel = (gcnew DevExpress::XtraEditors::SimpleButton());
			this->rmeenodelist = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemMemoExEdit());
			this->pmConditions = (gcnew DevExpress::XtraBars::PopupMenu(this->components));
			this->bAddCondition = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->bDeleteCondition = (gcnew DevExpress::XtraBars::BarLargeButtonItem());
			this->barManager = (gcnew DevExpress::XtraBars::BarManager(this->components));
			this->tabControl = (gcnew DevExpress::XtraTab::XtraTabControl());
			this->tpConfigHED = (gcnew DevExpress::XtraTab::XtraTabPage());
			this->tlConfigHED = (gcnew DevExpress::XtraTreeList::TreeList());
			this->tlcConfigHEDKey = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcConfigHEDValue = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcConfigHEDID = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tpFilters = (gcnew DevExpress::XtraTab::XtraTabPage());
			this->cbeFilter = (gcnew DevExpress::XtraEditors::ComboBoxEdit());
			this->lblFilter = (gcnew System::Windows::Forms::Label());
			this->tlFilter = (gcnew DevExpress::XtraTreeList::TreeList());
			this->tlcANDOR = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcField = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcOperation = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->tlcValue = (gcnew DevExpress::XtraTreeList::Columns::TreeListColumn());
			this->rse = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemSpinEdit());
			this->rse2 = (gcnew DevExpress::XtraEditors::Repository::RepositoryItemSpinEdit());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rmee))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbetosser_name))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbearea_select_mode))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbepopup_location))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rbeOpenFile))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rche))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rbeFolderBrowser))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rte))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rtero))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rde))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rde->VistaTimeProperties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbeskin))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbelanguage))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbefilter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcoe))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbeANDOR))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbeField))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbeString))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbeInt))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rmeenodelist))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmConditions))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barManager))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tabControl))->BeginInit();
			this->tabControl->SuspendLayout();
			this->tpConfigHED->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlConfigHED))->BeginInit();
			this->tpFilters->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cbeFilter->Properties))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlFilter))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rse))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rse2))->BeginInit();
			this->SuspendLayout();
			// 
			// rmee
			// 
			this->rmee->AutoHeight = false;
			this->rmee->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rmee->Name = L"rmee";
			// 
			// rcbetosser_name
			// 
			this->rcbetosser_name->AutoHeight = false;
			this->rcbetosser_name->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rcbetosser_name->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"HPT", L"BB-Toss", L"Partoss", L"areas.bbs"});
			this->rcbetosser_name->Name = L"rcbetosser_name";
			this->rcbetosser_name->TextEditStyle = DevExpress::XtraEditors::Controls::TextEditStyles::DisableTextEditor;
			// 
			// rcbearea_select_mode
			// 
			this->rcbearea_select_mode->AutoHeight = false;
			this->rcbearea_select_mode->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rcbearea_select_mode->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"0", L"1", L"2", L"3"});
			this->rcbearea_select_mode->Name = L"rcbearea_select_mode";
			this->rcbearea_select_mode->TextEditStyle = DevExpress::XtraEditors::Controls::TextEditStyles::DisableTextEditor;
			// 
			// rcbepopup_location
			// 
			this->rcbepopup_location->AutoHeight = false;
			this->rcbepopup_location->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rcbepopup_location->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"0", L"1", L"2", L"3"});
			this->rcbepopup_location->Name = L"rcbepopup_location";
			this->rcbepopup_location->TextEditStyle = DevExpress::XtraEditors::Controls::TextEditStyles::DisableTextEditor;
			// 
			// rbeOpenFile
			// 
			this->rbeOpenFile->AutoHeight = false;
			this->rbeOpenFile->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton())});
			this->rbeOpenFile->Name = L"rbeOpenFile";
			this->rbeOpenFile->ButtonClick += gcnew DevExpress::XtraEditors::Controls::ButtonPressedEventHandler(this, &FormSettings::rbeOpenFile_ButtonClick);
			// 
			// rche
			// 
			this->rche->AutoHeight = false;
			this->rche->Name = L"rche";
			// 
			// rbeFolderBrowser
			// 
			this->rbeFolderBrowser->AutoHeight = false;
			this->rbeFolderBrowser->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton())});
			this->rbeFolderBrowser->Name = L"rbeFolderBrowser";
			this->rbeFolderBrowser->ButtonClick += gcnew DevExpress::XtraEditors::Controls::ButtonPressedEventHandler(this, &FormSettings::rbeFolderBrowser_ButtonClick);
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
			// rde
			// 
			this->rde->AutoHeight = false;
			this->rde->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rde->Name = L"rde";
			this->rde->VistaTimeProperties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton())});
			// 
			// rcbeskin
			// 
			this->rcbeskin->AutoHeight = false;
			this->rcbeskin->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rcbeskin->Name = L"rcbeskin";
			this->rcbeskin->TextEditStyle = DevExpress::XtraEditors::Controls::TextEditStyles::DisableTextEditor;
			// 
			// rcbelanguage
			// 
			this->rcbelanguage->AutoHeight = false;
			this->rcbelanguage->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rcbelanguage->Name = L"rcbelanguage";
			this->rcbelanguage->TextEditStyle = DevExpress::XtraEditors::Controls::TextEditStyles::DisableTextEditor;
			// 
			// rcbefilter
			// 
			this->rcbefilter->AutoHeight = false;
			this->rcbefilter->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rcbefilter->Name = L"rcbefilter";
			this->rcbefilter->TextEditStyle = DevExpress::XtraEditors::Controls::TextEditStyles::DisableTextEditor;
			// 
			// rcoe
			// 
			this->rcoe->AutoHeight = false;
			this->rcoe->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rcoe->Name = L"rcoe";
			// 
			// rcbeANDOR
			// 
			this->rcbeANDOR->AutoHeight = false;
			this->rcbeANDOR->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rcbeANDOR->Items->AddRange(gcnew cli::array< System::Object^  >(2) {L"&", L"|"});
			this->rcbeANDOR->Name = L"rcbeANDOR";
			this->rcbeANDOR->TextEditStyle = DevExpress::XtraEditors::Controls::TextEditStyles::DisableTextEditor;
			// 
			// rcbeField
			// 
			this->rcbeField->AutoHeight = false;
			this->rcbeField->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rcbeField->Items->AddRange(gcnew cli::array< System::Object^  >(7) {L"Area", L"OName", L"DName", L"Subject", L"ODateTime", 
				L"DDateTime", L"Attributes"});
			this->rcbeField->Name = L"rcbeField";
			this->rcbeField->TextEditStyle = DevExpress::XtraEditors::Controls::TextEditStyles::DisableTextEditor;
			// 
			// rcbeString
			// 
			this->rcbeString->AutoHeight = false;
			this->rcbeString->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rcbeString->Items->AddRange(gcnew cli::array< System::Object^  >(4) {L"=", L"!=", L"~", L"!~"});
			this->rcbeString->Name = L"rcbeString";
			this->rcbeString->TextEditStyle = DevExpress::XtraEditors::Controls::TextEditStyles::DisableTextEditor;
			// 
			// rcbeInt
			// 
			this->rcbeInt->AutoHeight = false;
			this->rcbeInt->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo))});
			this->rcbeInt->Items->AddRange(gcnew cli::array< System::Object^  >(6) {L"=", L"!=", L">", L"<", L">=", L"<="});
			this->rcbeInt->Name = L"rcbeInt";
			this->rcbeInt->TextEditStyle = DevExpress::XtraEditors::Controls::TextEditStyles::DisableTextEditor;
			// 
			// btnSave
			// 
			this->btnSave->Location = System::Drawing::Point(225, 336);
			this->btnSave->Name = L"btnSave";
			this->btnSave->Size = System::Drawing::Size(72, 23);
			this->btnSave->TabIndex = 1;
			this->btnSave->Text = L"Сохранить";
			// 
			// btnCancel
			// 
			this->btnCancel->Location = System::Drawing::Point(303, 336);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 2;
			this->btnCancel->Text = L"Отменить";
			// 
			// rmeenodelist
			// 
			this->rmeenodelist->AutoHeight = false;
			this->rmeenodelist->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(2) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo)), 
				(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::OK))});
			this->rmeenodelist->Name = L"rmeenodelist";
			this->rmeenodelist->ButtonClick += gcnew DevExpress::XtraEditors::Controls::ButtonPressedEventHandler(this, &FormSettings::rmeenodelist_ButtonClick);
			// 
			// pmConditions
			// 
			this->pmConditions->LinksPersistInfo->AddRange(gcnew cli::array< DevExpress::XtraBars::LinkPersistInfo^  >(2) {(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bAddCondition)), 
				(gcnew DevExpress::XtraBars::LinkPersistInfo(this->bDeleteCondition))});
			this->pmConditions->Manager = this->barManager;
			this->pmConditions->Name = L"pmConditions";
			// 
			// bAddCondition
			// 
			this->bAddCondition->Caption = L"Добавить";
			this->bAddCondition->Id = 0;
			this->bAddCondition->Name = L"bAddCondition";
			this->bAddCondition->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormSettings::bAddCondition_ItemClick);
			// 
			// bDeleteCondition
			// 
			this->bDeleteCondition->Caption = L"Удалить";
			this->bDeleteCondition->Id = 2;
			this->bDeleteCondition->Name = L"bDeleteCondition";
			this->bDeleteCondition->ItemClick += gcnew DevExpress::XtraBars::ItemClickEventHandler(this, &FormSettings::bDeleteCondition_ItemClick);
			// 
			// barManager
			// 
			this->barManager->Form = this;
			this->barManager->Items->AddRange(gcnew cli::array< DevExpress::XtraBars::BarItem^  >(2) {this->bAddCondition, this->bDeleteCondition});
			this->barManager->MaxItemId = 3;
			// 
			// tabControl
			// 
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Top;
			this->tabControl->Location = System::Drawing::Point(0, 0);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedTabPage = this->tpConfigHED;
			this->tabControl->Size = System::Drawing::Size(382, 330);
			this->tabControl->TabIndex = 4;
			this->tabControl->TabPages->AddRange(gcnew cli::array< DevExpress::XtraTab::XtraTabPage^  >(2) {this->tpConfigHED, this->tpFilters});
			this->tabControl->Text = L"tabControl";
			// 
			// tpConfigHED
			// 
			this->tpConfigHED->Controls->Add(this->tlConfigHED);
			this->tpConfigHED->Name = L"tpConfigHED";
			this->tpConfigHED->Size = System::Drawing::Size(373, 299);
			this->tpConfigHED->Text = L"Общие";
			// 
			// tlConfigHED
			// 
			this->tlConfigHED->Columns->AddRange(gcnew cli::array< DevExpress::XtraTreeList::Columns::TreeListColumn^  >(3) {this->tlcConfigHEDKey, 
				this->tlcConfigHEDValue, this->tlcConfigHEDID});
			this->tlConfigHED->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tlConfigHED->Location = System::Drawing::Point(0, 0);
			this->tlConfigHED->Name = L"tlConfigHED";
			this->tlConfigHED->OptionsMenu->EnableColumnMenu = false;
			this->tlConfigHED->OptionsMenu->EnableFooterMenu = false;
			this->tlConfigHED->OptionsView->ShowIndicator = false;
			this->tlConfigHED->ShowButtonMode = DevExpress::XtraTreeList::ShowButtonModeEnum::ShowAlways;
			this->tlConfigHED->Size = System::Drawing::Size(373, 299);
			this->tlConfigHED->TabIndex = 1;
			this->tlConfigHED->GetCustomNodeCellEdit += gcnew DevExpress::XtraTreeList::GetCustomNodeCellEditEventHandler(this, &FormSettings::tlConfigHED_GetCustomNodeCellEdit);
			// 
			// tlcConfigHEDKey
			// 
			this->tlcConfigHEDKey->Caption = L"Ключ";
			this->tlcConfigHEDKey->FieldName = L"Key";
			this->tlcConfigHEDKey->Name = L"tlcConfigHEDKey";
			this->tlcConfigHEDKey->OptionsColumn->AllowFocus = false;
			this->tlcConfigHEDKey->OptionsColumn->AllowMove = false;
			this->tlcConfigHEDKey->OptionsColumn->AllowMoveToCustomizationForm = false;
			this->tlcConfigHEDKey->OptionsColumn->ReadOnly = true;
			this->tlcConfigHEDKey->OptionsColumn->ShowInCustomizationForm = false;
			this->tlcConfigHEDKey->Visible = true;
			this->tlcConfigHEDKey->VisibleIndex = 0;
			this->tlcConfigHEDKey->Width = 150;
			// 
			// tlcConfigHEDValue
			// 
			this->tlcConfigHEDValue->Caption = L"Значение";
			this->tlcConfigHEDValue->FieldName = L"Value";
			this->tlcConfigHEDValue->Name = L"tlcConfigHEDValue";
			this->tlcConfigHEDValue->OptionsColumn->AllowMove = false;
			this->tlcConfigHEDValue->OptionsColumn->AllowMoveToCustomizationForm = false;
			this->tlcConfigHEDValue->OptionsColumn->ShowInCustomizationForm = false;
			this->tlcConfigHEDValue->Visible = true;
			this->tlcConfigHEDValue->VisibleIndex = 1;
			this->tlcConfigHEDValue->Width = 210;
			// 
			// tlcConfigHEDID
			// 
			this->tlcConfigHEDID->FieldName = L"ID";
			this->tlcConfigHEDID->Name = L"tlcConfigHEDID";
			this->tlcConfigHEDID->OptionsColumn->AllowEdit = false;
			this->tlcConfigHEDID->OptionsColumn->AllowFocus = false;
			this->tlcConfigHEDID->OptionsColumn->AllowMove = false;
			this->tlcConfigHEDID->OptionsColumn->AllowMoveToCustomizationForm = false;
			this->tlcConfigHEDID->OptionsColumn->AllowSize = false;
			this->tlcConfigHEDID->OptionsColumn->AllowSort = false;
			this->tlcConfigHEDID->OptionsColumn->ShowInCustomizationForm = false;
			// 
			// tpFilters
			// 
			this->tpFilters->Controls->Add(this->cbeFilter);
			this->tpFilters->Controls->Add(this->lblFilter);
			this->tpFilters->Controls->Add(this->tlFilter);
			this->tpFilters->Name = L"tpFilters";
			this->tpFilters->Size = System::Drawing::Size(373, 299);
			this->tpFilters->Text = L"Фильтры";
			// 
			// cbeFilter
			// 
			this->cbeFilter->Location = System::Drawing::Point(64, 4);
			this->cbeFilter->Name = L"cbeFilter";
			this->cbeFilter->Properties->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(5) {(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Combo)), 
				(gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Plus)), (gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::Minus)), 
				(gcnew DevExpress::XtraEditors::Controls::EditorButton()), (gcnew DevExpress::XtraEditors::Controls::EditorButton(DevExpress::XtraEditors::Controls::ButtonPredefines::OK))});
			this->cbeFilter->Properties->TextEditStyle = DevExpress::XtraEditors::Controls::TextEditStyles::DisableTextEditor;
			this->cbeFilter->Size = System::Drawing::Size(303, 20);
			this->cbeFilter->TabIndex = 8;
			this->cbeFilter->SelectedIndexChanged += gcnew System::EventHandler(this, &FormSettings::cbeFilter_SelectedIndexChanged);
			// 
			// lblFilter
			// 
			this->lblFilter->Location = System::Drawing::Point(3, 7);
			this->lblFilter->Name = L"lblFilter";
			this->lblFilter->Size = System::Drawing::Size(55, 16);
			this->lblFilter->TabIndex = 7;
			this->lblFilter->Text = L"Фильтр:";
			// 
			// tlFilter
			// 
			this->tlFilter->Columns->AddRange(gcnew cli::array< DevExpress::XtraTreeList::Columns::TreeListColumn^  >(4) {this->tlcANDOR, 
				this->tlcField, this->tlcOperation, this->tlcValue});
			this->tlFilter->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->tlFilter->Location = System::Drawing::Point(0, 30);
			this->tlFilter->Name = L"tlFilter";
			this->tlFilter->OptionsMenu->EnableColumnMenu = false;
			this->tlFilter->OptionsMenu->EnableFooterMenu = false;
			this->tlFilter->OptionsView->AutoWidth = false;
			this->tlFilter->OptionsView->ShowIndicator = false;
			this->tlFilter->ShowButtonMode = DevExpress::XtraTreeList::ShowButtonModeEnum::ShowAlways;
			this->tlFilter->Size = System::Drawing::Size(373, 269);
			this->tlFilter->TabIndex = 6;
			this->tlFilter->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &FormSettings::tlFilter_MouseUp);
			this->tlFilter->GetCustomNodeCellEdit += gcnew DevExpress::XtraTreeList::GetCustomNodeCellEditEventHandler(this, &FormSettings::tlFilter_GetCustomNodeCellEdit);
			// 
			// tlcANDOR
			// 
			this->tlcANDOR->Caption = L"& / |";
			this->tlcANDOR->FieldName = L"ANDOR";
			this->tlcANDOR->Name = L"tlcANDOR";
			this->tlcANDOR->OptionsColumn->AllowMove = false;
			this->tlcANDOR->OptionsColumn->AllowMoveToCustomizationForm = false;
			this->tlcANDOR->OptionsColumn->AllowSort = false;
			this->tlcANDOR->OptionsColumn->ShowInCustomizationForm = false;
			this->tlcANDOR->Visible = true;
			this->tlcANDOR->VisibleIndex = 0;
			this->tlcANDOR->Width = 80;
			// 
			// tlcField
			// 
			this->tlcField->Caption = L"Поле";
			this->tlcField->FieldName = L"Field";
			this->tlcField->Name = L"tlcField";
			this->tlcField->OptionsColumn->AllowMove = false;
			this->tlcField->OptionsColumn->AllowMoveToCustomizationForm = false;
			this->tlcField->OptionsColumn->AllowSort = false;
			this->tlcField->OptionsColumn->ShowInCustomizationForm = false;
			this->tlcField->Visible = true;
			this->tlcField->VisibleIndex = 1;
			this->tlcField->Width = 80;
			// 
			// tlcOperation
			// 
			this->tlcOperation->Caption = L"Операция";
			this->tlcOperation->FieldName = L"Operation";
			this->tlcOperation->Name = L"tlcOperation";
			this->tlcOperation->OptionsColumn->AllowMove = false;
			this->tlcOperation->OptionsColumn->AllowMoveToCustomizationForm = false;
			this->tlcOperation->OptionsColumn->AllowSort = false;
			this->tlcOperation->OptionsColumn->ShowInCustomizationForm = false;
			this->tlcOperation->Visible = true;
			this->tlcOperation->VisibleIndex = 2;
			this->tlcOperation->Width = 80;
			// 
			// tlcValue
			// 
			this->tlcValue->Caption = L"Значение";
			this->tlcValue->FieldName = L"Value";
			this->tlcValue->Name = L"tlcValue";
			this->tlcValue->OptionsColumn->AllowMove = false;
			this->tlcValue->OptionsColumn->AllowMoveToCustomizationForm = false;
			this->tlcValue->OptionsColumn->AllowSort = false;
			this->tlcValue->OptionsColumn->ShowInCustomizationForm = false;
			this->tlcValue->Visible = true;
			this->tlcValue->VisibleIndex = 3;
			this->tlcValue->Width = 110;
			// 
			// rse
			// 
			this->rse->AutoHeight = false;
			this->rse->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton())});
			this->rse->IsFloatValue = false;
			this->rse->Mask->EditMask = L"N00";
			this->rse->MaxValue = System::Decimal(gcnew cli::array< System::Int32 >(4) {65536, 0, 0, 0});
			this->rse->MinValue = System::Decimal(gcnew cli::array< System::Int32 >(4) {0, 0, 0, 0});
			this->rse->Name = L"rse";
			// 
			// rse2
			// 
			this->rse2->AutoHeight = false;
			this->rse2->Buttons->AddRange(gcnew cli::array< DevExpress::XtraEditors::Controls::EditorButton^  >(1) {(gcnew DevExpress::XtraEditors::Controls::EditorButton())});
			this->rse2->IsFloatValue = false;
			this->rse2->Mask->EditMask = L"N00";
			this->rse2->MaxValue = System::Decimal(gcnew cli::array< System::Int32 >(4) {65536, 0, 0, 0});
			this->rse2->MinValue = System::Decimal(gcnew cli::array< System::Int32 >(4) {14, 0, 0, 0});
			this->rse2->Name = L"rse2";
			// 
			// FormSettings
			// 
			this->AutoScaleBaseSize = System::Drawing::Size(5, 13);
			this->ClientSize = System::Drawing::Size(382, 366);
			this->ControlBox = false;
			this->Controls->Add(this->tabControl);
			this->Controls->Add(this->btnCancel);
			this->Controls->Add(this->btnSave);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::Fixed3D;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"FormSettings";
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Настройки";
			this->TopMost = true;
			this->Closing += gcnew System::ComponentModel::CancelEventHandler(this, &FormSettings::FormSettings_Closing);

			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rmee))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbetosser_name))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbearea_select_mode))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbepopup_location))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rbeOpenFile))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rche))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rbeFolderBrowser))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rte))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rtero))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rde->VistaTimeProperties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rde))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbeskin))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbelanguage))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbefilter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcoe))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbeANDOR))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbeField))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbeString))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rcbeInt))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rmeenodelist))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pmConditions))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->barManager))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tabControl))->EndInit();
			this->tabControl->ResumeLayout(false);
			this->tpConfigHED->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlConfigHED))->EndInit();
			this->tpFilters->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->cbeFilter->Properties))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->tlFilter))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rse))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->rse2))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		public:	FormSettings(System::Windows::Forms::Form^ frm)
		{
			InitializeComponent();
			ConfigFilter = gcnew Config();
			this->wbTemp = (gcnew System::Windows::Forms::WebBrowser());
			frmMain = frm;
			HellEdDir = Directory::GetCurrentDirectory();
			ConfigHED = gcnew Config();
			ConfigLanguage = gcnew Config();
			ConfigNodelist = gcnew Config();
			InitializetlConfigHED();
			ConfigNodelist->Load(string::Concat(HellEdDir,L"\\nodelist.cfg"),false,65001);
			array<rtlNodelist^> ^ temp = gcnew array<rtlNodelist^>(100000);
			int n;
			for(n=0;ConfigNodelist->LoadRow();)
			{		
				bool fl=true;
				if (n>0)
					if (ConfigNodelist->CurRow[0]->Equals(temp[n-1]->ID)){fl=false;}
				if (fl)
				{
					temp[n++] = gcnew rtlNodelist(ConfigNodelist->CurRow[0],
						ConfigNodelist->CurRow[1],
						ConfigNodelist->CurRow[2],
						ConfigNodelist->CurRow[3],
						ConfigNodelist->CurRow[4],
						ConfigNodelist->CurRow[5]);
				}
			}
			ConfigNodelist->EndLoad();
			NodelistData = gcnew array<rtlNodelist^>(n);
			for(int i=0;i<n;i++){NodelistData[i]=temp[i];}
		}
		public: void InitializetlConfigHED()
		{
			rtlcfgHED = gcnew array<rtlConfig^>(41);
			
			int i=0;
			rtlcfgHED[i++] = gcnew rtlConfig(L"User",1);
			rtlcfgHED[i++] = gcnew rtlConfig(L"name",L"",rmee,101);
			rtlcfgHED[i++] = gcnew rtlConfig(L"address",L"",rmee,102);
			
			rtlcfgHED[i++] = gcnew rtlConfig(L"Tosser",2);
			rtlcfgHED[i++] = gcnew rtlConfig(L"tosser_name",L"",rcbetosser_name,201);
			rtlcfgHED[i++] = gcnew rtlConfig(L"tosser_config_path",L"",rbeOpenFile,202);
			rtlcfgHED[i++] = gcnew rtlConfig(L"tosser_path",L"",rbeOpenFile,203);
			rtlcfgHED[i++] = gcnew rtlConfig(L"tosser_onsend",L"",rche,204);
			rtlcfgHED[i++] = gcnew rtlConfig(L"tosser_onexit",L"",rche,205);
			rtlcfgHED[i++] = gcnew rtlConfig(L"scanmsgbase_onstart",L"",rche,206);
			rtlcfgHED[i++] = gcnew rtlConfig(L"echotoss_log_path",L"",rbeOpenFile,207);
			rtlcfgHED[i++] = gcnew rtlConfig(L"import_log_path",L"",rbeOpenFile,208);
			rtlcfgHED[i++] = gcnew rtlConfig(L"tosser_time",L"",rse,209);

	
			rtlcfgHED[i++] = gcnew rtlConfig(L"Filters",3);
			rtlcfgHED[i++] = gcnew rtlConfig(L"filter",L"",rcbefilter,301);

			rtlcfgHED[i++] = gcnew rtlConfig(L"Templates",4);
			rtlcfgHED[i++] = gcnew rtlConfig(L"tearline",L"",rte,401);
			rtlcfgHED[i++] = gcnew rtlConfig(L"origin",L"",rmee,402);
			
			rtlcfgHED[i++] = gcnew rtlConfig(L"Skins",5);
			rtlcfgHED[i++] = gcnew rtlConfig(L"skin",L"",rcbeskin,501);
			
			rtlcfgHED[i++] = gcnew rtlConfig(L"Languages",6);
			rtlcfgHED[i++] = gcnew rtlConfig(L"language",L"",rcbelanguage,601);

			rtlcfgHED[i++] = gcnew rtlConfig(L"Lists",7);
			rtlcfgHED[i++] = gcnew rtlConfig(L"nodelist",L"",rmeenodelist,701);

			rtlcfgHED[i++] = gcnew rtlConfig(L"Messages",8);
			rtlcfgHED[i++] = gcnew rtlConfig(L"known_kludge",L"",rmee,801);

			rtlcfgHED[i++] = gcnew rtlConfig(L"Editor",9);
			rtlcfgHED[i++] = gcnew rtlConfig(L"string_length",L"",rse2,901);

			rtlcfgHED[i++] = gcnew rtlConfig(L"Areas",10);
			rtlcfgHED[i++] = gcnew rtlConfig(L"area_select_mode",L"",rcbearea_select_mode,1001);
			rtlcfgHED[i++] = gcnew rtlConfig(L"area_name",L"",rte,1002);

			rtlcfgHED[i++] = gcnew rtlConfig(L"General",11);
			rtlcfgHED[i++] = gcnew rtlConfig(L"minimize_to_tray",L"",rche,1101);
			rtlcfgHED[i++] = gcnew rtlConfig(L"check_for_updates_onstart",L"",rche,1102);
			rtlcfgHED[i++] = gcnew rtlConfig(L"popup_time",L"",rse,1103);
			rtlcfgHED[i++] = gcnew rtlConfig(L"popup_location",L"",rcbepopup_location,1104);

			rtlcfgHED[i++] = gcnew rtlConfig(L"Encodings",12);
			rtlcfgHED[i++] = gcnew rtlConfig(L"config_encoding",L"",rse,1201);
			rtlcfgHED[i++] = gcnew rtlConfig(L"messages_encoding",L"",rse,1202);
			rtlcfgHED[i++] = gcnew rtlConfig(L"replace",L"",rmee,1203);
			rtlcfgHED[i++] = gcnew rtlConfig(L"files_encoding",L"",rse,1204);

			tlConfigHED->DataSource = rtlcfgHED;
			tlConfigHED->ExpandAll();
		}

		public: void SaveConfigHED()
		{
			array<string^> ^ strs;
			string^ name = (string^)tlConfigHED->FindNodeByKeyID(101)->GetValue(1);
			string^ address = (string^)tlConfigHED->FindNodeByKeyID(102)->GetValue(1);
			string^ tosser_name = (string^)tlConfigHED->FindNodeByKeyID(201)->GetValue(1);
			string^ tosser_config_path = (string^)tlConfigHED->FindNodeByKeyID(202)->GetValue(1);
			string^ tosser_path = (string^)tlConfigHED->FindNodeByKeyID(203)->GetValue(1);
			string^ tosser_onsend = tlConfigHED->FindNodeByKeyID(204)->GetValue(1)->ToString();
			string^ tosser_onexit = tlConfigHED->FindNodeByKeyID(205)->GetValue(1)->ToString();
			string^ scanmsgbase_onstart = tlConfigHED->FindNodeByKeyID(206)->GetValue(1)->ToString();
			string^ echotoss_log_path = (string^)tlConfigHED->FindNodeByKeyID(207)->GetValue(1);
			string^ import_log_path = (string^)tlConfigHED->FindNodeByKeyID(208)->GetValue(1);
			string^ tosser_time = tlConfigHED->FindNodeByKeyID(209)->GetValue(1)->ToString();
			string^ filter = (string^)tlConfigHED->FindNodeByKeyID(301)->GetValue(1);
			string^ tearline = (string^)tlConfigHED->FindNodeByKeyID(401)->GetValue(1);
			string^ origin = (string^)tlConfigHED->FindNodeByKeyID(402)->GetValue(1);
			string^ skin = (string^)tlConfigHED->FindNodeByKeyID(501)->GetValue(1);
			string^ language = (string^)tlConfigHED->FindNodeByKeyID(601)->GetValue(1);
			string^ nodelist = (string^)tlConfigHED->FindNodeByKeyID(701)->GetValue(1);
			string^ known_kludge = (string^)tlConfigHED->FindNodeByKeyID(801)->GetValue(1);
			string^ string_length = tlConfigHED->FindNodeByKeyID(901)->GetValue(1)->ToString();
			string^ area_select_mode = rcbearea_select_mode->Items->IndexOf(tlConfigHED->FindNodeByKeyID(1001)->GetValue(1)).ToString();
			string^ area_name = (string^)tlConfigHED->FindNodeByKeyID(1002)->GetValue(1);
			string^ minimize_to_tray = tlConfigHED->FindNodeByKeyID(1101)->GetValue(1)->ToString();
			string^ check_for_updates_onstart = tlConfigHED->FindNodeByKeyID(1102)->GetValue(1)->ToString();
			string^ popup_time = tlConfigHED->FindNodeByKeyID(1103)->GetValue(1)->ToString();
			string^ popup_location = rcbepopup_location->Items->IndexOf(tlConfigHED->FindNodeByKeyID(1104)->GetValue(1)).ToString();

			string^ config_encoding = tlConfigHED->FindNodeByKeyID(1201)->GetValue(1)->ToString();
			string^ messages_encoding = tlConfigHED->FindNodeByKeyID(1202)->GetValue(1)->ToString();
			string^ replace = tlConfigHED->FindNodeByKeyID(1203)->GetValue(1)->ToString();
			string^ files_encoding = tlConfigHED->FindNodeByKeyID(1204)->GetValue(1)->ToString();

			ConfigHED->BeginSave(string::Concat(HellEdDir, L"\\helled.cfg"),false,65001);
			ConfigHED->Add(L"#User");
			strs = name->Split(((string^)L"\r\n")->ToCharArray());
			for(int i=0;i<strs->Length;i++)if (strs[i]!=""){ConfigHED->Add(L"name",strs[i]);}
			strs = address->Split(((string^)L"\r\n")->ToCharArray());
			for(int i=0;i<strs->Length;i++)if (strs[i]!=""){ConfigHED->Add(L"address",strs[i]);}
			ConfigHED->Add(L"#Tosser");
			ConfigHED->Add(L"tosser_name",tosser_name);
			ConfigHED->Add(L"tosser_config_path",tosser_config_path);
			ConfigHED->Add(L"tosser_path",tosser_path);
			ConfigHED->Add(L"tosser_onsend",tosser_onsend->Equals(L"False") ? L"0" : L"1");
			ConfigHED->Add(L"tosser_onexit",tosser_onexit->Equals(L"False") ? L"0" : L"1");
			ConfigHED->Add(L"scanmsgbase_onstart",scanmsgbase_onstart->Equals(L"False") ? L"0" : L"1");
			ConfigHED->Add(L"echotoss_log_path",echotoss_log_path);
			ConfigHED->Add(L"import_log_path",import_log_path);
			ConfigHED->Add(L"tosser_time",tosser_time);
			ConfigHED->Add(L"#Filters");
			ConfigHED->Add(L"filter",filter);
			ConfigHED->Add(L"#Templates");
			ConfigHED->Add(L"tearline",tearline);
			strs = origin->Split(((string^)L"\r\n")->ToCharArray());
			for(int i=0;i<strs->Length;i++)if (strs[i]!=""){ConfigHED->Add(L"origin",strs[i]);}
			ConfigHED->Add(L"#Skins");
			ConfigHED->Add(L"skin",skin);
			ConfigHED->Add(L"#Languages");
			ConfigHED->Add(L"language",language);
			ConfigHED->Add(L"#Lists");
			strs = nodelist->Split(((string^)L"\r\n")->ToCharArray());
			for(int i=0;i<strs->Length;i++)if (strs[i]!=""){ConfigHED->Add(L"nodelist",strs[i]);}
			ConfigHED->Add(L"#Messages");
			strs = known_kludge->Split(((string^)L"\r\n")->ToCharArray());
			for(int i=0;i<strs->Length;i++)if (strs[i]!=""){ConfigHED->Add(L"known_kludge",strs[i]);}
			ConfigHED->Add(L"#Editor");
			ConfigHED->Add(L"string_length",string_length);
			ConfigHED->Add(L"#Areas");
			ConfigHED->Add(L"area_select_mode",area_select_mode);
			ConfigHED->Add(L"area_name",area_name);
			ConfigHED->Add(L"#General");
			ConfigHED->Add(L"minimize_to_tray",minimize_to_tray->Equals(L"False") ? L"0" : L"1");
			ConfigHED->Add(L"check_for_updates_onstart",check_for_updates_onstart->Equals(L"False") ? L"0" : L"1");
			ConfigHED->Add(L"popup_time",popup_time);
			ConfigHED->Add(L"popup_location",popup_location);
			ConfigHED->Add(L"#Encodings");
			ConfigHED->Add(L"config_encoding",config_encoding);
			ConfigHED->Add(L"messages_encoding",messages_encoding);
			strs = replace->Split(((string^)L"\r\n")->ToCharArray());
			for(int i=0;i<strs->Length;i++)
			if (strs[i]!=L""){ConfigHED->Add(L"replace",strs[i]);}
			ConfigHED->Add(L"files_encoding",files_encoding);

			ConfigHED->EndSave();
		}
		
		public: void tlConfigHED_GetCustomNodeCellEdit(object^ sender, DevExpress::XtraTreeList::GetCustomNodeCellEditEventArgs^ e) 
		{
			if(e->Column->FieldName->Equals(L"Value")){e->RepositoryItem = rtlcfgHED[e->Node->Id]->ValueEditor;}
		}

		public: void rbeOpenFile_ButtonClick(object^ sender, DevExpress::XtraEditors::Controls::ButtonPressedEventArgs^ e) 
		{
			OpenFileDialog^ dlg = gcnew OpenFileDialog();
			dlg->Filter = L"All Files(*.*)|*.*";
			dlg->FileName=(string^ )tlConfigHED->FocusedNode->GetValue(1);
			if(dlg->ShowDialog() == Windows::Forms::DialogResult::OK) {tlConfigHED->FocusedNode->SetValue(1,dlg->FileName);}
		}
		public: void rbeFolderBrowser_ButtonClick(object^ sender, DevExpress::XtraEditors::Controls::ButtonPressedEventArgs^ e) 
		{
			FolderBrowserDialog^ dlg = gcnew FolderBrowserDialog();
			dlg->SelectedPath=(string^)tlConfigHED->FocusedNode->GetValue(1);
			if(dlg->ShowDialog() == Windows::Forms::DialogResult::OK) {tlConfigHED->FocusedNode->SetValue(1,dlg->SelectedPath);}
		}
			
		public: void rmeenodelist_ButtonClick(object^ sender, DevExpress::XtraEditors::Controls::ButtonPressedEventArgs^ e)
		{
			MemoExEdit^ mee = (MemoExEdit^)sender;
			switch(mee->Properties->Buttons->IndexOf(e->Button)) 
			{
				case 0:
					break;
				case 1:
					CompileNodelist();
					break;
			}
		}
		public: void CompileNodelist()
		{
			array<string^> ^ strs;
			string^ nodelist = (string^)tlConfigHED->FindNodeByKeyID(701)->GetValue(1);
			strs = nodelist->Split(((string^)L"\r\n")->ToCharArray());
			
			array<object^> ^Rows = gcnew array<object^>(100000);
			int n=0;
			for(int i=0;i<strs->Length;i++)
			if (strs[i]!="")
			{
				StreamReader^ sr = gcnew StreamReader(strs[i],System::Text::Encoding::GetEncoding(ConfigEncoding));
				string^ zone=L"0";
				string^ net=L"0";
				string^ node=L"0";
				string^ point=L"0";
				string^ boss=L"0";
				for (string^ str = sr->ReadLine(); str; str = sr->ReadLine())
				{
					if (!str->StartsWith(L";")&&(str->IndexOf(L",")!=-1))
					{
						array<string^,1> ^ values = str->Split(((string^)L",")->ToCharArray());
						if (values[0]->ToLower()->Equals(L"boss")){boss=values[1];}
						else
						{
							if (values[0]->ToLower()->Equals(L"zone"))
							{
								zone=values[1];
								net=L"0";
								node=L"0";
								point=L"0";
							}
							if ((values[0]->ToLower()->Equals(L"region"))||
								(values[0]->ToLower()->Equals(L"host"))||
								(values[0]->ToLower()->Equals(L"net")))
							{
								net=values[1];
								node=L"0";
								point=L"0";
							}
							if ((values[0]->ToLower()->Equals(L"pvt"))||
								(values[0]->ToLower()->Equals(L"hub"))||
								(values[0]->ToLower()->Equals(L"down"))||
								(values[0]->ToLower()->Equals(L"")))
							{
								node=values[1];
								point=L"0";
							}
							if (values[0]->ToLower()->Equals(L"point")){point=values[1];}
							string^ addr = L"";
							string^ par = L"-1";
							if (!zone->Equals(L"0"))
							{
								addr=zone;
								if (!net->Equals(L"0"))
								{
									par=addr;
									addr=string::Concat(addr,L":",net);
									if (!node->Equals(L"0"))
									{
										par=addr;
										addr=string::Concat(addr,L"/",node);
									}
								}
							}
							if (!point->Equals(L"0"))
							{
								par=boss;
								addr=string::Concat(boss,L".",point);
							}
							Rows[n]=gcnew array<string^>(6){addr,
												par,
												values[2]->Replace("_"," "),
												values[3]->Replace("_"," "),
												values[4]->Replace("_"," "),
												values[5]};
							n++;					
						}
					}
				}
				sr->Close();
			}
		
			RowComparer^ rc = gcnew RowComparer();
			Array::Sort(Rows, 0, n, rc);		
			ConfigNodelist->BeginSave(string::Concat(HellEdDir,L"\\nodelist.cfg"),false,65001);
			NodelistData = gcnew array<rtlNodelist^>(n);
			for(int i=0;i<n;i++)
			{
				bool fl=true;
				if (i>0)
					if (((array<string^>^)Rows[i])[0]->Equals(((array<string^>^)Rows[i-1])[0])){fl=false;}
				if (fl)
				{
					ConfigNodelist->Add(((array<string^>^)Rows[i])[0],
					((array<string^>^)Rows[i])[1],
					((array<string^>^)Rows[i])[2],
					((array<string^>^)Rows[i])[3],
					((array<string^>^)Rows[i])[4],
					((array<string^>^)Rows[i])[5]);
					NodelistData[i] = gcnew rtlNodelist(((array<string^>^)Rows[i])[0],
						((array<string^>^)Rows[i])[1],
						((array<string^>^)Rows[i])[2],
						((array<string^>^)Rows[i])[3],
						((array<string^>^)Rows[i])[4],
						((array<string^>^)Rows[i])[5]);
				}
			}
			ConfigNodelist->EndSave();
		}

		public: void tlFilter_MouseUp(object^ sender, System::Windows::Forms::MouseEventArgs^ e)
		{
			if((int)(e->Button & Windows::Forms::MouseButtons::Right) != 0 && tlFilter->ClientRectangle.Contains(e->X, e->Y))
			{
				bDeleteCondition->Enabled = false;
				DevExpress::XtraTreeList::TreeListHitInfo^ hi = tlFilter->CalcHitInfo(tlFilter->PointToClient(Point(Control::MousePosition.X,Control::MousePosition.Y)));
				agn = hi->Node;
				if(agn)
				{
					bDeleteCondition->Enabled = true;
				}
				pmConditions->ShowPopup(Control::MousePosition);
			}
		}

		public: void SaveConfigFilter(string^ name)
		{
			ConfigFilter->BeginSave(string::Concat(HellEdDir,L"\\filters\\",name,L".cfg"),false,65001);
			for(int i=0;i<tlFilter->Nodes->Count;i++)
			{
				ConfigFilter->Add(tlFilter->Nodes[i]->GetValue(0)->ToString(),
				tlFilter->Nodes[i]->GetValue(1)->ToString(),
				tlFilter->Nodes[i]->GetValue(2)->ToString(),
				tlFilter->Nodes[i]->GetValue(3)->ToString());
			}
			ConfigFilter->EndSave();
		}
		public: void bAddCondition_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
			array<object^> ^ data = gcnew array<object^>(4);
			data[0]=L"|";
			data[1]=this->rcbeField->Items[0];
			data[2]=L"=";
			data[3]=L"";
			tlFilter->AppendNode(data,-1);
		}
		public: void bDeleteCondition_ItemClick(object^ sender, DevExpress::XtraBars::ItemClickEventArgs^ e) 
		{
            tlFilter->DeleteNode(agn);
		}

		public: void cbeFilter_SelectedIndexChanged(object^ sender, System::EventArgs^ e)
		{
			if (cbeFilter->SelectedIndex==-1)
				tlFilter->ClearNodes();
			else LoadConfigFilter(cbeFilter->Properties->Items[cbeFilter->SelectedIndex]->ToString());

		}

		public: void LoadConfigFilter(string^ Name)
		{
			tlFilter->ClearNodes();
			ConfigFilter->Load(string::Concat(HellEdDir,L"\\filters\\",Name,L".cfg"),true,65001);
			while(ConfigFilter->LoadRow())
			if (ConfigFilter->CurRow->Length>=4)
			{
				string^ str0 = ConfigFilter->CurRow[0];
				string^ str1 = ConfigFilter->CurRow[1];
				string^ str2 = ConfigFilter->CurRow[2];
				string^ str3 = ConfigFilter->CurRow[3];
				array<object^> ^ data = gcnew array<object^>(4);
		
				if ((str0->Equals(L"&"))||
					(str0->Equals(L"|")))
				{
					data[0]=str0;
					int op=-1;
					if (str1->ToLower()->Equals(L"area")){data[1]=L"Area"; op=0;}
					else if (str1->ToLower()->Equals(L"oname")){data[1]=L"OName"; op=0;}
					else if (str1->ToLower()->Equals(L"dname")){data[1]=L"DName"; op=0;}
					else if (str1->ToLower()->Equals(L"subject")){data[1]=L"Subject"; op=0;}
					else if (str1->ToLower()->Equals(L"attributes")){data[1]=L"Attributes"; op=01;}
					else if (str1->ToLower()->Equals(L"odatetime")){data[1]=L"ODateTime"; op=1;}
					else if (str1->ToLower()->Equals(L"ddatetime")){data[1]=L"DDateTime"; op=1;}
					if (op>=0)
					{
						if (op==0)
						{
							if ((str2->Equals(L"="))||
								(str2->Equals(L"!="))||
								(str2->Equals(L"~"))||
								(str2->Equals(L"!~")))
							{
								data[2]=str2;
								data[3]=str3;
								tlFilter->AppendNode(data,-1);
							}
						}
						else
						if (op==0)
						{
							if ((str2->Equals(L"="))||
								(str2->Equals(L"!="))||
								(str2->Equals(L">"))||
								(str2->Equals(L"<"))||
								(str2->Equals(L">="))||
								(str2->Equals(L"<=")))
							{
								data[2]=str2;
								data[3]=nullptr;
								tlFilter->AppendNode(data,-1);
							}
						}


					}
				}
			}
		}
		public: void tlFilter_GetCustomNodeCellEdit(object^ sender, DevExpress::XtraTreeList::GetCustomNodeCellEditEventArgs^ e) 
		{
			if (e->Column->FieldName->Equals(L"ANDOR"))
			{
				e->RepositoryItem=rcbeANDOR;
			}
			else if (e->Column->FieldName->Equals(L"Field"))
			{
				e->RepositoryItem=rcbeField;
			}
			else if (e->Column->FieldName->Equals(L"Operation"))
			{
				if ((e->Node->GetValue(1)->Equals(L"Area"))||
					(e->Node->GetValue(1)->Equals(L"OName"))||
					(e->Node->GetValue(1)->Equals(L"DName"))||
					(e->Node->GetValue(1)->Equals(L"Subject"))||
					(e->Node->GetValue(1)->Equals(L"Attributes")))
				{e->RepositoryItem = rcbeString;}
				else if ((e->Node->GetValue(1)->Equals(L"ODateTime"))||
					(e->Node->GetValue(1)->Equals(L"DDateTime")))
				{e->RepositoryItem = rcbeInt;}
			}
			else if (e->Column->FieldName->Equals(L"Value"))
			{
				if ((e->Node->GetValue(1)->Equals(L"Area"))||
					(e->Node->GetValue(1)->Equals(L"OName"))||
					(e->Node->GetValue(1)->Equals(L"DName"))||
					(e->Node->GetValue(1)->Equals(L"Subject"))||
					(e->Node->GetValue(1)->Equals(L"Attributes")))
				{e->RepositoryItem = rte;}
				else if ((e->Node->GetValue(1)->Equals(L"ODateTime"))||
					(e->Node->GetValue(1)->Equals(L"DDateTime")))
				{e->RepositoryItem = rde;}
			}
		}
		public: void FormSettings_Closing(object^ sender, System::ComponentModel::CancelEventArgs^ e)
		{
			e->Cancel=true;
		}
	};
}
