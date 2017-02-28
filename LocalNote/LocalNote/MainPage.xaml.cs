using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Navigation;

//Citation for some of the dialog boxes:
//https://docs.microsoft.com/en-us/windows/uwp/controls-and-patterns/dialogs

// The Blank Page item template is documented at http://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace LocalNote
{
    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {

        //bool editing = false;
        MainPageData mpd = new MainPageData();
        string SaveName;

        public MainPage()
        {
            this.InitializeComponent();
            
            
        }

        //VariableSizedWrapGrid conDlg = new Windows.UI.Xaml.Controls.ContentDialog
        //{
        //    Title = "Cpntent Dialog",

        //}

        private void AppBarButton_Click(object sender, RoutedEventArgs e)
        {
            listView.SelectedItems.Clear();
            textBoxBody.Text = "";
            textBoxBody.IsReadOnly = false;


            //var dlg = new Windows.UI.Popups.MessageDialog("Heyy");

            //dlg.ShowAsync();
        }


        //dialog for trying to save with already chosen name...
        private async void SameNameSaveMessage()
        {
            ContentDialog sameName = new ContentDialog()
            {
                Title = "HEYYYYYY!!:",
                Content = "Please choose a name that has not already been used...",
                PrimaryButtonText = "Ok"
            };

            ContentDialogResult result = await sameName.ShowAsync();
        }

        private async void AppBarButton_Click_1(object sender, RoutedEventArgs e)
        {
            var saveTextBox = new TextBox { Width = 200, Height = 10};
            AbbSave.IsEnabled = true;
            string body = textBoxBody.Text;

            ContentDialog saveFileDialog = new ContentDialog()
            {
                Title = "Save As...",
                //Content = "Are you sure you want to save the current note?",
                Content = saveTextBox,
                PrimaryButtonText = "Save",
                SecondaryButtonText = "Cancel"


            };

            ContentDialogResult result = await saveFileDialog.ShowAsync();

            if (result == ContentDialogResult.Primary)
            {
                SaveName = saveTextBox.Text;
                for (int i = 0; i < 4; i++)
                {
                    if (SaveName == mpd.Notes[i].Title)
                    //if (SaveName == "poo")
                    {
                        //Application.Current.Exit();
                        SameNameSaveMessage();
                        return;

                    }
                    else
                        mpd.Notes.Add(new NotesModel(SaveName, body));
                }

            }

            //if (result == ContentDialogResult.Primary)
            //{
            //    //Application.Current.Exit();
            //    mpd._allNotes.Add(new NotesModel("Fifth Note", body));
            //}

            
        }

        private async void About_Click(object sender, RoutedEventArgs e)
        {
            ContentDialog devName = new ContentDialog()
            {
                Title = "Name of developer:",
                Content = "Sean Patrick Ryall",
                PrimaryButtonText = "Ok"
            };

            ContentDialogResult result = await devName.ShowAsync();
        }


    

        private async void AbbExit_Click(object sender, RoutedEventArgs e)
        {

            // Application.Current.Exit();


            ContentDialog exitAppDialog = new ContentDialog()
            {
                Title = "Exit Confirmation",
                Content = "Are you sure you want to exit?",
                PrimaryButtonText = "Yes",
                SecondaryButtonText = "No"
            };

            ContentDialogResult result = await exitAppDialog.ShowAsync();

            if (result == ContentDialogResult.Primary)
            {
                Application.Current.Exit();
            }

        }


        private void AbbEdit_Click(object sender, RoutedEventArgs e)
        {
            AbbEdit.IsEnabled = false;
            textBoxBody.IsReadOnly = false;
            AbbSave.IsEnabled = true;

            //editing = true;
            ////textBoxBody.IsReadOnly = false;
            //while (editing)
            //{
            //    textBoxBody.IsReadOnly = false;
            //    //if (AbbSave == ClickMode)
            //    //{

            //    //}
            //    if (AbbEdit.IsFocusEngaged)
            //    {
            //        textBoxBody.IsReadOnly = true;
            //        editing = false;
            //    }
            //}

        }

        private async void AbbDel_Click(object sender, RoutedEventArgs e)
        {
            ContentDialog deleteFileDialog = new ContentDialog()
            {
                Title = "Note Deletion Confirmation",
                Content = "Are you sure you want to delete this note?",
                PrimaryButtonText = "Yes",
                SecondaryButtonText = "No"
            };

            ContentDialogResult result = await deleteFileDialog.ShowAsync();

            if (result == ContentDialogResult.Primary)
            {
                mpd.Notes.RemoveAt(listView.SelectedIndex);
                listView.SelectedItems.Clear();
                textBoxBody.Text = "";
            }
        }

        private void listView_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            AbbEdit.IsEnabled = true;
            AbbSave.IsEnabled = false;
            AbbDel.IsEnabled = true;
            textBoxBody.IsReadOnly = true;
            if (listView.SelectedItem == null)
            {
                AbbEdit.IsEnabled = false;
                AbbDel.IsEnabled = false;
                AbbSave.IsEnabled = true;
                textBoxBody.IsReadOnly = false;
            }
        }

        

    }
}
