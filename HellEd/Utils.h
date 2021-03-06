/////////////////////////////////////////////////////////////////////////////
//
// HellEd
//
// Utils.h
//
// Copyright (c) 2002-2008 by Alexey Bezugly
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version. See license.txt for details.
/////////////////////////////////////////////////////////////////////////////
#pragma once
#include "smapi/msgapi.h"

typedef System::Object object;
typedef System::String string;

#define DECODE_BYTE(b) ((b == 0x60) ? 0 : b - 0x20)
#define ENCODE_BYTE(b) (((b) == 0) ? 0x60 : ((b) + 0x20))

using namespace System;
using namespace System::Runtime::InteropServices;

public ref struct OLECMDTEXT
{
  public:

      unsigned int cmdtextf;
      unsigned int cwActual;
      unsigned int cwBuf;
      char rgwz;
};

 

public ref struct OLECMD
{
  public:

      long cmdID;
      System::UInt64 cmdf;
};

 

      // Constants for the commands that are named earlier

      public enum class MiscCommandTargetWrapper
      {
            Find = 1,
            ViewSource,
            Options
      };

// Interop definition for IOleCommandTarget. You need this attribute to marshal the wrapper as a COM 
// interface
[ComImport, 
Guid("b722bccb-4e68-101b-a2bc-00aa00404770"),
InterfaceType(ComInterfaceType::InterfaceIsIUnknown)]
public interface class IOleCommandTargetWrapper
{ 
      //IMPORTANT: The order of the methods is important here. 
      // Since you are doing early binding, the order of the methods
      //here MUST match the order of their vtable layout (which is determined
      //by their layout in IDL). The interop calls key off the vtable ordering,
      //not off the symbolic names, and therefore, if you switched these method
      //declarations and tried to call the Exec() function on an IOleCommandTarget
      //interface from your application, it would translate into a call to
      //QueryStatus() instead.

      void QueryStatus(Guid* pguidCmdGroup, System::UInt32 cCmds, 
     [MarshalAs(UnmanagedType::LPArray, SizeParamIndex=1)] OLECMD^ prgCmds, OLECMDTEXT^ CmdText);
      void Exec(interior_ptr<System::Guid> pguidCmdGroup, long nCmdId, long nCmdExecOpt, Object^% pvaIn,
                       Object^% pvaOut);

};

