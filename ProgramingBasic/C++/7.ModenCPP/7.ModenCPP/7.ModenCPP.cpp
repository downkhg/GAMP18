#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Song
{
public :
    wstring title;
    wstring artist;
    Song(wstring artist, wstring title)
    {
        this->title = title;
        this->artist = artist;
    }
};

unique_ptr<Song> SongFactory(const std::wstring& artist, const std::wstring& title)
{
    // Implicit move operation into the variable that stores the result.
    return make_unique<Song>(artist, title);
}

void MakeSongs()
{
    // Create a new unique_ptr with a new object.
    unique_ptr<Song> song = make_unique<Song>(L"Mr. Children", L"Namonaki Uta");

    // Use the unique_ptr.
    vector<wstring> titles = { song->title };

    // Move raw pointer from one unique_ptr to another.
    unique_ptr<Song> song2 = std::move(song);

    // Obtain unique_ptr from function that returns by value.
    auto song3 = SongFactory(L"Michael Jackson", L"Beat It");
}

void SharedPtr()
{
    vector<shared_ptr<Song>> v;

    v.push_back(make_shared<Song>(L"Bob Dylan", L"The Times They Are A Changing"));
    v.push_back(make_shared<Song>(L"Aretha Franklin", L"Bridge Over Troubled Water"));
    v.push_back(make_shared<Song>(L"Thala", L"Entre El Mar y Una Estrella"));

    vector<shared_ptr<Song>> v2;
    remove_copy_if(v.begin(), v.end(), back_inserter(v2), [](shared_ptr<Song> s)
    {
        return s->artist.compare(L"Bob Dylan") == 0;
    });

    for (const auto& s : v2)
    {
        wcout << s->artist << L":" << s->title << endl;
    }
}

void main()
{
    MakeSongs();
    SharedPtr();
}