#include <iostream>

#include <App.h>
#include <Sprite.h>
#include <lm/lm.h>



int main() 
{
    ApusCore::App app = ApusCore::App();

    ApusCore::Sprite* sp = app.CreateSprite();

    app.Start();

    return 0;
}