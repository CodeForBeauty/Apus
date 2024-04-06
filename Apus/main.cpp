#include <iostream>

#include <App.h>
#include <Sprite.h>
#include <lm/lm.h>

#include "NewApp.h"


int main() 
{
    ApusCore::App app = NewApp();

    ApusCore::Sprite* sp = app.CreateSprite();

    app.Start();

    return 0;
}