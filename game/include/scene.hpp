#ifndef SCENE_HPP
#define SCENE_HPP

class Game;
class Scene {
    public:
        Scene();
        virtual void ready(Game&);
        virtual void update(Game&);
        virtual void render(Game&);
        virtual void keyDown(Game&);
        virtual void mouseUp(Game&);
};

class SceneTitle : public Scene {
    public:
        SceneTitle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void keyDown(Game&) override;
        void mouseUp(Game&) override;
};

/*
class SceneSelect : public Scene {
};

class SceneBattle : public Scene {
};
*/

#endif
