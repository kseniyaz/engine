#include "engine.h"
#include "strategies/freeglutrenderstrategy.h"

int main(int argc, char **argv){
    RenderStrategy* strategy = new FreeglutRenderStrategy();
    Engine engine(strategy, &argc, *argv);

    engine.setWindowSize(1024, 768);
    engine.setWindowPosition(300, 100);
    engine.createWindow();

    auto iRun1 = engine.loadImage("png/run1.png");
    auto iRun2 = engine.loadImage("png/run2.png");
    auto iRun3 = engine.loadImage("png/run3.png");
    auto iRun4 = engine.loadImage("png/run4.png");
    auto iRun5 = engine.loadImage("png/run5.png");
    auto iRun6 = engine.loadImage("png/run6.png");
    auto iRun7 = engine.loadImage("png/run7.png");
    auto iRun8 = engine.loadImage("png/run8.png");

    auto aRun = new Animation();

    aRun->push(iRun1);
    aRun->push(iRun2);
    aRun->push(iRun3);
    aRun->push(iRun4);
    aRun->push(iRun5);
    aRun->push(iRun6);
    aRun->push(iRun7);
    aRun->push(iRun8);

    auto run = new AnimationGameObject(-512, 0.0, 0.5, 90, aRun);

    engine.addGameObject(run, "run");

    auto iIdle1 = engine.loadImage("png/idle1.png");
    auto iIdle2 = engine.loadImage("png/idle2.png");
    auto iIdle3 = engine.loadImage("png/idle3.png");
    auto iIdle4 = engine.loadImage("png/idle4.png");
    auto iIdle5 = engine.loadImage("png/idle5.png");
    auto iIdle6 = engine.loadImage("png/idle6.png");
    auto iIdle7 = engine.loadImage("png/idle7.png");
    auto iIdle8 = engine.loadImage("png/idle8.png");
    auto iIdle9 = engine.loadImage("png/idle9.png");
    auto iIdle10 = engine.loadImage("png/idle10.png");

    auto aIdle = new Animation();

    aIdle->push(iIdle1);
    aIdle->push(iIdle2);
    aIdle->push(iIdle3);
    aIdle->push(iIdle4);
    aIdle->push(iIdle5);
    aIdle->push(iIdle6);
    aIdle->push(iIdle7);
    aIdle->push(iIdle8);
    aIdle->push(iIdle9);
    aIdle->push(iIdle10);

    auto idle = new AnimationGameObject(-256, 0.0, 0.5, 100, aIdle);

    engine.addGameObject(idle, "idle");

    engine.removeGameObject("idle"); // remove go if needed

    engine.addGameObject(idle, "idle");

    auto iMelee1 = engine.loadImage("png/melee1.png");
    auto iMelee2 = engine.loadImage("png/melee2.png");
    auto iMelee3 = engine.loadImage("png/melee3.png");
    auto iMelee4 = engine.loadImage("png/melee4.png");
    auto iMelee5 = engine.loadImage("png/melee5.png");
    auto iMelee6 = engine.loadImage("png/melee6.png");
    auto iMelee7 = engine.loadImage("png/melee7.png");


    auto aMelee = new Animation();

    aMelee->push(iMelee1);
    aMelee->push(iMelee2);
    aMelee->push(iMelee3);
    aMelee->push(iMelee4);
    aMelee->push(iMelee5);
    aMelee->push(iMelee6);
    aMelee->push(iMelee7);

    auto melee = new AnimationGameObject(0, 0.0, 0.5, 100, aMelee);

    engine.addGameObject(melee, "melee");


    engine.Draw();
    delete strategy;
}


























