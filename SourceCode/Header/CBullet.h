#ifndef CBULLET_H
#define CBULLET_H
#include "CWeapon.h"
#include <Windows.h>

class CBullet : public CWeapon
{
    private:

        int             m_iOwner;//发射子弹归属坦克

    public:
        CBullet(const char* szName);
        virtual ~CBullet();

        //set方法
        void            SetOwner(int Owner)             {m_iOwner = Owner;}
        //get方法
        int             GetOwner()                      {return m_iOwner;}

        void            OnMove(int iDir);

        void            OnSpriteColSprite(CWeapon* pSprite);

    protected:

};

#endif // CBULLET_H
