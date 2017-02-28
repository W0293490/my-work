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

        private List<NotesModel> _allNotes = new List<NotesModel>();

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

        public ObservableCollection<NotesModel> Notes { get; set; }

        public MainPageData()
        {
            Notes = new ObservableCollection<NotesModel>();

            Notes.Add(new NotesModel("First Note", "This is the body of the first note..."));
            Notes.Add(new NotesModel("Second Note", "This is the body of the second note..."));
            Notes.Add(new NotesModel("Third Note", "This is the body of the 3rd note..."));
            Notes.Add(new NotesModel("Fourth Note", "This is the body of note four..."));

            _allNotes.Add(new NotesModel("First Note", "This is the body of the first note..."));
            _allNotes.Add(new NotesModel("Second Note", "This is the body of the second note..."));
            _allNotes.Add(new NotesModel("Third Note", "This is the body of the 3rd note..."));
            _allNotes.Add(new NotesModel("Fourth Note", "This is the body of note four..."));

            PerformFiltering();
        }

        private NotesModel _selectedNote;

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
                }
                else
                {
                    TestString = value.Body;
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
