#include <iostream>
#include <cstring>

class VideoGame {
private:
char* title;
int pathcesCount;
public:
    void swap(VideoGame& other) {
        std::swap(title, other.title);
        std::swap(pathcesCount, other.pathcesCount);
    }
    VideoGame(const char *title, int pathcesCount) : title(new char[strlen(title) + 1]), pathcesCount(pathcesCount) {
        strcpy(this->title, title);
    }

    ~VideoGame() {
        delete[] title;
    }
    VideoGame(const VideoGame& other){
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);
        pathcesCount = other.pathcesCount;
    }
    VideoGame& operator=(const VideoGame& other) {
        VideoGame copy(other);
        swap(copy);
        return *this;
    }

    
};