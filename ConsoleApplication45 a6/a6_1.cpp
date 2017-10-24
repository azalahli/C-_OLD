/* Myron Pow, Dave Harden, CS2C, 2/17/2016
Client for FHhashQPwithFind
meant to test if hash table works
I would seriously question the amount of commenting in-main
for this function, especially with the way it's meant to be submitted
I thought my string one didn't work for an hour while missing a commented out
line of code
*/

#include <iostream>
#include "FHhashQPwithFind.h"
#include "EBookEntry.h"
using namespace std;

/*Global function(s)
void printBook
PRE: EBookEntry object
POS: display of object;
*/
void printBook (const EBookEntry &book)
{
        cout << book.getETextNum() 
            << "\n" << book.getCreator().substr(0, 30)
            << "\n" << book.getTitle().substr(0, 100)
            << "\n" << book.getSubject().substr(0, 30) 
            << endl;
}

//int getKey(const EBookEntry & item);
string getKey( const EBookEntry & item);

int Hash(int key);
int Hash(const string & key);
int Hash(const EBookEntry &item);


// main func
// I will note that the example is internally inconsistent,
// and thus modified the client to use the first format shown
// hash_table vs hashTable
// randomIndices is left in camelCase due to the only instances of it
// being in camelCase

int main()
{
    const int NUM_RANDOM_INDICES = 25;
    int randomIndices[NUM_RANDOM_INDICES];
    EBookEntry book;

    //create a QP hash table of EBooks
    //FHhashQPwFind<EBookEntry, int> hash_table; // for ID equality
     FHhashQPwFind<EBookEntry, string> hash_table; // for any string equality


    // we want two books to be identical in different ways:  ID or author
    //EBookEntry::setSortType(EBookEntry::SORT_BY_ID);
     EBookEntry::setSortType(EBookEntry::SORT_BY_CREATOR);
    

    // read the data from file
    EBookEntryReader book_input("catalog-short4.txt");
    if (book_input.readError())
    {
        cout << book_input.getFileName() << " does not work for input" << endl;
        exit(1);
    }

    cout << book_input.getFileName() << endl;
    cout << book_input.getNumBooks() << endl << endl;

    // insert all books into the hash table (if SORT_BY_ID) or fewer (If SORT_BY_CREATOR)
    for (int i = 0; i < book_input.getNumBooks(); i++) 
    {
        hash_table.insert(book_input[i]);
    }

    cout << "random set of ebooks" << endl;

    // generate some random indices into the EBookEntryReader vector
    // display NUM_RANDOM_INDICES books from array
    for (int i = 0; i < NUM_RANDOM_INDICES; i++) 
    {
        randomIndices[i] = rand() % book_input.getNumBooks();
        printBook(book_input[randomIndices[i]]);
        cout << endl;
    }
    cout << endl;
    cout << endl;
    // attempt to find on the selected key
    cout << "The same random books from the hash table " << endl;
    for (int k = 0; k < NUM_RANDOM_INDICES; k++)
    {
        try
        {
            //book = hash_table.find(book_input[randomIndices[k]].getETextNum());
             book = hash_table.find( book_input[ randomIndices[k] ].getCreator() );
            printBook(book);
        }
        catch (...)
        {
            cout << "no.  ";
        }
        cout << endl;
    }
    // test known failures exceptions:
    cout << "Test Failures:"<< endl;
    try
    {
        //book = hash_table.find(-3);
         book = hash_table.find( "Jack Kerouac" );
    }
    catch (...)
    {
        cout << "no.  ";
        cout << endl;
    }

    // more failures
    try
    {
    }
    catch (...)
    {
    }

    try
    {
    }
    catch (...)
    {
    }
}






//GIVEN, just get keys and their author/number

// used for author equality
string getKey( const EBookEntry & item )
{
return item.getCreator() ;
}


/*
// used for ID equality
int getKey( const EBookEntry & item)
{
    return item.getETextNum() ;
}
*/




//HASHING FUNCTIONS GIVEN BY LESSON 6A.2
int Hash(int key) 
{
    return key;
}

