#ifndef CWEAPON_H
#define CWEAPON_H
#include "CommonClass.h"

class CWeapon : public CSprite
{
    private:
        int             m_iDir;//值为0、1、2、3，分别表示上、右、下、左。
        int             m_iHp;
        float           m_fSpeedX;
        float           m_fSpeedY;

    public:
        CWeapon( const char* szName );
        virtual ~CWeapon();

        //set方法
        void            SetHp(int hp)                   {m_iHp = hp;}
        void            SetDir(int dir)                 {m_iDir = dir;}
        void            SetSpeedX(float speedX)         {m_fSpeedX = speedX;}
        void            SetSpeedY(float speedY)         {m_fSpeedY = speedY;}
        //get方法
        int             GetHp()                         {return m_iHp;}
        int             GetDir()                        {return m_iDir;}
        float           GetSpeedX()                     {return m_fSpeedX;}
        float           GetSpeedY()                     {return m_fSpeedY;}

        bool	        IsDead();   //判断精灵是否死亡
		virtual void    Init(){}; //初始化函数
		virtual void    OnMove(float fDeltaTime){};  //敌方坦克移动函数
		virtual void    OnMove(){};
		virtual void    OnFire(float deltaTime){};  //发射子弹函数
		virtual void    OnSpriteColSprite(CWeapon* pSprite){}; //精灵与精灵碰撞时处理函数

    protected:

};

#endif // CWEAPON_H
