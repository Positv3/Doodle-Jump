#include "example.h"
#include "doodleview.h"

extern DoodleView* view;

A::A()
{
    view->scene->addItem(this);
}
