/////////////////////////////////////////////////////////////////////////////////
//
//
//
//
/////////////////////////////////////////////////////////////////////////////////
#include <Stdio.h>
#include "CommonClass.h"
#include "LessonX.h"
#include "CTankPlayer.h"
#include "CBullet.h"
#include <iostream>
using namespace std;
////////////////////////////////////////////////////////////////////////////////
//
//
CGameMain		g_GameMain;

//==============================================================================
//
// ����ĳ�������Ϊ��GameMainLoop����Ϊ��ѭ��������������ÿ֡ˢ����Ļͼ��֮�󣬶��ᱻ����һ�Ρ�

//==============================================================================
//
// ���캯��
CGameMain::CGameMain()
{
	m_iGameState			=	0;
	m_pBattleCity           =   new CSprite("battleCityText");
	m_pSpaceStart           =   new CSprite("spaceStart");


}
//==============================================================================
//
// ��������
CGameMain::~CGameMain()
{
    free(m_pBattleCity);
    free(m_pSpaceStart);
}

//==============================================================================
//
// ��Ϸ��ѭ�����˺���������ͣ�ĵ��ã�����ÿˢ��һ����Ļ���˺�����������һ��
// ���Դ�����Ϸ�Ŀ�ʼ�������С������ȸ���״̬.
// ��������fDeltaTime : �ϴε��ñ��������˴ε��ñ�������ʱ��������λ����
void CGameMain::GameMainLoop( float	fDeltaTime )
{
	switch( GetGameState() )
	{
		// ��ʼ����Ϸ�������һ���������
	case 1:
		{
			GameInit();
			SetGameState(2); // ��ʼ��֮�󣬽���Ϸ״̬����Ϊ������
		}
		break;

		// ��Ϸ�����У����������Ϸ�߼�
	case 2:
		{
			// TODO �޸Ĵ˴���Ϸѭ�������������ȷ��Ϸ�߼�
			if( true )
			{
				GameRun( fDeltaTime );
			}
			else // ��Ϸ������������Ϸ���㺯����������Ϸ״̬�޸�Ϊ����״̬
			{
				SetGameState(0);
				GameEnd();
			}
		}
		break;

		// ��Ϸ����/�ȴ����ո����ʼ
	case 0:
	default:
		break;
	};
}
//=============================================================================
//
// ÿ�ֿ�ʼǰ���г�ʼ���������һ���������
void CGameMain::GameInit()
{
    m_pBattleCity->SetSpriteVisible(false);
    m_pSpaceStart->SetSpriteVisible(false);

    m_pTankPlayer           =   new CTankPlayer("myplayer");//�½�һ��������myPlayer���ҷ�̹�˶���
	m_pTankPlayer->CloneSprite("player");//�ҷ�̹�˿�¡��funcodeģ���д��ڵ�����Ϊplayer��̹�ˣ���ʾ�½���̹�˶��������ھ������������
	m_pTankPlayer->Init();

	m_pTankEnemy = new CTankEnemy("enemy");
    m_pTankEnemy->Init();

    LoadMap();

    m_vWeapon.push_back(m_pTankPlayer);
}
//=============================================================================
//
// ÿ����Ϸ������
void CGameMain::GameRun( float fDeltaTime )
{
    if(m_pTankEnemy)
	{
		m_pTankEnemy->OnMove(fDeltaTime);
		m_pTankEnemy->OnFire(fDeltaTime);
	}

}
//=============================================================================
//
// ������Ϸ����
void CGameMain::GameEnd()
{
}
//=============================================================================
//
void CGameMain::OnKeyDown( const int iKey, const bool bAltPress, const bool bShiftPress, const bool bCtrlPress )
{
    //���ո����ʼ��Ϸ
    if( GetGameState() == 0 ){
        if( iKey == KEY_SPACE ){
            m_iGameState = 1;
        }
    }
    //�ٿ�myplayer
    if(m_iGameState == 2)
	{
		m_pTankPlayer->OnMove(iKey, true);
	}
    if(iKey == KEY_J)//�жϰ��¼��ǹ�ΪJ��
	{
		m_pTankPlayer->OnFire();
	}

}

void CGameMain::OnKeyUp(const int iKey)
{
    //�ٿ�myplayer
	if(m_iGameState == 2)
	{
		m_pTankPlayer->OnMove(iKey, false);
    }
}

//void CGameMain::OnSpriteColWorldLimit(const char* szName, const int iColSide)
//{
//	if (strstr(szName, "player") != NULL) //�ж���������߽��̹���Ƿ�Ϊ�ҷ�̹��
//	{
//		m_pTankPlayer->SetSpriteLinearVelocity(0.f, 0.f);
//	}
//	if(m_pTankEnemy&&strcmp(m_pTankEnemy->GetName(),szName)==0)
//	{
//		m_pTankEnemy->OnMove();
//	}
//}

void CGameMain::AddBullet( int iDir,float fPosX,float fPosY ,int iOwner)
{
	char* szName = CSystem::MakeSpriteName("bullet",m_iBulletNum);//����̹������
	CBullet* pBullet = new CBullet(szName);
	pBullet->CloneSprite("bullet");
	pBullet->SetSpriteWorldLimit(WORLD_LIMIT_NULL,-26, -22, 26, 22); //��������߽�
	pBullet->SetSpritePosition(fPosX,fPosY);
	pBullet->SetSpriteCollisionSend(true); //���ý�����ײ
	pBullet->OnMove(iDir);
	m_iBulletNum++; //�ӵ�������1
	if(iOwner == 1)
	{
		pBullet->SetOwner(1);//1��ʾ�ҷ�̹�˷�����ӵ�
	}
	else
	{
		pBullet->SetOwner(0); //0��ʾ�ط�̹�˷�����ӵ�
	}
    m_vWeapon.push_back(pBullet);
}
void CGameMain::LoadMap()
{
	char* szName;
	int i,j;
	float x,y;
	for(i=0;i<11;i++)
	{
		for(j=0;j<13;j++)
		{
			if(g_iMap[i][j]!=0)
			{
				szName = CSystem::MakeSpriteName("wall",j+i*13+i);//��������
				CWeapon* pWall = new CWeapon(szName);//�½�����
				pWall->CloneSprite("wall"); //��¡ǽ��
//				pWall->SetSpriteCollisionActive(0,1); //����Ϊ������ײ
//				pWall->SetSpriteCollisionResponse(COL_RESPONSE_CUSTOM);
				x =float(-24+4*j);
				y =float(-20+4*i);
				pWall->SetSpritePosition(x,y);
                m_vWeapon.push_back(pWall);
			}
		}
	}
}

CWeapon* CGameMain::FindWeaponByName(const char* szName)//�������ֲ��ҵ�����
{
	for(int i=0; i<m_vWeapon.size(); i++)
	{
			if(strcmp(szName,m_vWeapon[i]->GetName()) == 0)
			{
				return m_vWeapon[i];
			}
	}
}

void CGameMain::DeleteWeaponByName(const char* szName)//�������ְѾ����������ɾ��
{
	for(vector<CWeapon*>::iterator it=m_vWeapon.begin();it!=m_vWeapon.end();)
	{
		CWeapon* cw =*it;
		if(strcmp(szName,cw->GetName()) == 0)
		{
			m_vWeapon.erase(it);
			cw->DeleteSprite();
			delete cw;
			break;
		}
		else
		{
			it++;
		}
	}
}
