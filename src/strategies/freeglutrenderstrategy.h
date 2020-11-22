#ifndef FREEGLUTRENDERSTRATEGY_H
#define FREEGLUTRENDERSTRATEGY_H

#include <iostream>
#include <vector>
#include <functional>
#include <GL/freeglut.h>
#include <png.h>
#include "../render.h"
#include <chrono>

class FreeglutRenderStrategy: public RenderStrategy
{
public:
    void drawImage(Image*, double, double, double);
    Image* loadImage(const char * imageName);
    void drawAnimation(Animation* animation, double x, double y, double scale, double duration);
    void Init(int*, char*);
    void Draw();
    void setWindowSize(int, int);
    void setWindowPosition(int, int);
    void createWindow();
private:
    int width = 1980;
    int height = 1024;
    char* argv;
    std::vector<std::function<void()>>  displayFunctions;
    GLuint genTex(GLsizei, GLsizei, const GLvoid*);

    static void DrawImpl();
    static FreeglutRenderStrategy* currentInstance;
};

#endif // FREEGLUTRENDERSTRATEGY_H
