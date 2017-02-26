using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LocalNote
{
    public class NotesModel
    {
        public string Title { get; set; }
        public string Body { get; set; }

        public NotesModel(string title, string body)
        {
            Title = title;
            Body = body;
        }

    }
}
