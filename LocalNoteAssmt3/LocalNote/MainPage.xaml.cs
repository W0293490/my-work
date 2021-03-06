﻿using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.Storage;
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
        Windows.Storage.StorageFolder storageFolder = Windows.Storage.ApplicationData.Current.LocalFolder;

        //bool editing = false;
        MainPageData mpd = new MainPageData();
        string SaveName;
        string body;

        public MainPage()
        {
            this.InitializeComponent();
        }

        public void AbbAdd_Click(object sender, RoutedEventArgs e)
        {
            listView.SelectedItems.Clear();
            textBoxBody.Text = "";
            textBoxBody.IsReadOnly = false;
            AbbSave.IsEnabled = true;
        }


        //dialog for trying to save with already chosen name...
        public async void SameNameSaveMessage()
        {
            ContentDialog sameName = new ContentDialog()
            {
                Title = "HEYYYYYY!!:",
                Content = "Please choose a name that has not already been used...",
                PrimaryButtonText = "Ok"
            };

            ContentDialogResult result = await sameName.ShowAsync();
        }

        public async void AppBarButton_Click_1(object sender, RoutedEventArgs e)
        {
            
            var saveTextBox = new TextBox { Width = 200, Height = 10};
            AbbSave.IsEnabled = true;
            body = textBoxBody.Text;
            string currentTitle = mpd.Notes[listView.SelectedIndex].Title;

            if (listView.SelectedItem != null)
            {
                string title = mpd.Notes[listView.SelectedIndex].Title;
                ContentDialog overwriteFileDialog = new ContentDialog()
                {
                    Title = "Overwrite?...",
                    Content = "Are you sure you want to overwrite the current note?",
                    PrimaryButtonText = "Yes",
                    SecondaryButtonText = "Cancel"
                };

                ContentDialogResult result = await overwriteFileDialog.ShowAsync();

                if (result == ContentDialogResult.Primary)
                {

                    Windows.Storage.StorageFile sampleFile =
                            await storageFolder.CreateFileAsync(title,
                                Windows.Storage.CreationCollisionOption.ReplaceExisting);


                    await storageFolder.GetFileAsync(title);
                    await Windows.Storage.FileIO.WriteTextAsync(sampleFile, body);

                    mpd.Notes[listView.SelectedIndex].Body = body;

                    //mpd.Notes.RemoveAt(listView.SelectedIndex);

                    DataContext = mpd;

                }
            }
            else
            { 
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
                    for (int i = 0; i < mpd.Notes.Count; i++)
                    {
                        if (SaveName == mpd.Notes[i].Title)
                        //if (SaveName == "poo")
                        {
                            //Application.Current.Exit();
                            SameNameSaveMessage();
                            return;
                        }
                    }
                    
                    mpd.Notes.Add(new NotesModel(SaveName, body));

                    DataContext = mpd;

                    Windows.Storage.StorageFile sampleFile =
                        await storageFolder.CreateFileAsync(SaveName,
                            Windows.Storage.CreationCollisionOption.ReplaceExisting);


                    await storageFolder.GetFileAsync(SaveName);
                    await FileIO.WriteTextAsync(sampleFile, body);

                }
            }
        }

        public async void About_Click(object sender, RoutedEventArgs e)
        {
            ContentDialog devName = new ContentDialog()
            {
                Title = "Name of developer:",
                Content = "Sean Patrick Ryall",
                PrimaryButtonText = "Ok"
            };

            ContentDialogResult result = await devName.ShowAsync();
        }


        public async void AbbExit_Click(object sender, RoutedEventArgs e)
        {
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


        public void AbbEdit_Click(object sender, RoutedEventArgs e)
        {
            //string title = mpd.Notes[listView.SelectedIndex].Title;
            AbbEdit.IsEnabled = false;
            textBoxBody.IsReadOnly = false;
            AbbSave.IsEnabled = true;
        }

        public async void AbbDel_Click(object sender, RoutedEventArgs e)
        {
            string title = mpd.Notes[listView.SelectedIndex].Title;
            if (title != null)
            {
                StorageFile sFile = await storageFolder.GetFileAsync(title);

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

                    DataContext = mpd;
                    //listView.SelectedItems.Clear();
                    textBoxBody.Text = "";

                    await sFile.DeleteAsync();
                }
            }
        }


        public void listView_SelectionChanged(object sender, SelectionChangedEventArgs e)
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
