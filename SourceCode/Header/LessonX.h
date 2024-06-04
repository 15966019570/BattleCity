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
// ��Ϸ�ܹ��ࡣ��������Ϸ��ѭ������Ϸ��ʼ���������ȹ���
class	CGameMain
{
private:
	int				m_iGameState;				// ��Ϸ״̬��0���������ߵȴ���ʼ��1����ʼ����2����Ϸ������

    CSprite*        m_pBattleCity;
    CSprite*        m_pSpaceStart;

    CTankPlayer*    m_pTankPlayer;              //���
    bool            m_bPlayerSpeed;
//    CTankEnemy*     m_pTankEnemy;               //������
    bool            m_bEnemySpeed;
    vector<CWeapon*>m_vWeapon;
    bool            m_bTracePlayer;
    bool            m_bFish;
    bool            m_bInvincibility;

	float           m_fTankEnemyTime;
	int             m_iTankEnemyNumber;

	CWeapon*        m_pAim_nor;

    int             m_iBulletNum;

    CTextSprite*	m_pScore; //��ʾ�������ı�����
    CTextSprite*    m_pHight; //��ʾ��߷ֵ��ı�����
	CTextSprite*	m_pEnemy;//��ʾ�����������ı�����
	int             m_iScore;//����
    int             m_iEnemy;//��������
    int             m_iHight;//������߷�
    float           m_fDeltaTime;//��ʾ��Ϸʱ��

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
	CGameMain();            //���캯��
	~CGameMain();           //��������

	// Get����
	int				GetGameState()									{ return m_iGameState; }
    CTankPlayer*    GetPalyer()                                     { return m_pTankPlayer; }

	// Set����
	void			SetGameState( const int iState )				{ m_iGameState	=	iState; }

	// ��Ϸ��ѭ����
	void			GameMainLoop( float	fDeltaTime );
	void			GameInit();
	void			GameRun( float fDeltaTime );
	void			GameEnd();

	// ��Ϸ�ٿ�
	void            OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress );
	void            OnKeyUp( const int iKey );

    void            OnSpriteColWorldLimit( const char *szName, const int iColSide );

    void            AddBullet( int iDir,float fPosX,float fPosY ,int iOwner);
    void            LoadMap();
    void            RigidityMap();//��4���ҷ�̹���ܴ�ǽ���ٰ�4���ָ���

    CWeapon*        FindWeaponByName(const char* szName);
    void            DeleteWeaponByName(const char* szName);

    void	        AddTankEnemy(float fDeltaTime);

    void            OnSpriteColSprite(const char *szSrcName, const char *szTarName);

    void            DeleteAllSprite();
    void            PlayerSpeedFast();//��0���ҷ�̹���ٶȼӿ죬�ٰ�0���ָ���
    void            StopEnemy();//��6���з�̹��ȫ�̶����ٰ�6���ָ���
    void            PlayerTP();//��1���ҷ�̹�˴��͵��𴦡�
    void            TracePlayer(float fDeltaTime);//��9���з�̹�˶�׷���ҷ�̹�ˣ��ٰ�9���ָ���
};

/////////////////////////////////////////////////////////////////////////////////
//
extern CGameMain	g_GameMain;

#endif // _LESSON_X_H_
