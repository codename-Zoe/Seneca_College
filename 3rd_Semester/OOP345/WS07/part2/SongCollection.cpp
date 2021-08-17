#include <algorithm>
#include <functional>
#include <numeric>
#include <list>
#include <iomanip>
#include <fstream>
#include <string>
#include "SongCollection.h"

using namespace std;
namespace sdds
{
  size_t totalLength = 0;
	SongCollection::SongCollection(const char* filename) {
    Song song;
    string line;
    fstream file(filename);
    if (!file) {
      throw "Incorrect file name!";
    }
    while (!file.eof()) {
      getline(file, line, '\n');
      song.m_title = line.substr(0, 25);
      line = line.erase(0, 25);
      song.m_artist = line.substr(0, 25);
      line = line.erase(0, 25);
      song.m_album = line.substr(0, 25);
      line = line.erase(0, 25);

     // check if valid number is set to m_year
      try {
        song.m_year = stoi(line.substr(0, 5));
      }
      catch(...){
        song.m_year = 0;
      }
      line = line.erase(0, 5);

      song.m_length = stoi(line.substr(0, 5));
      // accumulate length of song
      totalLength += song.m_length;
      line = line.erase(0, 5);

      song.m_price = stod(line.substr(0, 5));
      line = line.erase(0, 5);

      song.m_title.erase(0, song.m_title.find_first_not_of(' '));
      song.m_title.erase(song.m_title.find_last_not_of(' ') + 1);

      song.m_artist.erase(0, song.m_artist.find_first_not_of(' '));
      song.m_artist.erase(song.m_artist.find_last_not_of(' ') + 1);

      song.m_album.erase(0, song.m_album.find_first_not_of(' '));
      song.m_album.erase(song.m_album.find_last_not_of(' ') + 1);
      m_song.push_back(song);
    }
    file.close();
	}

	void SongCollection::display(std::ostream& out) const {
    for_each(m_song.begin(), m_song.end(), [&out](const Song& song) {out << song << endl; });
    out << std::setw(89) << std::setfill('-') << '\n' << std::setfill(' ');
    out << "| " << std::setw(77) << "Total Listening Time: ";
    out << totalLength / 3600 << ":";
    out << totalLength % 3600 / 60 << ":"; 
    out << totalLength % 3600 % 60 << " |\n";
	}

  // sort the contents by the field given as a parameter
  void SongCollection::sort(const std::string field) {
    if (field == "title") {
      std::sort(m_song.begin(), m_song.end(), [](const Song songG, const Song songL) {
        return songG.m_title < songL.m_title;
        }
      );
    }
    else if (field == "album") {
      std::sort(m_song.begin(), m_song.end(), [](const Song songG, const Song songL) {
        return songG.m_album < songL.m_album;
        }
      );
    }
    else if (field == "length") {
      std::sort(m_song.begin(), m_song.end(), [](const Song songG, const Song songL) {
        return songG.m_length < songL.m_length;
        }
      );
    }
  }

  // replace [None] to blank space
  void SongCollection::cleanAlbum() {
    for_each(m_song.begin(), m_song.end(), [](Song& song) {
      song.m_album == "[None]" ? song.m_album = " " : song.m_album;
    });
  }

  // find the artist name given as a parameter in m_song
  bool SongCollection::inCollection(const std::string field) const {
    auto found = find_if(m_song.begin(), m_song.end(), [=](const Song& song) {return field == song.m_artist; });
    return found != m_song.end();
  }

  // find and store songs of the artist given as a parameter
  std::list<Song> SongCollection::getSongsForArtist(const std::string artist) const {
    list<Song> col_song;
    for_each(m_song.begin(), m_song.end(), [&](const Song& song) {
      if (song.m_artist == artist) {
        col_song.push_back(song);
      }
    });
    return col_song;
  }

	ostream& operator<<(std::ostream& out, const Song& theSong) {
    out << "| " << left << setw(20) << theSong.m_title << " | " << left << setw(15) << theSong.m_artist;
    out << " | " << left << setw(20) << theSong.m_album << " | ";
    if (theSong.m_year == 0) {
      out << right << setw(6) << " ";
    }
    else {
      out << right << setw(6) << theSong.m_year;
    }
    out << " | " << theSong.m_length / 60 << ":" << setw(2) << setfill('0') << theSong.m_length % 60 << setfill(' ') << " | " << theSong.m_price << " |";
    return out;
	}
}