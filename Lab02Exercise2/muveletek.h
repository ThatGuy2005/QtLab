#ifndef MUVELETEK_H
#define MUVELETEK_H

class Muveletek
{
public:
    virtual float getOsszeg() = 0;
    virtual float getKamat() = 0;
    virtual void letet(float osszeg) = 0;
    virtual void kivet (float osszeg) = 0;
};

#endif // MUVELETEK_H
