// zavd_89.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include <iostream>  

using namespace std;

class Hero {
public:
    void virtual create() = 0;
};

class KnightHero : public Hero {
public:
    void create() override {
        cout << "Knight" << endl;
    }
};

class ArcherHero : public Hero {
public:
    void create() override {
        cout << "Archer" << endl;
    }
};

class Enemy {
public:
    void virtual create() = 0;
};

class GoblinEnemy : public Enemy {
public:
    void create() override {
        cout << "Goblin" << endl;
    }
};

class WitchEnemy : public Enemy {
public:
    void create() override {
        cout << "Witch" << endl;
    }
};

class GameFactory { // AbstractFactory  
public:
    virtual Hero* createHero() = 0;
    virtual Enemy* createEnemy() = 0;
};

class FantasyGameFactory : public GameFactory {
public:
    Hero* createHero() override {
        Hero* hero = new KnightHero();
        return hero;
    };

    Enemy* createEnemy() override {
        Enemy* enemy = new GoblinEnemy();
        return enemy;
    }
};

class SciFiGameFactory : public GameFactory {
public:
    Hero* createHero() override {
        Hero* hero = new ArcherHero();
        return hero;
    };

    Enemy* createEnemy() override {
        Enemy* enemy = new WitchEnemy();
        return enemy;
    }
};

class User {
    GameFactory* factory;

public:
    User(GameFactory* _factory)
        : factory(_factory) {}

    void spawnHero() {
        Hero* hero = factory->createHero();
        hero->create();
    }

    void spawnEnemy() {
        Enemy* enemy = factory->createEnemy();
        enemy->create();
    }
};

int main()
{
    cout << "Welcome to the game!\n";
    cout << "Make choice\n";
    cout << "FantasyGameFactory - 1, SciFiGameFactory - 2, exit - 3\n";
    int choice;
    cout << "Choose: ";
    cin >> choice;
    if (choice == 1) {
        GameFactory* factory = new FantasyGameFactory();

        User user(factory);

        user.spawnHero();
        user.spawnEnemy();
    }

    else if (choice == 2) {
        GameFactory* factory = new SciFiGameFactory();

        User user(factory);

        user.spawnHero();
        user.spawnEnemy();
    }
    else if (choice == 3) {
        cout << "Exting......" << endl;
    }
    else {
        cout << "Unknown option" << endl;
    }
}