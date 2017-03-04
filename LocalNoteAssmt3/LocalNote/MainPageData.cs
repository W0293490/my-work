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

        public List<NotesModel> _allNotes = new List<NotesModel>();

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

        public ObservableCollection<NotesModel> Notes { get; set; }

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

        //Notes.Add(new NotesModel("First Note", "This is the body of the first note...Lorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean dui est, placerat ac nulla et, semper blandit enim. Sed scelerisque scelerisque velit, quis scelerisque sem euismod quis. Suspendisse viverra tincidunt orci, non vehicula metus tincidunt eget. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Donec facilisis at enim non aliquam. Vivamus tincidunt ligula felis, in interdum urna semper id. Maecenas est nisi, sagittis sed vestibulum vitae, condimentum sed diam. Donec tristique condimentum est nec convallis. Aenean accumsan dolor ultricies turpis dapibus, molestie vestibulum nisi venenatis. Nulla ut magna facilisis, commodo diam quis, iaculis ante. "));
        //    Notes.Add(new NotesModel("Second Note", "This is the body of the second note..."));
        //    Notes.Add(new NotesModel("Third Note", "This is the body of the 3rd note..."));
        //    Notes.Add(new NotesModel("Fourth Note", "This is the body of note four..."));

        //    _allNotes.Add(new NotesModel("First Note", "This is the body of the first note...\nLorem ipsum dolor sit amet, consectetur adipiscing elit. Aenean dui est, placerat ac nulla et, semper blandit enim. Sed scelerisque scelerisque velit, quis scelerisque sem euismod quis. Suspendisse viverra tincidunt orci, non vehicula metus tincidunt eget. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos. Donec facilisis at enim non aliquam. Vivamus tincidunt ligula felis, in interdum urna semper id. Maecenas est nisi, sagittis sed vestibulum vitae, condimentum sed diam. Donec tristique condimentum est nec convallis. Aenean accumsan dolor ultricies turpis dapibus, molestie vestibulum nisi venenatis. Nulla ut magna facilisis, commodo diam quis, iaculis ante. "));
        //    _allNotes.Add(new NotesModel("Second Note", "This is the body of the second note..."));
        //    _allNotes.Add(new NotesModel("Third Note", "This is the body of the 3rd note..."));
        //    _allNotes.Add(new NotesModel("Fourth Note", "This is the body of note four..."));

            PerformFiltering();
        }

        public NotesModel _selectedNote;

        public event PropertyChangedEventHandler PropertyChanged;

        public NotesModel SelectedNote
        {
            get { return _selectedNote; }
            set
            {
                _selectedNote = value;

                if (value == null)
                {
                    TestString = "No Note Selected";
                    NoteName = "No Note Selected";
                }
                else
                {
                    TestString = value.Body;
                    NoteName = "Current Note: " + value.Title;
                }
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
