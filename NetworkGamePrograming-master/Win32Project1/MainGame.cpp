#include "stdafx.h"
#include "MainGame.h"
#include "Obj.h"

CMainGame::CMainGame()
{
}


CMainGame::~CMainGame()
{
}



// �ʱ�ȭ
void CMainGame::Initialize()
{
	m_hdc = GetDC(g_hWnd);
	RECT clientrect;
	GetClientRect(g_hWnd, &clientrect);
	m_doubleBuffering.Initialize(m_hdc, clientrect);
	m_ball.Initialize(CVector2(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), PLAYER_SIZE, PLAYER_SPEED);
	m_ball.SetDirection(CVector2(1, 1));
	m_player.Initialize(CVector2(WINDOW_WIDTH - PLAYER_SIZE, WINDOW_HEIGHT / 2),
		PLAYER_SIZE, PLAYER_SPEED);
}
// process
void CMainGame::Progress()
{
	m_ball.move();
	m_collision.ifCollision(m_player, m_ball);
}

// �׸���
void CMainGame::Render()
{
	/*m_doubleBuffering.WriteToBackBuffer(&m_player1);
	m_doubleBuffering.WriteToBackBuffer(&m_player2);
	m_doubleBuffering.Present(m_hdc);*/

	m_doubleBuffering.WriteToBackBuffer(&m_player);
	m_doubleBuffering.WriteToBackBuffer(&m_ball);
	m_doubleBuffering.Present(m_hdc);

}
/* 
[2016/09/02 19��23�� 
�ۼ��� : �ڿ���(dygks910910@daum.net)]
����:���콺 �Է�ó���Լ� ����.
*/
void CMainGame::MouseInputProcessing(const MSG& msg)
{
	switch (msg.message)
	{
	case WM_LBUTTONDOWN:
		break;
	case WM_LBUTTONUP:
		break;
	case WM_RBUTTONDOWN:
		break;
	case WM_RBUTTONUP:
		break;
	case WM_MOUSEMOVE:
		m_player.MoveToMousePos(CVector2(LOWORD(msg.lParam), HIWORD(msg.lParam)),"p2");
		break;
	default:
		break;
	}
}

/*
[2016/09/04 01:54
�ۼ��� : ����(qpwoei25@naver.com)]
���� : Ű���� �Է�ó���Լ� ����.
*/
/* 
[2016/09/04 18��35�� 
�ۼ��� : �ڿ���(dygks910910@daum.net)]
���泻��:VK_UP�� DOWN���� player1��Ʈ��.
				F2,F3Ű�� �÷��̾�2 ��Ʈ��
*/
void CMainGame::KeyboardInputProcessing(const MSG& msg)
{
	switch (msg.message)
	{
	case WM_KEYDOWN:
		if (msg.wParam == VK_UP)
		{
		}
		if (msg.wParam == VK_DOWN)
		{

		}
		if (msg.wParam == VK_F3)
		{
		}
		if (msg.wParam == VK_F2)
		{
		}
		break;
	case WM_KEYUP:
		break;
	default:
		break;
	}
}
/*
[2016/09/04 01:56
�ۼ��� : ����(qpwoei25@naver.com)]
���� : Ÿ�̸� ó���Լ� ����.
*/
void CMainGame::GameTimer(const MSG & msg)
{
	switch (msg.message)
	{
	case WM_TIMER:
		//to do this;


		break;
	default:
		break;
	}
}


// ����
void CMainGame::Release()
{
	ReleaseDC(g_hWnd, m_hdc);


}

