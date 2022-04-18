#ifndef DOCUMENT_H
#define DOCUMENT_H


class Document
{
private:
    int i_;

public:
    Document();
    ~Document();

    int getI();
    void setI(int i);
    void setup();

};

#endif // DOCUMENT_H