int Hash(const string & key) 
{
    unsigned int k, retVal = 0;

    for (k = 0; k < key.length(); k++)
        retVal = 37 * retVal + key[k];

    return retVal;
}





//hash function for ebookentry(s), extrapolated from above
// PRE: EBookEntry
// POS: Hash for that EBookEntry
int Hash(const EBookEntry &item) 
{
    return Hash(getKey(item));
}

/*RUN1(INTS)
catalog-short4.txt
4863

random set of ebooks
28351
(no data found)
Dick and His Cat and Other Tales
Animals -- Juvenile fiction

26271
Newell, Peter, 1862-1924
The Slant Book
Children's poetry

28911
Okakura, Kakuzo, 1862-1913
The Book of Tea
Tea

11250
Sylvester, Charles Herbert
Journeys Through Bookland, Vol. 5
Children's literature

25186
Altsheler, Joseph A. (Joseph A
The Border WatchA Story of the Great Chief's Last Stand
Frontier and pioneer life -- J

19833
Bruno, Giordano, 1548-1600
The Heroic Enthusiasts (Gli Eroici Furori) Part the SecondAn Ethical Poem
(no data found)

29533
Birmingham, George A., 1865-19
The Red Hand of Ulster
Ulster (Northern Ireland and I

28135
Various
The Nursery, July 1877, XXII. No. 1A Monthly Magazine for Youngest Readers
Children's literature, America

4319
Clontz, J.
The Gospels in Four Part Harmony
Bible. N.T. Gospels -- Harmoni

28958
Merwin, Samuel, 1874-1936
The Road to Frontenac
Canada -- History -- To 1763 (

27963
Seeley, Levi, 1847-1928
History of Education
Education -- History

26324
Fletcher, J. S. (Joseph Smith)
Ravensdene Court
Detective and mystery stories

26327
Crawford, F. Marion (Francis M
Casa Braccio, Volumes 1 and 2 (of 2)
Italy -- Fiction

16459
Saint-Sa├½ns, Camille, 1835-19
Musical Memories
Music -- History and criticism

28421
Vasari, Giorgio, 1511-1574
Lives of the Most Eminent Painters Sculptors and ArchitectsVol. 05 ( of 10) Andrea da Fiesole to Lor
Artists -- Italy -- Biography

28438
Shea, Robert, 1933-1994
The Helpful Robots
Science fiction

27740
Haslam, John, 1764-1844
A Letter to the Right Honorable the Lord Chancellor, on the Nature and Interpretation of Unsoundness
Mental illness -- Jurisprudenc

6636
Ryder, Annie H
Hold Up Your Heads, Girls! : Helps for Girls, in School and Out
Girls

24793
Day, Holman, 1865-1935
Blow The Man DownA Romance Of The Coast - 1916
Ship captains -- Fiction

28883
Vincent, Harl, 1893-1968
The Copper-Clad World
Science fiction

27368
Faguet, ├ëmile, 1847-1916
The Cult of Incompetence
Democracy

28823
Meredith, George, 1828-1909
The Works Of George MeredithA Linked Index to the Project Gutenberg Editions
Indexes

26245
Thucydides, 455? BC-395 BC
The History of the Peloponnesian War
Greece -- History -- Peloponne

28964
Keene, Louis
Keene, Louis
World War, 1914-1918 -- Person

30271
Murphy, Arthur, 1727-1805
The Grecian Daughter
English drama



The same random books from the hash table
28351
(no data found)
Dick and His Cat and Other Tales
Animals -- Juvenile fiction

26271
Newell, Peter, 1862-1924
The Slant Book
Children's poetry

28911
Okakura, Kakuzo, 1862-1913
The Book of Tea
Tea

11250
Sylvester, Charles Herbert
Journeys Through Bookland, Vol. 5
Children's literature

25186
Altsheler, Joseph A. (Joseph A
The Border WatchA Story of the Great Chief's Last Stand
Frontier and pioneer life -- J

19833
Bruno, Giordano, 1548-1600
The Heroic Enthusiasts (Gli Eroici Furori) Part the SecondAn Ethical Poem
(no data found)

29533
Birmingham, George A., 1865-19
The Red Hand of Ulster
Ulster (Northern Ireland and I

28135
Various
The Nursery, July 1877, XXII. No. 1A Monthly Magazine for Youngest Readers
Children's literature, America

4319
Clontz, J.
The Gospels in Four Part Harmony
Bible. N.T. Gospels -- Harmoni

28958
Merwin, Samuel, 1874-1936
The Road to Frontenac
Canada -- History -- To 1763 (

27963
Seeley, Levi, 1847-1928
History of Education
Education -- History

26324
Fletcher, J. S. (Joseph Smith)
Ravensdene Court
Detective and mystery stories

26327
Crawford, F. Marion (Francis M
Casa Braccio, Volumes 1 and 2 (of 2)
Italy -- Fiction

16459
Saint-Sa├½ns, Camille, 1835-19
Musical Memories
Music -- History and criticism

28421
Vasari, Giorgio, 1511-1574
Lives of the Most Eminent Painters Sculptors and ArchitectsVol. 05 ( of 10) Andrea da Fiesole to Lor
Artists -- Italy -- Biography

28438
Shea, Robert, 1933-1994
The Helpful Robots
Science fiction

27740
Haslam, John, 1764-1844
A Letter to the Right Honorable the Lord Chancellor, on the Nature and Interpretation of Unsoundness
Mental illness -- Jurisprudenc

6636
Ryder, Annie H
Hold Up Your Heads, Girls! : Helps for Girls, in School and Out
Girls

24793
Day, Holman, 1865-1935
Blow The Man DownA Romance Of The Coast - 1916
Ship captains -- Fiction

28883
Vincent, Harl, 1893-1968
The Copper-Clad World
Science fiction

27368
Faguet, ├ëmile, 1847-1916
The Cult of Incompetence
Democracy

28823
Meredith, George, 1828-1909
The Works Of George MeredithA Linked Index to the Project Gutenberg Editions
Indexes

26245
Thucydides, 455? BC-395 BC
The History of the Peloponnesian War
Greece -- History -- Peloponne

28964
Keene, Louis
Keene, Louis
World War, 1914-1918 -- Person

30271
Murphy, Arthur, 1727-1805
The Grecian Daughter
English drama

Test Failures:
no.
Press any key to continue . . .
*/






