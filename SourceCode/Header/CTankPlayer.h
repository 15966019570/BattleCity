#ifndef CTANKPLAYER_H
#define CTANKPLAYER_H
#include "CWeapon.h"
#include <Windows.h>

class CTankPlayer : public CWeapon
{
    private:
        float             m_fSpeed;

    public:
        CTankPlayer( const char *szName );
        //CTankPlayer();
        virtual ~CTankPlayer();
        void            Init();

        //Set方法
        void            SetSpeed(float speed)       {m_fSpeed = speed;}
        //get方法
        float           GetSpeed()                  {return m_fSpeed;}

        void            OnMove(int iKey, bool bPress);
        void            OnFire();

        void            OnSpriteColSprite(CWeapon* pSprite);

    protected:
};

#endif // CTANKPLAYER_H
