// объявление класса и методов песни, мб здесь кстати заюзать шаблонный метод, чекай переписку гпт(т.е. использовать здесь перегруженный метод плей от разных классов типа mp3song wavsong flacsong), опционально добавить закладки(мне для этого отдельный список надо будет реализовать)
#pragma once

#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
class Song
{
    sf::Music music;
    std::string name;
    std::string path; 

    bool isPlaying;

public:
    Song();
    Song(const std::string &name_);
    Song(const Song &track);

    Song &operator=(const Song &track);
    bool operator==(const Song &track) const;

    bool get_status() const;
    std::string get_name() const;
    sf::Time get_current_time();

    void set_name(const std::string &name_);
    void set_path(const std::string &path_); 
    std::string get_path() const;           
    bool empty() const;

    void playback(sf::Time current_time);
    void pause();
    sf::Music &get_sfMusic();
};