#include <iostream>
#include <string>
#include <vector>
class Media {
public:
virtual void play() const = 0;
virtual std::vector<std::string> getInfo() const = 0;
virtual double getDuration() const = 0;
virtual Media* clone() const = 0;
virtual ~Media() = default;

};

class Song : public Media {
private:
std::string headline;
std::string performer;
double duration;
public:
Song(const std::string& headline,const  std::string& performer, double duration) : headline(headline), performer(performer), duration(duration) {}
void play() const final{
    std::cout << "The song is playing." << std::endl;
}
std::vector<std::string> getInfo() const final{
    std::vector<std::string> info;
    info.push_back(headline);
    info.push_back(performer);
    return info;
}
double getDuration() const final{
    return duration;
}
Media* clone() const
final {
    return new Song(*this);
}
};

class Podcast : public Media {
private:
std::string headline;
std::string host;
std::size_t episodesCount;
double averageDuration;
public:
Podcast(const std::string& headline, const std::string& host, std::size_t episodesCount, double averageDuration) : headline(headline), host(host),episodesCount(episodesCount),averageDuration(averageDuration) {}
void play() const
    {
        std::cout << "The podcast is playing." << std::endl;
    }
std::vector<std::string> getInfo() const {
    std::vector<std::string> info;
    info.push_back(headline);
    info.push_back(host);
    return info;
}
double getDuration() const {
    return averageDuration * episodesCount;
}
Media* clone() const {
    return new Podcast(*this);
}
};

class Audiobook : public Media
{
private:
std::string headline;
std::string author;
double duration;
std::size_t currentPosition;
public:
    Audiobook(const std::string& headline, const std::string& author, double duration, std::size_t currentPosition) : headline(headline), author(author), duration(duration), currentPosition(currentPosition) {}
    void play() const
    {
        std::cout << "The audiobook is playing." << std::endl;
    }
std::vector<std::string> getInfo() const
{
    std::vector<std::string> info;
    info.push_back(headline);
    info.push_back(author);
    return info;
}
double getDuration() const
{
    return duration;
}
Media *clone() const
{
    return new Audiobook(*this);
}
};


class Playlist {
private:
std::vector<Media*> list;
void swap(Playlist& other) {
    std::swap(this->list, other.list);
}
public:
Playlist(const std::vector<Media*>& list) {
    for (Media* p : list) {
        this->list.push_back(p->clone());
    }
}
~Playlist() {
    for(Media* p: list) {
        delete p;
    }
}

Playlist(const Playlist& other)
{
    for (Media *p : other.list)
    {
        this->list.push_back(p->clone());
    }
}

Playlist &operator=(const Playlist &other) {
    Playlist copy(other);
    swap(copy);
    return *this;
}
};

int main() {
    std::vector<Media*> list;
    Media* song = new Song("DNA", "BTS", 3.20);
    list.push_back(song);
    Media* audiobook = new Audiobook("Harry Potter", "J.K.Rowling", 2.5, 0);
    list.push_back(audiobook);
    Playlist playlist(list);
    delete song;
    delete audiobook;
}