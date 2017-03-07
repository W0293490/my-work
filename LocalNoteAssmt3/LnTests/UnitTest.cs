using System;
using Microsoft.VisualStudio.TestPlatform.UnitTestFramework;
using LocalNote;
using System.Threading.Tasks;
using Windows.Storage;

namespace NotesTest
{


    [TestClass]
    public class UnitTest1
    {
        static Windows.Storage.StorageFolder storageFolder = Windows.Storage.ApplicationData.Current.LocalFolder;
        MainPageData mpd = new MainPageData();



        [TestMethod]
        public void Test1AddToList()//tests adding notes to list, or observable collection
        {
            mpd.Notes.Add(new NotesModel("title", "body"));

            Assert.AreEqual("title", mpd.Notes[0].Title, "Note not added...");
            Assert.AreEqual("body", mpd.Notes[0].Body, "Note not added...");
        }




        [TestMethod]
        public async Task Test2AddFile()//tests create, read, and update of file
        {
            string title = "title";
            string body = "body";
            var folder = Windows.Storage.ApplicationData.Current.LocalFolder;
            var query = folder.CreateFileQuery();
            var files = await query.GetFilesAsync();
            Windows.Storage.StorageFile sampleFile =
                        await storageFolder.CreateFileAsync(title,
                            Windows.Storage.CreationCollisionOption.ReplaceExisting);

            await storageFolder.GetFileAsync(title);
            await Windows.Storage.FileIO.WriteTextAsync(sampleFile, body);

            foreach (Windows.Storage.StorageFile file in files)
            {
                string text = await Windows.Storage.FileIO.ReadTextAsync(file);
                Assert.AreEqual(title, file.Name, "Name not saved...");
                Assert.AreEqual(body, text, "Body not saved...");
            }
        }




        [TestMethod]
        public void Test3SameName()//tests checking if name already exists
        {
            mpd.Notes.Add(new NotesModel("title", "body"));
            
            string SaveName = "title";

            Assert.AreEqual(SaveName, mpd.Notes[0].Title, "Name not the same...");
        }




        [TestMethod]
        public async Task Test4Delete()//tests deleting a file, or note
        {
            string title = "title";
            string body = "body";
            Windows.Storage.StorageFile sampleFile =
                        await storageFolder.CreateFileAsync(title,
                            Windows.Storage.CreationCollisionOption.ReplaceExisting);
            //await storageFolder.GetFileAsync(title);
            await Windows.Storage.FileIO.WriteTextAsync(sampleFile, body);

            //NotesModel nm = new NotesModel(title, body);

            //mpd.Notes.RemoveAt(0);

            StorageFile sFile = await storageFolder.GetFileAsync(title);

            await sFile.DeleteAsync();

            //Assert.AreEqual(nm.Title, null, "did not delete...");
            //Assert.AreEqual(nm.Body, null, "did not delete...");

            var folder = Windows.Storage.ApplicationData.Current.LocalFolder;
            var query = folder.CreateFileQuery();
            var files = await query.GetFilesAsync();

            foreach (Windows.Storage.StorageFile file in files)
            {
                string text = await Windows.Storage.FileIO.ReadTextAsync(file);
                Assert.AreEqual(null, file.Name, "Name not deleted...");
                Assert.AreEqual(null, text, "Body not deleted...");
            }
        }



        [TestMethod]
        public void Test5EditBody()//tests editing body of note
        {
            mpd.Notes.Add(new NotesModel("title", "body"));

            mpd.Notes[0].Body = "booty";

            Assert.AreEqual("booty", mpd.Notes[0].Body, "Name not the same...");
        }
    }
}