namespace HellEd
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Diagnostics;
	using namespace System::IO;
	using namespace System::Text;
	using namespace System::Text::RegularExpressions;
	using namespace System::Runtime::InteropServices;

	/// <summary>
	/// Summary description for Utils.
	/// </summary>
	public ref struct Tag
	{
		public: int Pos;
		public: string^ str;
	};
	public ref class TagComparer: public IComparer
	{
		public: virtual int Compare(System::Object^ x, System::Object^ y)
		{
			if (((Tag^)x)->Pos<((Tag^)y)->Pos){return -1;}
			else if (((Tag^)x)->Pos>((Tag^)y)->Pos){return 1;}
			{return 0;}
		}
	};
	public ref class RowComparer: public IComparer
	{
		public: virtual int Compare(System::Object^ x, System::Object^ y)
		{
			return string::Compare(((array<string^>^)x)[0],((array<string^>^)y)[0]);
		}
	};
	public ref class Utils
	{
		public: static Utils()
		{
		}	
		public: static System::DateTime _stampToDateTime(_stamp stamp)
		{
			if ((stamp.date.yr)&&(stamp.date.mo)&&(stamp.date.da)&&
				(stamp.time.hh)&&(stamp.time.mm)&&(stamp.time.ss))
			{return System::DateTime(1980+stamp.date.yr,stamp.date.mo,stamp.date.da,
			stamp.time.hh,stamp.time.mm,stamp.time.ss);}
			else {return System::DateTime::Now;}
		}
		public: static _stamp DateTimeTo_stamp(System::DateTime dt)
		{
			_stamp stamp;
			stamp.date.yr = dt.Year-1980;
			stamp.date.mo = dt.Month;
			stamp.date.da = dt.Day;
			stamp.time.hh = dt.Hour;
			stamp.time.mm = dt.Minute;
			stamp.time.ss = dt.Second;
			return stamp;
		}
		public: static string^ URLEncode(string^ str)
		{
			return System::Web::HttpUtility::UrlEncode(str);
		}
		public: static string^ URLDecode(string^ str)
		{
			return System::Web::HttpUtility::UrlDecode(str);
		}

		public: static string^ NETADDRToString(NETADDR addr)
		{
			return string::Concat(addr.zone,L":",addr.net,L"/",addr.node,
				L".",addr.point);
		}

		public: static NETADDR StringToNETADDR(string^ str)
		{
			NETADDR addr;
			Regex^ re = gcnew Regex(L"(\\d{1,5}):(\\d{1,5})/(\\d{1,5})(?:\\.(\\d{1,5}))\?");
			Match^ m = re->Match(str);
			if (m->Success)
			{
				addr.zone = Convert::ToInt32(m->Groups[1]->Value);
				addr.net = Convert::ToInt32(m->Groups[2]->Value);
				addr.node = Convert::ToInt32(m->Groups[3]->Value);
				if (!m->Groups[4]->Value->Equals(L"")){addr.point = Convert::ToInt32(m->Groups[4]->Value);}
				else {addr.point=0;}
			}
			return addr;
		}

		public: static string^ CompleteAddr(string^ str)
		{
			string^ addr = str;
			if (addr->Length==0){addr=L"0:0/0.0";}
			{
				if (addr->IndexOf(L":")==-1){addr=string::Concat(addr,L":0");}
				if (addr->IndexOf(L"/")==-1){addr=string::Concat(addr,L"/0");}
			}
			return addr;
		}
		
		public: static string^ CompleteAddr2(string^ str)
		{
			string^ addr = str;
			if (addr->Length==0){addr=L"0:0/0.0";}
			{
				if (addr->IndexOf(L":")==-1){addr=string::Concat(addr,L":0");}
				if (addr->IndexOf(L"/")==-1){addr=string::Concat(addr,L"/0");}
				if (addr->IndexOf(L".")==-1){addr=string::Concat(addr,L".0");}
			}
			return addr;
		}

		public: static void SetValueLanguage(object^% key, string^ value)
		{
			if (key->GetType()->ToString()->Equals(L"DevExpress.XtraTreeList.Columns.TreeListColumn"))
			{((DevExpress::XtraTreeList::Columns::TreeListColumn^)key)->Caption=value;}
			else if (key->GetType()->ToString()->Equals(L"DevExpress.XtraLayout.LayoutControlItem"))
			{
				((DevExpress::XtraLayout::LayoutControlItem^)key)->Text=value;
				((DevExpress::XtraLayout::LayoutControlItem^)key)->CustomizationFormText=value;
			}
			else if (key->GetType()->ToString()->Equals(L"DevExpress.XtraLayout.BaseLayoutItem"))
			{
				((DevExpress::XtraLayout::LayoutControlItem^)key)->Text=value;
				((DevExpress::XtraLayout::LayoutControlItem^)key)->CustomizationFormText=value;
			}
			else if (key->GetType()->ToString()->Equals(L"DevExpress.XtraBars.BarSubItem"))
			{((DevExpress::XtraBars::BarSubItem^)key)->Caption=value;}
			else if (key->GetType()->ToString()->Equals(L"DevExpress.XtraBars.BarLargeButtonItem"))
			{
				((DevExpress::XtraBars::BarLargeButtonItem^)key)->Caption=value;
				((DevExpress::XtraBars::BarLargeButtonItem^)key)->Hint=value;
			}
			else if (key->GetType()->ToString()->Equals(L"DevExpress.XtraBars.BarStaticItem"))
			{((DevExpress::XtraBars::BarStaticItem^)key)->Caption=value;}
			else if (key->GetType()->ToString()->Equals(L"DevExpress.XtraTreeList.Nodes.TreeListNode"))
			{((DevExpress::XtraTreeList::Nodes::TreeListNode^)key)->SetValue(0,value);}
			else if (key->GetType()->ToString()->Equals(L"DevExpress.XtraTreeList.Columns.TreeListColumn"))
			{((DevExpress::XtraTreeList::Columns::TreeListColumn^)key)->Caption=value;}
			else if (key->GetType()->ToString()->Equals(L"DevExpress.XtraBars.Bar"))
			{((DevExpress::XtraBars::Bar^)key)->Text=value;}
			else if (key->GetType()->ToString()->Equals(L"DevExpress.XtraEditors.Controls.CheckedListBoxItem"))
			{((DevExpress::XtraEditors::Controls::CheckedListBoxItem^)key)->Value=value;}
			else if (key->GetType()->ToString()->Equals(L"DevExpress.XtraBars.Docking.DockPanel"))
			{((DevExpress::XtraBars::Docking::DockPanel^)key)->Text=value;}
			else if (key->GetType()->ToString()->Equals(L"DevExpress.XtraTab.XtraTabPage"))
			{((DevExpress::XtraTab::XtraTabPage^)key)->Text=value;}
			else if (key->GetType()->ToString()->Equals(L"DevExpress.XtraEditors.SimpleButton"))
			{((DevExpress::XtraEditors::SimpleButton^)key)->Text=value;}
			else if (key->GetType()->ToString()->Equals(L"System.Windows.Forms.Label"))
			{((Label^)key)->Text=value;}
			else if (key->GetType()->ToString()->Equals(L"System.Windows.Forms.LinkLabel"))
			{((LinkLabel^)key)->Text=value;}
			else if (key->GetType()->ToString()->Equals(L"HellEd.FormSettings"))
			{((System::Windows::Forms::Form^)key)->Text=value;}
			else if (key->GetType()->ToString()->Equals(L"HellEd.FormAbout"))
			{((System::Windows::Forms::Form^)key)->Text=value;}
		}

		public: static dword StringToAttr(string^ str)
		{
			dword attr = 0;
			if (str->IndexOf(L"pvt")!=-1){attr|=MSGPRIVATE;}
			if (str->IndexOf(L"crash")!=-1){attr|=MSGCRASH;}
			if (str->IndexOf(L"read")!=-1){attr|=MSGREAD;}
			if (str->IndexOf(L"sent")!=-1){attr|=MSGSENT;}
			if (str->IndexOf(L"att")!=-1){attr|=MSGFILE;}
			if (str->IndexOf(L"fwd")!=-1){attr|=MSGFWD;}
			if (str->IndexOf(L"orphan")!=-1){attr|=MSGORPHAN;}
			if (str->IndexOf(L"k/L")!=-1){attr|=MSGKILL;}
			if (str->IndexOf(L"loc")!=-1){attr|=MSGLOCAL;}
			if (str->IndexOf(L"hld")!=-1){attr|=MSGHOLD;}
			if (str->IndexOf(L"frq")!=-1){attr|=MSGFRQ;}
			if (str->IndexOf(L"rrq")!=-1){attr|=MSGRRQ;}
			if (str->IndexOf(L"cfm")!=-1){attr|=MSGCPT;}
			if (str->IndexOf(L"arq")!=-1){attr|=MSGARQ;}
			if (str->IndexOf(L"urq")!=-1){attr|=MSGURQ;}
			if (str->IndexOf(L"dir")!=-1){attr|=MSGXX2;}
			if (str->IndexOf(L"scn")!=-1){attr|=MSGSCANNED;}
			if (str->IndexOf(L"lck")!=-1){attr|=MSGLOCKED;}
			return attr;
		}
		public: static string^ AttrToString(dword attr)
		{
			string^ str = L"";
			if (attr & MSGPRIVATE){str=string::Concat(str,"pvt ");}
			if (attr & MSGCRASH){str=string::Concat(str,"crash ");}
			if (attr & MSGREAD){str=string::Concat(str,"read ");}
			if (attr & MSGSENT){str=string::Concat(str,"sent ");}
			if (attr & MSGFILE){str=string::Concat(str,"att ");}
			if (attr & MSGFWD){str=string::Concat(str,"fwd ");}
			if (attr & MSGORPHAN){str=string::Concat(str,"orphan ");}
			if (attr & MSGKILL){str=string::Concat(str,"k/s ");}
			if (attr & MSGLOCAL){str=string::Concat(str,"loc ");}
			if (attr & MSGHOLD){str=string::Concat(str,"hld ");}
			if (attr & MSGFRQ){str=string::Concat(str,"frq ");}
			if (attr & MSGRRQ){str=string::Concat(str,"rrq ");}
			if (attr & MSGCPT){str=string::Concat(str,"cfm ");}
			if (attr & MSGARQ){str=string::Concat(str,"arq ");}
			if (attr & MSGURQ){str=string::Concat(str,"urq ");}
			if (attr & MSGXX2){str=string::Concat(str,"dir ");}
			if (attr & MSGSCANNED){str=string::Concat(str,"scn ");}
			if (attr & MSGLOCKED){str=string::Concat(str,"lck ");}
			return str->Trim();
		}

		public: static void StringToCLB(string^ str,DevExpress::XtraEditors::CheckedListBoxControl ^  clbAttributes)
		{
			if (str->IndexOf(L"pvt")!=-1)	{clbAttributes->SetItemChecked(0,true);}
			if (str->IndexOf(L"crash")!=-1)	{clbAttributes->SetItemChecked(1,true);}
			if (str->IndexOf(L"read")!=-1)	{clbAttributes->SetItemChecked(2,true);}
			if (str->IndexOf(L"sent")!=-1)	{clbAttributes->SetItemChecked(3,true);}
			if (str->IndexOf(L"att")!=-1)	{clbAttributes->SetItemChecked(4,true);}
			if (str->IndexOf(L"fwd")!=-1)	{clbAttributes->SetItemChecked(5,true);}
			if (str->IndexOf(L"orphan")!=-1){clbAttributes->SetItemChecked(6,true);}
			if (str->IndexOf(L"k/s")!=-1)	{clbAttributes->SetItemChecked(7,true);}
			if (str->IndexOf(L"loc")!=-1)	{clbAttributes->SetItemChecked(8,true);}
			if (str->IndexOf(L"hld")!=-1)	{clbAttributes->SetItemChecked(9,true);}
			if (str->IndexOf(L"frq")!=-1)	{clbAttributes->SetItemChecked(10,true);}
			if (str->IndexOf(L"rrq")!=-1)	{clbAttributes->SetItemChecked(11,true);}
			if (str->IndexOf(L"cfm")!=-1)	{clbAttributes->SetItemChecked(12,true);}
			if (str->IndexOf(L"arq")!=-1)	{clbAttributes->SetItemChecked(13,true);}
			if (str->IndexOf(L"urq")!=-1)	{clbAttributes->SetItemChecked(14,true);}
			if (str->IndexOf(L"dir")!=-1)	{clbAttributes->SetItemChecked(15,true);}
			if (str->IndexOf(L"scn")!=-1)	{clbAttributes->SetItemChecked(16,true);}
			if (str->IndexOf(L"lck")!=-1)	{clbAttributes->SetItemChecked(17,true);}
		}
		
		public: static string^ CLBToString(DevExpress::XtraEditors::CheckedListBoxControl ^  clbAttributes)
		{
			string^ str = L"";
			if (clbAttributes->GetItemChecked(0)){str=string::Concat(str,"pvt ");}
			if (clbAttributes->GetItemChecked(1)){str=string::Concat(str,"crash ");}
			if (clbAttributes->GetItemChecked(2)){str=string::Concat(str,"read ");}
			if (clbAttributes->GetItemChecked(3)){str=string::Concat(str,"sent ");}
			if (clbAttributes->GetItemChecked(4)){str=string::Concat(str,"att ");}
			if (clbAttributes->GetItemChecked(5)){str=string::Concat(str,"fwd ");}
			if (clbAttributes->GetItemChecked(6)){str=string::Concat(str,"orphan ");}
			if (clbAttributes->GetItemChecked(7)){str=string::Concat(str,"k/s ");}
			if (clbAttributes->GetItemChecked(8)){str=string::Concat(str,"loc ");}
			if (clbAttributes->GetItemChecked(9)){str=string::Concat(str,"hld ");}
			if (clbAttributes->GetItemChecked(10)){str=string::Concat(str,"frq ");}
			if (clbAttributes->GetItemChecked(11)){str=string::Concat(str,"rrq ");}
			if (clbAttributes->GetItemChecked(12)){str=string::Concat(str,"cfm ");}
			if (clbAttributes->GetItemChecked(13)){str=string::Concat(str,"arq ");}
			if (clbAttributes->GetItemChecked(14)){str=string::Concat(str,"urq ");}
			if (clbAttributes->GetItemChecked(15)){str=string::Concat(str,"dir ");}
			if (clbAttributes->GetItemChecked(16)){str=string::Concat(str,"scn ");}
			if (clbAttributes->GetItemChecked(17)){str=string::Concat(str,"lck ");}
			return str->Trim();
		}
		public: static bool uu_decode(string^ source, string^ FileName)
		{
			source=source->Trim('\n')->Trim('\r');
			char* mas = (char*)(void*)Marshal::StringToHGlobalAnsi(source);
			char* linep;
			char* linebuf = mas;
			char outbyte[3];

			FileInfo^ fi = gcnew FileInfo(FileName); 
			FileStream^ sw = fi->OpenWrite();
			for(int i=0;i<source->Length;)
			{
				int linelen = DECODE_BYTE(linebuf[0]);
				linep = linebuf + 1;
				i++;
				for (int linecnt = linelen; linecnt > 0; linecnt -= 3, linep += 4, i+=4)
				{
					outbyte[0] = DECODE_BYTE(linep[0]);
					outbyte[1] = DECODE_BYTE(linep[1]);
					outbyte[0] = (outbyte[0] << 2);
					outbyte[0] = (outbyte[0] | ((outbyte[1] >> 4) & 0x03));
					outbyte[1] = (outbyte[1] << 4);
					outbyte[2] = DECODE_BYTE(linep[2]);
					outbyte[1] = (outbyte[1] | ((outbyte[2] >> 2) & 0x0F));
					outbyte[2] = (outbyte[2] << 6);
					outbyte[2] = (outbyte[2] | (DECODE_BYTE(linep[3]) & 0x3F));
					if (linecnt > 3)
					{
						for(int j=0;j<3;j++)
						{sw->WriteByte(outbyte[j]);}
					}
				    else
					{
						for(int j=0;j<linecnt;j++)
						{sw->WriteByte(outbyte[j]);}
						linecnt = 3;
					}
				}
				linebuf=linep;
				for(;;)
				{
					if (i<source->Length)
					if ((linebuf[0]=='\r'))
					{
						linebuf++;
						i++;
					}
					else {break;}
					else {break;}
				}
			}
			Marshal::FreeHGlobal((System::IntPtr)mas);
			sw->Close();
			return true;
		}
		public: static string^ uu_encode(string^ FileName)
		{
			int linelen;
			int linecnt;
			int p;
			char inbuf[45];
			FileInfo^ fi = gcnew FileInfo(FileName); 
			FileStream^ sr = fi->OpenRead();
			StringBuilder^ res = gcnew StringBuilder();
			res->Append(L"begin 644 ");
			res->AppendLine(fi->Name);
			do
			{
				int cnt = min(45,sr->Length-sr->Position);
				for(linelen=0;linelen<cnt;linelen++)
				{inbuf[linelen] = (char)sr->ReadByte();}
				for(int i=cnt;i<45;i++)
				{inbuf[i] = (char)0;}
				p=0;
				res->Append((__wchar_t)ENCODE_BYTE(linelen));
				for (linecnt=linelen;linecnt>0;linecnt -= 3)
				{
					res->Append((__wchar_t)(ENCODE_BYTE((inbuf[p+0] & 0xFC) >> 2)));
					res->Append((__wchar_t)(ENCODE_BYTE(((inbuf[p+0] & 0x03) << 4) +
						((inbuf[p+1] & 0xF0) >> 4))));
					res->Append((__wchar_t)(ENCODE_BYTE(((inbuf[p+1] & 0x0F) << 2) +
						((inbuf[p+2] & 0xC0) >> 6))));
					res->Append((__wchar_t)(ENCODE_BYTE(inbuf[p+2] & 0x3F)));
					p += 3;
			    }
				res->AppendLine();
			} while (linelen != 0);
			res->AppendLine("end");
			sr->Close();
			return res->ToString();
		}
		public: static string^ rot13(string^ str)
		{
			array<__wchar_t,1> ^ st=str->ToCharArray();
			for(int i=0;i<str->Length;i++)
			{
				if ((((char)st[i] >= 'A')&&((char)st[i] <= 'M'))||
					(((char)st[i] >= 'a')&&((char)st[i] <= 'm')))
				{st[i]=(__wchar_t)((char)st[i]+13);}
				else if ((((char)st[i] >= 'N')&&((char)st[i] <= 'Z'))||
					(((char)st[i] >= 'n')&&((char)st[i] <= 'z')))
				{st[i]=(__wchar_t)((char)st[i]-13);}
			}
			str = gcnew string(st);
			return str;
		}

		public: static string^ ProcessFTN(string^ txt, string^ HellEdDir, bool ShowKludges, bool DecryptROT13, bool UseStyles)
		{
			string^ res=txt;
			if (DecryptROT13){res=rot13(res);}
			ArrayList ^ tags = gcnew ArrayList();
			int n=0;
			Regex ^ re = gcnew Regex(L"^begin\\s644\\s(.*?$)(.*?)(^end$)",(RegexOptions)(RegexOptions::Multiline | RegexOptions::Singleline));
			MatchCollection^ mc = re->Matches(res);		
			int q=0;
			int pos=res->Length;
			for(int i=0;i<mc->Count;i++)
			{
				string^ FileName=mc[i]->Groups[1]->Value;
				string^ uue=mc[i]->Groups[2]->Value;
				if (uu_decode(uue,string::Concat(HellEdDir,L"\\temp\\",FileName)))
				{
					string^ link = string::Concat(L"<a href=\"file://localhost/",(gcnew Uri(HellEdDir))->AbsolutePath,L"/temp/",FileName,L"\">");
					bool img=false;
					int pnt = FileName->LastIndexOf(L".");
					if (pnt!=-1)
					{
						string^ ext=FileName->Substring(pnt+1)->ToLower();
						if ((ext->Equals(L"bmp"))||
							(ext->Equals(L"gif"))||
							(ext->Equals(L"ico"))||
							(ext->Equals(L"jpe"))||
							(ext->Equals(L"jpeg"))||
							(ext->Equals(L"jpg"))||
							(ext->Equals(L"png")))
						{
							img=true;
						}
					}
					if (img)							
					{
						link=string::Concat(link,L"<img src=\"file://localhost/",(gcnew Uri(HellEdDir))->AbsolutePath,L"/temp/",FileName,L"\" alt=\"",
							FileName,L"\">");
					}
					else
					{
						link=string::Concat(link,FileName);
					}
					link = string::Concat(link,L"</a>");
					tags->Add(gcnew Tag());
					((Tag^)tags[n])->Pos=mc[i]->Index+q;
					((Tag^)tags[n])->str=link;
					n++;
					res=string::Concat(res->Substring(0,mc[i]->Index+q),
						res->Substring(mc[i]->Index+mc[i]->Length+q));
					q=res->Length-pos;
				}
			}
			re = gcnew Regex(L"^(?:\\u263A|SEEN\\-BY:).*",RegexOptions::Multiline);
			mc = re->Matches(res);
			q=0;
			pos=res->Length;
			for(int i=0;i<mc->Count;i++)
			{
				if (ShowKludges)
				{
					tags->Add(gcnew Tag());
					((Tag^)tags[n])->Pos=mc[i]->Index+q;
					((Tag^)tags[n])->str=L"<span class=\"Kludge\">";
					n++;
					tags->Add(gcnew Tag());
					((Tag^)tags[n])->Pos=mc[i]->Index+q+mc[i]->Length;
					((Tag^)tags[n])->str=L"</span>";
					n++;
					res=string::Concat(res->Substring(0,mc[i]->Index+q),
						mc[i]->Value,
						res->Substring(mc[i]->Index+mc[i]->Length+q));
				}
				else
				{
					if (mc[i]->Index+mc[i]->Length+q+1<res->Length)
					{
						res=string::Concat(res->Substring(0,mc[i]->Index+q),
							res->Substring(mc[i]->Index+mc[i]->Length+q+1));
						for(int j=0;j<n;j++)
						if (((Tag^)tags[j])->Pos>mc[i]->Index){((Tag^)tags[j])->Pos-=(mc[i]->Length+1);}
					}
					else
					{
						res=res->Substring(0,mc[i]->Index+q);
					}
				}
				q=res->Length-pos;
			}
			re = gcnew Regex(L"^---\\s.*?$",RegexOptions::Multiline);
			mc = re->Matches(res);
			q=0;
			for(int i=0;i<mc->Count;i++)
			{
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index;
				((Tag^)tags[n])->str=L"<span class=\"Tearline\">";
				n++;
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index+mc[i]->Length;
				((Tag^)tags[n])->str=L"</span>";
				n++;
			}
			re = gcnew Regex(L"^\\s\\*\\sOrigin:(\\s.*)(\\((?:\\d*:)?\\d*/\\d*(?:\\.\\d*)?\\))$",RegexOptions::Multiline);
			mc = re->Matches(res);
			q=0;
			for(int i=0;i<mc->Count;i++)
			{
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index+q;
				((Tag^)tags[n])->str=L"<span class=\"Origin\"> * Origin:";
				for(int j=0;j<n;j++)
				if (((Tag^)tags[j])->Pos>((Tag^)tags[n])->Pos){((Tag^)tags[j])->Pos-=10;}
				n++;
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index+q+mc[i]->Groups[1]->Length+mc[i]->Groups[2]->Length;
				((Tag^)tags[n])->str=L"</span>";
				n++;
				res=string::Concat(res->Substring(0,mc[i]->Index+q),
					mc[i]->Groups[1]->Value,
					mc[i]->Groups[2]->Value,
					res->Substring(mc[i]->Index+mc[i]->Length+q));
				q-=10;
			}
			re = gcnew Regex(L"^\\s*[A-Za-zА-Яа-я]*(>>)*>\\s.*",RegexOptions::Multiline);
			mc = re->Matches(res);
			for(int i=0;i<mc->Count;i++)
			{
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index;
				((Tag^)tags[n])->str=L"<span class=\"OddQuote\">";
				n++;
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index+mc[i]->Length;
				((Tag^)tags[n])->str=L"</span>";
				n++;
			}			
			re = gcnew Regex(L"^\\s*[A-Za-zА-Яа-я]*(>>)*>>\\s.*",RegexOptions::Multiline);
			mc = re->Matches(res);
			for(int i=0;i<mc->Count;i++)
			{
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index;
				((Tag^)tags[n])->str=L"<span class=\"EvenQuote\">";
				n++;
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index+mc[i]->Length;
				((Tag^)tags[n])->str=L"</span>";
				n++;
			}	
			if (UseStyles)
			{
				Match^ m;
				re = gcnew Regex(L"(^|[\\s!\"\\$&%\\(\\)\\+,\\.:<=>@\\[\\\\\\]\\^`\\{\\|\\}~\\#/_])\\*([^\\*].*?)\\*($|[<\\s!\"\\$&%\\(\\)\\+,\\.:<=>@\\[\\\\\\]\\^`\\{\\|\\}~\\#/_])",RegexOptions::Multiline);
				q=0;
				pos=res->Length;
				for(m=re->Match(res);m->Success;m=re->Match(res,m->Index+m->Length+q))
				{
					tags->Add(gcnew Tag());
					((Tag^)tags[n])->Pos=m->Index+m->Groups[1]->Length;
					((Tag^)tags[n])->str=L"<b>";
					for(int j=0;j<n;j++)
					if (((Tag^)tags[j])->Pos>((Tag^)tags[n])->Pos){((Tag^)tags[j])->Pos-=1;}
					n++;
					tags->Add(gcnew Tag());
					((Tag^)tags[n])->Pos=m->Index+m->Groups[1]->Length+m->Groups[2]->Length;
					((Tag^)tags[n])->str=L"</b>";
					for(int j=0;j<n;j++)
					if (((Tag^)tags[j])->Pos>((Tag^)tags[n])->Pos){((Tag^)tags[j])->Pos-=1;}
					n++;
					res=string::Concat(res->Substring(0,m->Index),
						m->Groups[1]->Value,
						m->Groups[2]->Value,
						m->Groups[3]->Value,
						res->Substring(m->Index+m->Length));
					q-=3;
				}
				re = gcnew Regex(L"(^|[\\s!\"\\$&%\\(\\)\\+,\\.:<=>@\\[\\\\\\]\\^`\\{\\|\\}~\\*\\#_])/([^/].*?)/($|[<\\s!\"\\$&%\\(\\)\\+,\\.:<=>@\\[\\\\\\]\\^`\\{\\|\\}~\\*\\#_])",RegexOptions::Multiline);
				q=0;
				pos=res->Length;
				for(m=re->Match(res);m->Success;m=re->Match(res,m->Index+m->Length+q))
				{
					tags->Add(gcnew Tag());
					((Tag^)tags[n])->Pos=m->Index+m->Groups[1]->Length;
					((Tag^)tags[n])->str=L"<i>";
					for(int j=0;j<n;j++)
					if (((Tag^)tags[j])->Pos>((Tag^)tags[n])->Pos){((Tag^)tags[j])->Pos-=1;}
					n++;
					tags->Add(gcnew Tag());
					((Tag^)tags[n])->Pos=m->Index+m->Groups[1]->Length+m->Groups[2]->Length;
					((Tag^)tags[n])->str=L"</i>";
					for(int j=0;j<n;j++)
					if (((Tag^)tags[j])->Pos>((Tag^)tags[n])->Pos){((Tag^)tags[j])->Pos-=1;}
					n++;
					res=string::Concat(res->Substring(0,m->Index),
						m->Groups[1]->Value,
						m->Groups[2]->Value,
						m->Groups[3]->Value,
						res->Substring(m->Index+m->Length));
					q-=3;
				}
				re = gcnew Regex(L"(^|[\\s!\"\\$&%\\(\\)\\+,\\.:<=>@\\[\\\\\\]\\^`\\{\\|\\}~\\*\\#/])_([^_].*?)_($|[<\\s!\"\\$&%\\(\\)\\+,\\.:<=>@\\[\\\\\\]\\^`\\{\\|\\}~\\*\\#/])",RegexOptions::Multiline);
				q=0;
				pos=res->Length;
				for(m=re->Match(res);m->Success;m=re->Match(res,m->Index+m->Length+q))
				{
					tags->Add(gcnew Tag());
					((Tag^)tags[n])->Pos=m->Index+m->Groups[1]->Length;
					((Tag^)tags[n])->str=L"<u>";
					for(int j=0;j<n;j++)
					if (((Tag^)tags[j])->Pos>((Tag^)tags[n])->Pos){((Tag^)tags[j])->Pos-=1;}
					n++;
					tags->Add(gcnew Tag());
					((Tag^)tags[n])->Pos=m->Index+m->Groups[1]->Length+m->Groups[2]->Length;
					((Tag^)tags[n])->str=L"</u>";
					for(int j=0;j<n;j++)
					if (((Tag^)tags[j])->Pos>((Tag^)tags[n])->Pos){((Tag^)tags[j])->Pos-=1;}
					n++;
					pos=res->Length;
					res=string::Concat(res->Substring(0,m->Index),
						m->Groups[1]->Value,
						m->Groups[2]->Value,
						m->Groups[3]->Value,
						res->Substring(m->Index+m->Length));
					q-=3;
				}
				re = gcnew Regex(L"(^|[\\s!\"\\$&%\\(\\)\\+,\\.:<=>@\\[\\\\\\]\\^`\\{\\|\\}~\\*/_])\\#([^\\#].*?)\\#($|[<\\s!\"\\$&%\\(\\)\\+,\\.:<=>@\\[\\\\\\]\\^`\\{\\|\\}~\\*/_])",RegexOptions::Multiline);
				q=0;
				pos=res->Length;
				for(m=re->Match(res);m->Success;m=re->Match(res,m->Index+m->Length+q))
				{
					tags->Add(gcnew Tag());
					((Tag^)tags[n])->Pos=m->Index+m->Groups[1]->Length;
					((Tag^)tags[n])->str=L"<font class=\"r\">";
					for(int j=0;j<n;j++)
					if (((Tag^)tags[j])->Pos>((Tag^)tags[n])->Pos){((Tag^)tags[j])->Pos-=1;}
					n++;
					tags->Add(gcnew Tag());
					((Tag^)tags[n])->Pos=m->Index+m->Groups[1]->Length+m->Groups[2]->Length;
					((Tag^)tags[n])->str=L"</font>";
					for(int j=0;j<n;j++)
					if (((Tag^)tags[j])->Pos>((Tag^)tags[n])->Pos){((Tag^)tags[j])->Pos-=1;}
					n++;
					pos=res->Length;
					res=string::Concat(res->Substring(0,m->Index),
						m->Groups[1]->Value,
						m->Groups[2]->Value,
						m->Groups[3]->Value,
						res->Substring(m->Index+m->Length));
					q-=3;
				}
			}
			re = gcnew Regex(L"((ftp|http|https)://|www\\.)([\\w\\d\\-]+(\\.[\\w\\d\\-]+)+)(:\\d\\d?\\d?\\d?\\d?)?(((/[%+\\w\\d\\-\\\\\\.;~]*)+)*)(\\?[^\\s=&]+(&[^\\s=&])*(=[^\\s=&]+(&[^\\s=&]+(=[^\\s=&]+)*)*)*)?(\\#[\\w\\d\\-%+]+)?",RegexOptions::IgnoreCase);
			mc = re->Matches(res);
			for(int i=0;i<mc->Count;i++)
			{
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index;
				((Tag^)tags[n])->str=string::Concat(L"<a href=\"",
					mc[i]->Value,L"\">");
				n++;
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index+mc[i]->Length;
				((Tag^)tags[n])->str=L"</a>";
				n++;
			}
			re = gcnew Regex(L"(mailto:)?([\\w-\\.]+)@((\\[[0-9]{1,3}\\.[0-9]{1,3}\\.[0-9]{1,3}\\.)|(([\\w-]+\\.)+))([a-zA-Z]{2,4}|[0-9]{1,3})(\\]?)",RegexOptions::IgnoreCase);
			mc = re->Matches(res);
			for(int i=0;i<mc->Count;i++)
			{
				string^ link = mc[i]->Value;
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index;
				((Tag^)tags[n])->str=string::Concat("<a href=\"",link->StartsWith(L"mailto:") ? link : string::Concat(L"mailto:",link),L"\">");
				n++;
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index+mc[i]->Length;
				((Tag^)tags[n])->str=L"</a>";
				n++;
			}

			re = gcnew Regex(L"area://((?:[A-Za-z0-9\\._\\-&\\+]|(?:%[0-9A-F]{2}))*)/?(?:\\?(?:&?(msgid|time|usetz|from|to|subject|subj|find|geomark|geofrom|kl)(?:=((?:[A-Za-z0-9\\.\\+/,!@$^\\*\\(\\)\\-=_:\\\"';]|(?:%[0-9A-F]{2}))*))?)*)?",RegexOptions::IgnoreCase);
			mc = re->Matches(res);
			for(int i=0;i<mc->Count;i++)
			{
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index;
				((Tag^)tags[n])->str=string::Concat(L"<a href=\"",
					mc[i]->Value,L"\">");
				n++;
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index+mc[i]->Length;
				((Tag^)tags[n])->str=L"</a>";
				n++;
			}

			re = gcnew Regex(L"areafix:((?:[A-Za-z0-9\\._\\-&\\+]|(?:%[0-9A-F]{2}))*)(?:\\?(?:&?(leave|unsubscribe|uplink)(?:=((?:[A-Za-z0-9\\.\\+/,!@$^\\*\\(\\)\\-=_:\\\"';]|(?:%[0-9A-F]{2}))*))?)*)?",RegexOptions::IgnoreCase);
			mc = re->Matches(res);
			for(int i=0;i<mc->Count;i++)
			{
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index;
				((Tag^)tags[n])->str=string::Concat(L"<a href=\"",
					mc[i]->Value,L"\">");
				n++;
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index+mc[i]->Length;
				((Tag^)tags[n])->str=L"</a>";
				n++;
			}

			re = gcnew Regex(L"echomail:((?:[A-Za-z0-9\\._\\-&\\+]|(?:%[0-9A-F]{2}))+)(?:\\?(?:&?(to|subject|subj|body|from)(?:=((?:[A-Za-z0-9\\.\\+/,!@$^\\*\\(\\)\\-=_:\\\"';]|(?:%[0-9A-F]{2}))*))?)*)?",RegexOptions::IgnoreCase);
			mc = re->Matches(res);
			for(int i=0;i<mc->Count;i++)
			{
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index;
				((Tag^)tags[n])->str=string::Concat(L"<a href=\"",
					mc[i]->Value,L"\">");
				n++;
				tags->Add(gcnew Tag());
				((Tag^)tags[n])->Pos=mc[i]->Index+mc[i]->Length;
				((Tag^)tags[n])->str=L"</a>";
				n++;
			}

			re = gcnew Regex(L"(?:netmail:)?(\\d{1,5}:\\d{1,5}/\\d{1,5}(?:\\.\\d{1,5})?)(?:\\?(?:&?(to|subject|subj|from|body)(?:=((?:[A-Za-z0-9\\.\\+/,!@$^\\*\\(\\)\\-=_:\\\"';]|(?:%[0-9A-F]{2}))*))?)*)?",RegexOptions::IgnoreCase);
			mc = re->Matches(res);
			for(int i=0;i<mc->Count;i++)
			{
				bool fl=true;
				if (mc[i]->Index!=0)
					if (res->Substring(mc[i]->Index-1,1)->Equals(L"=")){fl=false;}
				if (fl)
				{
					string^ link = mc[i]->Value;
					tags->Add(gcnew Tag());
					((Tag^)tags[n])->Pos=mc[i]->Index;
					((Tag^)tags[n])->str=string::Concat("<a href=\"",link->StartsWith(L"netmail:") ? link : string::Concat(L"netmail:",link),L"\">");
					n++;
					tags->Add(gcnew Tag());
					((Tag^)tags[n])->Pos=mc[i]->Index+mc[i]->Length;
					((Tag^)tags[n])->str=L"</a>";
					n++;
				}
			}

			TagComparer^ tc = gcnew TagComparer();
			tags->Sort(tc);

			StringBuilder^ sb = gcnew StringBuilder(L"");
			for(int i=0;i<n;i++)
			{
				if (i==0)
				{
					sb->Append(res->Substring(0,((Tag^)tags[i])->Pos)->
						Replace("&","&amp;")-> 
						Replace("\"","&quot;")-> 
						Replace("'","&#039")-> 
						Replace("<","&lt;")-> 
						Replace(">","&gt;"));
					sb->Append(((Tag^)tags[i])->str);
				}
				else
				{
					sb->Append(res->Substring(((Tag^)tags[i-1])->Pos,((Tag^)tags[i])->Pos-((Tag^)tags[i-1])->Pos)->
						Replace("&","&amp;")-> 
						Replace("\"","&quot;")-> 
						Replace("'","&#039")-> 
						Replace("<","&lt;")-> 
						Replace(">","&gt;"));
					sb->Append(((Tag^)tags[i])->str);
				}
			}
			if (n>0)
			{
				sb->Append(res->Substring(((Tag^)tags[n-1])->Pos)->
							Replace("&","&amp;")-> 
							Replace("\"","&quot;")-> 
							Replace("'","&#039")-> 
							Replace("<","&lt;")-> 
							Replace(">","&gt;"));
			}
			res = sb->Replace("\n","\r\n")->
				Replace("\r\n","<br>\r\n")->
				Replace("\r\n ","\r\n&nbsp;")->
				Replace("> ",">&nbsp;")->
				Replace("  "," &nbsp;")->ToString();
			return res;
		}
	};
	public ref class rtlConfig
	{
		private: string^ key;
		private: object^ val;
		private: RepositoryItem^ valeditor;
		private: int id;
		private: int parentid;
		public: rtlConfig(string^ Key, int ID)
		{
			key = Key;
			val=L"";
			valeditor = gcnew RepositoryItem();
			valeditor->ReadOnly=true;
			id = ID;
			if (ID==0){parentid = -1;}
			else {parentid=(int)ID/100;}
		}
		public: rtlConfig(string^ Key, object^ Value, RepositoryItem^ ValueEditor, int ID) 
		{
			key = Key;
			val = Value;
			valeditor=ValueEditor;
			id = ID;
			if (ID==0){parentid = -1;}
			else {parentid=(int)ID/100;}
		}
		property int ID
		{
			int get(){return id;}
			void set(int ID){id=ID;}
		}
		property int ParentID
		{
			int get(){return parentid;}
			void set(int ParentID){parentid=ParentID;}
		}
		property string^ Key
		{
			string^ get(){return key;}
			void set(string^ Key){key=Key;}
		}
		property object^ Value
		{
			object^ get(){return val;}
			void set(object^ Value){val=Value;}
		}
		property RepositoryItem^ ValueEditor
		{
			RepositoryItem^ get(){return valeditor;}
		}
	};

	public ref class rtlMessages
	{
		private: dword id;
		private: dword parentid;
		private: word n;
		private: bool mark;
		private: string^ attributes;
		private: string^ oname;
		private: string^ dname;
		private: string^ subject;
		private: System::DateTime odatetime;
		private: System::DateTime ddatetime;
		private: string^ area;
		private: string^ msgid;
		public: rtlMessages(dword ID, dword ParentID, word N, bool Mark, string^ Attributes,
				string^ OName, string^ DName, string^ Subject, System::DateTime ODateTime,
				System::DateTime DDateTime, string^ Area, string^ MSGID)
		{
			id = ID;
			parentid = ParentID;
			n = N;
			mark = Mark;
			attributes = Attributes;
			oname = OName;
			dname = DName;
			subject = Subject;
			odatetime = ODateTime;
			ddatetime = DDateTime;
			area = Area;
			msgid = MSGID;
		}
		property dword ID
		{
			dword get(){return id;}
			void set(dword ID){id=ID;}
		}
		property dword ParentID
		{
			dword get(){return parentid;}
			void set(dword ParentID){parentid=ParentID;}
		}
		property word N
		{
			word get(){return n;}
			void set(word N){n=N;}
		}
		property bool Mark
		{
			bool get(){return mark;}
			void set(bool Mark){mark=Mark;}
		}
		property string^ Attributes
		{
			string^ get(){return attributes;}
			void set(string^ Attributes){attributes=Attributes;}
		}
		property string^ OName
		{
			string^ get(){return oname;}
			void set(string^ OName){oname=OName;}
		}
		property string^ DName
		{
			string^ get(){return dname;}
			void set(string^ DName){dname=DName;}
		}
		property string^ Subject
		{
			string^ get(){return subject;}
			void set(string^ Subject){subject=Subject;}
		}
		property System::DateTime ODateTime
		{
			System::DateTime get(){return odatetime;}
			void set(System::DateTime ODateTime){odatetime=ODateTime;}
		}
		property System::DateTime DDateTime
		{
			System::DateTime get(){return ddatetime;}
			void set(System::DateTime DDateTime){ddatetime=DDateTime;}
		}
		property string^ Area
		{
			string^ get(){return area;}
			void set(string^ Area){area=Area;}
		}
		property string^ MSGID
		{
			string^ get(){return msgid;}
			void set(string^ MSGID){msgid=MSGID;}
		}
	};

	public ref class rtlNodelist
	{
		private: string^ id;
		private: string^ parentid;
		private: string^ station;
		private: string^ place;
		private: string^ dname;
		private: string^ phone;
		public: rtlNodelist(string^ ID, string^ ParentID, string^ Station,
					string^ Place, string^ DName, string^ Phone)
		{
			id = ID;
			parentid = ParentID;
			station = Station;
			place = Place;
			dname = DName;
			phone = Phone;
		}
		property string^ ID
		{
			string^ get(){return id;}
			void set(string^ ID){id=ID;}
		}
		property string^ ParentID
		{
			string^ get(){return parentid;}
			void set(string^ ParentID){parentid=ParentID;}
		}
		property string^ DAddr
		{
			string^ get(){return id;}
			void set(string^ DAddr){id=DAddr;}
		}
		property string^ Station
		{
			string^ get(){return station;}
			void set(string^ Station){station=Station;}
		}
		property string^ Place
		{
			string^ get(){return place;}
			void set(string^ Place){place=Place;}
		}
		property string^ DName
		{
			string^ get(){return dname;}
			void set(string^ DName){dname=DName;}
		}
		property string^ Phone
		{
			string^ get(){return phone;}
			void set(string^ Phone){phone=Phone;}
		}
	};

	public ref class LayoutLoc: public DevExpress::XtraLayout::Localization::LayoutLocalizer
	{
		public: Hashtable^ htStrings;
		public: virtual string^ GetLocalizedString(DevExpress::XtraLayout::Localization::LayoutStringId id) override
		{
			switch(id)
			{
				case DevExpress::XtraLayout::Localization::LayoutStringId::AddTabMenuText: return (string^)htStrings[L"AddTabMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::ControlGroupDefaultText: return (string^)htStrings[L"ControlGroupDefaultText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::CreateEmptySpaceItem: return (string^)htStrings[L"CreateEmptySpaceItem"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::CreateTabbedGroupMenuText: return (string^)htStrings[L"CreateTabbedGroupMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::CustomizationFormTitle: return (string^)htStrings[L"CustomizationFormTitle"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::CustomizationParentName: return (string^)htStrings[L"CustomizationParentName"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::DefaultActionText: return (string^)htStrings[L"DefaultActionText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::DefaultEmptyText: return (string^)htStrings[L"DefaultEmptyText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::DefaultItemText: return (string^)htStrings[L"DefaultItemText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::EmptyRootGroupText: return (string^)htStrings[L"EmptyRootGroupText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::EmptySpaceItemDefaultText: return (string^)htStrings[L"EmptySpaceItemDefaultText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::EmptyTabbedGroupText: return (string^)htStrings[L"EmptyTabbedGroupText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::FreeSizingMenuItem: return (string^)htStrings[L"FreeSizingMenuItem"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::GroupItemsMenuText: return (string^)htStrings[L"GroupItemsMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::HiddenItemsPageTitle: return (string^)htStrings[L"HiddenItemsPageTitle"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::HideCustomizationFormMenuText: return (string^)htStrings[L"HideCustomizationFormMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::HideItemMenutext: return (string^)htStrings[L"HideItemMenutext"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::HideTextMenuItem: return (string^)htStrings[L"HideTextMenuItem"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::LayoutControlDescription: return (string^)htStrings[L"LayoutControlDescription"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::LayoutGroupDescription: return (string^)htStrings[L"LayoutGroupDescription"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::LayoutItemDescription: return (string^)htStrings[L"LayoutItemDescription"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::LoadButtonHintText: return (string^)htStrings[L"LoadButtonHintText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::LoadHintCaption: return (string^)htStrings[L"LoadHintCaption"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::LockHeightMenuItem: return (string^)htStrings[L"LockHeightMenuItem"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::LockItemSizeMenuText: return (string^)htStrings[L"LockItemSizeMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::LockMenuGroup: return (string^)htStrings[L"LockMenuGroup"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::LockSizeMenuItem: return (string^)htStrings[L"LockSizeMenuItem"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::LockWidthMenuItem: return (string^)htStrings[L"LockWidthMenuItem"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::RedoButtonHintText: return (string^)htStrings[L"RedoButtonHintText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::RedoHintCaption: return (string^)htStrings[L"RedoHintCaption"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::RenameMenuText: return (string^)htStrings[L"RenameMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::RenameSelected: return (string^)htStrings[L"RenameSelected"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::ResetConstraintsToDefaultsMenuItem: return (string^)htStrings[L"ResetConstraintsToDefaultsMenuItem"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::ResetLayoutMenuText: return (string^)htStrings[L"ResetLayoutMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::SaveButtonHintText: return (string^)htStrings[L"SaveButtonHintText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::SaveHintCaption: return (string^)htStrings[L"SaveHintCaption"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::ShowCustomizationFormMenuText: return (string^)htStrings[L"ShowCustomizationFormMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::ShowTextMenuItem: return (string^)htStrings[L"ShowTextMenuItem"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::SplitterItemDefaultText: return (string^)htStrings[L"SplitterItemDefaultText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::TabbedGroupDescription: return (string^)htStrings[L"TabbedGroupDescription"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::TextPositionBottomMenuText: return (string^)htStrings[L"TextPositionBottomMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::TextPositionLeftMenuText: return (string^)htStrings[L"TextPositionLeftMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::TextPositionMenuText: return (string^)htStrings[L"TextPositionMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::TextPositionRightMenuText: return (string^)htStrings[L"TextPositionRightMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::TextPositionTopMenuText: return (string^)htStrings[L"TextPositionTopMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::TreeViewPageTitle: return (string^)htStrings[L"TreeViewPageTitle"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::TreeViewRootNodeName: return (string^)htStrings[L"TreeViewRootNodeName"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::UndoButtonHintText: return (string^)htStrings[L"UndoButtonHintText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::UndoHintCaption: return (string^)htStrings[L"UndoHintCaption"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::UnGroupItemsMenuText: return (string^)htStrings[L"UnGroupItemsMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::UnGroupTabbedGroupMenuText: return (string^)htStrings[L"UnGroupTabbedGroupMenuText"];
				case DevExpress::XtraLayout::Localization::LayoutStringId::UnLockItemSizeMenuText: return (string^)htStrings[L"UnLockItemSizeMenuText"];
			}
			return L"";
		}
		public: LayoutLoc()
		{
			htStrings = gcnew Hashtable();

			htStrings->Add(L"AddTabMenuText",L"");
			htStrings->Add(L"ControlGroupDefaultText",L"");
			htStrings->Add(L"CreateEmptySpaceItem",L"");
			htStrings->Add(L"CreateTabbedGroupMenuText",L"");
			htStrings->Add(L"CustomizationFormTitle",L"");
			htStrings->Add(L"CustomizationParentName",L"");
			htStrings->Add(L"DefaultActionText",L"");
			htStrings->Add(L"DefaultEmptyText",L"");
			htStrings->Add(L"DefaultItemText",L"");
			htStrings->Add(L"EmptyRootGroupText",L"");
			htStrings->Add(L"EmptySpaceItemDefaultText",L"");
			htStrings->Add(L"EmptyTabbedGroupText",L"");
			htStrings->Add(L"FreeSizingMenuItem",L"");
			htStrings->Add(L"GroupItemsMenuText",L"");
			htStrings->Add(L"HiddenItemsPageTitle",L"");
			htStrings->Add(L"HideCustomizationFormMenuText",L"");
			htStrings->Add(L"HideItemMenutext",L"");
			htStrings->Add(L"HideTextMenuItem",L"");
			htStrings->Add(L"LayoutControlDescription",L"");
			htStrings->Add(L"LayoutGroupDescription",L"");
			htStrings->Add(L"LayoutItemDescription",L"");
			htStrings->Add(L"LoadButtonHintText",L"");
			htStrings->Add(L"LoadHintCaption",L"");
			htStrings->Add(L"LockHeightMenuItem",L"");
			htStrings->Add(L"LockItemSizeMenuText",L"");
			htStrings->Add(L"LockMenuGroup",L"");
			htStrings->Add(L"LockSizeMenuItem",L"");
			htStrings->Add(L"LockWidthMenuItem",L"");
			htStrings->Add(L"RedoButtonHintText",L"");
			htStrings->Add(L"RedoHintCaption",L"");
			htStrings->Add(L"RenameMenuText",L"");
			htStrings->Add(L"RenameSelected",L"");
			htStrings->Add(L"ResetConstraintsToDefaultsMenuItem",L"");
			htStrings->Add(L"ResetLayoutMenuText",L"");
			htStrings->Add(L"SaveButtonHintText",L"");
			htStrings->Add(L"SaveHintCaption",L"");
			htStrings->Add(L"ShowCustomizationFormMenuText",L"");
			htStrings->Add(L"ShowTextMenuItem",L"");
			htStrings->Add(L"SplitterItemDefaultText",L"");
			htStrings->Add(L"TabbedGroupDescription",L"");
			htStrings->Add(L"TextPositionBottomMenuText",L"");
			htStrings->Add(L"TextPositionLeftMenuText",L"");
			htStrings->Add(L"TextPositionMenuText",L"");
			htStrings->Add(L"TextPositionRightMenuText",L"");
			htStrings->Add(L"TextPositionTopMenuText",L"");
			htStrings->Add(L"TreeViewPageTitle",L"");
			htStrings->Add(L"TreeViewRootNodeName",L"");
			htStrings->Add(L"UndoButtonHintText",L"");
			htStrings->Add(L"UndoHintCaption",L"");
			htStrings->Add(L"UnGroupItemsMenuText",L"");
			htStrings->Add(L"UnGroupTabbedGroupMenuText",L"");
			htStrings->Add(L"UnLockItemSizeMenuText",L"");
		}
	};
	public ref class BarLoc: public DevExpress::XtraBars::Localization::BarLocalizer
	{
		public: Hashtable^ htStrings;
		public: virtual string^ GetLocalizedString(DevExpress::XtraBars::Localization::BarString id) override
		{
			switch(id)
			{
				case DevExpress::XtraBars::Localization::BarString::AddOrRemove: return (string^)htStrings[L"AddOrRemove"];
				case DevExpress::XtraBars::Localization::BarString::BarAllItems: return (string^)htStrings[L"BarAllItems"];
				case DevExpress::XtraBars::Localization::BarString::BarUnassignedItems: return (string^)htStrings[L"BarUnassignedItems"];
				case DevExpress::XtraBars::Localization::BarString::CustomizeButton: return (string^)htStrings[L"CustomizeButton"];
				case DevExpress::XtraBars::Localization::BarString::CustomizeWindowCaption: return (string^)htStrings[L"CustomizeWindowCaption"];
				case DevExpress::XtraBars::Localization::BarString::MenuAnimationFade: return (string^)htStrings[L"MenuAnimationFade"];
				case DevExpress::XtraBars::Localization::BarString::MenuAnimationNone: return (string^)htStrings[L"MenuAnimationNone"];
				case DevExpress::XtraBars::Localization::BarString::MenuAnimationRandom: return (string^)htStrings[L"MenuAnimationRandom"];
				case DevExpress::XtraBars::Localization::BarString::MenuAnimationSlide: return (string^)htStrings[L"MenuAnimationSlide"];
				case DevExpress::XtraBars::Localization::BarString::MenuAnimationSystem: return (string^)htStrings[L"MenuAnimationSystem"];
				case DevExpress::XtraBars::Localization::BarString::MenuAnimationUnfold: return (string^)htStrings[L"MenuAnimationUnfold"];
				case DevExpress::XtraBars::Localization::BarString::NewMenuName: return (string^)htStrings[L"NewMenuName"];
				case DevExpress::XtraBars::Localization::BarString::NewStatusBarName: return (string^)htStrings[L"NewStatusBarName"];
				case DevExpress::XtraBars::Localization::BarString::NewToolbarCaption: return (string^)htStrings[L"NewToolbarCaption"];
				case DevExpress::XtraBars::Localization::BarString::NewToolbarCustomNameFormat: return (string^)htStrings[L"NewToolbarCustomNameFormat"];
				case DevExpress::XtraBars::Localization::BarString::NewToolbarName: return (string^)htStrings[L"NewToolbarName"];
				case DevExpress::XtraBars::Localization::BarString::None: return (string^)htStrings[L"None"];
				case DevExpress::XtraBars::Localization::BarString::PopupMenuEditor: return (string^)htStrings[L"PopupMenuEditor"];
				case DevExpress::XtraBars::Localization::BarString::RenameToolbarCaption: return (string^)htStrings[L"RenameToolbarCaption"];
				case DevExpress::XtraBars::Localization::BarString::ResetBar: return (string^)htStrings[L"ResetBar"];
				case DevExpress::XtraBars::Localization::BarString::ResetBarCaption: return (string^)htStrings[L"ResetBarCaption"];
				case DevExpress::XtraBars::Localization::BarString::ResetButton: return (string^)htStrings[L"ResetButton"];
				
				case DevExpress::XtraBars::Localization::BarString::ToolBarMenu: return (string^)htStrings[L"ToolBarMenu"];
				case DevExpress::XtraBars::Localization::BarString::ToolbarNameCaption: return (string^)htStrings[L"ToolbarNameCaption"];
			}
			return L"";
		}
		public: BarLoc()
		{
			htStrings = gcnew Hashtable();
			htStrings->Add(L"AddOrRemove",L"");
			htStrings->Add(L"BarAllItems",L"");
			htStrings->Add(L"BarUnassignedItems",L"");
			htStrings->Add(L"CustomizeButton",L"");
			htStrings->Add(L"CustomizeWindowCaption",L"");
			htStrings->Add(L"MenuAnimationFade",L"");
			htStrings->Add(L"MenuAnimationNone",L"");
			htStrings->Add(L"MenuAnimationRandom",L"");
			htStrings->Add(L"MenuAnimationSlide",L"");
			htStrings->Add(L"MenuAnimationSystem",L"");
			htStrings->Add(L"MenuAnimationUnfold",L"");
			htStrings->Add(L"NewMenuName",L"");
			htStrings->Add(L"NewStatusBarName",L"");
			htStrings->Add(L"NewToolbarCaption",L"");
			htStrings->Add(L"NewToolbarCustomNameFormat",L"");
			htStrings->Add(L"NewToolbarName",L"");
			htStrings->Add(L"None",L"");
			htStrings->Add(L"PopupMenuEditor",L"");
			htStrings->Add(L"RenameToolbarCaption",L"");
			htStrings->Add(L"ResetBar",L"");
			htStrings->Add(L"ResetBarCaption",L"");
			htStrings->Add(L"ResetButton",L"");
			htStrings->Add(L"ToolBarMenu",L"");
			htStrings->Add(L"ToolbarNameCaption",L"");
		}
	};

	public ref class TreeListLoc: public DevExpress::XtraTreeList::Localization::TreeListLocalizer
	{
		public: Hashtable^ htStrings;
		public: virtual string^ GetLocalizedString(DevExpress::XtraTreeList::Localization::TreeListStringId id) override
		{
			switch(id)
			{
				case DevExpress::XtraTreeList::Localization::TreeListStringId::MenuColumnBestFit: return (string^)htStrings[L"MenuColumnBestFit"];
				case DevExpress::XtraTreeList::Localization::TreeListStringId::MenuColumnBestFitAllColumns: return (string^)htStrings[L"MenuColumnBestFitAllColumns"];
				case DevExpress::XtraTreeList::Localization::TreeListStringId::MenuColumnColumnCustomization: return (string^)htStrings[L"MenuColumnColumnCustomization"];
				case DevExpress::XtraTreeList::Localization::TreeListStringId::MenuColumnSortAscending: return (string^)htStrings[L"MenuColumnSortAscending"];
				case DevExpress::XtraTreeList::Localization::TreeListStringId::MenuColumnSortDescending: return (string^)htStrings[L"MenuColumnSortDescending"];
				case DevExpress::XtraTreeList::Localization::TreeListStringId::ColumnCustomizationText: return (string^)htStrings[L"ColumnCustomizationText"];
			}
			return L"";
		}
		public: TreeListLoc()
		{
			htStrings = gcnew Hashtable();
			htStrings->Add(L"TextEditMenuCopy",L"");
			htStrings->Add(L"ColumnCustomizationText",L"");
			htStrings->Add(L"MenuColumnBestFit",L"");
			htStrings->Add(L"MenuColumnBestFitAllColumns",L"");
			htStrings->Add(L"MenuColumnSortAscending",L"");
			htStrings->Add(L"MenuColumnSortDescending",L"");
			htStrings->Add(L"MenuColumnColumnCustomization",L"");
		}
    };

	public ref class SpellCheckerLoc: public DevExpress::XtraSpellChecker::Localization::SpellCheckerLocalizer
	{
		public: Hashtable^ htStrings;
		public: virtual string^ GetLocalizedString(DevExpress::XtraSpellChecker::Localization::SpellCheckerStringId id) override
		{
			switch(id)
			{
				case DevExpress::XtraSpellChecker::Localization::SpellCheckerStringId::ListBoxNoSuggestions: return (string^)htStrings[L"ListBoxNoSuggestions"];
				case DevExpress::XtraSpellChecker::Localization::SpellCheckerStringId::MnuAddtoDictionaryCaption: return (string^)htStrings[L"MnuAddtoDictionaryCaption"];
				case DevExpress::XtraSpellChecker::Localization::SpellCheckerStringId::MnuDeleteRepeatedWord: return (string^)htStrings[L"MnuDeleteRepeatedWord"];
				case DevExpress::XtraSpellChecker::Localization::SpellCheckerStringId::MnuIgnoreAllItemCaption: return (string^)htStrings[L"MnuIgnoreAllItemCaption"];
				case DevExpress::XtraSpellChecker::Localization::SpellCheckerStringId::MnuIgnoreRepeatedWord: return (string^)htStrings[L"MnuIgnoreRepeatedWord"];
				case DevExpress::XtraSpellChecker::Localization::SpellCheckerStringId::MnuItemCaption: return (string^)htStrings[L"MnuItemCaption"];
				case DevExpress::XtraSpellChecker::Localization::SpellCheckerStringId::MnuNoSuggestionsCaption: return (string^)htStrings[L"MnuNoSuggestionsCaption"];
				case DevExpress::XtraSpellChecker::Localization::SpellCheckerStringId::MsgBoxCaption: return (string^)htStrings[L"MsgBoxCaption"];
				case DevExpress::XtraSpellChecker::Localization::SpellCheckerStringId::MsgBoxCheckNotSelectedText: return (string^)htStrings[L"MsgBoxCheckNotSelectedText"];
				case DevExpress::XtraSpellChecker::Localization::SpellCheckerStringId::MsgBoxFinishCheck: return (string^)htStrings[L"MsgBoxFinishCheck"];
				case DevExpress::XtraSpellChecker::Localization::SpellCheckerStringId::MsgCanUseCurrentWord: return (string^)htStrings[L"MsgCanUseCurrentWord"];
			}
			return L"";
		}
		public: SpellCheckerLoc()
		{
			htStrings = gcnew Hashtable();

			htStrings->Add(L"ListBoxNoSuggestions",L"");
			htStrings->Add(L"MnuAddtoDictionaryCaption",L"");
			htStrings->Add(L"MnuDeleteRepeatedWord",L"");
			htStrings->Add(L"MnuIgnoreAllItemCaption",L"");
			htStrings->Add(L"MnuIgnoreRepeatedWord",L"");
			htStrings->Add(L"MnuItemCaption",L"");
			htStrings->Add(L"MnuNoSuggestionsCaption",L"");
			htStrings->Add(L"MsgBoxCaption",L"");
			htStrings->Add(L"MsgBoxCheckNotSelectedText",L"");
			htStrings->Add(L"MsgBoxFinishCheck",L"");
			htStrings->Add(L"MsgCanUseCurrentWord",L"");
		}
    };

	public ref class EditorLoc: public DevExpress::XtraEditors::Controls::Localizer
	{
		public: Hashtable^ htStrings;
		public: virtual string^ GetLocalizedString(DevExpress::XtraEditors::Controls::StringId id) override
		{
			switch(id)
			{
				case DevExpress::XtraEditors::Controls::StringId::TextEditMenuCopy: return (string^)htStrings[L"TextEditMenuCopy"];
				case DevExpress::XtraEditors::Controls::StringId::TextEditMenuCut: return (string^)htStrings[L"TextEditMenuCut"];
				case DevExpress::XtraEditors::Controls::StringId::TextEditMenuDelete: return (string^)htStrings[L"TextEditMenuDelete"];
				case DevExpress::XtraEditors::Controls::StringId::TextEditMenuPaste: return (string^)htStrings[L"TextEditMenuPaste"];
				case DevExpress::XtraEditors::Controls::StringId::TextEditMenuSelectAll: return (string^)htStrings[L"TextEditMenuSelectAll"];
				case DevExpress::XtraEditors::Controls::StringId::TextEditMenuUndo: return (string^)htStrings[L"TextEditMenuUndo"];
				case DevExpress::XtraEditors::Controls::StringId::XtraMessageBoxYesButtonText: return (string^)htStrings[L"XtraMessageBoxYesButtonText"];
				case DevExpress::XtraEditors::Controls::StringId::XtraMessageBoxNoButtonText: return (string^)htStrings[L"XtraMessageBoxNoButtonText"];
				case DevExpress::XtraEditors::Controls::StringId::XtraMessageBoxOkButtonText: return (string^)htStrings[L"OK"];
				case DevExpress::XtraEditors::Controls::StringId::XtraMessageBoxCancelButtonText: return (string^)htStrings[L"Cancel"];
				case DevExpress::XtraEditors::Controls::StringId::DateEditClear: return (string^)htStrings[L"DateEditClear"];
				case DevExpress::XtraEditors::Controls::StringId::DateEditToday: return (string^)htStrings[L"DateEditToday"];
				case DevExpress::XtraEditors::Controls::StringId::OK: return (string^)htStrings[L"OK"];
				case DevExpress::XtraEditors::Controls::StringId::Cancel: return (string^)htStrings[L"Cancel"];
			}
			return L"";
		}
		public: EditorLoc()
		{
			htStrings = gcnew Hashtable();
			htStrings->Add(L"TextEditMenuCopy",L"");
			htStrings->Add(L"TextEditMenuCut",L"");
			htStrings->Add(L"TextEditMenuDelete",L"");
			htStrings->Add(L"TextEditMenuPaste",L"");
			htStrings->Add(L"TextEditMenuSelectAll",L"");
			htStrings->Add(L"TextEditMenuUndo",L"");
			htStrings->Add(L"XtraMessageBoxYesButtonText",L"");
			htStrings->Add(L"XtraMessageBoxNoButtonText",L"");
			htStrings->Add(L"XtraMessageBoxOkButtonText",L"");
			htStrings->Add(L"XtraMessageBoxCancelButtonText",L"");
			htStrings->Add(L"DateEditClear",L"");
			htStrings->Add(L"DateEditToday",L"");
			htStrings->Add(L"OK",L"");
			htStrings->Add(L"Cancel",L"");
		}
	};
}