#ifndef CTANKPLAYER_H
#define CTANKPLAYER_H
#include "CWeapon.h"
#include <Windows.h>

class CTankPlayer : public CWeapon
{
    private:


    public:
        CTankPlayer( const char *szName );
        //CTankPlayer();
        virtual ~CTankPlayer();
        void            Init();


        void            OnMove(int iKey, bool bPress);
        void            OnFire();

        void            OnSpriteColSprite(CWeapon* pSprite);

    protected:
};

#endif // CTANKPLAYER_H