/*RUN 2(STRINGS)
catalog-short4.txt
4863

random set of ebooks
28351
(no data found)
Dick and His Cat and Other Tales
Animals -- Juvenile fiction

26271
Newell, Peter, 1862-1924
The Slant Book
Children's poetry

28911
Okakura, Kakuzo, 1862-1913
The Book of Tea
Tea

11250
Sylvester, Charles Herbert
Journeys Through Bookland, Vol. 5
Children's literature

25186
Altsheler, Joseph A. (Joseph A
The Border WatchA Story of the Great Chief's Last Stand
Frontier and pioneer life -- J

19833
Bruno, Giordano, 1548-1600
The Heroic Enthusiasts (Gli Eroici Furori) Part the SecondAn Ethical Poem
(no data found)

29533
Birmingham, George A., 1865-19
The Red Hand of Ulster
Ulster (Northern Ireland and I

28135
Various
The Nursery, July 1877, XXII. No. 1A Monthly Magazine for Youngest Readers
Children's literature, America

4319
Clontz, J.
The Gospels in Four Part Harmony
Bible. N.T. Gospels -- Harmoni

28958
Merwin, Samuel, 1874-1936
The Road to Frontenac
Canada -- History -- To 1763 (

27963
Seeley, Levi, 1847-1928
History of Education
Education -- History

26324
Fletcher, J. S. (Joseph Smith)
Ravensdene Court
Detective and mystery stories

26327
Crawford, F. Marion (Francis M
Casa Braccio, Volumes 1 and 2 (of 2)
Italy -- Fiction

16459
Saint-Sa├½ns, Camille, 1835-19
Musical Memories
Music -- History and criticism

28421
Vasari, Giorgio, 1511-1574
Lives of the Most Eminent Painters Sculptors and ArchitectsVol. 05 ( of 10) Andrea da Fiesole to Lor
Artists -- Italy -- Biography

28438
Shea, Robert, 1933-1994
The Helpful Robots
Science fiction

27740
Haslam, John, 1764-1844
A Letter to the Right Honorable the Lord Chancellor, on the Nature and Interpretation of Unsoundness
Mental illness -- Jurisprudenc

6636
Ryder, Annie H
Hold Up Your Heads, Girls! : Helps for Girls, in School and Out
Girls

24793
Day, Holman, 1865-1935
Blow The Man DownA Romance Of The Coast - 1916
Ship captains -- Fiction

28883
Vincent, Harl, 1893-1968
The Copper-Clad World
Science fiction

27368
Faguet, ├ëmile, 1847-1916
The Cult of Incompetence
Democracy

28823
Meredith, George, 1828-1909
The Works Of George MeredithA Linked Index to the Project Gutenberg Editions
Indexes

26245
Thucydides, 455? BC-395 BC
The History of the Peloponnesian War
Greece -- History -- Peloponne

28964
Keene, Louis
Keene, Louis
World War, 1914-1918 -- Person

30271
Murphy, Arthur, 1727-1805
The Grecian Daughter
English drama



The same random books from the hash table
28351
(no data found)
Dick and His Cat and Other Tales
Animals -- Juvenile fiction

26271
Newell, Peter, 1862-1924
The Slant Book
Children's poetry

28911
Okakura, Kakuzo, 1862-1913
The Book of Tea
Tea

11250
Sylvester, Charles Herbert
Journeys Through Bookland, Vol. 5
Children's literature

17677
Altsheler, Joseph A. (Joseph A
The Tree of Appomattox
(no data found)

19833
Bruno, Giordano, 1548-1600
The Heroic Enthusiasts (Gli Eroici Furori) Part the SecondAn Ethical Poem
(no data found)

24073
Birmingham, George A., 1865-19
General John Regan
Ireland -- Fiction

28712
Various
The American Missionary ΓÇö Volume 54, No. 3, October, 1900
Congregational churches -- Mis

4319
Clontz, J.
The Gospels in Four Part Harmony
Bible. N.T. Gospels -- Harmoni

28958
Merwin, Samuel, 1874-1936
The Road to Frontenac
Canada -- History -- To 1763 (

27963
Seeley, Levi, 1847-1928
History of Education
Education -- History

27965
Fletcher, J. S. (Joseph Smith)
The Chestermarke Instinct
Detective and mystery stories

28600
Crawford, F. Marion (Francis M
Ave Roma Immortalis, Vol. 2Studies from the Chronicles of Rome
Rome (Italy) -- Description an

16459
Saint-Sa├½ns, Camille, 1835-19
Musical Memories
Music -- History and criticism

28420
Vasari, Giorgio, 1511-1574
Lives of the Most Eminent Painters Sculptors and ArchitectsVol. 04 (of 10), Filippino Lippi to Domen
Artists -- Italy -- Biography

28976
Shea, Robert, 1933-1994
Shaman
Sauk Indians -- Fiction

27740
Haslam, John, 1764-1844
A Letter to the Right Honorable the Lord Chancellor, on the Nature and Interpretation of Unsoundness
Mental illness -- Jurisprudenc

6636
Ryder, Annie H
Hold Up Your Heads, Girls! : Helps for Girls, in School and Out
Girls

16631
Day, Holman, 1865-1935
The Skipper and the SkippedBeing the Shore Log of Cap'n Aaron Sproul
(no data found)

29321
Vincent, Harl, 1893-1968
Vulcan's Workshop
Science fiction

27368
Faguet, ├ëmile, 1847-1916
The Cult of Incompetence
Democracy

28823
Meredith, George, 1828-1909
The Works Of George MeredithA Linked Index to the Project Gutenberg Editions
Indexes

26245
Thucydides, 455? BC-395 BC
The History of the Peloponnesian War
Greece -- History -- Peloponne

28964
Keene, Louis
Keene, Louis
World War, 1914-1918 -- Person

30271
Murphy, Arthur, 1727-1805
The Grecian Daughter
English drama

Test Failures:
no.
Press any key to continue . . .
*/