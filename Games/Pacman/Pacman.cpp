/*
** EPITECH PROJECT, 2021
** B-OOP-400-NCE-4-1-arcade-marton.szuts
** File description:
** Pacman
*/

#include "Pacman.hpp"

Pacman::Pacman()
{
    std::srand(std::time(0));
    this->_p = new Player(&this->m);
    this->createGhosts();
    this->_timer = false;
    this->_win = false;
    this->_end = false;
    this->_combo = 0;
    this->getScoreFromFile();
}

Pacman::~Pacman()
{
    this->setScoreToFile();
}

void Pacman::init()
{
    std::ifstream file;
    std::string line;
    file.open("db/db_Menu/name.txt");
    if (file.is_open()) {
        getline(file, line);
        this->_name = line;
        file.close();
    }
}

void Pacman::moveGhosts()
{
    for (size_t i = 0; i < this->g.size(); i++) {
        this->g[i]->moveGhost();
        this->g[i]->move();
    }
}

void Pacman::createGhosts()
{
    int nb = 0;
    for (size_t i = 0; i < this->m.map.size(); i++) {
        for (size_t j = 0; j < this->m.map[i].size(); j++) {
            if (this->m.map[i][j] == 'G') {
                this->g.push_back(new Ghost(&this->m, j, i));
                nb++;
            }
        }
    }
}

Ghost *Pacman::findGhost(size_t x, size_t y) const
{
    for (Ghost *ghost : this->g) {
        if (ghost->getPosX() == x && ghost->getPosY() == y) {
            return ghost;
        }
    }
    return NULL;
}

void Pacman::setWeakGhost()
{
    for (Ghost *ghost : this->g) {
        ghost->setCar('w');
    }
}

void Pacman::setStrongGhost()
{
    for (Ghost *ghost : this->g) {
        ghost->setCar('G');
    }
}

void Pacman::overGhost()
{
    if (_p->getOnCar() == 'w') {
        Ghost *gogo = findGhost(_p->getPosX(), _p->getPosY());
        if (gogo) {
            gogo->setPos(13, 10);
            gogo->setOn(' ');
            gogo->setStart(1);
            gogo->setDir(K_UP);
        }
        m.setScore(m.getScore() + (200 * pow(2, _combo)));
        _combo += 1;
    }
}

bool Pacman::underGhost()
{
    for (Ghost *ghost : this->g) {
        if (ghost->getOnCar() == '@') {
            return true;
        }
    }
    return false;
}

bool Pacman::noMorePoint()
{
    for (std::string line : m.map) {
        for (int i = 0; line[i] != '\0'; i++) {
            if (line[i] == '.') {
                return false;
            }           
        }
    }
    _win = true;
    return true;
}

void Pacman::endGame()
{
    m.clearMap();
    if (_win) {
        m.setFileFromPath("db/db_Pacman/win.txt");
    } else {
        m.setFileFromPath("db/db_Pacman/lose.txt");
    }
    m._readMap();
}

bool Pacman::update()
{
    static std::chrono::_V2::system_clock::time_point currTime = my_clock::now();
    static std::chrono::_V2::system_clock::time_point prevTime = my_clock::now();
    static std::chrono::_V2::system_clock::time_point prevTimeBonus = my_clock::now();
    currTime = my_clock::now();

    if (_end == false) {
        if (this->_p->getPowerFull() && _timer == false) {
            setWeakGhost();
            prevTimeBonus = currTime;
            _timer = true;
        }

        if (std::chrono::duration_cast<std::chrono::microseconds>(currTime - prevTimeBonus).count() >= 5000000 && _timer) {
            setStrongGhost();
            _timer = false;
            _combo = 0;
            this->_p->setPowerFull(0);
        }

        if (this->_input != NONE)
            this->_p->setDir(this->_input);
        if (std::chrono::duration_cast<std::chrono::microseconds>(currTime - prevTime).count() >= 70000) {
            this->_p->move();
            overGhost();
            this->moveGhosts();
            if (underGhost() || noMorePoint()) {
                endGame();
                sleep(2);
                currTime = my_clock::now();
                _end = true;
            }
            prevTime = currTime;
        }

        if (_input == K_SPACE)
            return (true);
        return (false);
    } else {
        if (std::chrono::duration_cast<std::chrono::microseconds>(currTime - prevTime).count() >= 2000000) {
            return true;
        }
    }
    return (false);
}

std::vector<std::string> Pacman::getMap() const
{
    return (m.map);
}

size_t Pacman::getScore() const
{
    return (m.getScore());
}

void Pacman::setKeyPressed(Key k)
{
    this->_input = k;
}

std::map<char, std::string> Pacman::getTiles() const
{
    std::map<char, std::string> tileMap;
    std::ifstream file;
    std::string line;
    file.open("db/db_Pacman/config.txt");
    if (file.is_open()) {
        while (getline(file, line)) {
            tileMap.insert(std::make_pair(
                line[line.find('=') + 1],
                line.substr(0, line.find('='))
            ));
        }
        file.close();
    }

    return (tileMap);
}

void Pacman::getScoreFromFile()
{
    std::ifstream file;
    std::string line;
    file.open("db/db_Pacman/score.txt");
    if (file.is_open())
        getline(file, line);
    this->_bestScore = std::atoi(line.c_str());
}

void Pacman::setScoreToFile()
{
    if (this->m.getScore() > (int)this->_bestScore) {
        std::ofstream file;
        file.open("db/db_Pacman/score.txt");
        if (file.is_open()) {
            file.clear();
            file << std::to_string(this->m.getScore());
        }
        file.close();
    }
}

size_t Pacman::getBestScore() const
{
    return (_bestScore);
}

std::string Pacman::getName() const
{
    return (this->_name);
}

extern "C" IGame *createGame()
{
    return (new Pacman);
}

extern "C" void destroyGame(IGame *game)
{
    delete game;
}