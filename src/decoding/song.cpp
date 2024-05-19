#include "decoding/song.h"

#include <SFML/Audio.hpp>
#include <iostream>

Song::Song() {
    isPlaying = false;
    name = "";
}
Song::Song(const std::string &name_) {
    isPlaying = false;
    name = name_;
}
Song::Song(const Song &track) {
    name = track.name;
    isPlaying = false;
}

Song Song::operator=(const Song &track) {
    name = track.name;
    isPlaying = false;
    return *this;
}
bool Song::operator==(const Song &track) {
    return (name == track.name);
}

bool Song::get_status() {
    return isPlaying;
}
void Song::set_name(const std::string &name_) {
    name = name_;
}
std::string Song::get_name() {
    return name;
}
bool Song::empty() {
    if (name == ""){
        return true;
    }
    return false;
}


void Song::playback(const std::string &name_directory) {
    if (!music.openFromFile(name_directory + "\\" + name + ".flac") && !music.openFromFile(name_directory + "\\" + name + ".ogg")){
        std::cout << "Song not found!\n";
        return;
    }
    music.play();
    isPlaying = true;
}
void Song::pause(){
    music.pause();
    isPlaying = false;
}