﻿#pragma checksum "C:\Users\Sean\Desktop\myWork repo feb 26 17\my-work\LocalNote\LocalNote\MainPage.xaml" "{406ea660-64cf-4c82-b6f0-42d48172a799}" "713BAE23E731F4EEB7E0609E11E7C71A"
//------------------------------------------------------------------------------
// <auto-generated>
//     This code was generated by a tool.
//
//     Changes to this file may cause incorrect behavior and will be lost if
//     the code is regenerated.
// </auto-generated>
//------------------------------------------------------------------------------

namespace LocalNote
{
    partial class MainPage : 
        global::Windows.UI.Xaml.Controls.Page, 
        global::Windows.UI.Xaml.Markup.IComponentConnector,
        global::Windows.UI.Xaml.Markup.IComponentConnector2
    {
        /// <summary>
        /// Connect()
        /// </summary>
        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("Microsoft.Windows.UI.Xaml.Build.Tasks"," 14.0.0.0")]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public void Connect(int connectionId, object target)
        {
            switch(connectionId)
            {
            case 1:
                {
                    this.AbbAdd = (global::Windows.UI.Xaml.Controls.AppBarButton)(target);
                    #line 22 "..\..\..\MainPage.xaml"
                    ((global::Windows.UI.Xaml.Controls.AppBarButton)this.AbbAdd).Click += this.AppBarButton_Click;
                    #line default
                }
                break;
            case 2:
                {
                    this.AbbSave = (global::Windows.UI.Xaml.Controls.AppBarButton)(target);
                    #line 24 "..\..\..\MainPage.xaml"
                    ((global::Windows.UI.Xaml.Controls.AppBarButton)this.AbbSave).Click += this.AppBarButton_Click_1;
                    #line default
                }
                break;
            case 3:
                {
                    this.AbbEdit = (global::Windows.UI.Xaml.Controls.AppBarButton)(target);
                    #line 28 "..\..\..\MainPage.xaml"
                    ((global::Windows.UI.Xaml.Controls.AppBarButton)this.AbbEdit).Click += this.AbbEdit_Click;
                    #line default
                }
                break;
            case 4:
                {
                    this.AbbDel = (global::Windows.UI.Xaml.Controls.AppBarButton)(target);
                    #line 33 "..\..\..\MainPage.xaml"
                    ((global::Windows.UI.Xaml.Controls.AppBarButton)this.AbbDel).Click += this.AbbDel_Click;
                    #line default
                }
                break;
            case 5:
                {
                    this.AbbAbout = (global::Windows.UI.Xaml.Controls.AppBarButton)(target);
                    #line 38 "..\..\..\MainPage.xaml"
                    ((global::Windows.UI.Xaml.Controls.AppBarButton)this.AbbAbout).Click += this.About_Click;
                    #line default
                }
                break;
            case 6:
                {
                    this.AbbExit = (global::Windows.UI.Xaml.Controls.AppBarButton)(target);
                    #line 40 "..\..\..\MainPage.xaml"
                    ((global::Windows.UI.Xaml.Controls.AppBarButton)this.AbbExit).Click += this.AbbExit_Click;
                    #line default
                }
                break;
            case 7:
                {
                    this.textBoxBody = (global::Windows.UI.Xaml.Controls.TextBox)(target);
                }
                break;
            case 8:
                {
                    this.textBox = (global::Windows.UI.Xaml.Controls.TextBox)(target);
                }
                break;
            case 9:
                {
                    this.listView = (global::Windows.UI.Xaml.Controls.ListView)(target);
                    #line 62 "..\..\..\MainPage.xaml"
                    ((global::Windows.UI.Xaml.Controls.ListView)this.listView).SelectionChanged += this.listView_SelectionChanged;
                    #line default
                }
                break;
            default:
                break;
            }
            this._contentLoaded = true;
        }

        [global::System.CodeDom.Compiler.GeneratedCodeAttribute("Microsoft.Windows.UI.Xaml.Build.Tasks"," 14.0.0.0")]
        [global::System.Diagnostics.DebuggerNonUserCodeAttribute()]
        public global::Windows.UI.Xaml.Markup.IComponentConnector GetBindingConnector(int connectionId, object target)
        {
            global::Windows.UI.Xaml.Markup.IComponentConnector returnValue = null;
            return returnValue;
        }
    }
}

