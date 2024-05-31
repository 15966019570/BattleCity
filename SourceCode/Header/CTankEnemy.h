#ifndef CTANKENEMY_H
#define CTANKENEMY_H
#include <windows.h>
#include "CWeapon.h"

class CTankEnemy : public CWeapon
{
    private:

        float           m_fChangeDirTime;
        float           m_fBulletCreateTime;
    public:
        CTankEnemy(const char* szName);
        virtual ~CTankEnemy();

        void            Init();

        //set方法
        void            SetChangeDirTime(float Time)    {m_fChangeDirTime = Time;}
        //get方法
        float           GetChangeDirTime(float Time)    {return m_fChangeDirTime;}

        void            OnMove();
        void            OnMove(float fDeltaTime);

        void            OnFire(float fDeltaTime);

        void            OnSpriteColSprite(CWeapon* pSprite);

    protected:

};

#endif // CTANKENEMY_H
