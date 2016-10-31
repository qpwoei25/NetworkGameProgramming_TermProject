#include "stdafx.h"
#include "Player.h"


CPlayer::CPlayer()
{
}


CPlayer::~CPlayer()
{
}

void CPlayer::Initialize(const CVector2& pos, const float& size,const float& speed)
{
	CBall::Initialize(pos, size, speed);
}

void CPlayer::Progress()
{
	/*m_vPlayerPos.x += m_nBallSpeed;

	if ((m_vPlayerPos.x >= WINDOW_WIDTH - m_nBallSize) || (m_vPlayerPos.x <= m_nBallSize))
		m_nBallSpeed *= -1;*/
}

void CPlayer::Render(HDC hdc)
{
	CBall::Render(hdc);
}

void CPlayer::Release()
{
	
}
/*
2016 / 10 / 29 / 0:16
�ۼ���:�ڿ���(dygks910910@daum.net)
����:���콺�� �����ǿ� ���� �÷��̾��� ��ġ�� �ٲ�.�÷��̾��� ��ġ�� ���� �Ѿ�� ����.���� 1p�� ��ݺθ�,2p�� �¹ݺθ� �����.
*/
void CPlayer::MoveToMousePos(const CVector2& MousePos, char* p1)
{

		if (p1 == "p1")
		{
			if (MousePos.x <= WINDOW_WIDTH / 2)
			{
				SetPosition(CVector2((float)WINDOW_WIDTH / 2,MousePos.y));
				return;
			}
		}
		if (p1 == "p2")
		{
			if (MousePos.x >= WINDOW_WIDTH / 2)
			{
				SetPosition(CVector2((float)WINDOW_WIDTH / 2, MousePos.y));
				return;

			}
		}
			SetPosition(MousePos);
}



