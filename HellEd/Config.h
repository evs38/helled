
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
#pragma warning(disable:4303)
typedef System::Object object;
typedef System::String string;

using namespace System;
using namespace System::Drawing;
using namespace System::Collections;
using namespace System::ComponentModel;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::IO;
using namespace System::Diagnostics;
using namespace System::Windows::Forms::Design;
using namespace DevExpress::XtraEditors;
using namespace DevExpress::XtraEditors::Repository;
using namespace DevExpress::XtraTreeList::Columns;
using namespace DevExpress::XtraBars;

namespace HellEd
{
	/// <summary>
	/// Summary description for Config.
	/// </summary>
	public ref class Config
	{
		public: ArrayList^ sr;
		public: bool buff;
		public: StreamWriter^ sw;
		public: array<string^> ^CurRow;
		public: array<object^> ^Rows;
		public: int Count;
		public: string^ CurDir;
		public: int	ConfigEncoding;

		public: Config()
		{
			sr = gcnew ArrayList();
		}
		public: bool LoadRow()
		{
			if (sr->Count==0){return false;}
			string^ str = ((StreamReader^)sr[sr->Count-1])->ReadLine();
			if (str)
			{
				if (!str->StartsWith(L"#")&&(str!=L""))
				{
					int count=0;
					int i=0;
					array<string^> ^ values = gcnew array<string^>(32);
					__wchar_t c=0;
					__wchar_t cl=0;
					while (i<str->Length)	
					{	
						cl=c;
						c=str->ToCharArray(0,str->Length)[i];
						while (((c==9)||(c==32))&&(i<str->Length-1))
						{
							i++;
							c=str->ToCharArray()[i];
						}
						if (i<str->Length)
						{
							values[count]="";
							if (c=='"')
							{
								i++;
								cl=c;
								c=str->ToCharArray(0,str->Length)[i];
								i++;
								while ((!((c=='"')&&(cl!='\\')))&&(i<str->Length))
								{
									
values[count]=string::Concat(values[count],c);
									cl=c;
									c=str->ToCharArray()[i];
									i++;
								}
								values[count]=values[count]->Replace(L"\\\\",L"\\");
								values[count]=values[count]->Replace(L"\\\"",L"\"");
							}
							else
							{
								i++;
								while ((c!=9)&&(c!=32)&&(i<str->Length))
								{
									values[count]=string::Concat(values[count],c);
									c=str->ToCharArray()[i];
									i++;
								}
								if (i>=str->Length) {values[count]=string::Concat(values[count],c);}
							}
							count++;
						}
					}
					if (count>0)
					{
						if (values[0]->ToLower()->Equals(L"include"))
						{
							if (count>1)
							{
								Include(values[1]);
								return LoadRow();
							}
							else {return LoadRow();}
						}
						else
						{
							CurRow = gcnew array<string^>(count);
							for (int j=0;j<count;j++){CurRow[j]=values[j];}
							if (buff)
							{
								Rows[Count]=CurRow;
								Count++;
							}
							return true;
						}
					}
					else
					{return LoadRow();}
				}
				else {return LoadRow();}
			}
			else
			{
				((StreamReader^)sr[sr->Count-1])->Close();
				sr->RemoveAt(sr->Count-1);
				if ((sr->Count-1)>=0)
				{return LoadRow();}
				else {return false;}
			}
		}
		public: void Include(string^ FileName)
		{
			string^ str;
			if (sr->Count==0){str=FileName;}
			else
			{
				Uri^ abspath = gcnew Uri(gcnew Uri(CurDir),FileName);
				str = abspath->LocalPath;
			}
			if (File::Exists(str))
			{
				CurDir=string::Concat(Path::GetDirectoryName(str),"\\");
				sr->Add(gcnew StreamReader(str,System::Text::Encoding::GetEncoding(ConfigEncoding)));
			}
		}

		public: void Load(string^ FileName, bool b, int ce)
		{
			buff=b;
			ConfigEncoding=ce;
			if (buff)
			{
				Rows = gcnew array<object^>(100000);
				Count=0;
			}
			Include(FileName);
		}

		public: void Add(string^ Key)
		{
			string^ str="";
			CurRow = gcnew array<string^>(1);
			CurRow[0]=Key;
			if (buff)
			{
				Rows[Count]=CurRow;
				Count++;
			}
			for (int j=0;j<CurRow->Length;j++)
			{
				if ((CurRow[j]->IndexOf(L" ")!=-1)&&!((j==0)&&(CurRow[j]->StartsWith(L"#")))){str=string::Concat(str,L"\"",CurRow[j],L"\"");}
				else {str=string::Concat(str,CurRow[j]);}
				if (j!=CurRow->Length-1){str=string::Concat(str,L" ");}
			}
			sw->WriteLine(str);
		}
		public: void Add(string^ Key, string^ Value)
		{
			string^ str="";
			CurRow = gcnew array<string^>(2);
			CurRow[0]=Key;
			CurRow[1]=Value;
			if (buff)
			{
				Rows[Count]=CurRow;
				Count++;
			}
			for (int j=0;j<CurRow->Length;j++)
			{
				if ((CurRow[j]->IndexOf(L" ")!=-1)&&!((j==0)&&(CurRow[j]->StartsWith(L"#")))){str=string::Concat(str,L"\"",CurRow[j]->Replace(L"\\",L"\\\\")->Replace(L"\"",L"\\\""),L"\"");}
				else {str=string::Concat(str,CurRow[j]);}
				if (j!=CurRow->Length-1){str=string::Concat(str,L" ");}
			}
			sw->WriteLine(str);
		}
		public: void Add(string^ Key, string^ Value1, string^ Value2)
		{
			string^ str="";
			CurRow = gcnew array<string^>(3);
			CurRow[0]=Key;
			CurRow[1]=Value1;
			CurRow[2]=Value2;
			if (buff)
			{
				Rows[Count]=CurRow;
				Count++;
			}
			for (int j=0;j<CurRow->Length;j++)
			{
				if ((CurRow[j]->IndexOf(L" ")!=-1)&&!((j==0)&&(CurRow[j]->StartsWith(L"#")))){str=string::Concat(str,L"\"",CurRow[j],L"\"");}
				else {str=string::Concat(str,CurRow[j]);}
				if (j!=CurRow->Length-1){str=string::Concat(str,L" ");}
			}
			sw->WriteLine(str);
		}
		public: void Add(string^ Key, string^ Value1, string^ Value2, string^ Value3)
		{
			string^ str="";
			CurRow = gcnew array<string^>(4);
			CurRow[0]=Key;
			CurRow[1]=Value1;
			CurRow[2]=Value2;
			CurRow[3]=Value3;
			if (buff)
			{
				Rows[Count]=CurRow;
				Count++;
			}
			for (int j=0;j<CurRow->Length;j++)
			{
				if ((CurRow[j]->IndexOf(L" ")!=-1)&&!((j==0)&&(CurRow[j]->StartsWith(L"#")))){str=string::Concat(str,L"\"",CurRow[j],L"\"");}
				else {str=string::Concat(str,CurRow[j]);}
				if (j!=CurRow->Length-1){str=string::Concat(str,L" ");}
			}
			sw->WriteLine(str);
		}
		public: void Add(string^ Key, string^ Value1, string^ Value2, string^ Value3, string^ Value4)
		{
			string^ str="";
			CurRow = gcnew array<string^>(5);
			CurRow[0]=Key;
			CurRow[1]=Value1;
			CurRow[2]=Value2;
			CurRow[3]=Value3;
			CurRow[4]=Value4;
			if (buff)
			{
				Rows[Count]=CurRow;
				Count++;
			}
			for (int j=0;j<CurRow->Length;j++)
			{
				if ((CurRow[j]->IndexOf(L" ")!=-1)&&!((j==0)&&(CurRow[j]->StartsWith(L"#")))){str=string::Concat(str,L"\"",CurRow[j],L"\"");}
				else {str=string::Concat(str,CurRow[j]);}
				if (j!=CurRow->Length-1){str=string::Concat(str,L" ");}
			}
			sw->WriteLine(str);
		}
		public: void Add(string^ Key, string^ Value1, string^ Value2, string^ Value3, string^ Value4, string^ Value5)
		{
			string^ str="";
			CurRow = gcnew array<string^>(6);
			CurRow[0]=Key;
			CurRow[1]=Value1;
			CurRow[2]=Value2;
			CurRow[3]=Value3;
			CurRow[4]=Value4;
			CurRow[5]=Value5;
			if (buff)
			{
				Rows[Count]=CurRow;
				Count++;
			}
			for (int j=0;j<CurRow->Length;j++)
			{
				if ((CurRow[j]->IndexOf(L" ")!=-1)&&!((j==0)&&(CurRow[j]->StartsWith(L"#")))){str=string::Concat(str,L"\"",CurRow[j],L"\"");}
				else {str=string::Concat(str,CurRow[j]);}
				if (j!=CurRow->Length-1){str=string::Concat(str,L" ");}
			}
			sw->WriteLine(str);
		}

		public: void BeginSave(string^ FileName,bool b, int ce)
		{
			buff=b;
			ConfigEncoding=ce;
			if (buff)
			{
				Rows = gcnew array<object^>(100000);
				Count=0;
			}
			sw = gcnew StreamWriter(FileName,false,System::Text::Encoding::GetEncoding(ConfigEncoding));
		}
		public: void EndSave()
		{
			sw->Close();
			if (buff)
			{
				array<object^> ^ temp = gcnew array<object^>(Count);
				for(int i=0;i<Count;i++){temp[i]=Rows[i];}
				Rows=temp;
			}
		}
		public: void EndLoad()
		{
			if (buff)
			{
				array<object^> ^ temp = gcnew array<object^>(Count);
				for(int i=0;i<Count;i++){temp[i]=Rows[i];}
				Rows=temp;
			}
		}
	};
}