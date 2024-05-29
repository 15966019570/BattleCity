#include "CBullet.h"
#include "CWeapon.h"

CBullet::CBullet(const char* szName):CWeapon(szName) //对构造函数进行实现
{
    //ctor
    m_iOwner            =   1;
}

CBullet::~CBullet()
{
    //dtor
}

void CBullet::OnMove(int iDir)
{
    SetDir(iDir);
	switch(GetDir())
	{
	case 0:
		SetSpeedX(0);
		SetSpeedY(-10);
		break;
	case 1:
		SetSpeedX(10);
		SetSpeedY(0);
		break;
	case 2:
		SetSpeedX(0);
		SetSpeedY(10);
		break;
	case 3:
		SetSpeedX(-10);
		SetSpeedY(0);
		break;
	}
	SetSpriteRotation(90*GetDir());
	SetSpriteLinearVelocity(GetSpeedX(),GetSpeedY());
}
