using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LocalNote
{
    class MainPageData : INotifyPropertyChanged
    {
        private string _testString = "No Note Selected";
        private string _noteName = "No Note Selected";
        private string _noteBody = "";
        public ObservableCollection<NotesModel> Notes { get; set; }

        public ObservableCollection<NotesModel> _allNotes { get; set; }
        

        public event PropertyChangedEventHandler PropertyChanged;

        public string TestString
        {
            get { return _testString; }
            set
            {
                if (value == _testString)
                {
                    return;
                }   
                _testString = value;

                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(TestString)));
                
            }
        }

        public string NoteBody
        {
            get { return _noteBody; }
            set
            {
                if (value == _noteBody)
                {
                    return;
                }
                _noteBody = value;

                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(NoteBody)));

            }
        }

        public string NoteName
        {
            get { return _noteName; }
            set
            {
                if (value == _noteName)
                {
                    return;
                }
                _noteName = value;

                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(NoteName)));

            }
        }

        

        public async void fillList()
        {
            var folder = Windows.Storage.ApplicationData.Current.LocalFolder;
            var query = folder.CreateFileQuery();
            var files = await query.GetFilesAsync();

            foreach (Windows.Storage.StorageFile file in files)
            {
                //StringBuilder fileProperties = new StringBuilder();

                // Get top-level file properties.
                //fileProperties.AppendLine("File name: " + file.Name);
                //fileProperties.AppendLine("File type: " + file.FileType);
                string text = await Windows.Storage.FileIO.ReadTextAsync(file);
                _allNotes.Add(new NotesModel(file.Name, text));
                Notes.Add(new NotesModel(file.Name, text));

            }

        }

        public MainPageData()
        {
            Notes = new ObservableCollection<NotesModel>();

            fillList();

            PerformFiltering();
        }

        public NotesModel _selectedNote;
        
        public NotesModel SelectedNote
        {

            get { return _selectedNote; }
            set
            {
                _selectedNote = value;

                if (value == null)
                {
                    TestString = "No Note Selected";
                    NoteBody = "No Note Selected";
                    NoteName = "No Note Selected";
                }
                else
                {
                    NoteBody = value.Body;
                    NoteName = "Current Note: " + value.Title;
                }
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(NoteBody)));
            }
        }

        private string _filter;

        public string Filter
        {
            get { return _filter; }
            set
            {
                if (value == _filter)
                {
                    return;
                }
                _filter = value;
                PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(nameof(Filter)));

                PerformFiltering();
                    
            }
        }

        private void PerformFiltering()
        {
            _allNotes = new ObservableCollection<NotesModel>();
            if (_filter == null)
                _filter = "";

            var lowerCaseFilter = Filter.ToLowerInvariant().Trim();

            var result =
                _allNotes.Where(d => d.Title.ToLowerInvariant()
                .Contains(lowerCaseFilter))
                .ToList();

            var toRemove = Notes.Except(result).ToList();

            foreach (var x in toRemove)
                Notes.Remove(x);

            var resultCount = result.Count;
            for (int i = 0; i < resultCount; i++)
            {
                var resultItem = result[i];
                if (i + 1 > Notes.Count || !Notes[i].Equals(resultItem))
                    Notes.Insert(i, resultItem);
            }
        }



    }
}
