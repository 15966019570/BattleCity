/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#ifndef _LESSON_X_H_
#define _LESSON_X_H_
//
#include <Windows.h>
#include "CTankPlayer.h"
#include "CTankEnemy.h"
#include <vector>
#include "CWeapon.h"
using namespace std;

/////////////////////////////////////////////////////////////////////////////////
//
// 游戏总管类。负责处理游戏主循环、游戏初始化、结束等工作
class	CGameMain
{
private:
	int				m_iGameState;				// 游戏状态，0：结束或者等待开始；1：初始化；2：游戏进行中

    CSprite*        m_pBattleCity;
    CSprite*        m_pSpaceStart;

    CTankPlayer*    m_pTankPlayer;              //玩家
    bool            m_bPlayerSpeed;
//    CTankEnemy*     m_pTankEnemy;               //机器人
    bool            m_bEnemySpeed;
    vector<CWeapon*>m_vWeapon;
    bool            m_bTracePlayer;
    bool            m_bFish;
    bool            m_bInvincibility;

	float           m_fTankEnemyTime;
	int             m_iTankEnemyNumber;

	CWeapon*        m_pAim_nor;

    int             m_iBulletNum;

    CTextSprite*	m_pScore; //表示分数的文本精灵
    CTextSprite*    m_pHight; //表示最高分的文本精灵
	CTextSprite*	m_pEnemy;//表示敌人数量的文本精灵
	int             m_iScore;//分数
    int             m_iEnemy;//敌人数量
    int             m_iHight;//几局最高分
    float           m_fDeltaTime;//表示游戏时间

	bool            m_bWallStart;
	int				g_iMap[11][13] =
	{
		/*{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,0,0,0,1,0,1,0,0,0,1,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,0,0,1,0,1,0,1,0,1,0,0,0},
		{0,0,0,1,0,0,0,0,0,1,0,0,0},
		{0,0,0,1,0,1,0,1,0,1,0,0,0},
		{1,1,1,1,1,1,1,1,1,1,1,1,1},
		{0,1,0,1,0,0,0,0,0,1,0,1,0},
		{0,0,0,0,0,1,1,1,0,0,0,0,0},
		{0,0,0,0,0,1,0,1,0,0,0,0,0}*/

		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0},
		{0,1,0,1,0,1,0,1,0,1,0,1,0},
		{0,0,0,0,0,0,0,0,0,0,0,0,0},
		{0,0,0,0,0,1,1,1,0,0,0,0,0},
		{0,1,0,1,0,0,0,0,0,1,0,1,0},
		{0,1,0,1,0,0,0,0,0,1,0,1,0},
		{0,1,0,1,0,1,1,1,0,1,0,1,0},
		{0,0,0,0,0,1,0,1,0,0,0,0,0}
	};



public:
	CGameMain();            //构造函数
	~CGameMain();           //析构函数

	// Get方法
	int				GetGameState()									{ return m_iGameState; }
    CTankPlayer*    GetPalyer()                                     { return m_pTankPlayer; }

	// Set方法
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }

	// 游戏主循环等
	void			GameMainLoop( float	fDeltaTime );
	void			GameInit();
	void			GameRun( float fDeltaTime );
	void			GameEnd();

	// 游戏操控
	void            OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
	void            OnKeyUp( const int iKey );

    void            OnSpriteColWorldLimit( const char *szName, const int iColSide );

    void            AddBullet( int iDir,float fPosX,float fPosY ,int iOwner);
    void            LoadMap();
    void            RigidityMap();//按4键我方坦克能穿墙，再按4键恢复。

    CWeapon*        FindWeaponByName(const char* szName);
    void            DeleteWeaponByName(const char* szName);

    void	        AddTankEnemy(float fDeltaTime);

    void            OnSpriteColSprite(const char *szSrcName, const char *szTarName);

    void            DeleteAllSprite();
    void            PlayerSpeedFast();//按0键我方坦克速度加快，再按0键恢复。
    void            StopEnemy();//按6键敌方坦克全固定，再按6键恢复。
    void            PlayerTP();//按1键我方坦克传送到别处。
    void            TracePlayer(float fDeltaTime);//按9键敌方坦克都追击我方坦克，再按9键恢复。
};

/////////////////////////////////////////////////////////////////////////////////
//
extern CGameMain	g_GameMain;

#endif // _LESSON_X_H_
