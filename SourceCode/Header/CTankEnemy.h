#ifndef CTANKENEMY_H
#define CTANKENEMY_H
#include <windows.h>
#include "CWeapon.h"

class CTankEnemy : public CWeapon
{
    private:

        float           m_fChangeDirTime;
        float           m_fBulletCreateTime;
        float           m_fSpeed;
    public:
        CTankEnemy(const char* szName);
        virtual ~CTankEnemy();

        void            Init();

        //set·½·¨
        void            SetChangeDirTime(float Time)    {m_fChangeDirTime = Time;}
        void            SetSpeed(float speed)           {m_fSpeed = speed;}
        //get方法
        float           GetChangeDirTime(float Time)    {return m_fChangeDirTime;}
        float           GetSpeed()                      {return m_fSpeed;}

        void            OnMove();
        void            OnMove(float fDeltaTime);

        void            OnFire(float fDeltaTime);

        void            OnSpriteColSprite(CWeapon* pSprite);

    protected:

};

#endif // CTANKENEMY_H
