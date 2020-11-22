#include "freeglutrenderstrategy.h"


FreeglutRenderStrategy* FreeglutRenderStrategy::currentInstance;

void FreeglutRenderStrategy::Init(int* argc, char* _argv)
{
    argv = _argv;
    glutInit(argc, &argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(0, 0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

};

void FreeglutRenderStrategy::setWindowSize(int _width, int _height){
    width = _width;
    height = _height;
};

void FreeglutRenderStrategy::setWindowPosition(int x, int y){
    glutInitWindowPosition(x, y);
};

void FreeglutRenderStrategy::createWindow(){
    glutInitWindowSize(width, height);
    glutCreateWindow(argv);
};

void FreeglutRenderStrategy::drawImage(Image* image, double x, double y, double scale)
{
    FreeglutRenderStrategy::displayFunctions.push_back([image, this, x, y, scale](){
        glBindTexture(GL_TEXTURE_2D, image->texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex2f(x/(width/2.), (y-image->height*scale)/((height)/2.));
            glTexCoord2f(0.0, 1.0); glVertex2f(x/(width/2.), y/((height)/2.));
            glTexCoord2f(1.0, 1.0); glVertex2f((x+image->width*scale)/(width/2.), y/((height)/2.));
            glTexCoord2f(1.0, 0.0); glVertex2f((x+image->width*scale)/(width/2.),  (y-image->height*scale)/((height)/2.));
        glEnd();
    });
}


void FreeglutRenderStrategy::drawAnimation(Animation* animation, double x, double y, double scale, double delay)
{
    auto prevTime = std::chrono::high_resolution_clock::now();
    std::chrono::system_clock::time_point* prevTimeP = new std::chrono::system_clock::time_point(prevTime);

    auto animationIterator = animation->createIterator();
    FreeglutRenderStrategy::displayFunctions.push_back([this, x, y, scale, delay, prevTimeP, animationIterator](){
        auto now = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double, std::milli> fp_ms = now - *prevTimeP;

        if(fp_ms.count() > delay){
            *prevTimeP = now;
            animationIterator->next();
            if(animationIterator->isDone()) animationIterator->first();
        }

        glBindTexture(GL_TEXTURE_2D, animationIterator->currentItem()->texture);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0, 0.0); glVertex2f(x/(width/2.), (y - animationIterator->currentItem()->height*scale)/((height)/2.));
            glTexCoord2f(0.0, 1.0); glVertex2f(x/(width/2.), y/((height)/2.));
            glTexCoord2f(1.0, 1.0); glVertex2f((x + animationIterator->currentItem()->width*scale)/(width/2.), y/((height)/2.));
            glTexCoord2f(1.0, 0.0); glVertex2f((x + animationIterator->currentItem()->width*scale)/(width/2.),  (y - animationIterator->currentItem()->height*scale)/((height)/2.));
        glEnd();
    });
}

GLuint FreeglutRenderStrategy::genTex(GLsizei width, GLsizei height, const GLvoid* image_data)
{
    GLuint texture;

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    return texture;
};

Image* FreeglutRenderStrategy::loadImage(const char* imagePath)
{
    png_byte* image_data;
    png_uint_32 width, height;

    loadPng(imagePath, &width, &height, &image_data);
    GLuint texture = genTex(width, height, image_data);

    free(image_data);
    return new Image(texture, width, height);
}

void FreeglutRenderStrategy::Draw()
{

    FreeglutRenderStrategy::currentInstance = this;

    glutDisplayFunc(FreeglutRenderStrategy::DrawImpl);

    glutIdleFunc(glutPostRedisplay);
    glutMainLoop();
}

void FreeglutRenderStrategy::DrawImpl()
{
    glEnable(GL_TEXTURE_2D);

    for(auto glDisplayFunction: FreeglutRenderStrategy::currentInstance->displayFunctions)
    {
        glDisplayFunction();
    }

    glFlush();
    glDisable(GL_TEXTURE_2D);
}


