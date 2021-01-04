#include "Game/GUI/FPS.h"

FPS::FPS(std::map<std::string, sf::Font>& fonts)  :   dt_frames{0.f}, dt_average{0.f}, fps_render_timing{0.f} {
    this->fps.setFont(fonts["Courier"]);
    this->fps.setCharacterSize(20);
    this->fps.setFillColor(sf::Color::Green);
    this->fps.setPosition(5.f, 5.f);
}

FPS::~FPS() {

}

void FPS::update(const float &dt) {
    fps_render_timing += dt;
    dt_average += dt;
    dt_frames++;

    if(fps_render_timing >= 0.2) {
        float a = dt_frames / dt_average;

        if(a < 500)
            fps.setFillColor(sf::Color::Red);
        else
            fps.setFillColor(sf::Color::Green);

        std::ostringstream ss;
        ss << a;
        ss << " FPS\n";

        a = dt_average / dt_frames;
        ss << a;
        ss << " DT";

        std::string de_afisat(ss.str()); // float -> string conversion

        this->fps.setString(de_afisat);

        //Reset
        fps_render_timing = 0.f;
        dt_average = 0.f;
        dt_frames = 0.f;
    }
}

void FPS::render(sf::RenderTarget *target) {
    target->draw(this->fps);
}


