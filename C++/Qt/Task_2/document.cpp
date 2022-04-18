#include "document.h"

Document::Document()
{

}

Document::~Document()
{

}

int Document::getI()
{
    return i_;
}

void Document::setI(int i)
{
    i_ = i;
}

void Document::setup()
{
    setI(100);
}
