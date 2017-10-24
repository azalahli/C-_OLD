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

int getKey(const EBookEntry & item);
//string getKey( const EBookEntry & item);

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
    srand(time(0));

    //create a QP hash table of EBooks
    FHhashQPwFind<EBookEntry, int> hash_table; // for ID equality
    // FHhashQPwFind<EBookEntry, string> hash_table; // for any string equality


    // we want two books to be identical in different ways:  ID or author
    EBookEntry::setSortType(EBookEntry::SORT_BY_ID);
     //EBookEntry::setSortType(EBookEntry::SORT_BY_CREATOR);
    

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
            book = hash_table.find(book_input[randomIndices[k]].getETextNum());
             //book = hash_table.find( book_input[ randomIndices[k] ].getCreator() );
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
        book = hash_table.find(-3);
        // book = hash_table.find( "Jack Kerouac" );
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
/*
// used for author equality
string getKey( const EBookEntry & item )
{
return item.getCreator() ;
}
*/


// used for ID equality
int getKey( const EBookEntry & item)
{
    return item.getETextNum() ;
}





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
27439
Cobb, Irvin S. (Irvin Shrewsbu
Sundry Accounts
PS

29620
Rocklynne, Ross, 1913-1988
Sorry: Wrong Dimension
Science fiction

29115
Various
Harper's Young People, August 31, 1880An Illustrated Weekly
Children's periodicals, Americ

27971
Mackay, Eric, 1851-1898
A Lover's Litanies
Poetry

3076
Reed, John, 1887-1920
Ten Days That Shook the World
Soviet Union -- History -- Rev

29433
Emerson, Ralph Waldo, 1803-188
Nature
Nature

5742
Chandler, Katherine
The Bird-Woman of the Lewis and Clark Expedition
Readers (Primary)

26860
Vasari, Giorgio, 1511-1574
Lives of the Most Eminent Painters Sculptors and ArchitectsVol. 03 (of 10),  Filarete and Simone to
Artists -- Italy -- Biography

6362
Dos Passos, John, 1896-1970
Three Soldiers
(no data found)

28126
Various
The Christian Foundation, Or, Scientific and Religious Journal, April, 1880
Religion and science -- Period

29853
Andrews, Charles McLean, 1863-
The Fathers of New EnglandA Chronicle of the Puritan Commonwealths
New England -- History -- Colo

9206
Hawthorne, Nathaniel, 1804-186
The Toll Gatherer's Day (From &quot;Twice Told Tales&quot;)
(no data found)

25788
Stephen, Leslie, Sir, 1832-190
The English Utilitarians, Volume II (of 3)James Mill
Mill, James, 1773-1836

27842
Leith, C. K. (Charles Kenneth)
The Economic Aspect of Geology
Geology, Economic

29156
Conrad, Joseph, 1857-1924
The Project Gutenberg Works of Joseph ConradAn Index
Indexes

24940
Various
The Nursery, September 1873, Vol. XIV. No. 3
Children's literature, America

28877
Wiggin, Kate Douglas Smith, 18
Penelope's ProgressBeing Such Extracts from the Commonplace Book of Penelope Hamilton As Relate to H
Americans -- Scotland -- Ficti

26908
Marcet, Mrs. (Jane Haldimand),
Conversations on Chemistry, V. 1-2In Which the Elements of that Science Are FamiliarlyExplained and
Chemistry

28059
Phelps, Elizabeth Stuart, 1844
A Lost Hero
African Americans -- Fiction

26139
Ontario. Ministry of Education
Ontario Teachers' Manuals: Nature Study
Science -- Study and teaching

27373
Moodie, Susanna, 1803-1885
Flora Lyndsayor, Passages in an Eventful Life
PR

5949
Tarkington, Booth, 1869-1946
Beasley's Christmas Party
(no data found)

29513
Marshall, John, 1755-1835
Opinion of the Supreme Court of the United States, at January Term, 1832, Delivered by Mr. Chief Jus
Worcester, S. A. (Samuel Austi

27601
Bindloss, Harold, 1866-1945
Hawtrey's Deputy
PR

29042
Carroll, Lewis, 1832-1898
A Tangled Tale
Mathematical recreations



The same random books from the hash table
27439
Cobb, Irvin S. (Irvin Shrewsbu
Sundry Accounts
PS

29620
Rocklynne, Ross, 1913-1988
Sorry: Wrong Dimension
Science fiction

29115
Various
Harper's Young People, August 31, 1880An Illustrated Weekly
Children's periodicals, Americ

27971
Mackay, Eric, 1851-1898
A Lover's Litanies
Poetry

3076
Reed, John, 1887-1920
Ten Days That Shook the World
Soviet Union -- History -- Rev

29433
Emerson, Ralph Waldo, 1803-188
Nature
Nature

5742
Chandler, Katherine
The Bird-Woman of the Lewis and Clark Expedition
Readers (Primary)

26860
Vasari, Giorgio, 1511-1574
Lives of the Most Eminent Painters Sculptors and ArchitectsVol. 03 (of 10),  Filarete and Simone to
Artists -- Italy -- Biography

6362
Dos Passos, John, 1896-1970
Three Soldiers
(no data found)

28126
Various
The Christian Foundation, Or, Scientific and Religious Journal, April, 1880
Religion and science -- Period

29853
Andrews, Charles McLean, 1863-
The Fathers of New EnglandA Chronicle of the Puritan Commonwealths
New England -- History -- Colo

9206
Hawthorne, Nathaniel, 1804-186
The Toll Gatherer's Day (From &quot;Twice Told Tales&quot;)
(no data found)

25788
Stephen, Leslie, Sir, 1832-190
The English Utilitarians, Volume II (of 3)James Mill
Mill, James, 1773-1836

27842
Leith, C. K. (Charles Kenneth)
The Economic Aspect of Geology
Geology, Economic

29156
Conrad, Joseph, 1857-1924
The Project Gutenberg Works of Joseph ConradAn Index
Indexes

24940
Various
The Nursery, September 1873, Vol. XIV. No. 3
Children's literature, America

28877
Wiggin, Kate Douglas Smith, 18
Penelope's ProgressBeing Such Extracts from the Commonplace Book of Penelope Hamilton As Relate to H
Americans -- Scotland -- Ficti

26908
Marcet, Mrs. (Jane Haldimand),
Conversations on Chemistry, V. 1-2In Which the Elements of that Science Are FamiliarlyExplained and
Chemistry

28059
Phelps, Elizabeth Stuart, 1844
A Lost Hero
African Americans -- Fiction

26139
Ontario. Ministry of Education
Ontario Teachers' Manuals: Nature Study
Science -- Study and teaching

27373
Moodie, Susanna, 1803-1885
Flora Lyndsayor, Passages in an Eventful Life
PR

5949
Tarkington, Booth, 1869-1946
Beasley's Christmas Party
(no data found)

29513
Marshall, John, 1755-1835
Opinion of the Supreme Court of the United States, at January Term, 1832, Delivered by Mr. Chief Jus
Worcester, S. A. (Samuel Austi

27601
Bindloss, Harold, 1866-1945
Hawtrey's Deputy
PR

29042
Carroll, Lewis, 1832-1898
A Tangled Tale
Mathematical recreations

Test Failures:
no.
Press any key to continue . . .
*/






/*RUN 2(STRINGS)
catalog-short4.txt
4863

random set of ebooks
16908
Davis, Richard Harding, 1864-1
Once Upon A Time
(no data found)

28688
MacGregor, Mary Esther Miller,
The Silver Maple
Canada, Northern -- Fiction

22294
Black, Margaret Moyes
Robert Louis Stevenson
Stevenson, Robert Louis, 1850-

13449
Bennett, Arnold, 1867-1931
The Plain Man and His Wife
(no data found)

25488
Peck, George W. (George Wilbur
The Grocery Man And Peck's Bad BoyPeck's Bad Boy and His Pa, No. 2 - 1883
American wit and humor

28115
Altsheler, Joseph A. (Joseph A
The Great Sioux TrailA Story of Mountain and Plain
Dakota Indians -- Fiction

128
Lang, Andrew, 1844-1912
The Arabian Nights
Fairy tales

29422
Schmucker, Samuel Christian, 1
The Meaning of Evolution
Evolution

25710
Ewing, Juliana Horatia Gatty,
Last WordsA Final Collection of Stories
Conduct of life -- Juvenile fi

29024
Andrews, Roy Chapman, 1884-196
Across Mongolian PlainsA Naturalist's Account of China's 'Great Northwest'
Mongolia -- Description and tr

26218
Bonehill, Ralph
The Young Oarsmen of Lakeview
Boats and boating -- Juvenile

6323
(no data found)
The Junior Classics ΓÇö Volume 4
(no data found)

25536
Green, John Richard, 1837-1883
History of the English People, Volume VIII (of 8)Modern England, 1760-1815
Great Britain -- History

29357
(no data found)
Our Young Folks at Home and Abroad
Children's poetry

25030
Various
Lippincott's Magazine, Vol. 22, November, 1878of Popular Literature and Science
AP

28198
(no data found)
A Budget of Christmas Tales by Charles Dickens and Others
Christmas stories

16741
Eastman, Mary H. (Mary Henders
Aunt Phillis's CabinOr, Southern Life As It Is
(no data found)

25457
Korzybski, Alfred, 1879-1950
Manhood of Humanity.
Human beings

26659
James, William, 1842-1910
The Will to Believe : and Other Essays in Popular Philosophy
Philosophy

25472
Paine, Ralph Delahaye, 1871-19
Blackbeard: Buccaneer
Pirates -- Juvenile fiction

29614
Linebarger, Paul Myron Anthony
The Game of Rat and Dragon
Science fiction

25325
Various
The International Monthly, Volume 3, No. 1, April, 1851
Literature, Modern -- 19th cen

5960
Little, Frances, [pseud.], 186
Little Sister Snow
(no data found)

28638
Dunn, J. Allan, (Joseph Allan)
Rimrock Trail
Western stories

26134
Burgon, John William, 1813-188
The Last Twelve Verses of the Gospel According to S. Mark
Bible. N.T. Mark XVI, 9-20 --



The same random books from the hash table
358
Davis, Richard Harding, 1864-1
The Scarlet Car
Automobiles -- Fiction

28688
MacGregor, Mary Esther Miller,
The Silver Maple
Canada, Northern -- Fiction

22294
Black, Margaret Moyes
Robert Louis Stevenson
Stevenson, Robert Louis, 1850-

29860
Bennett, Arnold, 1867-1931
A Great ManA Frolic
Fiction

28970
Peck, George W. (George Wilbur
Works Of George W. PeckA Linked Index to the Project Gutenberg Editions of The&quot;Bad Boy&quot; Se
Indexes

17677
Altsheler, Joseph A. (Joseph A
The Tree of Appomattox
(no data found)

3319
Lang, Andrew, 1844-1912
Letters to Dead Authors
Literature

29422
Schmucker, Samuel Christian, 1
The Meaning of Evolution
Evolution

25710
Ewing, Juliana Horatia Gatty,
Last WordsA Final Collection of Stories
Conduct of life -- Juvenile fi

29024
Andrews, Roy Chapman, 1884-196
Across Mongolian PlainsA Naturalist's Account of China's 'Great Northwest'
Mongolia -- Description and tr

26218
Bonehill, Ralph
The Young Oarsmen of Lakeview
Boats and boating -- Juvenile

28351
(no data found)
Dick and His Cat and Other Tales
Animals -- Juvenile fiction

25536
Green, John Richard, 1837-1883
History of the English People, Volume VIII (of 8)Modern England, 1760-1815
Great Britain -- History

28351
(no data found)
Dick and His Cat and Other Tales
Animals -- Juvenile fiction

28712
Various
The American Missionary ΓÇö Volume 54, No. 3, October, 1900
Congregational churches -- Mis

28351
(no data found)
Dick and His Cat and Other Tales
Animals -- Juvenile fiction

16741
Eastman, Mary H. (Mary Henders
Aunt Phillis's CabinOr, Southern Life As It Is
(no data found)

25457
Korzybski, Alfred, 1879-1950
Manhood of Humanity.
Human beings

11984
James, William, 1842-1910
A Pluralistic UniverseHibbert Lectures at Manchester College on the Present Situation in Philosophy
(no data found)

3099
Paine, Ralph Delahaye, 1871-19
The Old Merchant Marine; A chronicle of American ships and sailors
Merchant marine -- United Stat

29614
Linebarger, Paul Myron Anthony
The Game of Rat and Dragon
Science fiction

28712
Various
The American Missionary ΓÇö Volume 54, No. 3, October, 1900
Congregational churches -- Mis

7523
Little, Frances, [pseud.], 186
The Lady of the Decoration
PZ

28597
Dunn, J. Allan, (Joseph Allan)
A Man to His Mate
PS

26134
Burgon, John William, 1813-188
The Last Twelve Verses of the Gospel According to S. Mark
Bible. N.T. Mark XVI, 9-20 --

Test Failures:
no.
Press any key to continue . . .
*/