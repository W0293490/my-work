using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LocalNote
{
    class FileHandler : INotifyPropertyChanged
    {
        public event PropertyChangedEventHandler PropertyChanged;

        //// Create sample file; replace if exists.
        //Windows.Storage.StorageFolder storageFolder =
        //    Windows.Storage.ApplicationData.Current.LocalFolder;
        //Windows.Storage.StorageFile sampleFile =
        //    await storageFolder.CreateFileAsync("sample.txt",
        //        Windows.Storage.CreationCollisionOption.ReplaceExisting);


    }
}
