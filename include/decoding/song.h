// объявление класса и методов песни, мб здесь кстати заюзать шаблонный метод, чекай переписку гпт(т.е. использовать здесь перегруженный метод плей от разных классов типа mp3song wavsong flacsong), опционально добавить закладки(мне для этого отдельный список надо будет реализовать)
#include <string>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include "ui/ui.h"
class Song{
    sf::Music music;
    std::string name;
    bool isPlaying;

    
    friend int CurrentTrackControlGUI(sf::RenderWindow &window, uiResources::ResourceManager &resourceManager, sf::Event &event);
public:
    Song();
    Song(const std::string &name_);
    Song(const Song &track);

   Song operator=(const Song &track);
   bool operator==(const Song &track);

    bool get_status();
    void set_name(const std::string &name_);
    std::string get_name() const;
    sf::Music& get_sfMusic();
    bool empty();


    void playback(const std::string &name_directory);
    void pause();
};