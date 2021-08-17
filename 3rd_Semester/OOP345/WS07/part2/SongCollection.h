#ifndef SONG_H
#define SONG_H
#include <string>
#include <vector>

namespace sdds
{
	struct Song
	{
		std::string m_artist;
		std::string m_title;
		std::string m_album;
		double m_price;
		size_t m_year;
		size_t m_length;
	};

	class SongCollection
	{
		std::vector<Song> m_song;
	public:
		SongCollection() {};
		SongCollection(const char* filename);
		void display(std::ostream& out) const;
		void sort(const std::string field);
		void cleanAlbum();
		bool inCollection(const std::string name) const;
		std::list<Song> getSongsForArtist(const std::string artist) const;
	};
	std::ostream& operator<<(std::ostream& out, const Song& theSong);
}
#endif